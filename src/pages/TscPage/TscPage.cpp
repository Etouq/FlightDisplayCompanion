#include "TscPage.hpp"

#include <QQmlEngine>

namespace pages::tsc
{

TscPage::TscPage(io::network::NetworkClient *netClient)
  : d_navCom(netClient)
{
    QObject::connect(&d_generalSettings,
                     &GeneralSettings::sendCommandsToSim,
                     netClient,
                     &io::network::NetworkClient::sendCommandString);

    qRegisterMetaType<SpeedBugEntry *>("SpeedBugEntry*");
    qmlRegisterUncreatableType<SpeedBugEntry>("Tsc.SpeedBugs", 1, 0, "SpeedBugEntry", "Bad Boy");
    qmlRegisterSingletonInstance("Tsc.FlightTmr", 1, 0, "FlightTmr", &d_flightTmr);
    qmlRegisterSingletonInstance("Tsc.NavCom", 1, 0, "NavCom", &d_navCom);
    qmlRegisterSingletonInstance("Tsc.SpeedBugs", 1, 0, "SpeedBugs", &d_speedBugs);
    qmlRegisterSingletonInstance("General.Settings", 1, 0, "GenSettings", &d_generalSettings);
}

}  // namespace pages::tsc
