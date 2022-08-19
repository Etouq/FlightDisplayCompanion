#include "gaugeDefinition.hpp"
#include <QIODevice>

namespace definitions
{

GaugeDefinition GaugeDefinition::fromBinary(QIODevice &data)
{
    GaugeDefinition ret;

    uint8_t size = 0;
    data.read(reinterpret_cast<char *>(&size), sizeof(size));
    ret.title = QString::fromUtf8(data.read(size));

    data.read(reinterpret_cast<char *>(&size), sizeof(size));
    ret.unitString = QString::fromUtf8(data.read(size));

    data.read(reinterpret_cast<char *>(&ret.minValue), sizeof(ret.minValue));
    data.read(reinterpret_cast<char *>(&ret.maxValue), sizeof(ret.maxValue));

    uint8_t listSize = 0;
    data.read(reinterpret_cast<char *>(&listSize), sizeof(listSize));

    double start = 0;
    double end = 0;
    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = 0;
    ++listSize;
    while (--listSize)
    {
        data.read(reinterpret_cast<char *>(&start), sizeof(start));
        data.read(reinterpret_cast<char *>(&end), sizeof(end));
        data.read(reinterpret_cast<char *>(&red), sizeof(red));
        data.read(reinterpret_cast<char *>(&green), sizeof(green));
        data.read(reinterpret_cast<char *>(&blue), sizeof(blue));

        ret.colorZones.append({ start, end, QColor(red, green, blue)});
    }

    data.read(reinterpret_cast<char *>(&listSize), sizeof(listSize));

    bool isBig = false;
    ++listSize;
    while (--listSize)
    {
        data.read(reinterpret_cast<char *>(&start), sizeof(start));
        data.read(reinterpret_cast<char *>(&isBig), sizeof(isBig));
        data.read(reinterpret_cast<char *>(&red), sizeof(red));
        data.read(reinterpret_cast<char *>(&green), sizeof(green));
        data.read(reinterpret_cast<char *>(&blue), sizeof(blue));

        ret.grads.append({start, isBig, QColor(red, green, blue)});
    }
    data.read(reinterpret_cast<char *>(&listSize), sizeof(listSize));

    ++listSize;
    while (--listSize)
    {
        data.read(reinterpret_cast<char *>(&start), sizeof(start));
        data.read(reinterpret_cast<char *>(&size), sizeof(size));

        ret.textGrads.append({ start, QString::fromUtf8(data.read(size))});
    }

    data.read(reinterpret_cast<char *>(&ret.textIncrement), sizeof(ret.textIncrement));
    data.read(reinterpret_cast<char *>(&ret.textNumDigits), sizeof(ret.textNumDigits));

    data.read(reinterpret_cast<char *>(&ret.forceTextColor), sizeof(ret.forceTextColor));
    data.read(reinterpret_cast<char *>(&red), sizeof(red));
    data.read(reinterpret_cast<char *>(&green), sizeof(green));
    data.read(reinterpret_cast<char *>(&blue), sizeof(blue));
    ret.textForcedColor.setRgb(red, green, blue);

    data.read(reinterpret_cast<char *>(&ret.hasMinRedBlink), sizeof(ret.hasMinRedBlink));
    data.read(reinterpret_cast<char *>(&ret.minRedBlinkThreshold), sizeof(ret.minRedBlinkThreshold));
    data.read(reinterpret_cast<char *>(&ret.hasMaxRedBlink), sizeof(ret.hasMaxRedBlink));
    data.read(reinterpret_cast<char *>(&ret.maxRedBlinkThreshold), sizeof(ret.maxRedBlinkThreshold));

    data.read(reinterpret_cast<char *>(&ret.noText), sizeof(ret.noText));

    data.read(reinterpret_cast<char *>(&ret.unit), sizeof(ret.unit));

    return ret;
}

}  // namespace definitions
