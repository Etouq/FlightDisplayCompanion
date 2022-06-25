import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15
import QtQml 2.15
import TypeEnums 1.0
import Mfd.GeoMapPage 1.0
import Pfd.HSIndicator 1.0

import "FlightplanLayer"

Item {
    id: geoMapRoot

    x: 420
    y: 0
    width: 1500
    height: 1200



    property variant zoomLevels: [0.1, 0.2, 0.3, 0.5, 1, 2, 3, 5, 10, 15, 20, 35, 50, 100, 150, 200, 250]
    property bool panModeActive: false
    property int zoomLevelIdx: 9
    property real currZoom: 9

    property real zoomSetting: zoomLevels[zoomLevelIdx]




    function updateZoom()
    {
        let midLeft = mapDisplay.toCoordinate(Qt.point(75, 600), false);
        let metersOnScreen = midLeft.distanceTo(mapDisplay.toCoordinate(Qt.point(1425, 600), false));
        let desiredMetersOnScreen = zoomLevels[zoomLevelIdx] * 1852 * 6;
        currZoom -= Math.log2(desiredMetersOnScreen / metersOnScreen);
    }

    Timer {
        interval: 50
        running: true
        repeat: true
        onTriggered: {
            updateZoom();
        }
    }


    Plugin {
        id: mapPlugin
        name: "osm"
        locales: "en_GB"

        PluginParameter { name: "osm.mapping.custom.host"; value: "https://tile.openstreetmap.org/" }
    }



    Map {
        id: mapDisplay
        anchors.fill: parent
        plugin: mapPlugin
        zoomLevel: currZoom
        copyrightsVisible: false

        gesture {
            acceptedGestures: MapGestureArea.PanGesture | MapGestureArea.FlickGesture
            preventStealing: true

            onPanStarted: function() {
                panModeActive = true;
            }

            onFlickStarted: function() {
                panModeActive = true;
            }

            onFlickFinished: function() {
                if(!panModeActive) {
                    mapDisplay.center = GeoMapPage.userPosition;
                }
            }
        }

        activeMapType: supportedMapTypes[supportedMapTypes.length - 1]

        Binding {
            target: mapDisplay
            property: 'center'
            value: GeoMapPage.userPosition
            when: !panModeActive
            restoreMode: Binding.RestoreBinding
        }

        states: [
            State {
                name: "northUpState"
                when: GeoMapPage.rotationMode === MapRotationMode.NORTH_UP
                PropertyChanges { target: mapDisplay; bearing: 0 }
            },
            State {
                name: "headingUpState"
                when: GeoMapPage.mapOrientationMode === MapRotationMode.HDG_UP
                PropertyChanges { target: mapDisplay; bearing: GeoMap.trueHeading }
            },
            State {
                name: "trackUpState"
                when: GeoMapPage.mapOrientationMode === MapRotationMode.TRACK_UP
                PropertyChanges { target: mapDisplay; bearing: HSIndicator.currentTrackAngle }
            },
            State {
                name: "dtkUpState"
                when: GeoMapPage.mapOrientationMode === MapRotationMode.DTK_UP
                PropertyChanges { target: mapDisplay; bearing: Flightplan.wpDtk }
            }
        ]


    }


    OverlayMap {
        zoomSetting: geoMapRoot.zoomSetting
        panModeActive: geoMapRoot.panModeActive

        mapCenter: mapDisplay.center
        mapBearing: mapDisplay.bearing
        currZoom: mapDisplay.zoomLevel
    }

    MapButtons {
        canZoomOut: geoMapRoot.zoomLevelIdx < geoMapRoot.zoomLevels.length - 1
        canZoomIn: geoMapRoot.zoomLevelIdx > 0
        mapNotCentered: geoMapRoot.panModeActive

        onDecreaseZoomClicked: function() {
            ++geoMapRoot.zoomLevelIdx;
            geoMapRoot.updateZoom();
        }

        onIncreaseZoomClicked: function() {
            --geoMapRoot.zoomLevelIdx;
            geoMapRoot.updateZoom();
        }

        onRecenterClicked: function() {
            mapDisplay.center = GeoMapPage.userPosition;
            geoMapRoot.panModeActive = false;
            geoMapRoot.updateZoom();
        }
    }



    Rectangle {
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        width: 150
        height: 60
        color: "#1a1d21"

        Text {
            id: zoomLevelText
            anchors.centerIn: parent
            font.family: "Roboto Mono"
            font.bold: true
            text: zoomLevels[zoomLevelIdx] + "NM"
            color: "#36c8d2"
            font.pixelSize: 45
        }

    }

    Rectangle {
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        height: copyrightText.height + 5
        width: copyrightText.width + 10
        color: "#7FFFFFFF"

        Text {
            id: copyrightText
            anchors.centerIn: parent
            textFormat: Text.StyledText
            font.pixelSize: 23
            text: "© <a href=\"https://www.openstreetmap.org/copyright\">OpenStreetMap</a> contributors"
            onLinkActivated: Qt.openUrlExternally(link)
        }
    }

}
