import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.WindInfo 1.0

Item {
    width: 135
    height: 90

    property int windMode: 1

    TapHandler {
        onTapped: {
            if (WindInfo.windStrength < 1) {
                if (windMode > 0)
                    windMode = 0;
                else
                    windMode = 1;
            }
            else {
                if (windMode >= 3)
                    windMode = 0;
                else
                    windMode++;
            }
        }
    }




    Rectangle {
        visible: windMode != 0
        anchors.fill: parent
        color: "#1a1d21"

        Text {
            visible: WindInfo.windStrength < 1
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.baseline: parent.top
            anchors.baselineOffset: 37.5
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 25
            font.bold: true
            text: "NO WIND"
        }

        Text {
            visible: WindInfo.windStrength < 1
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.baseline: parent.top
            anchors.baselineOffset: 67.5
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 25
            font.bold: true
            text: "DATA"
        }
    }

    Item {
        anchors.fill: parent
        visible: windMode == 1 && WindInfo.windStrength >= 1

        Shape {
            transform: Rotation {
                angle: WindInfo.windDirection < 180 ? 90 : -90
                origin.x: 33.75
                origin.y: 30
            }

            ShapePath {
                fillColor: "white"
                strokeColor: "transparent"

                PathMove { x: 33.75; y: 7.5 }
                PathLine { x: 26.25; y: 22.5 }
                PathLine { x: 31.5; y: 22.5 }
                PathLine { x: 31.5; y: 52.5 }
                PathLine { x: 36; y: 52.5 }
                PathLine { x: 36; y: 22.5 }
                PathLine { x: 41.25; y: 22.5 }
            }
        }

        Shape {
            transform: Rotation {
                angle: WindInfo.windDirection < 90 || WindInfo.windDirection > 270 ? 0 : 180
                origin.x: 33.75
                origin.y: 30
            }

            ShapePath {
                fillColor: "white"
                strokeColor: "transparent"

                PathMove { x: 33.75; y: 7.5 }
                PathLine { x: 26.25; y: 22.5 }
                PathLine { x: 31.5; y: 22.5 }
                PathLine { x: 31.5; y: 52.5 }
                PathLine { x: 36; y: 52.5 }
                PathLine { x: 36; y: 22.5 }
                PathLine { x: 41.25; y: 22.5 }
            }
        }

        Text {
            x: 75
            anchors.verticalCenter: parent.top
            anchors.verticalCenterOffset: 30
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 30
            font.bold: true
            text: Math.round(Math.abs(WindInfo.windStrength * Math.sin(WindInfo.windDirection / 180 * Math.PI)))
        }

        Text {
            anchors.horizontalCenter: parent.left
            anchors.horizontalCenterOffset: 33.75
            anchors.baseline: parent.top
            anchors.baselineOffset: 82.5
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 30
            font.bold: true
            text: Math.round(Math.abs(WindInfo.windStrength * Math.cos(WindInfo.windDirection / 180 * Math.PI)))
        }

    }

    Item {
        anchors.fill: parent
        visible: windMode == 2 && WindInfo.windStrength >= 1

        Shape {
            transform: Rotation {
                angle: WindInfo.windDirection
                origin.x: 33.75
                origin.y: 45
            }

            ShapePath {
                fillColor: "white"
                strokeColor: "transparent"

                PathMove { x: 33.75; y: 15 }
                PathLine { x: 22.25; y: 30 }
                PathLine { x: 31.5; y: 30 }
                PathLine { x: 31.5; y: 75 }
                PathLine { x: 36; y: 75 }
                PathLine { x: 36; y: 30 }
                PathLine { x: 45; y: 30 }
            }
        }

        Text {
            x: 75
            anchors.baseline: parent.top
            anchors.baselineOffset: 60
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 45
            font.bold: true
            text: Math.round(WindInfo.windStrength)
        }
    }

    Item {
        anchors.fill: parent
        visible: windMode == 3 && WindInfo.windStrength >= 1

        Shape {
            transform: Rotation {
                angle: WindInfo.windDirection
                origin.x: 33.75
                origin.y: 45
            }

            ShapePath {
                fillColor: "white"
                strokeColor: "transparent"

                PathMove { x: 33.75; y: 15 }
                PathLine { x: 22.25; y: 30 }
                PathLine { x: 31.5; y: 30 }
                PathLine { x: 31.5; y: 75 }
                PathLine { x: 36; y: 75 }
                PathLine { x: 36; y: 30 }
                PathLine { x: 45; y: 30 }
            }
        }

        Text {
            x: 60
            anchors.baseline: parent.top
            anchors.baselineOffset: 30
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 30
            font.bold: true
            text: Math.round(WindInfo.windTrueDirection) + "°"
        }

        Text {
            x: 60
            anchors.baseline: parent.top
            anchors.baselineOffset: 75
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 30
            font.bold: true
            text: Math.round(WindInfo.windStrength) + "KT"
        }
    }






}
