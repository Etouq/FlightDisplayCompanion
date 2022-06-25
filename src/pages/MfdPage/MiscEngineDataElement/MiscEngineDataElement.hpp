#ifndef __MISC_ENGINE_DATA_ELEMENT__
#define __MISC_ENGINE_DATA_ELEMENT__

#include <QObject>
#include <QString>

namespace pages::mfd
{

class MiscEngineDataElement : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float fuelRange READ fuelRange NOTIFY fuelRangeChanged)
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
    Q_PROPERTY(int elevTrimValue READ elevTrimValue NOTIFY elevTrimValueChanged)
    Q_PROPERTY(double rudderTrimTransformValue READ rudderTrimTransformValue NOTIFY rudderTrimTransformValueChanged)
    Q_PROPERTY(int rudderTrimValue READ rudderTrimValue NOTIFY rudderTrimValueChanged)
    Q_PROPERTY(double aileronTrimTransformValue READ aileronTrimTransformValue NOTIFY aileronTrimTransformValueChanged)
    Q_PROPERTY(int aileronTrimValue READ aileronTrimValue NOTIFY aileronTrimValueChanged)

public:

    explicit MiscEngineDataElement(QObject *parent = nullptr)
      : QObject(parent)
    {}

    void setParameters(bool hasApu,
                       bool hasSecondaryTempGauge,
                       bool hasFlaps,
                       bool hasSpoilers,
                       bool hasElevatorTrim,
                       bool hasRudderTrim,
                       bool hasAileronTrim)
    {
        d_hasApu = hasApu;
        d_hasSecondaryTempGauge = hasSecondaryTempGauge;

        d_hasFlaps = hasFlaps;
        d_hasSpoilers = hasSpoilers;

        d_hasElevatorTrim = hasElevatorTrim;
        d_hasRudderTrim = hasRudderTrim;
        d_hasAileronTrim = hasAileronTrim;

        emit redrawNeeded();
        d_fuelTimeText = QLatin1String("--:--");
        emit fuelTimeTextChanged();

        d_fuelRange = -1;
        d_fuelRangeText = QLatin1String("__._NM");
        emit fuelRangeTextChanged();
        emit fuelRangeChanged();
    }

    // basic info
    Q_INVOKABLE bool hasApu() const
    {
        return d_hasApu;
    }

    Q_INVOKABLE bool hasSecondaryTempGauge() const
    {
        return d_hasSecondaryTempGauge;
    }

    Q_INVOKABLE bool hasSingleTank() const
    {
        return d_hasSingleTank;
    }

    Q_INVOKABLE bool hasSpoilers() const
    {
        return d_hasSpoilers;
    }

    Q_INVOKABLE bool hasFlaps() const
    {
        return d_hasFlaps;
    }

    Q_INVOKABLE bool hasElevatorTrim() const
    {
        return d_hasElevatorTrim;
    }

    Q_INVOKABLE bool hasRudderTrim() const
    {
        return d_hasRudderTrim;
    }

    Q_INVOKABLE bool hasAileronTrim() const
    {
        return d_hasAileronTrim;
    }

    // fuel text
    float fuelRange() const
    {
        return d_fuelRange;
    }

    const QString &fuelTimeText() const
    {
        return d_fuelTimeText;
    }

    const QString &fuelRangeText() const
    {
        return d_fuelRangeText;
    }

    const QString &apuRpmText() const
    {
        return d_apuRpmText;
    }

    // flaps\spoilers
    double spoilersAngle() const
    {
        return d_spoilersAngle;
    }

    const QString &spoilersValue() const
    {
        return d_spoilersValue;
    }

    bool showSpoilersText() const
    {
        return d_showSpoilersText;
    }

    double flapsAngle() const
    {
        return d_flapsAngle;
    }

    const QString &flapsValue() const
    {
        return d_flapsValue;
    }

    bool showFlapsText() const
    {
        return d_showFlapsText;
    }

    // trims
    double elevTrimTransformValue() const
    {
        return d_elevTrimTransformValue;
    }

    int elevTrimValue() const
    {
        return d_elevTrimValue;
    }

    double rudderTrimTransformValue() const
    {
        return d_rudderTrimTransformValue;
    }

    int rudderTrimValue() const
    {
        return d_rudderTrimValue;
    }

    double aileronTrimTransformValue() const
    {
        return d_aileronTrimTransformValue;
    }

    int aileronTrimValue() const
    {
        return d_aileronTrimValue;
    }

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
    void elevTrimValueChanged();
    void rudderTrimTransformValueChanged();
    void rudderTrimValueChanged();
    void aileronTrimTransformValueChanged();
    void aileronTrimValueChanged();

    void redrawNeeded();

