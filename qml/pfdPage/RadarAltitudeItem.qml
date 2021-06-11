import QtQuick 2.15

Rectangle {
    visible: altInterface.radarAltitude < 2500
    enabled: altInterface.radarAltitude < 2500
    anchors.left: parent.left
    anchors.leftMargin: 1152
    anchors.verticalCenter: parent.bottom
    anchors.verticalCenterOffset: -600
    width: 153.6
    height: 60
    color: "#1A1D21"

    Text {
        id: ra_title
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 26.88
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: "RA"
    }

    Text {
        id: ra_value
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 103.68
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 40
        font.bold: true
        text: altInterface.radarAltitude
    }
}
