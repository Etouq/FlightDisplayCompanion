import QtQuick 2.15
import QtQuick.Controls 2.15

import IO.Network 1.0
import TypeEnums 1.0

import "styled_controls"
import "styled_controls/gradientButtonElements"

Item {
    id: root

    width: 1920
    height: 1200

    property bool showBackButton: false
    property bool showEnterButton: false

    property bool showConnectionState: false

    property string pageTitle: ""

    signal backClicked()
    signal enterClicked()
    signal pfdClicked()
    signal mfdClicked()
    signal navcomClicked()

    Loader {
        active: root.showConnectionState
        sourceComponent: NetworkClient.connectionState === ConnectionState.CONNECTED || NetworkClient.connectionState === ConnectionState.DISCONNECTED ? connectedIndicator : connectingIndicator
    }

    Text {
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: 60
        color: "white"
        text: pageTitle
    }

    ManualConnectPopup {
        id: manualConnectPopup
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
            y: 318
            width: 180
            height: 180
            x: 6

            Text {
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 60
                font.family: "Roboto Mono"
                font.bold: true
                color: "white"
                text: "PFD"
                lineHeight: 0.8
            }

            onReleased: root.pfdClicked()
        }
        GradientButton {
            y: 504
            width: 180
            height: 180
            x: 6

            Text {
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 60
                font.family: "Roboto Mono"
                font.bold: true
                color: "white"
                text: "MFD"
                lineHeight: 0.8
            }

            onReleased: root.mfdClicked()
        }
        GradientButton {
            y: 690
            width: 180
            height: 180
            x: 6

            Text {
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 60
                font.family: "Roboto Mono"
                font.bold: true
                color: "white"
                text: "NAV COM"
                wrapMode: Text.WordWrap
                lineHeight: 0.8
            }

            onReleased: root.navcomClicked()
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

    Component {
        id: connectedIndicator

        Item {
            x: 20
            y: 30
            height: 60

            Rectangle {
                width: 60
                height: 60
                radius: 30
                color: NetworkClient.connectionState === ConnectionState.CONNECTED ? "green": "red"

                MouseArea {
                    anchors.fill: parent
                    onClicked: manualConnectPopup.open()
                }
            }


        }
    }

    Component {
        id: connectingIndicator

        Item {
            x: 20
            y: 30
            height: 60

            LoadSpinner {
                radius: 30

                MouseArea {
                    anchors.fill: parent
                    onClicked: manualConnectPopup.open()
                }
            }
        }

    }
}

