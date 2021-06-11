#include "gaugebase.h"

#include <cmath>

#include "unitConverter/unitconverter.h"
using namespace std;

GaugeBase::GaugeBase(QObject *parent) : QObject(parent)
{
    UnitConverter::setConversionFunction(convertValue, Units::NONE);
}



void GaugeBase::setGaugeParameters(const GaugeDefinition &gaugeDef, double startAngle, double endAngle)
{
    d_isCircular = true;

    def = gaugeDef;

    UnitConverter::setConversionFunction(convertValue, def.unit);

    if (def.forceTextColor)
    {
        d_engine1Color = def.textForcedColor;
        d_engine2Color = def.textForcedColor;
        d_engine3Color = def.textForcedColor;
        d_engine4Color = def.textForcedColor;

        emit engine1ColorChanged();
        emit engine2ColorChanged();
        emit engine3ColorChanged();
        emit engine4ColorChanged();
    }

    if (def.noText)
    {
        d_engine1Value = "";
        d_engine2Value = "";
        d_engine3Value = "";
        d_engine4Value = "";

        emit engine1ValueChanged();
        emit engine2ValueChanged();
        emit engine3ValueChanged();
        emit engine4ValueChanged();
    }

    d_startAngle = startAngle;
    d_endAngle = endAngle;

    double sweepAngle = fmod(360.0 + fmod(d_startAngle - d_endAngle, 360.0), 360.0);
    d_cursorPosOffset = (sweepAngle * def.minValue) / (def.maxValue - def.minValue) + d_startAngle;
    d_cursorPosFactor = sweepAngle / (def.maxValue - def.minValue);

    updateEngine1(def.minValue);
    updateEngine2(def.minValue);
    updateEngine3(def.minValue);
    updateEngine4(def.minValue);

    d_engine1RedBlink = false;
    d_engine2RedBlink = false;
    d_engine3RedBlink = false;
    d_engine4RedBlink = false;

    emit engine1RedBlinkChanged();
    emit engine2RedBlinkChanged();
    emit engine3RedBlinkChanged();
    emit engine4RedBlinkChanged();
}


void GaugeBase::setGaugeParameters(const GaugeDefinition &gaugeDef, double length)
{
    d_isCircular = false;

    def = gaugeDef;

    UnitConverter::setConversionFunction(convertValue, def.unit);

    if (def.forceTextColor)
    {
        d_engine1Color = def.textForcedColor;
        d_engine2Color = def.textForcedColor;
        d_engine3Color = def.textForcedColor;
        d_engine4Color = def.textForcedColor;

        emit engine1ColorChanged();
        emit engine2ColorChanged();
        emit engine3ColorChanged();
        emit engine4ColorChanged();
    }

    if (def.noText)
    {
        d_engine1Value = "";
        d_engine2Value = "";
        d_engine3Value = "";
        d_engine4Value = "";

        emit engine1ValueChanged();
        emit engine2ValueChanged();
        emit engine3ValueChanged();
        emit engine4ValueChanged();
    }

    d_length = length;

    d_cursorPosOffset = (def.minValue * d_length) / (def.maxValue - def.minValue);
    d_cursorPosFactor = d_length / (def.maxValue - def.minValue);

    updateEngine1(def.minValue);
    updateEngine2(def.minValue);
    updateEngine3(def.minValue);
    updateEngine4(def.minValue);

    d_engine1RedBlink = false;
    d_engine2RedBlink = false;
    d_engine3RedBlink = false;
    d_engine4RedBlink = false;

    emit engine1RedBlinkChanged();
    emit engine2RedBlinkChanged();
    emit engine3RedBlinkChanged();
    emit engine4RedBlinkChanged();
}


void GaugeBase::updateEngine1(double newVal)
{
    convertValue(&newVal);

    if (!def.noText)
    {
        QString newValue = QString::number(round(newVal / def.textIncrement) * def.textIncrement, 'f', def.textNumDigits);

        if (newValue != d_engine1Value)
        {
            d_engine1Value = newValue;
            emit engine1ValueChanged();
        }

        if (!def.forceTextColor)
        {
            bool colorFound = false;
            for (auto it = def.colorZones.rbegin(); it != def.colorZones.rend(); ++it)
                if (newVal >= it->start && newVal <= it->end)
                {
                    if (it->color != d_engine1Color)
                    {
                        d_engine1Color = it->color;
                        emit engine1ColorChanged();
                    }
                    colorFound = true;
                    break;
                }

            if (!colorFound)
            {
                if (d_engine1Color != "white")
                {
                    d_engine1Color = "white";
                    emit engine1ColorChanged();
                }
            }
        }
    }


    bool newBlink = (def.hasMinRedBlink && def.minRedBlinkThreshold >= newVal) || (def.hasMaxRedBlink && def.maxRedBlinkThreshold <= newVal);
    if (newBlink != d_engine1RedBlink)
    {
        d_engine1RedBlink = newBlink;
        emit engine1RedBlinkChanged();
    }

    newVal = newVal <= def.minValue ? def.minValue : newVal > def.maxValue ? def.maxValue : newVal;

    if (d_isCircular)
    {
        d_engine1Angle = newVal * d_cursorPosFactor - d_cursorPosOffset;
        emit engine1AngleChanged();
    }
    else
    {
        d_engine1TransformValue = d_cursorPosOffset - newVal * d_cursorPosFactor;
        emit engine1TransformValueChanged();
    }
}

