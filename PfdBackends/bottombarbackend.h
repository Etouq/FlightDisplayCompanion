#ifndef BOTTOMBARBACKEND_H
#define BOTTOMBARBACKEND_H

#include <QObject>
#include <QString>

class BottombarBackend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString zuluTime READ zuluTime NOTIFY zuluTimeChanged)
    Q_PROPERTY(QString localTime READ localTime NOTIFY localTimeChanged)
    Q_PROPERTY(int groundSpeed READ groundSpeed NOTIFY groundSpeedChanged)
    Q_PROPERTY(QString totalAirTemp READ totalAirTemp NOTIFY totalAirTempChanged)

    QString d_zuluTime = "--:--:--";
    QString d_localTime = "--:--:--";
    int d_groundSpeed = 0;
    QString d_totalAirTemp = "0ºC";
    double d_tatValue = 0;

    int d_tempUnit = 0; // 0: Celsius, 1: fahrenheit, 2: kelvin, 3: rankine

public:
    explicit BottombarBackend(QObject *parent = nullptr);

    QString zuluTime() const;
    QString localTime() const;
    int groundSpeed() const;
    QString totalAirTemp() const;

signals:
    void zuluTimeChanged();
    void localTimeChanged();
    void groundSpeedChanged();
    void totalAirTempChanged();

public slots:
    void updateZuluTime(int newValue);
    void updateLocalTime(int newValue);
    void updateGroundSpeed(int newValue);
    void updateTotalAirTemp(float newValue);
    void updateTemperatureUnit(int unit);
};

#endif   // BOTTOMBARBACKEND_H
