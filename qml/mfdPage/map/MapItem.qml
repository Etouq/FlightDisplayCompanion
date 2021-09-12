import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15
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

        states: [
            State {
                name: "northUpState"
                when: mfdInterface.mapOrientationMode == 0
                PropertyChanges { target: mapDisplay; bearing: 0 }
                PropertyChanges { target: planeIconRotation; angle: mfdInterface.planeTrueHdg }
            },
            State {
                name: "headingUpState"
                when: mfdInterface.mapOrientationMode == 1
                PropertyChanges { target: mapDisplay; bearing: mfdInterface.planeTrueHdg }
                PropertyChanges { target: planeIconRotation; angle: 0 }
            },
            State {
                name: "trackUpState"
                when: mfdInterface.mapOrientationMode == 2
                PropertyChanges { target: mapDisplay; bearing: hsiInterface.currentTrackAngle }
                PropertyChanges { target: planeIconRotation; angle: mfdInterface.planeTrueHdg - hsiInterface.currentTrackAngle }
            }
        ]


    }


    Map {
        id: overlayMap
        plugin: Plugin { name: "itemsoverlay" }
        anchors.fill: parent
        center: mapDisplay.center
        zoomLevel: currZoom
        gesture.enabled: false
        color: 'transparent'
        bearing: mapDisplay.bearing

        property bool rangeCircleEnabled: true

        Connections {
            target: settingsInterface
            function onShowRangeRingsChanged() {
                overlayMap.rangeCircleEnabled = settingsInterface.getShowRangeRings();
            }
        }

        Component.onCompleted: overlayMap.rangeCircleEnabled = settingsInterface.getShowRangeRings();

        RangeCircles {
            visible: !panModeActive && parent.rangeCircleEnabled
        }

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

            coordinate: mfdInterface.currCoordinates
            sourceItem: Shape {
                id: planeIconSource
                width: 105 * mfdInterface.planeIconScaleFactor
                height: 105 * mfdInterface.planeIconScaleFactor

                ShapePath {
                    fillColor: mfdInterface.planeIconColor
                    strokeColor: mfdInterface.planeIconBorderColor
                    strokeWidth: 1.5 * mfdInterface.planeIconScaleFactor

                    scale: Qt.size(mfdInterface.planeIconScaleFactor, mfdInterface.planeIconScaleFactor)
                    PathMove { x: 37.759575; y: 88.151385 }
                    PathArc { radiusX: 12.222; radiusY: 12.222; xAxisRotation: 90; useLargeArc: false; direction: PathArc.Clockwise; x: 38.221575; y: 85.463385 }
                    PathArc { radiusX: 4.011; radiusY: 4.011; xAxisRotation: 90; useLargeArc: false; direction: PathArc.Clockwise; x: 40.111575; y: 83.363385 }
                    PathLine { x: 47.608575; y: 80.549385 }
                    PathArc { radiusX: 2.247; radiusY: 2.247; xAxisRotation: 90; useLargeArc: false; direction: PathArc.Counterclockwise; x: 48.259575; y: 78.806385 }
                    PathLine { x: 47.251575; y: 62.132385 }
                    PathLine { x: 20.959575; y: 70.007385 }
                    PathArc { radiusX: 0.756; radiusY: 0.756; xAxisRotation: 90; useLargeArc: false; direction: PathArc.Clockwise; x: 19.972575; y: 69.335385 }
                    PathCubic { control1X: 19.783575; control1Y: 67.235385; control2X: 19.804575; control2Y: 65.723385; x: 21.484575; y: 64.484385 }
                    PathLine { x: 46.726575; y: 46.151385 }
                    PathArc { radiusX: 0.924; radiusY: 0.924; xAxisRotation: 90; useLargeArc: false; direction: PathArc.Counterclockwise; x: 47.062575; y: 45.458385 }
                    PathCubic { control1X: 47.188575; control1Y: 42.728385; control2X: 47.776575; control2Y: 27.629385; x: 48.196575; y: 24.458385 }
                    PathArc { radiusX: 12.6; radiusY: 12.6; xAxisRotation: 90; useLargeArc: false; direction: PathArc.Clockwise; x: 50.548575; y: 17.549385 }
                    PathArc { radiusX: 2.415; radiusY: 2.415; xAxisRotation: 90; useLargeArc: false; direction: PathArc.Clockwise; x: 53.950575; y: 17.549385 }
                    PathArc { radiusX: 12.768; radiusY: 12.768; xAxisRotation: 90; useLargeArc: false; direction: PathArc.Clockwise; x: 56.365575; y: 24.437385 }
                    PathCubic { control1X: 56.806575; control1Y: 27.692385; control2X: 57.520575; control2Y: 42.791385; x: 57.667575; y: 45.437385 }
                    PathArc { radiusX: 0.84; radiusY: 0.84; xAxisRotation: 90; useLargeArc: false; direction: PathArc.Counterclockwise; x: 58.003575; y: 46.109385 }
                    PathLine { x: 83.497575; y: 64.253385 }
                    PathCubic { control1X: 85.177575; control1Y: 65.471385; control2X: 85.219575; control2Y: 67.004385; x: 85.030575; y: 69.083385 }
                    PathArc { radiusX: 0.735; radiusY: 0.735; xAxisRotation: 90; useLargeArc: false; direction: PathArc.Clockwise; x: 84.064575; y: 69.755385 }
                    PathLine { x: 57.709575; y: 62.153385 }
                    PathLine { x: 56.848575; y: 78.953385 }
                    PathArc { radiusX: 2.1; radiusY: 2.1; xAxisRotation: 90; useLargeArc: false; direction: PathArc.Counterclockwise; x: 57.499575; y: 80.675385 }
                    PathLine { x: 65.059575; y: 83.321385 }
                    PathArc { radiusX: 4.2; radiusY: 4.2; xAxisRotation: 90; useLargeArc: false; direction: PathArc.Clockwise; x: 66.949575; y: 85.421385 }
                    PathArc { radiusX: 13.944; radiusY: 13.944; xAxisRotation: 90; useLargeArc: false; direction: PathArc.Clockwise; x: 67.432575; y: 88.109385 }
                    PathLine { x: 37.759575; y: 88.151385 }
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
