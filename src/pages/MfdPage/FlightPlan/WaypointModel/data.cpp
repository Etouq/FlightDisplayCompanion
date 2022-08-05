#include "WaypointModel.hpp"

namespace pages::mfd
{

QVariant WaypointModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= d_waypoints.size())
        return QVariant();

    switch (static_cast<WaypointRoles>(role))
    {
        case IdentRole:
        {
            return d_waypoints[index.row()].ident;
        }
        case TypeIconUrlRole:
        {
            switch (d_waypoints[index.row()].wpType)
            {
                case WaypointType::AIRPORT:
                    return "qrc:/images/miscImages/ICON_MAP_AIRPORT.png";
                case WaypointType::INTERSECTION:
                    return "qrc:/images/miscImages/ICON_MAP_INT.png";
                case WaypointType::NDB:
                    return "qrc:/images/miscImages/ICON_MAP_NDB.png";
                case WaypointType::USER:
                    return "qrc:/images/miscImages/ICON_MAP_USER.png";
                case WaypointType::VOR:
                    return "qrc:/images/miscImages/ICON_MAP_VOR_2.png";
                case WaypointType::ATC:
                case WaypointType::NONE:
                default:
                    return "qrc:/images/miscImages/ICON_MAP_USER.png";
            }
        }
        case LatitudeRole:
        {
            return d_waypoints[index.row()].position.latitude();
        }
        case LongitudeRole:
        {
            return d_waypoints[index.row()].position.longitude();
        }
        case AltitudeRole:
        {
            switch (d_waypoints[index.row()].altType)
            {
                case WpAltitudeType::NONE:
                    return " _____FT";
                case WpAltitudeType::AT:
                    return " " + QString::number(d_waypoints[index.row()].alt1) + "FT";
                case WpAltitudeType::AT_OR_BELOW:
                    return "B" + QString::number(d_waypoints[index.row()].alt1) + "FT";
                case WpAltitudeType::AT_OR_ABOVE:
                    return "A" + QString::number(d_waypoints[index.row()].alt1) + "FT";
                case WpAltitudeType::BETWEEN:
                    return "A" + QString::number(d_waypoints[index.row()].alt1) + "FT\nB"
                      + QString::number(d_waypoints[index.row()].alt2) + "FT";
                default:
                    return " _____FT";
            }
        }
        case SpeedRole:
        {
            const int16_t speed = d_waypoints[index.row()].speed;
            return speed < 0 ? "___KT" : (QString::number(speed) + "KT");
        }
        case DistanceRole:
        {
            if (index.row() == 0)
                return "";

            const WaypointCalculated &data = d_calculatedData[index.row()];

            const double legDistance = data.legDistance;
            const double totalDistance = data.totalDistance;
            return QString("%1NM\n%2NM")
              .arg(legDistance, 0, 'f', legDistance < 100 ? 1 : 0)
              .arg(totalDistance, 0, 'f', totalDistance < 100 ? 1 : 0);
        }
        case BearingRole:
        {
            if (index.row() == 0)
                return "";
            return QString("%1°").arg(d_calculatedData[index.row()].bearing, 3);
        }
        case MapIconUrlRole:
        {
            switch (d_waypoints[index.row()].wpType)
            {
                case WaypointType::AIRPORT:
                    return "qrc:/images/mapImages/ICON_MAP_AIRPORT_NON_TOWERED_SERVICED_PINK.png";
                case WaypointType::INTERSECTION:
                    return "qrc:/images/mapImages/ICON_MAP_INTERSECTION.png";
                case WaypointType::NDB:
                    return "qrc:/images/mapImages/ICON_MAP_NDB_WAYPOINT.png";
                case WaypointType::USER:
                    return "qrc:/images/mapImages/ICON_MAP_USERWAYPOINT.png";
                case WaypointType::VOR:
                    return "qrc:/images/mapImages/ICON_MAP_VOR.png";
                case WaypointType::ATC:
                case WaypointType::NONE:
                default:
                    return "qrc:/images/mapImages/ICON_MAP_USERWAYPOINT.png";
            }
        }
        default:
            return QVariant();
    }
}

}  // namespace pages::mfd