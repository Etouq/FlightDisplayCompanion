#include "FlightPlan.hpp"

namespace pages::mfd
{

void FlightPlan::updateZuluTime(int64_t newValue)
{
    d_zuluTime = newValue;

    if (d_gpsDestEte == 0)
        d_gpsDestEta = "__:__UTC";
    else
    {
        int etaSec = (d_zuluTime + d_gpsDestEte) % (24 * 3600);
        int hours = etaSec / 3600;
        int minutes = (etaSec / 60) % 60;
        d_gpsDestEta = QString("%1:%2UTC").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0'));
    }
    emit destEtaChanged();
}

}  // namespace pages::mfd
