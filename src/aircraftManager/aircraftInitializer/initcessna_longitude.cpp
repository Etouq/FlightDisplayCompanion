#include "aircraftinitializer.hpp"

AircraftDefinition AircraftInitializer::initCESSNA_LONGITUDE()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 0, .end = 100, .color = QColor(0, 128, 0) }, ColorZone{ .start = 100, .end = 110, .color = QColor(255, 0, 0) } };
    QVector<GradDef> gradVec = { };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition n1Gauge = RawGaugeDefinition{ .title = "N1", .unitString = "%", .minValue = 0, .maxValue = 110, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::PERCENT };


    colorVec = { ColorZone{ .start = 0, .end = 98, .color = QColor(0, 128, 0) }, ColorZone{ .start = 98, .end = 100, .color = QColor(255, 255, 0) }, ColorZone{ .start = 100, .end = 110, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition n2Gauge = RawGaugeDefinition{ .title = "N2", .unitString = "%", .minValue = 0, .maxValue = 110, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::PERCENT };


    colorVec = { ColorZone{ .start = 0, .end = 950, .color = QColor(0, 128, 0) }, ColorZone{ .start = 950, .end = 1200, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition ittGauge = RawGaugeDefinition{ .title = "ITT", .unitString = "ºC", .minValue = 0, .maxValue = 1200, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 0.1 * 2939.27, .color = QColor(255, 0, 0) }, ColorZone{ .start = 0.1 * 2939.27, .end = 0.2 * 2939.27, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0.2 * 2939.27, .end = 2939.27, .color = QColor(0, 128, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 2000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 2500, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 500, .gradText = "500" }, TextGradDef{ .textGradPos = 1000, .gradText = "1000" }, TextGradDef{ .textGradPos = 1500, .gradText = "1500" }, TextGradDef{ .textGradPos = 2000, .gradText = "2000" }, TextGradDef{ .textGradPos = 2500, .gradText = "2500" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "L FUEL QTY R", .unitString = "KG", .minValue = 0, .maxValue = 2939.27, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 150, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 300, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 450, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 600, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 150, .gradText = "150" }, TextGradDef{ .textGradPos = 300, .gradText = "300" }, TextGradDef{ .textGradPos = 450, .gradText = "450" }, TextGradDef{ .textGradPos = 600, .gradText = "600" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "L FUEL FLOW R", .unitString = "KGH", .minValue = 0, .maxValue = 1600.0 * 0.45359237, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = 0, .end = 0.1 * 160.0, .color = QColor(255, 0, 0) }, ColorZone{ .start = 0.1 * 160.0, .end = 0.2 * 160.0, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0.2 * 160.0, .end = 0.8 * 160.0, .color = QColor(0, 128, 0) }, ColorZone{ .start = 0.8 * 160.0, .end = 0.9 * 160.0, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0.9 * 160.0, .end = 160, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 25, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 75, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 125, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 150, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 25, .gradText = "25" }, TextGradDef{ .textGradPos = 50, .gradText = "50" }, TextGradDef{ .textGradPos = 75, .gradText = "75" }, TextGradDef{ .textGradPos = 100, .gradText = "100" }, TextGradDef{ .textGradPos = 125, .gradText = "125" }, TextGradDef{ .textGradPos = 150, .gradText = "150" } };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "L OIL TEMP R", .unitString = "ºC", .minValue = 0, .maxValue = 160, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 0.1 * 125.0 * 6.894757, .color = QColor(255, 0, 0) }, ColorZone{ .start = 0.1 * 125.0 * 6.894757, .end = 0.2 * 125.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0.2 * 125.0 * 6.894757, .end = 0.8 * 125.0 * 6.894757, .color = QColor(0, 128, 0) }, ColorZone{ .start = 0.8 * 125.0 * 6.894757, .end = 0.9 * 125.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0.9 * 125.0 * 6.894757, .end = 125.0 * 6.894757, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 150, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 300, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 450, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 600, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 750, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 150, .gradText = "150" }, TextGradDef{ .textGradPos = 300, .gradText = "300" }, TextGradDef{ .textGradPos = 450, .gradText = "450" }, TextGradDef{ .textGradPos = 600, .gradText = "600" }, TextGradDef{ .textGradPos = 750, .gradText = "750" } };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "L OIL PRESS R", .unitString = "kPa", .minValue = 0, .maxValue = 125.0 * 6.894757, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KILOPASCAL };

    AircraftDefinition ret{ .type = AircraftDefinition::AircraftType::JET, .name = "Cessna Citation Longitude", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = true, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 2, .numTanks = 2, .lowLimit = 0, .flapsBegin = 91, .flapsEnd = 200, .greenBegin = 103, .greenEnd = 304, .yellowBegin = 0, .yellowEnd = 0, .redBegin = 0, .redEnd = 0, .highLimit = 304, .noColors = false, .dynamicBarberpole = true };

    ret.currentType.setValue(JetDefinition(RawJetDefinition{ .n1Gauge = n1Gauge, .n2Gauge = n2Gauge, .ittGauge = ittGauge, .hasApu = true, .egtReplacesItt = false}));

    return ret;
}
