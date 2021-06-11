import QtQuick 2.15

VerticalGauge {
    centerX: 0
    yTop: 0
    valuePos: 1

    minValue: fuelQtyGaugeItem.getMinValue()
    maxValue: fuelQtyGaugeItem.getMaxValue()

    title: fuelQtyGaugeItem.getName()
    unit: fuelQtyGaugeItem.getUnit()

    cursorTransformValue: fuelQtyGaugeItem.engine1TransformValue
    textValue: fuelQtyGaugeItem.engine1Value
    textColor: fuelQtyGaugeItem.engine1Color
    redBlink: fuelQtyGaugeItem.engine1RedBlink

    Component.onCompleted: {
        initModels(fuelQtyGaugeItem);
    }
}
