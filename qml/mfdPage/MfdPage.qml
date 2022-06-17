import QtQuick 2.15
import QtQuick.Controls 2.15

import "map"
import "engineDisplay"

Item {

    function clearAircraft() {
        edLoader.setSource('');
    }

    Connections {
        target: gaugeInterface
        function onGaugesLoaded() {


            let numEngines = 2;
            let numGauges = 3;
            const engineString = numEngines === 2 ? "Double" : numEngines === 3 ? "Triple" : "Quad";
            const gaugeString = numGauges === 2 ? "Double" : numGauges === 3 ? "Triple" : "Quad";
            edLoader.setSource("qrc:/mfdPage/engineDisplay/Gauges/Layouts/" + engineString + "Engine/" + gaugeString + "Gauge.qml");
        }
    }

    MapItem {
        id: mapIdentifier
        focus: true
    }

    NavTopBar {}

    Rectangle {
        x: 420
        y: 48
        width: 195
        height: 40
        color: "#1A1D21"

        Text {
            property var orientationStrings: ["NORTH UP", "HEADING UP", "TRACK UP"]
            anchors.centerIn: parent
            font.pixelSize: 31
            font.bold: true
            font.family: "Roboto Mono"
            color: "white"
            text: orientationStrings[mfdInterface.mapOrientationMode]
        }
    }

    Rectangle {
        x: 0
        y: 0
        width: 420
        height: 1200
        color: "#1A1D21"

        Loader {
            id: edLoader
            asynchronous: true
            anchors.fill: parent
        }

    }

}
