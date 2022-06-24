#ifndef __TSC_PAGE_HPP__
#define __TSC_PAGE_HPP__

#include "FlightTmr/FlightTmr.hpp"
#include "NavCom/NavCom.hpp"
#include "SpeedBugs/SpeedBugs.hpp"
#include "AircraftSelector/AircraftSelector.hpp"
#include "io/NetworkClient/NetworkClient.hpp"
#include "GeneralSettings/GeneralSettings.hpp"

#include <QQmlEngine>

namespace pages::tsc
{

class TscPage
{
public:

    TscPage(io::network::NetworkClient *netClient)
      : d_navCom(netClient)
    {
        qmlRegisterSingletonInstance("Tsc.FlightTmr", 1, 0, "FlightTmr", &d_flightTmr);
        qmlRegisterSingletonInstance("Tsc.NavCom", 1, 0, "NavCom", &d_navCom);
        qmlRegisterSingletonInstance("Tsc.SpeedBugs", 1, 0, "SpeedBugs", &d_speedBugs);
        qmlRegisterSingletonInstance("Tsc.AircraftSelector", 1, 0, "AircraftSelector", &d_aircraftSelector);
        qmlRegisterSingletonInstance("General.Settings", 1, 0, "GenSettings", &d_generalSettings);
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