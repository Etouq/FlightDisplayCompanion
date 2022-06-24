import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.Airspeed 1.0

Item {

    Rectangle {
        width: 192
        height: 48
        color: "#1a1d21"
    }

    Shape {
        ShapePath {
            fillColor: "#36c8d2"
            strokeColor: "transparent"

            PathMove { x: 182.4; y: 9.6 }
            PathLine { x: 172.8; y: 9.6 }
            PathLine { x: 172.8; y: 19.2 }
            PathLine { x: 177.6; y: 24 }
            PathLine { x: 172.8; y: 28.8 }
            PathLine { x: 172.8; y: 38.4 }
            PathLine { x: 182.4; y: 38.4 }
        }
    }

    Text {
        x: 19.2
        anchors.baseline: parent.top
        anchors.baselineOffset: 38.4
        color: "#36c8d2"
        font.bold: true
        font.family: "Roboto Mono"
        font.pixelSize: 43
        text: Airspeed.refSpeed
    }
}
