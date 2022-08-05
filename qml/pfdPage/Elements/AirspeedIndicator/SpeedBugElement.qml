import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQml 2.15
import Pfd.Airspeed 1.0
import Tsc.SpeedBugs 1.0

Item {

    Repeater {
        model: SpeedBugs.numActiveSpeedbugs

        delegate: Shape {
            id: spdBug


            required property int index
            readonly property SpeedBugEntry speedBugEntry: SpeedBugs.activeSpeedBugAt(spdBug.index)

            x: 192
            y: spdBug.speedBugEntry.speed * -9.6

            ShapePath {
                fillColor: "#1a1d21"
                strokeColor: "transparent"

                PathMove {
                    x: 0; y: 288
                }
                PathLine {
                    relativeX: 9.6; relativeY: 14.4
                }
                PathLine {
                    relativeX: 38.4; relativeY: 0
                }
                PathLine {
                    relativeX: 00; relativeY: -28.8
                }
                PathLine {
                    relativeX: -38.4; relativeY: 0
                }
            }
            Text {
                anchors.horizontalCenter: parent.left
                anchors.horizontalCenterOffset: 28.8
                anchors.verticalCenter: parent.top
                anchors.verticalCenterOffset: 288
                color: "aqua"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 24
                text: spdBug.speedBugEntry.designator()
            }
        }
    }

}
