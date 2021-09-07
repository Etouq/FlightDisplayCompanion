import QtQuick 2.15
import "../styled_controls"
import "../styled_controls/gradientButtonElements"

Row {
    id: root
    property alias name: radioId.text
    property alias activeFreq: radioActiveFreq.text
    property alias standbyFreq: radioStandbyFreq.text

    signal frequencyClicked()
    signal xferClicked()

    width: 663.6
    height: 192
    spacing: 4.8

    Rectangle {
        width: 224.4
        height: 192
        color: "black"

        GradientButton {
            x: 6
            y: 6
            width: 212.4
            height: 180

            Text {
                id: radioId
                x: 22.5
                y: 7.5
                font.family: "Roboto Mono"
                font.pixelSize: 66
                font.bold: true
                color: "white"
                text: "COM1"
            }
        }
    }

    Rectangle {
        width: 434.4
        height: 192
        color: "black"

        GradientButton {
            x: 6
            y: 6
            width: 422.4
            height: 180

            Column {
                anchors.verticalCenter: parent.verticalCenter
                x: 33.792
                spacing: 0

                Text {
                    id: radioActiveFreq
                    font.pixelSize: 66
                    font.family: "Roboto Mono"
                    font.bold: true
                    color: "white"
                    text: "124.850"
                }

                Text {
                    id: radioStandbyFreq
                    font.pixelSize: 66
                    font.family: "Roboto Mono"
                    font.bold: true
                    color: "aqua"
                    text: "118.850"
                }
            }

            onReleased: root.frequencyClicked()
        }
    }

    Rectangle {
        width: 192
        height: 192
        color: "black"

        GradientButton {
            x: 6
            y: 6
            width: 180
            height: 180

            Img {
                source: "qrc:/images/buttonImages/DoubleArrowVerticalWhite.svg"
            }

            Title {
                text: "XFER"
            }

            onReleased: root.xferClicked()
        }
    }
}

