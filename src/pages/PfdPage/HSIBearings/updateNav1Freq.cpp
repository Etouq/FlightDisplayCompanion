#include "HSIBearings.hpp"

namespace pages::pfd
{

void HSIBearings::updateNav1Freq(double newValue)
{
    d_nav1InternalFreq = newValue;
    if (d_nav1HasSignal && d_nav1HasDme)
    {
        QString newFreq = QString::number(newValue, 'f', 2);
        if (d_nav1Freq != newFreq)
        {
            d_nav1Freq = newFreq;
            emit nav1FreqChanged();
        }
    }
    else
    {
        if (d_nav1Freq != "")
        {
            d_nav1Freq = "";
            emit nav1FreqChanged();
        }
    }
}

}  // namespace pages::pfd
