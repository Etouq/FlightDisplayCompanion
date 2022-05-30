#include "aircraftinitializer.hpp"

AircraftDefinition AircraftInitializer::initSAVAGE_SHOCK_ULTRA()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 0, .end = 1400, .color = QColor(255, 255, 255) }, ColorZone{ .start = 1400, .end = 5500, .color = QColor(0, 128, 0) }, ColorZone{ .start = 5500, .end = 5800, .color = QColor(255, 255, 0) }, ColorZone{ .start = 5800, .end = 6000, .color = QColor(255, 0, 0) } };
    QVector<GradDef> gradVec = { };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition rpmGauge = RawGaugeDefinition{ .title = "RPM", .unitString = "", .minValue = 0, .maxValue = 6000, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::RPM };


    colorVec = { ColorZone{ .start = 0, .end = 40.0 * 3.38639, .color = QColor(255, 255, 255) }, ColorZone{ .start = 5.0 * 3.38639, .end = 35.0 * 3.38639, .color = QColor(0, 128, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition secondGauge = RawGaugeDefinition{ .title = "MAN", .unitString = "kPa", .minValue = 0, .maxValue = 40.0 * 3.38639, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KILOPASCAL };


    colorVec = { ColorZone{ .start = 500, .end = 1400, .color = QColor(0, 128, 0) }, ColorZone{ .start = 1400, .end = 1500, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 300, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 700, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 900, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1100, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1300, .isBig = false, .gradColor = "white" } };
    textGradVec = { };

    GaugeDefinition egtGauge = RawGaugeDefinition{ .title = "EGT", .unitString = "ºC", .minValue = 300, .maxValue = 1500, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0.2 * 38.10, .end = 38.10, .color = QColor(0, 128, 0) }, ColorZone{ .start = 0.1 * 38.10, .end = 0.2 * 38.10, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0, .end = 0.1 * 38.10, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 6, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 12, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 18, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 24, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 36, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 6, .gradText = "6" }, TextGradDef{ .textGradPos = 12, .gradText = "12" }, TextGradDef{ .textGradPos = 18, .gradText = "18" }, TextGradDef{ .textGradPos = 24, .gradText = "24" }, TextGradDef{ .textGradPos = 30, .gradText = "30" }, TextGradDef{ .textGradPos = 36, .gradText = "36" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "L FUEL QTY R", .unitString = "KG", .minValue = 0, .maxValue = 38.10, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 4, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 8, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 12, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 4, .gradText = "4" }, TextGradDef{ .textGradPos = 8, .gradText = "8" }, TextGradDef{ .textGradPos = 12, .gradText = "12" }, TextGradDef{ .textGradPos = 16, .gradText = "16" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "FUEL FLOW", .unitString = "KGH", .minValue = 0, .maxValue = 16, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = 8.0 / 1.8, .end = 88.0 / 1.8, .color = QColor(255, 255, 0) }, ColorZone{ .start = 88.0 / 1.8, .end = 198.0 / 1.8, .color = QColor(0, 128, 0) }, ColorZone{ .start = 198.0 / 1.8, .end = 228.0 / 1.8, .color = QColor(255, 255, 0) }, ColorZone{ .start = 228.0 / 1.8, .end = 248.0 / 1.8, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "OIL TEMP", .unitString = "ºC", .minValue = 8.0 / 1.8, .maxValue = 248.0 / 1.8, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 12.0 * 6.894757, .color = QColor(255, 0, 0) }, ColorZone{ .start = 12.0 * 6.894757, .end = 28.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 28.0 * 6.894757, .end = 85.0 * 6.894757, .color = QColor(0, 128, 0) }, ColorZone{ .start = 85.0 * 6.894757, .end = 102.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 102.0 * 6.894757, .end = 120.0 * 6.894757, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "OIL PRESS", .unitString = "kPa", .minValue = 0, .maxValue = 120.0 * 6.894757, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KILOPASCAL };

    AircraftDefinition ret{ .type = AircraftDefinition::AircraftType::PROP, .name = "Zlin Aviation Shock Ultra", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = false, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 1, .numTanks = 2, .lowLimit = 0, .flapsBegin = 26, .flapsEnd = 54, .greenBegin = 32, .greenEnd = 86, .yellowBegin = 86, .yellowEnd = 100, .redBegin = 100, .redEnd = 101, .highLimit = 101, .noColors = false, .dynamicBarberpole = false };

    ret.currentType.setValue(PropDefinition(RawPropDefinition{ .rpmGauge = rpmGauge, .secondGauge = secondGauge, .egtGauge = egtGauge, .hasEgt = true, .usePropRpm = false, .secondIsLoad = false, .maxHp = 1 }));

    return ret;

}
