import QtQuick 2.15
import QtQuick.Controls 2.15
import Tsc.SpeedBugs 1.0

import "../../"
import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"

TscPageBase {
    id: root

    showBackButton: true
    showEnterButton: true

    pageTitle: "Enter Designator"

    property var currentValue: ["_", "_", "_", "_", "_", "_"]
    property int currentIndex: -1
    property string currentInput: ""

    onEnterClicked: function() {
        SpeedBugs.newSpeedBug(currentInput);
        root.backClicked();
    }

    function updateInput() {
        noEdit.text = ""
        writed.text = ""
        writing.text = ""
        toWrite.text = ""

        root.currentInput = ""

        if (root.currentIndex === -1) {
            noEdit.text = root.currentValue.join("");
            return;
        }

        for (let i = 0; i < root.currentIndex; i++) {
            root.currentInput += root.currentValue[i];
        }

        writed.text = root.currentValue.slice(0, root.currentIndex).join("")
        writing.text = root.currentValue[root.currentIndex]
        toWrite.text = root.currentValue.slice(root.currentIndex + 1).join("")
    }

    function keyPressed(_key) {
        if (root.currentIndex >= root.currentValue.length)
            return;

        if (root.currentIndex === -1)
            root.currentIndex = 0

        root.currentValue[root.currentIndex] = _key
        root.currentIndex++

        for (let i = root.currentIndex; i < root.currentValue.length; i++) {
            root.currentValue[i] = "_"
        }

        root.updateInput()
    }

    function backspacePressed() {
        if (root.currentIndex === -1)
            return;

        root.currentIndex--
        for (let i = root.currentIndex; i < root.currentValue.length; i++) {
            root.currentValue[i] = "_"
        }

        root.updateInput()
    }

    Rectangle {
        width: 437.22
        x: 645.12
        y: 120
        height: 108
        color: "grey"

        Row {
            anchors.centerIn: parent
            spacing: 0

            Text {
                id: prefix
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 84
                color: "dimgray"
                text: "V"
            }

            Label {
                id: noEdit
                visible: text.length > 0
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 84
                color: "black"
                text: "______"
                topInset: 6
                bottomInset: 6

                background: Rectangle {
                    color: "aqua"
                }

            }

            Text {
                id: writed
                visible: text.length > 0
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 84
                color: "aqua"
                text: ""
            }

            Label {
                id: writing
                visible: text.length > 0
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 84
                color: "aqua"
                text: ""
                topInset: 6
                bottomInset: 6

                background: Rectangle {
                    id: writingBg
                }

                SequentialAnimation {
                    running: true
                    loops: Animation.Infinite
                    PropertyAction {
                        target: writingBg
                        property: "color"
                        value: "aqua"
                    }
                    PropertyAction {
                        target: writing
                        property: "color"
                        value: "black"
                    }
                    PauseAnimation {
                        duration: 400
                    }
                    ParallelAnimation {
                        ColorAnimation {
                            target: writingBg
                            property: "color"
                            from: "aqua"
                            to: "transparent"
                            duration: 200
                        }
                        ColorAnimation {
                            target: writing
                            property: "color"
                            from: "black"
                            to: "aqua"
                            duration: 200
                        }
                    }
                    PauseAnimation {
                        duration: 400
                    }
                }
            }

            Text {
                id: toWrite
                visible: text.length > 0
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 84
                color: "dimgray"
                text: ""
            }

        }
    }

    GradientButton {
        x: 1228.26
        y: 120
        width: 291.84
        Img {
            source: "qrc:/images/buttonImages/ICON_MAP_BKSP.png"
        }

        Title {
            text: "BKSP"
        }

        onReleased: root.backspacePressed()
    }

    FullKeyboard {
        y: 336
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864

        upperCase: false

        onKeyPressed: function (key) {
            root.keyPressed(key)
        }
    }
}
