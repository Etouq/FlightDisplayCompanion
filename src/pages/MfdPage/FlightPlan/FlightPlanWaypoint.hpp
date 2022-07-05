#ifndef __FLIGHTPLAN_WAYPOINT_HPP__
#define __FLIGHTPLAN_WAYPOINT_HPP__

#include <QGeoCoordinate>
#include <QObject>

namespace pages::mfd
{

enum class WaypointType : uint8_t
{
    NONE = 0,
    AIRPORT,
    INTERSECTION,
    VOR,
    NDB,
    USER,
    ATC
};

enum class WpAltitudeType: uint8_t
{
    NONE = 0,
    AT,
    AT_OR_BELOW,
    AT_OR_ABOVE,
    BETWEEN
};

struct FlightPlanWaypoint
{
    QGeoCoordinate position = QGeoCoordinate(0, 0);
    int32_t alt1 = 0;
    int32_t alt2 = 0;
    QString ident = "";
    WaypointType wpType = WaypointType::NONE;
    WpAltitudeType altType = WpAltitudeType::NONE;
};

}  // namespace pages::mfd



#endif  // __FLIGHTPLAN_WAYPOINT_HPP__
