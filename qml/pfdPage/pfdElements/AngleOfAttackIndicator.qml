import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {
    width: 192
    height: 192

    Rectangle {
        anchors.fill: parent
        color: "#1A1D21"
        opacity: 0.25
    }

    Shape {
        ShapePath {
            fillColor: "transparent"
            strokeColor: "white"
            strokeWidth: 7.68
            PathAngleArc {
                radiusX: 153.6
                radiusY: 153.6
                startAngle: 180
                sweepAngle: 90
                centerX: 172.8
                centerY: 172.8
            }
        }

        ShapePath {
            fillColor: "transparent"
            strokeColor: "red"
            strokeWidth: 7.68
            PathAngleArc {
                radiusX: 153.6
                radiusY: 153.6
                startAngle: 270
                sweepAngle: -15.3
                centerX: 172.8
                centerY: 172.8
            }
        }
    }

    Rectangle {
        x: -19.2
        y: 172.8
        width: 28.8
        height: 3.84
        color: "white"
        transform: Rotation {
            angle: 50
            origin.x: 192
            origin.y: 0
        }
    }

    Shape {
        ShapePath {
            fillColor: aoaInterface.cursorColor
            strokeColor: "black"
            strokeWidth: 1.92

            PathMove { x: 19.2; y: 172.8 }
            PathLine { relativeX: 38.4; relativeY: -14.4 }
            PathLine { relativeX: 0; relativeY: 28.8 }
            PathLine { x: 19.2; y: 172.8 }
        }

        transform: Rotation {
            angle: aoaInterface.aoaAngle
            origin.x: 172.8
            origin.y: 172.8
        }
    }

    Text {
        x: 115.2
        anchors.baseline: parent.top
        anchors.baselineOffset: 134.4
        color: "white"
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: 33
        text: "AOA"
    }

}
