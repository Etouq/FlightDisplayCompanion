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
    Q_PROPERTY(int totalAirTemp READ totalAirTemp NOTIFY totalAirTempChanged)

    QString d_zuluTime = "--:--:--";
    QString d_localTime = "--:--:--";
    int d_groundSpeed = 0;
    int d_totalAirTemp = 0;

public:
    explicit BottombarBackend(QObject *parent = nullptr);

    QString zuluTime() const;
    QString localTime() const;
    int groundSpeed() const;
    int totalAirTemp() const;

signals:
    void zuluTimeChanged();
    void localTimeChanged();
    void groundSpeedChanged();
    void totalAirTempChanged();

public slots:
    void updateZuluTime(int newValue);
    void updateLocalTime(int newValue);
    void updateGroundSpeed(int newValue);
    void updateTotalAirTemp(int newValue);
};

#endif   // BOTTOMBARBACKEND_H
