#include "FlightPlan.hpp"

namespace pages::mfd
{

void FlightPlan::updateWpEte(int64_t newValue)
{
    if (newValue == 0)
        d_gpsWpEte = "__:__";
    else if (newValue < 3600)
    {
        int sec = newValue % 60;
        d_gpsWpEte = QString("%1:%2").arg(newValue / 60).arg(sec, 2, 10, QChar('0'));
    }
    else
    {
        int min = (newValue % 3600) / 60;
        d_gpsWpEte = QString("%1:%2").arg(newValue / 3600).arg(min, 2, 10, QChar('0'));
    }

    emit wpEteChanged();
}

}  // namespace pages::mfd