void GaugeBase::updateEngine2(double newVal)
{
    convertValue(&newVal);

    if (!def.noText)
    {
        QString newValue = QString::number(round(newVal / def.textIncrement) * def.textIncrement, 'f', def.textNumDigits);

        if (newValue != d_engine2Value)
        {
            d_engine2Value = newValue;
            emit engine2ValueChanged();
        }

        if (!def.forceTextColor)
        {
            bool colorFound = false;
            for (auto it = def.colorZones.rbegin(); it != def.colorZones.rend(); ++it)
                if (newVal >= it->start && newVal <= it->end)
                {
                    if (it->color != d_engine2Color)
                    {
                        d_engine2Color = it->color;
                        emit engine2ColorChanged();
                    }
                    colorFound = true;
                    break;
                }

            if (!colorFound)
            {
                if (d_engine2Color != "white")
                {
                    d_engine2Color = "white";
                    emit engine2ColorChanged();
                }
            }
        }
    }


    bool newBlink = (def.hasMinRedBlink && def.minRedBlinkThreshold >= newVal) || (def.hasMaxRedBlink && def.maxRedBlinkThreshold <= newVal);
    if (newBlink != d_engine2RedBlink)
    {
        d_engine2RedBlink = newBlink;
        emit engine2RedBlinkChanged();
    }

    newVal = newVal <= def.minValue ? def.minValue : newVal > def.maxValue ? def.maxValue : newVal;

    if (d_isCircular)
    {
        d_engine2Angle = newVal * d_cursorPosFactor - d_cursorPosOffset;
        emit engine2AngleChanged();
    }
    else
    {
        d_engine2TransformValue = d_cursorPosOffset - newVal * d_cursorPosFactor;
        emit engine2TransformValueChanged();
    }
}

void GaugeBase::updateEngine3(double newVal)
{
    convertValue(&newVal);

    if (!def.noText)
    {
        QString newValue = QString::number(round(newVal / def.textIncrement) * def.textIncrement, 'f', def.textNumDigits);

        if (newValue != d_engine3Value)
        {
            d_engine3Value = newValue;
            emit engine3ValueChanged();
        }

        if (!def.forceTextColor)
        {
            bool colorFound = false;
            for (auto it = def.colorZones.rbegin(); it != def.colorZones.rend(); ++it)
                if (newVal >= it->start && newVal <= it->end)
                {
                    if (it->color != d_engine3Color)
                    {
                        d_engine3Color = it->color;
                        emit engine3ColorChanged();
                    }
                    colorFound = true;
                    break;
                }

            if (!colorFound)
            {
                if (d_engine3Color != "white")
                {
                    d_engine3Color = "white";
                    emit engine3ColorChanged();
                }
            }
        }
    }


    bool newBlink = (def.hasMinRedBlink && def.minRedBlinkThreshold >= newVal) || (def.hasMaxRedBlink && def.maxRedBlinkThreshold <= newVal);
    if (newBlink != d_engine3RedBlink)
    {
        d_engine3RedBlink = newBlink;
        emit engine3RedBlinkChanged();
    }

    newVal = newVal <= def.minValue ? def.minValue : newVal > def.maxValue ? def.maxValue : newVal;

    if (d_isCircular)
    {
        d_engine3Angle = newVal * d_cursorPosFactor - d_cursorPosOffset;
        emit engine3AngleChanged();
    }
    else
    {
        d_engine3TransformValue = d_cursorPosOffset - newVal * d_cursorPosFactor;
        emit engine3TransformValueChanged();
    }
}

void GaugeBase::updateEngine4(double newVal)
{
    convertValue(&newVal);

    if (!def.noText)
    {
        QString newValue = QString::number(round(newVal / def.textIncrement) * def.textIncrement, 'f', def.textNumDigits);

        if (newValue != d_engine4Value)
        {
            d_engine4Value = newValue;
            emit engine4ValueChanged();
        }

        if (!def.forceTextColor)
        {
            bool colorFound = false;
            for (auto it = def.colorZones.rbegin(); it != def.colorZones.rend(); ++it)
                if (newVal >= it->start && newVal <= it->end)
                {
                    if (it->color != d_engine4Color)
                    {
                        d_engine4Color = it->color;
                        emit engine4ColorChanged();
                    }
                    colorFound = true;
                    break;
                }

            if (!colorFound)
            {
                if (d_engine4Color != "white")
                {
                    d_engine4Color = "white";
                    emit engine4ColorChanged();
                }
            }
        }
    }


    bool newBlink = (def.hasMinRedBlink && def.minRedBlinkThreshold >= newVal) || (def.hasMaxRedBlink && def.maxRedBlinkThreshold <= newVal);
    if (newBlink != d_engine4RedBlink)
    {
        d_engine4RedBlink = newBlink;
        emit engine4RedBlinkChanged();
    }

    newVal = newVal <= def.minValue ? def.minValue : newVal > def.maxValue ? def.maxValue : newVal;

    if (d_isCircular)
    {
        d_engine4Angle = newVal * d_cursorPosFactor - d_cursorPosOffset;
        emit engine4AngleChanged();
    }
    else
    {
        d_engine4TransformValue = d_cursorPosOffset - newVal * d_cursorPosFactor;
        emit engine4TransformValueChanged();
    }
}
