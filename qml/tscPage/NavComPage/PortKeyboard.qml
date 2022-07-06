import QtQuick 2.15
import QtQuick.Controls 2.15

import IO.Network 1.0

import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"

TscPageBase {
    id: root

    showBackButton: true
    showEnterButton: true

    pageTitle: "Enter Port"

    Component.onCompleted: function() {
        updateInput();
    }

    onEnterClicked: function() {
        NetworkClient.port = currentInput
        root.backClicked();
    }



    property var digits: [0, 0, 0, 0, 0]
    property bool isInputing: false
    property int nbInput: 0
    property int currentInput: 0

    function updateInput() {
        toWrite.text = ""
        writed.text = ""
        writing.text = ""

        if (isInputing) {
            for (var i = 0; i < digits.length - 1; i++) {
                if (i < digits.length - nbInput)
                    toWrite.text += digits[i]
                else
                    writed.text += digits[i]
            }
            writing.text = digits[digits.length - 1]
        } else {
            toWrite.text = currentInput
            writing.text = ""
        }
    }

    function digitPressed(_digit) {
        if (!isInputing) {
            isInputing = true
            nbInput = 0
            digits = [0, 0, 0, 0, 0]
        }
        if (digits[0] === 0) {
            for (var i = 0; i < digits.length - 1; i++)
                digits[i] = digits[i + 1]
        }

        digits[digits.length - 1] = _digit
        currentInput = 10000 * digits[0] + 1000 * digits[1] + 100 * digits[2] + 10 * digits[3] + digits[4]

        if (nbInput < digits.length)
            nbInput++

        updateInput()
    }

    function backspacePressed() {
        if (!isInputing) {
            isInputing = true
            nbInput = 0
            digits = [0, 0, 0, 0, 0]
        }
        for (var i = digits.length - 1; i > 0; i--)
            digits[i] = digits[i - 1]

        digits[0] = 0
        currentInput = 10000 * digits[0] + 1000 * digits[1] + 100 * digits[2] + 10 * digits[3] + digits[4]

        if (nbInput > 0)
            nbInput--

        updateInput()
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
                id: toWrite
                visible: text.length > 0
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 84
                color: "dimgray"
                text: "00000"
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

    NumericKeyboard {
        y: 336
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864

        onDigitPressed: function (digit) {
            root.digitPressed(digit)
        }
    }
}
