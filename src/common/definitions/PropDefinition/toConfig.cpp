#include "PropDefinition.hpp"
#include "common/AircraftConfig.hpp"

namespace definitions
{

AircraftConfig PropDefinition::toConfig() const
{
    AircraftConfig ret = AircraftDefinition::toConfig();

    ret.type = AircraftType::PROP;

    ret.rpmEpsilon = hasRpm ? rpmGauge.getEpsilon(numEngines != 4) : 10000;
    ret.powerEpsilon = hasPower ? powerGauge.getEpsilon(numEngines != 4) : 10000;
    ret.manPressEpsilon = hasManPress ? manPressGauge.getEpsilon(numEngines != 4) : 10000;
    ret.chtEpsilon = hasCht ? chtGauge.getEpsilon(numEngines != 4) : 10000;

    ret.hasRpm = hasRpm;
    ret.usePropRpm = usePropRpm;

    ret.hasPower = hasPower;
    ret.powerAsPct = powerAsPct;
    if (powerAsPct)
        ret.maxPower = maxPower;

    ret.hasManPress = hasManPress;

    ret.hasCht = hasCht;
    ret.chtGaugeType = chtGaugeType;

    return ret;
}

}  // namespace definitions
