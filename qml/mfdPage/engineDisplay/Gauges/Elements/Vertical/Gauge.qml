import QtQuick 2.15
import QtQuick.Shapes 1.15
import Mfd.Engine 1.0
import "../"

Item {
    id: gauge

    //position and size
    readonly property real heightVal: gauge.gaugeData.getLength()
    required property real centerX
    required property real yTop

    readonly property real heightMult: gauge.gaugeData.getLength() / gauge.gaugeData.getRange()

    // 0: bottom, 1: attached
    required property int valuePos

    //data used in displaying values (cursor angle, text, etc.)
    property string title: ""
    property string unit: ""

    required property GaugeData gaugeData
    required property GaugeEngine engine

    // colorzones
    Repeater {
        model: gauge.gaugeData.numColorZones()
        delegate: Rectangle {
            required property int index

            width: 6
            height: gauge.gaugeData.colorZoneRangeAt(index) * gauge.heightMult
            x: gauge.centerX + 9
            y: (gauge.gaugeData.getMaxValue() - gauge.gaugeData.colorZoneEndAt(
                    index)) * gauge.heightMult + gauge.yTop
            color: gauge.gaugeData.colorZoneColorAt(index)
        }
    }

    // grads
    Repeater {
        model: gauge.gaugeData.numGrads()
        delegate: Rectangle {
            required property int index

            color: gauge.gaugeData.gradColorAt(index)

            Component.onCompleted: function () {
                if (gauge.gaugeData.gradIsBigAt(index)) {
                    width = 15
                    height = 2
                    x = gauge.centerX
                } else {
                    width = 11
                    height = 1.5
                    x = gauge.centerX + 4
                }

                y = (gauge.gaugeData.getMaxValue() - gauge.gaugeData.gradValAt(
                         index)) * gauge.heightMult + gauge.yTop - height / 2
            }
        }
    }

    // grad text
    Repeater {
        // only enabled when we don't have an attached value
        model: gauge.valuePos !== 1 ? gauge.gaugeData.numTextGrads() : 0
        delegate: Text {
            required property int index

            anchors.right: parent.left
            anchors.rightMargin: 3 - gauge.centerX
            anchors.verticalCenter: parent.top
            anchors.verticalCenterOffset: (gauge.gaugeData.getMaxValue(
                                               ) - gauge.gaugeData.textGradValAt(
                                               index)) * gauge.heightMult + gauge.yTop
            color: "white"
            font.pixelSize: 15
            font.family: "Roboto Mono"
            font.bold: true
            text: gauge.gaugeData.gradTextAt(index)
        }
    }

    Rectangle {
        id: rightBar
        x: gauge.centerX + 15
        y: gauge.yTop - 3
        width: 3
        height: gauge.heightVal + 6
        color: "white"
    }

    Rectangle {
        id: beginBar
        x: gauge.centerX
        y: gauge.yTop + gauge.heightVal
        width: 18
        height: 3
        color: "white"
    }

    Rectangle {
        id: endBar
        x: gauge.centerX
        y: gauge.yTop - 3
        width: 18
        height: 3
        color: "white"
    }

    Shape {
        id: cursor
        transform: Translate {
            y: gauge.engine.transformValue
        }

        ShapePath {
            fillColor: "white"
            strokeColor: "transparent"
            PathMove {
                x: gauge.centerX + 15
                y: gauge.yTop + gauge.heightVal
            }
            PathLine {
                relativeX: -4.5
                relativeY: -4.5
            }
            PathLine {
                relativeX: -7.5
                relativeY: 0
            }
            PathLine {
                relativeX: 0
                relativeY: 9
            }
            PathLine {
                relativeX: 7.5
                relativeY: 0
            }
        }

        Loader {
            // only active when attached
            active: gauge.valuePos == 1
            asynchronous: true
            sourceComponent: Item {
                Rectangle {
                    id: attachedValueAlertBg

                    visible: false

                    anchors {
                        fill: attachedValueText

                        leftMargin: -1.5
                        topMargin: 1.5
                        rightMargin: -1.5
                    }
                }

                Text {
                    id: attachedValueText

                    anchors {
                        right: parent.left
                        verticalCenter: parent.top

                        rightMargin: 3 - gauge.centerX
                        verticalCenterOffset: gauge.yTop + gauge.heightVal
                    }

                    font {
                        family: "Roboto Mono"
                        bold: true
                        pixelSize: 15
                    }

                    text: gauge.engine.value
                    color: gauge.engine.color
                }

                ValueBlinkAnimation {
                    textTarget: attachedValueText
                    rectTarget: attachedValueAlertBg

                    running: gauge.engine.redBlink
                    onStopped: function () {
                        attachedValueText.color = Qt.binding(function () {
                            return gauge.engine.color
                        })
                    }
                }
            }
        }
    }

    Loader {
        id: titleLoader
        // only active when title is not empty
        active: gauge.title !== ""
        asynchronous: true

        sourceComponent: Item {
            Rectangle {
                id: titleAlertBg

                visible: false

                anchors {
                    fill: titleText

                    leftMargin: -1.5
                    topMargin: 1.5
                    rightMargin: -1.5
                }
            }
            Text {
                id: titleText

                anchors {
                    horizontalCenter: parent.left
                    baseline: parent.top

                    horizontalCenterOffset: gauge.centerX
                    baselineOffset: gauge.yTop - 28.5
                }

                font {
                    family: "Roboto Mono"
                    bold: true
                    pixelSize: 18
                }

                text: gauge.title
                color: "white"
            }

            ValueBlinkAnimation {
                textTarget: titleText
                rectTarget: titleAlertBg

                running: gauge.engine.redBlink
                onStopped: function () {
                    titleText.color = "white"
                }
            }
        }
    }

    Loader {
        // only active when unit is not empty
        active: gauge.unit !== ""
        asynchronous: true

        sourceComponent: Item {

            Rectangle {
                id: unitAlertBg

                visible: false

                anchors {
                    fill: unitText

                    leftMargin: -1.5
                    topMargin: 1.5
                    rightMargin: -1.5
                }
            }
            Text {
                id: unitText

                anchors {
                    horizontalCenter: parent.left
                    baseline: parent.top

                    horizontalCenterOffset: gauge.centerX
                    baselineOffset: gauge.yTop - 9
                }

                font {
                    family: "Roboto Mono"
                    bold: true
                    pixelSize: 18
                }

                text: gauge.unit
                color: "white"
            }

            ValueBlinkAnimation {
                textTarget: unitText
                rectTarget: unitAlertBg

                running: gauge.engine.redBlink
                onStopped: function () {
                    unitText.color = "white"
                }
            }
        }
    }

    Loader {
        // only active when bottom
        active: gauge.valuePos === 0
        asynchronous: true

        sourceComponent: Item {
            Rectangle {
                id: bottomValueAlertBg

                visible: false

                anchors {
                    fill: bottomValueText

                    leftMargin: -1.5
                    topMargin: 1.5
                    rightMargin: -1.5
                }
            }
            Text {
                id: bottomValueText

                anchors {
                    horizontalCenter: parent.left
                    baseline: parent.top

                    horizontalCenterOffset: gauge.centerX
                    baselineOffset: gauge.yTop + gauge.heightVal + 22.5
                }

                font {
                    family: "Roboto Mono"
                    bold: true
                    pixelSize: 18
                }

                text: gauge.engine.value
                color: gauge.engine.color
            }

            ValueBlinkAnimation {
                textTarget: bottomValueText
                rectTarget: bottomValueAlertBg

                running: gauge.engine.redBlink
                onStopped: function () {
                    bottomValueText.color = Qt.binding(function () {
                        return gauge.engine.color
                    })
                }
            }
        }
    }
}
