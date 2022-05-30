#include "gaugebase.hpp"

// basic gauge info
QString GaugeBase::getName() const
{
    return def.title;
}
QString GaugeBase::getUnit() const
{
    return def.unitString;
}
double GaugeBase::getStartAngle() const
{
    return d_startAngle;
}
double GaugeBase::getEndAngle() const
{
    return d_endAngle;
}
double GaugeBase::getLength() const
{
    return d_length;
}
double GaugeBase::getMinValue() const
{
    return def.minValue;
}
double GaugeBase::getMaxValue() const
{
    return def.maxValue;
}


// colorzones
int GaugeBase::numColorZones() const
{
    return def.colorZones.size();
}

double GaugeBase::colorZoneStartAt(int idx) const
{
    return def.colorZones.at(idx).start <= def.minValue   ? def.minValue
           : def.colorZones.at(idx).start >= def.maxValue ? def.maxValue
                                                          : def.colorZones.at(idx).start;
}

double GaugeBase::colorZoneEndAt(int idx) const
{
    return def.colorZones.at(idx).end <= def.minValue ? def.minValue : def.colorZones.at(idx).end >= def.maxValue ? def.maxValue : def.colorZones.at(idx).end;
}

QColor GaugeBase::colorZoneColorAt(int idx) const
{
    return def.colorZones.at(idx).color;
}


// grads
int GaugeBase::numGrads() const
{
    return def.grads.size();
}

double GaugeBase::gradValAt(int idx) const
{
    return def.grads.at(idx).gradPos;
}

bool GaugeBase::gradIsBigAt(int idx) const
{
    return def.grads.at(idx).isBig;
}

QColor GaugeBase::gradColorAt(int idx) const
{
    return def.grads.at(idx).gradColor;
}


// textgrads
int GaugeBase::numTextGrads() const
{
    return def.textGrads.size();
}

double GaugeBase::textGradValAt(int idx) const
{
    return def.textGrads.at(idx).textGradPos;
}

QString GaugeBase::gradTextAt(int idx) const
{
    return def.textGrads.at(idx).gradText;
}

bool GaugeBase::needsExtraWide() const
{
    for (int i = 0; i < def.textGrads.size(); i++)
        if (def.textGrads[i].gradText.size() > 4)
            return true;
    return false;
}

// engine 1 values
double GaugeBase::engine1Angle() const
{
    return d_engine1Angle;
}
double GaugeBase::engine1TransformValue() const
{
    return d_engine1TransformValue;
}
const QString &GaugeBase::engine1Value() const
{
    return d_engine1Value;
}
const QColor &GaugeBase::engine1Color() const
{
    return d_engine1Color;
}
bool GaugeBase::engine1RedBlink() const
{
    return d_engine1RedBlink;
}

// engine 2 values
double GaugeBase::engine2Angle() const
{
    return d_engine2Angle;
}
double GaugeBase::engine2TransformValue() const
{
    return d_engine2TransformValue;
}
const QString &GaugeBase::engine2Value() const
{
    return d_engine2Value;
}
const QColor &GaugeBase::engine2Color() const
{
    return d_engine2Color;
}
bool GaugeBase::engine2RedBlink() const
{
    return d_engine2RedBlink;
}

// engine 3 values
double GaugeBase::engine3Angle() const
{
    return d_engine3Angle;
}
double GaugeBase::engine3TransformValue() const
{
    return d_engine3TransformValue;
}
const QString &GaugeBase::engine3Value() const
{
    return d_engine3Value;
}
const QColor &GaugeBase::engine3Color() const
{
    return d_engine3Color;
}
bool GaugeBase::engine3RedBlink() const
{
    return d_engine3RedBlink;
}

// engine 4 values
double GaugeBase::engine4Angle() const
{
    return d_engine4Angle;
}
double GaugeBase::engine4TransformValue() const
{
    return d_engine4TransformValue;
}
const QString &GaugeBase::engine4Value() const
{
    return d_engine4Value;
}
const QColor &GaugeBase::engine4Color() const
{
    return d_engine4Color;
}
bool GaugeBase::engine4RedBlink() const
{
    return d_engine4RedBlink;
}
