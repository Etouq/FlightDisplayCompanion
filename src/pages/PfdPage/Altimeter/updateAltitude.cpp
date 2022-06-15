#include "Altimeter.hpp"
#include <cmath>

namespace pages::pfd
{

void Altimeter::updateAltitude(double newValue)
{
    d_altitude = newValue;
    emit altitudeChanged();

    int newCenter = std::lround(newValue / 100.0) * 100;
    if (d_center != newCenter)
    {
        d_center = newCenter;
        emit centerChanged();
    }

    if (d_minimumsState == 2)
    {
        int newMinimum = std::lround(static_cast<double>(d_minimumsValue) + d_altitude - d_realRadioAltitude);
        if (d_minimumAltitude != newMinimum)
        {
            d_minimumAltitude = newMinimum;
            emit minimumAltitudeChanged();
        }
    }
}

}  // namespace pages::pfd
