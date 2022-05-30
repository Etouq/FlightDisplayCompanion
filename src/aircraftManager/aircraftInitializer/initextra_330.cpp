#include "aircraftinitializer.h"

AircraftDefinition AircraftInitializer::initEXTRA_330()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 700, .end = 2800, .color = QColor(0, 128, 0) } };
    QVector<GradDef> gradVec = { };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition rpmGauge = RawGaugeDefinition{ .title = "RPM", .unitString = "", .minValue = 0, .maxValue = 2800, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::RPM };


    colorVec = { ColorZone{ .start = 0, .end = 40.0 * 3.38639, .color = QColor(255, 255, 255) }, ColorZone{ .start = 10.0 * 3.38639, .end = 30.0 * 3.38639, .color = QColor(0, 128, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition secondGauge = RawGaugeDefinition{ .title = "MAN", .unitString = "kPa", .minValue = 0, .maxValue = 40.0 * 3.38639, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KILOPASCAL };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 400, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 600, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 700, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 800, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 900, .isBig = false, .gradColor = "white" } };
    textGradVec = { };

    GaugeDefinition egtGauge = RawGaugeDefinition{ .title = "EGT", .unitString = "ºC", .minValue = 400, .maxValue = 930, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0.2 * 54.425, .end = 54.425, .color = QColor(0, 128, 0) }, ColorZone{ .start = 0, .end = 0.2 * 28.44, .color = QColor(255, 255, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 10, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 10, .gradText = "10" }, TextGradDef{ .textGradPos = 20, .gradText = "20" }, TextGradDef{ .textGradPos = 30, .gradText = "30" }, TextGradDef{ .textGradPos = 40, .gradText = "40" }, TextGradDef{ .textGradPos = 50, .gradText = "50" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "FUEL QTY", .unitString = "KG", .minValue = 0, .maxValue = 54.425, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 5, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 10, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 15, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 25, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 5, .gradText = "5" }, TextGradDef{ .textGradPos = 10, .gradText = "10" }, TextGradDef{ .textGradPos = 15, .gradText = "15" }, TextGradDef{ .textGradPos = 20, .gradText = "20" }, TextGradDef{ .textGradPos = 25, .gradText = "25" }, TextGradDef{ .textGradPos = 30, .gradText = "30" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "FUEL FLOW", .unitString = "KGH", .minValue = 0, .maxValue = 30, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = -32.0 / 1.8, .end = 108.0 / 1.8, .color = QColor(255, 255, 0) }, ColorZone{ .start = 108.0 / 1.8, .end = 178.0 / 1.8, .color = QColor(0, 128, 0) }, ColorZone{ .start = 178.0 / 1.8, .end = 213.0 / 1.8, .color = QColor(255, 255, 0) }, ColorZone{ .start = 213.0 / 1.8, .end = 238.0 / 1.8, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "OIL TEMP", .unitString = "ºC", .minValue = -32.0 / 1.8, .maxValue = 238.0 / 1.8, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 25.0 * 6.894757, .color = QColor(255, 0, 0) }, ColorZone{ .start = 25.0 * 6.894757, .end = 55.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 55.0 * 6.894757, .end = 95.0 * 6.894757, .color = QColor(0, 128, 0) }, ColorZone{ .start = 95.0 * 6.894757, .end = 115.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 115.0 * 6.894757, .end = 120.0 * 6.894757, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "OIL PRESS", .unitString = "kPa", .minValue = 0, .maxValue = 130.0 * 6.894757, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KILOPASCAL };

    AircraftDefinition ret{ .type = AircraftDefinition::AircraftType::PROP, .name = "EXTRA 330LT", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = false, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 1, .numTanks = 1, .lowLimit = 0, .flapsBegin = 0, .flapsEnd = 0, .greenBegin = 65, .greenEnd = 160, .yellowBegin = 160, .yellowEnd = 221, .redBegin = 221, .redEnd = 222, .highLimit = 222, .noColors = false, .dynamicBarberpole = false };

    ret.currentType.setValue(PropDefinition(RawPropDefinition{ .rpmGauge = rpmGauge, .secondGauge = secondGauge, .egtGauge = egtGauge, .hasEgt = true, .usePropRpm = true, .secondIsLoad = false, .maxHp = 1 }));

    return ret;
}
