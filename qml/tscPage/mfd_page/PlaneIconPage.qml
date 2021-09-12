import QtQuick 2.15
import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"

TscPageBase {
    id: root

    pageTitle: "Plane Icon"

    showBackButton: true
    showHomeButton: true


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
            mfdInterface.planeIconColor = _newColor;
        }
    }

    ColorPopup {
        id: borderColorPopup

        onColorPicked: {
            mfdInterface.planeIconBorderColor = _newColor;
        }
    }

    SizePopup {
        id: iconSizePopup
    }






}
