#include "TurbopropDefinition.hpp"
#include "common/converters/basicConverters.hpp"

namespace definitions
{

QByteArray TurbopropDefinition::toBinary() const
{
    QByteArray ret = Converters::convert(AircraftType::TURBOPROP);
    ret += AircraftDefinition::toBinary();

    ret += n1Gauge.toBinary();
    ret += trqGauge.toBinary();
    ret += ittGauge.toBinary();
    ret += rpmGauge.toBinary();

    ret += Converters::convert(trqAsPct);

    ret += Converters::convert(ittGaugeType);

    ret += Converters::convert(rpmAsPct);
    ret += Converters::convert(usePropRpm);

    ret += Converters::convert(hasApu);

    return ret;
}

}  // namespace definitions
