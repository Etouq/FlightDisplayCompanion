import QtQuick 2.15
import Pfd.RadioInfo 1.0

Rectangle {
    x: -18
    y: -18
    width: 248.4
    height: childrenRect.height + 18 // 114 // 18 + (RadioInfo.nav1Avail + RadioInfo.nav2Avail) * 48
    radius: 18
    color: "#1A1D21"
    visible: RadioInfo.nav1Avail || RadioInfo.nav2Avail

    Column {
        x: 29.52
        y: 18
        width: 207.36
        spacing: 0

        Item {
            id: nav1Row
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


}
