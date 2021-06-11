#include "aircraftinitializer.h"

AircraftDefinition AircraftInitializer::initBEECHCRAFT_KING_AIR_350I()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 0, .end = 100, .color = QColor(0, 128, 0) }, ColorZone{ .start = 100, .end = 110, .color = QColor(255, 0, 0) } };
    QVector<GradDef> gradVec = { };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition n1Gauge = RawGaugeDefinition{ .title = "N1", .unitString = "%", .minValue = 0, .maxValue = 110, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::PERCENT };


    colorVec = { ColorZone{ .start = 0, .end = 100, .color = QColor(0, 128, 0) }, ColorZone{ .start = 100, .end = 110, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition trqGauge = RawGaugeDefinition{ .title = "TRQ", .unitString = "%", .minValue = 0, .maxValue = 110, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 100, .noText = false, .unit = Units::PERCENT };


    colorVec = { ColorZone{ .start = 0, .end = 850, .color = QColor(0, 128, 0) }, ColorZone{ .start = 840, .end = 900, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 150, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 300, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 450, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 600, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 750, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 150, .gradText = "150" }, TextGradDef{ .textGradPos = 300, .gradText = "300" }, TextGradDef{ .textGradPos = 450, .gradText = "450" }, TextGradDef{ .textGradPos = 600, .gradText = "600" }, TextGradDef{ .textGradPos = 750, .gradText = "750" }, TextGradDef{ .textGradPos = 900, .gradText = "900" } };

    GaugeDefinition ittGauge = RawGaugeDefinition{ .title = "L ITT R", .unitString = "ºC", .minValue = 0, .maxValue = 900, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 870, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 1950, .end = 2050, .color = QColor(0, 128, 0) }, ColorZone{ .start = 400, .end = 1000, .color = QColor(255, 255, 0) }, ColorZone{ .start = 2050, .end = 2200, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 400, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 800, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1200, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1600, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 2000, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 400, .gradText = "400" }, TextGradDef{ .textGradPos = 800, .gradText = "800" }, TextGradDef{ .textGradPos = 1200, .gradText = "1200" }, TextGradDef{ .textGradPos = 1600, .gradText = "1600" }, TextGradDef{ .textGradPos = 2000, .gradText = "2000" } };

    GaugeDefinition rpmGauge = RawGaugeDefinition{ .title = "L RPM R", .unitString = "", .minValue = 0, .maxValue = 2200, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 2050, .noText = false, .unit = Units::RPM };


    colorVec = { };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition egtGauge = RawGaugeDefinition{ .title = "", .unitString = "", .minValue = 0, .maxValue = 0, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::NONE };


    colorVec = { ColorZone{ .start = 0, .end = 733.45 * 0.18, .color = QColor(255, 255, 0) }, ColorZone{ .start = 733.45 * 0.18, .end = 733.45, .color = QColor(0, 128, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 125, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 250, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 375, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 625, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 125, .gradText = "125" }, TextGradDef{ .textGradPos = 250, .gradText = "250" }, TextGradDef{ .textGradPos = 375, .gradText = "375" }, TextGradDef{ .textGradPos = 500, .gradText = "500" }, TextGradDef{ .textGradPos = 625, .gradText = "625" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "L FUEL QTY R", .unitString = "KG", .minValue = 0, .maxValue = 733.45, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 25, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 75, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 125, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 25, .gradText = "25" }, TextGradDef{ .textGradPos = 50, .gradText = "50" }, TextGradDef{ .textGradPos = 75, .gradText = "75" }, TextGradDef{ .textGradPos = 100, .gradText = "100" }, TextGradDef{ .textGradPos = 125, .gradText = "125" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "L FUEL FLOW R", .unitString = "KGH", .minValue = 0, .maxValue = 292.5 * 0.45359237, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = 10, .end = 100, .color = QColor(0, 128, 0) }, ColorZone{ .start = -40, .end = 10, .color = QColor(255, 255, 0) }, ColorZone{ .start = 100, .end = 105, .color = QColor(255, 255, 0) }, ColorZone{ .start = -50, .end = -40, .color = QColor(255, 0, 0) }, ColorZone{ .start = 105, .end = 120, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = -50, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = -20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 10, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 70, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = -50, .gradText = "-50" }, TextGradDef{ .textGradPos = -20, .gradText = "-20" }, TextGradDef{ .textGradPos = 10, .gradText = "10" }, TextGradDef{ .textGradPos = 40, .gradText = "40" }, TextGradDef{ .textGradPos = 70, .gradText = "70" }, TextGradDef{ .textGradPos = 100, .gradText = "100" } };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "L OIL TEMP R", .unitString = "ºC", .minValue = -50, .maxValue = 120, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = true, .minRedBlinkThreshold = -41, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 105, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 85.0 * 6.894757, .end = 105.0 * 6.894757, .color = QColor(0, 128, 0) }, ColorZone{ .start = 40.0 * 6.894757, .end = 85.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0, .end = 40.0 * 6.894757, .color = QColor(255, 0, 0) }, ColorZone{ .start = 105.0 * 6.894757, .end = 120.0 * 6.894757, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 150, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 300, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 450, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 600, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 750, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 150, .gradText = "150" }, TextGradDef{ .textGradPos = 300, .gradText = "300" }, TextGradDef{ .textGradPos = 450, .gradText = "450" }, TextGradDef{ .textGradPos = 600, .gradText = "600" }, TextGradDef{ .textGradPos = 750, .gradText = "750" } };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "L OIL PRESS R", .unitString = "kPa", .minValue = 0, .maxValue = 120.0 * 6.894757, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = true, .minRedBlinkThreshold = 40.0 * 6.894757, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 101.6 * 6.894757, .noText = false, .unit = Units::KILOPASCAL };

    AircraftDefinition ret{ .type = AircraftDefinition::AircraftType::TURBOPROP, .name = "Beechcraft King Air 350i", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = false, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 2, .numTanks = 2, .lowLimit = 0, .flapsBegin = 82, .flapsEnd = 158, .greenBegin = 99, .greenEnd = 245, .yellowBegin = 0, .yellowEnd = 0, .redBegin = 245, .redEnd = 350, .highLimit = 350, .noColors = false, .dynamicBarberpole = false };

    ret.currentType.setValue(TurbopropDefinition(RawTurbopropDefinition{ .n1Gauge = n1Gauge, .trqGauge = trqGauge, .ittGauge = ittGauge, .rpmGauge = rpmGauge, .egtGauge = egtGauge, .hasEgt = false, .usePropRpm = true, .torqueAsPct = true }));

    return ret;
}
