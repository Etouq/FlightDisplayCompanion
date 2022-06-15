#ifndef __TYPE_ENUMS_HPP__
#define __TYPE_ENUMS_HPP__

#include <cstdint>

enum class HsiNavSource : uint8_t
{
    NONE,
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
    NONE,
    VDI,
    GS,
    GP,
    GSPREVIEW
};

enum TransponderState : uint8_t
{
    OFF = 0,
    STANDBY = 1,
    TEST = 2,
    ON = 3,
    ALT = 4,
    GROUND = 5
};

enum AircraftType : uint8_t
{
    JET,
    PROP,
    TURBOPROP,
    INVALID = 255
};

enum TemperatureGaugeType : uint8_t
{
    EGT,
    ITT,
    CHT
};

#endif  // __TYPE_ENUMS_HPP__