import QtQuick 2.15
import QtQml 2.15

import "../../"
import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"

TscPageBase {

    showBackButton: true

    pageTitle: "Engine Display Settings"

    Column {
        y: 180
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864
        spacing: 6

        GradientButton {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 360
            height: 252

            MainText {
                y: 50
                text: "Trim Unit"
            }

            onReleased: unitPopup.visible = true
        }

    }

    TrimUnitPopup {
        id: unitPopup
    }

}
