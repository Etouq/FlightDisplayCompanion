#include "TurbopropDefinition.hpp"
#include "common/AircraftConfig.hpp"

namespace definitions
{

AircraftConfig TurbopropDefinition::toConfig() const
{
    AircraftConfig ret = AircraftDefinition::toConfig();

    ret.type = AircraftType::TURBOPROP;

    ret.n1Epsilon = n1Gauge.getEpsilon(numEngines == 1);
    ret.trqEpsilon = trqGauge.getEpsilon(numEngines == 1);
    ret.ittEpsilon = ittGauge.getEpsilon(numEngines == 1);
    ret.rpmEpsilon = rpmGauge.getEpsilon(numEngines == 1);

    ret.trqAsPct = trqAsPct;
    ret.rpmAsPct = rpmAsPct;
    ret.usePropRpm = usePropRpm;

    ret.ittGaugeType = ittGaugeType;

    ret.hasApu = hasApu;

    return ret;
}

}  // namespace definitions
