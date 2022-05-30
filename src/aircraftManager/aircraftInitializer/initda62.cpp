#include "aircraftinitializer.hpp"

AircraftDefinition AircraftInitializer::initDA62()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 0, .end = 2325, .color = QColor(0, 128, 0) }, ColorZone{ .start = 2325, .end = 2375, .color = QColor(255, 255, 0) }, ColorZone{ .start = 2375, .end = 3000, .color = QColor(255, 0, 0) } };
    QVector<GradDef> gradVec = { };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition rpmGauge = RawGaugeDefinition{ .title = "RPM", .unitString = "", .minValue = 0, .maxValue = 3000, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::RPM };


    colorVec = { ColorZone{ .start = 0, .end = 95, .color = QColor(0, 128, 0) }, ColorZone{ .start = 95, .end = 100, .color = QColor(255, 255, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition secondGauge = RawGaugeDefinition{ .title = "LOAD", .unitString = "%", .minValue = 0, .maxValue = 100, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::PERCENT };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 700, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 725, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 750, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 775, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 800, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 825, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 850, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 875, .isBig = false, .gradColor = "white" } };
    textGradVec = { };

    GaugeDefinition egtGauge = RawGaugeDefinition{ .title = "EGT", .unitString = "ºC", .minValue = 1218.0 / 1.8, .maxValue = 1618.0 / 1.8, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 4.844, .end = 121.1, .color = QColor(0, 128, 0) }, ColorZone{ .start = 0, .end = 4.844, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 25, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 50, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 75, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 100, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 25, .gradText = "25" }, TextGradDef{ .textGradPos = 50, .gradText = "50" }, TextGradDef{ .textGradPos = 75, .gradText = "75" }, TextGradDef{ .textGradPos = 100, .gradText = "100" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "L FUEL QTY R", .unitString = "KG", .minValue = 0, .maxValue = 121.1, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 10, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 10, .gradText = "10" }, TextGradDef{ .textGradPos = 20, .gradText = "20" }, TextGradDef{ .textGradPos = 30, .gradText = "30" }, TextGradDef{ .textGradPos = 40, .gradText = "40" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "L FUEL FLOW R", .unitString = "KGH", .minValue = 0, .maxValue = 90.0 * 0.45359237, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = -35, .end = -30, .color = QColor(255, 0, 0) }, ColorZone{ .start = -30, .end = 50, .color = QColor(255, 255, 0) }, ColorZone{ .start = 50, .end = 135, .color = QColor(0, 128, 0) }, ColorZone{ .start = 135, .end = 140, .color = QColor(255, 255, 0) }, ColorZone{ .start = 140, .end = 145, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = -35, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = -5, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 25, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 55, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 85, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 115, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = -35, .gradText = "-35" }, TextGradDef{ .textGradPos = -5, .gradText = "-5" }, TextGradDef{ .textGradPos = 25, .gradText = "25" }, TextGradDef{ .textGradPos = 55, .gradText = "55" }, TextGradDef{ .textGradPos = 85, .gradText = "85" }, TextGradDef{ .textGradPos = 115, .gradText = "115" }, TextGradDef{ .textGradPos = 145, .gradText = "145" } };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "L OIL TEMP R", .unitString = "ºC", .minValue = -35, .maxValue = 145, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = true, .minRedBlinkThreshold = -30, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 140, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 90, .color = QColor(255, 0, 0) }, ColorZone{ .start = 90, .end = 250, .color = QColor(255, 255, 0) }, ColorZone{ .start = 250, .end = 600, .color = QColor(0, 128, 0) }, ColorZone{ .start = 600, .end = 650, .color = QColor(255, 255, 0) }, ColorZone{ .start = 650, .end = 700, .color = QColor(255, 0, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 150, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 300, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 450, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 600, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 150, .gradText = "150" }, TextGradDef{ .textGradPos = 300, .gradText = "300" }, TextGradDef{ .textGradPos = 450, .gradText = "450" }, TextGradDef{ .textGradPos = 600, .gradText = "600" } };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "L OIL PRESS R", .unitString = "kPa", .minValue = 0, .maxValue = 700, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = true, .minRedBlinkThreshold = 90, .hasMaxRedBlink = true, .maxRedBlinkThreshold = 650, .noText = false, .unit = Units::KILOPASCAL };

    AircraftDefinition ret{ .type = AircraftDefinition::AircraftType::PROP, .name = "DA62", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = false, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 2, .numTanks = 2, .lowLimit = 0, .flapsBegin = 64, .flapsEnd = 119, .greenBegin = 70, .greenEnd = 162, .yellowBegin = 162, .yellowEnd = 204, .redBegin = 0, .redEnd = 0, .highLimit = 204, .noColors = false, .dynamicBarberpole = false };

    ret.currentType.setValue(PropDefinition(RawPropDefinition{ .rpmGauge = rpmGauge, .secondGauge = secondGauge, .egtGauge = egtGauge, .hasEgt = true, .usePropRpm = true, .secondIsLoad = true, .maxHp = 180 }));

    return ret;
}
