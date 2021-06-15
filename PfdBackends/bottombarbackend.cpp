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

QString BottombarBackend::totalAirTemp() const
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

void BottombarBackend::updateTotalAirTemp(float newValue)
{
    switch (d_tempUnit)
    {
        case 1:
            d_totalAirTemp = QString::number(lround(newValue * 1.8 + 32.0)) + "ºF";
            break;
        case 2:
            d_totalAirTemp = QString::number(lround(newValue + 273.15)) + "K";
            break;
        case 3:
            d_totalAirTemp = QString::number(lround((newValue + 273.15) * 1.8)) + "ºR";
            break;
        case 0:
        default:
            d_totalAirTemp = QString::number(lround(newValue)) + "ºC";
            break;
    }

    d_tatValue = newValue;
    emit totalAirTempChanged();
}

void BottombarBackend::updateTemperatureUnit(int unit)
{
    d_tempUnit = unit;
    updateTotalAirTemp(d_tatValue);
}
