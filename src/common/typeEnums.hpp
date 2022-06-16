#ifndef __TYPE_ENUMS_HPP__
#define __TYPE_ENUMS_HPP__

#include <cstdint>
#include <QObject>

enum class HsiNavSource : uint8_t
{
    NONE = 0,
    GPS,
    VOR1,
    LOC1,
    TCN1,
    VOR2,
    LOC2,
    TCN2
};

enum class VerticalDeviationMode : uint8_t
{
    NONE = 0,
    VDI,
    GS,
    GP,
    GSPREVIEW
};

enum class TransponderState : uint8_t
{
    OFF = 0,
    STANDBY = 1,
    TEST = 2,
    ON = 3,
    ALT = 4,
    GROUND = 5
};

enum class AircraftType : uint8_t
{
    JET = 0,
    PROP,
    TURBOPROP,
    INVALID = 255
};

enum class TemperatureGaugeType : uint8_t
{
    EGT = 0,
    ITT,
    CHT
};

class QmlHsiNavSourceClass
{
Q_GADGET

    public:

    enum class Value
    {
        NONE = static_cast<int>(HsiNavSource::NONE),
        GPS = static_cast<int>(HsiNavSource::GPS),
        VOR1 = static_cast<int>(HsiNavSource::VOR1),
        LOC1 = static_cast<int>(HsiNavSource::LOC1),
        TCN1 = static_cast<int>(HsiNavSource::TCN1),
        VOR2 = static_cast<int>(HsiNavSource::VOR2),
        LOC2 = static_cast<int>(HsiNavSource::LOC2),
        TCN2 = static_cast<int>(HsiNavSource::TCN2)
    };
    Q_ENUM(Value)

private:
    explicit QmlHsiNavSourceClass();
};

class QmlVerticalDeviationModeClass
{
Q_GADGET

    public:

    enum class Value
    {
        NONE = static_cast<int>(VerticalDeviationMode::NONE),
        VDI = static_cast<int>(VerticalDeviationMode::VDI),
        GS = static_cast<int>(VerticalDeviationMode::GS),
        GP = static_cast<int>(VerticalDeviationMode::GP),
        GSPREVIEW = static_cast<int>(VerticalDeviationMode::GSPREVIEW)
    };
    Q_ENUM(Value)

private:
    explicit QmlVerticalDeviationModeClass();
};

class QmlTransponderStateClass
{
Q_GADGET

    public:

    enum class Value
    {
        OFF = static_cast<int>(TransponderState::OFF),
        STANDBY = static_cast<int>(TransponderState::STANDBY),
        TEST = static_cast<int>(TransponderState::TEST),
        ON = static_cast<int>(TransponderState::ON),
        ALT = static_cast<int>(TransponderState::ALT),
        GROUND = static_cast<int>(TransponderState::GROUND)
    };
    Q_ENUM(Value)

private:
    explicit QmlTransponderStateClass();
};

typedef QmlHsiNavSourceClass::Value QmlHsiNavSource;
typedef QmlVerticalDeviationModeClass::Value QmlVerticalDeviationMode;
typedef QmlTransponderStateClass::Value QmlTransponderState;

#endif  // __TYPE_ENUMS_HPP__