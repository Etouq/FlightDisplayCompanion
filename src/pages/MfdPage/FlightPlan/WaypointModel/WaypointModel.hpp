#ifndef __WAYPOINT_MODEL_HPP__
#define __WAYPOINT_MODEL_HPP__

#include "../FlightPlanWaypoint.hpp"

#include <QAbstractListModel>
#include <vector>
#include <QDebug>

namespace pages::mfd
{

class WaypointModel : public QAbstractListModel
{
    Q_OBJECT

    struct WaypointCalculated
    {
        double legDistance;
        double totalDistance;
        int bearing;
        // QString iconUrl;
    };

public:

    enum WaypointRoles
    {
        IdentRole = Qt::UserRole + 1,
        TypeIconUrlRole,
        LatitudeRole,
        LongitudeRole,
        AltitudeRole,
        SpeedRole,
        DistanceRole,
        BearingRole,
        MapIconUrlRole
    };

    explicit WaypointModel(QObject *parent = nullptr)
      : QAbstractListModel(parent)
    {}


    void overwrite(const std::vector<FlightPlanWaypoint> &waypoints)
    {
        if (waypoints.empty())
            return clear();

        beginResetModel();

        d_waypoints = waypoints;

        d_calculatedData = { WaypointCalculated() };

        double totalDistance = 0;
        QGeoCoordinate lastPosition = d_waypoints.front().position;

        for (auto begin = d_waypoints.cbegin() + 1, end = d_waypoints.cend(); begin != end; ++begin)
        {
            // both give 0 if d_waypoints is empty (since lastposition is invalid)
            const double distance = lastPosition.distanceTo(begin->position) / 1852.0;
            const int bearing = std::lround(lastPosition.azimuthTo(begin->position));

            totalDistance += distance;

            d_calculatedData.push_back({ distance, totalDistance, bearing });

            lastPosition = begin->position;
        }

        endResetModel();

        emit flightplanTitleChanged();
    }

    Q_INVOKABLE QString getTitle()
    {
        if (d_waypoints.size() == 0)
            return "____/____";

        if (d_waypoints.size() == 1)
            return d_waypoints.front().ident + "/____";

        return d_waypoints.front().ident + "/" + d_waypoints.back().ident;
    }

    Q_INVOKABLE QString getIdent(int idx)
    {
        return d_waypoints.at(idx).ident;
    }

    Q_INVOKABLE QString getWpIcon(int idx)
    {
        switch (d_waypoints[idx].wpType)
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

    void clear()
    {
        beginRemoveRows(QModelIndex(), 0, d_waypoints.size() - 1);
        d_waypoints.clear();
        d_calculatedData.clear();
        endRemoveRows();

        emit flightplanTitleChanged();
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const
    {
        Q_UNUSED(parent);
        return d_waypoints.size();
    }

    Q_INVOKABLE QGeoCoordinate position(int index) const
    {
        if (index < 0 || index >= d_waypoints.size())
            return QGeoCoordinate();
        return d_waypoints.at(index).position;
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    const std::vector<FlightPlanWaypoint> &data() const
    {
        return d_waypoints;
    }

    QList<FlightPlanWaypoint> dataAsList() const
    {
        return QList(d_waypoints.cbegin(), d_waypoints.cend());
    }

    const FlightPlanWaypoint &at(size_t pos) const
    {
        return d_waypoints[pos];
    }

signals:

    void flightplanTitleChanged();

protected:

    QHash<int, QByteArray> roleNames() const
    {
        return { { IdentRole, "ident" },
                 { TypeIconUrlRole, "wpTypeUrl" },
                 { LatitudeRole, "lat" },
                 { LongitudeRole, "lon" },
                 { AltitudeRole, "altTypeText" },
                 { SpeedRole, "speed" },
                 { DistanceRole, "dist" },
                 { BearingRole, "dtk" },
                 { MapIconUrlRole, "mapIconUrl" } };
    }

private:

    std::vector<FlightPlanWaypoint> d_waypoints;
    std::vector<WaypointCalculated> d_calculatedData;
};

}  // namespace flightplan

#endif  // __WAYPOINT_MODEL_HPP__