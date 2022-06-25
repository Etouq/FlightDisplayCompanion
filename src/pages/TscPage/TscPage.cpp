#include "TscPage.hpp"

#include <QQmlEngine>

namespace pages::tsc
{

TscPage::TscPage(io::network::NetworkClient *netClient)
  : d_navCom(netClient)
{
    qmlRegisterSingletonInstance("Tsc.FlightTmr", 1, 0, "FlightTmr", &d_flightTmr);
    qmlRegisterSingletonInstance("Tsc.NavCom", 1, 0, "NavCom", &d_navCom);
    qmlRegisterSingletonInstance("Tsc.SpeedBugs", 1, 0, "SpeedBugs", &d_speedBugs);
    qmlRegisterSingletonInstance("Tsc.AircraftSelector", 1, 0, "AircraftSelector", &d_aircraftSelector);
    qmlRegisterSingletonInstance("General.Settings", 1, 0, "GenSettings", &d_generalSettings);
}

}  // namespace pages::tsc
