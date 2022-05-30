#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include <QSettings>
#include <QString>

// static class used to provide easy access to settings
class SettingsController
{
    inline static QSettings *settings = nullptr;

    inline static bool d_firstTimeSetupCompleted = false;
    inline static QString d_dataPath = "";

    inline static QString d_lastUsedAddress = "";
    inline static int d_lastUsedPort = -1;

    inline static int d_tempUnit = 0; // 0: Celsius, 1: fahrenheit, 2: kelvin, 3: rankine
    inline static int d_pressureUnit = 0; // 0: inHg, 1: mbar

    inline static bool d_showMapFuelRange = true;
    inline static bool d_showRangeRings = true;
    inline static bool d_showRangeRingText = true;

    inline static int d_iconIdx = 0;
    inline static double d_iconSize = 1;
    inline static QString d_iconColor = "white";
    inline static QString d_iconBorderColor = "black";

public:
    static bool firstTimeSetupCompleted();
    static QString dataPath();

    static QString lastUsedAddress();
    static int lastUsedPort();

    static int temperatureUnit();
    static int pressureUnit();

    static bool showMapFuelRange();
    static bool showRangeRings();
    static bool showRangeRingText();

    static int iconIdx();
    static double iconSize();
    static QString iconColor();
    static QString iconBorderColor();

    static void setFirstTimeSetupCompleted(bool newValue);
    static void setDataPath(const QString &newValue);

    static void setLastUsedAddress(const QString &newValue);
    static void setLastUsedPort(int newValue);

    static void setTemperatureUnit(int unitId);
    static void setPressureUnit(int unitId);

    static void setShowMapFuelRange(bool show);
    static void setShowRangeRings(bool show);
    static void setShowRangeRingText(bool show);

    static void setIconIdx(int idx);
    static void setIconSize(double size);
    static void setIconColor(const QString &color);
    static void setIconBorderColor(const QString &color);

    static void clearSettings();

    static void init();

private:
    SettingsController();
    ~SettingsController();
};

#endif   // SETTINGSCONTROLLER_H
