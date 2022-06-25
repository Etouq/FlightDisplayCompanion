import QtQuick 2.15
import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"
import Tsc.FlightTmr 1.0

TscPageBase {
    id: root

    showBackButton: true
    showHomeButton: true

    pageTitle: "Timers"

    signal timeValueClicked()

    Component.onCompleted: FlightTmr.movedOnscreen();

    Component.onDestruction: FlightTmr.movedOffscreen();

    GradientButton {
        width: 510.72
        height: 216
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864
        y: 228

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 6
            font.family: "Roboto Mono"
            font.bold: true
            color: "white"
            font.pixelSize: 48
            text: "Time"
        }

        Text {
            id: timerValue
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 60
            font.family: "Roboto Mono"
            font.bold: true
            color: "aqua"
            font.pixelSize: 84
            text: FlightTmr.timeString
        }

        onReleased: root.timeValueClicked()
    }

    Rectangle {
        id: centerGroup
        y: 552
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864
        height: 540
        width: 510.72
        border.width: 2.4
        border.color: "white"
        color: "transparent"

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 6
            font.family: "Roboto Mono"
            font.bold: true
            color: "white"
            font.pixelSize: 48
            text: "Count"
        }

        GradientButton {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 485.6832
            height: 216
            y: 70.2

            UpperTitle {
                text: "Up"
            }

            GradientStatusBar {
                id: upTimerStatus
                active: !FlightTmr.countingDown
            }

            onReleased: FlightTmr.countingDown = false;
        }

        GradientButton {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 485.6832
            height: 216
            y: 302.4

            UpperTitle {
                text: "Down"
            }

            GradientStatusBar {
                id: downTimerStatus
                active: FlightTmr.countingDown
            }

            onReleased: FlightTmr.countingDown = true;
        }
    }

    GradientButton {
        anchors.right: centerGroup.left
        anchors.rightMargin: 47.136
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 162

        UpperTitle {
            text: "Reset"
        }

        onReleased: FlightTmr.reset();
    }

    GradientButton {
        anchors.left: centerGroup.right
        anchors.leftMargin: 47.136
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 162

        UpperTitle {
            text: FlightTmr.running ? "Stop" : "Start"
        }

        onReleased: FlightTmr.running ? FlightTmr.stop() : FlightTmr.start();
    }


}
