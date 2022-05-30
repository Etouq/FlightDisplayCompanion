#include "aircraftinitializer.h"

AircraftDefinition AircraftInitializer::initMUDRY_CAP_10_C()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 500, .end = 2650, .color = QColor(0, 128, 0) }, ColorZone{ .start = 2650, .end = 3000, .color = QColor(255, 0, 0) } };
    QVector<GradDef> gradVec = { };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition rpmGauge = RawGaugeDefinition{ .title = "RPM", .unitString = "", .minValue = 0, .maxValue = 3000, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::RPM };


    colorVec = { ColorZone{ .start = 10.0 * 3.38639, .end = 35.0 * 3.38639, .color = QColor(255, 255, 255) }, ColorZone{ .start = 15.0 * 3.38639, .end = 30.0 * 3.38639, .color = QColor(0, 128, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition secondGauge = RawGaugeDefinition{ .title = "MAN", .unitString = "kPa", .minValue = 10.0 * 3.38639, .maxValue = 35.0 * 3.38639, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KILOPASCAL };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 350, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 450, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 550, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 650, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 750, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 850, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 950, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1050, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1150, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1250, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1350, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1450, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1550, .isBig = false, .gradColor = "white" } };
    textGradVec = { };

    GaugeDefinition egtGauge = RawGaugeDefinition{ .title = "EGT", .unitString = "ºC", .minValue = 568.0 / 1.8, .maxValue = 1568.0 / 1.8, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0.2 * 110.7, .end = 110.7, .color = QColor(0, 128, 0) }, ColorZone{ .start = 0.1 * 110.7, .end = 0.2 * 110.7, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0, .end = 0.1 * 110.7, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 60, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 80, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 20, .gradText = "20" }, TextGradDef{ .textGradPos = 40, .gradText = "40" }, TextGradDef{ .textGradPos = 60, .gradText = "60" }, TextGradDef{ .textGradPos = 80, .gradText = "80" }, TextGradDef{ .textGradPos = 100, .gradText = "100" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "FUEL QTY", .unitString = "KG", .minValue = 0, .maxValue = 110.7, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 10, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 10, .gradText = "10" }, TextGradDef{ .textGradPos = 20, .gradText = "20" }, TextGradDef{ .textGradPos = 30, .gradText = "30" }, TextGradDef{ .textGradPos = 40, .gradText = "40" }, TextGradDef{ .textGradPos = 50, .gradText = "50" }, TextGradDef{ .textGradPos = 60, .gradText = "60" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "FUEL FLOW", .unitString = "KGH", .minValue = 0, .maxValue = 60, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = 68.0 / 1.8, .end = 98.0 / 1.8, .color = QColor(255, 0, 0) }, ColorZone{ .start = 98.0 / 1.8, .end = 198.0 / 1.8, .color = QColor(0, 128, 0) }, ColorZone{ .start = 198.0 / 1.8, .end = 228.0 / 1.8, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "OIL TEMP", .unitString = "ºC", .minValue = 68.0 / 1.8, .maxValue = 228.0 / 1.8, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 20.0 * 6.894757, .color = QColor(255, 0, 0) }, ColorZone{ .start = 20.0 * 6.894757, .end = 67.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 67.0 * 6.894757, .end = 95.0 * 6.894757, .color = QColor(0, 128, 0) }, ColorZone{ .start = 95.0 * 6.894757, .end = 100.0 * 6.894757, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "OIL PRESS", .unitString = "kPa", .minValue = 0, .maxValue = 100.0 * 6.894757, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KILOPASCAL };

    AircraftDefinition ret{ .type = AircraftDefinition::AircraftType::PROP, .name = "Robin Cap10", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = false, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 1, .numTanks = 1, .lowLimit = 0, .flapsBegin = 43, .flapsEnd = 86, .greenBegin = 51, .greenEnd = 162, .yellowBegin = 162, .yellowEnd = 184, .redBegin = 184, .redEnd = 186, .highLimit = 186, .noColors = false, .dynamicBarberpole = false };

    ret.currentType.setValue(PropDefinition(RawPropDefinition{ .rpmGauge = rpmGauge, .secondGauge = secondGauge, .egtGauge = egtGauge, .hasEgt = true, .usePropRpm = false, .secondIsLoad = false, .maxHp = 1 }));

    return ret;
}
