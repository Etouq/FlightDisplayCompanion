import QtQuick 2.15
import Pfd.Altimeter 1.0

Item {

    Item {
        x: 28.8
        y: 249.6
        width: 96
        height: 76.8
        clip: true

        Text {
            id: digit1Top
            x: 15.36
            anchors.baseline: parent.top
            anchors.baselineOffset: -1
            color: "white"
            font.bold: true
            font.family: "Roboto Mono"
            font.pixelSize: 48
            text: "X"
            transform: Translate {
                y: 0
            }
        }

        Text {
            id: digit1Bot
            x: 15.36
            anchors.baseline: parent.top
            anchors.baselineOffset: 54.72
            color: "white"
            font.bold: true
            font.family: "Roboto Mono"
            font.pixelSize: 48
            text: "X"
            transform: Translate {
                y: 0
            }
        }

        Text {
            id: digit2Top
            x: 42.24
            anchors.baseline: parent.top
            anchors.baselineOffset: -1
            color: "white"
            font.bold: true
            font.family: "Roboto Mono"
            font.pixelSize: 48
            text: "X"
            transform: Translate {
                y: 0
            }
        }

        Text {
            id: digit2Bot
            x: 42.24
            anchors.baseline: parent.top
            anchors.baselineOffset: 54.72
            color: "white"
            font.bold: true
            font.family: "Roboto Mono"
            font.pixelSize: 48
            text: "X"
            transform: Translate {
                y: 0
            }
        }

        Text {
            id: digit3Top
            x: 69.12
            anchors.baseline: parent.top
            anchors.baselineOffset: -1
            color: "white"
            font.bold: true
            font.family: "Roboto Mono"
            font.pixelSize: 48
            text: "X"
            transform: Translate {
                y: 0
            }
        }

        Text {
            id: digit3Bot
            x: 69.12
            anchors.baseline: parent.top
            anchors.baselineOffset: 54.72
            color: "white"
            font.bold: true
            font.family: "Roboto Mono"
            font.pixelSize: 48
            text: "X"
            transform: Translate {
                y: 0
            }
        }
    }


    Item {
        x: 124.8
        y: 230.4
        width: 67.2
        height: 115.2
        clip: true

        Item {
            id: endDigitsGroup
            y: 0

            Text {
                x: 6.72
                anchors.baseline: parent.top
                anchors.baselineOffset: -12.48
                color: "white"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 48
                text: Math.abs(Math.round((Altimeter.altitude + 20) % 100 / 10) % 10) + "0"
            }
            Text {
                x: 6.72
                anchors.baseline: parent.top
                anchors.baselineOffset: 30.72
                color: "white"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 48
                text: Math.abs(Math.round((Altimeter.altitude + 10) % 100 / 10) % 10) + "0"
            }
            Text {
                x: 6.72
                anchors.baseline: parent.top
                anchors.baselineOffset: 73.92
                color: "white"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 48
                text: Math.abs(Math.round(Altimeter.altitude % 100 / 10) % 10) + "0"
            }
            Text {
                x: 6.72
                anchors.baseline: parent.top
                anchors.baselineOffset: 117.12
                color: "white"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 48
                text: Math.abs(Math.round((Altimeter.altitude - 10) % 100 / 10) % 10) + "0"
            }
            Text {
                x: 6.72
                anchors.baseline: parent.top
                anchors.baselineOffset: 160.32
                color: "white"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 48
                text: Math.abs(Math.round((Altimeter.altitude - 20) % 100 / 10) % 10) + "0"
            }
        }
    }


    Connections {
        target: Altimeter
        function onAltitudeChanged() {
            updateDigits(Altimeter.altitude);
        }
    }

    Component.onCompleted: updateDigits(Altimeter.altitude);


    function updateDigits(_newAlt) {
        let endValue = _newAlt % 100;
        endDigitsGroup.y = endValue * 4.32 - Math.round(endValue / 10) * 43.2;

        let absAlt = Math.abs(_newAlt);
        if (absAlt >= 90) {
            let d3Value = (absAlt % 1000) / 100;

            digit3Bot.text = absAlt < 100 ? "" : Math.floor(d3Value);
            digit3Top.text = Math.ceil(d3Value) % 10;

            if (endValue > 90 || endValue < -90) {
                if (endValue < 0) {
                    digit3Bot.text = Math.ceil(d3Value) % 10;
                    digit3Top.text = absAlt < 100 ? "" : Math.floor(d3Value);
                }

                let translate = (endValue > 0 ? (endValue - 90) : (endValue + 100)) * 5.472;
                digit3Bot.transform[0].y = translate;
                digit3Top.transform[0].y = translate;
            }
            else {
                digit3Bot.transform[0].y = 0;
                digit3Top.transform[0].y = 0;
            }

            if (absAlt >= 990) {
                let d2Value = (absAlt % 10000) / 1000;

                digit2Bot.text = absAlt < 1000 ? "" : Math.floor(d2Value);
                digit2Top.text = Math.ceil(d2Value) % 10;

                if ((endValue > 90 || endValue < -90) && d3Value > 9) {
                    if (endValue < 0) {
                        digit2Bot.text = Math.ceil(d2Value) % 10;
                        digit2Top.text = absAlt < 1000 ? "" : Math.floor(d2Value);
                    }

                    let translate = (endValue > 0 ? (endValue - 90) : (endValue + 100)) * 5.472;
                    digit2Bot.transform[0].y = translate;
                    digit2Top.transform[0].y = translate;
                }
                else {
                    digit2Bot.transform[0].y = 0;
                    digit2Top.transform[0].y = 0;
                }

                if (absAlt >= 9990) {
                    let d1Value = (absAlt % 100000) / 10000;

                    digit1Bot.text = absAlt < 10000 ? "" : Math.floor(d1Value);
                    digit1Top.text = Math.ceil(d1Value) % 10;

                    if ((endValue > 90 || endValue < -90) && d3Value > 9 && d2Value > 9) {
                        if (endValue < 0) {
                            digit1Bot.text = Math.ceil(d1Value) % 10;
                            digit1Top.text = absAlt < 10000 ? "" : Math.floor(d1Value);
                        }

                        let translate = (endValue > 0 ? (endValue - 90) : (endValue + 100)) * 5.472;
                        digit1Bot.transform[0].y = translate;
                        digit1Top.transform[0].y = translate;
                    }
                    else {
                        digit1Bot.transform[0].y = 0;
                        digit1Top.transform[0].y = 0;
                    }
                }
                else {
                    digit1Bot.transform[0].y = 0;
                    digit1Top.transform[0].y = 0;

                    digit1Bot.text =_newAlt < 0 ? "-" : "";
                    digit1Top.text = "";
                }
            }
            else {
                digit2Bot.transform[0].y = 0;
                digit2Top.transform[0].y = 0;

                digit2Bot.text =_newAlt < 0 ? "-" : "";
                digit1Bot.text = "";
                digit1Top.text = "";
                digit2Top.text = "";
            }

        }
        else {
            digit3Bot.transform[0].y = 0;
            digit3Top.transform[0].y = 0;

            digit3Bot.text = _newAlt < 0 ? "-" : "";
            digit2Bot.text = "";
            digit1Bot.text = "";
            digit1Top.text = "";
            digit2Top.text = "";
        }

    }



}
