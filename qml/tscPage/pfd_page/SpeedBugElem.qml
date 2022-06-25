import QtQuick 2.15
import QtQuick.Layouts 1.12
import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"
import Tsc.SpeedBugs 1.0

TscPageBase {
    id: root

    showBackButton: true
    showHomeButton: true

    pageTitle: "Speed Bugs"


    signal valueClicked(int _bugIndex, int _startingValue);

    // function setVr(value) {
    //     tscBackend.vrSpeed = value;
    // }

    // function setVx(value) {
    //     tscBackend.vxSpeed = value;
    // }

    // function setVy(value) {
    //     tscBackend.vySpeed = value;
    // }

    // function setVapp(value) {
    //     tscBackend.vappSpeed = value;
    // }

    Rectangle {
        width: 951.36
        anchors.right: parent.right
        anchors.rightMargin: 337.92
        height: 1020
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 54
        border.width: 4.8
        border.color: "white"
        color: "transparent"

        Rectangle {
            height: parent.height
            width: 2.4
            color: "white"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Column {
            anchors.fill: parent
            anchors.margins: 10.8
            spacing: 2.4

            Repeater {
                model: SpeedBugs.numSpeedbugs()

                delegate: SpeedBugsRow {

                    required property int index

                    bugIndex: index

                }
            }

        }



    }

    GradientButton {
        x: 86.4
        anchors.bottom: resetButton.top
        anchors.bottomMargin: 10
        width: 437.76
        enabled: aircraftInterface.aircraftLoaded

        MainText {
            text: "Set As Defaults"
        }

        onReleased: {
            SpeedBugs.updateDefaultSpeedbugs(tscBackend.vrSpeed, tscBackend.vxSpeed, tscBackend.vySpeed, tscBackend.vappSpeed);
        }
    }

    GradientButton {
        id: resetButton
        x: 86.4
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 54
        width: 437.76

        MainText {
            text: "Restore All Defaults"
        }

        onReleased: {
            if (aircraftInterface.aircraftLoaded)
                tscBackend.resetSpeedBugs();
            else {
                tscBackend.vrSpeed = 85;
                tscBackend.vxSpeed = 100;
                tscBackend.vySpeed = 124;
                tscBackend.vappSpeed = 85;
            }
        }
    }




}
