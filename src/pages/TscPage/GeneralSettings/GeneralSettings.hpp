#ifndef __GENERAL_SETINGS_HPP__
#define __GENERAL_SETINGS_HPP__

#include "common/QmlEnums.hpp"
#include "common/dataIdentifiers.hpp"

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
    Q_PROPERTY(QmlBottomTemperatureTypeClass::Value bottomTempType READ bottomTempType WRITE setBottomTempType NOTIFY bottomTempTypeChanged)
    Q_PROPERTY(QmlWindModeClass::Value windMode READ windMode WRITE setWindMode NOTIFY windModeChanged)
    Q_PROPERTY(QmlTimeTypeClass::Value topTimeType READ topTimeType WRITE setTopTimeType NOTIFY topTimeTypeChanged)
    Q_PROPERTY(QmlTimeTypeClass::Value botTimeType READ botTimeType WRITE setBotTimeType NOTIFY botTimeTypeChanged)




public:

    explicit GeneralSettings(QObject *parent = nullptr)
      : QObject(parent),
        d_showRangeText(d_settings.value("showRangeText", true).toBool()),
        d_showRangeRings(d_settings.value("showRangeRings", true).toBool()),
        d_showFuelRangeRing(d_settings.value("showFuelRangeRing", true).toBool()),
        d_bottomTempType(BottomTemperatureType(d_settings.value("bottomTempType", static_cast<int>(BottomTemperatureType::TAT)).toInt())),
        d_windMode(WindMode(d_settings.value("windMode", static_cast<int>(WindMode::OFF)).toInt())),
        d_topTimeType(TimeType(d_settings.value("topTimeType", static_cast<int>(TimeType::UTC)).toInt())),
        d_botTimeType(TimeType(d_settings.value("botTimeType", static_cast<int>(TimeType::LCL)).toInt())),
        d_bearing1Mode(BearingMode(d_settings.value("bearing1Mode", static_cast<int>(BearingMode::OFF)).toInt())),
        d_bearing2Mode(BearingMode(d_settings.value("bearing2Mode", static_cast<int>(BearingMode::OFF)).toInt())),
        d_dmeMode(BearingMode(d_settings.value("dmeMode", static_cast<int>(BearingMode::OFF)).toInt()))
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
        d_settings.setValue("showRangeText", newValue);
        d_showRangeText = newValue;
        emit showRangeTextChanged();
    }

    void setShowRangeRings(bool newValue)
    {
        d_settings.setValue("showRangeRings", newValue);
        d_showRangeRings = newValue;
        emit showRangeRingsChanged();
    }

    void setShowFuelRangeRing(bool newValue)
    {
        d_settings.setValue("showFuelRangeRing", newValue);
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

    BottomTemperatureType bottomTempType() const
    {
        return d_bottomTempType;
    }

    void setBottomTempType(BottomTemperatureType newType)
    {
        d_settings.setValue("bottomTempType", static_cast<int>(newType));
        d_bottomTempType = newType;
        emit bottomTempTypeChanged();
    }

    WindMode windMode() const
    {
        return d_windMode;
    }

    void setWindMode(WindMode newMode)
    {
        d_settings.setValue("windMode", static_cast<int>(newMode));
        d_windMode = newMode;
        emit windModeChanged();
    }

    Q_INVOKABLE void nextWindMode()
    {
        switch (d_windMode)
        {
            case WindMode::OFF:
                d_windMode = WindMode::MODE1;
                break;
            case WindMode::MODE1:
                d_windMode = WindMode::MODE2;
                break;
            case WindMode::MODE2:
                d_windMode = WindMode::MODE3;
                break;
            case WindMode::MODE3:
                d_windMode = WindMode::OFF;
                break;
        }
        emit windModeChanged();
    }

    TimeType topTimeType() const
    {
        return d_topTimeType;
    }
    TimeType botTimeType() const
    {
        return d_botTimeType;
    }

    void setTopTimeType(TimeType newType)
    {
        d_settings.setValue("topTimeType", static_cast<int>(newType));
        d_topTimeType = newType;
        emit topTimeTypeChanged();
    }
    void setBotTimeType(TimeType newType)
    {
        d_settings.setValue("botTimeType", static_cast<int>(newType));
        d_botTimeType = newType;
        emit botTimeTypeChanged();
    }

    Q_INVOKABLE void nextBearing1Mode()
    {
        d_bearing1Mode = getNextBearingMode(d_bearing1Mode);
        d_settings.setValue("bearing1Mode", static_cast<int>(d_bearing1Mode));
        emit bearing1ModeChanged();
    }

    Q_INVOKABLE void nextBearing2Mode()
    {
        d_bearing2Mode = getNextBearingMode(d_bearing2Mode);
        d_settings.setValue("bearing2Mode", static_cast<int>(d_bearing2Mode));
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
        d_settings.setValue("dmeMode", static_cast<int>(d_dmeMode));
        emit dmeModeChanged();
    }

    Q_INVOKABLE void nextCdiMode()
    {
        SimCommandId cmdId = SimCommandId::NEXT_CDI_MODE;
        QByteArray dataToSend(reinterpret_cast<const char *>(&cmdId), sizeof(cmdId));
        emit sendCommandsToSim(dataToSend);
    }

signals:
    void showRangeTextChanged();
    void showRangeRingsChanged();
    void showFuelRangeRingChanged();
    void bearing1ModeChanged();
    void bearing2ModeChanged();
    void dmeModeChanged();
    void bottomTempTypeChanged();
    void windModeChanged();
    void topTimeTypeChanged();
    void botTimeTypeChanged();

    void sendCommandsToSim(const QByteArray &data);

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

    QSettings d_settings;

    bool d_showRangeText = true;
    bool d_showRangeRings = true;
    bool d_showFuelRangeRing = true;

    BearingMode d_bearing1Mode = BearingMode::OFF;
    BearingMode d_bearing2Mode = BearingMode::OFF;
    BearingMode d_dmeMode = BearingMode::OFF;

    BottomTemperatureType d_bottomTempType = BottomTemperatureType::TAT;
    WindMode d_windMode = WindMode::OFF;

    TimeType d_topTimeType = TimeType::UTC;
    TimeType d_botTimeType = TimeType::LCL;
};

}  // namespace pages::tsc


#endif  // __GENERAL_SETINGS_HPP__
