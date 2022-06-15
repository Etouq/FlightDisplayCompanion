#include "gaugeDefinition.hpp"

namespace definitions
{

GaugeDefinition::GaugeDefinition(const RawGaugeDefinition &rhs)
{
    title = rhs.title;
    unitString = rhs.unitString;
    minValue = rhs.minValue;
    maxValue = rhs.maxValue;
    colorZones = rhs.colorZones;
    grads = rhs.grads;
    textGrads = rhs.textGrads;
    textIncrement = rhs.textIncrement;
    textNumDigits = rhs.textNumDigits;
    forceTextColor = rhs.forceTextColor;
    textForcedColor = rhs.textForcedColor;
    hasMinRedBlink = rhs.hasMinRedBlink;
    minRedBlinkThreshold = rhs.minRedBlinkThreshold;
    hasMaxRedBlink = rhs.hasMaxRedBlink;
    maxRedBlinkThreshold = rhs.maxRedBlinkThreshold;
    noText = rhs.noText;
    unit = rhs.unit;
}

}  // namespace definitions
