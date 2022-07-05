import QtQuick 2.15

import Pfd.Altimeter 1.0

import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"

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
            text: "Minimum Source"
        }
    }

    Rectangle {
        x: 604.8
        y: 180
        width: 518.4
        height: 724.992
        border.width: 4.8
        border.color: "white"
        color: "black"

        Column {
            x: 15.168
            y: 15.168
            spacing: 10.368

            GradientButton {
                width: 488.064
                height: 224.64

                Text {
                    y: 44.928
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 60
                    font.family: "Roboto Mono"
                    font.bold: true
                    color: "white"
                    text: "Off"
                }

                onReleased: {
                    Altimeter.minimumsState = 0;
                    popupRoot.visible = false;
                }
            }

            GradientButton {
                width: 488.064
                height: 224.64

                Text {
                    y: 44.928
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 60
                    font.family: "Roboto Mono"
                    font.bold: true
                    color: "white"
                    text: "Baro"
                }

                onReleased: {
                    Altimeter.minimumsState = 1;
                    Altimeter.updateMinimumAlt();
                    popupRoot.visible = false;
                }
            }

            GradientButton {
                width: 488.064
                height: 224.64

                Text {
                    y: 44.928
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 60
                    font.family: "Roboto Mono"
                    font.bold: true
                    color: "white"
                    text: "Radio Alt"
                }

                onReleased: {
                    Altimeter.minimumsState = 2;
                    Altimeter.updateMinimumAlt();
                    popupRoot.visible = false;
                }
            }
        }
    }


}
