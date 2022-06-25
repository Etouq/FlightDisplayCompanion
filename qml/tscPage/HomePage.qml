import QtQuick 2.15
import "styled_controls"
import "styled_controls/gradientButtonElements"
import General.Settings 1.0
import TypeEnums 1.0

TscPageBase {
    id: root

    pageTitle: "Home"

    signal speedbugsClicked()
    signal timersClicked()
    signal minimumsClicked()
    signal mapSettingsClicked()
    signal planeIconClicked()
    signal radiosClicked()

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
                    text: root.bearingModeToString(GenSettings.bearing1Mode)
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
                    text: root.bearingModeToString(GenSettings.bearing2Mode)
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

                onReleased: root.speedbugsClicked()
            }

            GradientButton {
                Img {
                    source: "qrc:/images/buttonImages/ICON_MAP_SMALL_TIMERS.png"
                }

                Title {
                    text: "Timers"
                }

                onReleased: root.timersClicked()
            }

            GradientButton {
                Img {
                    source: "qrc:/images/buttonImages/ICON_MAP_MINIMUMS.png"
                }

                Title {
                    text: "Minimums"
                }

                onReleased: root.minimumsClicked()
            }
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 6

            GradientButton {
                Img {
                    source: "qrc:/images/buttonImages/ICON_MAP_SETTINGS_1.png"
                }

                Title {
                    text: "Map"
                }

                onReleased: root.mapSettingsClicked()
            }

            GradientButton {

                Img {
                    source: "qrc:/images/mapImages/planeIconOutligned.svg"
                }

                Title {
                    text: "Plane\nIcon"
                }

                onReleased: root.planeIconClicked()
            }
        }

        GradientButton {
            anchors.horizontalCenter: parent.horizontalCenter

            MainText {
                text: "Nav/Com\nRadios"
            }

            onReleased: root.radiosClicked()
        }

    }



}
