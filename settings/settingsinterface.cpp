#include "settingsinterface.h"
#include "settingscontroller.h"

SettingsInterface::SettingsInterface(QObject *parent) : QObject(parent)
{
}

void SettingsInterface::setTemperatureUnit(int unitId)
{
    SettingsController::setTemperatureUnit(unitId);
    emit temperatureUnitChanged();
}

int SettingsInterface::getTemperatureUnit() const
{
    return SettingsController::temperatureUnit();
}

void SettingsInterface::setPressureUnit(int unitId)
{
    SettingsController::setPressureUnit(unitId);
    emit pressureUnitChanged();
}

int SettingsInterface::getPressureUnit() const
{
    return SettingsController::pressureUnit();
}

void SettingsInterface::setShowMapFuelRange(bool show)
{
    SettingsController::setShowMapFuelRange(show);
    emit showMapFuelRangeChanged();
}

bool SettingsInterface::getShowMapFuelRange() const
{
    return SettingsController::showMapFuelRange();
}

void SettingsInterface::setShowRangeRings(bool show)
{
    SettingsController::setShowRangeRings(show);
    emit showRangeRingsChanged();
}

bool SettingsInterface::getShowRangeRings() const
{
    return SettingsController::showRangeRings();
}

void SettingsInterface::setShowRangeRingText(bool show)
{
    SettingsController::setShowRangeRingText(show);
    emit showRangeRingTextChanged();
}

bool SettingsInterface::getShowRangeRingText() const
{
    return SettingsController::showRangeRingText();
}
