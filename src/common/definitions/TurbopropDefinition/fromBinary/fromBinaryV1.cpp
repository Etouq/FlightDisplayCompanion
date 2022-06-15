#include "../TurbopropDefinition.hpp"
#include "common/converters/basicConverters.hpp"


namespace definitions
{

TurbopropDefinition TurbopropDefinition::fromBinaryV1(QIODevice &data, FileVersion version)
{
    TurbopropDefinition ret;

    ret.type = AircraftType::TURBOPROP;

    ret.n1Gauge = GaugeDefinition::fromBinary(data, version);
    ret.trqGauge = GaugeDefinition::fromBinary(data, version);
    ret.ittGauge = GaugeDefinition::fromBinary(data, version);
    ret.rpmGauge = GaugeDefinition::fromBinary(data, version);

    ret.egtGauge = GaugeDefinition::fromBinary(data, version);
    Converters::convert(data, ret.hasEgt);

    Converters::convert(data, ret.usePropRpm);

    Converters::convert(data, ret.trqAsPct);


    ret.fromBinaryProtected(data, version);

    return ret;
}

}  // namespace definitions
