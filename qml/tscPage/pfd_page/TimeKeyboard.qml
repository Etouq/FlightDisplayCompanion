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

    pageTitle: "Enter Time"

    property var digits: [0, 0, 0, 0, 0, 0]
    property bool isInputing: false
    property int nbInput: 0
    property int currentInput: 0

    function validateEdit() {
        let maxDigits = [2, 3, 5, 9, 5, 9];
        let isValid = true;
        for (let i = 0; i < this.digits.length; i++) {
            if (this.digits[i] > maxDigits[i]) {
                isValid = false;
            }
        }
        if (isValid) {
            return true;
        }
        else {
            isInputing = false;
            invalidInputPopup.visible = true;
            return false;
        }
    }

    function updateInput() {
        if (isInputing) {
           let text = "";
            for (let i = 0; i < digits.length - 1; i++) {
                text += '<font color="' + (i < digits.length - nbInput ? "dimgray" : "aqua") + '">';
                text += digits[i] + '</font>';

                if (i % 2 == 1)
                    text += '<font color="aqua">:</font>';
            }

            nonWriting.text = text;

            writing.text = digits[digits.length - 1];
        }
        else {
            let seconds = Math.floor(currentInput / 1000) % 60;
            let minutes = Math.floor(currentInput / 60000) % 60;
            let hours = Math.floor(currentInput / 3600000) % 24;

            nonWriting.text = '<font color="white">' + '00'.slice(0, 2 - hours.toString().length) + hours + ':' + '00'.slice(0, 2 - minutes.toString().length) + minutes + ':' + '00'.slice(0, 2 - seconds.toString().length) + seconds + '</font>';
            writing.text = "";
        }
    }

    function digitPressed(_digit) {
        if (!isInputing) {
            isInputing = true;
            nbInput = 0;
            digits = [0, 0, 0, 0, 0, 0];
        }
        if (digits[0] === 0) {
            for (let i = 0; i < digits.length - 1; i++)
                digits[i] = digits[i + 1];
        }

        digits[digits.length - 1] = _digit;
        currentInput = (10 * digits[0] + digits[1]) * 3600000 + (10 * digits[2] + digits[3]) * 60000 + (10 * digits[4] + digits[5]) * 1000;

        if (nbInput < digits.length)
            nbInput++;

        updateInput();
    }

    function backspacePressed() {
        if (!isInputing) {
            isInputing = true;
            nbInput = 0;
            digits = [0, 0, 0, 0, 0, 0];
        }
        for (let i = digits.length - 1; i > 0; i--)
            digits[i] = digits[i - 1];

        digits[0] = 0;
        currentInput = (10 * digits[0] + digits[1]) * 3600000 + (10 * digits[2] + digits[3]) * 60000 + (10 * digits[4] + digits[5]) * 1000;

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
                id: nonWriting
                visible: text.length > 0
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 84
                textFormat: Text.StyledText
                text: '<font color="dimgray">00</font><font color="aqua">:</font><font color="dimgray">00</font><font color="aqua">:</font><font color="dimgray">00</font>'
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


    Rectangle {
        id: invalidInputPopup
        x: 288
        y: 180
        width: 1152
        height: 840
        border.width: 4.8
        border.color: "white"
        color: "black"
        visible: false

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            y: 42
            width: 1036.8
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 84
            font.family: "Roboto Mono"
            font.bold: true
            color: "white"
            text: "Invalid Entry\nValid range is\n00:00:00\nto\n23:59:59"
        }

        GradientButton {
            width: 230.4
            height: 168
            x: 460.8
            y: 630

            MainText {
                text: "OK"
            }

            onReleased: invalidInputPopup.visible = false
        }
    }


}
