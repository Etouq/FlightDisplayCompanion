import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQml 2.15
import Mfd 1.0
import Mfd.GeoMapPage 1.0
import TypeEnums 1.0

import "GeoMapElem"
import "EngineDisplay"

Item {

    function clearAircraft() {
        edLoader.setSource('');
    }

    Connections {
        target: MfdRoot
        function onGaugesLoaded(layoutPath: string) {
            edLoader.setSource("qrc:/MfdPage/EngineDisplay/Gauges/Layouts/" + layoutPath + ".qml");
        }
    }

    GeoMapElem {
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
            id: mapOrientationText

            anchors.centerIn: parent
            font.pixelSize: 31
            font.bold: true
            font.family: "Roboto Mono"
            color: "white"
            text: "NORTH UP"

            Component.onCompleted: function() {
                mapOrientationText.text = mapOrientationToString();
            }

            Connections {
                target: GeoMapPage
                function onRotationModeChanged() {
                    mapOrientationText.text = mapOrientationToString();
                }
            }

            function mapOrientationToString() {
                switch (GeoMapPage.rotationMode) {
                    case MapRotationMode.NORTH_UP:
                        return "NORTH UP";
                    case MapRotationMode.DTK_UP:
                        return "DTK UP";
                    case MapRotationMode.HDG_UP:
                        return "HDG UP";
                    case MapRotationMode.TRACK_UP:
                        return "TRACK UP";
                }
            }
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
