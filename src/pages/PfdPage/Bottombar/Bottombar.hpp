#ifndef __BOTTOMBAR_HPP__
#define __BOTTOMBAR_HPP__

#include <QDateTime>
#include <QObject>
#include <QString>
#include "common/Units.hpp"

namespace io::network
{
class NetworkClient;
}

namespace pages::pfd
{

class Bottombar : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString zuluTime READ zuluTime NOTIFY zuluTimeChanged)
    Q_PROPERTY(QString localTime READ localTime NOTIFY localTimeChanged)
    Q_PROPERTY(int groundSpeed READ groundSpeed NOTIFY groundSpeedChanged)
    Q_PROPERTY(QString totalAirTemp READ totalAirTemp NOTIFY totalAirTempChanged)
    Q_PROPERTY(QString outsideAirTemp READ outsideAirTemp NOTIFY outsideAirTempChanged)
    Q_PROPERTY(QString stdAtmAirTemp READ stdAtmAirTemp NOTIFY stdAtmAirTempChanged)
    Q_PROPERTY(int tempUnit READ tempUnit NOTIFY tempUnitChanged)

public:

    explicit Bottombar(io::network::NetworkClient *netClient, QObject *parent = nullptr);

    const QString &zuluTime() const
    {
        return d_zuluTime;
    }

    const QString &localTime() const
    {
        return d_localTime;
    }

    int groundSpeed() const
    {
        return d_groundSpeed;
    }

    const QString &totalAirTemp() const
    {
        return d_totalAirTemp;
    }

    const QString &outsideAirTemp() const
    {
        return d_outsideAirTemp;
    }

    const QString &stdAtmAirTemp() const
    {
        return d_stdAtmAirTemp;
    }

    int tempUnit() const
    {
        switch (d_tempUnit)
        {
            default:
            case Units::CELSIUS:
                return 0;
            case Units::FAHRENHEIT:
                return 1;
            case Units::KELVIN:
                return 2;
            case Units::RANKINE:
                return 3;
        }
    }

signals:
    void zuluTimeChanged();
    void localTimeChanged();
    void groundSpeedChanged();
    void totalAirTempChanged();
    void outsideAirTempChanged();
    void stdAtmAirTempChanged();

    void tempUnitChanged();

public slots:

    void updateZuluTime(int newValue)
    {
        d_zuluTime = QDateTime::fromSecsSinceEpoch(newValue, Qt::UTC).toString("HH:mm:ss");
        emit zuluTimeChanged();
    }

    void updateLocalTime(int newValue)
    {
        d_localTime = QDateTime::fromSecsSinceEpoch(newValue, Qt::UTC).toString("HH:mm:ss");
        emit localTimeChanged();
    }

    void updateGroundSpeed(int newValue)
    {
        d_groundSpeed = newValue;
        emit groundSpeedChanged();
    }

    void updateTotalAirTemp(float newValue)
    {
        createTempString(d_totalAirTemp, newValue);
        d_tatValue = newValue;
        emit totalAirTempChanged();
    }

    void updateOutsideAirTemp(float newValue)
    {
        createTempString(d_outsideAirTemp, newValue);
        d_oatValue = newValue;
        emit outsideAirTempChanged();
    }

    void updateStdAtmAirTemp(float newValue)
    {
        createTempString(d_stdAtmAirTemp, newValue);
        d_isaValue = newValue;
        emit stdAtmAirTempChanged();
    }

    void updateTemperatureUnit(int unit)
    {
        switch (unit)
        {
            default:
            case 0:
                d_tempUnit = Units::CELSIUS;
                break;
            case 1:
                d_tempUnit = Units::FAHRENHEIT;
                break;
            case 2:
                d_tempUnit = Units::KELVIN;
                break;
            case 3:
                d_tempUnit = Units::RANKINE;
                break;
        }

        emit tempUnitChanged();

        updateTotalAirTemp(d_tatValue);
        updateOutsideAirTemp(d_oatValue);
        updateStdAtmAirTemp(d_isaValue);
    }

private:

    void createTempString(QString &str, float temperature) const;

    QString d_zuluTime = "--:--:--";
    QString d_localTime = "--:--:--";
    int d_groundSpeed = 0;
    QString d_totalAirTemp = "0ºC";
    QString d_outsideAirTemp = "0ºC";
    QString d_stdAtmAirTemp = "0ºC";
    double d_tatValue = 0;
    double d_oatValue = 0;
    double d_isaValue = 0;

    Units d_tempUnit = Units::CELSIUS;  // 0: Celsius, 1: fahrenheit, 2: kelvin, 3: rankine
};

}  // namespace pages::pfd


#endif  // __BOTTOMBAR_HPP__