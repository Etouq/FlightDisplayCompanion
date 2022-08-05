#ifndef __FLIGHTPLAN_HPP__
#define __FLIGHTPLAN_HPP__

#include "FlightPlanWaypoint.hpp"
#include "WaypointModel/WaypointModel.hpp"

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

    Q_PROPERTY(int activeLegIdx READ activeLegIdx NOTIFY activeLegIdxChanged)
    Q_PROPERTY(double wpDtk READ wpDtk NOTIFY wpDtkChanged)
    Q_PROPERTY(QString wpEte READ wpEte NOTIFY wpEteChanged)
    Q_PROPERTY(QString destEta READ destEta NOTIFY destEtaChanged)

public:

    explicit FlightPlan(io::network::NetworkClient *netClient, QObject *parent = nullptr);

    int activeLegIdx() const
    {
        return d_activeLegIdx;
    }

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

signals:

    void flightplanChanged();
    void wpDtkChanged();
    void wpEteChanged();
    void destEtaChanged();
    void activeLegIdxChanged();

public slots:

    void clearFlightplan()
    {
        d_wpModel.clear();
        emit flightplanChanged();
    }

    void receivedFlightplan(const QList<FlightPlanWaypoint> &wpList)
    {
        d_wpModel.overwrite(std::vector<FlightPlanWaypoint>(wpList.begin(), wpList.end()));
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

    void updateActiveLegIdx(int newIdx)
    {
        d_activeLegIdx = newIdx;
        emit activeLegIdxChanged();
    }

private:

    double d_gpsWpDtk = 0;

    QString d_gpsWpEte = "__:__";
    QString d_gpsDestEta = "__:__UTC";

    int64_t d_gpsDestEte = 0;
    int64_t d_zuluTime = 0;

    WaypointModel d_wpModel;

    int d_activeLegIdx = -1;
};

}  // namespace pages::mfd


#endif  // __FLIGHTPLAN_HPP__
