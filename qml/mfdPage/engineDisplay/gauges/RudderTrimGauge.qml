import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {
    id: main

    property real elevTop: 0
    property bool noElevTrim: false
    property bool noAileronTrim: false


    Text {
        id: rudText
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: main.noElevTrim ? 210 : 267
        anchors.baseline: parent.top
        anchors.baselineOffset: main.elevTop + (main.noAileronTrim ? 52.9125 : 21.3)
        color: "white"
        font.pixelSize: 24
        font.family: "Roboto Mono"
        font.bold: true
        text: "RUD"
    }

    Rectangle {
        id: horizontalBar
        x: main.noElevTrim ? 147 : 204
        y: main.elevTop + (main.noAileronTrim ? 81.1125 : 49.5)
        width: 126
        height: 3
        color: "white"
    }

    Rectangle {
        id: leftBar
        x: main.noElevTrim ? 147 : 204
        y: main.elevTop + (main.noAileronTrim ? 61.6125 : 30)
        width: 3
        height: 22.5
        color: "white"
    }

    Rectangle {
        id: rightBar
        x: main.noElevTrim ? 270 : 327
        y: main.elevTop + (main.noAileronTrim ? 61.6125 : 30)
        width: 3
        height: 22.5
        color: "white"
    }

    Rectangle {
        id: centerGrad
        x: main.noElevTrim ? 208.5 : 265.5
        y: main.elevTop + (main.noAileronTrim ? 73.6125 : 42)
        width: 3
        height: 7.5
        color: "white"
    }

    Shape {
        id: cursor
        transform: Translate { x: commonGaugeProperties.rudderTrimTransformValue }
        ShapePath {
            fillColor: "aqua"
            strokeColor: "transparent"

            PathMove {
                x: main.noElevTrim ? 204 : 261
                y: main.elevTop + (main.noAileronTrim ? 57.1125 : 25.5)
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
    }
}
