#include "HSIBearings.hpp"

namespace pages::pfd
{

void HSIBearings::updateNav2Dme(double newValue)
{
    d_nav2DmeDist = newValue;
    if (d_nav2HasNav)
    {
        QString newDist = d_nav2HasDme ? QString::number(d_nav2DmeDist, 'f', 1) + " NM" : "";
        if (d_nav2Distance != newDist)
        {
            d_nav2Distance = newDist;
            emit nav2DistanceChanged();
        }
    }
    else if (d_nav2Distance != "")
    {
        d_nav2Distance = "";
        emit nav2DistanceChanged();
    }

    if (d_nav2HasDme && d_nav2HasSignal)
    {
        QString newDist = QString::number(d_nav2DmeDist, 'f', 1) + " NM";
        if (d_nav2Dme != newDist)
        {
            d_nav2Dme = newDist;
            emit nav2DmeChanged();
        }
    }
    else
    {
        if (d_nav2Dme != "")
        {
            d_nav2Dme = "";
            emit nav2DmeChanged();
        }
    }
}

}  // namespace pages::pfd
