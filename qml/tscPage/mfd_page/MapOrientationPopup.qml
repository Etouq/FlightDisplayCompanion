import QtQuick 2.15
import "../styled_controls"
import "../styled_controls/gradientButtonElements"

Rectangle {
    id: popupRoot
    visible: false
    anchors.fill: parent
    color: Qt.rgba(0, 0, 0, 0.8)


    MouseArea {
        anchors.fill: parent
        onClicked: popupRoot.visible = false
    }

    Rectangle {
        width: 1728
        height: 120
        color: "black"

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 60
            color: "white"
            text: "Map Orientation"
        }
    }

    Rectangle {
        x: 379.2
        y: 180
        width: 969.6
        height: 819.6
        border.width: 4.8
        border.color: "white"
        color: "black"

        Column {
            x: 24
            y: 24
            width: 921.6
            height: 768
            spacing: 6

            GradientButton {
                width: 921.6

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: 50.4
                    font.pixelSize: 60
                    font.family: "Roboto Mono"
                    font.bold: true
                    color: "white"
                    text: "North Up"
                }

                onReleased: { mfdInterface.mapOrientationMode = 0; popupRoot.visible = false; }
            }

            GradientButton {
                width: 921.6

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: 50.4
                    font.pixelSize: 60
                    font.family: "Roboto Mono"
                    font.bold: true
                    color: "white"
                    text: "Heading Up"
                }

                onReleased: { mfdInterface.mapOrientationMode = 1; popupRoot.visible = false; }
            }

            GradientButton {
                width: 921.6

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    y: 50.4
                    font.pixelSize: 60
                    font.family: "Roboto Mono"
                    font.bold: true
                    color: "white"
                    text: "Track Up"
                }

                onReleased: { mfdInterface.mapOrientationMode = 2; popupRoot.visible = false; }
            }
        }
    }

}
