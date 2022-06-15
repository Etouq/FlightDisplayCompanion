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
    Q_PROPERTY(double rudderTrimTransformValue READ rudderTrimTransformValue NOTIFY rudderTrimTransformValueChanged)
    Q_PROPERTY(double aileronTrimTransformValue READ aileronTrimTransformValue NOTIFY aileronTrimTransformValueChanged)

    // fuel text
    float d_fuelRange = -1;
    QString d_fuelTimeText = "--:--";
    QString d_fuelRangeText = "__._NM";
    QString d_apuRpmText = "0%";
    bool d_hasApu = false;

    bool d_hasEgt = false;

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
    bool d_hasRudderTrim = false;
    double d_rudderTrimTransformValue = 0;
    bool d_hasAileronTrim = false;
    double d_aileronTrimTransformValue = 0;

    // private
    double d_smoothedSpeed = 0;
    double d_smoothedFF = 0;

public:

    explicit MiscEngineDataElement(QObject *parent = nullptr)
      : QObject(parent)
    {}

    void setParameters(bool hasApu,
                       bool hasEgt,
                       bool hasFlaps,
                       bool hasSpoilers,
                       bool hasElevatorTrim,
                       bool hasRudderTrim,
                       bool hasAileronTrim)
    {
        d_hasApu = hasApu;
        d_hasEgt = hasEgt;

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

    Q_INVOKABLE bool hasEgt() const
    {
        return d_hasEgt;
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

    double rudderTrimTransformValue() const
    {
        return d_rudderTrimTransformValue;
    }

    double aileronTrimTransformValue() const
    {
        return d_aileronTrimTransformValue;
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
    void rudderTrimTransformValueChanged();
    void aileronTrimTransformValueChanged();

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

    void updateElevTrim(double newVal)
    {
        if (d_hasElevatorTrim)
        {
            d_elevTrimTransformValue = newVal * 60.0;
            emit elevTrimTransformValueChanged();
        }
    }

    void updateRudderTrim(double newVal)
    {
        if (d_hasRudderTrim)
        {
            d_rudderTrimTransformValue = newVal * 60.0;
            emit rudderTrimTransformValueChanged();
        }
    }

    void updateAileronTrim(double newVal)
    {
        if (d_hasAileronTrim)
        {
            d_aileronTrimTransformValue = newVal * 60.0;
            emit aileronTrimTransformValueChanged();
        }
    }
};

}  // namespace pages::mfd

#endif  // __MISC_ENGINE_DATA_ELEMENT__