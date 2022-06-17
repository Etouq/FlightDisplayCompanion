#ifndef __PFPAGE_HPP__
#define __PFPAGE_HPP__

#include "AirspeedIndicator/AirspeedIndicator.hpp"
#include "Altimeter/Altimeter.hpp"
#include "AoaIndicator/AoaIndicator.hpp"
#include "ApInfo/ApInfo.hpp"
#include "AttitudeIndicator/AttitudeIndicator.hpp"
#include "Bottombar/Bottombar.hpp"
#include "HSIBearings/HSIBearings.hpp"
#include "HSIndicator/HSIndicator.hpp"
#include "NavInfo/NavInfo.hpp"
#include "RadioInfo/RadioInfo.hpp"
#include "WindInfo/WindInfo.hpp"
#include "io/NetworkClient/NetworkClient.hpp"

#include <QQmlEngine>


namespace pages::pfd
{

class PfdPage
{
public:

    PfdPage(io::network::NetworkClient *netClient)
      : airspeedIndicator(netClient),
        altimeter(netClient),
        aoaIndicator(netClient),
        apInfo(netClient),
        attitudeIndicator(netClient),
        bottombar(netClient),
        hsiBearings(netClient),
        hsIndicator(netClient),
        navInfo(netClient),
        radioInfo(netClient),
        windInfo(netClient)
    {
        qmlRegisterSingletonInstance("Pfd.Airspeed", 1, 0, "Airspeed", &airspeedIndicator);
        qmlRegisterSingletonInstance("Pfd.Altimeter", 1, 0, "Altimeter", &altimeter);
        qmlRegisterSingletonInstance("Pfd.Aoa", 1, 0, "Aoa", &aoaIndicator);
        qmlRegisterSingletonInstance("Pfd.Autopilot", 1, 0, "ApInfo", &apInfo);
        qmlRegisterSingletonInstance("Pfd.Attitude", 1, 0, "Attitude", &attitudeIndicator);
        qmlRegisterSingletonInstance("Pfd.Bottombar", 1, 0, "Bottombar", &bottombar);
        qmlRegisterSingletonInstance("Pfd.Bearings", 1, 0, "Bearings", &hsiBearings);
        qmlRegisterSingletonInstance("Pfd.HSIndicator", 1, 0, "HSIndicator", &hsIndicator);
        qmlRegisterSingletonInstance("Pfd.NavInfo", 1, 0, "NavInfo", &navInfo);
        qmlRegisterSingletonInstance("Pfd.RadioInfo", 1, 0, "RadioInfo", &radioInfo);
        qmlRegisterSingletonInstance("Pfd.WindInfo", 1, 0, "WindInfo", &windInfo);
    }


    AirspeedIndicator airspeedIndicator;
    Altimeter altimeter;
    AoaIndicator aoaIndicator;
    ApInfo apInfo;
    AttitudeIndicator attitudeIndicator;
    Bottombar bottombar;
    HSIBearings hsiBearings;
    HSIndicator hsIndicator;
    NavInfo navInfo;
    RadioInfo radioInfo;
    WindInfo windInfo;
};

}  // namespace pages::pfd


#endif  // __PFPAGE_HPP__