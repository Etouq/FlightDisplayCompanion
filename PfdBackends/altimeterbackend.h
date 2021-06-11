#ifndef ALTIMETERBACKEND_H
#define ALTIMETERBACKEND_H

#include <QObject>
#include <QString>

// possible TODO: add altitude capture blink logic

class AltimeterBackend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int center READ center NOTIFY centerChanged)
    Q_PROPERTY(double altitude READ altitude NOTIFY altitudeChanged)
    Q_PROPERTY(int radarAltitude READ radarAltitude NOTIFY radarAltitudeChanged)
    Q_PROPERTY(double radarAltitudeTransformValue READ radarAltitudeTransformValue NOTIFY radarAltitudeTransformValueChanged)
    Q_PROPERTY(int referenceAltitude READ referenceAltitude NOTIFY referenceAltitudeChanged)

    Q_PROPERTY(double vspeedIndicatorTransformValue READ vspeedIndicatorTransformValue NOTIFY vspeedIndicatorTransformValueChanged)
    Q_PROPERTY(QString vspeedTextValue READ vspeedTextValue NOTIFY vspeedTextValueChanged)
    Q_PROPERTY(int referenceVspeed READ referenceVspeed NOTIFY referenceVspeedChanged)

    Q_PROPERTY(double pressure READ pressure NOTIFY pressureChanged)

    Q_PROPERTY(int verticalDeviationMode READ verticalDeviationMode NOTIFY verticalDeviationModeChanged)
    Q_PROPERTY(double verticalDeviationTransformValue READ verticalDeviationTransformValue NOTIFY verticalDeviationTransformValueChanged)

    Q_PROPERTY(double altitudeTrendValue READ altitudeTrendValue NOTIFY altitudeTrendValueChanged)

    // exposed items
    int d_center = 0;
    double d_altitude = 0;
    int d_radarAltitude = 0;
    double d_radarAltitudeTransformValue = 0;
    int d_reference_altitude = 0;

    double d_vspeedIndicatorTransformValue = 0;
    QString d_vspeedTextValue = "-0000";
    int d_reference_vspeed = 0;

    double d_pressure = 29.92;

    int d_vertical_deviation_mode = 0;   // 0: none, 1: vdi, 2: gs, 3: gp, 4: gspreview
    double d_verticalDeviationTransformValue = 0;

    double d_altitudeTrendValue = 250;


    // variables for cdi source and vertical deviation mode/value are selected on server side
    // internal items
    double d_scaleFactor = 0.96;

public:
    explicit AltimeterBackend(QObject *parent = nullptr);

    int center() const;
    double altitude() const;
    int radarAltitude() const;
    double radarAltitudeTransformValue() const;
    int referenceAltitude() const;

    double vspeedIndicatorTransformValue() const;
    QString vspeedTextValue() const;
    int referenceVspeed() const;

    double pressure() const;

    int verticalDeviationMode() const;
    double verticalDeviationTransformValue() const;

    double altitudeTrendValue() const;

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

    void verticalDeviationModeChanged();
    void verticalDeviationTransformValueChanged();

    void altitudeTrendValueChanged();

public slots:
    void updateAltitude(double newValue);
    void updateRadarAltitude(double newValue);
    void updateReferenceAltitude(int newValue);

    void updateVspeed(double newValue);
    void updateReferenceVspeed(int newValue);

    void updatePressure(double newValue);

    void updateVerticalDeviationMode(int newValue);
    void updateVerticalDeviationValue(double newValue);
};

#endif   // ALTIMETERBACKEND_H
