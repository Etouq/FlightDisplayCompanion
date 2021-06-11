import QtQuick 2.15
import QtQuick.Shapes 1.15
import "gauges"

Item {
    anchors.fill: parent
    /*antialiasing: true
    layer.enabled: true
    layer.samples: 8*/
    clip: true

    //property real scaleFactor: 1
    property int numTanks: 1

    Component.onCompleted: {
        fuelTankGaugeLoader.setSource(numTanks == 1 ? "qrc:/mfdPage/engineDisplay/gauges/FuelSingleTankGauge.qml" : "qrc:/mfdPage/engineDisplay/gauges/FuelDoubleTankGauge.qml", { "centerX": 97.5, "yTop": 558 });
        if (commonGaugeProperties.getHasSpoilers())
            flapsGaugeLoader.setSource("qrc:/mfdPage/engineDisplay/gauges/FlapsSpoilersGauge.qml", { "yStart": 954.6 });
        else if(commonGaugeProperties.getHasFlaps())
            flapsGaugeLoader.setSource("qrc:/mfdPage/engineDisplay/gauges/FlapsGauge.qml", { "yStart": 954.6 });
        else
            flapsGaugeLoader.setSource("");

    }


    Item {
        id: n1GaugeParent

        VerticalGauge {
            centerX: 61.5
            yTop: 40.5
            valuePos: 2

            minValue: n1GaugeItem.getMinValue()
            maxValue: n1GaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorTransformValue: n1GaugeItem.engine1TransformValue
            textValue: n1GaugeItem.engine1Value
            textColor: n1GaugeItem.engine1Color
            redBlink: n1GaugeItem.engine1RedBlink

            Component.onCompleted: {
                initModels(n1GaugeItem);
            }
        }

        VerticalGauge {
            centerX: 160.5
            yTop: 40.5
            valuePos: 2

            minValue: n1GaugeItem.getMinValue()
            maxValue: n1GaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorTransformValue: n1GaugeItem.engine2TransformValue
            textValue: n1GaugeItem.engine2Value
            textColor: n1GaugeItem.engine2Color
            redBlink: n1GaugeItem.engine2RedBlink

            Component.onCompleted: {
                initModels(n1GaugeItem);
            }
        }

        VerticalGauge {
            centerX: 259.5
            yTop: 40.5
            valuePos: 2

            minValue: n1GaugeItem.getMinValue()
            maxValue: n1GaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorTransformValue: n1GaugeItem.engine3TransformValue
            textValue: n1GaugeItem.engine3Value
            textColor: n1GaugeItem.engine3Color
            redBlink: n1GaugeItem.engine3RedBlink

            Component.onCompleted: {
                initModels(n1GaugeItem);
            }
        }

        VerticalGauge {
            centerX: 358.5
            yTop: 40.5
            valuePos: 2

            minValue: n1GaugeItem.getMinValue()
            maxValue: n1GaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorTransformValue: n1GaugeItem.engine4TransformValue
            textValue: n1GaugeItem.engine4Value
            textColor: n1GaugeItem.engine4Color
            redBlink: n1GaugeItem.engine4RedBlink

            Component.onCompleted: {
                initModels(n1GaugeItem);
            }
        }

        Text {
            anchors.horizontalCenter: parent.left
            anchors.horizontalCenterOffset: 210
            anchors.baseline: parent.top
            anchors.baselineOffset: 30
            color: "white"
            font.pixelSize: 23
            font.family: "Roboto Mono"
            font.bold: true
            text: n1GaugeItem.getName() + ' ' + n1GaugeItem.getUnit()
        }
    }

    Item {
        id: n2GaugeParent

        VerticalGauge {
            centerX: 61.5
            yTop: 209.25
            valuePos: 2

            minValue: n2GaugeItem.getMinValue()
            maxValue: n2GaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorTransformValue: n2GaugeItem.engine1TransformValue
            textValue: n2GaugeItem.engine1Value
            textColor: n2GaugeItem.engine1Color
            redBlink: n2GaugeItem.engine1RedBlink

            Component.onCompleted: {
                initModels(n2GaugeItem);
            }
        }

        VerticalGauge {
            centerX: 160.5
            yTop: 209.25
            valuePos: 2

            minValue: n2GaugeItem.getMinValue()
            maxValue: n2GaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorTransformValue: n2GaugeItem.engine2TransformValue
            textValue: n2GaugeItem.engine2Value
            textColor: n2GaugeItem.engine2Color
            redBlink: n2GaugeItem.engine2RedBlink

            Component.onCompleted: {
                initModels(n2GaugeItem);
            }
        }

        VerticalGauge {
            centerX: 259.5
            yTop: 209.25
            valuePos: 2

            minValue: n2GaugeItem.getMinValue()
            maxValue: n2GaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorTransformValue: n2GaugeItem.engine3TransformValue
            textValue: n2GaugeItem.engine3Value
            textColor: n2GaugeItem.engine3Color
            redBlink: n2GaugeItem.engine3RedBlink

            Component.onCompleted: {
                initModels(n2GaugeItem);
            }
        }

        VerticalGauge {
            centerX: 358.5
            yTop: 209.25
            valuePos: 2

            minValue: n2GaugeItem.getMinValue()
            maxValue: n2GaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorTransformValue: n2GaugeItem.engine4TransformValue
            textValue: n2GaugeItem.engine4Value
            textColor: n2GaugeItem.engine4Color
            redBlink: n2GaugeItem.engine4RedBlink

            Component.onCompleted: {
                initModels(n2GaugeItem);
            }
        }

        Text {
            anchors.horizontalCenter: parent.left
            anchors.horizontalCenterOffset: 210
            anchors.baseline: parent.top
            anchors.baselineOffset: 198.75
            color: "white"
            font.pixelSize: 23
            font.family: "Roboto Mono"
            font.bold: true
            text: n2GaugeItem.getName() + ' ' + n2GaugeItem.getUnit()
        }
    }

    Item {
        id: ittGaugeParent

        VerticalGauge {
            centerX: 61.5
            yTop: 378
            valuePos: 2

            minValue: ittGaugeItem.getMinValue()
            maxValue: ittGaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorTransformValue: ittGaugeItem.engine1TransformValue
            textValue: ittGaugeItem.engine1Value
            textColor: ittGaugeItem.engine1Color
            redBlink: ittGaugeItem.engine1RedBlink

            Component.onCompleted: {
                initModels(ittGaugeItem);
            }
        }

        VerticalGauge {
            centerX: 160.5
            yTop: 378
            valuePos: 2

            minValue: ittGaugeItem.getMinValue()
            maxValue: ittGaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorTransformValue: ittGaugeItem.engine2TransformValue
            textValue: ittGaugeItem.engine2Value
            textColor: ittGaugeItem.engine2Color
            redBlink: ittGaugeItem.engine2RedBlink

            Component.onCompleted: {
                initModels(ittGaugeItem);
            }
        }

        VerticalGauge {
            centerX: 259.5
            yTop: 378
            valuePos: 2

            minValue: ittGaugeItem.getMinValue()
            maxValue: ittGaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorTransformValue: ittGaugeItem.engine3TransformValue
            textValue: ittGaugeItem.engine3Value
            textColor: ittGaugeItem.engine3Color
            redBlink: ittGaugeItem.engine3RedBlink

            Component.onCompleted: {
                initModels(ittGaugeItem);
            }
        }

        VerticalGauge {
            centerX: 358.5
            yTop: 378
            valuePos: 2

            minValue: ittGaugeItem.getMinValue()
            maxValue: ittGaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorTransformValue: ittGaugeItem.engine4TransformValue
            textValue: ittGaugeItem.engine4Value
            textColor: ittGaugeItem.engine4Color
            redBlink: ittGaugeItem.engine4RedBlink

            Component.onCompleted: {
                initModels(ittGaugeItem);
            }
        }

        Text {
            anchors.horizontalCenter: parent.left
            anchors.horizontalCenterOffset: 210
            anchors.baseline: parent.top
            anchors.baselineOffset: 367.5
            color: "white"
            font.pixelSize: 23
            font.family: "Roboto Mono"
            font.bold: true
            text: ittGaugeItem.getName() + ' ' + ittGaugeItem.getUnit()
        }
    }

    Loader {
        id: fuelTankGaugeLoader
    }

    VerticalDoubleGauge {
        id: fuelFlowGauge
        centerX: 322.5
        yTop: 558

        extraWide: fuelFlowGaugeItem.needsExtraWide()

        minValue: fuelFlowGaugeItem.getMinValue()
        maxValue: fuelFlowGaugeItem.getMaxValue()

        title: fuelFlowGaugeItem.getName()
        unit: fuelFlowGaugeItem.getUnit()

        leftCursorTransformValue: fuelFlowGaugeItem.engine1TransformValue
        leftTextValue: fuelFlowGaugeItem.engine1Value
        leftTextColor: fuelFlowGaugeItem.engine1Color
        leftRedBlink: fuelFlowGaugeItem.engine1RedBlink

        rightCursorTransformValue: fuelFlowGaugeItem.engine2TransformValue
        rightTextValue: fuelFlowGaugeItem.engine2Value
        rightTextColor: fuelFlowGaugeItem.engine2Color
        rightRedBlink: fuelFlowGaugeItem.engine2RedBlink

        Component.onCompleted: {
            initModels(fuelFlowGaugeItem);
        }
    }

    FuelText {
        id: fuelTextGauge
        topBaseline: 705
    }

    VerticalDoubleGauge {
        id: oilTempGauge
        centerX: 120
        yTop: 780

        extraWide: oilTempGaugeItem.needsExtraWide()

        minValue: oilTempGaugeItem.getMinValue()
        maxValue: oilTempGaugeItem.getMaxValue()

        title: oilTempGaugeItem.getName()
        unit: oilTempGaugeItem.getUnit()

        leftCursorTransformValue: oilTempGaugeItem.engine1TransformValue
        leftTextValue: oilTempGaugeItem.engine1Value
        leftTextColor: oilTempGaugeItem.engine1Color
        leftRedBlink: oilTempGaugeItem.engine1RedBlink

        rightCursorTransformValue: oilTempGaugeItem.engine2TransformValue
        rightTextValue: oilTempGaugeItem.engine2Value
        rightTextColor: oilTempGaugeItem.engine2Color
        rightRedBlink: oilTempGaugeItem.engine2RedBlink

        Component.onCompleted: {
            initModels(oilTempGaugeItem);
        }
    }

    VerticalDoubleGauge {
        id: oilPressGauge
        centerX: 300
        yTop: 780

        extraWide: oilPressGaugeItem.needsExtraWide()

        minValue: oilPressGaugeItem.getMinValue()
        maxValue: oilPressGaugeItem.getMaxValue()

        title: oilPressGaugeItem.getName()
        unit: oilPressGaugeItem.getUnit()

        leftCursorTransformValue: oilPressGaugeItem.engine1TransformValue
        leftTextValue: oilPressGaugeItem.engine1Value
        leftTextColor: oilPressGaugeItem.engine1Color
        leftRedBlink: oilPressGaugeItem.engine1RedBlink

        rightCursorTransformValue: oilPressGaugeItem.engine2TransformValue
        rightTextValue: oilPressGaugeItem.engine2Value
        rightTextColor: oilPressGaugeItem.engine2Color
        rightRedBlink: oilPressGaugeItem.engine2RedBlink

        Component.onCompleted: {
            initModels(oilPressGaugeItem);
        }
    }

    Loader {
        id: flapsGaugeLoader
    }

    TrimGauges {
        elevTop: 1057.5
    }
}
