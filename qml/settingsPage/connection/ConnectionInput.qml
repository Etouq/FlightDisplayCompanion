import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQml 2.15
import QtQuick.Layouts 1.15
import "../flightplan"

GridLayout {
    x: 50
    y: 100
    columns: 2
    rowSpacing: 10

    Button {
        id: connectButton
        Layout.preferredWidth: 250
        Layout.preferredHeight: 100
        Layout.rowSpan: 2
        Layout.rightMargin: 20
        opacity: enabled ? 1 : 0.38

        background: Rectangle {
            color: connectButton.enabled ? (connectButton.pressed ? "white" : "#00b4ff") : "#949595"
            radius: 6

            Rectangle {
                anchors.fill: parent
                color: "white"
                opacity: 0.24
                visible: connectButton.focus && !connectButton.pressed
            }
        }

        contentItem: Text {
            text: netInterface.connected === 0 ? "Connect" : netInterface.connected === 1 ? "Disconnect" : netInterface.connected === 2 ? "Connecting" : "Disconnecting"
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
}
