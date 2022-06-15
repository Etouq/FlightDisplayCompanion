#include "AircraftDefinition.hpp"
#include "common/AircraftConfig.hpp"

namespace definitions
{

AircraftConfig AircraftDefinition::toConfig() const
{
    AircraftConfig ret;

    ret.numEngines = numEngines;

    ret.fuelFlowEpsilon = fuelFlowGauge.getEpsilon(false);
    ret.oilTempEpsilon = fuelFlowGauge.getEpsilon(false);
    ret.oilPressEpsilon = fuelFlowGauge.getEpsilon(false);
    ret.fuelQtyEpsilon = fuelFlowGauge.getEpsilon(false);
    ret.egtEpsilon = hasEgt ? egtGauge.getEpsilon(false) : 10000;

    ret.fuelFlowByWeight = fuelFlowByWeight;

    ret.singleTank = singleTank;
    ret.fuelQtyByWeight = fuelQtyByWeight;

    ret.hasFlaps = hasFlaps;
    ret.hasSpoilers = hasSpoilers;

    ret.hasElevTrim = hasElevatorTrim;
    ret.hasRudderTrim = hasRudderTrim;
    ret.hasAileronTrim = hasAileronTrim;

    if (fuelQtyByWeight)
        ret.fuelQtyEpsilon /= 4.0;

    if (fuelFlowByWeight)
        ret.fuelFlowEpsilon /= 3600.0;
    else
        ret.fuelFlowEpsilon *= 0.2641720523; // placeholder until liters per hour is fixed

    return ret;
}

}  // namespace definitions
