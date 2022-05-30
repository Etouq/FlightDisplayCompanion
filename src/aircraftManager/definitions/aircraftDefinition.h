#ifndef AIRCRAFTDEFINITION_H
#define AIRCRAFTDEFINITION_H

#include <QVariant>

#include "gaugeDefinition.h"

// definition containing all parameters used to display engine data of an aircraft
struct AircraftDefinition
{
    enum class AircraftType : int8_t
    {
        INVALID = -1,
        JET = 0,
        PROP = 1,
        TURBOPROP = 2
    };

    AircraftType type = AircraftType::INVALID;

    QVariant currentType;

    QString name = "";   // used as identifier so needs to be unique

    GaugeDefinition fuelQtyGauge;
    GaugeDefinition fuelFlowGauge;
    GaugeDefinition oilTempGauge;
    GaugeDefinition oilPressGauge;

    bool hasFlaps = false;
    bool hasSpoilers = false;

    bool hasElevatorTrim = false;
    bool hasRudderTrim = false;
    bool hasAileronTrim = false;

    bool fuelQtyByVolume = false;
    bool fuelFlowByVolume = false;

    int8_t numEngines = 1;
    int8_t numTanks = 1;

    float lowLimit = 0;
    float flapsBegin = 0;
    float flapsEnd = 0;
    float greenBegin = 0;
    float greenEnd = 0;
    float yellowBegin = 0;
    float yellowEnd = 0;
    float redBegin = 0;
    float redEnd = 0;
    float highLimit = 0;
    bool noColors = false;
    bool dynamicBarberpole = false;

    uint16_t defaultVr = 85;
    uint16_t defaultVx = 100;
    uint16_t defaultVy = 124;
    uint16_t defaultVapp = 85;

    QByteArray toBinary() const;

    QByteArray toNetworkData() const;

    static AircraftDefinition fromBinary(QIODevice &data, FileVersion version);

    bool operator==(const AircraftDefinition &rhs) const
    {
        return name == rhs.name;
    }
    bool operator!=(const AircraftDefinition &rhs) const
    {
        return name != rhs.name;
    }
    bool operator<(const AircraftDefinition &rhs) const
    {
        return name < rhs.name;
    }
    bool operator<=(const AircraftDefinition &rhs) const
    {
        return name <= rhs.name;
    }
    bool operator>(const AircraftDefinition &rhs) const
    {
        return name > rhs.name;
    }
    bool operator>=(const AircraftDefinition &rhs) const
    {
        return name >= rhs.name;
    }

private:
    static AircraftDefinition fromBinaryV1(QIODevice &data, FileVersion version);
    static AircraftDefinition fromBinaryV2(QIODevice &data, FileVersion version);
};

#endif   // AIRCRAFTDEFINITION_H
