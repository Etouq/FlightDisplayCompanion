import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQml 2.15

Item {

    id: main

    //position and size
    property real startAngle: 195
    property real endAngle: 345
    property real radius: 120
    property real centerX: 210
    property real centerY: 210

    property int titleSize: 0
    property int unitSize: 0

    property int valueTextSize: 0

    //styling options
    property real arcWidth: 3
    property real colorZoneWidth: 6

    property real gradScaleFactor: 1
    property real cursorScaleFactor: gradScaleFactor


    property real minValue: 0
    property real maxValue: 100

    //data used in displaying values (cursor angle, text, etc.)
    property alias title: titleText.text
    property alias unit: unitText.text
    property alias cursorAngle: cursorTransform.angle
    property alias textValue: valueText.text
    property color textColor: "white"
    property bool redBlink: false



    function wrapAngle(_angle) {
        return (360 + (_angle % 360)) % 360;
    }

    function valueToAngle(_value) {
        return main.startAngle - (_value - main.minValue) / (main.maxValue - main.minValue) * wrapAngle(main.startAngle - main.endAngle);
    }

    function initModels(gaugeBackend) {
        drawColorZones(gaugeBackend);
        fillGradModel(gaugeBackend);
        fillTextGradModel(gaugeBackend);
    }


    function drawColorZones(gaugeBackend) {
        colorParent.data = [];

        for (let i = 0; i < gaugeBackend.numColorZones(); i++) {
            let colorStartAngle = valueToAngle(gaugeBackend.colorZoneStartAt(i));
            let colorEndAngle = valueToAngle(gaugeBackend.colorZoneEndAt(i));

            let zone = Qt.createQmlObject(
                            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath { ' +
                            'fillColor: "' + gaugeBackend.colorZoneColorAt(i) + '";' +
                            'strokeColor: "transparent";' +
                            'PathAngleArc { ' +
                            'centerX: ' + main.centerX + ';' +
                            'centerY: ' + main.centerY + ';' +
                            'radiusX: ' + (main.radius - main.arcWidth / 2 - 1.5) + ';' +
                            'radiusY: ' + (main.radius - main.arcWidth / 2 - 1.5) + ';' +
                            'startAngle: ' + -colorStartAngle + ';' +
                            'sweepAngle: ' + (colorStartAngle - colorEndAngle) + ' }' +
                            'PathAngleArc { ' +
                            'centerX: ' + main.centerX + ';' +
                            'centerY: ' + main.centerY + ';' +
                            'radiusX: ' + (main.radius - main.arcWidth / 2 - 1.5 - main.colorZoneWidth) + ';' +
                            'radiusY: ' + (main.radius - main.arcWidth / 2 - 1.5 - main.colorZoneWidth) + ';' +
                            'startAngle: ' + -colorEndAngle + ';' +
                            'sweepAngle: ' + (colorEndAngle - colorStartAngle) + ';' +
                            'moveToStart: false } }',
                            colorParent);
            colorParent.data.push(zone);
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
        id: gradModel
    }

    ListModel {
        id: textGradModel
    }


    Shape {
        id: colorParent
    }

    Item {
        id: gradParent

        Repeater {
            model: gradModel
            delegate: Rectangle {
                width: main.gradScaleFactor * (isBig ? 13.5 : 9)
                height: main.gradScaleFactor * (isBig ? 2.1 : 1.5)
                x: main.centerX + main.radius - main.gradScaleFactor * (isBig ? 13.5 : 9)
                y: main.centerY - main.gradScaleFactor * (isBig ? 1.05 : 0.75)
                color: gradColor
                transform: Rotation {
                    angle: -valueToAngle(gradVal)
                    origin.x: main.gradScaleFactor * (isBig ? 13.5 : 9) - main.radius
                    origin.y: main.gradScaleFactor * (isBig ? 1.05 : 0.75)
                }
            }
        }
    }

    Item {
        id: textGradParent

        Repeater {
            model: textGradModel
            delegate: Text {
                anchors.horizontalCenter: parent.left
                anchors.horizontalCenterOffset: main.centerX + (main.radius + main.arcWidth / 2 - main.gradScaleFactor * 9 - 10) * 0.85 * Math.cos(valueToAngle(textGradVal) * Math.PI / 180)
                anchors.verticalCenter: parent.top
                anchors.verticalCenterOffset: main.centerY - (main.radius + main.arcWidth / 2 - main.gradScaleFactor * 9 - 8) * 0.9 * Math.sin(valueToAngle(textGradVal) * Math.PI / 180)
                color: "white"
                font.pixelSize: 13
                font.family: "Roboto Mono"
                font.bold: true
                text: gradText
            }
        }
    }

    Shape {
        id: mainArc
        ShapePath {
            fillColor: "transparent"
            strokeColor: "white"
            strokeWidth: main.arcWidth

            PathAngleArc {
                centerX: main.centerX
                centerY: main.centerY
                radiusX: main.radius
                radiusY: main.radius
                startAngle: -main.startAngle
                sweepAngle: wrapAngle(main.startAngle - main.endAngle)
            }
        }
    }

    Rectangle {
        id: beginLimit
        width: 15 * main.gradScaleFactor
        height: 3 * main.gradScaleFactor
        x: main.centerX + main.radius - 15 * main.gradScaleFactor
        y: main.centerY - (3 * main.gradScaleFactor) / 2
        color: "white"

        transform: Rotation {
            angle: -main.startAngle
            origin.x: 15 * main.gradScaleFactor - main.radius
            origin.y: (3 * main.gradScaleFactor) / 2
        }
    }

    Rectangle {
        id: endLimit
        width: 15 * main.gradScaleFactor
        height: 3 * main.gradScaleFactor
        x: main.centerX + main.radius - 15 * main.gradScaleFactor
        y: main.centerY - (3 * main.gradScaleFactor) / 2
        color: "white"

        transform: Rotation {
            angle: -main.endAngle
            origin.x: 15 * main.gradScaleFactor - main.radius
            origin.y: (3 * main.gradScaleFactor) / 2
        }
    }

    Shape {
        id: cursor
        transform: Rotation {
            id: cursorTransform
            //angle: main.cursorAngle
            origin.x: main.centerX
            origin.y: main.centerY
        }
        ShapePath {
            fillColor: "white"
            strokeColor: "transparent"

            PathMove {
                x: main.centerX + main.radius - main.arcWidth / 2 - main.colorZoneWidth
                y: main.centerY
            }

            PathLine {
                relativeX: -15 * main.cursorScaleFactor
                relativeY: -7.5 * main.cursorScaleFactor
            }
            PathLine {
                relativeX: 0
                relativeY: 15 * main.cursorScaleFactor
            }
        }
    }

    Rectangle {
        id: titleText_alertbg
        visible: main.redBlink && titleText.text.length > 0
        x: titleText.x - 1.5
        y: titleText.y - 1.5
        width: titleText.width + 3
        height: titleText.height + 3

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
        visible: main.redBlink && unitText.text.length > 0
        x: unitText.x - 1.5
        y: unitText.y - 1.5
        width: unitText.width + 3
        height: unitText.height + 3

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
        visible: main.redBlink && valueText.text.length > 0
        x: valueText.x - 1.5
        y: valueText.y - 1.5
        width: valueText.width + 3
        height: valueText.height + 3

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

    property real totalTextSize: (titleText.visible ? main.titleSize : 0) + (unitText.visible ? main.unitSize : 0) + (valueText.visible ? main.valueTextSize : 0)

    Text {
        id: titleText
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: main.centerX
        y: main.centerY - main.totalTextSize / 2 - (height - main.titleSize) / 2
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: main.titleSize
        color: "white"
        visible: text.length > 0

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
        y: main.centerY - main.totalTextSize / 2 - (height - main.unitSize) / 2 + (titleText.visible ? main.titleSize : 0)
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: main.unitSize
        //text: main.unit
        color: "white"
        visible: text.length > 0

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

    Text {
        id: valueText
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: main.centerX
        y: main.centerY + main.totalTextSize / 2 - height + (height - main.valueTextSize) / 2
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: main.valueTextSize
        //text: main.textValue
        color: "white"
        visible: text.length > 0


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






















































