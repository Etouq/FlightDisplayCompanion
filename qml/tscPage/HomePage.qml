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
                property int idx: 0

                UpperTitle {
                    text: "Bearing 1"
                }

                CenterImg {
                    source: "qrc:/images/buttonImages/ICON_MAP_SMALL_BEARING_1.png"
                }

                LowerValue {
                    text: brg1Button.values[brg1Button.idx]
                }

                onReleased: idx = (idx + 1) % 5
            }

            GradientButton {
                id: brg2Button
                property var values: ["OFF", "NAV1", "NAV2", "GPS", "ADF"]
                property int idx: 0

                UpperTitle {
                    text: "Bearing 2"
                }

                CenterImg {
                    source: "qrc:/images/buttonImages/ICON_MAP_SMALL_BEARING_2_1.png"
                }

                LowerValue {
                    text: brg2Button.values[brg2Button.idx]
                }

                onReleased: idx = (idx + 1) % 5
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

        GradientButton {
            anchors.horizontalCenter: parent.horizontalCenter

            MainText {
                text: "Nav/Com\nRadios"
            }

            onReleased: root.radiosClicked()
        }

    }
}
