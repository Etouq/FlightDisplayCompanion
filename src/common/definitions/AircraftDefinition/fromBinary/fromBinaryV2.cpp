#include "../AircraftDefinition.hpp"
#include "common/converters/basicConverters.hpp"


namespace definitions
{

void AircraftDefinition::fromBinaryV2(QIODevice &data, FileVersion version)
{
    // type should already be handled by derived class
    fromBinaryV1(data, version);

    refSpeedDefaults = { { Converters::convert<uint16_t>(data), "R" },
                             { Converters::convert<uint16_t>(data), "X" },
                             { Converters::convert<uint16_t>(data), "Y" },
                             { Converters::convert<uint16_t>(data), "AP" } };
}

}  // namespace definitions
