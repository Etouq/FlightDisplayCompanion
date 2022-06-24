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

#endif  // __TYPE_ENUMS_HPP__