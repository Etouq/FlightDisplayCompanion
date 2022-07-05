import QtQuick 2.15

import Tsc.NavCom 1.0
import TypeEnums 1.0

import "../styled_controls"
import "../styled_controls/gradientButtonElements"

Row {
    id: xpdrRowRoot

    width: 663.6
    height: 192
    spacing: 4.8

    signal xpndrClicked()

    Rectangle {
        width: 224.4
        height: 192
        color: "black"

        GradientButton {
            x: 6
            y: 6
            width: 212.4
            height: 180

            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                y: 7.5
                font.family: "Roboto Mono"
                font.pixelSize: 66
                font.bold: true
                color: "white"
                text: "XPDR"
            }
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
                id: xpdrStateText
                x: 33.792
                font.pixelSize: 36
                color: "white"
                text: "OFF"

            }

            Text {
                id: xpdrValueText

                x: 33.792
                anchors.verticalCenter: parent.verticalCenter

                font.pixelSize: 84
                font.family: "Roboto Mono"
                font.bold: true

                color: "white"
                text: ("0000" + NavCom.xpdrCode).slice(-4)
            }

            onReleased: xpdrRowRoot.xpndrClicked()
        }
    }

    Rectangle {
        width: 192
        height: 192
        color: "black"
    }

    states: [
        State {
            name: "xpdrOff"
            when: NavCom.xpdrState === TransponderState.OFF

            PropertyChanges {
                target: xpdrStateText
                text: "OFF"
                color: "white"
            }

            PropertyChanges {
                target: xpdrValueText
                color: "white"
            }
        },
        State {
            name: "xpdrStby"
            when: NavCom.xpdrState === TransponderState.STANDBY

            PropertyChanges {
                target: xpdrStateText
                text: "STBY"
                color: "white"
            }

            PropertyChanges {
                target: xpdrValueText
                color: "white"
            }
        },
        State {
            name: "xpdrTest"
            when: NavCom.xpdrState === TransponderState.TEST

            PropertyChanges {
                target: xpdrStateText
                text: "TEST"
                color: "white"
            }

            PropertyChanges {
                target: xpdrValueText
                color: "white"
            }
        },
        State {
            name: "xpdrOn"
            when: NavCom.xpdrState === TransponderState.ON

            PropertyChanges {
                target: xpdrStateText
                text: "ON"
                color: "lawngreen"
            }

            PropertyChanges {
                target: xpdrValueText
                color: "lawngreen"
            }
        },
        State {
            name: "xpdrAlt"
            when: NavCom.xpdrState === TransponderState.ALT

            PropertyChanges {
                target: xpdrStateText
                text: "ALT"
                color: "lawngreen"
            }

            PropertyChanges {
                target: xpdrValueText
                color: "lawngreen"
            }
        }
    ]
}