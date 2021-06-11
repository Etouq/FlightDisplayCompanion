import QtQuick 2.15
import QtQuick.Shapes 1.15
import "gauges"


Item {
    anchors.fill: parent
    clip: true

    property int numTanks: 2

    Component.onCompleted: {
        fuelTankGaugeLoader.setSource(numTanks == 1 ? "qrc:/mfdPage/engineDisplay/gauges/FuelSingleTankGauge.qml" : "qrc:/mfdPage/engineDisplay/gauges/FuelDoubleTankGauge.qml", { "centerX": 105, "yTop": 445.5 });
        if (commonGaugeProperties.getHasSpoilers())
            flapsGaugeLoader.setSource("qrc:/mfdPage/engineDisplay/gauges/FlapsSpoilersGauge.qml", { "yStart": 909.6 });
        else if(commonGaugeProperties.getHasFlaps())
            flapsGaugeLoader.setSource("qrc:/mfdPage/engineDisplay/gauges/FlapsGauge.qml", { "yStart": 909.6 });
        else
            flapsGaugeLoader.setSource("");

    }

    CircularGauge {
        id: rpmGauge
        startAngle: rpmGaugeItem.getStartAngle()
        endAngle: rpmGaugeItem.getEndAngle()
        radius: 120
        centerX: 210
        centerY: 135

        titleSize: 30
        unitSize: 30
        
        valueTextSize: 38
        
        arcWidth: 4
        colorZoneWidth: 8
        gradScaleFactor: 1.3

        minValue: rpmGaugeItem.getMinValue()
        maxValue: rpmGaugeItem.getMaxValue()

        title: rpmGaugeItem.getName()
        unit: rpmGaugeItem.getUnit()

        cursorAngle: rpmGaugeItem.engine1Angle
        textValue: rpmGaugeItem.engine1Value
        textColor: rpmGaugeItem.engine1Color
        redBlink: rpmGaugeItem.engine1RedBlink

        Component.onCompleted: {
            initModels(rpmGaugeItem);
        }
    }

    CircularGauge {
        id: secondGauge
        startAngle: secondGaugeItem.getStartAngle()
        endAngle: secondGaugeItem.getEndAngle()
        radius: 120
        centerX: 210
        centerY: 322.5

        titleSize: 30
        unitSize: 30
        
        valueTextSize: 38
        
        minValue: secondGaugeItem.getMinValue()
        maxValue: secondGaugeItem.getMaxValue()

        arcWidth: 4
        colorZoneWidth: 8
        gradScaleFactor: 1.3

        title: secondGaugeItem.getName()
        unit: secondGaugeItem.getUnit()

        cursorAngle: secondGaugeItem.engine1Angle
        textValue: secondGaugeItem.engine1Value
        textColor: secondGaugeItem.engine1Color
        redBlink: secondGaugeItem.engine1RedBlink

        Component.onCompleted: {
            initModels(secondGaugeItem);
        }
    }

    Loader {
        id: fuelTankGaugeLoader
    }

    VerticalGauge {
        id: fuelFlowGauge
        centerX: 315
        yTop: 445.5

        valuePos: 1

        minValue: fuelFlowGaugeItem.getMinValue()
        maxValue: fuelFlowGaugeItem.getMaxValue()

        title: fuelFlowGaugeItem.getName()
        unit: fuelFlowGaugeItem.getUnit()

        cursorTransformValue: fuelFlowGaugeItem.engine1TransformValue
        textValue: fuelFlowGaugeItem.engine1Value
        textColor: fuelFlowGaugeItem.engine1Color
        redBlink: fuelFlowGaugeItem.engine1RedBlink


        Component.onCompleted: {
            initModels(fuelFlowGaugeItem);
        }
    }

    FuelText {
        id: fuelTextGauge
        topBaseline: 622.5
    }

    VerticalGauge {
        id: oilTempGauge
        centerX: commonGaugeProperties.getHasEgt() ?  82.5 : 120
        yTop: 730.5

        valuePos: 2

        minValue: oilTempGaugeItem.getMinValue()
        maxValue: oilTempGaugeItem.getMaxValue()

        title: oilTempGaugeItem.getName()
        unit: oilTempGaugeItem.getUnit()

        cursorTransformValue: oilTempGaugeItem.engine1TransformValue
        textValue: oilTempGaugeItem.engine1Value
        textColor: oilTempGaugeItem.engine1Color
        redBlink: oilTempGaugeItem.engine1RedBlink

        Component.onCompleted: {
            initModels(oilTempGaugeItem);
        }
    }

    VerticalGauge {
        id: oilPressGauge
        centerX: commonGaugeProperties.getHasEgt() ?  337.5 : 300
        yTop: 730.5

        valuePos: 2

        minValue: oilPressGaugeItem.getMinValue()
        maxValue: oilPressGaugeItem.getMaxValue()

        title: oilPressGaugeItem.getName()
        unit: oilPressGaugeItem.getUnit()

        cursorTransformValue: oilPressGaugeItem.engine1TransformValue
        textValue: oilPressGaugeItem.engine1Value
        textColor: oilPressGaugeItem.engine1Color
        redBlink: oilPressGaugeItem.engine1RedBlink

        Component.onCompleted: {
            initModels(oilPressGaugeItem);
        }
    }

    Component {
        id: egtGaugeComp
        VerticalGauge {
            centerX: 210
            yTop: 730.5

            valuePos: 2

            minValue: egtGaugeItem.getMinValue()
            maxValue: egtGaugeItem.getMaxValue()

            title: egtGaugeItem.getName()
            unit: egtGaugeItem.getUnit()

            cursorTransformValue: egtGaugeItem.engine1TransformValue
            textValue: egtGaugeItem.engine1Value
            textColor: egtGaugeItem.engine1Color
            redBlink: egtGaugeItem.engine1RedBlink

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
