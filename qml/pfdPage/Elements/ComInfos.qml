import QtQuick 2.15
import Pfd.RadioInfo 1.0

Rectangle {
    anchors.right: parent.right
    anchors.rightMargin: -18
    y: -18
    width: 248.4
    height: childrenRect.height + 18//114 // 18 + (RadioInfo.com1Avail + RadioInfo.com2Avail + RadioInfo.com3Avail) * 48
    radius: 18
    color: "#1A1D21"
    visible: RadioInfo.com1Avail || RadioInfo.com2Avail || RadioInfo.com3Avail

    Column {
        x: 11.52
        y: 18
        width: 207.36
        spacing: 0

        Item {
            id: com1Row
            height: 48
            width: 207.36
            visible: RadioInfo.com1Avail

            Text {
                anchors.verticalCenter: parent.verticalCenter
                color: "white"
                font.family: "Roboto Mono"
                font.pixelSize: 30
                font.bold: true
                text: "COM1"
            }

            Text {
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                color: "green"
                font.family: "Roboto Mono"
                font.pixelSize: 30
                font.bold: true
                text: RadioInfo.com1Freq.toFixed(3)
            }

        }

        Item {
            id: com2Row
            height: 48
            width: 207.36
            visible: RadioInfo.com2Avail

            Text {
                anchors.verticalCenter: parent.verticalCenter
                color: "white"
                font.family: "Roboto Mono"
                font.pixelSize: 30
                font.bold: true
                text: "COM2"
            }

            Text {
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                color: "green"
                font.family: "Roboto Mono"
                font.pixelSize: 30
                font.bold: true
                text: RadioInfo.com2Freq.toFixed(3)
            }

        }

        Item {
            id: com3Row
            height: 48
            width: 207.36
            visible: RadioInfo.com3Avail

            Text {
                anchors.verticalCenter: parent.verticalCenter
                color: "white"
                font.family: "Roboto Mono"
                font.pixelSize: 30
                font.bold: true
                text: "COM3"
            }

            Text {
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right
                color: "green"
                font.family: "Roboto Mono"
                font.pixelSize: 30
                font.bold: true
                text: RadioInfo.com3Freq.toFixed(3)
            }

        }
    }
}
