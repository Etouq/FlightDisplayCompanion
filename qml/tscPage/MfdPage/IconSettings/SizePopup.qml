import QtQuick 2.15

import Mfd.GeoMapPage 1.0

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
            text: "Pick Icon Size"
        }
    }

    Rectangle {
        x: 649.2
        y: 130.2
        width: 429.6
        height: 819.6
        border.width: 4.8
        border.color: "white"
        color: "black"

        Column {
            anchors.centerIn: parent
            width: 400
            height: 790
            spacing: 10

            GradientButton {
                width: 400
                height: 150

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 45
                    font.family: "Roboto Mono"
                    font.bold: true
                    color: "white"
                    text: "Extra Small"
                }

                onReleased: { GeoMapPage.iconScale = 0.5; popupRoot.visible = false; }
            }

            GradientButton {
                width: 400
                height: 150

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 45
                    font.family: "Roboto Mono"
                    font.bold: true
                    color: "white"
                    text: "Small"
                }

                onReleased: { GeoMapPage.iconScale = 0.75; popupRoot.visible = false; }
            }

            GradientButton {
                width: 400
                height: 150

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 45
                    font.family: "Roboto Mono"
                    font.bold: true
                    color: "white"
                    text: "Medium"
                }

                onReleased: { GeoMapPage.iconScale = 1; popupRoot.visible = false; }
            }

            GradientButton {
                width: 400
                height: 150

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 45
                    font.family: "Roboto Mono"
                    font.bold: true
                    color: "white"
                    text: "Large"
                }

                onReleased: { GeoMapPage.iconScale = 1.5; popupRoot.visible = false; }
            }

            GradientButton {
                width: 400
                height: 150

                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 45
                    font.family: "Roboto Mono"
                    font.bold: true
                    color: "white"
                    text: "Extra Large"
                }

                onReleased: { GeoMapPage.iconScale = 2; popupRoot.visible = false; }
            }
        }
    }

}
