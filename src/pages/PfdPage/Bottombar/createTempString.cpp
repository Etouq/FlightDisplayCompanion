#include "Bottombar.hpp"
#include <cmath>

namespace pages::pfd
{

void Bottombar::createTempString(QString &str, float temperature) const
{
    switch (d_tempUnit)
    {
        case Units::FAHRENHEIT:
            str = QString::number(std::lround(temperature * 1.8 + 32.0)) + "ºF";
            break;
        case Units::KELVIN:
            str = QString::number(std::lround(temperature + 273.15)) + "K";
            break;
        case Units::RANKINE:
            str = QString::number(std::lround((temperature + 273.15) * 1.8)) + "ºR";
            break;
        case Units::CELSIUS: [[likely]]
        default:
            str = QString::number(std::lround(temperature)) + "ºC";
            break;
    }

}

}

