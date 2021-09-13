#include "airspeedindicatorbackend.h"
#include <cmath>

AirspeedIndicatorBackend::AirspeedIndicatorBackend(QObject *parent) : QObject(parent)
{
}

void AirspeedIndicatorBackend::updateColorElements()
{
    double dCenter = static_cast<double>(d_center);

    if (d_min_speed > 0)
        d_minTransform = 1185.6 + 9.6 * (dCenter - d_min_speed);
    if (d_max_speed > 0)
    {
        d_maxTransform = fmin(fmax((dCenter - d_max_speed) * 9.6 + 384.0, -96.0), 768.0);
        emit maxTransformChanged();
    }

    d_greenY = fmin(fmax(-96.0, 288.0 + 9.6 * (dCenter - d_green_end)), 672.0);
    d_greenHeight = fmin(fmax(-96.0, 288.0 + 9.6 * (dCenter - d_green_begin)), 672.0) - d_greenY;
    d_yellowY = fmin(fmax(-96.0, 288.0 + 9.6 * (dCenter - d_yellow_end)), 672.0);
    d_yellowHeight = fmin(fmax(-96.0, 288.0 + 9.6 * (dCenter - d_yellow_begin)), 672.0) - d_yellowY;
    d_redY = fmin(fmax(-96.0, 288.0 + 9.6 * (dCenter - d_red_end)), 672.0);
    d_redHeight = fmin(fmax(-96.0, 288.0 + 9.6 * (dCenter - d_red_begin)), 672.0) - d_redY;
    d_flapsY = fmin(fmax(-96.0, 288.0 + 9.6 * (dCenter - d_flaps_end)), 672.0);
    d_flapsHeight = fmin(fmax(-96.0, 288.0 + 9.6 * (dCenter - d_flaps_begin)), 672.0) - d_flapsY;

}

void AirspeedIndicatorBackend::updateAirspeed(double newValue)
{
    d_rawAirspeed = newValue;

    d_airspeed = fmax(newValue, 20.0);
    emit airspeedChanged();

    int newCenter = std::max(lround(newValue / 10.0) * 10, 60l);
    if (d_center != newCenter)
    {
        d_center = newCenter;
        if (!d_noColor)
            updateColorElements();
        emit centerChanged();
    }

    bool newRedCursor = !d_noColor && (d_airspeed < d_min_speed || (d_max_speed > 0 && d_airspeed > d_max_speed));
    if (d_redCursor != newRedCursor)
    {
        d_redCursor = newRedCursor;
        emit redCursorChanged();
    }
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
    if (!d_noColor)
        if (d_max_speed > 0)
        {
            d_maxTransform = fmin(fmax((static_cast<double>(d_center) * d_max_speed) * 9.6 + 384.0, -96.0), 768.0);
            emit maxTransformChanged();
        }
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
    d_center = std::max(lround(d_rawAirspeed / 10.0) * 10, 60l);;
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
    emit noColorChanged();
    emit minSpeedChanged();
    emit colorsChanged();

    updateColorElements();
    emit centerChanged();
}


double AirspeedIndicatorBackend::minSpeed() const
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

bool AirspeedIndicatorBackend::noColor() const
{
    return d_noColor;
}

double AirspeedIndicatorBackend::airspeed() const
{
    return d_airspeed;
}

int AirspeedIndicatorBackend::center() const
{
    return d_center;
}

double AirspeedIndicatorBackend::rawAirspeed() const
{
    return d_rawAirspeed;
}

double AirspeedIndicatorBackend::minTransform() const
{
    return d_minTransform;
}

double AirspeedIndicatorBackend::greenY() const
{
    return d_greenY;
}

double AirspeedIndicatorBackend::greenHeight() const
{
    return d_greenHeight;
}

double AirspeedIndicatorBackend::yellowY() const
{
    return d_yellowY;
}

double AirspeedIndicatorBackend::yellowHeight() const
{
    return d_yellowHeight;
}

double AirspeedIndicatorBackend::redY() const
{
    return d_redY;
}

double AirspeedIndicatorBackend::redHeight() const
{
    return d_redHeight;
}

double AirspeedIndicatorBackend::flapsY() const
{
    return d_flapsY;
}

double AirspeedIndicatorBackend::flapsHeight() const
{
    return d_flapsHeight;
}

double AirspeedIndicatorBackend::maxTransform() const
{
    return d_maxTransform;
}


bool AirspeedIndicatorBackend::redCursor() const
{
    return d_redCursor;
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
