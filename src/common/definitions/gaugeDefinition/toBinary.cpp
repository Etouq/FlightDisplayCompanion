#include "gaugeDefinition.hpp"
#include "common/converters/listConverters.hpp"

#include <QByteArray>


namespace definitions
{

QByteArray GaugeDefinition::toBinary() const
{
    QByteArray ret = Converters::convert(title);
    ret += Converters::convert(unitString);
    ret += Converters::convert(minValue);
    ret += Converters::convert(maxValue);
    ret += Converters::convert(colorZones);
    ret += Converters::convert(grads);
    ret += Converters::convert(textGrads);
    ret += Converters::convert(textIncrement);
    ret += Converters::convert(textNumDigits);
    ret += Converters::convert(forceTextColor);
    ret += Converters::convert(textForcedColor);
    ret += Converters::convert(hasMinRedBlink);
    ret += Converters::convert(minRedBlinkThreshold);
    ret += Converters::convert(hasMaxRedBlink);
    ret += Converters::convert(maxRedBlinkThreshold);
    ret += Converters::convert(noText);
    ret += Converters::convert(unit);
    return ret;
}


}  // namespace definitions
