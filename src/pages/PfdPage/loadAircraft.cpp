#include "PfdPage.hpp"
#include "common/definitions/AircraftDefinition/AircraftDefinition.hpp"

namespace pages::pfd
{

void PfdPage::loadAircraft(const definitions::AircraftDefinition &aircraft)
{
    d_airspeedIndicator.updateColors(aircraft.lowLimit,
                                     aircraft.flapsBegin,
                                     aircraft.flapsEnd,
                                     aircraft.greenBegin,
                                     aircraft.greenEnd,
                                     aircraft.yellowBegin,
                                     aircraft.yellowEnd,
                                     aircraft.redBegin,
                                     aircraft.redEnd,
                                     aircraft.highLimit,
                                     aircraft.noColors,
                                     aircraft.dynamicBarberpole);
}

}  // namespace pages::pfd
