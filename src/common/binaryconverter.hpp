#ifndef BINARYCONVERTER_HPP
#define BINARYCONVERTER_HPP

#include "mfdbackend.hpp"
#include "AircraftConfig.hpp"
#include "definitions/basetypes.hpp"

// #include <concepts>
#include <cstdint>
#include <QByteArray>
#include <QIODevice>
#include <QList>

#include <type_traits>

namespace BinaryConverter
{

template<typename T>
concept Numeric = std::is_arithmetic_v<T> || std::is_enum_v<T>;

// to binary converters
template<Numeric T>
[[nodiscard]] inline QByteArray convert(T val)
{
    return QByteArray(reinterpret_cast<char *>(&val), sizeof(val));
}

[[nodiscard]] inline QByteArray convert(const QString &str)
{
    QByteArray bytes = str.toUtf8();
    uint8_t size = bytes.size();
    return bytes.prepend(reinterpret_cast<char *>(&size), sizeof(size));
}

[[nodiscard]] inline QByteArray convert(const QColor &col)
{
    uint8_t red = col.red();
    uint8_t green = col.green();
    uint8_t blue = col.blue();
    return QByteArray(reinterpret_cast<char *>(&red), sizeof(red)).append(reinterpret_cast<char *>(&green), sizeof(green)).append(reinterpret_cast<char *>(&blue), sizeof(blue));
}

[[nodiscard]] inline QByteArray convert(const definitions::ColorZone &zone)
{
    return convert(zone.start) + convert(zone.end) + convert(zone.color);
}

[[nodiscard]] inline QByteArray convert(const definitions::GradDef &grad)
{
    return convert(grad.gradPos) + convert(grad.isBig) + convert(grad.gradColor);
}

[[nodiscard]] inline QByteArray convert(const definitions::TextGradDef &textGrad)
{
    return convert(textGrad.textGradPos) + convert(textGrad.gradText);
}

[[nodiscard]] inline QByteArray convert(const FlightPlanWaypoint &wp)
{
    return convert(wp.position.latitude())
    + convert(wp.position.longitude())
    + convert(wp.alt1)
    + convert(wp.alt2)
    + convert(wp.ident)
    + convert(wp.wpType)
    + convert(wp.altType);
}

[[nodiscard]] inline QByteArray convert(const AircraftConfig &config)
{
    return convert(config.numEngines)
    + convert(config.type)
    + convert(config.n1Epsilon)
    + convert(config.n2Epsilon)
    + convert(config.ittEpsilon)
    + convert(config.rpmEpsilon)
    + convert(config.powerEpsilon)
    + convert(config.manPressEpsilon)
    + convert(config.chtEpsilon)
    + convert(config.trqEpsilon)
    + convert(config.fuelFlowEpsilon)
    + convert(config.egtEpsilon)
    + convert(config.oilTempEpsilon)
    + convert(config.oilPressEpsilon)
    + convert(config.fuelQtyEpsilon)
    + convert(config.ittGaugeType)
    + convert(config.hasRpm)
    + convert(config.usePropRpm)
    + convert(config.hasPower)
    + convert(config.powerAsPct)
    + convert(config.maxPower)
    + convert(config.hasManPress)
    + convert(config.hasCht)
    + convert(config.chtGaugeType)
    + convert(config.trqAsPct)
    + convert(config.rpmAsPct)
    + convert(config.fuelFlowByWeight)
    + convert(config.singleTank)
    + convert(config.fuelQtyByWeight)
    + convert(config.hasApu)
    + convert(config.hasEgt)
    + convert(config.egtGaugeType)
    + convert(config.hasFlaps)
    + convert(config.hasSpoilers)
    + convert(config.hasElevTrim)
    + convert(config.hasRudderTrim)
    + convert(config.hasAileronTrim);
}

template<class T> requires requires(T a) { convert(a); }
[[nodiscard]] inline QByteArray convert(const QList<T> &list)
{
    QByteArray ret = convert(static_cast<uint16_t>(list.size()));
    for (const T &val : list)
        ret += convert(val);

    return ret;
}

// from binary converters
template<Numeric T>
[[nodiscard]] inline T convert(QIODevice &data)
{
    T val;
    data.read(reinterpret_cast<char *>(&val), sizeof(val));
    return val;
}

template<Numeric T>
inline void convert(QIODevice &data, T &val)
{
    data.read(reinterpret_cast<char *>(&val), sizeof(val));
}

template<class T>
requires std::is_same_v<T, QString>
[[nodiscard]] inline QString convert(QIODevice &data)
{
    const uint8_t size = convert<uint8_t>(data);
    return size == 0 ? "" : QString::fromUtf8(data.read(size));
}

[[nodiscard]] inline QString convertWithSize(QIODevice &data, uint8_t size)
{
    return QString::fromUtf8(data.read(size));
}

template<class T>
requires std::is_same_v<T, FlightPlanWaypoint>
[[nodiscard]] inline FlightPlanWaypoint convert(QIODevice &data)
{
    FlightPlanWaypoint ret;
    ret.position = QGeoCoordinate(convert<double>(data), convert<double>(data));
    convert(data, ret.alt1);
    convert(data, ret.alt2);
    convert(data, ret.wpType);
    convert(data, ret.altType);
    ret.ident = convert<QString>(data);
    return ret;
}

inline void convert(QIODevice &data, FlightPlanWaypoint &val)
{
    val.position = QGeoCoordinate(convert<double>(data), convert<double>(data));
    convert(data, val.alt1);
    convert(data, val.alt2);
    convert(data, val.wpType);
    convert(data, val.altType);
    val.ident = convert<QString>(data);
}

template<class T>
requires std::is_same_v<T, AircraftConfig>
[[nodiscard]] inline AircraftConfig convert(QIODevice &data)
{
    AircraftConfig ret;
    convert(data, ret.numEngines);
    convert(data, ret.type);
    convert(data, ret.n1Epsilon);
    convert(data, ret.n2Epsilon);
    convert(data, ret.ittEpsilon);
    convert(data, ret.rpmEpsilon);
    convert(data, ret.powerEpsilon);
    convert(data, ret.manPressEpsilon);
    convert(data, ret.chtEpsilon);
    convert(data, ret.trqEpsilon);
    convert(data, ret.fuelFlowEpsilon);
    convert(data, ret.egtEpsilon);
    convert(data, ret.oilTempEpsilon);
    convert(data, ret.oilPressEpsilon);
    convert(data, ret.fuelQtyEpsilon);
    convert(data, ret.ittGaugeType);
    convert(data, ret.hasRpm);
    convert(data, ret.usePropRpm);
    convert(data, ret.hasPower);
    convert(data, ret.powerAsPct);
    convert(data, ret.maxPower);
    convert(data, ret.hasManPress);
    convert(data, ret.hasCht);
    convert(data, ret.chtGaugeType);
    convert(data, ret.trqAsPct);
    convert(data, ret.rpmAsPct);
    convert(data, ret.fuelFlowByWeight);
    convert(data, ret.singleTank);
    convert(data, ret.fuelQtyByWeight);
    convert(data, ret.hasApu);
    convert(data, ret.hasEgt);
    convert(data, ret.egtGaugeType);
    convert(data, ret.hasFlaps);
    convert(data, ret.hasSpoilers);
    convert(data, ret.hasElevTrim);
    convert(data, ret.hasRudderTrim);
    convert(data, ret.hasAileronTrim);

    return ret;
}

inline void convert(QIODevice &data, AircraftConfig &val)
{
    convert(data, val.numEngines);
    convert(data, val.type);
    convert(data, val.n1Epsilon);
    convert(data, val.n2Epsilon);
    convert(data, val.ittEpsilon);
    convert(data, val.rpmEpsilon);
    convert(data, val.powerEpsilon);
    convert(data, val.manPressEpsilon);
    convert(data, val.chtEpsilon);
    convert(data, val.trqEpsilon);
    convert(data, val.fuelFlowEpsilon);
    convert(data, val.egtEpsilon);
    convert(data, val.oilTempEpsilon);
    convert(data, val.oilPressEpsilon);
    convert(data, val.fuelQtyEpsilon);
    convert(data, val.ittGaugeType);
    convert(data, val.hasRpm);
    convert(data, val.usePropRpm);
    convert(data, val.hasPower);
    convert(data, val.powerAsPct);
    convert(data, val.maxPower);
    convert(data, val.hasManPress);
    convert(data, val.hasCht);
    convert(data, val.chtGaugeType);
    convert(data, val.trqAsPct);
    convert(data, val.rpmAsPct);
    convert(data, val.fuelFlowByWeight);
    convert(data, val.singleTank);
    convert(data, val.fuelQtyByWeight);
    convert(data, val.hasApu);
    convert(data, val.hasEgt);
    convert(data, val.egtGaugeType);
    convert(data, val.hasFlaps);
    convert(data, val.hasSpoilers);
    convert(data, val.hasElevTrim);
    convert(data, val.hasRudderTrim);
    convert(data, val.hasAileronTrim);
}

template<typename T> requires requires(T a, QIODevice &data) { convert(data, a); }
[[nodiscard]] inline QList<T> convertList(QIODevice &data)
{
    uint16_t size = convert<uint16_t>(data);
    QList<T> ret;
    ret.reserve(size);

    ++size;
    while (--size)
        ret.append(convert<T>(data));

    return ret;
}

template<typename T> requires requires(T a, QIODevice &data) { convert(data, a); }
inline void convertList(QIODevice &data, QList<T> &list)
{
    list.clear();
    uint16_t size = convert<uint16_t>(data);
    list.reserve(size);

    ++size;
    while (--size)
        list.append(convert<T>(data));
}

}  // namespace BinaryConverter

#endif  // BINARYCONVERTER_HPP
