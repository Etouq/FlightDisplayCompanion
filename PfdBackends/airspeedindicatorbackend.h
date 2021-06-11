#ifndef AIRSPEEDINDICATORBACKEND_H
#define AIRSPEEDINDICATORBACKEND_H

#include <QObject>


class AirspeedIndicatorBackend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double airspeed READ airspeed NOTIFY airspeedChanged)
    Q_PROPERTY(double maxSpeed READ maxSpeed NOTIFY maxSpeedChanged)
    Q_PROPERTY(int trueAirspeed READ trueAirspeed NOTIFY trueAirspeedChanged)
    Q_PROPERTY(int refSpeed READ refSpeed NOTIFY refSpeedChanged)

    // exposed items
    double d_airspeed = 0;

    // color positions
    double d_min_speed = 0;
    double d_green_begin = 0;
    double d_green_end = 0;
    double d_yellow_begin = 0;
    double d_yellow_end = 0;
    double d_flaps_begin = 0;
    double d_flaps_end = 0;
    double d_red_begin = 0;
    double d_red_end = 0;
    double d_max_speed = 0;   // is also barberpole
    bool d_noColor = false;

    int d_true_airspeed = 0;


    int d_ref_speed = 0;

    bool d_dynamic_max = false;


public:
    explicit AirspeedIndicatorBackend(QObject *parent = nullptr);

    Q_INVOKABLE double getMinSpeed() const;
    Q_INVOKABLE double getGreenBegin() const;
    Q_INVOKABLE double getGreenEnd() const;
    Q_INVOKABLE double getYellowBegin() const;
    Q_INVOKABLE double getYellowEnd() const;
    Q_INVOKABLE double getFlapsBegin() const;
    Q_INVOKABLE double getFlapsEnd() const;
    Q_INVOKABLE double getRedBegin() const;
    Q_INVOKABLE double getRedEnd() const;
    Q_INVOKABLE double getMaxSpeed() const;

    Q_INVOKABLE bool getNoColor() const;

    double airspeed() const;
    double maxSpeed() const;
    int trueAirspeed() const;
    int refSpeed() const;

signals:
    void airspeedChanged();
    void maxSpeedChanged();
    void trueAirspeedChanged();
    void refSpeedChanged();

    void colorsChanged();

public slots:
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
    void updateAirspeed(double newValue);
    void updateMaxSpeed(double newValue);
    void updateDynamicMaxSpeed(double newValue);
    void updateTrueAirspeed(int newValue);
    void updateRefSpeed(int newValue);
};

#endif   // AIRSPEEDINDICATORBACKEND_H
