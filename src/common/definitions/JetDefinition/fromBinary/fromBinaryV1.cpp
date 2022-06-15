#include "../JetDefinition.hpp"
#include "common/converters/basicConverters.hpp"

namespace definitions
{

JetDefinition JetDefinition::fromBinaryV1(QIODevice &data, FileVersion version)
{
    JetDefinition ret;

    ret.type = AircraftType::JET;

    ret.n1Gauge = GaugeDefinition::fromBinary(data, version);
    ret.n2Gauge = GaugeDefinition::fromBinary(data, version);
    ret.ittGauge = GaugeDefinition::fromBinary(data, version);

    Converters::convert(data, ret.hasApu);
    ret.ittGaugeType = Converters::convert<bool>(data) ? TemperatureGaugeType::EGT : TemperatureGaugeType::ITT;

    ret.fromBinaryProtected(data, version);

    ret.hasEgt = false;
    ret.egtGaugeType = TemperatureGaugeType::EGT;

    return ret;
}

}  // namespace definitions
