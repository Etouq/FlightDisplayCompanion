#include "Altimeter.hpp"

#include <cmath>


namespace pages::pfd
{

void Altimeter::updateMinimumAlt()
{
    if (d_minimumsState == 1)
    {
        d_minimumAltitude = d_minimumsValue;
        emit minimumAltitudeChanged();
    }
    else if (d_minimumsState == 2)
    {
        d_minimumAltitude = std::lround(static_cast<double>(d_minimumsValue) + d_altitude - d_realRadioAltitude);
        emit minimumAltitudeChanged();
    }
}

}  // namespace pages::pfd
