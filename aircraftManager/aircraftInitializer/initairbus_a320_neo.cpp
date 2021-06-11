#include "aircraftinitializer.h"

AircraftDefinition AircraftInitializer::initAIRBUS_A320_NEO()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 0, .end = 100, .color = QColor(0, 128, 0)}, ColorZone{ .start = 100, .end = 110, .color = QColor(255, 0, 0)} };
    QVector<GradDef> gradVec = { GradDef{ .gradPos = 50, .isBig = true, .gradColor = "white" }, GradDef{ .gradPos = 60, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 70, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 80, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 90, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = true, .gradColor = "white" } };
    QVector<TextGradDef> textGradVec = { TextGradDef{ .textGradPos = 50, .gradText = "5" }, TextGradDef{ .textGradPos = 100, .gradText = "10" } };

    GaugeDefinition n1Gauge = RawGaugeDefinition{ .title = "N1", .unitString = "%", .minValue = 0, .maxValue = 110, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::PERCENT };


    colorVec = { ColorZone{ .start = 0, .end = 100, .color = QColor(0, 128, 0)}, ColorZone{ .start = 100, .end = 110, .color = QColor(255, 0, 0)} };
    gradVec = { GradDef{ .gradPos = 50, .isBig = true, .gradColor = "white" }, GradDef{ .gradPos = 60, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 70, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 80, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 90, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = true, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 50, .gradText = "5" }, TextGradDef{ .textGradPos = 100, .gradText = "10" } };

    GaugeDefinition n2Gauge = RawGaugeDefinition{ .title = "N2", .unitString = "%", .minValue = 0, .maxValue = 110, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::PERCENT };


    colorVec = { ColorZone{ .start = 0, .end = 850, .color = QColor(0, 128, 0) }, ColorZone{ .start = 850, .end = 1000, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 500, .isBig = false, .gradColor = "white" } };
    textGradVec = { };

    GaugeDefinition ittGauge = RawGaugeDefinition{ .title = "EGT", .unitString = "ºC", .minValue = 0, .maxValue = 1000, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 0.1 * 10636.63, .color = QColor(255, 0, 0)}, ColorZone{ .start = 0.1 * 10636.63, .end = 0.2 * 10636.63, .color = QColor(255, 255, 0)}, ColorZone{ .start = 0.2 * 10636.63, .end = 10636.63, .color = QColor(0, 128, 0)} };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 3000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 4500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 6000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 7500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 9000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 10500, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 1500, .gradText = "1500" }, TextGradDef{ .textGradPos = 3000, .gradText = "3000" }, TextGradDef{ .textGradPos = 4500, .gradText = "4500" }, TextGradDef{ .textGradPos = 6000, .gradText = "6000" }, TextGradDef{ .textGradPos = 7500, .gradText = "7500" }, TextGradDef{ .textGradPos = 9000, .gradText = "9000" }, TextGradDef{ .textGradPos = 10500, .gradText = "10500" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "L FUEL QTY R", .unitString = "KG", .minValue = 0, .maxValue = 10636.63, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = {};
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 200, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 400, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 600, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 800, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 200, .gradText = "200" }, TextGradDef{ .textGradPos = 400, .gradText = "400" }, TextGradDef{ .textGradPos = 600, .gradText = "600" }, TextGradDef{ .textGradPos = 800, .gradText = "800" }, TextGradDef{ .textGradPos = 1000, .gradText = "1000" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "L FUEL FLOW R", .unitString = "KGH", .minValue = 0, .maxValue = 1000, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = 0, .end = 0.001, .color = QColor(255, 0, 0) }, ColorZone{ .start = 0.001, .end = 165, .color = QColor(0, 128, 0) }, ColorZone{ .start = 165, .end = 200, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 60, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 90, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 120, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 150, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 180, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 30, .gradText = "30" }, TextGradDef{ .textGradPos = 60, .gradText = "60" }, TextGradDef{ .textGradPos = 90, .gradText = "90" }, TextGradDef{ .textGradPos = 120, .gradText = "120" }, TextGradDef{ .textGradPos = 150, .gradText = "150" }, TextGradDef{ .textGradPos = 180, .gradText = "180" } };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "L OIL TEMP R", .unitString = "ºC", .minValue = 0, .maxValue = 200, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 17.0 * 6.894757, .color = QColor(255, 0, 0) }, ColorZone{ .start = 17.0 * 6.894757, .end = 25.0 * 6.894757, .color = QColor(219, 114, 0) }, ColorZone{ .start = 25.0 * 6.894757, .end = 100.0 * 6.894757, .color = QColor(0, 128, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 200, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 300, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 400, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 600, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 100, .gradText = "100" }, TextGradDef{ .textGradPos = 200, .gradText = "200" }, TextGradDef{ .textGradPos = 300, .gradText = "300" }, TextGradDef{ .textGradPos = 400, .gradText = "400" }, TextGradDef{ .textGradPos = 500, .gradText = "500" }, TextGradDef{ .textGradPos = 600, .gradText = "600" } };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "L OIL PRESS R", .unitString = "kPa", .minValue = 0, .maxValue = 100.0 * 6.894757, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KILOPASCAL };


    AircraftDefinition ret{.type = AircraftDefinition::AircraftType::JET, .name = "Airbus A320 Neo", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = true, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 2, .numTanks = 2, .lowLimit = 0, .flapsBegin = 0, .flapsEnd = 0, .greenBegin = 0, .greenEnd = 0, .yellowBegin = 0, .yellowEnd = 0, .redBegin = 0, .redEnd = 0, .highLimit = 0, .noColors = false, .dynamicBarberpole = true};

    ret.currentType.setValue(JetDefinition(RawJetDefinition{ .n1Gauge = n1Gauge, .n2Gauge = n2Gauge, .ittGauge = ittGauge, .hasApu = true, .egtReplacesItt = true}));

    return ret;
}
