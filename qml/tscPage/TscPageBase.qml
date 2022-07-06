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
        sourceComponent: NetworkClient.connectionState === ConnectionState.CONNECTED || NetworkClient.connectionState === ConnectionState.DISCONNECTED ? connectedIndicator: connectingIndicator
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
            }

            Loader {
                active: NetworkClient.connectionState === ConnectionState.CONNECTED
                sourceComponent: Grid {
                    x: 70
                    anchors.verticalCenter: parent.verticalCenter

                    columns: 2
                    columnSpacing: 5
                    rowSpacing: 0

                    Text {
                        font.family: "Roboto Mono"
                        font.bold: true
                        font.pixelSize: 30
                        color: "white"
                        text: "Address: "
                    }

                    Text {
                        font.family: "Roboto Mono"
                        font.bold: true
                        font.pixelSize: 30
                        color: "white"
                        text: NetworkClient.address
                    }

                    Text {
                        font.family: "Roboto Mono"
                        font.bold: true
                        font.pixelSize: 30
                        color: "white"
                        text: "Port: "
                    }

                    Text {
                        font.family: "Roboto Mono"
                        font.bold: true
                        font.pixelSize: 30
                        color: "white"
                        text: NetworkClient.port
                    }
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
            }

            Component.onCompleted: {
                if (NetworkClient.connectionState === ConnectionState.CONNECTING)
                {
                connectingText.actionText = "Connecting"
            }
            else {
                connectingText.actionText = "Disonnecting"
            }
        }

        Text {
            id: connectingText
            property int numDots: 0
            property string actionText: "Connecting"

            x: 70
            anchors.verticalCenter: parent.verticalCenter
            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 30
            color: "white"
            text: actionText + ".".repeat(numDots)
        }

        Timer {
            running: true
            interval: 400
            repeat: true
            onTriggered: {
                connectingText.numDots = (connectingText.numDots + 1) % 4
            }
        }

    }
}
}
