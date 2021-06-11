#include "navinfobackend.h"

navInfoBackend::navInfoBackend(QObject *parent) : QObject(parent)
{
}

bool navInfoBackend::gpsIsActiveFlightPlan() const
{
    return d_gpsIsActiveFlightPlan;
}

QString navInfoBackend::currentLegTo() const
{
    return d_currentLegTo;
}

QString navInfoBackend::currentLegFrom() const
{
    return d_currentLegFrom;
}

bool navInfoBackend::legIsDirectTo() const
{
    return d_legIsDirectTo;
}

QString navInfoBackend::currentLegDistance() const
{
    return d_currentLegDistance;
}

QString navInfoBackend::currentLegBearing() const
{
    return d_currentLegBearing;
}

void navInfoBackend::updateGpsIsActiveFlightPlan(bool newValue)
{
    d_gpsIsActiveFlightPlan = newValue;
    emit gpsIsActiveFlightPlanChanged();
}

void navInfoBackend::updateCurrentLegTo(const QString &newValue)
{
    if (d_currentLegTo != newValue)
    {
        d_currentLegTo = newValue;
        emit currentLegToChanged();
    }
}

void navInfoBackend::updateCurrentLegFrom(const QString &newValue)
{
    if (d_currentLegFrom != newValue)
    {
        d_currentLegFrom = newValue;
        emit currentLegFromChanged();
    }
}

void navInfoBackend::updateLegIsDirectTo(bool newValue)
{
    d_legIsDirectTo = newValue;
    emit legIsDirectToChanged();
}

void navInfoBackend::updateCurrentLegDistance(double newValue)
{
    d_currentLegDistance = QString::number(newValue, 'f', 1) + "NM";
    emit currentLegDistanceChanged();
}

void navInfoBackend::updateCurrentLegBearing(int newValue)
{
    d_currentLegBearing = QString("%1°").arg(newValue, 3, 10, QChar('0'));
    emit currentLegBearingChanged();
}
