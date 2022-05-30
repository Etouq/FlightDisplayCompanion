#include "aircraftinitializer.hpp"

AircraftDefinition AircraftInitializer::initFLIGHTDESIGNCT()
{
    QVector<ColorZone> colorVec = { ColorZone{ .start = 0, .end = 1500, .color = QColor(255, 0, 0) }, ColorZone{ .start = 1500, .end = 1800, .color = QColor(255, 255, 0) }, ColorZone{ .start = 1800, .end = 5450, .color = QColor(0, 128, 0) }, ColorZone{ .start = 5450, .end = 5800, .color = QColor(255, 255, 0) }, ColorZone{ .start = 5800, .end = 6000, .color = QColor(255, 0, 0) } };
    QVector<GradDef> gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 1000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 2000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 3000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 4000, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 5000, .isBig = false, .gradColor = "white" } };
    QVector<TextGradDef> textGradVec = { };

    GaugeDefinition rpmGauge = RawGaugeDefinition{ .title = "RPM", .unitString = "", .minValue = 0, .maxValue = 6000, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::RPM };


    colorVec = { ColorZone{ .start = 0, .end = 92, .color = QColor(0, 128, 0) }, ColorZone{ .start = 92, .end = 100, .color = QColor(255, 255, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition secondGauge = RawGaugeDefinition{ .title = "LOAD", .unitString = "%", .minValue = 0, .maxValue = 100, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::PERCENT };


    colorVec = { };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition egtGauge = RawGaugeDefinition{ .title = "", .unitString = "", .minValue = 0, .maxValue = 0, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::NONE };


    colorVec = { ColorZone{ .start = 0.2 * 46.26, .end = 46.26, .color = QColor(0, 128, 0) }, ColorZone{ .start = 0, .end = 0.2 * 46.26, .color = QColor(255, 255, 0) } };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 10, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 10, .gradText = "10" }, TextGradDef{ .textGradPos = 20, .gradText = "20" }, TextGradDef{ .textGradPos = 30, .gradText = "30" }, TextGradDef{ .textGradPos = 40, .gradText = "40" } };

    GaugeDefinition fuelQtyGauge = RawGaugeDefinition{ .title = "L FUEL QTY R", .unitString = "KG", .minValue = 0, .maxValue = 46.26, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG };


    colorVec = { };
    gradVec = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 10, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 20, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 30, .isBig = false, .gradColor = "white" }, GradDef{ .gradPos = 40, .isBig = false, .gradColor = "white" } };
    textGradVec = { TextGradDef{ .textGradPos = 0, .gradText = "0" }, TextGradDef{ .textGradPos = 10, .gradText = "10" }, TextGradDef{ .textGradPos = 20, .gradText = "20" }, TextGradDef{ .textGradPos = 30, .gradText = "30" }, TextGradDef{ .textGradPos = 40, .gradText = "40" } };

    GaugeDefinition fuelFlowGauge = RawGaugeDefinition{ .title = "FUEL FLOW", .unitString = "KGH", .minValue = 0, .maxValue = 45, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KG_PER_HOUR };


    colorVec = { ColorZone{ .start = 40, .end = 49, .color = QColor(255, 0, 0) }, ColorZone{ .start = 49, .end = 89, .color = QColor(255, 255, 0) }, ColorZone{ .start = 89, .end = 110, .color = QColor(0, 128, 0) }, ColorZone{ .start = 110, .end = 130, .color = QColor(255, 255, 0) }, ColorZone{ .start = 130, .end = 150, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilTempGauge = RawGaugeDefinition{ .title = "OIL TEMP", .unitString = "ºC", .minValue = 40, .maxValue = 150, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::CELSIUS };


    colorVec = { ColorZone{ .start = 0, .end = 90, .color = QColor(255, 0, 0) }, ColorZone{ .start = 90, .end = 200, .color = QColor(255, 255, 0) }, ColorZone{ .start = 200, .end = 500, .color = QColor(0, 128, 0) }, ColorZone{ .start = 500, .end = 700, .color = QColor(255, 255, 0) }, ColorZone{ .start = 700, .end = 800, .color = QColor(255, 0, 0) } };
    gradVec = { };
    textGradVec = { };

    GaugeDefinition oilPressGauge = RawGaugeDefinition{ .title = "OIL PRESS", .unitString = "kPa", .minValue = 0, .maxValue = 800, .colorZones = colorVec, .grads = gradVec, .textGrads = textGradVec, .textIncrement = 1, .textNumDigits = 0, .forceTextColor = false, .textForcedColor = QColor(), .hasMinRedBlink = false, .minRedBlinkThreshold = 0, .hasMaxRedBlink = false, .maxRedBlinkThreshold = 0, .noText = false, .unit = Units::KILOPASCAL };

    AircraftDefinition ret{ .type = AircraftDefinition::AircraftType::PROP, .name = "Flight Design CTSL", .fuelQtyGauge = fuelQtyGauge, .fuelFlowGauge = fuelFlowGauge, .oilTempGauge = oilTempGauge, .oilPressGauge = oilPressGauge, .hasFlaps = true, .hasSpoilers = false, .hasElevatorTrim = true, .hasRudderTrim = true, .hasAileronTrim = true, .fuelQtyByVolume = false, .fuelFlowByVolume = false, .numEngines = 1, .numTanks = 2, .lowLimit = 0, .flapsBegin = 35, .flapsEnd = 62, .greenBegin = 40, .greenEnd = 120, .yellowBegin = 120, .yellowEnd = 161, .redBegin = 161, .redEnd = 162, .highLimit = 162, .noColors = false, .dynamicBarberpole = false };

    ret.currentType.setValue(PropDefinition(RawPropDefinition{ .rpmGauge = rpmGauge, .secondGauge = secondGauge, .egtGauge = egtGauge, .hasEgt = false, .usePropRpm = true, .secondIsLoad = true, .maxHp = 100 }));

    return ret;

}
