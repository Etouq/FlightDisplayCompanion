#include "gaugeDefinition.hpp"
#include "unitConverter/unitconverter.hpp"

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

QByteArray GaugeDefinition::toBinary() const
{
    QByteArray ret = BinaryUtil::toBinary(title);
    ret += BinaryUtil::toBinary(unitString);
    ret += BinaryUtil::toBinary(minValue);
    ret += BinaryUtil::toBinary(maxValue);
    ret += BinaryUtil::toBinary(colorZones);
    ret += BinaryUtil::toBinary(grads);
    ret += BinaryUtil::toBinary(textGrads);
    ret += BinaryUtil::toBinary(textIncrement);
    ret += BinaryUtil::toBinary(textNumDigits);
    ret += BinaryUtil::toBinary(forceTextColor);
    ret += BinaryUtil::toBinary(textForcedColor);
    ret += BinaryUtil::toBinary(hasMinRedBlink);
    ret += BinaryUtil::toBinary(minRedBlinkThreshold);
    ret += BinaryUtil::toBinary(hasMaxRedBlink);
    ret += BinaryUtil::toBinary(maxRedBlinkThreshold);
    ret += BinaryUtil::toBinary(noText);
    ret += BinaryUtil::toBinary(unit);
    return ret;
}

GaugeDefinition GaugeDefinition::fromBinary(QIODevice &data, FileVersion version)
{
    switch (version)
    {
        case FileVersion::V1:
        case FileVersion::V2:
            return fromBinaryV1(data);
            break;
    }
}


GaugeDefinition GaugeDefinition::fromBinaryV1(QIODevice &data)
{
    GaugeDefinition ret;
    ret.title = BinaryUtil::readString(data);
    ret.unitString = BinaryUtil::readString(data);
    ret.minValue = BinaryUtil::readDouble(data);
    ret.maxValue = BinaryUtil::readDouble(data);
    BinaryUtil::readColorZoneVec(data, ret.colorZones);
    BinaryUtil::readGradVec(data, ret.grads);
    BinaryUtil::readTextGradVec(data, ret.textGrads);
    ret.textIncrement = BinaryUtil::readDouble(data);
    ret.textNumDigits = BinaryUtil::readInt8_t(data);
    ret.forceTextColor = BinaryUtil::readBool(data);
    ret.textForcedColor = BinaryUtil::readColor(data);
    ret.hasMinRedBlink = BinaryUtil::readBool(data);
    ret.minRedBlinkThreshold = BinaryUtil::readDouble(data);
    ret.hasMaxRedBlink = BinaryUtil::readBool(data);
    ret.maxRedBlinkThreshold = BinaryUtil::readDouble(data);
    ret.noText = BinaryUtil::readBool(data);
    ret.unit = BinaryUtil::readUnit(data);
    return ret;
}


double GaugeDefinition::getEpsilon(bool isCircular) const
{
    // convert into the default units
    double baseUnitRange = 0;
    double textIncrementBaseValue = 0;

    if (unit == Units::KELVIN)
    {
        baseUnitRange = maxValue - minValue;
        textIncrementBaseValue = textIncrement;
    }
    else if (unit == Units::FAHRENHEIT || unit == Units::RANKINE)
    {
        baseUnitRange = (maxValue - minValue) / 1.8;
        textIncrementBaseValue = textIncrement / 1.8;
    }
    else
    {
        void (*convertValue)(double *);
        UnitConverter::setConversionFunction(convertValue, unit);
        double inversionFactor = 1;
        convertValue(&inversionFactor);
        baseUnitRange = (maxValue - minValue) / inversionFactor;
        textIncrementBaseValue = textIncrement / inversionFactor;
    }

    double eps = 0;
    // calculate an epsilon that should give about 4 positions per pixel on a 1920x1200 display
    if (isCircular)
        eps = baseUnitRange / 1750.0;
    else
        eps = baseUnitRange / 500.0;

    return fmin(eps, textIncrementBaseValue / 2);
}
