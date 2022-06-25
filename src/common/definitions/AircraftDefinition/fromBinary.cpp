#include "AircraftDefinition.hpp"
#include "common/converters/listConverters.hpp"

namespace definitions
{

AircraftDefinition AircraftDefinition::fromBinary(QIODevice &stream)
{
    AircraftDefinition ret;

    Converters::convert(stream, ret.type);

    Converters::convertString(stream, ret.name);

    ret.firstGauge = GaugeDefinition::fromBinary(stream);
    ret.secondGauge = GaugeDefinition::fromBinary(stream);
    ret.thirdGauge = GaugeDefinition::fromBinary(stream);
    ret.fourthGauge = GaugeDefinition::fromBinary(stream);

    ret.fuelQtyGauge = GaugeDefinition::fromBinary(stream);
    ret.fuelFlowGauge = GaugeDefinition::fromBinary(stream);
    ret.oilTempGauge = GaugeDefinition::fromBinary(stream);
    ret.secondaryTempGauge = GaugeDefinition::fromBinary(stream);
    ret.oilPressGauge = GaugeDefinition::fromBinary(stream);

    Converters::convert(stream, ret.gauge1Type);
    Converters::convert(stream, ret.gauge2Type);
    Converters::convert(stream, ret.gauge3Type);
    Converters::convert(stream, ret.gauge4Type);

    Converters::convert(stream, ret.engineTempType);

    Converters::convert(stream, ret.maxPower);

    Converters::convert(stream, ret.hasApu);

    Converters::convert(stream, ret.hasFlaps);
    Converters::convert(stream, ret.hasSpoilers);

    Converters::convert(stream, ret.hasElevatorTrim);
    Converters::convert(stream, ret.hasRudderTrim);
    Converters::convert(stream, ret.hasAileronTrim);

    Converters::convert(stream, ret.fuelQtyByWeight);
    Converters::convert(stream, ret.fuelFlowByWeight);

    Converters::convert(stream, ret.hasSecondaryTempGauge);
    Converters::convert(stream, ret.secondaryTempType);

    Converters::convert(stream, ret.numEngines);
    Converters::convert(stream, ret.singleTank);

    Converters::convert(stream, ret.lowLimit);
    Converters::convert(stream, ret.flapsBegin);
    Converters::convert(stream, ret.flapsEnd);
    Converters::convert(stream, ret.greenBegin);
    Converters::convert(stream, ret.greenEnd);
    Converters::convert(stream, ret.yellowBegin);
    Converters::convert(stream, ret.yellowEnd);
    Converters::convert(stream, ret.redBegin);
    Converters::convert(stream, ret.redEnd);
    Converters::convert(stream, ret.highLimit);
    Converters::convert(stream, ret.noColors);
    Converters::convert(stream, ret.dynamicBarberpole);

    Converters::convert(stream, ret.refSpeedDefaults);

    return ret;
}

}  // namespace definitions
