import QtQuick 2.15

Rectangle {
    anchors.right: parent.right
    anchors.rightMargin: -18
    y: -18
    width: 248.4
    height: 114
    radius: 18
    color: "#1A1D21"
    visible: radioInterface.hasComm1 || radioInterface.hasComm2

    Item {
        id: com1Row
        x: 11.52
        y: 18
        height: 48
        width: 207.36
        visible: radioInterface.hasComm1

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
            text: radioInterface.comm1Freq.toFixed(3)
        }

    }

    Item {
        id: com2Row
        x: 11.52
        y: 66
        height: 48
        width: 207.36
        visible: radioInterface.hasComm2

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
            text: radioInterface.comm2Freq.toFixed(3)
        }

    }
}
