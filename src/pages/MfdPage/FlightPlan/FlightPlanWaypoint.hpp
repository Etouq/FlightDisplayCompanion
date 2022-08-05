#ifndef __FLIGHTPLAN_WAYPOINT_HPP__
#define __FLIGHTPLAN_WAYPOINT_HPP__

#include <QGeoCoordinate>
#include <QIODevice>
#include <string>

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
    int16_t speed = 0;

    std::string toBinary() const
    {
        double coordElement = position.latitude();
        std::string ret(reinterpret_cast<const char *>(&coordElement), sizeof(coordElement));
        coordElement = position.longitude();
        ret.append(reinterpret_cast<const char *>(&coordElement), sizeof(coordElement));

        QByteArray identData = ident.toUtf8();
        uint8_t identSize = identData.size();

        ret.append(reinterpret_cast<const char *>(&identSize), sizeof(identSize));
        ret.append(identData.constData(), identSize);

        ret.append(reinterpret_cast<const char *>(&alt1), sizeof(alt1));
        ret.append(reinterpret_cast<const char *>(&alt2), sizeof(alt2));
        ret.append(reinterpret_cast<const char *>(&wpType), sizeof(wpType));
        ret.append(reinterpret_cast<const char *>(&altType), sizeof(altType));
        ret.append(reinterpret_cast<const char *>(&speed), sizeof(speed));

        return ret;
    }

    static FlightPlanWaypoint fromBinary(QIODevice &data)
    {
        FlightPlanWaypoint ret;
        double coordElement = 0;
        data.read(reinterpret_cast<char *>(&coordElement), sizeof(coordElement));
        ret.position.setLatitude(coordElement);
        data.read(reinterpret_cast<char *>(&coordElement), sizeof(coordElement));
        ret.position.setLongitude(coordElement);

        uint8_t identSize = 0;
        data.read(reinterpret_cast<char *>(&identSize), sizeof(identSize));

        ret.ident = QString::fromUtf8(data.read(identSize));

        data.read(reinterpret_cast<char *>(&ret.alt1), sizeof(ret.alt1));
        data.read(reinterpret_cast<char *>(&ret.alt2), sizeof(ret.alt2));
        data.read(reinterpret_cast<char *>(&ret.wpType), sizeof(ret.wpType));
        data.read(reinterpret_cast<char *>(&ret.altType), sizeof(ret.altType));
        data.read(reinterpret_cast<char *>(&ret.speed), sizeof(ret.speed));

        return ret;
    }
};

}  // namespace pages::mfd



#endif  // __FLIGHTPLAN_WAYPOINT_HPP__
