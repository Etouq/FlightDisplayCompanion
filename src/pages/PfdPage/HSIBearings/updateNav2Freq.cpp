#include "HSIBearings.hpp"

namespace pages::pfd
{

void HSIBearings::updateNav2Freq(double newValue)
{
    d_nav2InternalFreq = newValue;
    if (d_nav2HasSignal && d_nav2HasDme)
    {
        QString newFreq = QString::number(newValue, 'f', 2);
        if (d_nav2Freq != newFreq)
        {
            d_nav2Freq = newFreq;
            emit nav2FreqChanged();
        }
    }
    else
    {
        if (d_nav2Freq != "")
        {
            d_nav2Freq = "";
            emit nav2FreqChanged();
        }
    }
}

}  // namespace pages::pfd
