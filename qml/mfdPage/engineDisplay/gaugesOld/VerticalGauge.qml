import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQml 2.15

Item {
    id: main

    //position and size
    property real heightVal: 120
    property real centerX: 210
    property real yTop: 210


    //styling options
    property int valuePos: 1 // 1: bottom, 2: attached to cursor


    property real minValue: 0
    property real maxValue: 100

    //data used in displaying values (cursor angle, text, etc.)
    property string title: ""
    property string unit: ""
    property real cursorTransformValue: 0
    property string textValue: "0"
    property color textColor: "white"
    property bool redBlink: false

    function initModels(gaugeBackend) {
        fillColorModel(gaugeBackend);
        fillGradModel(gaugeBackend);
        fillTextGradModel(gaugeBackend);
    }

    function fillColorModel(gaugeBackend) {
        colorModel.clear();
        for (let i = 0; i < gaugeBackend.numColorZones(); i++) {
            colorModel.append({ "colorStart": gaugeBackend.colorZoneStartAt(i), "colorEnd": gaugeBackend.colorZoneEndAt(i), "colorVal": gaugeBackend.colorZoneColorAt(i).toString() });
        }
    }

    function fillGradModel(gaugeBackend) {
        gradModel.clear()
        for (let i = 0; i < gaugeBackend.numGrads(); i++) {
            gradModel.append({ "gradVal": gaugeBackend.gradValAt(i), "isBig": gaugeBackend.gradIsBigAt(i), "gradColor": gaugeBackend.gradColorAt(i).toString() });
        }
    }

    function fillTextGradModel(gaugeBackend) {
        textGradModel.clear();
        for (let i = 0; i < gaugeBackend.numTextGrads(); i++) {
            textGradModel.append({ "textGradVal": gaugeBackend.textGradValAt(i), "gradText": gaugeBackend.gradTextAt(i) });
        }
    }

    ListModel {
        id: colorModel
    }

    ListModel {
        id: gradModel
    }

    ListModel {
        id: textGradModel
    }

    Item {
        id: colorParent

        Repeater {
            model: colorModel
            delegate: Rectangle {
                width: 6
                height: (colorEnd- colorStart) / (main.maxValue - main.minValue) * main.heightVal
                x: main.centerX + 9
                y: (main.maxValue - colorEnd) / (main.maxValue - main.minValue) * main.heightVal + main.yTop
                color: colorVal
            }
        }
    }

    Item {
        id: gradParent

        Repeater {
            model: gradModel
            delegate: Rectangle {
                width: isBig ? 15 : 11
                height: isBig ? 2 : 1.5
                x: isBig ? main.centerX : main.centerX + 4
                y: (main.maxValue - gradVal) / (main.maxValue - main.minValue) * main.heightVal + main.yTop - (isBig ? 1 : 0.75)
                color: gradColor
            }
        }
    }

    Item {
        id: textGradParent
        visible: main.valuePos == 1
        enabled: main.valuePos == 1

        Repeater {
            model: textGradModel
            delegate: Text {
                anchors.right: parent.left
                anchors.rightMargin: 3 - main.centerX
                anchors.verticalCenter: parent.top
                anchors.verticalCenterOffset: (main.maxValue - textGradVal) / (main.maxValue - main.minValue) * main.heightVal + main.yTop
                color: "white"
                font.pixelSize: 15
                font.family: "Roboto Mono"
                font.bold: true
                text: gradText
            }
        }
    }

    Rectangle {
        id: rightBar
        x: main.centerX + 15
        y: main.yTop - 3
        width: 3
        height: main.heightVal + 6
        color: "white"
    }

    Rectangle {
        id: beginBar
        x: main.centerX
        y: main.yTop + main.heightVal
        width: 18
        height: 3
        color: "white"
    }

    Rectangle {
        id: endBar
        x: main.centerX
        y: main.yTop - 3
        width: 18
        height: 3
        color: "white"
    }

    Shape {
        id: cursorParent
        transform: Translate { y: main.cursorTransformValue }

        ShapePath {
            fillColor: "white"
            strokeColor: "transparent"
            PathMove {
                x: main.centerX + 15
                y: main.yTop + main.heightVal
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

        Text {//valueText when attached to cursor
            anchors.right: parent.left
            anchors.rightMargin: 3 - main.centerX
            anchors.verticalCenter: parent.top
            anchors.verticalCenterOffset: main.yTop + main.heightVal
            color: main.textColor
            font.pixelSize: 15
            font.family: "Roboto Mono"
            font.bold: true
            text: main.textValue
            visible: main.valuePos == 2
            enabled: main.valuePos == 2
        }
    }

    Rectangle {
        id: titleText_alertbg
        visible: main.redBlink
        x: titleText.x - 1.5
        y: titleText.y + 1.5
        width: titleText.width + 3
        height: titleText.height - 0.75

        SequentialAnimation on color {
            alwaysRunToEnd: false
            loops: Animation.Infinite
            running: main.redBlink
            PropertyAction { value: "white" }
            PauseAnimation { duration: 500 }
            PropertyAction { value: "red" }
            PauseAnimation { duration: 500 }
        }
    }

    Rectangle {
        id: unitText_alertbg
        visible: main.redBlink
        x: unitText.x - 1.5
        y: unitText.y + 1.5
        width: unitText.width + 3
        height: unitText.height - 0.75

        SequentialAnimation on color {
            alwaysRunToEnd: false
            loops: Animation.Infinite
            running: main.redBlink
            PropertyAction { value: "white" }
            PauseAnimation { duration: 500 }
            PropertyAction { value: "red" }
            PauseAnimation { duration: 500 }
        }
    }

    Rectangle {
        id: valueText_alertbg
        visible: main.redBlink && main.valuePos == 1
        enabled: main.valuePos == 1
        x: valueText.x - 1.5
        y: valueText.y + 1.5
        width: valueText.width + 3
        height: valueText.height

        SequentialAnimation on color {
            alwaysRunToEnd: false
            loops: Animation.Infinite
            running: main.redBlink
            PropertyAction { value: "white" }
            PauseAnimation { duration: 500 }
            PropertyAction { value: "red" }
            PauseAnimation { duration: 500 }
        }
    }



    Text {
        id: titleText
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: main.centerX
        anchors.baseline: parent.top
        anchors.baselineOffset: main.yTop - 28.5
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: 18
        text: main.title
        color: "white"

        SequentialAnimation on color {
            alwaysRunToEnd: false
            loops: Animation.Infinite
            running: main.redBlink
            PropertyAction { value: "red" }
            PauseAnimation { duration: 500 }
            PropertyAction { value: "white" }
            PauseAnimation { duration: 500 }
            onStopped: titleText.color = "white"
        }
    }

    Text {
        id: unitText
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: main.centerX
        anchors.baseline: parent.top
        anchors.baselineOffset: main.yTop - 9
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: 18
        text: main.unit
        color: "white"

        SequentialAnimation on color {
            alwaysRunToEnd: false
            loops: Animation.Infinite
            running: main.redBlink
            PropertyAction { value: "red" }
            PauseAnimation { duration: 500 }
            PropertyAction { value: "white" }
            PauseAnimation { duration: 500 }
            onStopped: unitText.color = "white"
        }
    }

    Text {//used when not attached to cursor
        id: valueText
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: main.centerX
        anchors.baseline: parent.top
        anchors.baselineOffset: main.yTop + main.heightVal + 22.5
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: 18
        text: main.textValue
        color: "white"
        visible: main.valuePos == 1
        enabled: main.valuePos == 1

        SequentialAnimation on color {
            alwaysRunToEnd: false
            loops: Animation.Infinite
            running: main.redBlink
            PropertyAction { value: "red" }
            PauseAnimation { duration: 500 }
            PropertyAction { value: "white" }
            PauseAnimation { duration: 500 }
        }

        Binding on color {
            when: !main.redBlink
            target: valueText
            value: main.textColor
            restoreMode: Binding.RestoreBindingOrValue
        }
    }









}
