import QtQuick 2.15
import Mfd.Engine 1.0

Item {
    id: main
    anchors.fill: parent

    property real topBaseline: 0
    property bool hasApu: EngineMisc.hasApu()

    Text {
        id: fuelTimeTitle
        anchors.left: parent.left
        anchors.leftMargin: 7.5
        anchors.baseline: parent.top
        anchors.baselineOffset: main.hasApu ? main.topBaseline : main.topBaseline + 11.25
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        text: "FUEL TIME"
    }

    Text {
        id: fuelTimeText
        anchors.right: parent.left
        anchors.rightMargin: -202.5
        anchors.baseline: parent.top
        anchors.baselineOffset: main.hasApu ? main.topBaseline : main.topBaseline + 11.25
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        text: EngineMisc.fuelTimeText
    }

    Text {
        id: fuelRangeTitle
        anchors.left: parent.right
        anchors.leftMargin: -202.5
        anchors.baseline: parent.top
        anchors.baselineOffset: main.hasApu ? main.topBaseline : main.topBaseline + 11.25
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        text: "FUEL RANGE"
    }

    Text {
        id: fuelRangeText
        anchors.right: parent.right
        anchors.rightMargin: 7.5
        anchors.baseline: parent.top
        anchors.baselineOffset: main.hasApu ? main.topBaseline : main.topBaseline + 11.25
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        text: EngineMisc.fuelRangeText
    }

    Rectangle {
        id: separator
        x: 209
        width: 2
        anchors.top: fuelTimeTitle.top
        anchors.bottom: fuelTimeTitle.bottom
        color: "white"
    }

    Loader {
        active: main.hasApu
        sourceComponent: Item {
            Text {
                id: apuTitle
                anchors.right: parent.left
                anchors.rightMargin: -195
                anchors.top: fuelTimeTitle.bottom
                color: "white"
                font.pixelSize: 18
                font.family: "Roboto Mono"
                font.bold: true
                text: "APU N1"
            }

            Text {
                id: apuText
                anchors.left: parent.right
                anchors.leftMargin: -195
                anchors.top: fuelTimeTitle.bottom
                color: "white"
                font.pixelSize: 18
                font.family: "Roboto Mono"
                font.bold: true
                text: EngineMisc.apuRpmText
            }
        }
    }


}
