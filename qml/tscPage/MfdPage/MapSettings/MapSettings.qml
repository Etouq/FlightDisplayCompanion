import QtQuick 2.15
import QtQml 2.15

import Mfd.GeoMapPage 1.0
import General.Settings 1.0
import TypeEnums 1.0

import "../../"
import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"

TscPageBase {

    showBackButton: true

    pageTitle: "Map Settings"

    Column {
        y: 180
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864
        spacing: 6

        GradientButton {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 360
            height: 252

            UpperTitle {
                text: "Orientation"
            }

            LowerValue {
                id: orientationButton

                text: "North Up"
            }

            onReleased: orientationPopup.visible = true
        }


        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 6

            GradientButton {

                MainText {
                    text: "Range Rings"
                }

                GradientStatusBar {
                    active: GenSettings.showRangeRings
                }

                onReleased: GenSettings.showRangeRings = !GenSettings.showRangeRings
            }

            GradientButton {

                enabled: GenSettings.showRangeRings

                UpperTitle {
                    text: "Range Rings Text"
                }

                GradientStatusBar {
                    active: GenSettings.showRangeText
                }

                onReleased: GenSettings.showRangeText = !GenSettings.showRangeText
            }
        }

        GradientButton {
            anchors.horizontalCenter: parent.horizontalCenter

            MainText {
                text: "Fuel Range Ring"
            }

            GradientStatusBar {
                active: GenSettings.showFuelRangeRing
            }

            onReleased: GenSettings.showFuelRangeRing = !GenSettings.showFuelRangeRing
        }

    }

    MapOrientationPopup {
        id: orientationPopup
    }

    states: [
        State {
            name: "northUpOrientation"
            when: GeoMapPage.rotationMode === MapRotationMode.NORTH_UP

            PropertyChanges {
                target: orientationButton
                text: "North Up"
            }
        },
        State {
            name: "dtkUpOrientation"
            when: GeoMapPage.rotationMode === MapRotationMode.DTK_UP

            PropertyChanges {
                target: orientationButton
                text: "Desired Track Up"
            }
        },
        State {
            name: "hdgUpOrientation"
            when: GeoMapPage.rotationMode === MapRotationMode.HDG_UP

            PropertyChanges {
                target: orientationButton
                text: "Heading Up"
            }
        },
        State {
            name: "trackUpOrientation"
            when: GeoMapPage.rotationMode === MapRotationMode.TRACK_UP

            PropertyChanges {
                target: orientationButton
                text: "Track Up"
            }
        }
    ]

}
