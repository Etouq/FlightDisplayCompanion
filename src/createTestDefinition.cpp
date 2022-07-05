#include "main.hpp"
#include "common/definitions/AircraftDefinition/AircraftDefinition.hpp"

using namespace definitions;

AircraftDefinition createTestDefinition()
{
    QList<ColorZone> colorZones = { ColorZone{ .start = 0, .end = 100, .color = Qt::darkGreen },
                                    ColorZone{ .start = 100, .end = 110, .color = Qt::red } };
    QList<GradDef> grads = { GradDef{ .gradPos = 50, .isBig = true, .gradColor = Qt::white },
                             GradDef{ .gradPos = 60, .isBig = false, .gradColor = Qt::white },
                             GradDef{ .gradPos = 70, .isBig = false, .gradColor = Qt::white },
                             GradDef{ .gradPos = 80, .isBig = false, .gradColor = Qt::white },
                             GradDef{ .gradPos = 90, .isBig = false, .gradColor = Qt::white },
                             GradDef{ .gradPos = 100, .isBig = true, .gradColor = Qt::white } };
    QList<TextGradDef> textGrads = { TextGradDef{ .textGradPos = 50, .gradText = "5" },
                                     TextGradDef{ .textGradPos = 100, .gradText = "10" } };

    GaugeDefinition firstGauge = { .title = "N1",
                                   .unitString = "%",
                                   .minValue = 0,
                                   .maxValue = 110,
                                   .colorZones = colorZones,
                                   .grads = grads,
                                   .textGrads = textGrads,
                                   .hasMaxRedBlink = true,
                                   .maxRedBlinkThreshold = 100,
                                   .unit = Units::PERCENT };

    GaugeDefinition secondGauge = { .title = "TRQ",
                                    .unitString = "%",
                                    .minValue = 0,
                                    .maxValue = 110,
                                    .colorZones = colorZones,
                                    .grads = grads,
                                    .textGrads = textGrads,
                                    .hasMaxRedBlink = true,
                                    .maxRedBlinkThreshold = 100,
                                    .unit = Units::PERCENT };

    colorZones = { ColorZone{ .start = 0, .end = 850, .color = Qt::darkGreen },
                   ColorZone{ .start = 840, .end = 900, .color = Qt::red } };
    grads = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 150, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 300, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 450, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 600, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 750, .isBig = false, .gradColor = Qt::white } };
    textGrads = {
        TextGradDef{ .textGradPos = 0, .gradText = "0" },     TextGradDef{ .textGradPos = 150, .gradText = "150" },
        TextGradDef{ .textGradPos = 300, .gradText = "300" }, TextGradDef{ .textGradPos = 450, .gradText = "450" },
        TextGradDef{ .textGradPos = 600, .gradText = "600" }, TextGradDef{ .textGradPos = 750, .gradText = "750" },
        TextGradDef{ .textGradPos = 900, .gradText = "900" }
    };


    GaugeDefinition thirdGauge = { .title = "L ITT R",
                                   .unitString = "ºC",
                                   .minValue = 0,
                                   .maxValue = 900,
                                   .colorZones = colorZones,
                                   .grads = grads,
                                   .textGrads = textGrads,
                                   .hasMaxRedBlink = true,
                                   .maxRedBlinkThreshold = 870,
                                   .unit = Units::CELSIUS };

    colorZones = { ColorZone{ .start = 1950, .end = 2050, .color = Qt::darkGreen },
                   ColorZone{ .start = 400, .end = 1000, .color = Qt::yellow },
                   ColorZone{ .start = 2050, .end = 2200, .color = Qt::red } };
    grads = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 400, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 800, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 1200, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 1600, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 2000, .isBig = false, .gradColor = Qt::white } };
    textGrads = {
        TextGradDef{ .textGradPos = 0, .gradText = "0" },       TextGradDef{ .textGradPos = 400, .gradText = "400" },
        TextGradDef{ .textGradPos = 800, .gradText = "800" },   TextGradDef{ .textGradPos = 1200, .gradText = "1200" },
        TextGradDef{ .textGradPos = 1600, .gradText = "1600" }, TextGradDef{ .textGradPos = 2000, .gradText = "2000" }
    };


    GaugeDefinition fourthGauge = { .title = "L RPM R",
                                    .unitString = "",
                                    .minValue = 0,
                                    .maxValue = 2200,
                                    .colorZones = colorZones,
                                    .grads = grads,
                                    .textGrads = textGrads,
                                    .hasMaxRedBlink = true,
                                    .maxRedBlinkThreshold = 2050,
                                    .unit = Units::RPM };

    colorZones = { ColorZone{ .start = 0, .end = 733.45 * 0.18, .color = Qt::yellow },
                   ColorZone{ .start = 733.45 * 0.18, .end = 733.45, .color = Qt::darkGreen } };
    grads = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 125, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 250, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 375, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 500, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 625, .isBig = false, .gradColor = Qt::white } };
    textGrads = {
        TextGradDef{ .textGradPos = 0, .gradText = "0" },     TextGradDef{ .textGradPos = 125, .gradText = "125" },
        TextGradDef{ .textGradPos = 250, .gradText = "250" }, TextGradDef{ .textGradPos = 375, .gradText = "375" },
        TextGradDef{ .textGradPos = 500, .gradText = "500" }, TextGradDef{ .textGradPos = 625, .gradText = "625" }
    };


    GaugeDefinition fuelQtyGauge = { .title = "L FUEL QTY R",
                                     .unitString = "KG",
                                     .minValue = 0,
                                     .maxValue = 733.45,
                                     .colorZones = colorZones,
                                     .grads = grads,
                                     .textGrads = textGrads,
                                     .unit = Units::KG };

    colorZones = {};
    grads = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 25, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 50, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 75, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 100, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 125, .isBig = false, .gradColor = Qt::white } };
    textGrads = {
        TextGradDef{ .textGradPos = 0, .gradText = "0" },     TextGradDef{ .textGradPos = 25, .gradText = "25" },
        TextGradDef{ .textGradPos = 50, .gradText = "50" },   TextGradDef{ .textGradPos = 75, .gradText = "75" },
        TextGradDef{ .textGradPos = 100, .gradText = "100" }, TextGradDef{ .textGradPos = 125, .gradText = "125" }
    };

    GaugeDefinition fuelFlowGauge = { .title = "L FUEL FLOW R",
                                      .unitString = "KGH",
                                      .minValue = 0,
                                      .maxValue = 292.5 * 0.45359237,
                                      .colorZones = colorZones,
                                      .grads = grads,
                                      .textGrads = textGrads,
                                      .unit = Units::KG_PER_HOUR };


    colorZones = { ColorZone{ .start = 10, .end = 100, .color = Qt::darkGreen },
                   ColorZone{ .start = -40, .end = 10, .color = Qt::yellow },
                   ColorZone{ .start = 100, .end = 105, .color = Qt::yellow },
                   ColorZone{ .start = -50, .end = -40, .color = Qt::red },
                   ColorZone{ .start = 105, .end = 120, .color = Qt::red } };
    grads = { GradDef{ .gradPos = -50, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = -20, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 10, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 40, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 70, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 100, .isBig = false, .gradColor = Qt::white } };
    textGrads = {
        TextGradDef{ .textGradPos = -50, .gradText = "-50" }, TextGradDef{ .textGradPos = -20, .gradText = "-20" },
        TextGradDef{ .textGradPos = 10, .gradText = "10" },   TextGradDef{ .textGradPos = 40, .gradText = "40" },
        TextGradDef{ .textGradPos = 70, .gradText = "70" },   TextGradDef{ .textGradPos = 100, .gradText = "100" }
    };

    GaugeDefinition oilTempGauge = { .title = "L OIL TEMP R",
                                     .unitString = "ºC",
                                     .minValue = -50,
                                     .maxValue = 120,
                                     .colorZones = colorZones,
                                     .grads = grads,
                                     .textGrads = textGrads,
                                     .hasMinRedBlink = true,
                                     .minRedBlinkThreshold = -41,
                                     .hasMaxRedBlink = true,
                                     .maxRedBlinkThreshold = 105,
                                     .unit = Units::CELSIUS };

    colorZones = {};
    grads = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 100, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 200, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 300, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 400, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 500, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 600, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 700, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 800, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 900, .isBig = false, .gradColor = Qt::white } };
    textGrads = {
        TextGradDef{ .textGradPos = 0, .gradText = "0" },     TextGradDef{ .textGradPos = 100, .gradText = "100" },
        TextGradDef{ .textGradPos = 200, .gradText = "200" }, TextGradDef{ .textGradPos = 300, .gradText = "300" },
        TextGradDef{ .textGradPos = 400, .gradText = "400" }, TextGradDef{ .textGradPos = 500, .gradText = "500" },
        TextGradDef{ .textGradPos = 600, .gradText = "600" }, TextGradDef{ .textGradPos = 700, .gradText = "700" },
        TextGradDef{ .textGradPos = 800, .gradText = "800" }, TextGradDef{ .textGradPos = 900, .gradText = "900" }
    };

    GaugeDefinition secondaryTempGauge = { .title = "L EGT R",
                                           .unitString = "ºC",
                                           .minValue = 0,
                                           .maxValue = 1628.0 / 1.8,
                                           .colorZones = colorZones,
                                           .grads = grads,
                                           .textGrads = textGrads,
                                           .unit = Units::CELSIUS };


    colorZones = { ColorZone{ .start = 85.0 * 6.894757, .end = 105.0 * 6.894757, .color = Qt::darkGreen },
                   ColorZone{ .start = 40.0 * 6.894757, .end = 85.0 * 6.894757, .color = Qt::yellow },
                   ColorZone{ .start = 0, .end = 40.0 * 6.894757, .color = Qt::red },
                   ColorZone{ .start = 105.0 * 6.894757, .end = 120.0 * 6.894757, .color = Qt::red } };
    grads = { GradDef{ .gradPos = 0, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 150, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 300, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 450, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 600, .isBig = false, .gradColor = Qt::white },
              GradDef{ .gradPos = 750, .isBig = false, .gradColor = Qt::white } };
    textGrads = {
        TextGradDef{ .textGradPos = 0, .gradText = "0" },     TextGradDef{ .textGradPos = 150, .gradText = "150" },
        TextGradDef{ .textGradPos = 300, .gradText = "300" }, TextGradDef{ .textGradPos = 450, .gradText = "450" },
        TextGradDef{ .textGradPos = 600, .gradText = "600" }, TextGradDef{ .textGradPos = 750, .gradText = "750" }
    };

    GaugeDefinition oilPressGauge = { .title = "L OIL PRESS R",
                                      .unitString = "kPa",
                                      .minValue = 0,
                                      .maxValue = 120.0 * 6.894757,
                                      .colorZones = colorZones,
                                      .grads = grads,
                                      .textGrads = textGrads,
                                      .hasMinRedBlink = true,
                                      .minRedBlinkThreshold = 40.0 * 6.894757,
                                      .hasMaxRedBlink = true,
                                      .maxRedBlinkThreshold = 101.6 * 6.894757,
                                      .unit = Units::KILOPASCAL };

    return { .type = AircraftType::TURBOPROP,
             .name = "TestAircraft",
             .firstGauge = firstGauge,
             .secondGauge = secondGauge,
             .thirdGauge = thirdGauge,
             .fourthGauge = fourthGauge,
             .fuelQtyGauge = fuelQtyGauge,
             .fuelFlowGauge = fuelFlowGauge,
             .oilTempGauge = oilTempGauge,
             .secondaryTempGauge = secondaryTempGauge,
             .oilPressGauge = oilPressGauge,
             .gauge1Type = SwitchingGaugeType::N1,
             .gauge2Type = SwitchingGaugeType::TORQUE_PCT,
             .gauge3Type = SwitchingGaugeType::ENGINE_TEMP,
             .gauge4Type = SwitchingGaugeType::RPM,
             .engineTempType = TemperatureGaugeType::ITT,
             .hasApu = false,
             .hasFlaps = true,
             .hasSpoilers = true,
             .hasElevatorTrim = true,
             .hasRudderTrim = true,
             .hasAileronTrim = true,
             .fuelQtyByWeight = true,
             .fuelFlowByWeight = true,
             .hasSecondaryTempGauge = true,
             .secondaryTempType = TemperatureGaugeType::EGT,
             .numEngines = 2,
             .singleTank = false,
             .lowLimit = 0,
             .flapsBegin = 82,
             .flapsEnd = 158,
             .greenBegin = 99,
             .greenEnd = 245,
             .yellowBegin = 0,
             .yellowEnd = 0,
             .redBegin = 245,
             .redEnd = 350,
             .highLimit = 350,
             .noColors = false,
             .dynamicBarberpole = false };
}
