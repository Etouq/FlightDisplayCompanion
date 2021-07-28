import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQuick.Controls 2.15
import QtQml 2.15

Item {
    x: 420
    width: 1500
    height: 1200



    property variant zoomLevels: [0.1, 0.2, 0.3, 0.5, 1, 2, 3, 5, 10, 15, 20, 35, 50, 100, 150, 200, 250]
    property bool panModeActive: false
    property int zoomLevelIdx: 9
    property real currZoom: 9


    property bool firstCoordinateReceived: false // used to indicate we have received the first coordinate (to circumvent zeroes)
    property var lastCoordinate: QtPositioning.coordinate(0,0)
    property double startTime: new Date().getTime()

    property int lastIndex: 0

    Connections {
        target: mfdInterface
        function onCurrCoordinatesChanged() {
            if (!mfdInterface.simRunning)
            {
                return;
            }

            if (!firstCoordinateReceived)
            {
                startTime = new Date().getTime();
                lastCoordinate = mfdInterface.currCoordinates;
                flightRouteLog.addCoordinate(lastCoordinate);
                firstCoordinateReceived = true;
            }
            else if (new Date().getTime() - startTime >= 500 &&
                    flightRouteLog.coordinateAt(flightRouteLog.pathLength() - 1).distanceTo(mfdInterface.currCoordinates) >= 10) {
                startTime = new Date().getTime();
                lastCoordinate = mfdInterface.currCoordinates;
                flightRouteLog.addCoordinate(lastCoordinate);
            }
        }
    }

    Connections {
        target: mfdInterface
        function onSimRunningChanged() {
            if (mfdInterface.simRunning) { //wipe the flightlog for the new flight
                for (let i = flightRouteLog.pathLength() - 1; i >= 0; i--)
                    flightRouteLog.removeCoordinate(i);
                firstCoordinateReceived = false;
            }
        }
    }

    function fillFlightplanData() {
        var fpPath = [];
        flightPlanMapRoute.path = [];
        flightPlanMapRoute1.path = [];
        flightPlanMapRoute2.path = [];
        flightPlanMapRoute3.path = [];
        flightPlanMapRoute4.path = [];

        flightPlanMapRoute1.enabled = false;
        flightPlanMapRoute1.visible = false;
        flightPlanMapRoute2.enabled = false;
        flightPlanMapRoute2.visible = false;
        flightPlanMapRoute3.enabled = false;
        flightPlanMapRoute3.visible = false;
        flightPlanMapRoute4.enabled = false;
        flightPlanMapRoute4.visible = false;

        flightplanWpListModel.clear();

        for (let i = 0; i < mfdInterface.getFlightPlanSize(); i++) {
            let coord = mfdInterface.getFpPositionAt(i);
            fpPath.push(coord);
            flightplanWpListModel.append({"posLat": coord.latitude, "posLon": coord.longitude, "ident": mfdInterface.getFpIdentAt(i), "type": mfdInterface.getFpWpTypeAt(i)});
        }

        if (fpPath.length <= 60)
        {
            flightPlanMapRoute.path = fpPath;
            return;
        }

        flightPlanMapRoute.path = fpPath.slice(0, 61);

        flightPlanMapRoute1.enabled = true;
        flightPlanMapRoute1.visible = true;
        flightPlanMapRoute1.path = fpPath.slice(60, 121);

        if (fpPath.length <= 120)
            return;

        flightPlanMapRoute2.enabled = true;
        flightPlanMapRoute2.visible = true;
        flightPlanMapRoute2.path = fpPath.slice(120, 181);

        if (fpPath.length <= 180)
            return;

        flightPlanMapRoute3.enabled = true;
        flightPlanMapRoute3.visible = true;
        flightPlanMapRoute3.path = fpPath.slice(180, 241);

        if (fpPath.length <= 240)
            return;

        flightPlanMapRoute4.enabled = true;
        flightPlanMapRoute4.visible = true;
        flightPlanMapRoute4.path = fpPath.slice(240);
    }

    Connections {
        target: mfdInterface
        function onFlightplanChanged() {
            fillFlightplanData();
        }
    }

    Component.onCompleted: {
        fillFlightplanData();
    }


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

    ListModel {
        id: flightplanWpListModel
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
        gesture.acceptedGestures: MapGestureArea.PanGesture | MapGestureArea.FlickGesture
        gesture.onPanStarted: panModeActive = true;
        gesture.onFlickStarted: panModeActive = true;
        gesture.onFlickFinished: if(!panModeActive) mapDisplay.center = mfdInterface.currCoordinates;
        gesture.preventStealing: true

        activeMapType: supportedMapTypes[supportedMapTypes.length - 1]

        Binding {
            target: mapDisplay
            property: 'center'
            value: mfdInterface.currCoordinates
            when: !panModeActive
            restoreMode: Binding.RestoreBinding
        }


    }


    Map {
        id: overlayMap
        plugin: Plugin { name: "itemsoverlay" }
        anchors.fill: parent
        center: mapDisplay.center
        zoomLevel: currZoom
        gesture.enabled: false
        color: 'transparent'

        property bool rangeCircleEnabled: trues

        Connections {
            target: settingsInterface
            function onShowRangeRingsChanged() {
                overlayMap.rangeCircleEnabled = settingsInterface.getShowRangeRings();
            }
        }

        Component.onCompleted: overlayMap.rangeCircleEnabled = settingsInterface.getShowRangeRings();

        RangeCircles { visible: !panModeActive && parent.rangeCircleEnabled }

        MapCircle {
            id: fuelRangeCircle
            property bool fuelCircleEnabled: true
            center: mfdInterface.currCoordinates
            radius: 1852 * commonGaugeProperties.fuelRange
            border.width: 3
            border.color: "green"
            visible: commonGaugeProperties.fuelRange > 0 && fuelCircleEnabled

            Connections {
                target: settingsInterface
                function onShowMapFuelRangeChanged() {
                    fuelRangeCircle.fuelCircleEnabled = settingsInterface.getShowMapFuelRange();
                }
            }

            Component.onCompleted: fuelRangeCircle.fuelCircleEnabled = settingsInterface.getShowMapFuelRange();
        }


        MapPolyline {
            id: flightPlanMapRoute
            line.width: 6
            line.color: "#ed008c"
            path: []
        }

        MapPolyline {
            id: flightPlanMapRoute1
            enabled: false
            visible: false
            line.width: 6
            line.color: "#ed008c"
            path: []
        }

        MapPolyline {
            id: flightPlanMapRoute2
            enabled: false
            visible: false
            line.width: 6
            line.color: "#ed008c"
            path: []
        }

        MapPolyline {
            id: flightPlanMapRoute3
            enabled: false
            visible: false
            line.width: 6
            line.color: "#ed008c"
            path: []
        }

        MapPolyline {
            id: flightPlanMapRoute4
            enabled: false
            visible: false
            line.width: 6
            line.color: "#ed008c"
            path: []
        }


        MapPolyline {
            id: flightRouteLog
        }

        FlightplanWpIcons {}


        MapQuickItem {
            id: planeIcon
            anchorPoint.x: planeIconSource.width / 2
            anchorPoint.y: planeIconSource.height / 2
            width: 105
            height: 105
            coordinate: mfdInterface.currCoordinates
            sourceItem: Image {
                id: planeIconSource
                source: "qrc:/images/planeIconOutligned.svg"
                width: 105
                height: 105
                smooth: true

                transform: Rotation
                {
                    origin.x: planeIconSource.width / 2
                    origin.y: planeIconSource.height / 2
                    angle: mfdInterface.planeTrueHdg
                }
            }
        }

    }

    MapButtons {}



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
