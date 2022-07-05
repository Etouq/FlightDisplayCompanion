#include "gaugeDefinition.hpp"
#include "common/converters/listConverters.hpp"

namespace definitions
{

GaugeDefinition GaugeDefinition::fromBinary(QIODevice &data)
{
    GaugeDefinition ret;
    Converters::convertString(data, ret.title);
    Converters::convertString(data, ret.unitString);
    Converters::convert(data, ret.minValue);
    Converters::convert(data, ret.maxValue);
    Converters::convert(data, ret.colorZones);
    Converters::convert(data, ret.grads);
    Converters::convert(data, ret.textGrads);
    Converters::convert(data, ret.textIncrement);
    Converters::convert(data, ret.textNumDigits);
    Converters::convert(data, ret.forceTextColor);
    Converters::convert(data, ret.textForcedColor);
    Converters::convert(data, ret.hasMinRedBlink);
    Converters::convert(data, ret.minRedBlinkThreshold);
    Converters::convert(data, ret.hasMaxRedBlink);
    Converters::convert(data, ret.maxRedBlinkThreshold);
    Converters::convert(data, ret.noText);
    Converters::convert(data, ret.unit);
    return ret;
}

}  // namespace definitions
