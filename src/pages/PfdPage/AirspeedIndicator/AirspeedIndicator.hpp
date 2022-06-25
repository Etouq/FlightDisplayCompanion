#ifndef __AIRSPEEDINDICATOR_HPP__
#define __AIRSPEEDINDICATOR_HPP__


#include <QObject>
#include <chrono>

namespace io::network
{
class NetworkClient;
}

namespace pages::pfd
{

class AirspeedIndicator : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double airspeed READ airspeed NOTIFY airspeedChanged)
    Q_PROPERTY(double acceleration READ acceleration NOTIFY airspeedChanged)
    Q_PROPERTY(int center READ center NOTIFY centerChanged)
    Q_PROPERTY(double rawAirspeed READ rawAirspeed NOTIFY airspeedChanged)

    Q_PROPERTY(bool redCursor READ redCursor NOTIFY redCursorChanged)

    Q_PROPERTY(double minTransform READ minTransform NOTIFY centerChanged)
    Q_PROPERTY(double greenY READ greenY NOTIFY centerChanged)
    Q_PROPERTY(double greenHeight READ greenHeight NOTIFY centerChanged)
    Q_PROPERTY(double yellowY READ yellowY NOTIFY centerChanged)
    Q_PROPERTY(double yellowHeight READ yellowHeight NOTIFY centerChanged)
    Q_PROPERTY(double redY READ redY NOTIFY centerChanged)
    Q_PROPERTY(double redHeight READ redHeight NOTIFY centerChanged)
    Q_PROPERTY(double flapsY READ flapsY NOTIFY centerChanged)
    Q_PROPERTY(double flapsHeight READ flapsHeight NOTIFY centerChanged)
    Q_PROPERTY(double maxTransform READ maxTransform NOTIFY maxTransformChanged)

    Q_PROPERTY(bool noColor READ noColor NOTIFY noColorChanged)

    Q_PROPERTY(double minSpeed READ minSpeed NOTIFY minSpeedChanged)
    Q_PROPERTY(double maxSpeed READ maxSpeed NOTIFY maxSpeedChanged)
    Q_PROPERTY(int trueAirspeed READ trueAirspeed NOTIFY trueAirspeedChanged)
    Q_PROPERTY(int refSpeed READ refSpeed NOTIFY refSpeedChanged)

public:

    explicit AirspeedIndicator(io::network::NetworkClient *netClient, QObject *parent = nullptr);

    double airspeed() const
    {
        return d_airspeed;
    }
    double acceleration() const
    {
        return d_acceleration;
    }
    int center() const
    {
        return d_center;
    }
    double rawAirspeed() const
    {
        return d_rawAirspeed;
    }

    bool redCursor() const
    {
        return d_redCursor;
    }

    double minTransform() const
    {
        return d_minTransform;
    }
    double greenY() const
    {
        return d_greenY;
    }
    double greenHeight() const
    {
        return d_greenHeight;
    }
    double yellowY() const
    {
        return d_yellowY;
    }
    double yellowHeight() const
    {
        return d_yellowHeight;
    }
    double redY() const
    {
        return d_redY;
    }
    double redHeight() const
    {
        return d_redHeight;
    }
    double flapsY() const
    {
        return d_flapsY;
    }
    double flapsHeight() const
    {
        return d_flapsHeight;
    }
    double maxTransform() const
    {
        return d_maxTransform;
    }

    bool noColor() const
    {
        return d_noColor;
    }

    double minSpeed() const
    {
        return d_minSpeed;
    }
    double maxSpeed() const
    {
        return d_maxSpeed;
    }
    int trueAirspeed() const
    {
        return d_trueAirspeed;
    }
    int refSpeed() const
    {
        return d_refSpeed;
    }

    void updateColors(double minSpeed,
                      double flapsBegin,
                      double flapsEnd,
                      double greenBegin,
                      double greenEnd,
                      double yellowBegin,
                      double yellowEnd,
                      double redBegin,
                      double redEnd,
                      double maxSpeed,
                      bool noColor,
                      bool dynamicMax = false);

signals:
    void airspeedChanged();
    void centerChanged();

    void redCursorChanged();

    void maxTransformChanged();

    void noColorChanged();

    void minSpeedChanged();
    void maxSpeedChanged();
    void trueAirspeedChanged();
    void refSpeedChanged();

public slots:

    void updateAirspeed(double newValue);
    void updateMaxSpeed(double newValue); // for dynamic max speed
    void updateTrueAirspeed(int newValue)
    {
        d_trueAirspeed = newValue;
        emit trueAirspeedChanged();
    }
    void updateRefSpeed(int newValue)
    {
        d_refSpeed = newValue;
        emit refSpeedChanged();
    }

private:
    void updateColorElements();

    void updateAcceleration(double newAirspeed);

    // exposed items
    double d_airspeed = 20;
    double d_acceleration = 0;
    int d_center = -10000;
    double d_rawAirspeed = 0;

    bool d_redCursor = false;

    double d_minTransform = 0;
    double d_greenY = -1;
    double d_greenHeight = 0;
    double d_yellowY = -1;
    double d_yellowHeight = 0;
    double d_redY = -1;
    double d_redHeight = 0;
    double d_flapsY = -1;
    double d_flapsHeight = 0;
    double d_maxTransform = 0;

    // color positions
    double d_minSpeed = 0;
    double d_greenBegin = 0;
    double d_greenEnd = 0;
    double d_yellowBegin = 0;
    double d_yellowEnd = 0;
    double d_flapsBegin = 0;
    double d_flapsEnd = 0;
    double d_redBegin = 0;
    double d_redEnd = 0;
    double d_maxSpeed = 0;  // is also barberpole
    bool d_noColor = false;

    int d_trueAirspeed = 0;
    int d_refSpeed = 0;

    bool d_dynamicMax = false;

    double d_lastSpeed = -1;

    std::chrono::steady_clock::time_point d_previousTime;

};

}  // namespace pages::pfd

#endif  // __AIRSPEEDINDICATOR_HPP__
