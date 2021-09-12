import QtQuick 2.15
import "styled_controls"
import "styled_controls/gradientButtonElements"

TscPageBase {
    id: root

    pageTitle: "Home"

    signal speedbugsClicked()
    signal timersClicked()
    signal minimumsClicked()
    signal mapSettingsClicked()
    signal planeIconClicked()
    signal radiosClicked()




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
                property var values: ["OFF", "NAV1", "NAV2", "GPS", "ADF"]

                UpperTitle {
                    text: "Bearing 1"
                }

                CenterImg {
                    source: "qrc:/images/buttonImages/ICON_MAP_SMALL_BEARING_1.png"
                }

                LowerValue {
                    text: brg1Button.values[hsiBrgInterface.brg1Mode]
                }

                onReleased: hsiBrgInterface.brg1Mode = (hsiBrgInterface.brg1Mode + 1) % 5
            }

            GradientButton {
                id: brg2Button
                property var values: ["OFF", "NAV1", "NAV2", "GPS", "ADF"]

                UpperTitle {
                    text: "Bearing 2"
                }

                CenterImg {
                    source: "qrc:/images/buttonImages/ICON_MAP_SMALL_BEARING_2_1.png"
                }

                LowerValue {
                    text: brg2Button.values[hsiBrgInterface.brg2Mode]
                }

                onReleased: hsiBrgInterface.brg2Mode = (hsiBrgInterface.brg2Mode + 1) % 5
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
