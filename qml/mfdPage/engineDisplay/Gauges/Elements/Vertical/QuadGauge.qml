import QtQuick 2.15
import QtQuick.Shapes 1.15
import Mfd.Engine 1.0
import "../"

Item {
    id: gauge

    x: gauge.centerX - gauge.centerWidth / 2 - 48
    y: gauge.yTop
    width: gauge.centerWidth + 96
    height: gauge.gaugeData.getLength()

    //position and size
    required property real centerX
    required property real yTop

    readonly property real heightMult: gauge.gaugeData.getLength() / gauge.gaugeData.getRange()

    property alias title: titleText.text
    property alias unit: unitText.text

    property real minCenterWidth: 42

    readonly property real centerWidth: Math.max(gauge.minCenterWidth, 2 * gauge.gaugeData.valueMaxSize() + gauge.gaugeData.unitWidth() - 86, gauge.gaugeData.maxTextGradWidth() + 6)

    required property GaugeData gaugeData
    readonly property GaugeEngine engine1: gauge.gaugeData.engine1()
    readonly property GaugeEngine engine2: gauge.gaugeData.engine2()
    readonly property GaugeEngine engine3: gauge.gaugeData.engine3()
    readonly property GaugeEngine engine4: gauge.gaugeData.engine4()


    // colorzones
    Repeater {
        model: gauge.gaugeData.numColorZones()
        delegate: Item {
            required property int index

            y: (gauge.gaugeData.getMaxValue() - gauge.gaugeData.colorZoneEndAt(index)) * gauge.heightMult
            width: gauge.centerWidth + 96

            Rectangle {
                id: leftColorRect
                x: 0
                y: 0
                width: 9
            }

            Rectangle {
                id: midColorRect
                anchors.horizontalCenter: parent.horizontalCenter
                y: 0
                width: gauge.centerWidth + 18
            }

            Rectangle {
                id: rightColorRect
                anchors.right: parent.right
                y: 0
                width: 9
            }

            Component.onCompleted: function() {
                const height = gauge.gaugeData.colorZoneRangeAt(index) * gauge.heightMult;
                leftColorRect.height = height;
                midColorRect.height = height;
                rightColorRect.height = height;

                const zoneColor = gauge.gaugeData.colorZoneColorAt(index)
                leftColorRect.color = zoneColor
                midColorRect.color = zoneColor
                rightColorRect.color = zoneColor
            }
        }
    }

    // grads
    Repeater {
        model: gauge.gaugeData.numGrads()
        delegate: Item {
            required property int index

            width: gauge.centerWidth + 96

            Rectangle {
                id: leftGradRect
                x: 0
                y: 0
            }

            Rectangle {
                id: midGradRect
                anchors.horizontalCenter: parent.horizontalCenter
                y: 0
            }

            Rectangle {
                id: rightGradRect
                anchors.right: parent.right
                y: 0
            }

            Component.onCompleted: function() {

                if (gauge.gaugeData.gradIsBigAt(index)) {

                    //const yVal = (gauge.gaugeData.getMaxValue() - gauge.gaugeData.gradValAt(index)) * gauge.heightMult + gauge.yTop - 1;
                    y = (gauge.gaugeData.getMaxValue() - gauge.gaugeData.gradValAt(index)) * gauge.heightMult - 1;

                    leftGradRect.width = 15;
                    midGradRect.width = 30 + gauge.centerWidth;
                    rightGradRect.width = 15;

                    leftGradRect.height = 2;
                    midGradRect.height = 2;
                    rightGradRect.height = 2;
                }
                else {

                    //const yVal = (gauge.gaugeData.getMaxValue() - gauge.gaugeData.gradValAt(index)) * gauge.heightMult + gauge.yTop - 0.75;
                    y = (gauge.gaugeData.getMaxValue() - gauge.gaugeData.gradValAt(index)) * gauge.heightMult - 0.75;

                    leftGradRect.width = 10.5;
                    midGradRect.width = 21 + gauge.centerWidth;
                    rightGradRect.width = 10.5;

                    leftGradRect.height = 1.5;
                    midGradRect.height = 1.5;
                    rightGradRect.height = 1.5;
                }

                const gradColor = gauge.gaugeData.gradColorAt(index)
                leftGradRect.color = gradColor
                midGradRect.color = gradColor
                rightGradRect.color = gradColor

            }
        }
    }


    Rectangle {
        id: beginBarLeft
        x: 0
        anchors.top: parent.bottom
        width: 16.5
        height: 3
        color: "white"
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
        id: beginBarRight
        anchors.right: parent.right
        anchors.top: parent.bottom
        width: 16.5
        height: 3
        color: "white"
    }

    Rectangle {
        id: endBarLeft
        x: 0
        anchors.bottom: parent.top
        width: 16.5
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
        id: endBarRight
        anchors.right: parent.right
        anchors.bottom: parent.top
        width: 16.5
        height: 3
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
        x: 0
        y: -3
        width: 3
        height: gauge.height + 6
        color: "white"
    }

    Rectangle {
        id: barLeftMid
        anchors.right: gradTextBackground.left
        y: -3
        width: 3
        height: gauge.height + 6
        color: "white"
    }

    Rectangle {
        id: barRightMid
        anchors.left: gradTextBackground.right
        y: -3
        width: 3
        height: gauge.height + 6
        color: "white"
    }

    Rectangle {
        id: barRight
        anchors.right: parent.right
        y: -3
        width: 3
        height: gauge.height + 6
        color: "white"
    }

    Shape {
        id: cursors

        anchors.fill: parent
        anchors.leftMargin: 9
        anchors.rightMargin: 9
        anchors.bottomMargin: -7.5

        clip: true

        ShapePath {
            id: cursorLeft
            fillColor: "white"
            strokeColor: "transparent"

            startY: gauge.engine1.transformValue

            PathMove {
                x: 0
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

        ShapePath {
            id: cursorLeftMid
            fillColor: "white"
            strokeColor: "transparent"

            startY: gauge.engine2.transformValue

            PathMove {
                x: 30
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
            id: cursorRightMid
            fillColor: "white"
            strokeColor: "transparent"

            startY: gauge.engine3.transformValue

            PathMove {
                x: cursors.width - 30
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

        ShapePath {
            id: cursorRight
            fillColor: "white"
            strokeColor: "transparent"

            startY: gauge.engine4.transformValue

            PathMove {
                x: cursors.width
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
        id: leftMidValueAlertBg
        visible: false
        anchors {
            fill: leftMidValueText
            leftMargin: -1.5
            rightMargin: -1.5
            topMargin: 1.5
        }
    }

    Rectangle {
        id: rightMidValueAlertBg
        visible: false
        anchors {
            fill: rightMidValueText
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

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.baseline: parent.top
        anchors.baselineOffset: -29.5

        font {
            family: "Roboto Mono"
            bold: true
            pixelSize: 18
        }

        color: "white"
    }


    Text {
        id: unitText

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.baseline: parent.top
        anchors.baselineOffset: -12

        font {
            family: "Roboto Mono"
            bold: true
            pixelSize: 16
        }

        color: "white"
    }

    Text {
        id: leftValueText

        anchors.left: barLeft.horizontalCenter
        anchors.baseline: parent.top
        anchors.baselineOffset: -10

        font {
            family: "Roboto Mono"
            bold: true
            pixelSize: 18
        }

        color: gauge.engine1.color
        text: gauge.engine1.value
    }

    Text {
        id: leftMidValueText
        anchors.right: barLeftMid.horizontalCenter
        anchors.top: cursors.bottom

        font {
            family: "Roboto Mono"
            bold: true
            pixelSize: 18
        }

        color: gauge.engine2.color
        text: gauge.engine2.value
    }

    Text {
        id: rightMidValueText
        anchors.left: barRightMid.horizontalCenter
        anchors.top: cursors.bottom

        font {
            family: "Roboto Mono"
            bold: true
            pixelSize: 18
        }

        color: gauge.engine3.color
        text: gauge.engine3.value
    }

    Text {
        id: rightValueText
        anchors.right: barRight.horizontalCenter
        anchors.baseline: parent.top
        anchors.baselineOffset: -10

        font {
            family: "Roboto Mono"
            bold: true
            pixelSize: 18
        }

        color: gauge.engine4.color
        text: gauge.engine4.value
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
        textTarget: leftMidValueText
        rectTarget: leftMidValueAlertBg
        running: gauge.engine2.redBlink
        onStopped: function() {
            leftMidValueText.color = Qt.binding(function() { return gauge.engine2.color });
        }
    }

    ValueBlinkAnimation {
        textTarget: rightMidValueText
        rectTarget: rightMidValueAlertBg
        running: gauge.engine3.redBlink
        onStopped: function() {
            rightMidValueText.color = Qt.binding(function() { return gauge.engine3.color });
        }
    }

    ValueBlinkAnimation {
        textTarget: rightValueText
        rectTarget: rightValueAlertBg
        running: gauge.engine4.redBlink
        onStopped: function() {
            rightValueText.color = Qt.binding(function() { return gauge.engine4.color });
        }
    }
}
