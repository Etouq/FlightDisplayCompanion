#ifndef SETTINGSINTERFACE_H
#define SETTINGSINTERFACE_H

#include <QObject>

// interface for qml to access settings
class SettingsInterface : public QObject
{
    Q_OBJECT
public:
    explicit SettingsInterface(QObject *parent = nullptr);

    Q_INVOKABLE void setTemperatureUnit(int unitId);
    Q_INVOKABLE int getTemperatureUnit() const;

    Q_INVOKABLE void setPressureUnit(int unitId);
    Q_INVOKABLE int getPressureUnit() const;

    Q_INVOKABLE void setShowMapFuelRange(bool show);
    Q_INVOKABLE bool getShowMapFuelRange() const;

    Q_INVOKABLE void setShowRangeRings(bool show);
    Q_INVOKABLE bool getShowRangeRings() const;

    Q_INVOKABLE void setShowRangeRingText(bool show);
    Q_INVOKABLE bool getShowRangeRingText() const;

signals:
    void temperatureUnitChanged(int unit);
    void pressureUnitChanged();
    void showMapFuelRangeChanged();
    void showRangeRingsChanged();
    void showRangeRingTextChanged();
};

#endif   // SETTINGSINTERFACE_H
