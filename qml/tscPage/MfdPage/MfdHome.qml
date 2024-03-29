import QtQuick 2.15

import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"

TscPageBase {
    id: mfdHome

    pageTitle: "MFD Home"

    showConnectionState: true

    signal mapSettingsClicked()
    signal planeIconClicked()
    signal flightplanClicked()
    signal edSettingsClicked()


    Column {
        y: 120
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864
        spacing: 6

        GradientButton {
            anchors.horizontalCenter: parent.horizontalCenter

            Img {
                source: "qrc:/images/buttonImages/ICON_MAP_SETTINGS_1.png"
            }

            Title {
                text: "Map"
            }

            onReleased: mfdHome.mapSettingsClicked()
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 6

            GradientButton {

                Img {
                    source: "qrc:/images/mapImages/planeIconOutligned.svg"
                }

                Title {
                    text: "Plane\nIcon"
                }

                onReleased: mfdHome.planeIconClicked()
            }

            GradientButton {

                Img {
                    source: "qrc:/images/buttonImages/ICON_MAP_FLIGHT_PLAN_MED_1.png"
                }

                Title {
                    text: "Flight\nPlan"
                }

                onReleased: mfdHome.flightplanClicked()
            }
        }

        GradientButton {
            anchors.horizontalCenter: parent.horizontalCenter

            Img {
                source: "qrc:/images/buttonImages/ICON_MAP_SETUP.png"
            }

            Title {
                text: "ED\nSettings"
            }

            onReleased: mfdHome.edSettingsClicked()
        }

    }



}
