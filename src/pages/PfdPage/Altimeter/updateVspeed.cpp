#include "Altimeter.hpp"
#include <cmath>

namespace pages::pfd
{

void Altimeter::updateVspeed(double newValue)
{
    d_vspeedIndicatorTransformValue = newValue >= 2250.0 ? -216.0 : newValue <= -2250.0 ? 216.0 : -newValue / 9.6;
    emit vspeedIndicatorTransformValueChanged();

    d_altitudeTrendValue = newValue >= 2000 ? -48 : newValue <= -2000 ? 528 : 240.0 - 0.144 * newValue;
    emit altitudeTrendValueChanged();

    QString newSpeedText = (std::abs(newValue) >= 50.0 ? QString::number(std::lround(newValue / 25.0 + 0.5) * 25) : "");
    if (d_vspeedTextValue != newSpeedText)
    {
        d_vspeedTextValue = newSpeedText;
        emit vspeedTextValueChanged();
    }
}

}  // namespace pages::pfd
