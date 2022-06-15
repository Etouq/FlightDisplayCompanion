#ifndef __AIRCRAFT_CONFIG_HPP__
#define __AIRCRAFT_CONFIG_HPP__

#include "typeEnums.hpp"

struct AircraftConfig
{
    uint8_t numEngines = 1;
    AircraftType type = AircraftType::JET;

    // jet aircraft
    double n1Epsilon = 10000; // shared with turboprop
    double n2Epsilon = 10000;
    double ittEpsilon = 10000; // shared with turboprop

    // prop aircraft
    double rpmEpsilon = 10000; // shared with turboprop
    double powerEpsilon = 10000;
    double manPressEpsilon = 10000;
    double chtEpsilon = 10000;

    // turboprop aircraft
    double trqEpsilon = 10000;

    // general
    double fuelFlowEpsilon = 10000;
    double oilTempEpsilon = 10000;
    double oilPressEpsilon = 10000;
    double egtEpsilon = 10000;

    double fuelQtyEpsilon = 10000;

    // jet aircraft
    TemperatureGaugeType ittGaugeType = TemperatureGaugeType::ITT; // shared with turboprop

    // prop aircraft
    bool hasRpm = true;
    bool usePropRpm = false; // shared with turboprop

    bool hasPower = false;
    bool powerAsPct = true;
    double maxPower = 1;

    bool hasManPress = true;

    bool hasCht = false;
    TemperatureGaugeType chtGaugeType = TemperatureGaugeType::CHT;

    // turboprop aircraft
    bool trqAsPct = true;
    bool rpmAsPct = false;

    bool hasApu = false; // shared with jet

    // general
    bool fuelFlowByWeight = false;

    bool singleTank = false;
    bool fuelQtyByWeight = false;

    bool hasEgt = false;
    TemperatureGaugeType egtGaugeType = TemperatureGaugeType::EGT;

    bool hasFlaps = false;
    bool hasSpoilers = false;

    bool hasElevTrim = false;
    bool hasRudderTrim = false;
    bool hasAileronTrim = false;


};



#endif  // __AIRCRAFT_CONFIG_HPP__