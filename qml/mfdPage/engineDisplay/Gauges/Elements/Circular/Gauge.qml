import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQml 2.15
import Mfd.Engine 1.0
import "../"

Item {
    id: gauge

    //position and size
    readonly property real startAngle: gauge.gaugeData.getStartAngle()
    readonly property real endAngle: gauge.gaugeData.getEndAngle()
    required property real radius
    required property real centerX
    required property real centerY

    property int titleSize: 0
    property int unitSize: 0

    property int valueTextSize: 0

    //styling options
    property real arcWidth: 3
    property real colorZoneWidth: 6

    property real gradScaleFactor: 1
    property real cursorScaleFactor: gradScaleFactor

    readonly property real minValue: gauge.gaugeData.getMinValue()
    readonly property real maxValue: gauge.gaugeData.getMaxValue()

    readonly property real valueToAngleMult: {
                        const gaugeAngleRange = gauge.endAngle - gauge.startAngle;
                        const wrappedAngle = gaugeAngleRange - 360 * Math.floor(gaugeAngleRange / 360);

                        return wrappedAngle / (gauge.gaugeData.getMaxValue() - gauge.gaugeData.getMinValue());
                    }

    //data used in displaying values (cursor angle, text, etc.)
    property string title: ""
    property string unit: ""

    required property GaugeEngine gaugeData
    required property GaugeEngine engine


    function createColorZones() {
        let ret = [];

        for (let i = 0; i < gauge.gaugeData.numColorZones(); i++) {

            const arcComponent = Qt.createComponent("ColorArc.qml");

            const instance = arcComponent.createObject(colorParent, {
                                                           fillColor: gauge.gaugeData.colorZoneColorAt(i),
                                                           centerX: gauge.centerX,
                                                           centerY: gauge.centerY,
                                                           outerRadius: gauge.radius - gauge.arcWidth / 2 - 1.5,
                                                           arcWidth: gauge.colorZoneWidth,
                                                           startAngle: gauge.gaugeData.valueToAngle(gauge.gaugeData.colorZoneStartAt(i)),
                                                           endAngle: gauge.gaugeData.valueToAngle(gauge.gaugeData.colorZoneEndAt(i))
                                                       });

            if (instance === null) {
                console.log("Error creating arc")
            }
            else {
                ret.push(instance)
            }
        }

        return ret;
    }

    Shape {
        id: colorParent

        data: gauge.createColorZones()
    }

    Repeater {
        model: gauge.gaugeData.numGrads()
        delegate: Rectangle {
            required property int index

            color: gauge.gaugeData.colorZoneColorAt(index)

            transform: Rotation {
                id: gradTransform
            }

            Component.onCompleted: function () {
                if (gaugeData.gradIsBigAt(index)) {
                    width = gauge.gradScaleFactor * 13.5
                    height = gauge.gradScaleFactor * 2.1

                    x = gauge.centerX + gauge.radius - gauge.gradScaleFactor * 13.5
                } else {
                    width = gauge.gradScaleFactor * 9
                    height = gauge.gradScaleFactor * 1.5
                }

                x = gauge.centerX + gauge.radius - width
                y = gauge.centerY - height / 2

                gradTransform.origin.x = width - gauge.radius
                gradTransform.origin.y = height / 2
                gradTransform.angle = gauge.gaugeData.valueToAngle(gauge.gaugeData.gradValAt(index))
            }
        }
    }

    Repeater {
        model: gauge.gaugeData.numTextGrads()
        delegate: Text {
            required property int index

            anchors.horizontalCenter: parent.left
            anchors.verticalCenter: parent.top

            font.pixelSize: 13
            font.family: "Roboto Mono"
            font.bold: true

            text: gauge.gaugeData.gradTextAt(index)
            color: "white"

            Component.onCompleted: function () {
                const radiusFactor = gauge.radius + gauge.arcWidth / 2
                                   - gauge.gradScaleFactor * 9 - 10
                const gradValRad = gauge.gaugeData.valueToAngle(
                        gauge.gaugeData.textGradValAt(index)
                    ) * Math.PI / 180
                anchors.horizontalCenterOffset = gauge.centerX +
                    radiusFactor * 0.85 * Math.cos(gradValRad)
                anchors.verticalCenterOffset = gauge.centerY -
                    radiusFactor * 0.9 * Math.sin(gradValRad)
            }
        }
    }

    Shape {
        id: mainArc
        ShapePath {
            fillColor: "transparent"
            strokeColor: "white"
            strokeWidth: gauge.arcWidth

            PathAngleArc {
                centerX: gauge.centerX
                centerY: gauge.centerY
                radiusX: gauge.radius
                radiusY: gauge.radius
                startAngle: gauge.startAngle
                sweepAngle: {
                        const gaugeRange = gauge.endAngle - gauge.startAngle;
                        return gaugeRange - 360 * Math.floor(gaugeRange / 360);
                    }
            }
        }
    }

    Rectangle {
        id: beginLimit
        width: 15 * gauge.gradScaleFactor
        height: 3 * gauge.gradScaleFactor
        x: gauge.centerX + gauge.radius - 15 * gauge.gradScaleFactor
        y: gauge.centerY - (3 * gauge.gradScaleFactor) / 2
        color: "white"

        transform: Rotation {
            angle: gauge.startAngle
            origin.x: 15 * gauge.gradScaleFactor - gauge.radius
            origin.y: (3 * gauge.gradScaleFactor) / 2
        }
    }

    Rectangle {
        id: endLimit
        width: 15 * gauge.gradScaleFactor
        height: 3 * gauge.gradScaleFactor
        x: gauge.centerX + gauge.radius - 15 * gauge.gradScaleFactor
        y: gauge.centerY - (3 * gauge.gradScaleFactor) / 2
        color: "white"

        transform: Rotation {
            angle: gauge.endAngle
            origin.x: 15 * gauge.gradScaleFactor - gauge.radius
            origin.y: (3 * gauge.gradScaleFactor) / 2
        }
    }

    Shape {
        id: cursor
        transform: Rotation {
            id: cursorTransform
            angle: gauge.engine.angle
            origin.x: gauge.centerX
            origin.y: gauge.centerY
        }
        ShapePath {
            fillColor: "white"
            strokeColor: "transparent"

            PathMove {
                x: gauge.centerX + gauge.radius - gauge.arcWidth / 2 - gauge.colorZoneWidth
                y: gauge.centerY
            }

            PathLine {
                relativeX: -15 * gauge.cursorScaleFactor
                relativeY: -7.5 * gauge.cursorScaleFactor
            }
            PathLine {
                relativeX: 0
                relativeY: 15 * gauge.cursorScaleFactor
            }
        }
    }


    Rectangle {
        id: valueAlertBg
        visible: false

        anchors {
            fill: valueText

            margins: 1.5
        }
    }

    readonly property real totalTextSize: (gauge.title !== "" ? gauge.titleSize : 0)
                                          + (gauge.unit !== "" ? gauge.unitSize : 0)
                                          + (valueText.visible ? gauge.valueTextSize : 0)

    Loader {
        active: gauge.title != ""
        asynchronous: true
        sourceComponent: Item {
            Rectangle {
                id: titleAlertBg
                visible: false

                anchors {
                    fill: titleText

                    margins: 1.5
                }
            }
            Text {
                id: titleText
                anchors.horizontalCenter: parent.left
                anchors.horizontalCenterOffset: gauge.centerX
                y: gauge.centerY - gauge.totalTextSize / 2
                   - (titleText.height - gauge.titleSize) / 2
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: gauge.titleSize
                text: gauge.title
                color: "white"
            }

            ValueBlinkAnimation {
                rectTarget: titleAlertBg
                textTarget: titleText

                running: gauge.engine.redBlink
                onStopped: function () {
                    titleText.color = "white"
                }
            }
        }
    }

    Loader {
        active: gauge.unit != ""
        asynchronous: true
        sourceComponent: Item {
            Rectangle {
                id: unitAlertBg
                visible: false

                anchors {
                    fill: unitText

                    margins: 1.5
                }
            }
            Text {
                id: unitText
                anchors.horizontalCenter: parent.left
                anchors.horizontalCenterOffset: gauge.centerX
                y: gauge.centerY - gauge.totalTextSize / 2 - (unitText.height - gauge.unitSize)
                   / 2 + (gauge.title != "" ? gauge.titleSize : 0)
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: gauge.unitSize
                text: gauge.unit
                color: "white"
            }

            ValueBlinkAnimation {
                rectTarget: unitAlertBg
                textTarget: unitText

                running: gauge.engine.redBlink
                onStopped: function () {
                    unitText.color = "white"
                }
            }
        }
    }

    Text {
        id: valueText
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: gauge.centerX
        y: gauge.centerY + gauge.totalTextSize / 2 - valueText.height
           + (valueText.height - gauge.valueTextSize) / 2
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: gauge.valueTextSize
        text: gauge.engine.value
        color: gauge.engine.color
    }

    ValueBlinkAnimation {
        rectTarget: valueAlertBg
        textTarget: valueText

        running: gauge.engine.redBlink
        onStopped: function () {
            valueText.color = Qt.binding(function () {
                return gauge.engine.color
            })
        }
    }
}
