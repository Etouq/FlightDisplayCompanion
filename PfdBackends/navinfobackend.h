#ifndef NAVINFOBACKEND_H
#define NAVINFOBACKEND_H

#include <QObject>
#include <QString>

class navInfoBackend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool gpsIsActiveFlightPlan READ gpsIsActiveFlightPlan NOTIFY gpsIsActiveFlightPlanChanged)
    Q_PROPERTY(QString currentLegTo READ currentLegTo NOTIFY currentLegToChanged)
    Q_PROPERTY(QString currentLegFrom READ currentLegFrom NOTIFY currentLegFromChanged)
    Q_PROPERTY(bool legIsDirectTo READ legIsDirectTo NOTIFY legIsDirectToChanged)
    Q_PROPERTY(QString currentLegDistance READ currentLegDistance NOTIFY currentLegDistanceChanged)
    Q_PROPERTY(QString currentLegBearing READ currentLegBearing NOTIFY currentLegBearingChanged)

    // exposed items
    bool d_gpsIsActiveFlightPlan = false;
    QString d_currentLegTo = "";
    QString d_currentLegFrom = "";
    bool d_legIsDirectTo = false;
    QString d_currentLegDistance = "__._NM";
    QString d_currentLegBearing = "___°";


public:
    explicit navInfoBackend(QObject *parent = nullptr);

    bool gpsIsActiveFlightPlan() const;
    QString currentLegTo() const;
    QString currentLegFrom() const;
    bool legIsDirectTo() const;
    QString currentLegDistance() const;
    QString currentLegBearing() const;


signals:
    void gpsIsActiveFlightPlanChanged();
    void currentLegToChanged();
    void currentLegFromChanged();
    void legIsDirectToChanged();
    void currentLegDistanceChanged();
    void currentLegBearingChanged();

public slots:
    void updateGpsIsActiveFlightPlan(bool newValue);
    void updateCurrentLegTo(QString const &newValue);
    void updateCurrentLegFrom(QString const &newValue);
    void updateLegIsDirectTo(bool newValue);
    void updateCurrentLegDistance(double newValue);
    void updateCurrentLegBearing(int newValue);
};

#endif   // NAVINFOBACKEND_H
