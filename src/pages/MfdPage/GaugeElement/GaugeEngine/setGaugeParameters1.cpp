#include "GaugeEngine.hpp"
#include "common/UnitConverter/UnitConverter.hpp"

namespace pages::mfd
{

void GaugeEngine::setGaugeParameters(const definitions::GaugeDefinition &gaugeDef, double startAngle, double endAngle)
{
    d_isCircular = true;

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

    //UnitConverter::setConversionFunction(convertValue, d_def.unit);

    if (d_def.forceTextColor)
    {
        d_color = d_def.textForcedColor;

        emit colorChanged();
    }

    if (d_def.noText)
    {
        d_value = "";
    }

    // const double sweepAngle = d_startAngle - d_endAngle - 360 * std::floor((d_startAngle - d_endAngle) / 360.0);
    // d_cursorPosOffset = (sweepAngle * def.minValue) / (def.maxValue - def.minValue) + d_startAngle;
    // d_cursorPosFactor = sweepAngle / (def.maxValue - def.minValue);

    const double sweepAngle = endAngle - startAngle - 360 * std::floor((endAngle - startAngle) / 360.0);
    d_cursorPosOffset = startAngle - (sweepAngle * gaugeDef.minValue) / (gaugeDef.maxValue - gaugeDef.minValue);
    d_cursorPosFactor = sweepAngle / (gaugeDef.maxValue - gaugeDef.minValue);

    // double sweepAngle = fmod(360.0 + fmod(startAngle - endAngle, 360.0), 360.0);
    // d_cursorPosOffset = (sweepAngle * d_def.minValue) / (d_def.maxValue - d_def.minValue) + startAngle;
    // d_cursorPosFactor = sweepAngle / (d_def.maxValue - d_def.minValue);

    update(d_def.minValue);

    d_redBlink = false;

    emit redBlinkChanged();
}

}  // namespace pages::mfd
