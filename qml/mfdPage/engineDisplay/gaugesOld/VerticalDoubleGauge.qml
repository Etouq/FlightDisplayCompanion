import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQml 2.15

Item {
    id: main

    clip: true

    width: extraWide ? 165 : 150
    x: centerX - internalCenterX
    y: yTop - 45
    height: heightVal + 52.5


    property real heightVal: 120
    property real centerX: 210
    property real yTop: 210

    property bool extraWide: false
    
    property real internalCenterX: extraWide ? 82.5 : 75;
    property real internalyTop: 45

    property real minValue: 0
    property real maxValue: 100

    property alias title: titleText.text
    property alias unit: unitText.text

    property alias leftCursorTransformValue: leftCursorTranslation.y
    property alias leftTextValue: leftValueText.text
    property color leftTextColor: "white"
    property bool leftRedBlink: false

    property alias rightCursorTransformValue: rightCursorTranslation.y
    property alias rightTextValue: rightValueText.text
    property color rightTextColor: "white"
    property bool rightRedBlink: false


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
            textGradModel.append({ "textGradVal": gaugeBackend.textGradValAt(i), "gradText": gaugeBackend.gradTextAt(i).toString() });
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
                width: main.extraWide ? 75 : 60
                height: (colorEnd- colorStart) / (main.maxValue - main.minValue) * main.heightVal
                x: main.internalCenterX - (main.extraWide ? 37.5 : 30)
                y: (main.maxValue - colorEnd) / (main.maxValue - main.minValue) * main.heightVal + main.internalyTop
                color: colorVal
            }
        }
    }

    Item {
        id: gradParent

        Repeater {
            model: gradModel
            delegate: Rectangle {
                width: 63 + (main.extraWide ? 15 : 0) + (isBig ? 9 : 0)
                height: isBig ? 2 : 1.5
                x: main.internalCenterX - 31.5 - (main.extraWide ? 7.5 : 0) - (isBig ? 4.5 : 0)
                y: (main.maxValue - gradVal) / (main.maxValue - main.minValue) * main.heightVal + main.internalyTop - (isBig ? 1 : 0.75)
                color: gradColor
            }
        }
    }

    Rectangle {
        id: beginBar
        color: "white"
        width: main.extraWide ? 90 : 75
        x: main.internalCenterX - (main.extraWide ? 45 : 37.5)
        y: main.internalyTop + main.heightVal
        height: 3
    }

    Rectangle {
        id: endBar
        color: "white"
        width: main.extraWide ? 90 : 75
        x: main.internalCenterX - (main.extraWide ? 45 : 37.5)
        y: main.internalyTop - 3
        height: 3
    }

    Rectangle {
        id: gradTextBackground
        color: "#1a1d21"
        width: main.extraWide ? 57 : 42
        x: main.internalCenterX - (main.extraWide ? 28.5 : 21)
        y: main.internalyTop - 10.5
        height: main.heightVal + 21

    }

    Item {
        id: textGradParent

        Repeater {
            model: textGradModel
            delegate: Text {
                anchors.horizontalCenter: parent.left
                anchors.horizontalCenterOffset: main.internalCenterX
                anchors.verticalCenter: parent.top
                anchors.verticalCenterOffset: (main.maxValue - textGradVal) / (main.maxValue - main.minValue) * main.heightVal + main.internalyTop
                color: "white"
                font.pixelSize: 15
                font.family: "Roboto Mono"
                font.bold: true
                text: gradText
            }
        }
    }

    Rectangle {
        id: barLeft
        color: "white"
        width: 3
        x: main.internalCenterX - (extraWide ? 31.5 : 24)
        y: main.internalyTop - 3
        height: main.heightVal + 6
    }

    Rectangle {
        id: barRight
        color: "white"
        width: 3
        x: main.internalCenterX + (extraWide ? 28.5 : 21)
        y: main.internalyTop - 3
        height: main.heightVal + 6
    }

    Shape {
        id: leftCursor
        transform: Translate { id: leftCursorTranslation }

        ShapePath {
            fillColor: "white"
            strokeColor: "transparent"

            PathMove {
                x: main.internalCenterX - (extraWide ? 37.5 : 30)
                y: main.internalyTop + main.heightVal
            }
            PathLine {
                relativeX: -15
                relativeY: 0
            }
            PathLine {
                relativeX: 0
                relativeY: main.heightVal + 15
            }
            PathLine {
                relativeX: 7.5
                relativeY: 0
            }
            PathLine {
                relativeX: 0
                relativeY: -main.heightVal
            }
        }
    }

    Shape {
        id: rightCursor
        transform: Translate { id: rightCursorTranslation }

        ShapePath {
            fillColor: "white"
            strokeColor: "transparent"

            PathMove {
                x: main.internalCenterX + (extraWide ? 37.5 : 30)
                y: main.internalyTop + main.heightVal
            }
            PathLine {
                relativeX: 15
                relativeY: 0
            }
            PathLine {
                relativeX: 0
                relativeY: main.heightVal + 15
            }
            PathLine {
                relativeX: -7.5
                relativeY: 0
            }
            PathLine {
                relativeX: 0
                relativeY: -main.heightVal
            }
        }
    }

    Rectangle {
        id: leftValueText_alertbg
        visible: main.leftRedBlink
        x: leftValueText.x - 1.5
        y: leftValueText.y + 1.5
        width: leftValueText.width + 3
        height: leftValueText.height

        SequentialAnimation on color {
            alwaysRunToEnd: false
            loops: Animation.Infinite
            running: main.leftRedBlink
            PropertyAction { value: "white" }
            PauseAnimation { duration: 500 }
            PropertyAction { value: "red" }
            PauseAnimation { duration: 500 }
        }
    }

    Rectangle {
        id: rightValueText_alertbg
        visible: main.rightRedBlink
        x: rightValueText.x - 1.5
        y: rightValueText.y + 1.5
        width: rightValueText.width + 3
        height: rightValueText.height

        SequentialAnimation on color {
            alwaysRunToEnd: false
            loops: Animation.Infinite
            running: main.rightRedBlink
            PropertyAction { value: "white" }
            PauseAnimation { duration: 500 }
            PropertyAction { value: "red" }
            PauseAnimation { duration: 500 }
        }
    }

    Text {
        id: titleText
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: main.internalCenterX
        anchors.baseline: parent.top
        anchors.baselineOffset: main.internalyTop - 29.5
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        //text: main.title
    }

    Text {
        id: unitText
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: main.internalCenterX
        anchors.baseline: parent.top
        anchors.baselineOffset: main.internalyTop - 10
        color: "white"
        font.pixelSize: 18
        font.family: "Roboto Mono"
        font.bold: true
        //text: main.unit
    }

    Text {
        id: leftValueText
        anchors.right: parent.left
        anchors.rightMargin: Math.max(22.5, unitText.width / 2 + 5) - main.internalCenterX
        anchors.baseline: parent.top
        anchors.baselineOffset: main.internalyTop - 10
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: 18
        //text: main.leftTextValue
        color: "white"

        SequentialAnimation on color {
            alwaysRunToEnd: false
            loops: Animation.Infinite
            running: main.leftRedBlink
            PropertyAction { value: "red" }
            PauseAnimation { duration: 500 }
            PropertyAction { value: "white" }
            PauseAnimation { duration: 500 }
        }

        Binding on color {
            when: !main.leftRedBlink
            target: leftValueText
            value: main.leftTextColor
            restoreMode: Binding.RestoreBindingOrValue
        }
    }

    Text {
        id: rightValueText
        anchors.left: parent.left
        anchors.leftMargin: main.internalCenterX + Math.max(22.5, unitText.width / 2 + 5)
        anchors.baseline: parent.top
        anchors.baselineOffset: main.internalyTop - 10
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: 18
        //text: main.rightTextValue
        color: "white"

        SequentialAnimation on color {
            alwaysRunToEnd: false
            loops: Animation.Infinite
            running: main.rightRedBlink
            PropertyAction { value: "red" }
            PauseAnimation { duration: 500 }
            PropertyAction { value: "white" }
            PauseAnimation { duration: 500 }
        }

        Binding on color {
            when: !main.rightRedBlink
            target: rightValueText
            value: main.rightTextColor
            restoreMode: Binding.RestoreBindingOrValue
        }
    }



}
