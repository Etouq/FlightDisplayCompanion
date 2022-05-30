#include "angleofattackindicatorbackend.hpp"

AngleOfAttackIndicatorBackend::AngleOfAttackIndicatorBackend(QObject *parent) : QObject(parent)
{
}

void AngleOfAttackIndicatorBackend::updateAoa(double newValue)
{
    d_aoaAngle = 230 - newValue >= 90 ? 90 : 230 - newValue <= 0 ? 0 : 230 - newValue;
    emit aoaAngleChanged();

    QColor newCursorColor = d_aoaAngle >= (1.0 - d_redPercent / 100.0) * 90.0 ? QColor(255, 0, 0, 255) : QColor(255, 255, 255, 255);
    if (newCursorColor != d_cursorColor)
    {
        d_cursorColor = newCursorColor;
        emit cursorColorChanged();
    }
}

double AngleOfAttackIndicatorBackend::aoaAngle() const
{
    return d_aoaAngle;
}
QColor AngleOfAttackIndicatorBackend::cursorColor() const
{
    return d_cursorColor;
}
