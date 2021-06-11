#include "bottombarbackend.h"

#include <QDateTime>

BottombarBackend::BottombarBackend(QObject *parent) : QObject(parent)
{
}

QString BottombarBackend::zuluTime() const
{
    return d_zuluTime;
}

QString BottombarBackend::localTime() const
{
    return d_localTime;
}

int BottombarBackend::groundSpeed() const
{
    return d_groundSpeed;
}

int BottombarBackend::totalAirTemp() const
{
    return d_totalAirTemp;
}


void BottombarBackend::updateZuluTime(int newValue)
{
    d_zuluTime = QDateTime::fromSecsSinceEpoch(newValue, Qt::UTC).toString("HH:mm:ss");
    emit zuluTimeChanged();
}

void BottombarBackend::updateLocalTime(int newValue)
{
    d_localTime = QDateTime::fromSecsSinceEpoch(newValue, Qt::UTC).toString("HH:mm:ss");
    emit localTimeChanged();
}

void BottombarBackend::updateGroundSpeed(int newValue)
{
    d_groundSpeed = newValue;
    emit groundSpeedChanged();
}

void BottombarBackend::updateTotalAirTemp(int newValue)
{
    d_totalAirTemp = newValue;
    emit totalAirTempChanged();
}
