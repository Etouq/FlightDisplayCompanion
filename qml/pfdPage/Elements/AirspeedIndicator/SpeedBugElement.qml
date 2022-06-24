import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQml 2.15
import Pfd.Airspeed 1.0
import Tsc.SpeedBugs 1.0

Item {

    ListModel {
        id: speedBugModel
    }

    Repeater {
        model: speedBugModel

        delegate: Shape {
            id: spdBug


            required property int bugSpeed
            required property string bugDesignator

            x: 192
            y: bugSpeed * -9.6

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
                text: spdBug.bugDesignator
            }
        }
    }

    Connections {
        target: SpeedBugs
        function onActiveSpeedBugsChanged()
        {
            speedBugModel.clear()

            for (const bugIdx of SpeedBugs.getActiveIds()) {
                speedBugModel.append({
                    "bugSpeed": SpeedBugs.speed(bugIdx),
                    "bugDesignator": SpeedBugs.designator(bugIdx)
                })
            }
        }
    }

    Component.onCompleted: function() {
        speedBugModel.clear()

        for (const bugIdx of SpeedBugs.getActiveIds()) {
            speedBugModel.append({
                "bugSpeed": SpeedBugs.speed(bugIdx),
                "bugDesignator": SpeedBugs.designator(bugIdx)
            })
        }
    }

}
