import QtQuick 2.15
import QtQuick.Shapes 1.15
import "gauges"

Item {
    anchors.fill: parent
    clip: true

    property int numTanks: 1

    Component.onCompleted: {
        fuelTankGaugeLoader.setSource(numTanks == 1 ? "qrc:/mfdPage/engineDisplay/gauges/FuelSingleTankGauge.qml" : "qrc:/mfdPage/engineDisplay/gauges/FuelDoubleTankGauge.qml", { "centerX": 97.5, "yTop": 499.5 });
        if (commonGaugeProperties.getHasSpoilers())
            flapsGaugeLoader.setSource("qrc:/mfdPage/engineDisplay/gauges/FlapsSpoilersGauge.qml", { "yStart": 939.6 });
        else if(commonGaugeProperties.getHasFlaps())
            flapsGaugeLoader.setSource("qrc:/mfdPage/engineDisplay/gauges/FlapsGauge.qml", { "yStart": 939.6 });
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
        id: trqGaugeParent

        CircularGauge {
            id: trqGaugeLeft
            startAngle: trqGaugeItem.getStartAngle()
            endAngle: trqGaugeItem.getEndAngle()
            radius: 70.5
            centerX: 97.5
            centerY: 217.5

            valueTextSize: 26
            
            minValue: trqGaugeItem.getMinValue()
            maxValue: trqGaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorAngle: trqGaugeItem.engine1Angle
            textValue: trqGaugeItem.engine1Value
            textColor: trqGaugeItem.engine1Color
            redBlink: trqGaugeItem.engine1RedBlink

            Component.onCompleted: {
                initModels(trqGaugeItem);
            }
        }

        CircularGauge {
            id: trqGaugeRight
            startAngle: trqGaugeItem.getStartAngle()
            endAngle: trqGaugeItem.getEndAngle()
            radius: 70.5
            centerX: 322.5
            centerY: 217.5

            valueTextSize: 26
            
            minValue: trqGaugeItem.getMinValue()
            maxValue: trqGaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorAngle: trqGaugeItem.engine2Angle
            textValue: trqGaugeItem.engine2Value
            textColor: trqGaugeItem.engine2Color
            redBlink: trqGaugeItem.engine2RedBlink

            Component.onCompleted: {
                initModels(trqGaugeItem);
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
            text: trqGaugeItem.getName() + '\n' + trqGaugeItem.getUnit()
        }
    }

    VerticalDoubleGauge {
        id: ittGauge
        centerX: 97.5
        yTop: 318

        extraWide: ittGaugeItem.needsExtraWide()

        minValue: ittGaugeItem.getMinValue()
        maxValue: ittGaugeItem.getMaxValue()

        title: ittGaugeItem.getName()
        unit: ittGaugeItem.getUnit()

        leftCursorTransformValue: ittGaugeItem.engine1TransformValue
        leftTextValue: ittGaugeItem.engine1Value
        leftTextColor: ittGaugeItem.engine1Color
        leftRedBlink: ittGaugeItem.engine1RedBlink

        rightCursorTransformValue: ittGaugeItem.engine2TransformValue
        rightTextValue: ittGaugeItem.engine2Value
        rightTextColor: ittGaugeItem.engine2Color
        rightRedBlink: ittGaugeItem.engine2RedBlink

        Component.onCompleted: {
            initModels(ittGaugeItem);
        }
    }

    VerticalDoubleGauge {
        id: rpmGauge
        centerX: 322.5
        yTop: 318

        extraWide: rpmGaugeItem.needsExtraWide()

        minValue: rpmGaugeItem.getMinValue()
        maxValue: rpmGaugeItem.getMaxValue()

        title: rpmGaugeItem.getName()
        unit: rpmGaugeItem.getUnit()

        leftCursorTransformValue: rpmGaugeItem.engine1TransformValue
        leftTextValue: rpmGaugeItem.engine1Value
        leftTextColor: rpmGaugeItem.engine1Color
        leftRedBlink: rpmGaugeItem.engine1RedBlink

        rightCursorTransformValue: rpmGaugeItem.engine2TransformValue
        rightTextValue: rpmGaugeItem.engine2Value
        rightTextColor: rpmGaugeItem.engine2Color
        rightRedBlink: rpmGaugeItem.engine2RedBlink

        Component.onCompleted: {
            initModels(rpmGaugeItem);
        }
    }

    Loader {
        id: fuelTankGaugeLoader
    }

    VerticalDoubleGauge {
        id: fuelFlowGauge
        centerX: 322.5
        yTop: 499.5

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
        topBaseline: 675
    }

    VerticalDoubleGauge {
        id: oilTempGauge
        centerX: commonGaugeProperties.getHasEgt() ?  82.5 : 120
        yTop: 765

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
        centerX: commonGaugeProperties.getHasEgt() ?  337.5 : 300
        yTop: 765

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

    Component {
        id: egtGaugeComp
        VerticalDoubleGauge {
            centerX: 210
            yTop: 765

            extraWide: egtGaugeItem.needsExtraWide()

            minValue: egtGaugeItem.getMinValue()
            maxValue: egtGaugeItem.getMaxValue()

            title: egtGaugeItem.getName()
            unit: egtGaugeItem.getUnit()

            leftCursorTransformValue: egtGaugeItem.engine1TransformValue
            leftTextValue: egtGaugeItem.engine1Value
            leftTextColor: egtGaugeItem.engine1Color
            leftRedBlink: egtGaugeItem.engine1RedBlink

            rightCursorTransformValue: egtGaugeItem.engine2TransformValue
            rightTextValue: egtGaugeItem.engine2Value
            rightTextColor: egtGaugeItem.engine2Color
            rightRedBlink: egtGaugeItem.engine2RedBlink

            Component.onCompleted: {
                initModels(egtGaugeItem);
            }
        }
    }

    Loader {
        id: egtLoader
        sourceComponent: commonGaugeProperties.getHasEgt() ? egtGaugeComp : undefined
    }

    Loader {
        id: flapsGaugeLoader
    }

    TrimGauges {
        elevTop: 1042.5
    }


}
