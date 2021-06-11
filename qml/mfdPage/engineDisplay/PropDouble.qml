import QtQuick 2.15
import QtQuick.Shapes 1.15
import "gauges"

Item {
    anchors.fill: parent
    clip: true


    property int numTanks: 1

    Component.onCompleted: {
        fuelTankGaugeLoader.setSource(numTanks == 1 ? "qrc:/mfdPage/engineDisplay/gauges/FuelSingleTankGauge.qml" : "qrc:/mfdPage/engineDisplay/gauges/FuelDoubleTankGauge.qml", { "centerX": 105, "yTop": 445.5 });
        if (commonGaugeProperties.getHasSpoilers())
            flapsGaugeLoader.setSource("qrc:/mfdPage/engineDisplay/gauges/FlapsSpoilersGauge.qml", { "yStart": 909.6 });
        else if(commonGaugeProperties.getHasFlaps())
            flapsGaugeLoader.setSource("qrc:/mfdPage/engineDisplay/gauges/FlapsGauge.qml", { "yStart": 909.6 });
        else
            flapsGaugeLoader.setSource("");

    }

    Item {
        id: rpmGaugeParent

        CircularGauge {
            id: rpmGaugeLeft
            startAngle: rpmGaugeItem.getStartAngle()
            endAngle: rpmGaugeItem.getEndAngle()
            radius: 75
            centerX: 97.5
            centerY: 135

            valueTextSize: 26
            
            minValue: rpmGaugeItem.getMinValue()
            maxValue: rpmGaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorAngle: rpmGaugeItem.engine1Angle
            textValue: rpmGaugeItem.engine1Value
            textColor: rpmGaugeItem.engine1Color
            redBlink: rpmGaugeItem.engine1RedBlink

            Component.onCompleted: {
                initModels(rpmGaugeItem);
            }
        }

        CircularGauge {
            id: rpmGaugeRight
            startAngle: rpmGaugeItem.getStartAngle()
            endAngle: rpmGaugeItem.getEndAngle()
            radius: 75
            centerX: 322.5
            centerY: 135

            valueTextSize: 26
            
            minValue: rpmGaugeItem.getMinValue()
            maxValue: rpmGaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorAngle: rpmGaugeItem.engine2Angle
            textValue: rpmGaugeItem.engine2Value
            textColor: rpmGaugeItem.engine2Color
            redBlink: rpmGaugeItem.engine2RedBlink

            Component.onCompleted: {
                initModels(rpmGaugeItem);
            }
        }

        Text {
            anchors.horizontalCenter: parent.left
            anchors.horizontalCenterOffset: 210
            y: 60
            lineHeight: 0.8
            horizontalAlignment: Text.AlignHCenter
            color: "white"
            font.pixelSize: 26
            font.family: "Roboto Mono"
            font.bold: true
            text: rpmGaugeItem.getName() + '\n' + rpmGaugeItem.getUnit()
        }
    }

    Item {
        id: secondGaugeParent

        CircularGauge {
            id: secondGaugeLeft
            startAngle: secondGaugeItem.getStartAngle()
            endAngle: secondGaugeItem.getEndAngle()
            radius: 75
            centerX: 97.5
            centerY: 315

            valueTextSize: 26
            
            minValue: secondGaugeItem.getMinValue()
            maxValue: secondGaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorAngle: secondGaugeItem.engine1Angle
            textValue: secondGaugeItem.engine1Value
            textColor: secondGaugeItem.engine1Color
            redBlink: secondGaugeItem.engine1RedBlink

            Component.onCompleted: {
                initModels(secondGaugeItem);
            }
        }

        CircularGauge {
            id: secondGaugeRight
            startAngle: secondGaugeItem.getStartAngle()
            endAngle: secondGaugeItem.getEndAngle()
            radius: 75
            centerX: 322.5
            centerY: 315

            valueTextSize: 26
            
            minValue: secondGaugeItem.getMinValue()
            maxValue: secondGaugeItem.getMaxValue()

            title: ""
            unit: ""

            cursorAngle: secondGaugeItem.engine2Angle
            textValue: secondGaugeItem.engine2Value
            textColor: secondGaugeItem.engine2Color
            redBlink: secondGaugeItem.engine2RedBlink

            Component.onCompleted: {
                initModels(secondGaugeItem);
            }
        }

        Text {
            anchors.horizontalCenter: parent.left
            anchors.horizontalCenterOffset: 210
            y: 240
            lineHeight: 0.8
            horizontalAlignment: Text.AlignHCenter
            color: "white"
            font.pixelSize: 26
            font.family: "Roboto Mono"
            font.bold: true
            text: secondGaugeItem.getName() + '\n' + secondGaugeItem.getUnit()
        }
    }

    Loader {
        id: fuelTankGaugeLoader
    }

    VerticalDoubleGauge {
        id: fuelFlowGauge
        centerX: 315
        yTop: 445.5

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
        topBaseline: 622.5
    }

    VerticalDoubleGauge {
        id: oilTempGauge
        centerX: commonGaugeProperties.getHasEgt() ?  82.5 : 120
        yTop: 730.5

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
        yTop: 730.5

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
            yTop: 730.5

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
        elevTop: 1020
    }

}
