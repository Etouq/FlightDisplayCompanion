import QtQuick 2.15
import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"

TscPageBase {
    id: root

    showBackButton: true
    showHomeButton: true

    pageTitle: "Radios"

    signal xpndrClicked()

    signal radioClicked(string title, real minFreq, real maxFreq, int activeFreq, int stbyFreq, var endCallback, int nbDigits);

    Rectangle {
        y: 120
        width: 870
        height: 988.8
        color: "white"
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864

        Column {
            x: 4.8
            y: 4.8
            width: 860.4
            height: 979.2

            spacing: 4.8

            RadioRow {
                name: "COM1"
                activeFreq: (tscBackend.com1ActiveHz / 1000000).toFixed(3)
                standbyFreq: (tscBackend.com1StbyHz / 1000000).toFixed(3)

                onFrequencyClicked: root.radioClicked("COM1 Standby", 118, 136.99, tscBackend.com1ActiveHz, tscBackend.com1StbyHz, tscBackend.setCom1Freq, 3)
                onXferClicked: tscBackend.swapCom1()
            }

            RadioRow {
                name: "COM2"
                activeFreq: (tscBackend.com2ActiveHz / 1000000).toFixed(3)
                standbyFreq: (tscBackend.com2StbyHz / 1000000).toFixed(3)

                onFrequencyClicked: root.radioClicked("COM2 Standby", 118, 136.99, tscBackend.com2ActiveHz, tscBackend.com2StbyHz, tscBackend.setCom2Freq, 3)
                onXferClicked: tscBackend.swapCom2()
            }

            RadioRow {
                name: "NAV1"
                activeFreq: (tscBackend.nav1ActiveHz / 1000000).toFixed(2)
                standbyFreq: (tscBackend.nav1StbyHz / 1000000).toFixed(2)

                onFrequencyClicked: root.radioClicked("NAV1", 108, 117.95, tscBackend.nav1ActiveHz, tscBackend.nav1StbyHz, tscBackend.setNav1Freq, 2)
                onXferClicked: tscBackend.swapNav1()
            }

            RadioRow {
                name: "NAV2"
                activeFreq: (tscBackend.nav2ActiveHz / 1000000).toFixed(2)
                standbyFreq: (tscBackend.nav2StbyHz / 1000000).toFixed(2)

                onFrequencyClicked: root.radioClicked("NAV2", 108, 117.95, tscBackend.nav2ActiveHz, tscBackend.nav2StbyHz, tscBackend.setNav2Freq, 2)
                onXferClicked: tscBackend.swapNav2()
            }

            Row {
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
                            x: 22.5
                            y: 7.5
                            font.family: "Roboto Mono"
                            font.pixelSize: 66
                            font.bold: true
                            color: "white"
                            text: "XPDR"
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


                        TopText {
                            property var stateToString: ["Off", "STBY", "TEST", "ON", "ALT"]
                            x: 33.792
                            font.pixelSize: 36
                            color: tscBackend.xpdrState === 3 || tscBackend.xpdrState === 4 ? "lawngreen" : "white"
                            text: stateToString[tscBackend.xpdrState]
                        }

                        Text {
                            x: 33.792
                            anchors.verticalCenter: parent.verticalCenter
                            font.pixelSize: 84
                            font.family: "Roboto Mono"
                            font.bold: true
                            color: tscBackend.xpdrState === 3 || tscBackend.xpdrState === 4 ? "lawngreen" : "white"
                            text: ("0000" + tscBackend.xpdrCode).slice(-4)
                        }

                        onReleased: root.xpndrClicked()
                    }
                }

                Rectangle {
                    width: 192
                    height: 192
                    color: "black"
                }


            }

        }
    }


}
