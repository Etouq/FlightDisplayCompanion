import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.Altimeter 1.0

Shape {
    Rectangle {
        x: 48
        width: 192
        height: 48
        color: "#1a1d21"
        z: -1
    }

    ShapePath {
        fillColor: "#36c8d2"
        strokeColor: "transparent"

        PathMove { x: 57.6; y: 9.6 }
        PathLine { x: 67.2; y: 9.6 }
        PathLine { x: 67.2; y: 19.2 }
        PathLine { x: 62.4; y: 24 }
        PathLine { x: 67.2; y: 28.8 }
        PathLine { x: 67.2; y: 38.4 }
        PathLine { x: 57.6; y: 38.4 }
    }

    Text {
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 168
        anchors.baseline: parent.top
        anchors.baselineOffset: 38.4
        color: "#36c8d2"
        font.bold: true
        font.family: "Roboto Mono"
        font.pixelSize: 43
        text: Altimeter.referenceAltitude
    }
}
