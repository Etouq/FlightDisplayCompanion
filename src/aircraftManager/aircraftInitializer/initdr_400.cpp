#include "aircraftinitializer.h"

AircraftDefinition AircraftInitializer::initDR_400()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 2000, .end = 2600, .color = QColor(0, 128, 0) }, ColorZone{ .start = 2600, .end = 3000, .color = QColor(255, 0, 0) } };
    QVector<GradDef> gradVec = { };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition rpmGauge = RawGaugeDefinition{ .title = "RPM", .unitString = "", .minValue = 0, .maxValue = 3000, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::RPM };


    colorVec = { ColorZone{ .start = 0, .end = 92, .color = QColor(0, 128, 0) }, ColorZone{ .start = 92, .end = 100, .color = QColor(255, 255, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition secondGauge = RawGaugeDefinition{ .title = "LOAD", .unitString = "%", .minValue = 0, .maxValue = 100, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::PERCENT };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 700, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 725, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 750, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 775, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 800, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 825, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 850, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 875, .isBig = false, .gradColor = "white" } };
    textGradVec = { };

    GaugeDefinition egtGauge = RawGaugeDefinition{ .title = "EGT", .unitString = "ºC", .minValue = 1218.0 / 1.8, .maxValue = 1618.0 / 1.8, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0.2 * 78.92, .end = 78.92, .color = QColor(0, 128, 0) }, ColorZone{ .start = 0.1 * 78.92, .end = 0.2 * 78.92, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0, .end = 0.1 * 78.92, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 10, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 60, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 70, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 10, .gradText = "10" }, TextGradDef{ .textGradPos = 20, .gradText = "20" }, TextGradDef{ .textGradPos = 30, .gradText = "30" }, TextGradDef{ .textGradPos = 40, .gradText = "40" }, TextGradDef{ .textGradPos = 50, .gradText = "50" }, TextGradDef{ .textGradPos = 60, .gradText = "60" }, TextGradDef{ .textGradPos = 70, .gradText = "70" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "FUEL QTY", .unitString = "KG", .minValue = 0, .maxValue = 78.92, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 5, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 10, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 15, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 5, .gradText = "5" }, TextGradDef{ .textGradPos = 10, .gradText = "10" }, TextGradDef{ .textGradPos = 15, .gradText = "15" }, TextGradDef{ .textGradPos = 20, .gradText = "20" }, TextGradDef{ .textGradPos = 25, .gradText = "25" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "FUEL FLOW", .unitString = "KGH", .minValue = 0, .maxValue = 25, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = 103.0 / 1.8, .end = 198.0 / 1.8, .color = QColor(0, 128, 0) }, ColorZone{ .start = 198.0 / 1.8, .end = 228.0 / 1.8, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "OIL TEMP", .unitString = "ºC", .minValue = 68.0 / 1.8, .maxValue = 228.0 / 1.8, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 90, .color = QColor(255, 0, 0) }, ColorZone{ .start = 90, .end = 250, .color = QColor(255, 255, 0) }, ColorZone{ .start = 250, .end = 600, .color = QColor(0, 128, 0) }, ColorZone{ .start = 600, .end = 650, .color = QColor(255, 255, 0) }, ColorZone{ .start = 650, .end = 700, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "OIL PRESS", .unitString = "kPa", .minValue = 0, .maxValue = 700, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = true, .minRedBlinkThreshold = 90, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 650, .noText = false, .unit = Units::KILOPASCAL };

    AircraftDefinition ret{ .type = AircraftDefinition::AircraftType::PROP, .name = "Robin DR400/100 Cadet", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = false, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 1, .numTanks = 1, .lowLimit = 0, .flapsBegin = 46, .flapsEnd = 92, .greenBegin = 51, .greenEnd = 140, .yellowBegin = 140, .yellowEnd = 166, .redBegin = 166, .redEnd = 167, .highLimit = 167, .noColors = false, .dynamicBarberpole = false };

    ret.currentType.setValue(PropDefinition(RawPropDefinition{ .rpmGauge = rpmGauge, .secondGauge = secondGauge, .egtGauge = egtGauge, .hasEgt = true, .usePropRpm = false, .secondIsLoad = true, .maxHp = 118 }));

    return ret;
}
