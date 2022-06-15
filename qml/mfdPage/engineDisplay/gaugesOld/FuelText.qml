import QtQuick 2.15

Item {
    id: main
    anchors.fill: parent

    property real topBaseline: 0
    property bool hasApu: commonGaugeProperties.getHasApu()

    Text {
        id: fuelTimeTitle
        anchors.left: parent.left
        anchors.leftMargin: 7.5
        anchors.baseline: parent.top
        anchors.baselineOffset: main.hasApu ? topBaseline : topBaseline + 11.25
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
        anchors.baselineOffset: main.hasApu ? topBaseline : topBaseline + 11.25
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        text: commonGaugeProperties.fuelTimeText
    }

    Text {
        id: fuelRangeTitle
        anchors.left: parent.right
        anchors.leftMargin: -202.5
        anchors.baseline: parent.top
        anchors.baselineOffset: main.hasApu ? topBaseline : topBaseline + 11.25
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
        anchors.baselineOffset: main.hasApu ? topBaseline : topBaseline + 11.25
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        text: commonGaugeProperties.fuelRangeText
    }

    Rectangle {
        id: separator
        x: 209
        width: 2
        anchors.top: fuelTimeTitle.top
        anchors.bottom: fuelTimeTitle.bottom
        color: "white"
    }

    Text {
        id: apuTitle
        visible: main.hasApu
        enabled: main.hasApu
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
        visible: main.hasApu
        enabled: main.hasApu
        anchors.left: parent.right
        anchors.leftMargin: -195
        anchors.top: fuelTimeTitle.bottom
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        text: commonGaugeProperties.apuRpmText
    }

}
