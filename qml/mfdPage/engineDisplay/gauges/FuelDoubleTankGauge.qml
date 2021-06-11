import QtQuick 2.15

VerticalDoubleGauge {
    centerX: 0
    yTop: 0

    extraWide: fuelQtyGaugeItem.needsExtraWide()

    minValue: fuelQtyGaugeItem.getMinValue()
    maxValue: fuelQtyGaugeItem.getMaxValue()

    title: fuelQtyGaugeItem.getName()
    unit: fuelQtyGaugeItem.getUnit()

    leftCursorTransformValue: fuelQtyGaugeItem.engine1TransformValue
    leftTextValue: fuelQtyGaugeItem.engine1Value
    leftTextColor: fuelQtyGaugeItem.engine1Color
    leftRedBlink: fuelQtyGaugeItem.engine1RedBlink

    rightCursorTransformValue: fuelQtyGaugeItem.engine2TransformValue
    rightTextValue: fuelQtyGaugeItem.engine2Value
    rightTextColor: fuelQtyGaugeItem.engine2Color
    rightRedBlink: fuelQtyGaugeItem.engine2RedBlink

    Component.onCompleted: {
        initModels(fuelQtyGaugeItem);
    }
}
