import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {

    Shape {
        ShapePath {
            fillColor: iasInterface.redCursor ? "red" : "#1a1d21"
            strokeColor: "transparent"

            PathMove { x: 192; y: 336 }
            PathLine { x: 163.2; y: 297.6 }
            PathLine { x: 144; y: 297.6 }
            PathLine { x: 144; y: 278.4 }
            PathLine { x: 96; y: 278.4 }
            PathLine { x: 96; y: 297.6 }
            PathLine { x: 0; y: 297.6 }
            PathLine { x: 0; y: 374.4 }
            PathLine { x: 96; y: 374.4 }
            PathLine { x: 96; y: 393.6 }
            PathLine { x: 144; y: 393.6 }
            PathLine { x: 144; y: 374.4 }
            PathLine { x: 163.2; y: 374.4 }
        }
    }

    Item {
        y: 297.6
        width: 96
        height: 76.8
        clip: true

        Text {
            id: digit1Top
            x: 26.88
            anchors.baseline: parent.top
            anchors.baselineOffset: -0.96
            color: "white"
            font.bold: true
            font.family: "Roboto Mono"
            font.pixelSize: 48
            text: "-"
            transform: Translate {
                y: 0
            }
        }

        Text {
            id: digit1Bot
            x: 26.88
            anchors.baseline: parent.top
            anchors.baselineOffset: 52.8
            color: "white"
            font.bold: true
            font.family: "Roboto Mono"
            font.pixelSize: 48
            text: "-"
            transform: Translate {
                y: 0
            }
        }

        Text {
            id: digit2Top
            x: 67.2
            anchors.baseline: parent.top
            anchors.baselineOffset: -0.96
            color: "white"
            font.bold: true
            font.family: "Roboto Mono"
            font.pixelSize: 48
            text: "-"
            transform: Translate {
                y: 0
            }
        }

        Text {
            id: digit2Bot
            x: 67.2
            anchors.baseline: parent.top
            anchors.baselineOffset: 52.8
            color: "white"
            font.bold: true
            font.family: "Roboto Mono"
            font.pixelSize: 48
            text: "-"
            transform: Translate {
                y: 0
            }
        }
    }


    Item {
        x: 96
        y: 278.4
        width: 67.2
        height: 115.2
        clip: true

        Item {
            id: endDigitsGroup
            y: 0

            property int endCenter: 0

            Text {
                x: 11.52
                anchors.baseline: parent.top
                anchors.baselineOffset: -14.4
                color: "white"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 48
                text: iasInterface.rawAirspeed <= 20 ? " " : (2 + endDigitsGroup.endCenter) % 10
            }

            Text {
                x: 11.52
                anchors.baseline: parent.top
                anchors.baselineOffset: 28.8
                color: "white"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 48
                text: iasInterface.rawAirspeed <= 20 ? " " : (1 + endDigitsGroup.endCenter) % 10
            }

            Text {
                x: 11.52
                anchors.baseline: parent.top
                anchors.baselineOffset: 72
                color: "white"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 48
                text: iasInterface.rawAirspeed <= 20 ? "-" : endDigitsGroup.endCenter % 10
            }

            Text {
                x: 11.52
                anchors.baseline: parent.top
                anchors.baselineOffset: 115.2
                color: "white"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 48
                text: iasInterface.rawAirspeed <= 20 ? " " : (9 + endDigitsGroup.endCenter) % 10
            }

            Text {
                x: 11.52
                anchors.baseline: parent.top
                anchors.baselineOffset: 158.4
                color: "white"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 48
                text: iasInterface.rawAirspeed <= 20 ? " " : (8 + endDigitsGroup.endCenter) % 10
            }
        }
    }

    Connections {
        target: iasInterface
        function onAirspeedChanged() {
            updateDigits(iasInterface.airspeed);
        }
    }

    function updateDigits(_newSpeed) {
        let endValue = _newSpeed % 10;
        let endCenter = Math.round(endValue);
        endDigitsGroup.endCenter = endCenter;
        endDigitsGroup.y = (endValue - endCenter) * 43.2;

        if (iasInterface.rawAirspeed > 20) {
            let d2Value = (_newSpeed % 100) / 10;
            digit2Bot.text = Math.floor(d2Value);
            digit2Top.text = Math.ceil(d2Value) % 10;
            if (endValue > 9) {
                let translate = (endValue - 9) * 52.8;
                digit2Bot.transform[0].y = translate;
                digit2Top.transform[0].y = translate;
            }
            else {
                digit2Bot.transform[0].y = 0;
                digit2Top.transform[0].y = 0;
            }

            if (_newSpeed >= 99) {
                let d1Value = (_newSpeed % 1000) / 100;
                digit1Bot.text = _newSpeed < 100 ? "" : Math.floor(d1Value);
                digit1Top.text = Math.ceil(d1Value) % 10;
                if (endValue > 9 && d2Value > 9) {
                    let translate = (endValue - 9) * 52.8;
                    digit1Bot.transform[0].y = translate;
                    digit1Top.transform[0].y = translate;
                }
                else {
                    digit1Bot.transform[0].y = 0;
                    digit1Top.transform[0].y = 0;
                }
            }
            else {
                digit1Bot.text = "";
                digit1Top.text = "";
            }
        }
        else {
            digit2Bot.text = "-";
            digit1Bot.text = "-";
            digit1Bot.transform[0].y = 0;
            digit1Top.transform[0].y = 0;
            digit2Bot.transform[0].y = 0;
            digit2Top.transform[0].y = 0;
        }
    }

}
