#include "../PropDefinition.hpp"
#include "common/converters/basicConverters.hpp"

namespace definitions
{

PropDefinition PropDefinition::fromBinaryV3(QIODevice &data, FileVersion version)
{
    PropDefinition ret;

    ret.type = AircraftType::PROP;

    ret.fromBinaryProtected(data, version);

    ret.rpmGauge = GaugeDefinition::fromBinary(data, version);
    ret.powerGauge = GaugeDefinition::fromBinary(data, version);
    ret.manPressGauge = GaugeDefinition::fromBinary(data, version);
    ret.chtGauge = GaugeDefinition::fromBinary(data, version);

    Converters::convert(data, ret.hasRpm);
    Converters::convert(data, ret.usePropRpm);

    Converters::convert(data, ret.hasPower);
    Converters::convert(data, ret.powerAsPct);
    Converters::convert(data, ret.maxPower);

    Converters::convert(data, ret.hasManPress);

    Converters::convert(data, ret.hasCht);
    Converters::convert(data, ret.chtGaugeType);

    return ret;
}

}  // namespace definitions
