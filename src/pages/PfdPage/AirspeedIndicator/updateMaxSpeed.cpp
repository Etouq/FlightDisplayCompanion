#include "AirspeedIndicator.hpp"
#include <algorithm>

namespace pages::pfd
{

void AirspeedIndicator::updateMaxSpeed(double newValue)
{
    if (!d_dynamicMax)
        return;

    d_maxSpeed = newValue;

    if (!d_noColor)
    {
        d_maxTransform = std::clamp(384.0 + 9.6 * (static_cast<double>(d_center) - d_maxSpeed), 0.0, 768.0);
        emit maxTransformChanged();
    }
    emit maxSpeedChanged();
}

}  // namespace pages::pfd
