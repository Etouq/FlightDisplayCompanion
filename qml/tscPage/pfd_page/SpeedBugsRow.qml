import QtQuick 2.15
import "../styled_controls"
import "../styled_controls/gradientButtonElements"
import Tsc.SpeedBugs 1.0

Row {
    id: speedBugRow

    required property int bugIndex

    signal speedClicked()
    signal removeClicked()

    width: 920.16
    height: 197.76
    spacing: 4.8

    Rectangle {
        width: 356.4
        height: 197.76
        color: "black"
        border.color: "transparent"
        border.width: 0

        GradientButton {
            anchors.centerIn: parent
            width: 346.8
            height: 188.16

            MainText {
                text: "V" + SpeedBugs.designator(speedBugRow.bugIndex).toLowerCase()
            }

            GradientStatusBar {
                id: vrStatus
                active: SpeedBugs.active(speedBugRow.bugIndex)
            }

            onReleased: SpeedBugs.toggleActive(speedBugRow.bugIndex)
        }
    }

    Rectangle {
        width: 356.4
        height: 197.76
        color: "black"
        border.color: "transparent"
        border.width: 0

        GradientButton {
            anchors.centerIn: parent
            width: 346.8
            height: 188.16

            Text {
                width: parent.width
                anchors.top: parent.top
                anchors.topMargin: 42
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 60
                font.family: "Roboto Mono"
                font.bold: true
                color: "aqua"
                text: SpeedBugs.speed(speedBugRow.bugIndex) + "KT"
            }

            onReleased: speedBugRow.speedClicked()
        }
    }

    Rectangle {
        width: 197.76
        height: 197.76
        color: "black"
        border.color: "transparent"
        border.width: 0

        GradientButton {
            anchors.centerIn: parent
            width: 188.16
            height: 188.16

            Rectangle {
                height: parent.height * 0.2
                width: parent.width * 0.6
                y: parent.height * 0.4
                anchors.horizontalCenter: parent.horizontalCenter
                color: "red"
                border {
                    color: "white"
                    width: 2
                }
                radius: 2

            }

            onReleased: speedBugRow.removeClicked()
        }
    }
}

