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
            let typeVal = aircraftInterface.getAircraftType();
            if (typeVal === -1)
            {
                edLoader.setSource('');
                return;
            }
            let typeString = typeVal === 0 ? "Jet" : typeVal === 1 ? "Prop" : "Turboprop";
            let engineString = aircraftInterface.getNumEngines() === 1 ? "Single" : aircraftInterface.getNumEngines() === 2 ? "Double" : "Quad";
            edLoader.setSource("qrc:/mfdPage/engineDisplay/" + typeString + engineString + ".qml", { "numTanks": aircraftInterface.getNumTanks() });
        }
    }

    MapItem {
        id: mapIdentifier
        focus: true
    }

    NavTopBar {}

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
