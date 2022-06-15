import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {
    id: main

    property real elevTop: 0
    property bool noElevTrim: false
    property bool noRudderTrim: false


    Text {
        id: ailText
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: main.noElevTrim ? 210 : 267
        anchors.baseline: parent.top
        anchors.baselineOffset: main.elevTop + (main.noRudderTrim ? 85.5375 : 118.575)
        color: "white"
        font.pixelSize: 24
        font.family: "Roboto Mono"
        font.bold: true
        text: "AIL"
    }

    Rectangle {
        id: horizontalBar
        x: main.noElevTrim ? 147 : 204
        y: main.elevTop + (main.noRudderTrim ? 34.4625 : 67.5)
        width: 126
        height: 3
        color: "white"
    }

    Rectangle {
        id: leftBar
        x: main.noElevTrim ? 147 : 204
        y: main.elevTop + (main.noRudderTrim ? 34.4625 : 67.5)
        width: 3
        height: 22.5
        color: "white"
    }

    Rectangle {
        id: rightBar
        x: main.noElevTrim ? 270 : 327
        y: main.elevTop + (main.noRudderTrim ? 34.4625 : 67.5)
        width: 3
        height: 22.5
        color: "white"
    }

    Rectangle {
        id: centerGrad
        x: main.noElevTrim ? 208.5 : 265.5
        y: main.elevTop + (main.noRudderTrim ? 37.4625 : 70.5)
        width: 3
        height: 7.5//maybe increase to 9.75
        color: "white"
    }

    Shape {
        id: cursor
        transform: Translate { x: commonGaugeProperties.aileronTrimTransformValue }
        ShapePath {
            fillColor: "aqua"
            strokeColor: "transparent"

            PathMove {
                x: main.noElevTrim ? 204 : 261
                y: main.elevTop + (main.noRudderTrim ? 61.4625 : 94.5)
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
    }
}
