import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.Bottombar 1.0

Item {
    width: 1920
    y: 1177.8 + (65 - 57 * Math.sin(-0.6) - 116) * 691.2 / 156
    height: 1200 - y

    Shape {
        ShapePath
        {
            fillColor: "#1A1D21"
            strokeColor: "transparent"

            PathMove { x: 0; y: 0 }
            PathLine { x: 0; y: 1200 }
            PathLine { x: 1920; y: 1200 }
            PathLine { x: 1920; y: 0 }
            PathLine { x: 614.4 + (78 - 57 * Math.cos(Math.PI + 0.6)) * 691.2 / 156; relativeY: 0 }
            PathArc { radiusX: 57 * 691.2 / 156; radiusY: 57 * 691.2 / 156; x: 614.4 + (78 - 57 * Math.cos(-0.6)) * 691.2 / 156; relativeY: 0}
        }
    }

    Text {
        x: 12
        width: 50
        height: parent.height / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: "GS"
    }

    Text {
        x: 62
        width: 130
        height: parent.height / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: Bottombar.groundSpeed + "KT"
    }

    Text {
        x: 12
        width: 50
        height: parent.height / 2
        anchors.bottom: parent.bottom
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: "TAT"
    }

    Text {
        x: 62
        width: 130
        height: parent.height / 2
        anchors.bottom: parent.bottom
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: Bottombar.totalAirTemp
    }

    Rectangle {
        x: 201.6
        width: 4.8
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        color: "white"
    }

    Text {
        x: 1425
        width: 65
        height: parent.height / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: "UTC"
    }

    Text {
        id: timeText
        x: 1500
        width: 180
        height: parent.height / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: Bottombar.zuluTime
    }

    Text {
        x: 1425
        width: 65
        height: parent.height / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        anchors.bottom: parent.bottom
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: "LCL"
    }

    Text {
        x: 1500
        width: 180
        height: parent.height / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
        anchors.bottom: parent.bottom
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: Bottombar.localTime
    }


}
