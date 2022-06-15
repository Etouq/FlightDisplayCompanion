#include "JetDefinition.hpp"
#include "common/converters/basicConverters.hpp"


namespace definitions
{

QByteArray JetDefinition::toBinary() const
{
    QByteArray ret = Converters::convert(AircraftType::JET);
    ret += AircraftDefinition::toBinary();
    ret += n1Gauge.toBinary();
    ret += n2Gauge.toBinary();
    ret += ittGauge.toBinary();
    ret += Converters::convert(ittGaugeType);
    ret += Converters::convert(hasApu);
    return ret;
}

}  // namespace definitions
