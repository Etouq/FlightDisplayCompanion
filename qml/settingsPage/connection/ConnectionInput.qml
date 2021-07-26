import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQml 2.15
import QtQuick.Layouts 1.15
import "../flightplan"

GridLayout {
    id: root
    x: 50
    y: 80
    columns: 2
    rowSpacing: 10

    Connections {
        target: netInterface
        function onStateChanged(stateId) {
            switch (stateId) {
                case 1:
                    connectionText.text = "Looking up Host";
                    break;
                case 2:
                    connectionText.text = "Connecting";
                    break;
                case 4:
                    connectionText.text = "Socket Bound";
                    break;
                case 6:
                    connectionText.text = "Closing";
                    break;
                default:
                    connectionText.text = "";
                    break;
            }
        }
    }

    Button {
        id: connectButton
        Layout.preferredWidth: 250
        Layout.preferredHeight: 100
        Layout.rowSpan: 2
        Layout.rightMargin: 20

        background: Rectangle {
            color: connectButton.enabled ? (connectButton.pressed ? "white" : "#00b4ff") : "#949595"
            radius: 6

            Rectangle {
                anchors.fill: parent
                color: "white"
                opacity: 0.24
                visible: connectButton.visualFocus && !connectButton.pressed
            }
        }

        contentItem: Text {
            text: netInterface.connected === 0 || netInterface.connected === 2 ? "Connect" : "Disconnect"
            color: connectButton.enabled ? (connectButton.pressed ? "#00b4ff" : "white") : "#666767"
            font.family: "Roboto Mono"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 24
        }

        enabled: netInterface.connected === 0 || netInterface.connected === 1;
        onClicked: netInterface.buttonPressed();
    }

    StyledTextInput {
        id: addressField
        Layout.preferredWidth: 250
        Layout.preferredHeight: 45

        placeholderTxt: "Address"

        EnterKey.type: Qt.EnterKeyNext
        KeyNavigation.tab: portField

        onEditingFinished: {
            netInterface.address = addressField.text;
            ensureVisible(0);
        }
        Component.onCompleted: {
            if (netInterface.address !== "")
                text = netInterface.address;
        }
    }

    StyledTextInput {
        id: portField
        Layout.preferredWidth: 250
        Layout.preferredHeight: 45

        placeholderTxt: "Port"

        EnterKey.type: Qt.EnterKeyDone
        KeyNavigation.tab: root.parent

        inputMethodHints: Qt.ImhDigitsOnly
        onEditingFinished: {
            netInterface.port = parseInt(portField.text);
            ensureVisible(0);
        }

        Component.onCompleted: {
            if (netInterface.port > -1)
                text = netInterface.port;
        }
    }

    Text {
        id: connectionText
        Layout.columnSpan: 2
        Layout.fillWidth: true
        color: "black"
        font.family: "Roboto Mono"
        font.pixelSize: 20
    }
}
