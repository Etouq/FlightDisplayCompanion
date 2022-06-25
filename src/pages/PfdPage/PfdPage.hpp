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


namespace definitions
{
struct AircraftDefinition;
}

namespace io::network
{
class NetworkClient;
}

namespace pages::pfd
{

class PfdPage
{
public:

    PfdPage(io::network::NetworkClient *netClient);

    void loadAircraft(const definitions::AircraftDefinition &aircraft);

private:

    AirspeedIndicator d_airspeedIndicator;
    Altimeter d_altimeter;
    AoaIndicator d_aoaIndicator;
    ApInfo d_apInfo;
    AttitudeIndicator d_attitudeIndicator;
    Bottombar d_bottombar;
    HSIBearings d_hsiBearings;
    HSIndicator d_hsIndicator;
    NavInfo d_navInfo;
    RadioInfo d_radioInfo;
    WindInfo d_windInfo;
};

}  // namespace pages::pfd


#endif  // __PFPAGE_HPP__