#include "GaugeEngine.hpp"

namespace pages::mfd
{

void GaugeEngine::update(double newValue)
{
    newValue = newValue * d_conversionFactor + d_conversionOffset;

    if (!d_def.noText)
    {
        QString newText =
          QString::number(round(newValue / d_def.textIncrement) * d_def.textIncrement, 'f', d_def.textNumDigits);

        if (newText != d_value)
        {
            d_value = newText;
            emit valueChanged();
        }

        if (!d_def.forceTextColor)
        {
            bool colorFound = false;
            auto it = d_def.colorZones.crbegin();
            auto end = d_def.colorZones.crend();
            for (; it != end; ++it)
                if (newValue >= it->start && newValue <= it->end)
                {
                    if (it->color != d_color)
                    {
                        d_color = it->color;
                        emit colorChanged();
                    }
                    colorFound = true;
                    break;
                }

            if (!colorFound && d_color != "white")
            {
                d_color = "white";
                emit colorChanged();
            }
        }
    }


    bool newBlink = (d_def.hasMinRedBlink && d_def.minRedBlinkThreshold >= newValue)
      || (d_def.hasMaxRedBlink && d_def.maxRedBlinkThreshold <= newValue);
    if (newBlink != d_redBlink)
    {
        d_redBlink = newBlink;
        emit redBlinkChanged();
    }

    newValue = newValue <= d_def.minValue ? d_def.minValue : newValue > d_def.maxValue ? d_def.maxValue : newValue;

    if (d_isCircular)
    {
        d_angle = newValue * d_cursorPosFactor + d_cursorPosOffset;
        emit angleChanged();
    }
    else
    {
        d_transformValue = d_cursorPosOffset - newValue * d_cursorPosFactor;
        emit transformValueChanged();
    }
}

}  // namespace pages::mfd
