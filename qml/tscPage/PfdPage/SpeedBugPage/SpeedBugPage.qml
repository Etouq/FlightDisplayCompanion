import QtQuick 2.15
import QtQuick.Layouts 1.12
import QtQml 2.15
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.15

import Tsc.SpeedBugs 1.0

import "../../"
import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"

TscPageBase {
    id: root

    showBackButton: true

    pageTitle: "Speed Bugs"

    signal valueClicked(SpeedBugEntry speedBugEntry)
    signal addSpeedbugClicked()

    Rectangle {
        anchors.right: parent.right
        anchors.rightMargin: 337.92
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 54
        width: 934.56
        height: 1017.6
        color: "white"

        ListView {
            id: bugList
            clip: true

            anchors.fill: parent
            anchors.margins: 9.6

            spacing: 2.4
            model: SpeedBugs.numSpeedbugs

            //headerPositioning: ListView.OverlayHeader

            ScrollBar.vertical: ScrollBar {
                parent: bugList.parent

                anchors {
                    top: bugList.top
                    left: bugList.right
                    bottom: bugList.bottom

                    topMargin: -9.6
                    leftMargin: 14.8
                    bottomMargin: -9.6
                }

                visible: SpeedBugs.numSpeedbugs > 4

                contentItem: Rectangle {
                    implicitWidth: 20
                    color: "white"
                }
            }

            delegate: SpeedBugsRow {
                id: bugRow

                required property int index

                bugIndex: index

                onSpeedClicked: root.valueClicked(bugRow.speedBugEntry)
            }

            header: Row {
                width: 915.36
                height: 197.76
                spacing: 2.4

                Rectangle {
                    width: 356.4
                    height: 197.76
                    color: "black"
                    border.color: "transparent"
                    border.width: 0

                    GradientButton {
                        anchors.centerIn: parent
                        width: 346.8
                        height: 188.16

                        MainText {
                            text: "All On"
                        }


                        //onReleased: activate all
                    }
                }

                Rectangle {
                    width: 356.4
                    height: 197.76
                    color: "black"
                    border.color: "transparent"
                    border.width: 0

                    GradientButton {
                        anchors.centerIn: parent
                        width: 346.8
                        height: 188.16

                        MainText {
                            text: "All Off"
                        }

                        //onReleased: deactivate all
                    }
                }

                Rectangle {
                    width: 197.76
                    height: 197.76
                    color: "black"
                    border.color: "transparent"
                    border.width: 0

                    GradientButton {
                        anchors.centerIn: parent
                        width: 188.16
                        height: 188.16

                        Shape {
                            anchors.fill: parent

                            ShapePath {
                                id: plusSign
                                strokeColor: "black"
                                strokeWidth: 3
                                fillColor: "green"

                                property real armLength: 53
                                property real thickness: 15

                                startX: 94.08 - thickness / 2
                                startY: 94.08 - thickness / 2

                                PathLine {
                                    relativeX: 0
                                    relativeY: -plusSign.armLength
                                }
                                PathLine {
                                    relativeX: plusSign.thickness
                                    relativeY: 0
                                }
                                PathLine {
                                    relativeX: 0
                                    relativeY: plusSign.armLength
                                }
                                PathLine {
                                    relativeX: plusSign.armLength
                                    relativeY: 0
                                }
                                PathLine {
                                    relativeX: 0
                                    relativeY: plusSign.thickness
                                }
                                PathLine {
                                    relativeX: -plusSign.armLength
                                    relativeY: 0
                                }
                                PathLine {
                                    relativeX: 0
                                    relativeY: plusSign.armLength
                                }
                                PathLine {
                                    relativeX: -plusSign.thickness
                                    relativeY: 0
                                }
                                PathLine {
                                    relativeX: 0
                                    relativeY: -plusSign.armLength
                                }
                                PathLine {
                                    relativeX: -plusSign.armLength
                                    relativeY: 0
                                }
                                PathLine {
                                    relativeX: 0
                                    relativeY: -plusSign.thickness
                                }
                                PathLine {
                                    relativeX: plusSign.armLength
                                    relativeY: 0
                                }
                            }
                        }

                        onReleased: root.addSpeedbugClicked()
                    }
                }
            }

        }
    }


    GradientButton {
        x: 86.4
        anchors.bottom: resetButton.top
        anchors.bottomMargin: 10
        width: 437.76
        enabled: false //aircraftInterface.aircraftLoaded

        MainText {
            text: "Set As Defaults"
        }

        onReleased: SpeedBugs.storeSpeedbugsAsDefaults()
    }

    GradientButton {
        id: resetButton
        x: 86.4
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 54
        width: 437.76

        MainText {
            text: "Restore All Defaults"
        }

        onReleased: SpeedBugs.restoreDefaults()
    }
}
