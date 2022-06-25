#include "TscPage.hpp"
#include "common/definitions/AircraftDefinition/AircraftDefinition.hpp"

namespace pages::tsc
{

void TscPage::loadAircraft(const definitions::AircraftDefinition &aircraft)
{
    d_speedBugs.setSpeedbugs(aircraft.refSpeedDefaults);
    d_aircraftSelector.clear();
}

}  // namespace pages::pfd
