#include "../AircraftDefinition.hpp"
#include "common/converters/basicConverters.hpp"

namespace definitions
{

void AircraftDefinition::fromBinaryV1(QIODevice &data, FileVersion version)
{
    name = Converters::convertString(data);
    fuelQtyGauge = GaugeDefinition::fromBinary(data, version);
    fuelFlowGauge = GaugeDefinition::fromBinary(data, version);
    oilTempGauge = GaugeDefinition::fromBinary(data, version);
    oilPressGauge = GaugeDefinition::fromBinary(data, version);

    Converters::convert(data, hasFlaps);
    Converters::convert(data, hasSpoilers);

    Converters::convert(data, hasElevatorTrim);
    Converters::convert(data, hasRudderTrim);
    Converters::convert(data, hasAileronTrim);

    fuelQtyByWeight = !Converters::convert<bool>(data);
    fuelFlowByWeight = !Converters::convert<bool>(data);

    numEngines = Converters::convert<int8_t>(data);
    singleTank = Converters::convert<int8_t>(data) == 1;

    Converters::convert(data, lowLimit);
    Converters::convert(data, flapsBegin);
    Converters::convert(data, flapsEnd);
    Converters::convert(data, greenBegin);
    Converters::convert(data, greenEnd);
    Converters::convert(data, yellowBegin);
    Converters::convert(data, yellowEnd);
    Converters::convert(data, redBegin);
    Converters::convert(data, redEnd);
    Converters::convert(data, highLimit);

    Converters::convert(data, noColors);
    Converters::convert(data, dynamicBarberpole);
}

}  // namespace definitions
