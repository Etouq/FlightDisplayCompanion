#ifndef MISCEDBASE_H
#define MISCEDBASE_H

#include <QObject>
#include <QString>

// interface for qml for information that differs from the standard gauge
class MiscEDBase : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double fuelRange READ fuelRange NOTIFY fuelRangeChanged)
    Q_PROPERTY(QString fuelTimeText READ fuelTimeText NOTIFY fuelTimeTextChanged)
    Q_PROPERTY(QString fuelRangeText READ fuelRangeText NOTIFY fuelRangeTextChanged)
    Q_PROPERTY(QString apuRpmText READ apuRpmText NOTIFY apuRpmTextChanged)

    Q_PROPERTY(double spoilersAngle READ spoilersAngle NOTIFY spoilersAngleChanged)
    Q_PROPERTY(QString spoilersValue READ spoilersValue NOTIFY spoilersValueChanged)
    Q_PROPERTY(bool showSpoilersText READ showSpoilersText NOTIFY showSpoilersTextChanged)

    Q_PROPERTY(double flapsAngle READ flapsAngle NOTIFY flapsAngleChanged)
    Q_PROPERTY(QString flapsValue READ flapsValue NOTIFY flapsValueChanged)
    Q_PROPERTY(bool showFlapsText READ showFlapsText NOTIFY showFlapsTextChanged)

    Q_PROPERTY(double elevTrimTransformValue READ elevTrimTransformValue NOTIFY elevTrimTransformValueChanged)
    Q_PROPERTY(double rudderTrimTransformValue READ rudderTrimTransformValue NOTIFY rudderTrimTransformValueChanged)
    Q_PROPERTY(double aileronTrimTransformValue READ aileronTrimTransformValue NOTIFY aileronTrimTransformValueChanged)

    //fuel text
    double d_fuelRange = -1;
    QString d_fuelTimeText = "--:--";
    QString d_fuelRangeText = "__._NM";
    QString d_apuRpmText = "0%";
    bool d_hasApu = false;

    bool d_hasEgt = false;

    //flaps\spoilers
    double d_spoilersMaxAngle = -60;
    double d_spoilersAngle = 0;
    QString d_spoilersValue = "0%";
    bool d_showSpoilersText = false;
    bool d_hasSpoilers = false;
    double d_flapsAngle = 0;
    QString d_flapsValue = "0º";
    bool d_showFlapsText = false;
    bool d_hasFlaps = false;

    //trims
    bool d_hasElevatorTrim = false;
    double d_elevTrimTransformValue = 0;
    bool d_hasAileronTrim = false;
    double d_aileronTrimTransformValue = 0;
    bool d_hasRudderTrim = false;
    double d_rudderTrimTransformValue = 0;

    //private
    double d_smoothedSpeed = 0;
    double d_smoothedFF = 0;


public:
    explicit MiscEDBase(QObject *parent = nullptr);
    void setParameters(bool hasApu, bool hasEgt, bool hasFlaps, bool hasSpoilers, bool hasElevatorTrim, bool hasAileronTrim, bool hasRudderTrim);


    //basic info
    Q_INVOKABLE bool getHasApu() const;
    Q_INVOKABLE bool getHasEgt() const;
    Q_INVOKABLE bool getHasSpoilers() const;
    Q_INVOKABLE bool getHasFlaps() const;
    Q_INVOKABLE bool getHasElevatorTrim() const;
    Q_INVOKABLE bool getHasAileronTrim() const;
    Q_INVOKABLE bool getHasRudderTrim() const;

    double fuelRange() const;
    const QString& fuelRangeText() const;
    const QString& fuelTimeText() const;
    const QString& apuRpmText() const;

    double spoilersAngle() const;
    const QString& spoilersValue() const;
    bool showSpoilersText() const;
    double flapsAngle() const;
    const QString& flapsValue() const;
    bool showFlapsText() const;

    double elevTrimTransformValue() const;
    double aileronTrimTransformValue() const;
    double rudderTrimTransformValue() const;



    double getD_fuelRange() const;
    void setD_fuelRange(double newD_fuelRange);

signals:
    void fuelRangeChanged();
    void fuelRangeTextChanged();
    void fuelTimeTextChanged();
    void apuRpmTextChanged();

    void spoilersAngleChanged();
    void spoilersValueChanged();
    void showSpoilersTextChanged();

    void flapsAngleChanged();
    void flapsValueChanged();
    void showFlapsTextChanged();

    void elevTrimTransformValueChanged();
    void aileronTrimTransformValueChanged();
    void rudderTrimTransformValueChanged();

    void currCoordinatesChanged();

    void redrawNeeded();

public slots:
    void updateFuelText(double totalFuelflow, double totalFuelQty, double groundSpeed);
    void updateApuRpm(int newVal);

    void updateSpoilers(double newVal);
    void updateFlaps(double newVal);

    void updateElevTrim(double newVal);
    void updateAileronTrim(double newVal);
    void updateRudderTrim(double newVal);
};

#endif // MISCEDBASE_H
