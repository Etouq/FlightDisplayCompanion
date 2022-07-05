#include "FlightTmr.hpp"

using namespace std::chrono;

namespace pages::tsc
{

void FlightTmr::update()
{
    d_currentValue = duration_cast<milliseconds>(steady_clock::now() - d_lastStartTime).count() + d_lastStartValue;

    if (d_currentValue >= 0 && d_countingDown)
    {
        // just switched from negative (counting down) to positive (counting up)
        d_countingDown = false;
        emit countingDownChanged();
    }

    if (d_currentValue >= 86400000)  // 24*60*60*1000 (number of ms in a day)
    {
        // we exceeded 24H so we wrap back (preserving the exceeded time)
        d_currentValue -= 86400000;
    }

    updateTimeString(std::abs(d_currentValue) / 1000);
}

}  // namespace pages::tsc
