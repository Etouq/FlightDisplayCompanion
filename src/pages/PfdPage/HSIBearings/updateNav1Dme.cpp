#include "HSIBearings.hpp"

namespace pages::pfd
{

void HSIBearings::updateNav1Dme(double newValue)
{
    d_nav1DmeDist = newValue;
    if (d_nav1HasNav)
    {
        QString newDist = d_nav1HasDme ? QString::number(d_nav1DmeDist, 'f', 1) + " NM" : "";
        if (d_nav1Distance != newDist)
        {
            d_nav1Distance = newDist;
            emit nav1DistanceChanged();
        }
    }
    else if (d_nav1Distance != "")
    {
        d_nav1Distance = "";
        emit nav1DistanceChanged();
    }

    if (d_nav1HasDme && d_nav1HasSignal)
    {
        QString newDist = QString::number(d_nav1DmeDist, 'f', 1) + " NM";
        if (d_nav1Dme != newDist)
        {
            d_nav1Dme = newDist;
            emit nav1DmeChanged();
        }
    }
    else
    {
        if (d_nav1Dme != "")
        {
            d_nav1Dme = "";
            emit nav1DmeChanged();
        }
    }
}

}  // namespace pages::pfd
