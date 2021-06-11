#include "settingscontroller.h"

SettingsController::SettingsController()
{
    if (settings == nullptr)
        settings = new QSettings();
}

SettingsController::~SettingsController()
{
    delete settings;
}

bool SettingsController::firstTimeSetupCompleted()
{
    return d_firstTimeSetupCompleted;
}

QString SettingsController::dataPath()
{
    return d_dataPath;
}

QString SettingsController::lastUsedAddress()
{
    return d_lastUsedAddress;
}

int SettingsController::lastUsedPort()
{
    return d_lastUsedPort;
}

int SettingsController::temperatureUnit()
{
    return d_tempUnit;
}

int SettingsController::pressureUnit()
{
    return d_pressureUnit;
}

bool SettingsController::showMapFuelRange()
{
    return d_showMapFuelRange;
}

bool SettingsController::showRangeRings()
{
    return d_showRangeRings;
}

bool SettingsController::showRangeRingText()
{
    return d_showRangeRingText;
}

void SettingsController::setFirstTimeSetupCompleted(bool newValue)
{
    settings->setValue("firstTimeSetupCompleted", newValue);
    d_firstTimeSetupCompleted = newValue;
}

void SettingsController::setDataPath(const QString &newValue)
{
    settings->setValue("dataPath", newValue);
    d_dataPath = newValue;
}

void SettingsController::setLastUsedAddress(const QString &newValue)
{
    settings->setValue("lastUsedAddress", newValue);
    d_lastUsedAddress = newValue;
}

void SettingsController::setLastUsedPort(int newValue)
{
    settings->setValue("lastUsedPort", newValue);
    d_lastUsedPort = newValue;
}

void SettingsController::setTemperatureUnit(int unitId)
{
    settings->setValue("temperatureUnit", unitId);
    d_tempUnit = unitId;
}

void SettingsController::setPressureUnit(int unitId)
{
    settings->setValue("pressureUnit", unitId);
    d_pressureUnit = unitId;
}

void SettingsController::setShowMapFuelRange(bool show)
{
    settings->setValue("showMapFuelRange", show);
    d_showMapFuelRange = show;
}

void SettingsController::setShowRangeRings(bool show)
{
    settings->setValue("showRangeRings", show);
    d_showRangeRings = show;
}

void SettingsController::setShowRangeRingText(bool show)
{
    settings->setValue("showRangeRingText", show);
    d_showRangeRingText = show;
}

void SettingsController::clearSettings()
{
    setFirstTimeSetupCompleted(false);
    setDataPath("");

    setLastUsedAddress("");
    setLastUsedPort(-1);

    setTemperatureUnit(0);
    setPressureUnit(0);

    setShowMapFuelRange(true);
    setShowRangeRings(true);
    setShowRangeRingText(true);
}

void SettingsController::init()
{
    if (settings == nullptr)
        settings = new QSettings();

    d_firstTimeSetupCompleted = settings->value("firstTimeSetupCompleted", false).toBool();
    d_dataPath = settings->value("dataPath", "").toString();

    d_lastUsedAddress = settings->value("lastUsedAddress", "").toString();
    d_lastUsedPort = settings->value("lastUsedPort", -1).toInt();

    d_tempUnit = settings->value("temperatureUnit", 0).toInt();
    d_pressureUnit = settings->value("pressureUnit", 0).toInt();

    d_showMapFuelRange = settings->value("showMapFuelRange", true).toBool();
    d_showRangeRings = settings->value("showRangeRings", true).toBool();
    d_showRangeRingText = settings->value("showRangeRingText", true).toBool();


    settings->setValue("firstTimeSetupCompleted", d_firstTimeSetupCompleted);
    settings->setValue("dataPath", d_dataPath);

    settings->setValue("lastUsedAddress", d_lastUsedAddress);
    settings->setValue("lastUsedPort", d_lastUsedPort);

    settings->setValue("temperatureUnit", d_tempUnit);
    settings->setValue("pressureUnit", d_pressureUnit);

    settings->setValue("showMapFuelRange", d_showMapFuelRange);
    settings->setValue("showRangeRings", d_showRangeRings);
    settings->setValue("showRangeRingText", d_showRangeRingText);
}
