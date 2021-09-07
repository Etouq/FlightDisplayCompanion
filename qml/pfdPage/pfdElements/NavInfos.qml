import QtQuick 2.15
import QtQuick.Layouts 1.15

Rectangle {
    x: 1267.2
    y: 780
    width: 480
    height: 96
    color: "#1a1d21"
    visible: navInterface.gpsIsActiveFlightPlan

    Text {
        x: 24
        width: 171
        height: 57.6
        verticalAlignment: Text.AlignVCenter
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: navInterface.currentLegFrom
    }

    Image {
        width: 65
        height: 40
        y: 8.8
        anchors.horizontalCenter: parent.horizontalCenter
        source: navInterface.legIsDirectTo ? "qrc:/images/micsImages/directToIcon.png" : "qrc:/images/miscImages/courseToIcon.png"
    }

    Text {
        x: 285
        width: 171
        height: 57.6
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: navInterface.currentLegTo
    }

    RowLayout {
        id: bottomInfos
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4.8
        spacing: 0


        Text {
            Layout.leftMargin: 9.6
            Layout.rightMargin: 9.6
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 28
            font.bold: true
            text: "DIS"
        }

        Text {
            Layout.leftMargin: 9.6
            Layout.rightMargin: 9.6
            color: "#D12BC7"
            font.family: "Roboto Mono"
            font.pixelSize: 28
            font.bold: true
            text: navInterface.currentLegDistance
        }

        Text {
            Layout.leftMargin: 9.6
            Layout.rightMargin: 9.6
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 28
            font.bold: true
            text: "BRG"
        }

        Text {
            Layout.leftMargin: 9.6
            Layout.rightMargin: 9.6
            color: "#D12BC7"
            font.family: "Roboto Mono"
            font.pixelSize: 28
            font.bold: true
            text: navInterface.currentLegBearing
        }
    }
}
