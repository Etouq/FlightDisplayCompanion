#include "aircraftinitializer.h"

AircraftDefinition AircraftInitializer::initSR22()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 500, .end = 2700, .color = QColor(0, 128, 0) }, ColorZone{ .start = 2700, .end = 2800, .color = QColor(255, 255, 0) }, ColorZone{ .start = 2800, .end = 3000, .color = QColor(255, 0, 0) } };
    QVector<GradDef> gradVec = { };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition rpmGauge = RawGaugeDefinition{ .title = "RPM", .unitString = "", .minValue = 0, .maxValue = 3000, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::RPM };


    colorVec = { ColorZone{ .start = 0, .end = 98, .color = QColor(0, 128, 0) }, ColorZone{ .start = 98, .end = 100, .color = QColor(255, 255, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition secondGauge = RawGaugeDefinition{ .title = "LOAD", .unitString = "%", .minValue = 0, .maxValue = 100, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::PERCENT };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 700, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 725, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 750, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 775, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 800, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 825, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 850, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 875, .isBig = false, .gradColor = "white" } };
    textGradVec = { };

    GaugeDefinition egtGauge = RawGaugeDefinition{ .title = "EGT", .unitString = "ºC", .minValue = 1218.0 / 1.8, .maxValue = 1618.0 / 1.8, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0.2 * 110.12, .end = 110.12, .color = QColor(0, 128, 0) }, ColorZone{ .start = 0.1 * 110.12, .end = 0.2 * 110.12, .color = QColor(255, 255, 0) }, ColorZone{ .start = 0, .end = 0.1 * 110.12, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 6, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 12, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 18, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 24, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 36, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 42, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 48, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 54, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 60, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 66, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 72, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 78, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 84, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 90, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 96, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 102, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 108, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 6, .gradText = "6" }, TextGradDef{ .textGradPos = 12, .gradText = "12" }, TextGradDef{ .textGradPos = 18, .gradText = "18" }, TextGradDef{ .textGradPos = 24, .gradText = "24" }, TextGradDef{ .textGradPos = 30, .gradText = "30" }, TextGradDef{ .textGradPos = 36, .gradText = "36" }, TextGradDef{ .textGradPos = 42, .gradText = "42" }, TextGradDef{ .textGradPos = 48, .gradText = "48" }, TextGradDef{ .textGradPos = 54, .gradText = "54" }, TextGradDef{ .textGradPos = 60, .gradText = "60" }, TextGradDef{ .textGradPos = 66, .gradText = "66" }, TextGradDef{ .textGradPos = 72, .gradText = "72" }, TextGradDef{ .textGradPos = 78, .gradText = "78" }, TextGradDef{ .textGradPos = 84, .gradText = "84" }, TextGradDef{ .textGradPos = 90, .gradText = "90" }, TextGradDef{ .textGradPos = 96, .gradText = "96" }, TextGradDef{ .textGradPos = 102, .gradText = "102" }, TextGradDef{ .textGradPos = 108, .gradText = "108" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "L FUEL QTY R", .unitString = "KG", .minValue = 0, .maxValue = 110.12, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { ColorZone{ .start = 30.0 * 0.45359237, .end = 60.0 * 0.45359237, .color = QColor(0, 128, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 60, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 80, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 20, .gradText = "20" }, TextGradDef{ .textGradPos = 40, .gradText = "40" }, TextGradDef{ .textGradPos = 60, .gradText = "60" }, TextGradDef{ .textGradPos = 80, .gradText = "80" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "FUEL FLOW", .unitString = "KGH", .minValue = 0, .maxValue = 180.0 * 0.45359237, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = 98.0 / 1.8, .end = 163.0 / 1.8, .color = QColor(0, 128, 0) }, ColorZone{ .start = 163.0 / 1.8, .end = 168.0 / 1.8, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "OIL TEMP", .unitString = "ºC", .minValue = 68.0 / 1.8, .maxValue = 168.0 / 1.8, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 10.0 * 6.894757, .color = QColor(255, 0, 0) }, ColorZone{ .start = 10.0 * 6.894757, .end = 28.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 28.0 * 6.894757, .end = 60.0 * 6.894757, .color = QColor(0, 128, 0) }, ColorZone{ .start = 60.0 * 6.894757, .end = 115.0 * 6.894757, .color = QColor(255, 255, 0) }, ColorZone{ .start = 115.0 * 6.894757, .end = 120.0 * 6.894757, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "OIL PRESS", .unitString = "kPa", .minValue = 0, .maxValue = 120.0 * 6.894757, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KILOPASCAL };

    AircraftDefinition ret{ .type = AircraftDefinition::AircraftType::PROP, .name = "Cirrus SR22", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = false, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 1, .numTanks = 2, .lowLimit = 0, .flapsBegin = 62, .flapsEnd = 104, .greenBegin = 73, .greenEnd = 177, .yellowBegin = 177, .yellowEnd = 200, .redBegin = 200, .redEnd = 250, .highLimit = 250, .noColors = false, .dynamicBarberpole = false };

    ret.currentType.setValue(PropDefinition(RawPropDefinition{ .rpmGauge = rpmGauge, .secondGauge = secondGauge, .egtGauge = egtGauge, .hasEgt = true, .usePropRpm = true, .secondIsLoad = true, .maxHp = 310 }));

    return ret;
}
