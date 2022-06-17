import QtQuick 2.15
import QtQuick.Shapes 1.15
import Mfd.Engine 1.0

Item {
    id: main

    width: 15
    height: 120

    Text {
        id: elevText
        anchors.left: parent.left
        anchors.leftMargin: -22.5
        anchors.baseline: parent.top
        anchors.baselineOffset: -12
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        text: "ELEV"
    }

    Rectangle {
        id: verticalBar
        x: 15
        y: -3
        width: 3
        height: 126
        color: "white"
    }

    Rectangle {
        id: topBar
        x: 0
        y: -3
        width: 15
        height: 3
        color: "white"
    }

    Text {
        id: dnText
        anchors.left: parent.left
        anchors.leftMargin: -22.5
        anchors.verticalCenter: topBar.verticalCenter
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        text: "DN"
    }

    Rectangle {
        id: bottomBar
        x: 0
        y: 120
        width: 15
        height: 3
        color: "white"
    }

    Text {
        id: upText
        anchors.left: parent.left
        anchors.leftMargin: -22.5
        anchors.verticalCenter: bottomBar.verticalCenter
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        text: "UP"
    }

    Rectangle {
        id: centerGrad
        x: 7.5
        y: 58.5
        width: 7.5
        height: 3
        color: "white"
    }

    Shape {
        id: cursor

        transform: Translate {
            y: EngineMisc.elevTrimTransformValue
        }

        ShapePath {
            fillColor: "aqua"
            strokeColor: "transparent"

            PathMove {
                x: 0
                y: 54
            }
            PathLine {
                relativeX: 7.5
                relativeY: 0
            }
            PathLine {
                relativeX: 7.5
                relativeY: 6
            }
            PathLine {
                relativeX: -7.5
                relativeY: 6
            }
            PathLine {
                relativeX: -7.5
                relativeY: 0
            }
        }
    }

    Text {
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.left
        anchors.rightMargin: 3
        font {
            family: "Roboto Mono"
            bold: true
            pixelSize: 15
        }

        transform: Translate {
            y: Math.max(Math.min(EngineMisc.elevTrimTransformValue, 45), -45)
        }

        color: "white"
        text: (EngineMisc.elevTrimValue / 0.6).toFixed() + "%"
    }

}
