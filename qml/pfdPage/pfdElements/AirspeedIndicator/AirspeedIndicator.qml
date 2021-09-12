import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {

    AirspeedReferenceGroup {
    }

    Rectangle {
        y: 48
        width: 192
        height: 576
        color: "#1a1d21"
        opacity: 0.25
    }

    CenterItem {
        y: 48
        width: 240
        height: 576
        clip: true
    }

    Cursor {
    }

    Rectangle {
        y: 624
        width: 192
        height: 48
        color: "#1a1d21"
    }

    Text {
        x: 4.8
        anchors.baseline: parent.top
        anchors.baselineOffset: 660.48
        color: "white"
        font.bold: true
        font.family: "Roboto Mono"
        font.pixelSize: 34
        text: "TAS"
    }

    Text {
        anchors.right: parent.right
        anchors.rightMargin: 52.8
        anchors.baseline: parent.top
        anchors.baselineOffset: 660.48
        color: "white"
        font.bold: true
        font.family: "Roboto Mono"
        font.pixelSize: 34
        text: iasInterface.trueAirspeed + "KT"
    }

}
