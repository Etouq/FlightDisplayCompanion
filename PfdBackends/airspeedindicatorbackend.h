#ifndef AIRSPEEDINDICATORBACKEND_H
#define AIRSPEEDINDICATORBACKEND_H

#include <QObject>


class AirspeedIndicatorBackend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double airspeed READ airspeed NOTIFY airspeedChanged)
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

    Q_PROPERTY(double maxSpeed READ maxSpeed NOTIFY maxSpeedChanged)
    Q_PROPERTY(double minSpeed READ minSpeed NOTIFY minSpeedChanged)
    Q_PROPERTY(int trueAirspeed READ trueAirspeed NOTIFY trueAirspeedChanged)
    Q_PROPERTY(int refSpeed READ refSpeed NOTIFY refSpeedChanged)

    // exposed items
    double d_airspeed = 20;
    int d_center = 60;
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

    void updateColorElements();

    double minSpeed() const;
    Q_INVOKABLE double getGreenBegin() const;
    Q_INVOKABLE double getGreenEnd() const;
    Q_INVOKABLE double getYellowBegin() const;
    Q_INVOKABLE double getYellowEnd() const;
    Q_INVOKABLE double getFlapsBegin() const;
    Q_INVOKABLE double getFlapsEnd() const;
    Q_INVOKABLE double getRedBegin() const;
    Q_INVOKABLE double getRedEnd() const;
    Q_INVOKABLE double getMaxSpeed() const;

    bool noColor() const;

    double airspeed() const;
    int center() const;
    double rawAirspeed() const;

    bool redCursor() const;

    double minTransform() const;
    double greenY() const;
    double greenHeight() const;
    double yellowY() const;
    double yellowHeight() const;
    double redY() const;
    double redHeight() const;
    double flapsY() const;
    double flapsHeight() const;
    double maxTransform() const;

    double maxSpeed() const;
    int trueAirspeed() const;
    int refSpeed() const;

signals:
    void airspeedChanged();
    void centerChanged();
    void maxTransformChanged();

    void redCursorChanged();

    void maxSpeedChanged();
    void minSpeedChanged();
    void trueAirspeedChanged();
    void refSpeedChanged();

    void noColorChanged();

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
