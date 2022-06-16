#include "FlightTmr.hpp"

using namespace std::chrono;

namespace pages::tsc
{

void FlightTmr::update()
{
    d_currentValue = duration_cast<milliseconds>(steady_clock::now() - d_lastStartTime).count();

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

    // update time string
    int seconds = std::abs(d_currentValue) / 1000;
    int hours = seconds / 3600;
    seconds -= hours * 3600;
    int mins = seconds / 60;
    seconds -= mins * 60;

    QString timeStr =
      QString("%1:%2:%3").arg(hours, 2, 10, QChar('0')).arg(mins, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0'));


    if (d_timeString != timeStr)
    {
        d_timeString = timeStr;
        emit timeStringChanged();
    }
}

}  // namespace pages::tsc
