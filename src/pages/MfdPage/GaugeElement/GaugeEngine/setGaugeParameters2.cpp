#include "GaugeEngine.hpp"
#include "common/UnitConverter/UnitConverter.hpp"

namespace pages::mfd
{

void GaugeEngine::setGaugeParameters(const definitions::GaugeDefinition &gaugeDef, double length)
{
    d_isCircular = false;

    d_def = gaugeDef;

    d_conversionFactor = UnitConverter::getMultiplier(d_def.unit);

    if (d_def.unit == Units::FAHRENHEIT)
        d_conversionOffset = 32;
    else if (d_def.unit == Units::KELVIN)
        d_conversionOffset = 273.15;
    else if (d_def.unit == Units::RANKINE)
        d_conversionOffset = 491.67;  // 273.15 * 1.8;
    else
        d_conversionOffset = 0;

    if (d_def.forceTextColor)
    {
        d_color = d_def.textForcedColor;

        emit colorChanged();
    }

    if (d_def.noText)
    {
        d_value = "";
    }

    d_cursorPosOffset = (d_def.minValue * length) / (d_def.maxValue - d_def.minValue);
    d_cursorPosFactor = length / (d_def.maxValue - d_def.minValue);

    update(d_def.minValue);

    d_redBlink = false;

    emit redBlinkChanged();
}

}  // namespace pages::mfd
