import QtQuick 2.15
import QtQuick.Shapes 1.15

import Tsc.SpeedBugs 1.0

import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"

Row {
    id: speedBugRow

    required property int bugIndex
    readonly property SpeedBugEntry speedBugEntry: SpeedBugs.speedBugAt(speedBugRow.bugIndex)

    signal speedClicked()
    signal removeClicked()

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
                text: "V" + speedBugRow.speedBugEntry.designator()
            }

            GradientStatusBar {
                active: speedBugRow.speedBugEntry.active
            }

            onReleased: SpeedBugs.toggleActive(speedBugRow.bugIndex)
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

            Text {
                width: parent.width
                anchors.top: parent.top
                anchors.topMargin: 42
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 60
                font.family: "Roboto Mono"
                font.bold: true
                color: "aqua"
                text: speedBugRow.speedBugEntry.speed + "KT"
            }

            onReleased: speedBugRow.speedClicked()
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
                    id: crossSign
                    strokeColor: "black"
                    strokeWidth: 3
                    fillColor: "red"

                    readonly property real armLength: 69.08 / Math.sqrt(2)
                    readonly property real thickness: 10 / Math.sqrt(2)

                    startX: 94.08
                    startY: 94.08 - thickness / 2

                    PathLine {
                        relativeX: crossSign.armLength
                        relativeY: -crossSign.armLength
                    }
                    PathLine {
                        relativeX: crossSign.thickness
                        relativeY: crossSign.thickness
                    }
                    PathLine {
                        relativeX: -crossSign.armLength
                        relativeY: crossSign.armLength
                    }
                    PathLine {
                        relativeX: crossSign.armLength
                        relativeY: crossSign.armLength
                    }
                    PathLine {
                        relativeX: -crossSign.thickness
                        relativeY: crossSign.thickness
                    }
                    PathLine {
                        relativeX: -crossSign.armLength
                        relativeY: -crossSign.armLength
                    }
                    PathLine {
                        relativeX: -crossSign.armLength
                        relativeY: crossSign.armLength
                    }
                    PathLine {
                        relativeX: -crossSign.thickness
                        relativeY: -crossSign.thickness
                    }
                    PathLine {
                        relativeX: crossSign.armLength
                        relativeY: -crossSign.armLength
                    }
                    PathLine {
                        relativeX: -crossSign.armLength
                        relativeY: -crossSign.armLength
                    }
                    PathLine {
                        relativeX: crossSign.thickness
                        relativeY: -crossSign.thickness
                    }
                    PathLine {
                        relativeX: crossSign.armLength
                        relativeY: crossSign.armLength
                    }
                }
            }

            onReleased: SpeedBugs.removeSpeedBug(speedBugRow.bugIndex)
        }
    }
}

