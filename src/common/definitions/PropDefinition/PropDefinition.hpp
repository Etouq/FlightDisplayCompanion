#ifndef __PROP_DEFINITION_HPP__
#define __PROP_DEFINITION_HPP__

#include "common/definitions/baseTypes.hpp"
#include "common/typeEnums.hpp"
#include "../AircraftDefinition/AircraftDefinition.hpp"


namespace definitions
{

struct PropDefinition : public AircraftDefinition
{
    GaugeDefinition rpmGauge;
    GaugeDefinition powerGauge;
    GaugeDefinition manPressGauge;
    GaugeDefinition chtGauge;

    bool hasRpm = true;
    bool usePropRpm = false;

    bool hasPower = false;
    bool powerAsPct = true;
    double maxPower = 1;

    bool hasManPress = true;

    bool hasCht = false;
    TemperatureGaugeType chtGaugeType = TemperatureGaugeType::CHT;


    QByteArray toBinary() const;

    static PropDefinition fromBinary(QIODevice &data, FileVersion version)
    {
        switch (version)
        {
            case FileVersion::V1:
            case FileVersion::V2:
                return fromBinaryV1(data, version);
            case FileVersion::V3:
                return fromBinaryV3(data, version);
        }
    }

    AircraftConfig toConfig() const;

private:

    static PropDefinition fromBinaryV1(QIODevice &data, FileVersion version);
    static PropDefinition fromBinaryV3(QIODevice &data, FileVersion version);
};

}  // namespace definitions


#endif  // __PROP_DEFINITION_HPP__