#include "FlightPlan.hpp"

namespace pages::mfd
{

void FlightPlan::editWp(int idx,
                        double lat,
                        double lon,
                        int alt1,
                        int alt2,
                        QString ident,
                        QmlWaypointType wpType,
                        QmlWpAltitudeType altType)
{
    d_waypoints[idx] = { .position = QGeoCoordinate(lat, lon),
                         .alt1 = alt1,
                         .alt2 = alt2,
                         .ident = ident,
                         .wpType = static_cast<WaypointType>(wpType),
                         .altType = static_cast<WpAltitudeType>(altType) };
    emit flightplanChanged();
}

}  // namespace pages::mfd
