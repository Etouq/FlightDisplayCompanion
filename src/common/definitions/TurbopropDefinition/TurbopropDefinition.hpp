#ifndef __TURBOPROP_DEFINITION_HPP__
#define __TURBOPROP_DEFINITION_HPP__

#include "../AircraftDefinition/AircraftDefinition.hpp"


namespace definitions
{

struct TurbopropDefinition : public AircraftDefinition
{
    GaugeDefinition n1Gauge;
    GaugeDefinition trqGauge;
    GaugeDefinition ittGauge;
    GaugeDefinition rpmGauge;

    bool trqAsPct = true;

    TemperatureGaugeType ittGaugeType = TemperatureGaugeType::ITT;

    bool rpmAsPct = false;
    bool usePropRpm = false;

    bool hasApu = false;


    QByteArray toBinary() const;

    static TurbopropDefinition fromBinary(QIODevice &data, FileVersion version)
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

    static TurbopropDefinition fromBinaryV1(QIODevice &data, FileVersion version);
    static TurbopropDefinition fromBinaryV3(QIODevice &data, FileVersion version);
};

}  // namespace definitions


#endif  // __TURBOPROP_DEFINITION_HPP__