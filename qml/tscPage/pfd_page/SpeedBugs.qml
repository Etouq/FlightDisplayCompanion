import QtQuick 2.15
import QtQuick.Layouts 1.12
import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"

TscPageBase {
    id: root

    showBackButton: true
    showHomeButton: true

    pageTitle: "Speed Bugs"


    signal valueClicked(var _callback, int _startingValue);

    function setVr(value) {
        tscBackend.vrSpeed = value;
    }

    function setVx(value) {
        tscBackend.vxSpeed = value;
    }

    function setVy(value) {
        tscBackend.vySpeed = value;
    }

    function setVapp(value) {
        tscBackend.vappSpeed = value;
    }

    Rectangle {
        width: 729.6
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
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.leftMargin: 10.8
            anchors.rightMargin: 10.8
            anchors.topMargin: 10.8
            anchors.bottomMargin: 10.8
            spacing: 4.8

            Item {
                width: parent.width
                height: 188.16
                GradientButton {
                    anchors.left: parent.left
                    width: 346.8
                    height: 188.16

                    enabled: !tscBackend.vrActive || !tscBackend.vxActive || !tscBackend.vyActive || !tscBackend.vappActive

                    MainText {
                        text: "All On"
                    }

                    onReleased: {
                        tscBackend.vrActive = true;
                        tscBackend.vxActive = true;
                        tscBackend.vyActive = true;
                        tscBackend.vappActive = true;
                    }
                }

                GradientButton {
                    anchors.right: parent.right
                    width: 346.8
                    height: 188.16

                    enabled: tscBackend.vrActive || tscBackend.vxActive || tscBackend.vyActive || tscBackend.vappActive

                    MainText {
                        text: "All Off"
                    }

                    onReleased: {
                        tscBackend.vrActive = false;
                        tscBackend.vxActive = false;
                        tscBackend.vyActive = false;
                        tscBackend.vappActive = false;
                    }
                }
            }

            Rectangle {
                x: -10.5
                width: parent.width + 21
                height: 2.4
                color: "white"
            }

            Item {
                width: parent.width
                height: 188.16
                GradientButton {
                    anchors.left: parent.left
                    width: 346.8
                    height: 188.16

                    MainText {
                        text: "Vr"
                    }

                    GradientStatusBar {
                        id: vrStatus
                        active: tscBackend.vrActive
                    }

                    onReleased: tscBackend.vrActive = !tscBackend.vrActive
                }

                GradientButton {
                    anchors.right: parent.right
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
                        text: tscBackend.vrSpeed + "KT"
                    }

                    onReleased: root.valueClicked(root.setVr, tscBackend.vrSpeed)
                }
            }

            Rectangle {
                x: -10.5
                width: parent.width + 21
                height: 2.4
                color: "white"
            }

            Item {
                width: parent.width
                height: 188.16
                GradientButton {
                    anchors.left: parent.left
                    width: 346.8
                    height: 188.16

                    MainText {
                        text: "Vx"
                    }

                    GradientStatusBar {
                        id: vxStatus
                        active: tscBackend.vxActive
                    }

                    onReleased: tscBackend.vxActive = !tscBackend.vxActive
                }

                GradientButton {
                    anchors.right: parent.right
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
                        text: tscBackend.vxSpeed + "KT"
                    }

                    onReleased: root.valueClicked(root.setVx, tscBackend.vxSpeed)
                }
            }

            Rectangle {
                x: -10.5
                width: parent.width + 21
                height: 2.4
                color: "white"
            }

            Item {
                width: parent.width
                height: 188.16
                GradientButton {
                    anchors.left: parent.left
                    width: 346.8
                    height: 188.16

                    MainText {
                        text: "Vy"
                    }

                    GradientStatusBar {
                        id: vyStatus
                        active: tscBackend.vyActive
                    }

                    onReleased: tscBackend.vyActive = !tscBackend.vyActive
                }

                GradientButton {
                    anchors.right: parent.right
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
                        text: tscBackend.vySpeed + "KT"
                    }

                    onReleased: root.valueClicked(root.setVy, tscBackend.vySpeed)
                }
            }

            Rectangle {
                x: -10.5
                width: parent.width + 21
                height: 2.4
                color: "white"
            }

            Item {
                width: parent.width
                height: 188.16
                GradientButton {
                    anchors.left: parent.left
                    width: 346.8
                    height: 188.16

                    MainText {
                        text: "Vapp"
                    }

                    GradientStatusBar {
                        id: vappStatus
                        active: tscBackend.vappActive
                    }

                    onReleased: tscBackend.vappActive = !tscBackend.vappActive
                }

                GradientButton {
                    anchors.right: parent.right
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
                        text: tscBackend.vappSpeed + "KT"
                    }

                    onReleased: root.valueClicked(root.setVapp, tscBackend.vappSpeed)
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
            aircraftInterface.updateDefaultSpeedbugs(tscBackend.vrSpeed, tscBackend.vxSpeed, tscBackend.vySpeed, tscBackend.vappSpeed);
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
