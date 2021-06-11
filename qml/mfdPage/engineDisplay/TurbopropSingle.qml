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

    CircularGauge {
        id: n1Gauge
        startAngle: n1GaugeItem.getStartAngle()
        endAngle: n1GaugeItem.getEndAngle()
        radius: 90
        centerX: 105
        centerY: 105

        titleSize: 23
        unitSize: 23
        
        valueTextSize: 30
        
        arcWidth: 4
        colorZoneWidth: 8
        gradScaleFactor: 1.3

        minValue: n1GaugeItem.getMinValue()
        maxValue: n1GaugeItem.getMaxValue()

        title: n1GaugeItem.getName()
        unit: n1GaugeItem.getUnit()

        cursorAngle: n1GaugeItem.engine1Angle
        textValue: n1GaugeItem.engine1Value
        textColor: n1GaugeItem.engine1Color
        redBlink: n1GaugeItem.engine1RedBlink

        Component.onCompleted: {
            initModels(n1GaugeItem);
        }
    }

    CircularGauge {
        id: trqGauge
        startAngle: trqGaugeItem.getStartAngle()
        endAngle: trqGaugeItem.getEndAngle()
        radius: 90
        centerX: 315
        centerY: 105

        titleSize: 23
        unitSize: 23
        
        valueTextSize: 30
        
        arcWidth: 4
        colorZoneWidth: 8
        gradScaleFactor: 1.3

        minValue: trqGaugeItem.getMinValue()
        maxValue: trqGaugeItem.getMaxValue()

        title: trqGaugeItem.getName()
        unit: trqGaugeItem.getUnit()

        cursorAngle: trqGaugeItem.engine1Angle
        textValue: trqGaugeItem.engine1Value
        textColor: trqGaugeItem.engine1Color
        redBlink: trqGaugeItem.engine1RedBlink

        Component.onCompleted: {
            initModels(trqGaugeItem);
        }
    }

    CircularGauge {
        id: ittGauge
        startAngle: ittGaugeItem.getStartAngle()
        endAngle: ittGaugeItem.getEndAngle()
        radius: 90
        centerX: 105
        centerY: 315

        titleSize: 23
        unitSize: 23
        
        valueTextSize: 30
        
        arcWidth: 4
        colorZoneWidth: 8
        gradScaleFactor: 1.3

        minValue: ittGaugeItem.getMinValue()
        maxValue: ittGaugeItem.getMaxValue()

        title: ittGaugeItem.getName()
        unit: ittGaugeItem.getUnit()

        cursorAngle: ittGaugeItem.engine1Angle
        textValue: ittGaugeItem.engine1Value
        textColor: ittGaugeItem.engine1Color
        redBlink: ittGaugeItem.engine1RedBlink

        Component.onCompleted: {
            initModels(ittGaugeItem);
        }
    }

    CircularGauge {
        id: rpmGauge
        startAngle: rpmGaugeItem.getStartAngle()
        endAngle: rpmGaugeItem.getEndAngle()
        radius: 90
        centerX: 315
        centerY: 315

        titleSize: 23
        unitSize: 23
        
        valueTextSize: 30
        
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
