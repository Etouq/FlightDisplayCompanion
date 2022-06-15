import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {
    id: main

    property real elevTop: 0
    property bool isOnlyTrimGauge: false

    Text {
        id: elevText
        anchors.left: parent.left
        anchors.leftMargin: main.isOnlyTrimGauge ? 189 : 90
        anchors.baseline: parent.top
        anchors.baselineOffset: main.elevTop - 12
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        text: "ELEV"
    }

    Rectangle {
        id: verticalBar
        x: main.isOnlyTrimGauge ? 226.5 : 127.5
        y: main.elevTop - 3
        width: 3
        height: 126
        color: "white"
    }

    Rectangle {
        id: topBar
        x: main.isOnlyTrimGauge ? 211.5 : 112.5
        y: main.elevTop - 3
        width: 15
        height: 3
        color: "white"
    }

    Text {
        id: dnText
        anchors.left: parent.left
        anchors.leftMargin: main.isOnlyTrimGauge ? 189 : 90
        anchors.baseline: parent.top
        anchors.baselineOffset: main.elevTop + 6
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        text: "DN"
    }

    Rectangle {
        id: bottomBar
        x: main.isOnlyTrimGauge ? 211.5 : 112.5
        y: main.elevTop + 120
        width: 15
        height: 3
        color: "white"
    }

    Text {
        id: upText
        anchors.left: parent.left
        anchors.leftMargin: main.isOnlyTrimGauge ? 189 : 90
        anchors.baseline: parent.top
        anchors.baselineOffset: main.elevTop + 129
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        text: "UP"
    }

    Rectangle {
        id: centerGrad
        x: main.isOnlyTrimGauge ? 219 : 120
        y: main.elevTop + 58.5
        width: 7.5
        height: 3
        color: "white"
    }

    Shape {
        id: cursor
        transform: Translate { y: commonGaugeProperties.elevTrimTransformValue }
        ShapePath {
            fillColor: "aqua"
            strokeColor: "transparent"

            PathMove {
                x: main.isOnlyTrimGauge ? 211.5 : 112.5
                y: main.elevTop + 54
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

}
