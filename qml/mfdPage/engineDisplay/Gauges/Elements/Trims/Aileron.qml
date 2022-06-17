import QtQuick 2.15
import QtQuick.Shapes 1.15
import Mfd.Engine 1.0

Item {
    id: main

    width: 126
    height: 27

    Text {
        id: ailText
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.bottom
        anchors.topMargin: 11
        color: "white"
        font.pixelSize: 24
        font.family: "Roboto Mono"
        font.bold: true
        text: "AIL"
    }

    Rectangle {
        id: horizontalBar
        x: 0
        y: 0
        width: 126
        height: 3
        color: "white"
    }

    Rectangle {
        id: leftBar
        x: 0
        y: 0
        width: 3
        height: 22.5
        color: "white"
    }

    Rectangle {
        id: rightBar
        x: 123
        y: 0
        width: 3
        height: 22.5
        color: "white"
    }

    Rectangle {
        id: centerGrad
        x: 61.5
        y: 3
        width: 3
        height: 7.5//maybe increase to 9.75
        color: "white"
    }

    Shape {
        id: cursor
        anchors.fill: parent

        transform: Translate {
            x: EngineMisc.aileronTrimTransformValue
        }

        ShapePath {
            fillColor: "aqua"
            strokeColor: "transparent"

            PathMove {
                x: 57
                y: 27
            }
            PathLine {
                relativeX: 0
                relativeY: -12
            }
            PathLine {
                relativeX: 6
                relativeY: -12
            }
            PathLine {
                relativeX: 6
                relativeY: 12
            }
            PathLine {
                relativeX: 0
                relativeY: 12
            }
        }

        Text {
            id: trimValueText
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.bottom
            anchors.topMargin: -1

            font {
                family: "Roboto Mono"
                bold: true
                pixelSize: 15
            }

            color: "white"
            text: (EngineMisc.aileronValue < 0 ? "" : " ") + (EngineMisc.aileronValue / 0.6).toFixed() + "°"
        }
    }
}
