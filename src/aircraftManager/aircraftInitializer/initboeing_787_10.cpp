#include "aircraftinitializer.hpp"

AircraftDefinition AircraftInitializer::initBOEING_787_10()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 0, .end = 100, .color = QColor(0, 128, 0) }, ColorZone{ .start = 100, .end = 110, .color = QColor(255, 0, 0) } };
    QVector<GradDef> gradVec = { };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition n1Gauge = RawGaugeDefinition{ .title = "N1", .unitString = "%", .minValue = 0, .maxValue = 110, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::PERCENT };


    colorVec = { ColorZone{ .start = 0, .end = 100, .color = QColor(0, 128, 0) }, ColorZone{ .start = 100, .end = 110, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition n2Gauge = RawGaugeDefinition{ .title = "N2", .unitString = "%", .minValue = 0, .maxValue = 110, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::PERCENT };


    colorVec = { ColorZone{ .start = 0, .end = 910, .color = QColor(0, 128, 0) }, ColorZone{ .start = 910, .end = 1000, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition ittGauge = RawGaugeDefinition{ .title = "EGT", .unitString = "ºC", .minValue = 0, .maxValue = 1000, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 0.1 * 45428.175, .color = QColor(255, 0, 0) }, ColorZone{ .start = 0.1 * 45428.175, .end = 0.2 * 45428.175, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0.2 * 45428.175, .end = 45428.175, .color = QColor(0, 128, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 7500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 15000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 22500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 37500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 45000, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 7500, .gradText = "7500" }, TextGradDef{ .textGradPos = 15000, .gradText = "15000" }, TextGradDef{ .textGradPos = 22500, .gradText = "22500" }, TextGradDef{ .textGradPos = 30000, .gradText = "30000" }, TextGradDef{ .textGradPos = 37500, .gradText = "37500" }, TextGradDef{ .textGradPos = 45000, .gradText = "45000" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "L FUEL QTY R", .unitString = "KG", .minValue = 0, .maxValue = 45428.175, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 200, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 400, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 600, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 800, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 200, .gradText = "200" }, TextGradDef{ .textGradPos = 400, .gradText = "400" }, TextGradDef{ .textGradPos = 600, .gradText = "600" }, TextGradDef{ .textGradPos = 800, .gradText = "800" }, TextGradDef{ .textGradPos = 1000, .gradText = "1000" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "L FUEL FLOW R", .unitString = "KGH", .minValue = 0, .maxValue = 1000, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = 0, .end = 35, .color = QColor(255, 0, 0) }, ColorZone{ .start = 35, .end = 165, .color = QColor(0, 128, 0) }, ColorZone{ .start = 165, .end = 200, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 150, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 50, .gradText = "50" }, TextGradDef{ .textGradPos = 100, .gradText = "100" }, TextGradDef{ .textGradPos = 150, .gradText = "150" }, TextGradDef{ .textGradPos = 200, .gradText = "200" } };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "L OIL TEMP R", .unitString = "ºC", .minValue = 0, .maxValue = 200, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 17.0 * 6.894757, .color = QColor(255, 0, 0) }, ColorZone{ .start = 17.0 * 6.894757, .end = 25.0 * 6.894757, .color = QColor(219, 114, 0) }, ColorZone{ .start = 25.0 * 6.894757, .end = 90.0 * 6.894757, .color = QColor(0, 128, 0) }, ColorZone{ .start = 90.0 * 6.894757, .end = 100.0 * 6.894757, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 120, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 240, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 360, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 480, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 600, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 120, .gradText = "120" }, TextGradDef{ .textGradPos = 240, .gradText = "240" }, TextGradDef{ .textGradPos = 360, .gradText = "360" }, TextGradDef{ .textGradPos = 480, .gradText = "480" }, TextGradDef{ .textGradPos = 600, .gradText = "600" } };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "L OIL PRESS R", .unitString = "kPa", .minValue = 0, .maxValue = 100.0 * 6.894757, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KILOPASCAL };



    AircraftDefinition ret{.type = AircraftDefinition::AircraftType::JET, .name = "Boeing 787-10 Dreamliner", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = true, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 2, .numTanks = 2, .lowLimit = 0, .flapsBegin = 0, .flapsEnd = 0, .greenBegin = 0, .greenEnd = 0, .yellowBegin = 0, .yellowEnd = 0, .redBegin = 0, .redEnd = 0, .highLimit = 0, .noColors = false, .dynamicBarberpole = true};

    ret.currentType.setValue(JetDefinition(RawJetDefinition{ .n1Gauge = n1Gauge, .n2Gauge = n2Gauge, .ittGauge = ittGauge, .hasApu = true, .egtReplacesItt = true}));

    return ret;
}
