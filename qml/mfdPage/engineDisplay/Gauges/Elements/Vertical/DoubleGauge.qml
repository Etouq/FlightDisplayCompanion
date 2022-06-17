import QtQuick 2.15
import QtQuick.Shapes 1.15
import Mfd.Engine 1.0
import "../"

Item {
    id: gauge

    x: gauge.centerX - gauge.centerWidth / 2 - 24
    y: gauge.yTop
    width: gauge.centerWidth + 48
    height: gauge.gaugeData.getLength()

    //position and size
    required property real centerX
    required property real yTop

    readonly property real heightMult: gauge.gaugeData.getLength() / gauge.gaugeData.getRange()

    property alias title: titleText.text
    property alias unit: unitText.text

    property real minCenterWidth: 42

    readonly property real centerWidth: Math.max(gauge.minCenterWidth, gauge.gaugeData.unitWidth() + 10, gauge.gaugeData.maxTextGradWidth() + 6)

    required property GaugeData gaugeData
    readonly property GaugeEngine engine1: gauge.gaugeData.engine1()
    readonly property GaugeEngine engine2: gauge.gaugeData.engine2()


    // colorzones
    Repeater {
        model: gauge.gaugeData.numColorZones()
        delegate: Rectangle {
            required property int index

            anchors.horizontalCenter: parent.horizontalCenter
            y: (gauge.gaugeData.getMaxValue() - gauge.gaugeData.colorZoneEndAt(index)) * gauge.heightMult
            width: gauge.centerWidth + 18
            height: gauge.gaugeData.colorZoneRangeAt(index) * gauge.heightMult
            color: gauge.gaugeData.colorZoneColorAt(index)
        }
    }

    // grads
    Repeater {
        model: gauge.gaugeData.numGrads()
        delegate: Rectangle {
            required property int index

            anchors.horizontalCenter: parent.horizontalCenter

            color: gauge.gaugeData.gradColorAt(index)

            Component.onCompleted: function () {
                if (gauge.gaugeData.gradIsBigAt(index)) {
                    width = 30 + gauge.centerWidth;
                    height = 2;
                } else {
                    width = 21 + gauge.centerWidth
                    height = 1.5;
                }

                y = (gauge.gaugeData.getMaxValue() - gauge.gaugeData.gradValAt(index)) * gauge.heightMult - height / 2;
            }
        }
    }

    Rectangle {
        id: beginBar
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.bottom
        width: gauge.centerWidth + 33
        height: 3
        color: "white"
    }

    Rectangle {
        id: endBar
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.top
        height: 3
        width: gauge.centerWidth + 33
        color: "white"
    }

    Rectangle {
        id: gradTextBackground
        anchors.horizontalCenter: parent.horizontalCenter
        y: -10.5
        width: gauge.centerWidth
        height: gauge.height + 21
        color: "#1a1d21"
    }

    // grad text
    Repeater {
        model: gauge.gaugeData.numTextGrads()
        delegate: Text {
            required property int index

            anchors {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.top
            }

            anchors.verticalCenterOffset: (gauge.gaugeData.getMaxValue() - gauge.gaugeData.textGradValAt(index)) * gauge.heightMult

            color: "white"

            font {
                family: "Roboto Mono"
                bold: true
                pixelSize: 15
            }

            text: gauge.gaugeData.gradTextAt(index)
        }
    }

    Rectangle {
        id: barLeft
        anchors.right: gradTextBackground.left
        y: -3
        width: 3
        height: gauge.height + 6
        color: "white"
    }

    Rectangle {
        id: barRight
        anchors.left: gradTextBackground.right
        y: -3
        width: 3
        height: gauge.height + 6
        color: "white"
    }


    Shape {
        id: cursors

        anchors.fill: parent
        anchors.bottomMargin: -7.5

        clip: true

        ShapePath {
            id: leftCursor
            fillColor: "white"
            strokeColor: "transparent"

            startY: gauge.engine1.transformValue

            PathMove {
                x: 15
                relativeY: gauge.height
            }
            PathLine {
                relativeX: -15
                relativeY: 0
            }
            PathLine {
                relativeX: 0
                relativeY: gauge.height + 15
            }
            PathLine {
                relativeX: 7.5
                relativeY: 0
            }
            PathLine {
                relativeX: 0
                relativeY: -gauge.height
            }
        }

        ShapePath {
            id: rightCursor
            fillColor: "white"
            strokeColor: "transparent"

            startY: gauge.engine2.transformValue

            PathMove {
                x: cursors.width - 15
                relativeY: gauge.height
            }
            PathLine {
                relativeX: 15
                relativeY: 0
            }
            PathLine {
                relativeX: 0
                relativeY: gauge.height + 15
            }
            PathLine {
                relativeX: -7.5
                relativeY: 0
            }
            PathLine {
                relativeX: 0
                relativeY: -gauge.height
            }
        }
    }

    Rectangle {
        id: leftValueAlertBg
        visible: false

        anchors {
            fill: leftValueText
            leftMargin: -1.5
            rightMargin: -1.5
            topMargin: 1.5
        }

    }

    Rectangle {
        id: rightValueAlertBg
        visible: false

        anchors {
            fill: rightValueText
            leftMargin: -1.5
            rightMargin: -1.5
            topMargin: 1.5
        }
    }

    Text {
        id: titleText

        anchors {
            horizontalCenter: parent.horizontalCenter
            baseline: parent.top

            baselineOffset: -29.5
        }

        font {
            family: "Roboto Mono"
            bold: true
            pixelSize: 18
        }

        color: "white"
    }

    Text {
        id: unitText

        anchors {
            horizontalCenter: parent.horizontalCenter
            baseline: parent.top

            baselineOffset: -12
        }

        font {
            family: "Roboto Mono"
            bold: true
            pixelSize: 16
        }

        color: "white"
    }

    Text {
        id: leftValueText
        anchors.right: barLeft.horizontalCenter
        anchors.baseline: parent.top
        anchors.baselineOffset: -10

        font {
            family: "Roboto Mono"
            bold: true
            pixelSize: 18
        }

        text: gauge.engine1.value
        color: gauge.engine1.color
    }

    Text {
        id: rightValueText
        anchors.left: barRight.horizontalCenter
        anchors.baseline: parent.top
        anchors.baselineOffset: -10

        font {
            family: "Roboto Mono"
            bold: true
            pixelSize: 18
        }

        text: gauge.engine2.value
        color: gauge.engine2.color
    }

    ValueBlinkAnimation {
        textTarget: leftValueText
        rectTarget: leftValueAlertBg
        running: gauge.engine1.redBlink
        onStopped: function() {
            leftValueText.color = Qt.binding(function() { return gauge.engine1.color });
        }
    }

    ValueBlinkAnimation {
        textTarget: rightValueText
        rectTarget: rightValueAlertBg
        running: gauge.engine2.redBlink
        onStopped: function() {
            rightValueText.color = Qt.binding(function() { return gauge.engine2.color });
        }
    }

}
