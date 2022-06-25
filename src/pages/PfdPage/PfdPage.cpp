#include "PfdPage.hpp"

#include <QQmlEngine>


namespace pages::pfd
{

PfdPage::PfdPage(io::network::NetworkClient *netClient)
  : d_airspeedIndicator(netClient),
    d_altimeter(netClient),
    d_aoaIndicator(netClient),
    d_apInfo(netClient),
    d_attitudeIndicator(netClient),
    d_bottombar(netClient),
    d_hsiBearings(netClient),
    d_hsIndicator(netClient),
    d_navInfo(netClient),
    d_radioInfo(netClient),
    d_windInfo(netClient)
{
    qmlRegisterSingletonInstance("Pfd.Airspeed", 1, 0, "Airspeed", &d_airspeedIndicator);
    qmlRegisterSingletonInstance("Pfd.Altimeter", 1, 0, "Altimeter", &d_altimeter);
    qmlRegisterSingletonInstance("Pfd.Aoa", 1, 0, "Aoa", &d_aoaIndicator);
    qmlRegisterSingletonInstance("Pfd.Autopilot", 1, 0, "ApInfo", &d_apInfo);
    qmlRegisterSingletonInstance("Pfd.Attitude", 1, 0, "Attitude", &d_attitudeIndicator);
    qmlRegisterSingletonInstance("Pfd.Bottombar", 1, 0, "Bottombar", &d_bottombar);
    qmlRegisterSingletonInstance("Pfd.Bearings", 1, 0, "Bearings", &d_hsiBearings);
    qmlRegisterSingletonInstance("Pfd.HSIndicator", 1, 0, "HSIndicator", &d_hsIndicator);
    qmlRegisterSingletonInstance("Pfd.NavInfo", 1, 0, "NavInfo", &d_navInfo);
    qmlRegisterSingletonInstance("Pfd.RadioInfo", 1, 0, "RadioInfo", &d_radioInfo);
    qmlRegisterSingletonInstance("Pfd.WindInfo", 1, 0, "WindInfo", &d_windInfo);
}

}  // namespace pages::pfd
