import QtQuick 2.15
import QtQuick.Controls 2.15
import "gradientButtonElements"

Column {
    id: numKeyboard

    signal digitPressed(int digit)
    signal transferPressed()

    property bool hasTransferButton: false

    spacing: 30
    height: 810

    Row {
        height: 180
        spacing: 82.26

        GradientRoundButton {
            width: 180
            height: 180
            text: "1"

            onReleased: numKeyboard.digitPressed(1);
        }

        GradientRoundButton {
            width: 180
            height: 180
            text: "2"

            onReleased: numKeyboard.digitPressed(2);
        }

        GradientRoundButton {
            width: 180
            height: 180
            text: "3"

            onReleased: numKeyboard.digitPressed(3);
        }
    }

    Row {
        height: 180
        spacing: 82.26

        GradientRoundButton {
            width: 180
            height: 180
            text: "4"

            onReleased: numKeyboard.digitPressed(4);
        }

        GradientRoundButton {
            width: 180
            height: 180
            text: "5"

            onReleased: numKeyboard.digitPressed(5);
        }

        GradientRoundButton {
            width: 180
            height: 180
            text: "6"

            onReleased: numKeyboard.digitPressed(6);
        }
    }

    Row {
        height: 180
        spacing: 82.26

        GradientRoundButton {
            width: 180
            height: 180
            text: "7"

            onReleased: numKeyboard.digitPressed(7);
        }

        GradientRoundButton {
            width: 180
            height: 180
            text: "8"

            onReleased: numKeyboard.digitPressed(8);
        }

        GradientRoundButton {
            width: 180
            height: 180
            text: "9"

            onReleased: numKeyboard.digitPressed(9);
        }
    }

    Row {
        x: 262.26
        height: 180
        spacing: 82.26

        GradientRoundButton {
            width: 180
            height: 180
            text: "0"
            onReleased: numKeyboard.digitPressed(0)
        }

        Loader {
            active: numKeyboard.hasTransferButton
            sourceComponent: GradientButton {
                width: 180
                height: 180

                Img {
                    source: "qrc:/images/buttonImages/DoubleArrowVerticalWhite.svg"
                }

                Title {
                    text: "XFER"
                }

                onReleased: numKeyboard.transferPressed();
            }
        }


    }

}

