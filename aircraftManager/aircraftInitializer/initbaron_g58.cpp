#include "aircraftinitializer.h"

AircraftDefinition AircraftInitializer::initBARON_G58()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 0, .end = 3000, .color = QColor(255, 255, 255) }, ColorZone{ .start = 1800, .end = 2700, .color = QColor(0, 128, 0) }, ColorZone{ .start = 2700, .end = 3000, .color = QColor(255, 0, 0) } };
    QVector<GradDef> gradVec = { };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition rpmGauge = RawGaugeDefinition{ .title = "RPM", .unitString = "", .minValue = 0, .maxValue = 3000, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 10, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 2700, .noText = false, .unit = Units::RPM };


    colorVec = { ColorZone{ .start = 10.0 * 3.38639, .end = 35.0 * 3.38639, .color = QColor(255, 255, 255) }, ColorZone{ .start = 15.0 * 3.38639, .end = 30.0 * 3.38639, .color = QColor(0, 128, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition secondGauge = RawGaugeDefinition{ .title = "MAN", .unitString = "kPa", .minValue = 10.0 * 3.38639, .maxValue = 35.0 * 3.38639, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KILOPASCAL };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 200, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 300, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 400, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 600, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 700, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 800, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 900, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 100, .gradText = "100" }, TextGradDef{ .textGradPos = 200, .gradText = "200" }, TextGradDef{ .textGradPos = 300, .gradText = "300" }, TextGradDef{ .textGradPos = 400, .gradText = "400" }, TextGradDef{ .textGradPos = 500, .gradText = "500" }, TextGradDef{ .textGradPos = 600, .gradText = "600" }, TextGradDef{ .textGradPos = 700, .gradText = "700" }, TextGradDef{ .textGradPos = 800, .gradText = "800" }, TextGradDef{ .textGradPos = 900, .gradText = "900" } };

    GaugeDefinition egtGauge = RawGaugeDefinition{ .title = "L EGT R", .unitString = "ºC", .minValue = 0, .maxValue = 1628.0 / 1.8, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 0.16 * 255.82, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0.16 * 255.82, .end = 255.82, .color = QColor(0, 128, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 150, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 200, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 250, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 50, .gradText = "50" }, TextGradDef{ .textGradPos = 100, .gradText = "100" }, TextGradDef{ .textGradPos = 150, .gradText = "150" }, TextGradDef{ .textGradPos = 200, .gradText = "200" }, TextGradDef{ .textGradPos = 250, .gradText = "250" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "L FUEL QTY R", .unitString = "KG", .minValue = 0, .maxValue = 255.82, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { ColorZone{ .start = 164.4 * 0.45359237, .end = 180.0 * 0.45359237, .color = QColor(255, 0, 0) }, ColorZone{ .start = 18.0 * 0.45359237, .end = 164.4 * 0.45359237, .color = QColor(0, 128, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 15, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 45, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 60, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 75, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 15, .gradText = "15" }, TextGradDef{ .textGradPos = 30, .gradText = "30" }, TextGradDef{ .textGradPos = 45, .gradText = "45" }, TextGradDef{ .textGradPos = 60, .gradText = "60" }, TextGradDef{ .textGradPos = 75, .gradText = "75" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "L FUEL FLOW R", .unitString = "KGH", .minValue = 0, .maxValue = 180.0 * 0.45359237, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = 0, .end = 24, .color = QColor(255, 255, 0) }, ColorZone{ .start = 24, .end = 116, .color = QColor(0, 128, 0) }, ColorZone{ .start = 116, .end = 120, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 60, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 80, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 20, .gradText = "20" }, TextGradDef{ .textGradPos = 40, .gradText = "40" }, TextGradDef{ .textGradPos = 60, .gradText = "60" }, TextGradDef{ .textGradPos = 80, .gradText = "80" }, TextGradDef{ .textGradPos = 100, .gradText = "100" }, TextGradDef{ .textGradPos = 120, .gradText = "120" } };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "L OIL TEMP R", .unitString = "ºC", .minValue = 0, .maxValue = 120, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 120, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 10.0 * 6.894757, .color = QColor(255, 0, 0) }, ColorZone{ .start = 10.0 * 6.894757, .end = 30.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 30.0 * 6.894757, .end = 60.0 * 6.894757, .color = QColor(0, 128, 0) }, ColorZone{ .start = 100.0 * 6.894757, .end = 105.0 * 6.894757, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 125, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 250, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 375, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 625, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 125, .gradText = "125" }, TextGradDef{ .textGradPos = 250, .gradText = "250" }, TextGradDef{ .textGradPos = 375, .gradText = "375" }, TextGradDef{ .textGradPos = 500, .gradText = "500" }, TextGradDef{ .textGradPos = 625, .gradText = "625" } };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "L OIL PRESS R", .unitString = "kPa", .minValue = 0, .maxValue = 105.0 * 6.894757, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = true, .minRedBlinkThreshold = 10.0 * 6.894757, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 100.0 * 6.894757, .noText = false, .unit = Units::KILOPASCAL };

    AircraftDefinition ret{ .type = AircraftDefinition::AircraftType::PROP, .name = "Beechcraft Baron G58", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = false, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 2, .numTanks = 2, .lowLimit = 0, .flapsBegin = 74, .flapsEnd = 122, .greenBegin = 84, .greenEnd = 195, .yellowBegin = 195, .yellowEnd = 223, .redBegin = 0, .redEnd = 0, .highLimit = 223, .noColors = false, .dynamicBarberpole = false };

    ret.currentType.setValue(PropDefinition(RawPropDefinition{ .rpmGauge = rpmGauge, .secondGauge = secondGauge, .egtGauge = egtGauge, .hasEgt = true, .usePropRpm = true, .secondIsLoad = false, .maxHp = 1 }));

    return ret;
}

