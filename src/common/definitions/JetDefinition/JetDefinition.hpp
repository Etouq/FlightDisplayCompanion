#ifndef __JET_DEFINITION_HPP__
#define __JET_DEFINITION_HPP__

#include "../AircraftDefinition/AircraftDefinition.hpp"


namespace definitions
{

struct JetDefinition : public AircraftDefinition
{
    GaugeDefinition n1Gauge;
    GaugeDefinition n2Gauge;
    GaugeDefinition ittGauge;

    TemperatureGaugeType ittGaugeType = TemperatureGaugeType::ITT;

    bool hasApu = true;


    QByteArray toBinary() const;

    static JetDefinition fromBinary(QIODevice &data, FileVersion version)
    {
        switch (version)
        {
            case FileVersion::V1:
            case FileVersion::V2:
                return fromBinaryV1(data, version);
            case FileVersion::V3:
                //return fromBinaryV3(data, version);
                return JetDefinition();
        }
    }

    AircraftConfig toConfig() const;

private:

    static JetDefinition fromBinaryV1(QIODevice &data, FileVersion version);
    static JetDefinition fromBinaryV3(QIODevice &data, FileVersion version);
};

}  // namespace definitions


#endif  // __JET_DEFINITION_HPP__