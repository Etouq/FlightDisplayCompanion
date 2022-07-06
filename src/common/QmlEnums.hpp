#ifndef __QML_ENUMS_HPP__
#define __QML_ENUMS_HPP__

#include "typeEnums.hpp"
#include "pages/MfdPage/FlightPlan/FlightPlanWaypoint.hpp"

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

typedef QmlHsiNavSourceClass::Value QmlHsiNavSource;


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

typedef QmlVerticalDeviationModeClass::Value QmlVerticalDeviationMode;


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

typedef QmlTransponderStateClass::Value QmlTransponderState;


class QmlMapRotationModeClass
{
Q_GADGET

    public:

    enum class Value
    {
        NORTH_UP,
        DTK_UP,
        HDG_UP,
        TRACK_UP
    };
    Q_ENUM(Value)

private:
    explicit QmlMapRotationModeClass();
};

typedef QmlMapRotationModeClass::Value MapRotationMode;


class QmlWaypointTypeClass
{
Q_GADGET

    public:

    enum class Value
    {
        NONE = static_cast<int>(pages::mfd::WaypointType::NONE),
        AIRPORT = static_cast<int>(pages::mfd::WaypointType::AIRPORT),
        INTERSECTION = static_cast<int>(pages::mfd::WaypointType::INTERSECTION),
        VOR = static_cast<int>(pages::mfd::WaypointType::VOR),
        NDB = static_cast<int>(pages::mfd::WaypointType::NDB),
        USER = static_cast<int>(pages::mfd::WaypointType::USER),
        ATC = static_cast<int>(pages::mfd::WaypointType::ATC)
    };
    Q_ENUM(Value)

private:
    explicit QmlWaypointTypeClass();
};

typedef QmlWaypointTypeClass::Value QmlWaypointType;


class QmlWpAltitudeTypeClass
{
Q_GADGET

    public:

    enum class Value
    {
        NONE = static_cast<int>(pages::mfd::WpAltitudeType::NONE),
        AT = static_cast<int>(pages::mfd::WpAltitudeType::AT),
        AT_OR_BELOW = static_cast<int>(pages::mfd::WpAltitudeType::AT_OR_BELOW),
        AT_OR_ABOVE = static_cast<int>(pages::mfd::WpAltitudeType::AT_OR_ABOVE),
        BETWEEN = static_cast<int>(pages::mfd::WpAltitudeType::BETWEEN)
    };
    Q_ENUM(Value)

private:
    explicit QmlWpAltitudeTypeClass();
};

typedef QmlWpAltitudeTypeClass::Value QmlWpAltitudeType;


class QmlBearingModeClass
{
Q_GADGET

    public:

    enum Value
    {
        OFF,
        NAV1,
        NAV2,
        GPS,
        ADF
    };
    Q_ENUM(Value)

private:
    explicit QmlBearingModeClass();
};

typedef QmlBearingModeClass::Value BearingMode;


class QmlWindModeClass
{
Q_GADGET

    public:

    enum class Value
    {
        OFF,
        MODE1,
        MODE2,
        MODE3
    };
    Q_ENUM(Value)

private:
    explicit QmlWindModeClass();
};

typedef QmlWindModeClass::Value WindMode;


class QmlMinimumsSourceClass
{
Q_GADGET

    public:

    enum class Value
    {
        OFF,
        BARO,
        RADIO_ALT
    };
    Q_ENUM(Value)

private:
    explicit QmlMinimumsSourceClass();
};

typedef QmlMinimumsSourceClass::Value MinimumsSource;


class QmlBottomTemperatureTypeClass
{
Q_GADGET

    public:

    enum class Value
    {
        TAT,
        OAT,
        ISA
    };
    Q_ENUM(Value)

private:
    explicit QmlBottomTemperatureTypeClass();
};

typedef QmlBottomTemperatureTypeClass::Value BottomTemperatureType;


class QmlTimeTypeClass
{
Q_GADGET

    public:

    enum class Value
    {
        UTC,
        LCL,
        TMR
    };
    Q_ENUM(Value)

private:
    explicit QmlTimeTypeClass();
};

typedef QmlTimeTypeClass::Value TimeType;

namespace io::network
{

class ConnectionStateClass
{
    Q_GADGET

public:

    enum Value
    {
        DISCONNECTED,
        CONNECTED,
        CONNECTING,
        DISCONNECTING
    };
    Q_ENUM(Value)

private:

    explicit ConnectionStateClass()
    {}
};

typedef ConnectionStateClass::Value ConnectionState;

}

#endif  // __QML_ENUMS_HPP__
