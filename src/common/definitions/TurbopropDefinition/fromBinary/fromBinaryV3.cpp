#include "../TurbopropDefinition.hpp"
#include "common/converters/basicConverters.hpp"

namespace definitions
{

TurbopropDefinition TurbopropDefinition::fromBinaryV3(QIODevice &data, FileVersion version)
{
    TurbopropDefinition ret;

    ret.type = AircraftType::TURBOPROP;

    ret.fromBinaryProtected(data, version);

    ret.n1Gauge = GaugeDefinition::fromBinary(data, version);
    ret.trqGauge = GaugeDefinition::fromBinary(data, version);
    ret.ittGauge = GaugeDefinition::fromBinary(data, version);
    ret.rpmGauge = GaugeDefinition::fromBinary(data, version);

    Converters::convert(data, ret.trqAsPct);

    Converters::convert(data, ret.ittGaugeType);

    Converters::convert(data, ret.rpmAsPct);
    Converters::convert(data, ret.usePropRpm);

    Converters::convert(data, ret.hasApu);

    return ret;
}

}  // namespace definitions
