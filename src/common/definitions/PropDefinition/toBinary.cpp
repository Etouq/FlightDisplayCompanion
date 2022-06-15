#include "PropDefinition.hpp"
#include "common/converters/basicConverters.hpp"

namespace definitions
{

QByteArray PropDefinition::toBinary() const
{
    QByteArray ret = Converters::convert(AircraftType::PROP);
    ret += AircraftDefinition::toBinary();

    ret += rpmGauge.toBinary();
    ret += powerGauge.toBinary();
    ret += manPressGauge.toBinary();
    ret += chtGauge.toBinary();

    ret += Converters::convert(hasRpm);
    ret += Converters::convert(usePropRpm);

    ret += Converters::convert(hasPower);
    ret += Converters::convert(powerAsPct);
    ret += Converters::convert(maxPower);

    ret += Converters::convert(hasManPress);

    ret += Converters::convert(hasCht);
    ret += Converters::convert(chtGaugeType);

    return ret;
}

}  // namespace definitions
