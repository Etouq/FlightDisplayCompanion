#include "airspeedindicatorbackend.h"
#include <cmath>

AirspeedIndicatorBackend::AirspeedIndicatorBackend(QObject *parent) : QObject(parent)
{
}

void AirspeedIndicatorBackend::updateAirspeed(double newValue)
{
    d_airspeed = newValue;
    emit airspeedChanged();
}

void AirspeedIndicatorBackend::updateMaxSpeed(double newValue)
{
    d_max_speed = newValue;
    emit maxSpeedChanged();
}

void AirspeedIndicatorBackend::updateDynamicMaxSpeed(double newValue)
{
    if (!d_dynamic_max)
        return;
    d_max_speed = newValue;
    emit maxSpeedChanged();
}

void AirspeedIndicatorBackend::updateTrueAirspeed(int newValue)
{
    d_true_airspeed = newValue;
    emit trueAirspeedChanged();
}

void AirspeedIndicatorBackend::updateRefSpeed(int newValue)
{
    d_ref_speed = newValue;
    emit refSpeedChanged();
}

void AirspeedIndicatorBackend::updateColors(double minSpeed,
                                            double flapsBegin,
                                            double flapsEnd,
                                            double greenBegin,
                                            double greenEnd,
                                            double yellowBegin,
                                            double yellowEnd,
                                            double redBegin,
                                            double redEnd,
                                            double maxSpeed,
                                            bool noColor,
                                            bool dynamicMax)
{
    d_min_speed = minSpeed;
    d_flaps_begin = flapsBegin;
    d_flaps_end = flapsEnd;
    d_green_begin = greenBegin;
    d_green_end = greenEnd;
    d_yellow_begin = yellowBegin;
    d_yellow_end = yellowEnd;
    d_red_begin = redBegin;
    d_red_end = redEnd;
    d_max_speed = maxSpeed;

    d_noColor = noColor;
    d_dynamic_max = dynamicMax;
    emit colorsChanged();
}


double AirspeedIndicatorBackend::getMinSpeed() const
{
    return d_min_speed;
}
double AirspeedIndicatorBackend::getGreenBegin() const
{
    return d_green_begin;
}
double AirspeedIndicatorBackend::getGreenEnd() const
{
    return d_green_end;
}
double AirspeedIndicatorBackend::getYellowBegin() const
{
    return d_yellow_begin;
}
double AirspeedIndicatorBackend::getYellowEnd() const
{
    return d_yellow_end;
}
double AirspeedIndicatorBackend::getFlapsBegin() const
{
    return d_flaps_begin;
}
double AirspeedIndicatorBackend::getFlapsEnd() const
{
    return d_flaps_end;
}
double AirspeedIndicatorBackend::getRedBegin() const
{
    return d_red_begin;
}
double AirspeedIndicatorBackend::getRedEnd() const
{
    return d_red_end;
}
double AirspeedIndicatorBackend::getMaxSpeed() const
{
    return d_max_speed;
}

bool AirspeedIndicatorBackend::getNoColor() const
{
    return d_noColor;
}

double AirspeedIndicatorBackend::airspeed() const
{
    return d_airspeed;
}

double AirspeedIndicatorBackend::maxSpeed() const
{
    return d_max_speed;
}
int AirspeedIndicatorBackend::trueAirspeed() const
{
    return d_true_airspeed;
}
int AirspeedIndicatorBackend::refSpeed() const
{
    return d_ref_speed;
}
