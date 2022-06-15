#include "AirspeedIndicator.hpp"
#include <algorithm>

namespace pages::pfd
{

void AirspeedIndicator::updateColorElements()
{
    double dCenter = static_cast<double>(d_center);

    if (d_minSpeed > 0.1)
        d_minTransform = 1152 + 9.6 * (dCenter - d_minSpeed); // height = 672, 1.5height + 144
    if (d_maxSpeed > 0.1)
    {
        d_maxTransform = std::clamp(384.0 + 9.6 * (dCenter - d_maxSpeed), 0.0, 768.0);
        emit maxTransformChanged();
    }

    // 288: (height - 96) / 2
    d_greenY =  std::clamp(288.0 + 9.6 * (dCenter - d_greenEnd), -96.0, 672.0);
    d_greenHeight =  std::clamp(288.0 + 9.6 * (dCenter - d_greenBegin), -96.0, 672.0) - d_greenY;
    d_yellowY =  std::clamp(288.0 + 9.6 * (dCenter - d_yellowEnd), -96.0, 672.0);
    d_yellowHeight =  std::clamp(288.0 + 9.6 * (dCenter - d_yellowBegin), -96.0, 672.0) - d_yellowY;
    d_redY =  std::clamp(288.0 + 9.6 * (dCenter - d_redEnd), -96.0, 672.0);
    d_redHeight =  std::clamp(288.0 + 9.6 * (dCenter - d_redBegin), -96.0, 672.0) - d_redY;
    d_flapsY =  std::clamp(288.0 + 9.6 * (dCenter - d_flapsEnd), -96.0, 672.0);
    d_flapsHeight =  std::clamp(288.0 + 9.6 * (dCenter - d_flapsBegin), -96.0, 672.0) - d_flapsY;
}

}  // namespace pages::pfd
