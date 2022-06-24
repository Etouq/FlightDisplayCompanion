#include "AirspeedIndicator.hpp"
#include <cmath>
using namespace std::chrono;

namespace pages::pfd
{

void AirspeedIndicator::updateAirspeed(double newValue)
{
    d_rawAirspeed = newValue;

    d_airspeed = std::max(newValue, 20.0);

    updateAcceleration(newValue);

    emit airspeedChanged();

    int newCenter = std::max(std::lround(newValue / 10.0 + 0.5) * 10, 60l);
    if (d_center != newCenter)
    {
        d_center = newCenter;

        if (!d_noColor) [[likely]]
            updateColorElements();

        emit centerChanged();
    }


    bool cursorIsRed = !d_noColor && ((d_minSpeed > 0.1 && d_airspeed < d_minSpeed) || (d_maxSpeed > 0.1 && d_airspeed > d_maxSpeed));
    if (d_redCursor != cursorIsRed)
    {
        d_redCursor = cursorIsRed;
        emit redCursorChanged();
    }
}

}  // namespace pages::pfd
