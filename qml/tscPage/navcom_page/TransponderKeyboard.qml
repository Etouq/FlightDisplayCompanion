import QtQuick 2.15
import QtQuick.Controls 2.15
import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"
import Tsc.NavCom 1.0
import TypeEnums 1.0

TscPageBase {
    id: root

    showBackButton: true
    showHomeButton: true
    showEnterButton: true

    pageTitle: "Transponder"


    property var currentInput: [-1, -1, -1, -1]
    property int inputIndex: -1

    Component.onCompleted: updateInput()


    function updateInput() {
        fixed.text = "";
        writed.text = "";
        writing.text = "";
        toWrite.text = "";

        if (inputIndex == -1) {
            fixed.text = ("0000" + NavCom.xpdrCode).slice(-4);
        }
        else {
            let regex = new RegExp('(.{' + inputIndex + '})(.?)(.*)');
            let transponderCode = "";
            for (let i = 0; i < currentInput.length; i++)
                transponderCode += (currentInput[i] === -1 ? "_" : currentInput[i]);
            let matches = transponderCode.match(regex);
            writed.text = matches[1];
            writing.text = matches[2];
            toWrite.text = matches[3];
        }
    }

    function digitPressed(_digit) {
        if (inputIndex == -1) {
            currentInput = [-1, -1, -1, -1];
            inputIndex = 0;
        }
        if (inputIndex < 4) {
            currentInput[inputIndex] = _digit;
            inputIndex++;

            if (inputIndex === 4) {
                let code = 4096 * root.currentInput[0] + 256 * root.currentInput[1] + 16 * root.currentInput[2] + root.currentInput[3];
                NavCom.xpdrCode = code;
            }
        }

        updateInput();
    }

    function backspacePressed() {
        if (inputIndex == -1) {
            currentInput = [-1, -1, -1, -1];
            inputIndex = 0;
        }
        else if (inputIndex > 0) {
            inputIndex--;
            currentInput[inputIndex] = -1;
        }

        updateInput();
    }





    Column {
        x: 29.184
        y: 39
        spacing: 6

        Text {
            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 60
            color: "white"
            text: "Mode"
        }

        GradientButton {
            MainText {
                font.pixelSize: 42
                text: "Altitude\nReporting"
            }

            GradientStatusBar {
                active: NavCom.xpdrState === TransponderState.ALT
            }

            onReleased: tscBackend.xpdrState = TransponderState.ALT
        }

        GradientButton {
            MainText {
                font.pixelSize: 42
                text: "On"
            }

            GradientStatusBar {
                active: NavCom.xpdrState === TransponderState.ON
            }

            onReleased: NavCom.xpdrState = TransponderState.ON
        }

        GradientButton {
            MainText {
                font.pixelSize: 42
                text: "Standby"
            }

            GradientStatusBar {
                active: NavCom.xpdrState === TransponderState.STANDBY
            }

            onReleased: NavCom.xpdrState = TransponderState.STANDBY
        }
    }

    Rectangle {
        x: 572.16
        y: 120
        width: 583.68
        height: 132
        color: "#212121"

        Row {
            anchors.centerIn: parent
            spacing: 0

            Label {
                id: fixed
                visible: text.length > 0
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 96
                color: "black"
                text: "0123"

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
                font.pixelSize: 96
                color: "aqua"
                text: ""
            }

            Label {
                id: writing
                visible: text.length > 0
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 96
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
                font.pixelSize: 96
                color: "aqua"
                text: ""
            }

        }
    }

    GradientButton {
        x: 1360.5
        y: 30

        Img {
            source: "qrc:/images/buttonImages/ICON_MAP_BKSP.png"
        }

        Title {
            text: "BKSP"
        }

        onReleased: root.backspacePressed();
    }

    Column {
        x: 562.5
        y: 300
        spacing: 30

        Row {
            height: 240
            spacing: 30

            GradientRoundButton {
                width: 240
                height: 240
                text: "0"

                onReleased: root.digitPressed(0);
            }

            GradientRoundButton {
                width: 240
                height: 240
                text: "1"

                onReleased: root.digitPressed(1);
            }

            GradientRoundButton {
                width: 240
                height: 240
                text: "2"

                onReleased: root.digitPressed(2);
            }

            GradientRoundButton {
                width: 240
                height: 240
                text: "3"

                onReleased: root.digitPressed(3);
            }
        }

        Row {
            height: 240
            spacing: 30

            GradientRoundButton {
                width: 240
                height: 240
                text: "4"

                onReleased: root.digitPressed(4);
            }

            GradientRoundButton {
                width: 240
                height: 240
                text: "5"

                onReleased: root.digitPressed(5);
            }

            GradientRoundButton {
                width: 240
                height: 240
                text: "6"

                onReleased: root.digitPressed(6);
            }

            GradientRoundButton {
                width: 240
                height: 240
                text: "7"

                onReleased: root.digitPressed(7);
            }
        }
    }

    GradientButton {
        x: 1360.5
        y: 926.4

        MainText {
            text: "VFR"
        }

        onReleased: {
            root.currentInput = [1, 2, 0, 0];
            root.inputIndex = 4
            root.updateInput();

            let code = 4096 * root.currentInput[0] + 256 * root.currentInput[1] + 16 * root.currentInput[2] + root.currentInput[3];
            NavCom.xpdrCode = code;
        }
    }





}
