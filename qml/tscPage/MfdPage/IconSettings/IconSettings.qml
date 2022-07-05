import QtQuick 2.15

import Mfd.GeoMapPage 1.0

import "../../"
import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"

TscPageBase {
    id: iconSettings

    pageTitle: "Aircraft Icon"

    showBackButton: true


    Column {
        y: 120
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864
        spacing: 10

        GradientButton {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 504

            MainText {
                y: 50
                text: "Icon"
            }

            onReleased: iconPopup.visible = true
        }

        GradientButton {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 504

            MainText {
                y: 50
                text: "Icon Size"
            }

            onReleased: iconSizePopup.visible = true
        }

        GradientButton {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 504

            MainText {
                y: 50
                text: "Fill Color"
            }

            onReleased: fillColorPopup.visible = true
        }

        GradientButton {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 504

            MainText {
                y: 50
                text: "Border Color"
            }

            onReleased: borderColorPopup.visible = true
        }


    }

    ColorPopup {
        id: fillColorPopup

        onColorPicked: {
            GeoMapPage.iconColor = _newColor;
        }
    }

    ColorPopup {
        id: borderColorPopup

        onColorPicked: {
            GeoMapPage.iconBorder = _newColor;
        }
    }

    SizePopup {
        id: iconSizePopup
    }

    IconPopup {
        id: iconPopup
    }






}
