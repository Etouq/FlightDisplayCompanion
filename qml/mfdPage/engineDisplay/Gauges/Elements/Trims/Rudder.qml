import QtQuick 2.15
import QtQuick.Shapes 1.15
import Mfd.Engine 1.0

Item {
    id: main

    width: 126
    height: 27


    Text {
        id: rudText
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.top
        anchors.bottomMargin: 11
        color: "white"
        font.pixelSize: 24
        font.family: "Roboto Mono"
        font.bold: true
        text: "RUD"
    }

    Rectangle {
        id: horizontalBar
        x: 0
        y: 24
        width: 126
        height: 3
        color: "white"
    }

    Rectangle {
        id: leftBar
        x: 0
        y: 4.5
        width: 3
        height: 22.5
        color: "white"
    }

    Rectangle {
        id: rightBar
        x: 123
        y: 4.5
        width: 3
        height: 22.5
        color: "white"
    }

    Rectangle {
        id: centerGrad
        x: 61.5
        y: 16.5
        width: 3
        height: 7.5
        color: "white"
    }

    Shape {
        id: cursor
        anchors.fill: parent

        transform: Translate {
            x: EngineMisc.rudderTrimTransformValue
        }

        ShapePath {
            fillColor: "aqua"
            strokeColor: "transparent"

            PathMove {
                x: 57
                y: 0
            }
            PathLine {
                relativeX: 0
                relativeY: 12
            }
            PathLine {
                relativeX: 6
                relativeY: 12
            }
            PathLine {
                relativeX: 6
                relativeY: -12
            }
            PathLine {
                relativeX: 0
                relativeY: -12
            }
        }

        Text {
            id: trimValueText
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.top
            anchors.bottomMargin: -1

            font {
                family: "Roboto Mono"
                bold: true
                pixelSize: 15
            }

            color: "white"
            text: (EngineMisc.rudderValue < 0 ? "" : " ") + (EngineMisc.rudderValue / 0.6).toFixed() + "°"
        }
    }
}
