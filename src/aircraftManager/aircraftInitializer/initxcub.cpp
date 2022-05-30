#include "aircraftinitializer.h"

AircraftDefinition AircraftInitializer::initXCUB()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 500, .end = 2700, .color = QColor(0, 128, 0) }, ColorZone{ .start = 2700, .end = 3000, .color = QColor(255, 0, 0) } };
    QVector<GradDef> gradVec = { };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition rpmGauge = RawGaugeDefinition{ .title = "RPM", .unitString = "", .minValue = 0, .maxValue = 3000, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 2700, .noText = false, .unit = Units::RPM };


    colorVec = { ColorZone{ .start = 30.0 * 3.38639, .end = 40.0 * 3.38639, .color = QColor(255, 255, 255) }, ColorZone{ .start = 0, .end = 30.0 * 3.38639, .color = QColor(0, 128, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition secondGauge = RawGaugeDefinition{ .title = "MAN", .unitString = "kPa", .minValue = 0, .maxValue = 40.0 * 3.38639, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KILOPASCAL };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 700, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 725, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 750, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 775, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 800, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 825, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 850, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 875, .isBig = false, .gradColor = "white" } };
    textGradVec = { };

    GaugeDefinition egtGauge = RawGaugeDefinition{ .title = "EGT", .unitString = "ºC", .minValue = 1218.0 / 1.8, .maxValue = 1618.0 / 1.8, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0.2 * 62.59, .end = 62.59, .color = QColor(0, 128, 0) }, ColorZone{ .start = 0.1 * 62.59, .end = 0.2 * 62.59, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0, .end = 0.1 * 62.59, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 10, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 60, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 10, .gradText = "10" }, TextGradDef{ .textGradPos = 20, .gradText = "20" }, TextGradDef{ .textGradPos = 30, .gradText = "30" }, TextGradDef{ .textGradPos = 40, .gradText = "40" }, TextGradDef{ .textGradPos = 50, .gradText = "50" }, TextGradDef{ .textGradPos = 60, .gradText = "60" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "L FUEL QTY R", .unitString = "KG", .minValue = 0, .maxValue = 62.59, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 10, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 10, .gradText = "10" }, TextGradDef{ .textGradPos = 20, .gradText = "20" }, TextGradDef{ .textGradPos = 30, .gradText = "30" }, TextGradDef{ .textGradPos = 40, .gradText = "40" }, TextGradDef{ .textGradPos = 50, .gradText = "50" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "FUEL FLOW", .unitString = "KGH", .minValue = 0, .maxValue = 120.0 * 0.45359237, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = -32.0 / 1.8, .end = 68.0 / 1.8, .color = QColor(255, 255, 0) }, ColorZone{ .start = 68.0 / 1.8, .end = 213.0 / 1.8, .color = QColor(0, 128, 0) }, ColorZone{ .start = 213.0 / 1.8, .end = 218.0 / 1.8, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "OIL TEMP", .unitString = "ºC", .minValue = -32.0 / 1.8, .maxValue = 218.0 / 1.8, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 213.0 / 1.8, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 25.0 * 6.894757, .color = QColor(255, 0, 0) }, ColorZone{ .start = 25.0 * 6.894757, .end = 55.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 55.0 * 6.894757, .end = 95.0 * 6.894757, .color = QColor(0, 128, 0) }, ColorZone{ .start = 95.0 * 6.894757, .end = 115.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 115.0 * 6.894757, .end = 120.0 * 6.894757, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "OIL PRESS", .unitString = "kPa", .minValue = 0, .maxValue = 120.0 * 6.894757, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = true, .minRedBlinkThreshold = 25.0 * 6.894757, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 115.0 * 6.894757, .noText = false, .unit = Units::KILOPASCAL };

    AircraftDefinition ret{ .type = AircraftDefinition::AircraftType::PROP, .name = "Cub Crafter X Cub", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = false, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 1, .numTanks = 2, .lowLimit = 40, .flapsBegin = 40, .flapsEnd = 70, .greenBegin = 41, .greenEnd = 117, .yellowBegin = 117, .yellowEnd = 144, .redBegin = 0, .redEnd = 0, .highLimit = 144, .noColors = false, .dynamicBarberpole = false };

    ret.currentType.setValue(PropDefinition(RawPropDefinition{ .rpmGauge = rpmGauge, .secondGauge = secondGauge, .egtGauge = egtGauge, .hasEgt = true, .usePropRpm = true, .secondIsLoad = false, .maxHp = 1 }));

    return ret;

}
