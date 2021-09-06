import QtQuick 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.15
import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"

TscPageBase {
    id: root

    showBackButton: true
    showHomeButton: true
    showEnterButton: true

    pageTitle: "Minimums"


    property var digits: [0, 0, 0, 0, 0]
    property bool isEditing: false


    function updateInput() {
        initial.text = "";
        nonWriting.text = "";
        writing.text = "";

        if (isEditing) {
            nonWriting.text = '<font color="black">';
            let zerosEnded = false;

            for (let i = 0; i < digits.length -1; i++) {
                if (digits[i] !== 0 && !zerosEnded) {
                    nonWriting.text += '</font><font color="aqua">';
                    zerosEnded = true;
                }
                nonWriting.text += digits[i];
            }

            nonWriting.text += '</font>';

            writing.text = digits[digits.length - 1];
        }
        else {
            initial.text = tscBackend.minimumsValue + "FT";
        }
    }

    function onDigitPressed(_digit) {
        if (!isEditing) {
            isEditing = true;
            digits = [0, 0, 0, 0, 0];
        }
        if (digits[0] === 0) {
            for (let i = 0; i < digits.length - 1; i++) {
                digits[i] = digits[i + 1];
            }
        }
        digits[digits.length - 1] = _digit;

        updateInput();
    }

    function onBackspacePressed() {
        if (!isEditing) {
            isEditing = true;
            digits = [0, 0, 0, 0, 0];
        }
        for (let i = digits.length - 1; i > 0; i--) {
            digits[i] = digits[i - 1];
        }
        digits[0] = 0;

        updateInput();
    }

    Component.onCompleted: {
        let storedValue = tscBackend.minimumsValue;

        for (let i = digits.length - 1; i >= 0; i--) {
            digits[i] = storedValue % 10;
            storedValue = Math.floor(storedValue / 10);
        }

        updateInput();
    }

    onEnterClicked: {
        isEditing = false;
        let newValue = 0;

        for (let i = 0; i < digits.length; i++) {
            newValue += digits[i] * Math.pow(10, digits.length - i - 1);
        }

        tscBackend.minimumsValue = newValue;
        updateInput();
    }


    GradientButton {
        width: 437.76
        height: 216
        x: 116.448
        y: 120

        UpperTitle {
            text: "Minimums"
        }

        LowerValue {
            text: tscBackend.minimumsState === 0 ? "Off" : tscBackend.minimumsState === 1 ? "Baro" : "Radio Alt"
        }

        onReleased: minimumsPopup.visible = true
    }





    Item {
        width: 802.56
        height: 1080
        x: 623.232
        y: 120

        Rectangle {
            width: 481.536
            height: 97.2
            y: 54
            color: "#212121"

            Row {
                anchors.centerIn: parent

                Label {
                    id: initial
                    visible: text.length > 0
                    font.family: "Roboto Mono"
                    font.bold: true
                    font.pixelSize: 72
                    color: "black"
                    text: "0FT"

                    topInset: 6
                    bottomInset: 6

                    background: Rectangle {
                        color: "aqua"
                    }
                }

                Text {
                    id: nonWriting
                    visible: text.length > 0
                    font.family: "Roboto Mono"
                    font.bold: true
                    font.pixelSize: 72
                    color: "black"
                    text: ""
                }

                Label {
                    id: writing
                    visible: text.length > 0
                    font.family: "Roboto Mono"
                    font.bold: true
                    font.pixelSize: 72
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

                Text {
                    visible: !initial.visible
                    font.family: "Roboto Mono"
                    font.bold: true
                    font.pixelSize: 72
                    color: "aqua"
                    text: "FT"
                }

            }

        }

        GradientButton {
            anchors.right: parent.right
            height: 216

            Img {
                source: "qrc:/images/ICON_MAP_BKSP.png"
            }

            Title {
                text: "BKSP"
            }

            onReleased: root.onBackspacePressed()
        }

        Column {
            y: 216
            x: -111.492
            spacing: 30
            height: 810

            Row {
                height: 180
                spacing: 82.26

                GradientRoundButton {
                    width: 180
                    height: 180
                    text: "1"

                    onReleased: root.onDigitPressed(1)
                }

                GradientRoundButton {
                    width: 180
                    height: 180
                    text: "2"

                    onReleased: root.onDigitPressed(2)
                }

                GradientRoundButton {
                    width: 180
                    height: 180
                    text: "3"

                    onReleased: root.onDigitPressed(3)
                }
            }

            Row {
                height: 180
                spacing: 82.26

                GradientRoundButton {
                    width: 180
                    height: 180
                    text: "4"

                    onReleased: root.onDigitPressed(4)
                }

                GradientRoundButton {
                    width: 180
                    height: 180
                    text: "5"

                    onReleased: root.onDigitPressed(5)
                }

                GradientRoundButton {
                    width: 180
                    height: 180
                    text: "6"

                    onReleased: root.onDigitPressed(6)
                }
            }

            Row {
                height: 180
                spacing: 82.26

                GradientRoundButton {
                    width: 180
                    height: 180
                    text: "7"

                    onReleased: root.onDigitPressed(7)
                }

                GradientRoundButton {
                    width: 180
                    height: 180
                    text: "8"

                    onReleased: root.onDigitPressed(8)
                }

                GradientRoundButton {
                    width: 180
                    height: 180
                    text: "9"

                    onReleased: root.onDigitPressed(9)
                }
            }

            GradientRoundButton {
                x: 262.26
                width: 180
                height: 180
                text: "0"

                onReleased: root.onDigitPressed(0)
            }
        }


    }


    MinimumsSource {
        id: minimumsPopup
    }

}
