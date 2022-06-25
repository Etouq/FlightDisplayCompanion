#ifndef __TSC_PAGE_HPP__
#define __TSC_PAGE_HPP__

#include "FlightTmr/FlightTmr.hpp"
#include "NavCom/NavCom.hpp"
#include "SpeedBugs/SpeedBugs.hpp"
#include "AircraftSelector/AircraftSelector.hpp"
#include "io/NetworkClient/NetworkClient.hpp"
#include "GeneralSettings/GeneralSettings.hpp"


namespace definitions
{
struct AircraftDefinition;
}

namespace pages::tsc
{

class TscPage
{
public:

    TscPage(io::network::NetworkClient *netClient);

    void loadAircraft(const definitions::AircraftDefinition &aircraft);

    AircraftSelector *getSelector()
    {
        return &d_aircraftSelector;
    }

private:

    FlightTmr d_flightTmr;
    NavCom d_navCom;
    SpeedBugs d_speedBugs;
    AircraftSelector d_aircraftSelector;
    GeneralSettings d_generalSettings;
};

}  // namespace pages::tsc

#endif  // __TSC_PAGE_HPP__