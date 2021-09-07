import QtQuick 2.15
import QtQuick.Controls 2.15

import "styled_controls"
import "styled_controls/gradientButtonElements"

Item {
    id: root

    width: 1920
    height: 1200

    property bool showBackButton: false
    property bool showHomeButton: false
    property bool showEnterButton: false

    property string pageTitle: ""

    signal backClicked()
    signal homeClicked()
    signal enterClicked()

    Text {
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: 60
        color: "white"
        text: pageTitle
    }

    Rectangle { // navigation bar
        height: parent.height
        anchors.right: parent.right
        width: 192
        color: "#212121"

        GradientButton {
            y: 6
            width: 180
            height: 180
            x: 6

            Img {
                source: "qrc:/images/buttonImages/ICON_MAP_BUTTONBAR_BACK_1.png"
            }

            Title {
                text: "Back"
            }

            onReleased: root.backClicked()

            visible: root.showBackButton
        }

        GradientButton {
            y: 192
            width: 180
            height: 180
            x: 6

            Img {
                source: "qrc:/images/buttonImages/ICON_MAP_BUTTONBAR_HOME.png"
            }

            Title {
                text: "Home"
            }

            onReleased: root.homeClicked()

            visible: root.showHomeButton
        }

        GradientButton {
            y: 1014
            width: 180
            height: 180
            x: 6

            Img {
                source: "qrc:/images/buttonImages/ICON_MAP_ENTER.png"
            }

            Title {
                text: "Enter"
            }

            onReleased: root.enterClicked()

            visible: root.showEnterButton
        }
    }

}
