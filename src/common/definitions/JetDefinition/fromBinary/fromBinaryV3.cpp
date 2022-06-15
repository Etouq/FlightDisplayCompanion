#include "../JetDefinition.hpp"
#include "common/converters/basicConverters.hpp"

namespace definitions
{

JetDefinition JetDefinition::fromBinaryV3(QIODevice &data, FileVersion version)
{
    JetDefinition ret;

    ret.type = AircraftType::JET;

    ret.fromBinaryProtected(data, version);

    ret.n1Gauge = GaugeDefinition::fromBinary(data, version);
    ret.n2Gauge = GaugeDefinition::fromBinary(data, version);
    ret.ittGauge = GaugeDefinition::fromBinary(data, version);

    Converters::convert(data, ret.ittGaugeType);
    Converters::convert(data, ret.hasApu);

    return ret;
}

}  // namespace definitions
