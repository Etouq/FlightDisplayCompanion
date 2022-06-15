#include "AirspeedIndicator.hpp"
#include <cmath>

namespace pages::pfd
{

void AirspeedIndicator::updateColors(double minSpeed,
                      double flapsBegin,
                      double flapsEnd,
                      double greenBegin,
                      double greenEnd,
                      double yellowBegin,
                      double yellowEnd,
                      double redBegin,
                      double redEnd,
                      double maxSpeed,
                      bool noColor,
                      bool dynamicMax)
{
    d_center = std::max(std::lround(d_rawAirspeed / 10.0 + 0.5) * 10, 60l);
    d_minSpeed = minSpeed;
    d_flapsBegin = flapsBegin;
    d_flapsEnd = flapsEnd;
    d_greenBegin = greenBegin;
    d_greenEnd = greenEnd;
    d_yellowBegin = yellowBegin;
    d_yellowEnd = yellowEnd;
    d_redBegin = redBegin;
    d_redEnd = redEnd;
    d_maxSpeed = maxSpeed;

    d_noColor = noColor;
    d_dynamicMax = dynamicMax;
    emit noColorChanged();
    emit minSpeedChanged();
    emit maxSpeedChanged();

    updateColorElements();
    emit centerChanged();
}

}  // namespace pages::pfd
