#include "aircraftinitializer.h"

AircraftDefinition AircraftInitializer::initCESSNA_208B_GRAND_CARAVAN_EX()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 51, .end = 101.6, .color = QColor(0, 128, 0) } };
    QVector<GradDef> gradVec = { GradDef{ .gradPos = 10, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 60, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 70, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 80, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 90, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 101.6, .isBig = true, .gradColor = QColor(255, 0, 0) } };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition n1Gauge = RawGaugeDefinition{ .title = "N1", .unitString = "%", .minValue = 0, .maxValue = 110, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 101.6, .noText = false, .unit = Units::PERCENT };


    colorVec = { ColorZone{ .start = 0, .end = 2396.0 * 1.355818, .color = QColor(0, 128, 0) }, ColorZone{ .start = 2396.0 * 1.355818, .end = 2600.0 * 1.355818, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 250, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 750, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1250, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1750, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 2000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 2250, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 2500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 2750, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 3000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 3500, .isBig = false, .gradColor = "white" } };
    textGradVec = { };

    GaugeDefinition trqGauge = RawGaugeDefinition{ .title = "TRQ", .unitString = "N·M", .minValue = 0, .maxValue = 2600.0 * 1.355818, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 2400.0 * 1.355818, .noText = false, .unit = Units::NEWTONMETER };


    colorVec = { ColorZone{ .start = 100, .end = 805, .color = QColor(0, 128, 0) }, ColorZone{ .start = 805, .end = 835, .color = QColor(255, 255, 0) } };
    gradVec = { GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 150, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 200, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 250, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 300, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 350, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 400, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 450, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 500, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 550, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 600, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 650, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 700, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 750, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 800, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 835, .isBig = true, .gradColor = QColor(255, 0, 0) }, GradDef{ .gradPos = 850, .isBig = false, .gradColor = "white" } };
    textGradVec = { };

    GaugeDefinition ittGauge = RawGaugeDefinition{ .title = "ITT", .unitString = "ºC", .minValue = 0, .maxValue = 900, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 835, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 1600, .color = QColor(255, 255, 255) }, ColorZone{ .start = 1600, .end = 1900, .color = QColor(0, 128, 0) }, ColorZone{ .start = 1900, .end = 2500, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition rpmGauge = RawGaugeDefinition{ .title = "RPM", .unitString = "", .minValue = 0, .maxValue = 2500, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::RPM };


    colorVec = { };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition egtGauge = RawGaugeDefinition{ .title = "", .unitString = "", .minValue = 0, .maxValue = 0, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::NONE };


    colorVec = { ColorZone{ .start = 0, .end = 25.0 * 0.45359237, .color = QColor(255, 0, 0) }, ColorZone{ .start = 25.0 * 0.45359237, .end = 1100.0 * 0.45359237, .color = QColor(0, 128, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 200, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 300, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 400, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 100, .gradText = "100" }, TextGradDef{ .textGradPos = 200, .gradText = "200" }, TextGradDef{ .textGradPos = 300, .gradText = "300" }, TextGradDef{ .textGradPos = 400, .gradText = "400" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "L FUEL QTY R", .unitString = "KG", .minValue = 0, .maxValue = 1100.0 * 0.45359237, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 150, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 50, .gradText = "50" }, TextGradDef{ .textGradPos = 100, .gradText = "100" }, TextGradDef{ .textGradPos = 150, .gradText = "150" }, TextGradDef{ .textGradPos = 200, .gradText = "200" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "FUEL FLOW", .unitString = "KGH", .minValue = 0, .maxValue = 200, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = 10, .end = 100, .color = QColor(0, 128, 0) }, ColorZone{ .start = -40, .end = 10, .color = QColor(255, 255, 0) }, ColorZone{ .start = 100, .end = 105, .color = QColor(255, 255, 0) } };
    gradVec = { GradDef{ .gradPos = -41, .isBig = true, .gradColor = QColor(255, 0, 0) }, GradDef{ .gradPos = 105, .isBig = true, .gradColor = QColor(255, 0, 0) } };
    textGradVec = { };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "OIL TEMP", .unitString = "ºC", .minValue = -50, .maxValue = 120, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = true, .minRedBlinkThreshold = -41, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 105, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 85.0 * 6.894757, .end = 105.0 * 6.894757, .color = QColor(0, 128, 0) }, ColorZone{ .start = 40.0 * 6.894757, .end = 85.0 * 6.894757, .color = QColor(255, 255, 0) } };
    gradVec = { GradDef{ .gradPos = 40.0 * 6.894757, .isBig = true, .gradColor = QColor(255, 0, 0) }, GradDef{ .gradPos = 105.0 * 6.894757, .isBig = true, .gradColor = QColor(255, 0, 0) } };
    textGradVec = { };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "OIL PRESS", .unitString = "kPa", .minValue = 0, .maxValue = 120.0 * 6.894757, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = true, .minRedBlinkThreshold = 40.0 * 6.894757, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 101.6 * 6.894757, .noText = false, .unit = Units::KILOPASCAL };

    AircraftDefinition ret{ .type = AircraftDefinition::AircraftType::TURBOPROP, .name = "Cessna 208 B Grand Caravan EX", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = false, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 1, .numTanks = 2, .lowLimit = 0, .flapsBegin = 50, .flapsEnd = 125, .greenBegin = 63, .greenEnd = 175, .yellowBegin = 0, .yellowEnd = 0, .redBegin = 20, .redEnd = 50, .highLimit = 175, .noColors = false, .dynamicBarberpole = false };

    ret.currentType.setValue(TurbopropDefinition(RawTurbopropDefinition{ .n1Gauge = n1Gauge, .trqGauge = trqGauge, .ittGauge = ittGauge, .rpmGauge = rpmGauge, .egtGauge = egtGauge, .hasEgt = false, .usePropRpm = true, .torqueAsPct = false }));

    return ret;
}
