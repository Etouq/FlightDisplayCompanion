#ifndef __GENERAL_SETINGS_HPP__
#define __GENERAL_SETINGS_HPP__

#include "common/QmlEnums.hpp"

#include <QObject>
#include <QSettings>


namespace pages::tsc
{


class GeneralSettings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool showRangeText READ showRangeText WRITE setShowRangeText NOTIFY showRangeTextChanged)
    Q_PROPERTY(bool showRangeRings READ showRangeRings WRITE setShowRangeRings NOTIFY showRangeRingsChanged)
    Q_PROPERTY(bool showFuelRangeRing READ showFuelRangeRing WRITE setShowFuelRangeRing NOTIFY showFuelRangeRingChanged)
    Q_PROPERTY(QmlBearingModeClass::Value bearing1Mode READ bearing1Mode NOTIFY bearing1ModeChanged)
    Q_PROPERTY(QmlBearingModeClass::Value bearing2Mode READ bearing2Mode NOTIFY bearing2ModeChanged)
    Q_PROPERTY(QmlBearingModeClass::Value dmeMode READ dmeMode NOTIFY dmeModeChanged)


public:

    explicit GeneralSettings(QObject *parent = nullptr)
      : QObject(parent)
    {}

    bool showRangeText() const
    {
        return d_showRangeText;
    }

    bool showRangeRings() const
    {
        return d_showRangeRings;
    }

    bool showFuelRangeRing() const
    {
        return d_showFuelRangeRing;
    }

    void setShowRangeText(bool newValue)
    {
        d_showRangeText = newValue;
        emit showRangeTextChanged();
    }

    void setShowRangeRings(bool newValue)
    {
        d_showRangeRings = newValue;
        emit showRangeRingsChanged();
    }

    void setShowFuelRangeRing(bool newValue)
    {
        d_showFuelRangeRing = newValue;
        emit showFuelRangeRingChanged();
    }

    BearingMode bearing1Mode() const
    {
        return d_bearing1Mode;
    }

    BearingMode bearing2Mode() const
    {
        return d_bearing2Mode;
    }

    BearingMode dmeMode() const
    {
        return d_dmeMode;
    }

    Q_INVOKABLE void nextBearing1Mode()
    {
        d_bearing1Mode = getNextBearingMode(d_bearing1Mode);
        emit bearing1ModeChanged();
    }

    Q_INVOKABLE void nextBearing2Mode()
    {
        d_bearing2Mode = getNextBearingMode(d_bearing2Mode);
        emit bearing2ModeChanged();
    }

    Q_INVOKABLE void nextDmeMode()
    {
        switch (d_dmeMode)
        {
            case BearingMode::OFF:
                d_dmeMode = BearingMode::NAV1;
                break;
            case BearingMode::NAV1:
                d_dmeMode = BearingMode::NAV2;
                break;
            case BearingMode::NAV2:
            default:
                d_dmeMode = BearingMode::OFF;
                break;
        }
        emit dmeModeChanged();
    }

signals:
    void showRangeTextChanged();
    void showRangeRingsChanged();
    void showFuelRangeRingChanged();
    void bearing1ModeChanged();
    void bearing2ModeChanged();
    void dmeModeChanged();


private:

    static BearingMode getNextBearingMode(BearingMode mode)
    {
        switch (mode)
        {
            case BearingMode::OFF:
                return BearingMode::NAV1;
            case BearingMode::NAV1:
                return BearingMode::NAV2;
            case BearingMode::NAV2:
                return BearingMode::GPS;
            case BearingMode::GPS:
                return BearingMode::ADF;
            case BearingMode::ADF:
                return BearingMode::OFF;
        }
    }

    bool d_showRangeText = true;
    bool d_showRangeRings = true;
    bool d_showFuelRangeRing = true;

    BearingMode d_bearing1Mode = BearingMode::OFF;
    BearingMode d_bearing2Mode = BearingMode::OFF;
    BearingMode d_dmeMode = BearingMode::OFF;
};

}  // namespace pages::tsc


#endif  // __GENERAL_SETINGS_HPP__
