import QtQuick 2.15
import Pfd.RadioInfo 1.0

Rectangle {
    x: -18
    y: -18
    width: 248.4
    height: 114
    radius: 18
    color: "#1A1D21"
    visible: RadioInfo.nav1Avail || RadioInfo.nav2Avail

    Item {
        id: nav1Row
        x: 29.52
        y: 18
        height: 48
        width: 207.36
        visible: RadioInfo.nav1Avail

        Text {
            anchors.verticalCenter: parent.verticalCenter
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 30
            font.bold: true
            text: "NAV1"
        }

        Text {
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            color: "green"
            font.family: "Roboto Mono"
            font.pixelSize: 30
            font.bold: true
            text: RadioInfo.nav1Freq.toFixed(2)
        }

    }

    Item {
        id: nav2Row
        x: 29.52
        y: 66
        height: 48
        width: 207.36
        visible: RadioInfo.nav2Avail

        Text {
            anchors.verticalCenter: parent.verticalCenter
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 30
            font.bold: true
            text: "NAV2"
        }

        Text {
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            color: "green"
            font.family: "Roboto Mono"
            font.pixelSize: 30
            font.bold: true
            text: RadioInfo.nav2Freq.toFixed(2)
        }

    }
}
