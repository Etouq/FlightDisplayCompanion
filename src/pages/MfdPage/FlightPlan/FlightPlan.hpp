#ifndef __FLIGHTPLAN_HPP__
#define __FLIGHTPLAN_HPP__

#include "FlightPlanWaypoint.hpp"
#include "common/QmlEnums.hpp"

#include <QList>
#include <QObject>
#include <QString>

namespace io::network
{
class NetworkClient;
}

namespace pages::mfd
{

class FlightPlan : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double wpDtk READ wpDtk NOTIFY wpDtkChanged)
    Q_PROPERTY(QString wpEte READ wpEte NOTIFY wpEteChanged)
    Q_PROPERTY(QString destEta READ destEta NOTIFY destEtaChanged)

public:

    explicit FlightPlan(io::network::NetworkClient *netClient, QObject *parent = nullptr);

    double wpDtk() const
    {
        return d_gpsWpDtk;
    }

    const QString &wpEte() const
    {
        return d_gpsWpEte;
    }

    const QString &destEta() const
    {
        return d_gpsDestEta;
    }

    Q_INVOKABLE int getFlightPlanSize() const
    {
        return static_cast<int>(d_waypoints.size());
    }

    Q_INVOKABLE QGeoCoordinate getPosition(int idx) const
    {
        return d_waypoints[idx].position;
    }

    Q_INVOKABLE int getAltitude1(int idx) const
    {
        return d_waypoints[idx].alt1;
    }

    Q_INVOKABLE int getAltitude2(int idx) const
    {
        return d_waypoints[idx].alt2;
    }

    Q_INVOKABLE const QString &getIdent(int idx) const
    {
        return d_waypoints[idx].ident;
    }

    Q_INVOKABLE QmlWaypointType getWpType(int idx) const
    {
        return static_cast<QmlWaypointType>(d_waypoints[idx].wpType);
    }

    Q_INVOKABLE QmlWpAltitudeType getAltType(int idx) const
    {
        return static_cast<QmlWpAltitudeType>(d_waypoints[idx].altType);
    }

    Q_INVOKABLE double getLegDistanceTo(int idx) const
    {
        if (idx == 0)
            return -1.0;
        return d_waypoints[idx - 1].position.distanceTo(d_waypoints[idx].position) / 1852.0;
    }

    Q_INVOKABLE double getCumulativeDistance(int idx) const
    {
        if (idx == 0)
            return -1.0;
        double totalDist = 0.0;
        for (int i = 1; i <= idx; i++)
            totalDist += d_waypoints[i - 1].position.distanceTo(d_waypoints[i].position);
        return totalDist / 1852.0;
    }

    Q_INVOKABLE int getLegBearing(int idx) const
    {
        if (idx == 0)
            return -1.0;
        return std::lround(d_waypoints[idx - 1].position.azimuthTo(d_waypoints[idx].position));
    }

    Q_INVOKABLE void appendWp(double lat,
                              double lon,
                              int alt1,
                              int alt2,
                              QString ident,
                              QmlWaypointType wpType,
                              QmlWpAltitudeType altType);

    Q_INVOKABLE void insertWp(int idx,
                              double lat,
                              double lon,
                              int alt1,
                              int alt2,
                              QString ident,
                              QmlWaypointType wpType,
                              QmlWpAltitudeType altType);

    Q_INVOKABLE void removeWp(int idx)
    {
        d_waypoints.removeAt(idx);
        emit flightplanChanged();
    }

    Q_INVOKABLE void editWp(int idx,
                            double lat,
                            double lon,
                            int alt1,
                            int alt2,
                            QString ident,
                            QmlWaypointType wpType,
                            QmlWpAltitudeType altType);


signals:

    void flightplanChanged();
    void wpDtkChanged();
    void wpEteChanged();
    void destEtaChanged();

public slots:

    void clearFlightplan()
    {
        d_waypoints.clear();
        emit flightplanChanged();
    }

    void receivedFlightplan(const QList<FlightPlanWaypoint> &wpList)
    {
        d_waypoints = wpList;
        emit flightplanChanged();
    }

    void updateWpDtk(double newValue)
    {
        d_gpsWpDtk = newValue;
        emit wpDtkChanged();
    }

    void updateWpEte(int64_t newValue);
    void updateDestEte(int64_t newValue);
    void updateZuluTime(int64_t newValue);

private:

    double d_gpsWpDtk = 0;

    QString d_gpsWpEte = "__:__";
    QString d_gpsDestEta = "__:__UTC";

    int64_t d_gpsDestEte = 0;
    int64_t d_zuluTime = 0;

    QList<FlightPlanWaypoint> d_waypoints;
};

}  // namespace pages::mfd


#endif  // __FLIGHTPLAN_HPP__