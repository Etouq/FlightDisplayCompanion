#ifndef __NAVINFO_HPP__
#define __NAVINFO_HPP__

#include "io/NetworkClient/NetworkClient.hpp"

#include <QObject>
#include <QString>

namespace pages::pfd
{

class NavInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool gpsIsActiveFlightPlan READ gpsIsActiveFlightPlan NOTIFY gpsIsActiveFlightPlanChanged)
    Q_PROPERTY(QString currentLegTo READ currentLegTo NOTIFY currentLegToChanged)
    Q_PROPERTY(QString currentLegFrom READ currentLegFrom NOTIFY currentLegFromChanged)
    Q_PROPERTY(bool legIsDirectTo READ legIsDirectTo NOTIFY legIsDirectToChanged)
    Q_PROPERTY(QString currentLegDistance READ currentLegDistance NOTIFY currentLegDistanceChanged)
    Q_PROPERTY(QString currentLegBearing READ currentLegBearing NOTIFY currentLegBearingChanged)

public:

    explicit NavInfo(io::network::NetworkClient *netClient, QObject *parent = nullptr)
      : QObject(parent)
    {
        using io::network::NetworkClient;
        connect(netClient, &NetworkClient::gpsIsActiveFlightplanChanged, this, &NavInfo::updateGpsIsActiveFlightPlan);
        connect(netClient, &NetworkClient::currentLegToChanged, this, &NavInfo::updateCurrentLegTo);
        connect(netClient, &NetworkClient::currentLegFromChanged, this, &NavInfo::updateCurrentLegFrom);
        connect(netClient, &NetworkClient::legIsDirectToChanged, this, &NavInfo::updateLegIsDirectTo);
        connect(netClient, &NetworkClient::gpsDistanceChanged, this, &NavInfo::updateCurrentLegDistance);
        connect(netClient, &NetworkClient::gpsBearingChanged, this, &NavInfo::updateCurrentLegBearing);
    }

    bool gpsIsActiveFlightPlan() const
    {
        return d_gpsIsActiveFlightPlan;
    }

    QString currentLegTo() const
    {
        return d_currentLegTo;
    }

    QString currentLegFrom() const
    {
        return d_currentLegFrom;
    }

    bool legIsDirectTo() const
    {
        return d_legIsDirectTo;
    }

    QString currentLegDistance() const
    {
        return d_currentLegDistance;
    }

    QString currentLegBearing() const
    {
        return d_currentLegBearing;
    }

signals:

    void gpsIsActiveFlightPlanChanged();
    void currentLegToChanged();
    void currentLegFromChanged();
    void legIsDirectToChanged();
    void currentLegDistanceChanged();
    void currentLegBearingChanged();

public slots:

    void updateGpsIsActiveFlightPlan(bool newValue)
    {
        d_gpsIsActiveFlightPlan = newValue;
        emit gpsIsActiveFlightPlanChanged();
    }

    void updateCurrentLegTo(QString const &newValue)
    {
        if (d_currentLegTo != newValue)
        {
            d_currentLegTo = newValue;
            emit currentLegToChanged();
        }
    }

    void updateCurrentLegFrom(QString const &newValue)
    {
        if (d_currentLegFrom != newValue)
        {
            d_currentLegFrom = newValue;
            emit currentLegFromChanged();
        }
    }

    void updateLegIsDirectTo(bool newValue)
    {
        d_legIsDirectTo = newValue;
        emit legIsDirectToChanged();
    }

    void updateCurrentLegDistance(double newValue)
    {
        d_currentLegDistance = QString::number(newValue, 'f', 1) + "NM";
        emit currentLegDistanceChanged();
    }

    void updateCurrentLegBearing(int newValue)
    {
        d_currentLegBearing = QString("%1°").arg(newValue, 3, 10, QChar('0'));
        emit currentLegBearingChanged();
    }

private:

    // exposed items
    bool d_gpsIsActiveFlightPlan = false;
    QString d_currentLegTo = "";
    QString d_currentLegFrom = "";
    bool d_legIsDirectTo = false;
    QString d_currentLegDistance = "__._NM";
    QString d_currentLegBearing = "___°";
};

}  // namespace pages::pfd

#endif  // __NAVINFO_HPP__