public slots:
    void updateFuelText(float totalFuelflow, float totalFuelQty, float groundSpeed);

    void updateApuRpm(int newVal)
    {
        if (d_hasApu)
        {
            QString newApuRpm = QString::number(newVal) + "%";
            if (newApuRpm != d_apuRpmText)
            {
                d_apuRpmText = newApuRpm;
                emit apuRpmTextChanged();
            }
        }
    }

    void updateSpoilers(double newVal)
    {
        if (d_hasSpoilers)
        {
            d_spoilersAngle = (newVal) *d_spoilersMaxAngle;
            emit spoilersAngleChanged();
            int pctValue = lround(newVal * 100.0);
            bool newShowSpoilersText = pctValue > 0;
            if (d_showSpoilersText != newShowSpoilersText)
            {
                d_showSpoilersText = newShowSpoilersText;
                emit showSpoilersTextChanged();
            }
            if (d_showSpoilersText)
            {
                d_spoilersValue = QString::number(pctValue) + "%";
                emit spoilersValueChanged();
            }
        }
    }

    void updateFlaps(double newVal)
    {
        if (d_hasFlaps)
        {
            d_flapsAngle = newVal;
            emit flapsAngleChanged();
            int roundedAngle = lround(newVal);
            bool newShowFlapsText = roundedAngle != 0;
            if (d_showFlapsText != newShowFlapsText)
            {
                d_showFlapsText = newShowFlapsText;
                emit showFlapsTextChanged();
            }
            if (d_showFlapsText)
            {
                QString newFlapsValue = QString::number(roundedAngle) + "º";
                if (d_flapsValue != newFlapsValue)
                {
                    d_flapsValue = newFlapsValue;
                    emit flapsValueChanged();
                }
            }
        }
    }

    void updateElevTrim(double newPct, int newAngle)
    {
        if (d_hasElevatorTrim)
        {
            d_elevTrimTransformValue = newPct * 60.0;
            emit elevTrimTransformValueChanged();

            d_elevTrimPct = std::lround(newPct * 100.0);
            d_elevTrimDegrees = newAngle;

            if (d_trimUseDegrees)
            {
                if (d_elevTrimDegrees != d_elevTrimValue)
                {
                    d_elevTrimValue = d_elevTrimDegrees;
                    emit elevTrimValueChanged();
                }
            }
            else if (d_elevTrimPct != d_elevTrimValue)
            {
                d_elevTrimValue = d_elevTrimPct;
                emit elevTrimValueChanged();
            }
        }
    }

    void updateRudderTrim(double newPct, int newAngle)
    {
        if (d_hasRudderTrim)
        {
            d_rudderTrimTransformValue = newPct * 60.0;
            emit rudderTrimTransformValueChanged();

            d_rudderTrimPct = std::lround(newPct * 100.0);
            d_rudderTrimDegrees = newAngle;

            if (d_trimUseDegrees)
            {
                if (d_rudderTrimDegrees != d_rudderTrimValue)
                {
                    d_rudderTrimValue = d_rudderTrimDegrees;
                    emit rudderTrimValueChanged();
                }
            }
            else if (d_rudderTrimPct != d_rudderTrimValue)
            {
                d_rudderTrimValue = d_rudderTrimPct;
                emit rudderTrimValueChanged();
            }
        }
    }

    void updateAileronTrim(double newPct, int newAngle)
    {
        if (d_hasAileronTrim)
        {
            d_aileronTrimTransformValue = newPct * 60.0;
            emit aileronTrimTransformValueChanged();

            d_ailTrimPct = std::lround(newPct * 100.0);
            d_ailTrimDegrees = newAngle;

            if (d_trimUseDegrees)
            {
                if (d_ailTrimDegrees != d_aileronTrimValue)
                {
                    d_aileronTrimValue = d_ailTrimDegrees;
                    emit aileronTrimValueChanged();
                }
            }
            else if (d_ailTrimPct != d_aileronTrimValue)
            {
                d_aileronTrimValue = d_ailTrimPct;
                emit aileronTrimValueChanged();
            }
        }
    }

private:

    // fuel text
    float d_fuelRange = -1;
    QString d_fuelTimeText = "--:--";
    QString d_fuelRangeText = "__._NM";
    QString d_apuRpmText = "0%";
    bool d_hasApu = false;

    bool d_hasSecondaryTempGauge = false;
    bool d_hasSingleTank = false;

    // flaps\spoilers
    static constexpr double d_spoilersMaxAngle = -60;
    double d_spoilersAngle = 0;
    QString d_spoilersValue = "0%";
    bool d_showSpoilersText = false;
    bool d_hasSpoilers = false;
    double d_flapsAngle = 0;
    QString d_flapsValue = "0º";
    bool d_showFlapsText = false;
    bool d_hasFlaps = false;

    // trims
    bool d_hasElevatorTrim = false;
    double d_elevTrimTransformValue = 0;
    int d_elevTrimValue = 0;
    bool d_hasRudderTrim = false;
    double d_rudderTrimTransformValue = 0;
    int d_rudderTrimValue = 0;
    bool d_hasAileronTrim = false;
    double d_aileronTrimTransformValue = 0;
    int d_aileronTrimValue = 0;

    // private
    double d_smoothedSpeed = 0;
    double d_smoothedFF = 0;

    bool d_trimUseDegrees = true;

    int d_elevTrimDegrees = 0;
    int d_elevTrimPct = 0;
    int d_rudderTrimDegrees = 0;
    int d_rudderTrimPct = 0;
    int d_ailTrimDegrees = 0;
    int d_ailTrimPct = 0;
};

}  // namespace pages::mfd

#endif  // __MISC_ENGINE_DATA_ELEMENT__
