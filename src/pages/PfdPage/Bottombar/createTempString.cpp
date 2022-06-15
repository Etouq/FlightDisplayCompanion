#include "Bottombar.hpp"
#include <cmath>

namespace pages::pfd
{

void Bottombar::createTempString(QString &str, float temperature) const
{
    switch (d_tempUnit)
    {
        case 1:
            str = QString::number(std::lround(temperature * 1.8 + 32.0)) + "ºF";
            break;
        case 2:
            str = QString::number(std::lround(temperature + 273.15)) + "K";
            break;
        case 3:
            str = QString::number(std::lround((temperature + 273.15) * 1.8)) + "ºR";
            break;
        case 0: [[likely]]
        default:
            str = QString::number(std::lround(temperature)) + "ºC";
            break;
    }

}

}

