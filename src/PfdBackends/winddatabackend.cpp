#include "winddatabackend.hpp"

#include <cmath>

WindDataBackend::WindDataBackend(QObject *parent) : QObject(parent)
{
}

double WindDataBackend::windDirection() const
{
    return d_wind_direction;
}

double WindDataBackend::windStrength() const
{
    return d_wind_strength;
}

double WindDataBackend::windTrueDirection() const
{
    return d_wind_true_direction;
}

void WindDataBackend::updateWindDirection(double newValue)
{
    d_wind_direction = newValue;
    emit windDirectionChanged();
}

void WindDataBackend::updateWindStrength(double newValue)
{
    d_wind_strength = newValue;
    emit windStrengthChanged();
}

void WindDataBackend::updateWindTrueDirection(double newValue)
{
    d_wind_true_direction = newValue;
    emit windTrueDirectionChanged();
}
