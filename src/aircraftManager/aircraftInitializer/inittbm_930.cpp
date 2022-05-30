#include "aircraftinitializer.hpp"

AircraftDefinition AircraftInitializer::initTBM_930()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 51, .end = 104, .color = QColor(0, 128, 0) }, ColorZone{ .start = 104, .end = 110, .color = QColor(255, 0, 0) } };
    QVector<GradDef> gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 10, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 60, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 70, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 80, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 90, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" } };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition n1Gauge = RawGaugeDefinition{ .title = "NG", .unitString = "%", .minValue = 0, .maxValue = 110, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 104, .noText = false, .unit = Units::PERCENT };


    colorVec = { ColorZone{ .start = 0, .end = 100, .color = QColor(0, 128, 0) }, ColorZone{ .start = 100, .end = 110, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition trqGauge = RawGaugeDefinition{ .title = "TRQ", .unitString = "%", .minValue = 0, .maxValue = 110, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 100, .noText = false, .unit = Units::PERCENT };


    colorVec = { ColorZone{ .start = 400, .end = 840, .color = QColor(0, 128, 0) }, ColorZone{ .start = 840, .end = 900, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 150, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 300, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 450, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 600, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 750, .isBig = false, .gradColor = "white" } };
    textGradVec = { };

    GaugeDefinition ittGauge = RawGaugeDefinition{ .title = "ITT", .unitString = "ºC", .minValue = 0, .maxValue = 900, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 870, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 1950, .end = 2050, .color = QColor(0, 128, 0) }, ColorZone{ .start = 450, .end = 1000, .color = QColor(255, 255, 0) }, ColorZone{ .start = 2050, .end = 2200, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition rpmGauge = RawGaugeDefinition{ .title = "RPM", .unitString = "", .minValue = 0, .maxValue = 2200, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::RPM };


    colorVec = { };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition egtGauge = RawGaugeDefinition{ .title = "", .unitString = "", .minValue = 0, .maxValue = 0, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::NONE };


    colorVec = { ColorZone{ .start = 0, .end = 23.8404, .color = QColor(255, 255, 0) }, ColorZone{ .start = 23.8404, .end = 397.34, .color = QColor(0, 128, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 200, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 300, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 100, .gradText = "100" }, TextGradDef{ .textGradPos = 200, .gradText = "200" }, TextGradDef{ .textGradPos = 300, .gradText = "300" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "L FUEL QTY R", .unitString = "KG", .minValue = 0, .maxValue = 397.34, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 150, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 200, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 250, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 50, .gradText = "50" }, TextGradDef{ .textGradPos = 100, .gradText = "100" }, TextGradDef{ .textGradPos = 150, .gradText = "150" }, TextGradDef{ .textGradPos = 200, .gradText = "200" }, TextGradDef{ .textGradPos = 250, .gradText = "250" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "FUEL FLOW", .unitString = "KGH", .minValue = 0, .maxValue = 585.0 * 0.45359237, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = 0, .end = 104, .color = QColor(0, 128, 0) }, ColorZone{ .start = -40, .end = 0, .color = QColor(255, 255, 0) }, ColorZone{ .start = 104, .end = 120, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "OIL TEMP", .unitString = "ºC", .minValue = -40, .maxValue = 120, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = true, .minRedBlinkThreshold = -40, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 104, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 105.0 * 6.894757, .end = 135.0 * 6.894757, .color = QColor(0, 128, 0) }, ColorZone{ .start = 60.0 * 6.894757, .end = 105.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0, .end = 60.0 * 6.894757, .color = QColor(255, 0, 0) }, ColorZone{ .start = 135.0 * 6.894757, .end = 170.0 * 6.894757, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "OIL PRESS", .unitString = "kPa", .minValue = 0, .maxValue = 170.0 * 6.894757, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = true, .minRedBlinkThreshold = 60.0 * 6.894757, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 135.0 * 6.894757, .noText = false, .unit = Units::KILOPASCAL };

    AircraftDefinition ret{ .type = AircraftDefinition::AircraftType::TURBOPROP, .name = "Daher TBM 930", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = false, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 1, .numTanks = 2, .lowLimit = 0, .flapsBegin = 65, .flapsEnd = 122, .greenBegin = 122, .greenEnd = 266, .yellowBegin = 0, .yellowEnd = 0, .redBegin = 0, .redEnd = 0, .highLimit = 266, .noColors = false, .dynamicBarberpole = false };

    ret.currentType.setValue(TurbopropDefinition(RawTurbopropDefinition{ .n1Gauge = n1Gauge, .trqGauge = trqGauge, .ittGauge = ittGauge, .rpmGauge = rpmGauge, .egtGauge = egtGauge, .hasEgt = false, .usePropRpm = true, .torqueAsPct = true }));

    return ret;
}
