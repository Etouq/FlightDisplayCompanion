#include "../PropDefinition.hpp"
#include "common/converters/basicConverters.hpp"

namespace definitions
{

PropDefinition PropDefinition::fromBinaryV1(QIODevice &data, FileVersion version)
{
    PropDefinition ret;

    ret.type = AircraftType::PROP;

    ret.rpmGauge = GaugeDefinition::fromBinary(data, version);
    GaugeDefinition temp = GaugeDefinition::fromBinary(data, version);

    ret.egtGauge = GaugeDefinition::fromBinary(data, version);
    ret.egtGaugeType = TemperatureGaugeType::EGT;
    Converters::convert(data, ret.hasEgt);


    Converters::convert(data, ret.usePropRpm);

    bool tmpIsLoad = Converters::convert<bool>(data);
    if (tmpIsLoad)
    {
        ret.hasPower = true;
        ret.hasManPress = false;
        ret.powerGauge = temp;
    }
    else
    {
        ret.hasPower = false;
        ret.hasManPress = true;
        ret.manPressGauge = temp;
    }
    ret.maxPower = Converters::convert<double>(data) * 5.50; // * 550 (hp to ft/lbs) / 100 (pct)
    ret.powerAsPct = true;

    ret.hasCht = false;
    ret.chtGaugeType = TemperatureGaugeType::CHT;

    ret.fromBinaryProtected(data, version);

    return ret;
}

}  // namespace definitions
