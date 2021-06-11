import QtQuick 2.15
import QtQuick.Shapes 1.15
import "gauges"

Item {
    anchors.fill: parent
    clip: true

    property int numTanks: 1

    Component.onCompleted: {
        fuelTankGaugeLoader.setSource(numTanks == 1 ? "qrc:/mfdPage/engineDisplay/gauges/FuelSingleTankGauge.qml" : "qrc:/mfdPage/engineDisplay/gauges/FuelDoubleTankGauge.qml", { "centerX": 97.5, "yTop": 480 });
        if (commonGaugeProperties.getHasSpoilers())
            flapsGaugeLoader.setSource("qrc:/mfdPage/engineDisplay/gauges/FlapsSpoilersGauge.qml", { "yStart": 924.6 });
        else if(commonGaugeProperties.getHasFlaps())
            flapsGaugeLoader.setSource("qrc:/mfdPage/engineDisplay/gauges/FlapsGauge.qml", { "yStart": 924.6 });
        else
            flapsGaugeLoader.setSource("");

    }

    Item {
        id: n1GaugeParent

        CircularGauge {
            id: n1GaugeLeft
            startAngle: n1GaugeItem.getStartAngle()
            endAngle: n1GaugeItem.getEndAngle()
            radius: 70.5
            centerX: 97.5
            centerY: 82.5

            valueTextSize: 26

            minValue: n1GaugeItem.getMinValue()
            maxValue: n1GaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorAngle: n1GaugeItem.engine1Angle
            textValue: n1GaugeItem.engine1Value
            textColor: n1GaugeItem.engine1Color
            redBlink: n1GaugeItem.engine1RedBlink

            Component.onCompleted: {
                initModels(n1GaugeItem);
            }
        }

        CircularGauge {
            id: n1GaugeRight
            startAngle: n1GaugeItem.getStartAngle()
            endAngle: n1GaugeItem.getEndAngle()
            radius: 70.5
            centerX: 322.5
            centerY: 82.5

            valueTextSize: 26
            
            minValue: n1GaugeItem.getMinValue()
            maxValue: n1GaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorAngle: n1GaugeItem.engine2Angle
            textValue: n1GaugeItem.engine2Value
            textColor: n1GaugeItem.engine2Color
            redBlink: n1GaugeItem.engine2RedBlink

            Component.onCompleted: {
                initModels(n1GaugeItem);
            }
        }

        Text {
            anchors.horizontalCenter: parent.left
            anchors.horizontalCenterOffset: 210
            y: 10.5
            lineHeight: 0.8
            horizontalAlignment: Text.AlignHCenter
            color: "white"
            font.pixelSize: 26
            font.family: "Roboto Mono"
            font.bold: true
            text: n1GaugeItem.getName() + '\n' + n1GaugeItem.getUnit()
        }
    }

    Item {
        id: n2GaugeParent

        CircularGauge {
            id: n2GaugeLeft
            startAngle: n2GaugeItem.getStartAngle()
            endAngle: n2GaugeItem.getEndAngle()
            radius: 70.5
            centerX: 97.5
            centerY: 217.5

            valueTextSize: 26
            
            minValue: n2GaugeItem.getMinValue()
            maxValue: n2GaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorAngle: n2GaugeItem.engine1Angle
            textValue: n2GaugeItem.engine1Value
            textColor: n2GaugeItem.engine1Color
            redBlink: n2GaugeItem.engine1RedBlink

            Component.onCompleted: {
                initModels(n2GaugeItem);
            }
        }

        CircularGauge {
            id: n2GaugeRight
            startAngle: n2GaugeItem.getStartAngle()
            endAngle: n2GaugeItem.getEndAngle()
            radius: 70.5
            centerX: 322.5
            centerY: 217.5

            valueTextSize: 26
            
            minValue: n2GaugeItem.getMinValue()
            maxValue: n2GaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorAngle: n2GaugeItem.engine2Angle
            textValue: n2GaugeItem.engine2Value
            textColor: n2GaugeItem.engine2Color
            redBlink: n2GaugeItem.engine2RedBlink

            Component.onCompleted: {
                initModels(n2GaugeItem);
            }
        }

        Text {
            anchors.horizontalCenter: parent.left
            anchors.horizontalCenterOffset: 210
            y: 145.5
            lineHeight: 0.8
            horizontalAlignment: Text.AlignHCenter
            color: "white"
            font.pixelSize: 26
            font.family: "Roboto Mono"
            font.bold: true
            text: n2GaugeItem.getName() + '\n' + n2GaugeItem.getUnit()
        }
    }

    Item {
        id: ittGaugeParent

        CircularGauge {
            id: ittGaugeLeft
            startAngle: ittGaugeItem.getStartAngle()
            endAngle: ittGaugeItem.getEndAngle()
            radius: 70.5
            centerX: 97.5
            centerY: 352.5

            valueTextSize: 26
            
            minValue: ittGaugeItem.getMinValue()
            maxValue: ittGaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorAngle: ittGaugeItem.engine1Angle
            textValue: ittGaugeItem.engine1Value
            textColor: ittGaugeItem.engine1Color
            redBlink: ittGaugeItem.engine1RedBlink

            Component.onCompleted: {
                initModels(ittGaugeItem);
            }
        }

        CircularGauge {
            id: ittGaugeRight
            startAngle: ittGaugeItem.getStartAngle()
            endAngle: ittGaugeItem.getEndAngle()
            radius: 70.5
            centerX: 322.5
            centerY: 352.5

            valueTextSize: 26
            
            minValue: ittGaugeItem.getMinValue()
            maxValue: ittGaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorAngle: ittGaugeItem.engine2Angle
            textValue: ittGaugeItem.engine2Value
            textColor: ittGaugeItem.engine2Color
            redBlink: ittGaugeItem.engine2RedBlink

            Component.onCompleted: {
                initModels(ittGaugeItem);
            }
        }

        Text {
            anchors.horizontalCenter: parent.left
            anchors.horizontalCenterOffset: 210
            y: 280.5
            lineHeight: 0.8
            horizontalAlignment: Text.AlignHCenter
            color: "white"
            font.pixelSize: 26
            font.family: "Roboto Mono"
            font.bold: true
            text: ittGaugeItem.getName() + '\n' + ittGaugeItem.getUnit()
        }
    }

    Loader {
        id: fuelTankGaugeLoader
    }

    VerticalDoubleGauge {
        id: fuelFlowGauge
        centerX: 322.5
        yTop: 480

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
        topBaseline: 660
    }

    VerticalDoubleGauge {
        id: oilTempGauge
        centerX: 120
        yTop: 750

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
        yTop: 750

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
        elevTop: 1027.5
    }


}
