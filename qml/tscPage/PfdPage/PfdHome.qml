import QtQuick 2.15

import Pfd.HSIndicator 1.0
import General.Settings 1.0
import TypeEnums 1.0

import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"

TscPageBase {
    id: pfdHome

    pageTitle: "PFD Home"

    showConnectionState: true

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
                id: navSourceText
                text: "GPS"
            }

            onReleased: GenSettings.nextCdiMode()
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

    states: [
        State {
            name: "noSource"
            when: HSIndicator.navSource === HsiNavSource.NONE

            PropertyChanges {
                target: cdiButton
                visible: false
            }
        },
        State {
            name: "gpsSource"
            when: HSIndicator.navSource === HsiNavSource.GPS

            PropertyChanges {
                target: navSourceText
                text: "GPS"
            }
        },
        State {
            name: "nav1Source"
            when: HSIndicator.navSource === HsiNavSource.VOR1 || HSIndicator.navSource === HsiNavSource.LOC1 || HSIndicator.navSource === HsiNavSource.TCN1

            PropertyChanges {
                target: navSourceText
                text: "NAV1"
            }
        },
        State {
            name: "nav2Source"
            when: HSIndicator.navSource === HsiNavSource.VOR2 || HSIndicator.navSource === HsiNavSource.LOC2 || HSIndicator.navSource === HsiNavSource.TCN2

            PropertyChanges {
                target: navSourceText
                text: "NAV2"
            }
        }
    ]

}
