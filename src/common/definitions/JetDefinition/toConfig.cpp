#include "JetDefinition.hpp"
#include "common/AircraftConfig.hpp"
#include "common/typeEnums.hpp"


namespace definitions
{

AircraftConfig JetDefinition::toConfig() const
{
    AircraftConfig ret = AircraftDefinition::toConfig();

    ret.type = AircraftType::JET;

    ret.n1Epsilon = n1Gauge.getEpsilon(numEngines != 4);
    ret.n2Epsilon = n2Gauge.getEpsilon(numEngines != 4);
    ret.ittEpsilon = ittGauge.getEpsilon(numEngines != 4);

    ret.ittGaugeType = ittGaugeType;
    ret.hasApu = hasApu;

    return ret;
}

}  // namespace definitions
