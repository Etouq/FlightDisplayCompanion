#include "AirspeedIndicator.hpp"

#include <cmath>
#include <QDebug>

using namespace std::chrono;

namespace pages::pfd
{

void AirspeedIndicator::updateAcceleration(double newAirspeed)
{
    steady_clock::time_point now = steady_clock::now();

    const double deltaTime = duration_cast<duration<double, seconds::period>>(now - d_previousTime).count();
    d_previousTime = now;

    if (newAirspeed < 20.0) [[unlikely]]
    {
        if (std::abs(d_acceleration) > 0.01)
        {
            d_acceleration = 0;
        }

        d_lastSpeed = newAirspeed;

        return;
    }

    static constexpr double smoothFactor = 1.0;
    // if (deltaTime > smoothFactor) [[unlikely]]
    // {
    //     d_acceleration = (newAirspeed - d_lastSpeed) / deltaTime;
    // }
    // else [[likely]]
    // {
    //     d_acceleration = ((smoothFactor - deltaTime) * d_acceleration + (newAirspeed - d_lastSpeed)) / smoothFactor;
    // }

    d_acceleration = (std::fdim(smoothFactor, deltaTime) * d_acceleration + (newAirspeed - d_lastSpeed)) / std::max(deltaTime, smoothFactor);

    // adjust for display
    d_qmlAcceleration = std::clamp(336.0 - d_acceleration * 57.6, 48.0, 624.0);

    d_lastSpeed = newAirspeed;
}

}  // namespace pages::pfd