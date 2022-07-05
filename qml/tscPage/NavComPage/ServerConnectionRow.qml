import QtQuick 2.15

import IO.Network 1.0
import TypeEnums 1.0

import "../styled_controls"
import "../styled_controls/gradientButtonElements"

Row {
    id: serverConnectionRowRoot

    width: 663.6
    height: 192
    spacing: 4.8

    signal portClicked()
    signal addressClicked()

    Rectangle {
        width: 224.4
        height: 192
        color: "black"

        GradientButton {
            x: 6
            y: 6
            width: 212.4
            height: 180

            TopText {
                x: 33.792
                font.pixelSize: 36
                color: "white"
                text: "Port"

            }

            Text {
                id: serverPortValueText

                x: 33.792
                anchors.verticalCenter: parent.verticalCenter

                font.pixelSize: 50
                font.family: "Roboto Mono"
                font.bold: true

                color: "white"
                text: "42069"
            }

            onReleased: serverConnectionRowRoot.portClicked()
        }
    }

    Rectangle {
        width: 434.4
        height: 192
        color: "black"

        GradientButton {
            x: 6
            y: 6
            width: 422.4
            height: 180

            TopText {
                x: 33.792
                font.pixelSize: 36
                color: "white"
                text: "Address"

            }

            Text {
                id: serverAddressValueText

                x: 33.792
                anchors.verticalCenter: parent.verticalCenter

                font.pixelSize: 50
                font.family: "Roboto Mono"
                font.bold: true

                color: "white"
                text: ("0000" + NavCom.xpdrCode).slice(-4)
            }

            onReleased: serverConnectionRowRoot.addressClicked()
        }
    }

    Rectangle {
        width: 192
        height: 192
        color: "black"
    }

}