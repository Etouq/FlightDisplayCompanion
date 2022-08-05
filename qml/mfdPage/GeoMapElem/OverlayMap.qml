import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15
import QtQml 2.15

import Mfd.GeoMapPage 1.0
import Mfd.Engine 1.0
import Mfd.Flightplan 1.0

import Pfd.HSIndicator 1.0

import General.Settings 1.0

import IO.Network 1.0
import TypeEnums 1.0

import "FlightplanLayer"

Item {
    id: overlayMapRoot

    x: 0
    y: 0
    width: 1500
    height: 1200

    required property real zoomSetting

    property alias mapCenter: overlayMap.center
    property alias mapBearing: overlayMap.bearing
    property alias currZoom: overlayMap.zoomLevel


    property bool panModeActive: false


    property bool firstCoordinateReceived: false // used to indicate we have received the first coordinate (to circumvent zeroes)
    property var lastCoordinate: QtPositioning.coordinate(0,0)
    property double startTime: new Date().getTime()


    Connections {
        target: GeoMapPage
        function onUserPositionChanged() {
            if (!NetworkClient.simRunning)
            {
                return;
            }

            if (!firstCoordinateReceived)
            {
                overlayMapRoot.startTime = new Date().getTime();
                overlayMapRoot.lastCoordinate = GeoMapPage.userPosition;
                flightRouteLog.addCoordinate(lastCoordinate);
                overlayMapRoot.firstCoordinateReceived = true;
            }
            else if (new Date().getTime() - overlayMapRoot.startTime >= 500 &&
                    flightRouteLog.coordinateAt(flightRouteLog.pathLength() - 1).distanceTo(GeoMapPage.userPosition) >= 10) {
                overlayMapRoot.startTime = new Date().getTime();
                overlayMapRoot.lastCoordinate = GeoMapPage.userPosition;
                flightRouteLog.addCoordinate(overlayMapRoot.lastCoordinate);
            }
        }
    }

    Connections {
        target: NetworkClient
        function onSimRunningChanged() {
            if (NetworkClient.simRunning) { //wipe the flightlog for the new flight
                flightRouteLog.path = [];
                overlayMapRoot.firstCoordinateReceived = false;
            }
        }
    }



    Map {
        id: overlayMap

        plugin: Plugin { name: "itemsoverlay" }

        anchors.fill: parent

        gesture.enabled: false
        color: 'transparent'


        RangeCircles {
            visible: !overlayMapRoot.panModeActive && GenSettings.showRangeRings
            zoomSetting: overlayMapRoot.zoomSetting
        }

        MapCircle {
            id: fuelRangeCircle

            center: GeoMapPage.userPosition
            radius: 1852 * EngineMisc.fuelRange
            border.width: 3
            border.color: "green"

            visible: EngineMisc.fuelRange > 0 && GenSettings.showFuelRangeRing
        }

        FlightplanLayer {
        }

        MapPolyline {
            id: flightRouteLog
        }

        MapQuickItem {
            id: planeIcon
            anchorPoint.x: planeIconSource.width / 2
            anchorPoint.y: planeIconSource.height / 2

            coordinate: GeoMapPage.userPosition

            sourceItem: Shape {
                id: planeIconSource
                width: 105 * GeoMapPage.iconScale
                height: 105 * GeoMapPage.iconScale

                ShapePath {
                    fillColor: GeoMapPage.iconColor
                    strokeColor: GeoMapPage.iconBorder
                    strokeWidth: GeoMapPage.iconScale

                    scale: Qt.size(GeoMapPage.iconScale, GeoMapPage.iconScale)
                    PathSvg { path: GeoMapPage.iconPath }
                }

                transform: Rotation
                {
                    id: planeIconRotation
                    origin.x: planeIconSource.width / 2
                    origin.y: planeIconSource.height / 2
                }
            }
        }

    }


    states: [
        State {
            name: "northUpState"
            when: GeoMapPage.rotationMode === MapRotationMode.NORTH_UP
            PropertyChanges { target: planeIconRotation; angle: GeoMapPage.trueHeading }
        },
        State {
            name: "headingUpState"
            when: GeoMapPage.mapOrientationMode === MapRotationMode.HDG_UP
            PropertyChanges { target: planeIconRotation; angle: 0 }
        },
        State {
            name: "trackUpState"
            when: GeoMapPage.mapOrientationMode === MapRotationMode.TRACK_UP
            PropertyChanges { target: planeIconRotation; angle: GeoMapPage.trueHeading - HSIndicator.currentTrackAngle }
        },
        State {
            name: "dtkUpState"
            when: GeoMapPage.mapOrientationMode === MapRotationMode.DTK_UP
            PropertyChanges { target: planeIconRotation; angle: GeoMapPage.trueHeading - Flightplan.wpDtk }
        }
    ]

}
