#ifndef __AIRCRAFT_CONFIG_HPP__
#define __AIRCRAFT_CONFIG_HPP__

#include "typeEnums.hpp"

struct AircraftConfig
{
    AircraftType type = AircraftType::JET;

    uint8_t numEngines = 1;
    bool singleTank = false;

    double firstGaugeEpsilon = 10000;
    double secondGaugeEpsilon = 10000;
    double thirdGaugeEpsilon = 10000;
    double fourthGaugeEpsilon = 10000;

    double fuelQtyEpsilon = 10000;
    double fuelFlowEpsilon = 10000;
    double oilTempEpsilon = 10000;
    double secondaryTempEpsilon = 10000;
    double oilPressEpsilon = 10000;

    SwitchingGaugeType gauge1Type = SwitchingGaugeType::NONE;
    SwitchingGaugeType gauge2Type = SwitchingGaugeType::NONE;
    SwitchingGaugeType gauge3Type = SwitchingGaugeType::NONE;
    SwitchingGaugeType gauge4Type = SwitchingGaugeType::NONE;

    TemperatureGaugeType engineTempType = TemperatureGaugeType::ITT;

    double maxPower = 1;

    bool hasApu = false;

    bool hasFlaps = false;
    bool hasSpoilers = false;

    bool hasElevatorTrim = false;
    bool hasRudderTrim = false;
    bool hasAileronTrim = false;

    bool fuelQtyByWeight = false;
    bool fuelFlowByWeight = false;

    bool hasSecondaryTempGauge = false;
    TemperatureGaugeType secondaryTempType = TemperatureGaugeType::EGT;

};



#endif  // __AIRCRAFT_CONFIG_HPP__