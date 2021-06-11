import QtQuick 2.15
import QtQuick.Shapes 1.15

Shape {
    id: main

    property real yStart: 0


    ShapePath {
        id: wing
        fillColor: "transparent"
        strokeColor: "white"
        strokeWidth: 1.5

        PathMove {
            x: 179.49885
            y: main.yStart - 0.75
        }
        PathCubic {
            relativeControl1X: -16.66845
            relativeControl1Y: -3.26145
            relativeControl2X: -50.49885
            relativeControl2Y: -8.85
            relativeX: -76.33635
            relativeY: -5.85
        }
        PathCubic {
            relativeControl1X: -72.6
            relativeControl1Y: 9.9
            relativeControl2X: -73.1625
            relativeControl2Y: 42
            relativeX: 3.3
            relativeY: 46.2
        }
        PathCubic {
            relativeControl1X: 39.6
            relativeControl1Y: 3.3
            relativeControl2X: 89.1
            relativeControl2Y: 3.3
            relativeX: 155.1
            relativeY: 0
        }
        PathCubic {
            relativeControl1X: -16.5
            relativeControl1Y: -9.9
            relativeControl2X: -6
            relativeControl2Y: -25.2
            relativeX: 3.3
            relativeY: -23.1
        }
        PathCubic {
            relativeControl1X: -9.3
            relativeControl1Y: -2.1
            relativeControl2X: -25.0704
            relativeControl2Y: -5.36295
            relativeX: -29.2821
            relativeY: -6.20085
        }
        PathLine {
            x: 179.49885
            y: main.yStart - 0.75
        }
    }

    Shape {
        id: flaps
        transform: Rotation {
            angle: commonGaugeProperties.flapsAngle
            origin.x: 269.8124972
            origin.y: main.yStart + 28.05
        }
        ShapePath {
            fillColor: "white"
            strokeColor: "transparent"

            PathMove {
                x: 270.5625
                y: main.yStart + 37.95
            }
            PathQuad {
                relativeControlX: -23.1
                relativeControlY: -9.9
                relativeX: 0
                relativeY: -19.8
            }
            PathQuad {
                relativeControlX: 115.5
                relativeControlY: 16.5
                relativeX: 0
                relativeY: 19.8
            }
        }
    }

    Text {
        id: flapsText
        visible: commonGaugeProperties.showFlapsText
        anchors.left: parent.left
        anchors.leftMargin: 360.5624972
        anchors.baseline: parent.top
        anchors.baselineOffset: main.yStart + 39.6
        color: "white"
        font.pixelSize: 23
        font.family: "Roboto Mono"
        font.bold: true
        text: commonGaugeProperties.flapsValue
    }


}
