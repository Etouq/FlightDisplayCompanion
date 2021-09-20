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

int SettingsController::iconIdx()
{
    return d_iconIdx;
}

double SettingsController::iconSize()
{
    return d_iconSize;
}

QString SettingsController::iconColor()
{
    return d_iconColor;
}

QString SettingsController::iconBorderColor()
{
    return d_iconBorderColor;
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

void SettingsController::setIconIdx(int idx)
{
    settings->setValue("iconIdx", idx);
    d_iconIdx = idx;
}

void SettingsController::setIconSize(double size)
{
    settings->setValue("iconSize", size);
    d_iconSize = size;
}

void SettingsController::setIconColor(const QString &color)
{
    settings->setValue("iconColor", color);
    d_iconColor = color;
}

void SettingsController::setIconBorderColor(const QString &color)
{
    settings->setValue("iconBorderColor", color);
    d_iconBorderColor = color;
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

    setIconIdx(0);
    setIconSize(1);
    setIconColor("white");
    setIconBorderColor("black");
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

    d_iconIdx = settings->value("iconIdx", 0).toInt();
    d_iconSize = settings->value("iconSize", 1).toDouble();
    d_iconColor = settings->value("iconColor", "white").toString();
    d_iconBorderColor = settings->value("iconBorderColor", "black").toString();


    settings->setValue("firstTimeSetupCompleted", d_firstTimeSetupCompleted);
    settings->setValue("dataPath", d_dataPath);

    settings->setValue("lastUsedAddress", d_lastUsedAddress);
    settings->setValue("lastUsedPort", d_lastUsedPort);

    settings->setValue("temperatureUnit", d_tempUnit);
    settings->setValue("pressureUnit", d_pressureUnit);

    settings->setValue("showMapFuelRange", d_showMapFuelRange);
    settings->setValue("showRangeRings", d_showRangeRings);
    settings->setValue("showRangeRingText", d_showRangeRingText);

    settings->setValue("iconIdx", d_iconIdx);
    settings->setValue("iconSize", d_iconSize);
    settings->setValue("iconColor", d_iconColor);
    settings->setValue("iconBorderColor", d_iconBorderColor);
}
