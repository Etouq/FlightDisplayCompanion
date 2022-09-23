import QtQuick 2.15
import QtQuick.Window 2.2
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import IO.Network 1.0

Popup {
    id: popup

    x: ((parent.width - 192) - width) / 2
    y: 60

    modal: true
    focus: true

    ColumnLayout {
            anchors.fill: parent
            spacing: 5

            GridLayout {
                columns: 2
                rowSpacing: 5
                columnSpacing: 10

                Text {
                    text: "Address:"
                }

                TextField {
                    id: addressField
                    Layout.preferredWidth: 380

                    EnterKey.type: Qt.EnterKeyNext
                    KeyNavigation.tab: portField

                    Keys.onEnterPressed: function() {
                        portField.forceActiveFocus()
                    }

                    Keys.onReturnPressed: function() {
                        portField.forceActiveFocus()
                    }

                    Component.onCompleted: function() {
                        text = NetworkClient.address;
                    }
                }

                Text {
                    text: "Port:"
                    Layout.fillWidth: true
                }

                TextField {
                    id: portField
                    property bool validPort: false
                    Layout.preferredWidth: 380

                    EnterKey.type: Qt.EnterKeyDone
                    KeyNavigation.tab: cancelButton

                    Keys.onEnterPressed: function() {
                        if(validPort) {
                            NetworkClient.manualConnect(addressField.text, parseInt(portField.text));
                            popup.close();
                        }
                        else
                            portField.nextItemInFocusChain().forceActiveFocus()
                    }

                    Keys.onReturnPressed: function() {
                        if(validPort) {
                            NetworkClient.manualConnect(addressField.text, parseInt(portField.text));
                            popup.close();
                        }
                        else
                            portField.nextItemInFocusChain().forceActiveFocus()
                    }

                    Component.onCompleted: function() {
                        text = NetworkClient.port;
                    }

                    onTextEdited: function() {
                        if (text === "") {
                            validPort = false;
                            return;
                        }

                        const completeVal = Number(text);

                        if (isNaN(completeVal)) {
                            console.log(text + " is not a number");
                            validPort = false;
                            undo();
                            return;
                        }
                        if (completeVal < 0) {
                            console.log(text + " is negative");
                            validPort = false;
                            undo();
                            return;
                        }
                        if (completeVal > 65535) {
                            console.log(text + " is too large");
                            validPort = false;
                            return;
                        }

                        validPort = true;
                    }
                }
            }

            RowLayout {
                spacing: 5

                Button {
                    id: cancelButton
                    Layout.preferredWidth: 80
                    Layout.fillWidth: true
                    text: "Cancel"

                    KeyNavigation.tab: okButton

                    onReleased: function() {
                        popup.close();
                    }
                }

                Button {
                    id: okButton
                    Layout.preferredWidth: 80
                    Layout.fillWidth: true
                    text: "Ok"

                    enabled: portField.validPort

                    onReleased: function() {
                        NetworkClient.manualConnect(addressField.text, parseInt(portField.text));
                        popup.close();
                    }
                }
            }
        }
}
