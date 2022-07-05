import QtQuick 2.15
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.15

import Pfd.Altimeter 1.0

import "../../"
import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"

TscPageBase {
    id: root

    property var digits: [0, 0, 0, 0, 0]
    property bool isEditing: false

    function updateInput() {
        initial.text = ""
        nonWriting.text = ""
        writed.text = ""

        if (isEditing) {

            let splitIndex = digits.findIndex(function(digit, index) {

                return digit !== 0 || index === digits.length - 1
            });

            nonWriting.text = digits.slice(0, splitIndex).join("")
            writed.text = digits.slice(splitIndex, -1).join("")
        } else {
            initial.text = Altimeter.minimumsValue + "FT"
        }
    }

    function onDigitPressed(_digit) {
        if (!isEditing) {
            isEditing = true
            digits = [0, 0, 0, 0, 0]
        }
        if (digits[0] === 0) {
            for (let i = 0; i < digits.length - 1; i++) {
                digits[i] = digits[i + 1]
            }
        }
        digits[digits.length - 1] = _digit

        updateInput()
    }

    function onBackspacePressed() {
        if (!isEditing) {
            isEditing = true
            digits = [0, 0, 0, 0, 0]
        }
        for (var i = digits.length - 1; i > 0; i--) {
            digits[i] = digits[i - 1]
        }
        digits[0] = 0

        updateInput()
    }


    showBackButton: true
    showEnterButton: true

    pageTitle: "Minimums"

    Component.onCompleted: {
        let storedValue = Altimeter.minimumsValue

        for (var i = digits.length - 1; i >= 0; i--) {
            digits[i] = storedValue % 10
            storedValue = Math.floor(storedValue / 10)
        }

        updateInput()
    }

    onEnterClicked: function() {
        isEditing = false
        let newValue = 0

        for (var i = 0; i < digits.length; i++) {
            newValue += digits[i] * Math.pow(10, digits.length - i - 1)
        }

        Altimeter.minimumsValue = newValue
        Altimeter.updateMinimumAlt()
        updateInput()
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
            text: Altimeter.minimumsState === 0 ? "Off" : Altimeter.minimumsState
                                                  === 1 ? "Baro" : "Radio Alt"
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
                    visible: root.isEditing
                    font.family: "Roboto Mono"
                    font.bold: true
                    font.pixelSize: 72
                    color: "aqua"
                    text: root.digits[4]
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
                source: "qrc:/images/buttonImages/ICON_MAP_BKSP.png"
            }

            Title {
                text: "BKSP"
            }

            onReleased: root.onBackspacePressed()
        }

        NumericKeyboard {
            y: 216
            x: -111.492

            onDigitPressed: function (digit) {
                root.digitPressed(digit)
            }
        }
    }

    MinimumsSource {
        id: minimumsPopup
    }
}
