import QtQuick 2.15
import QtQuick.Shapes 1.15
import Mfd.Engine 1.0

Shape {
    id: main

    required property real yStart

    ShapePath {
        id: wing
        fillColor: "transparent"
        strokeColor: "white"
        strokeWidth: 1.5

        PathMove {
            x: 179.0625
            y: main.yStart
        }
        PathCubic {
            relativeControl1X: -16.5
            relativeControl1Y: -3.3
            relativeControl2X: -50.0625
            relativeControl2Y: -9.6
            relativeX: -75.9
            relativeY: -6.6
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
        PathLine {
            relativeX: -29.7
            relativeY: -6.6
        }
    }


    Shape {
        id: flaps
        transform: Rotation {
            angle: EngineMisc.flapsAngle
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
        visible: EngineMisc.showFlapsText
        anchors.left: parent.left
        anchors.leftMargin: 350.5624972
        anchors.baseline: parent.top
        anchors.baselineOffset: main.yStart + 39.6
        color: "white"
        font.pixelSize: 23
        font.family: "Roboto Mono"
        font.bold: true
        text: EngineMisc.flapsValue
    }

    Shape {
        id: spoilers
        transform: Rotation {
            angle: EngineMisc.spoilersAngle
            origin.x: 188.9624972
            origin.y: main.yStart + 1.275
        }
        ShapePath {
            fillColor: "white"
            strokeColor: "transparent"

            PathMove {
                x: 192.2625
                y: main.yStart + 6.6
            }
            PathQuad {
                relativeControlX: -14.025
                relativeControlY: -6.6
                relativeX: 0
                relativeY: -9.9
            }
            PathQuad {
                relativeControlX: 74.25
                relativeControlY: 14.85
                relativeX: 0
                relativeY: 9.9
            }
        }
    }

    Text {
        id: spoilersText
        visible: EngineMisc.showSpoilersText
        anchors.left: parent.left
        anchors.leftMargin: 233.5124972
        anchors.baseline: parent.top
        anchors.baselineOffset: main.yStart - 13.2
        color: "white"
        font.pixelSize: 23
        font.family: "Roboto Mono"
        font.bold: true
        text: EngineMisc.spoilersValue
    }


}
