#include "Altimeter.hpp"
#include <cmath>

namespace pages::pfd
{

void Altimeter::updateRadarAltitude(double newValue)
{
    if (d_minimumsState == 2)
    {
        int newMinimum = std::lround(static_cast<double>(d_minimumsValue) + d_altitude - newValue);
        if (d_minimumAltitude != newMinimum)
        {
            d_minimumAltitude = newMinimum;
            emit minimumAltitudeChanged();
        }
    }

    d_realRadioAltitude = newValue;
    if (newValue < 0.0 || newValue > 2500.0)
    {
        if (d_radarAltitudeTransformValue < 672.0)
        {
            d_radarAltitudeTransformValue = 672.0;
            emit radarAltitudeTransformValueChanged();
        }
        if (d_radarAltitude != 3000)
        {
            d_radarAltitude = 3000;
            emit radarAltitudeChanged();
        }
        return;
    }

    d_radarAltitudeTransformValue = std::min(288.0 + newValue * 1.536, 672.0);
    emit radarAltitudeTransformValueChanged();

    if (int roundedAlt = std::lround(newValue); d_radarAltitude != roundedAlt)
    {
        d_radarAltitude = roundedAlt;
        emit radarAltitudeChanged();
    }
}

}  // namespace pages::pfd
