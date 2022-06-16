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
    WaypointType wpType = WaypointType::AIRPORT;
    WpAltitudeType altType = WpAltitudeType::AT;
};

}  // namespace pages::mfd

class QmlWaypointTypeClass
{
Q_GADGET

    public:

    enum class Value
    {
        NONE = static_cast<int>(pages::mfd::WaypointType::NONE),
        AIRPORT = static_cast<int>(pages::mfd::WaypointType::AIRPORT),
        INTERSECTION = static_cast<int>(pages::mfd::WaypointType::INTERSECTION),
        VOR = static_cast<int>(pages::mfd::WaypointType::VOR),
        NDB = static_cast<int>(pages::mfd::WaypointType::NDB),
        USER = static_cast<int>(pages::mfd::WaypointType::USER),
        ATC = static_cast<int>(pages::mfd::WaypointType::ATC)
    };
    Q_ENUM(Value)

private:
    explicit QmlWaypointTypeClass();
};

class QmlWpAltitudeTypeClass
{
Q_GADGET

    public:

    enum class Value
    {
        NONE = static_cast<int>(pages::mfd::WpAltitudeType::NONE),
        AT = static_cast<int>(pages::mfd::WpAltitudeType::AT),
        AT_OR_BELOW = static_cast<int>(pages::mfd::WpAltitudeType::AT_OR_BELOW),
        AT_OR_ABOVE = static_cast<int>(pages::mfd::WpAltitudeType::AT_OR_ABOVE),
        BETWEEN = static_cast<int>(pages::mfd::WpAltitudeType::BETWEEN)
    };
    Q_ENUM(Value)

private:
    explicit QmlWpAltitudeTypeClass();
};

typedef QmlWaypointTypeClass::Value QmlWaypointType;
typedef QmlWpAltitudeTypeClass::Value QmlWpAltitudeType;

#endif  // __FLIGHTPLAN_WAYPOINT_HPP__