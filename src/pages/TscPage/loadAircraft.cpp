#include "TscPage.hpp"
#include "common/definitions/AircraftDefinition/AircraftDefinition.hpp"

namespace pages::tsc
{

void TscPage::loadAircraft(const definitions::AircraftDefinition &aircraft)
{
    d_speedBugs.setSpeedbugs(aircraft.refSpeedDefaults);
}

}  // namespace pages::pfd
