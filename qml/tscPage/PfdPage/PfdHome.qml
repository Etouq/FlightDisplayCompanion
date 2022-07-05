import QtQuick 2.15

import IO.Network 1.0
import General.Settings 1.0
import TypeEnums 1.0

import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"
import "../../settingsPage/flightplan"

TscPageBase {
    id: pfdHome

    pageTitle: "PFD Home"

    signal speedbugsClicked()
    signal timersClicked()
    signal minimumsClicked()
    signal pfdSettingsClicked()

    function bearingModeToString(mode) {
        switch(mode) {
            case BearingMode.OFF:
                return "OFF";
            case BearingMode.NAV1:
                return "NAV1";
            case BearingMode.NAV2:
                return "NAV2";
            case BearingMode.GPS:
                return "GPS";
            case BearingMode.ADF:
                return "ADF";
        }
    }


    Column {
        y: 120
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864
        spacing: 6

        GradientButton {
            id: cdiButton
            anchors.horizontalCenter: parent.horizontalCenter

            UpperTitle {
                text: "NAV SOURCE"
            }

            LowerValue {
                text: "GPS"
            }

            onReleased: function() {
                NetworkClient.connectToServer(addressField.text, parseInt(portField.text));
            }
        }

        StyledTextInput {
            id: addressField
            width: 250
            height: 45

            placeholderTxt: "Address"

            EnterKey.type: Qt.EnterKeyNext

            Component.onCompleted: {
                if (NetworkClient.address() !== "")
                    text = NetworkClient.address();
            }
        }

        StyledTextInput {
            id: portField
            width: 250
            height: 45

            placeholderTxt: "Port"

            EnterKey.type: Qt.EnterKeyDone

            inputMethodHints: Qt.ImhDigitsOnly

            Component.onCompleted: {
                if (NetworkClient.port() > -1)
                    text = NetworkClient.port();
            }
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 6

            GradientButton {
                id: brg1Button

                UpperTitle {
                    text: "Bearing 1"
                }

                CenterImg {
                    source: "qrc:/images/buttonImages/ICON_MAP_SMALL_BEARING_1.png"
                }

                LowerValue {
                    text: pfdHome.bearingModeToString(GenSettings.bearing1Mode)
                }

                onReleased: GenSettings.nextBearing1Mode()
            }

            GradientButton {
                id: brg2Button

                UpperTitle {
                    text: "Bearing 2"
                }

                CenterImg {
                    source: "qrc:/images/buttonImages/ICON_MAP_SMALL_BEARING_2_1.png"
                }

                LowerValue {
                    text: pfdHome.bearingModeToString(GenSettings.bearing2Mode)
                }

                onReleased: GenSettings.nextBearing2Mode()
            }
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 6

            GradientButton {
                Img {
                    source: "qrc:/images/buttonImages/ICON_MAP_SPEED_BUG.png"
                }

                Title {
                    text: "Speed Bugs"
                }

                onReleased: pfdHome.speedbugsClicked()
            }

            GradientButton {
                Img {
                    source: "qrc:/images/buttonImages/ICON_MAP_SMALL_TIMERS.png"
                }

                Title {
                    text: "Timers"
                }

                onReleased: pfdHome.timersClicked()
            }

            GradientButton {
                Img {
                    source: "qrc:/images/buttonImages/ICON_MAP_MINIMUMS.png"
                }

                Title {
                    text: "Minimums"
                }

                onReleased: pfdHome.minimumsClicked()
            }
        }

        GradientButton {
            id: pfdSettingsButton
            anchors.horizontalCenter: parent.horizontalCenter

            Img {
                source: "qrc:/images/buttonImages/ICON_MAP_SMALL_PFD_SETTINGS_1.png"
            }

            Title {
                text: "PFD Settings"
            }

            onReleased: pfdHome.pfdSettingsClicked()
        }

    }

}
