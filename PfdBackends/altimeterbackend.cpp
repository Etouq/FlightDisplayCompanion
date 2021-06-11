#include "altimeterbackend.h"

#include <cmath>

AltimeterBackend::AltimeterBackend(QObject *parent) : QObject(parent)
{
}


void AltimeterBackend::updateAltitude(double newValue)
{
    int newCenter = std::lround(newValue / 100.0) * 100;
    if (d_center != newCenter)
    {
        d_center = newCenter;
        emit centerChanged();
    }
    d_altitude = newValue;
    emit altitudeChanged();
}

void AltimeterBackend::updateRadarAltitude(double newValue)
{
    if (newValue < 0.0 || newValue > 2500.0)
    {
        if (d_radarAltitudeTransformValue < 700.0)
        {
            d_radarAltitudeTransformValue = 700.0;
            emit radarAltitudeTransformValueChanged();
        }
        if (d_radarAltitude != 3000)
        {
            d_radarAltitude = 3000;
            emit radarAltitudeChanged();
        }
        return;
    }
    d_radarAltitudeTransformValue = std::min(300.0 + newValue * 1.6, 700.0) * d_scaleFactor;
    emit radarAltitudeTransformValueChanged();
    if (d_radarAltitude != std::lround(newValue))
    {
        d_radarAltitude = std::lround(newValue);
        emit radarAltitudeChanged();
    }
}

void AltimeterBackend::updateReferenceAltitude(int newValue)
{
    d_reference_altitude = newValue;
    emit referenceAltitudeChanged();
}


void AltimeterBackend::updateVspeed(double newValue)
{
    d_vspeedIndicatorTransformValue = (newValue >= 2500.0 ? -250.0 : newValue <= -2500.0 ? 250.0 : -newValue / 10.0) * d_scaleFactor;
    emit vspeedIndicatorTransformValueChanged();

    d_altitudeTrendValue = newValue >= 2000 ? -50 : newValue <= -2000 ? 550 : 250.0 - 0.15 * newValue;
    emit altitudeTrendValueChanged();

    QString newSpeedText = (std::abs(newValue) >= 100.0 ? QString::number(lround(newValue / 50.0) * 50) : "");
    if (d_vspeedTextValue != newSpeedText)
    {
        d_vspeedTextValue = newSpeedText;
        emit vspeedTextValueChanged();
    }
}

void AltimeterBackend::updateReferenceVspeed(int newValue)
{
    d_reference_vspeed = newValue;
    emit referenceVspeedChanged();
}


void AltimeterBackend::updatePressure(double newValue)
{
    d_pressure = newValue;
    emit pressureChanged();
}


void AltimeterBackend::updateVerticalDeviationMode(int newValue)
{
    d_vertical_deviation_mode = newValue;
    emit verticalDeviationModeChanged();
    if (newValue != 0)
        emit verticalDeviationTransformValueChanged();
}

void AltimeterBackend::updateVerticalDeviationValue(double newValue)
{
    d_verticalDeviationTransformValue = (newValue <= -1 ? -200 : newValue >= 1 ? 200 : newValue * 200) * d_scaleFactor;
    emit verticalDeviationTransformValueChanged();
}


int AltimeterBackend::center() const
{
    return d_center;
}
double AltimeterBackend::altitude() const
{
    return d_altitude;
}
int AltimeterBackend::radarAltitude() const
{
    return d_radarAltitude;
}
double AltimeterBackend::radarAltitudeTransformValue() const
{
    return d_radarAltitudeTransformValue;
}
int AltimeterBackend::referenceAltitude() const
{
    return d_reference_altitude;
}

double AltimeterBackend::vspeedIndicatorTransformValue() const
{
    return d_vspeedIndicatorTransformValue;
}
QString AltimeterBackend::vspeedTextValue() const
{
    return d_vspeedTextValue;
}
int AltimeterBackend::referenceVspeed() const
{
    return d_reference_vspeed;
}

double AltimeterBackend::pressure() const
{
    return d_pressure;
}

int AltimeterBackend::verticalDeviationMode() const
{
    return d_vertical_deviation_mode;
}
double AltimeterBackend::verticalDeviationTransformValue() const
{
    return d_verticalDeviationTransformValue;
}

double AltimeterBackend::altitudeTrendValue() const
{
    return d_altitudeTrendValue;
}
