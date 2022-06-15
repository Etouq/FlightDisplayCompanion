#include "GaugeEngine.hpp"
#include "unitConverter/unitconverter.hpp"

namespace pages::mfd
{

void GaugeEngine::setGaugeParameters(const definitions::GaugeDefinition &gaugeDef, double startAngle, double endAngle)
{
    d_isCircular = true;

    d_def = gaugeDef;

    UnitConverter::setConversionFunction(convertValue, d_def.unit);

    if (d_def.forceTextColor)
    {
        d_color = d_def.textForcedColor;

        emit colorChanged();
    }

    if (d_def.noText)
    {
        d_value = "";
    }

    double sweepAngle = fmod(360.0 + fmod(startAngle - endAngle, 360.0), 360.0);
    d_cursorPosOffset = (sweepAngle * d_def.minValue) / (d_def.maxValue - d_def.minValue) + startAngle;
    d_cursorPosFactor = sweepAngle / (d_def.maxValue - d_def.minValue);

    update(d_def.minValue);

    d_redBlink = false;

    emit redBlinkChanged();
}

}  // namespace pages::mfd
