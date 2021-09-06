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

    signal transferClicked()

    property real minFreq: 0 // minimum frequency in Hz
    property real maxFreq: 0 // maximum frequency in Hz
    property real stbyFreq: 0 // standby frequency in Hz
    property var endCallback: null
    property int nbDigits: 3 // number of decimal digits in MHz notation

    property int inputIndex: -1
    property int currentInput: 0 // current frequency input in Hz


    function setContext(_title, _minFreq, _maxFreq, _activeFreq, _stbyFreq, _endCallback, _nbDigits) {
        pageTitle = _title;
        minFreq = _minFreq * 1000000;
        maxFreq = _maxFreq * 1000000;
        activeFreqText.text = "Active Freq: " + (_activeFreq / 1000000).toFixed(_nbDigits);
        stbyFreq = _stbyFreq;
        endCallback = _endCallback;
        nbDigits = _nbDigits;

        currentInput = _stbyFreq;

        updateInput();
    }

    function updateInput() {
        stbyFreqLabel.text = "";
        writed.text = "";
        writing.text = "";
        toWrite.text = "";

        if (inputIndex == -1) {
            currentInput = stbyFreq;
            stbyFreqLabel.text = (stbyFreq / 1000000).toFixed(nbDigits);
        }
        else {
            let inputString = (currentInput / 1000000).toFixed(nbDigits);
            let regexStr = new RegExp('(.{' + (inputIndex > 2 ? inputIndex + 1 : inputIndex) + '})(.?)(.*)');
            let matches = inputString.match(regexStr);
            writed.text = matches[1];
            writing.text = matches[2];
            toWrite.text = matches[3];
        }
    }

    function digitPressed(_digit) {
        if (inputIndex == -1) {
            inputIndex = 0;
            currentInput = minFreq;
        }

        if (inputIndex < (3 + nbDigits) &&
                (nbDigits == 3 || inputIndex != 4 ||
                 _digit === 0 || _digit === 2 || _digit === 5 || _digit === 7)) {

            let newInput = Math.pow(10, 9 - inputIndex) *
                Math.floor((currentInput + 1) / Math.pow(10, 9 - inputIndex)) +
                Math.pow(10, 8 - inputIndex) * _digit;

            if (newInput <= maxFreq && newInput >= minFreq) {
                currentInput = newInput;
                inputIndex++
            }
            else if (newInput < minFreq && Math.pow(10, 8 - inputIndex) > minFreq - newInput) {
                currentInput = minFreq;
                inputIndex++;
            }

        }

        updateInput();
    }

    function backspacePressed() {
        if (inputIndex > 0) {
            inputIndex--;
            currentInput = Math.pow(10, 9 - inputIndex) * Math.floor(currentInput / Math.pow(10, 9 - inputIndex));

            if (currentInput < minFreq)
                currentInput = minFreq;
        }

        updateInput();
    }



    Column {
        spacing: 12
        width: 576
        x: 576
        y: 120

        Text {
            id: activeFreqText
            width: 576
            horizontalAlignment: Text.AlignHCenter
            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 42
            color: "white"
        }

        Rectangle {
            width: 576
            height: 108
            color: "grey"

            Row {
                anchors.centerIn: parent
                spacing: 0

                Label {
                    id: stbyFreqLabel
                    visible: text.length > 0
                    font.family: "Roboto Mono"
                    font.bold: true
                    font.pixelSize: 72
                    color: "black"
                    text: "117.95"

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
                    font.pixelSize: 72
                    color: "aqua"
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
                    id: toWrite
                    visible: text.length > 0
                    font.family: "Roboto Mono"
                    font.bold: true
                    font.pixelSize: 72
                    color: "dimgray"
                    text: ""
                }
            }
        }

    }


    GradientButton {
        y: 120
        x: 1228.26
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
                onReleased: root.digitPressed(1)
            }

            GradientRoundButton {
                width: 180
                height: 180
                text: "2"
                onReleased: root.digitPressed(2)
            }

            GradientRoundButton {
                width: 180
                height: 180
                text: "3"
                onReleased: root.digitPressed(3)
            }
        }

        Row {
            height: 180
            spacing: 82.26

            GradientRoundButton {
                width: 180
                height: 180
                text: "4"
                onReleased: root.digitPressed(4)
            }

            GradientRoundButton {
                width: 180
                height: 180
                text: "5"
                onReleased: root.digitPressed(5)
            }

            GradientRoundButton {
                width: 180
                height: 180
                text: "6"
                onReleased: root.digitPressed(6)
            }
        }

        Row {
            height: 180
            spacing: 82.26

            GradientRoundButton {
                width: 180
                height: 180
                text: "7"
                onReleased: root.digitPressed(7)
            }

            GradientRoundButton {
                width: 180
                height: 180
                text: "8"
                onReleased: root.digitPressed(8)
            }

            GradientRoundButton {
                width: 180
                height: 180
                text: "9"
                onReleased: root.digitPressed(9)
            }
        }

        Row {
            x: 262.26
            height: 120
            spacing: 82.26

            GradientRoundButton {
                width: 180
                height: 180
                text: "0"
                onReleased: root.digitPressed(0)
            }

            GradientButton {
                width: 180
                height: 180

                Img {
                    source: "qrc:/images/DoubleArrowVerticalWhite.svg"
                }

                Title {
                    text: "XFER"
                }

                onReleased: root.transferClicked();
            }
        }



    }

}
