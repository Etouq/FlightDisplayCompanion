#include "AirspeedIndicator.hpp"

#include <cmath>

using namespace std::chrono;

namespace pages::pfd
{

void AirspeedIndicator::updateAcceleration(double newAirspeed)
{
    steady_clock::time_point now = steady_clock::now();

    const double deltaTime = duration_cast<duration<double, milliseconds::period>>(now - d_previousTime).count();
    d_previousTime = now;

    if (newAirspeed < 20.0) [[unlikely]]
    {
        if (std::abs(d_acceleration) > 0.01)
        {
            d_acceleration = 0;
        }

        return;
    }

    d_acceleration = std::fdim(2000.0, deltaTime) * d_acceleration / 2000.0
      + std::min(deltaTime, 2000.0) * (newAirspeed - d_lastSpeed) / (2.0 * deltaTime);

    // adjust for display
    d_acceleration = std::clamp(288 - d_acceleration * 57.6, 0.0, 576.0);

    d_lastSpeed = newAirspeed;
}

}  // namespace pages::pfd
