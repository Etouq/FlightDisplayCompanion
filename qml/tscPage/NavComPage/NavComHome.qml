import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQml 2.15

import Tsc.NavCom 1.0
import TypeEnums 1.0

import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"

TscPageBase {
    id: root

    pageTitle: "Radios"

    signal xpndrClicked()

    signal radioClicked(string title, real minFreq, real maxFreq, int activeFreq, int stbyFreq, var endCallback, int nbDigits)

    Rectangle {
        y: 120
        width: 870
        height: Math.min(988.8, (NavCom.com1Avail ? 196.8 : 0) + (NavCom.com2Avail ? 196.8 : 0) + (NavCom.com3Avail ? 196.8 : 0) + (NavCom.nav1Avail ? 196.8 : 0) + (NavCom.nav2Avail ? 196.8 : 0) + (NavCom.xpdrAvail ? 196.8 : 0) + 4.8)
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864

        color: "white"

        Flickable {
            id: radioList
            anchors.fill: parent
            anchors.margins: 4.8

            contentWidth: 860.4
            contentHeight: radioListColumn.height

            clip: true

            ScrollBar.vertical: ScrollBar {
                parent: radioList.parent

                anchors {
                    top: radioList.top
                    left: radioList.right
                    bottom: radioList.bottom

                    topMargin: -4.8
                    leftMargin: 9.6
                    bottomMargin: -4.8
                }

                visible: radioListColumn.height > radioList.height

                contentItem: Rectangle {
                    implicitWidth: 20
                    color: "white"
                }

            }

            Column {
                id: radioListColumn
                spacing: 4.8
                height: childrenRect.height

                Loader {
                    active: NavCom.com1Avail

                    sourceComponent: RadioRow {
                        name: "COM1"
                        activeFreq: NavCom.com1Freq.toFixed(3)
                        standbyFreq: NavCom.com1StbyFreq.toFixed(3)

                        onFrequencyClicked: root.radioClicked("COM1 Standby",
                                                              118,
                                                              136.99,
                                                              NavCom.com1Freq,
                                                              NavCom.com1StbyFreq,
                                                              NavCom.setCom1Freq,
                                                              3)
                        onXferClicked: NavCom.swapCom1()
                    }
                }

                Loader {
                    active: NavCom.com2Avail

                    sourceComponent: RadioRow {
                        name: "COM2"
                        activeFreq: NavCom.com2Freq.toFixed(3)
                        standbyFreq: NavCom.com2StbyFreq.toFixed(3)

                        onFrequencyClicked: root.radioClicked("COM2 Standby",
                                                              118,
                                                              136.99,
                                                              NavCom.com2Freq,
                                                              NavCom.com2StbyFreq,
                                                              NavCom.setCom2Freq,
                                                              3)
                        onXferClicked: NavCom.swapCom2()
                    }
                }

                Loader {
                    active: NavCom.com3Avail

                    sourceComponent: RadioRow {
                        name: "COM3"
                        activeFreq: NavCom.com3Freq.toFixed(3)
                        standbyFreq: NavCom.com3StbyFreq.toFixed(3)

                        onFrequencyClicked: root.radioClicked("COM3 Standby",
                                                              118,
                                                              136.99,
                                                              NavCom.com3Freq,
                                                              NavCom.com3StbyFreq,
                                                              NavCom.setCom3Freq,
                                                              3)
                        onXferClicked: NavCom.swapCom3()
                    }
                }

                Loader {
                    active: NavCom.nav1Avail

                    sourceComponent: RadioRow {
                        name: "NAV1"
                        activeFreq: NavCom.nav1Freq.toFixed(2)
                        standbyFreq: NavCom.nav1StbyFreq.toFixed(2)

                        onFrequencyClicked: root.radioClicked("NAV1",
                                                              108,
                                                              117.95,
                                                              NavCom.nav1Freq,
                                                              NavCom.nav1StbyFreq,
                                                              NavCom.setNav1Freq,
                                                              2)
                        onXferClicked: NavCom.swapNav1()
                    }
                }

                Loader {
                    active: NavCom.nav2Avail

                    sourceComponent: RadioRow {
                        name: "NAV2"
                        activeFreq: NavCom.nav2Freq.toFixed(2)
                        standbyFreq: NavCom.nav2Freq.toFixed(2)

                        onFrequencyClicked: root.radioClicked("NAV2",
                                                              108,
                                                              117.95,
                                                              NavCom.nav2Freq,
                                                              NavCom.nav2StbyFreq,
                                                              NavCom.setNav2Freq,
                                                              2)
                        onXferClicked: NavCom.swapNav2()
                    }
                }

                Loader {
                    active: NavCom.xpdrAvail

                    sourceComponent: TransponderRow {
                        onXpndrClicked: root.xpndrClicked()
                    }
                }
            }

        }


    }


}
