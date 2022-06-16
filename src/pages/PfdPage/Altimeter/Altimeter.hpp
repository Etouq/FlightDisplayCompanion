#ifndef __ALTIMETER_HPP__
#define __ALTIMETER_HPP__

#include "common/typeEnums.hpp"

#include <QObject>
#include <QString>

namespace io::network
{
class NetworkClient;
}

namespace pages::pfd
{

class Altimeter : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int center READ center NOTIFY centerChanged)
    Q_PROPERTY(double altitude READ altitude NOTIFY altitudeChanged)
    Q_PROPERTY(int radarAltitude READ radarAltitude NOTIFY radarAltitudeChanged)
    Q_PROPERTY(
      double radarAltitudeTransformValue READ radarAltitudeTransformValue NOTIFY radarAltitudeTransformValueChanged)
    Q_PROPERTY(int referenceAltitude READ referenceAltitude NOTIFY referenceAltitudeChanged)

    Q_PROPERTY(double vspeedIndicatorTransformValue READ vspeedIndicatorTransformValue NOTIFY
                 vspeedIndicatorTransformValueChanged)
    Q_PROPERTY(QString vspeedTextValue READ vspeedTextValue NOTIFY vspeedTextValueChanged)
    Q_PROPERTY(int referenceVspeed READ referenceVspeed NOTIFY referenceVspeedChanged)

    Q_PROPERTY(double pressure READ pressure NOTIFY pressureChanged)

    Q_PROPERTY(QmlVerticalDeviationMode vertDevMode READ vertDevMode NOTIFY vertDevModeChanged)
    Q_PROPERTY(double vertDevTransformValue READ vertDevTransformValue NOTIFY vertDevTransformValueChanged)

    Q_PROPERTY(double altitudeTrendValue READ altitudeTrendValue NOTIFY altitudeTrendValueChanged)

    // minimums
    Q_PROPERTY(int minimumsValue MEMBER d_minimumsValue NOTIFY minimumsValueChanged)
    Q_PROPERTY(int minimumsState MEMBER d_minimumsState NOTIFY minimumsStateChanged)
    Q_PROPERTY(int minimumAltitude READ minimumAltitude NOTIFY minimumAltitudeChanged)

public:

    explicit Altimeter(io::network::NetworkClient *netClient, QObject *parent = nullptr);

    int center() const
    {
        return d_center;
    }

    double altitude() const
    {
        return d_altitude;
    }

    int radarAltitude() const
    {
        return d_radarAltitude;
    }

    double radarAltitudeTransformValue() const
    {
        return d_radarAltitudeTransformValue;
    }

    int referenceAltitude() const
    {
        return d_referenceAltitude;
    }

    double vspeedIndicatorTransformValue() const
    {
        return d_vspeedIndicatorTransformValue;
    }

    const QString &vspeedTextValue() const
    {
        return d_vspeedTextValue;
    }

    int referenceVspeed() const
    {
        return d_referenceVspeed;
    }

    double pressure() const
    {
        return d_pressure;
    }

    QmlVerticalDeviationMode vertDevMode() const
    {
        return static_cast<QmlVerticalDeviationMode>(d_vertDevMode);
    }

    double vertDevTransformValue() const
    {
        return d_vertDevTransformValue;
    }

    double altitudeTrendValue() const
    {
        return d_altitudeTrendValue;
    }

    int minimumAltitude() const
    {
        return d_minimumAltitude;
    }

    Q_INVOKABLE void updateMinimumAlt();

signals:
    void centerChanged();
    void altitudeChanged();
    void radarAltitudeChanged();
    void radarAltitudeTransformValueChanged();
    void referenceAltitudeChanged();

    void vspeedIndicatorTransformValueChanged();
    void vspeedTextValueChanged();
    void referenceVspeedChanged();

    void pressureChanged();

    void vertDevModeChanged();
    void vertDevTransformValueChanged();

    void altitudeTrendValueChanged();

    void minimumsValueChanged();
    void minimumsStateChanged();
    void minimumAltitudeChanged();

public slots:
    void updateAltitude(double newValue);
    void updateRadarAltitude(double newValue);

    void updateReferenceAltitude(int newValue)
    {
        d_referenceAltitude = newValue;
        emit referenceAltitudeChanged();
    }

    void updateVspeed(double newValue);

    void updateReferenceVspeed(int newValue)
    {
        d_referenceVspeed = newValue;
        emit referenceVspeedChanged();
    }

    void updatePressure(double newValue)
    {
        d_pressure = newValue;
        emit pressureChanged();
    }

    void updateVertDevMode(VerticalDeviationMode newValue)
    {
        d_vertDevMode = newValue;
        emit vertDevModeChanged();
        if (newValue != VerticalDeviationMode::NONE)
            emit vertDevTransformValueChanged();
    }

    void updateVertDevValue(double newValue)
    {
        d_vertDevTransformValue = newValue <= -1 ? -192 : newValue >= 1 ? 192 : newValue * 192;
        emit vertDevTransformValueChanged();
    }

private:

    // exposed items
    int d_center = 0;
    double d_altitude = 0;
    int d_radarAltitude = 0;
    double d_radarAltitudeTransformValue = 288;
    int d_referenceAltitude = 0;

    double d_vspeedIndicatorTransformValue = 0;
    QString d_vspeedTextValue = "-0000";
    int d_referenceVspeed = 0;

    double d_pressure = 29.92;

    VerticalDeviationMode d_vertDevMode = VerticalDeviationMode::NONE;
    double d_vertDevTransformValue = 0;

    double d_altitudeTrendValue = 250;

    // minimums
    int d_minimumsValue = 0;    // set value
    int d_minimumsState = 0;    // 0: off, 1: baro, 2: radio
    int d_minimumAltitude = 0;  // value transformed if mode is radio

    // variables for cdi source and vertical deviation mode/value are selected on server side
    // internal items
    double d_scaleFactor = 0.96;
    double d_realRadioAltitude = 0;
};

}  // namespace pages::pfd


#endif  // __ALTIMETER_HPP__