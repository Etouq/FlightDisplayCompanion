import QtQuick 2.15
import QtQuick.Controls 2.15
import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"

TscPageBase {
    id: root

    showBackButton: true
    showHomeButton: true
    showEnterButton: true

    pageTitle: "Enter Speed"

    function setContext(_callback, _startingValue) {
        callback = _callback;
        currentInput = _startingValue;
        updateInput();
    }

    property var callback

    property var digits: [0, 0, 0]
    property bool isInputing: false
    property int nbInput: 0
    property int currentInput: 0

    function updateInput() {
        toWrite.text = "";
        writed.text = "";
        writing.text = "";

        if (isInputing) {
            for (let i = 0; i < digits.length - 1; i++) {
                if (i < digits.length - nbInput)
                    toWrite.text += digits[i];
                else
                    writed.text += digits[i];
            }
            writing.text = digits[digits.length - 1];
        }
        else {
            toWrite.text = currentInput + "KT";
            writing.text = "";
        }
    }

    function digitPressed(_digit) {
        if (!isInputing) {
            isInputing = true;
            nbInput = 0;
            digits = [0, 0, 0];
        }
        if (digits[0] === 0) {
            for (let i = 0; i < digits.length - 1; i++)
                digits[i] = digits[i + 1];
        }

        digits[digits.length - 1] = _digit;
        currentInput = 100 * digits[0] + 10 * digits[1] + digits[2];

        if (nbInput < digits.length)
            nbInput++;

        updateInput();
    }

    function backspacePressed() {
        if (!isInputing) {
            isInputing = true;
            nbInput = 0;
            digits = [0, 0, 0];
        }
        for (let i = digits.length - 1; i > 0; i--)
            digits[i] = digits[i - 1];

        digits[0] = 0;
        currentInput = 100 * digits[0] + 10 * digits[1] + digits[2];

        if (nbInput > 0)
            nbInput--;

        updateInput();
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
                text: "00KT"
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
                    PropertyAction { target: writingBg; property: "color"; value: "aqua" }
                    PropertyAction { target: writing; property: "color"; value: "black" }
                    PauseAnimation { duration: 400 }
                    ParallelAnimation {
                        ColorAnimation { target: writingBg; property: "color"; from: "aqua"; to: "transparent"; duration: 200 }
                        ColorAnimation { target: writing; property: "color"; from: "black"; to: "aqua"; duration: 200 }
                    }
                    PauseAnimation { duration: 400 }
                }
            }
        }
    }

    GradientButton {
        x: 1228.26
        y: 120
        width: 291.84
        Img {
            source: "qrc:/images/ICON_MAP_BKSP.png"
        }

        Title {
            text: "BKSP"
        }

        onReleased: root.backspacePressed();
    }

    Column {
        y: 336
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864
        spacing: 30
        height: 810

        Row {
            height: 180
            spacing: 82.26

            GradientRoundButton {
                width: 180
                height: 180
                text: "1"

                onReleased: root.digitPressed(1);
            }

            GradientRoundButton {
                width: 180
                height: 180
                text: "2"

                onReleased: root.digitPressed(2);
            }

            GradientRoundButton {
                width: 180
                height: 180
                text: "3"

                onReleased: root.digitPressed(3);
            }
        }

        Row {
            height: 180
            spacing: 82.26

            GradientRoundButton {
                width: 180
                height: 180
                text: "4"

                onReleased: root.digitPressed(4);
            }

            GradientRoundButton {
                width: 180
                height: 180
                text: "5"

                onReleased: root.digitPressed(5);
            }

            GradientRoundButton {
                width: 180
                height: 180
                text: "6"

                onReleased: root.digitPressed(6);
            }
        }

        Row {
            height: 180
            spacing: 82.26

            GradientRoundButton {
                width: 180
                height: 180
                text: "7"

                onReleased: root.digitPressed(7);
            }

            GradientRoundButton {
                width: 180
                height: 180
                text: "8"

                onReleased: root.digitPressed(8);
            }

            GradientRoundButton {
                width: 180
                height: 180
                text: "9"

                onReleased: root.digitPressed(9);
            }
        }

        GradientRoundButton {
            x: 262.26
            width: 180
            height: 180
            text: "0"

            onReleased: root.digitPressed(0);
        }

    }

}
