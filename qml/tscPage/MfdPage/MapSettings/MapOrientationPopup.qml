import QtQuick 2.15

import Mfd.GeoMapPage 1.0
import TypeEnums 1.0

import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"

Rectangle {
    id: popupRoot

    anchors.fill: parent

    visible: false

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
        y: 100
        width: 969.6
        height: 1074
        border.width: 4.8
        border.color: "white"
        color: "black"

        Column {
            anchors.centerIn: parent
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

                onReleased: { GeoMapPage.rotationMode = MapRotationMode.NORTH_UP; popupRoot.visible = false; }
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

                onReleased: { GeoMapPage.rotationMode = MapRotationMode.HDG_UP; popupRoot.visible = false; }
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

                onReleased: { GeoMapPage.rotationMode = MapRotationMode.TRACK_UP; popupRoot.visible = false; }
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
                    text: "Desired Track Up"
                }

                onReleased: { GeoMapPage.rotationMode = MapRotationMode.DTK_UP; popupRoot.visible = false; }
            }
        }

    }

}
