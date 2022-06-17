#ifndef __STRUCT_CONVERTERS_HPP__
#define __STRUCT_CONVERTERS_HPP__


#include "basicConverters.hpp"
#include "mfdbackend.hpp"
#include "../AircraftConfig.hpp"
#include "../definitions/baseTypes.hpp"
#include "pages/MfdPage/FlightPlan/FlightPlanWaypoint.hpp"

#include <QByteArray>
#include <QIODevice>

#include <type_traits>


namespace Converters
{

// to binary converters
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

[[nodiscard]] inline QByteArray convert(const definitions::ReferenceSpeed &refSpeed)
{
    return convert(refSpeed.speed) + convert(refSpeed.designator);
}

[[nodiscard]] inline QByteArray convert(const FlightPlanWaypoint &wp)
{
    return convert(wp.position.latitude()) + convert(wp.position.longitude()) + convert(wp.alt1) + convert(wp.alt2)
      + convert(wp.ident) + convert(wp.wpType) + convert(wp.altType);
}

[[nodiscard]] inline QByteArray convert(const pages::mfd::FlightPlanWaypoint &wp)
{
    return convert(wp.position.latitude()) + convert(wp.position.longitude()) + convert(wp.alt1) + convert(wp.alt2)
      + convert(wp.ident) + convert(wp.wpType) + convert(wp.altType);
}

[[nodiscard]] inline QByteArray convert(const AircraftConfig &config)
{
    return convert(config.numEngines) + convert(config.type) + convert(config.n1Epsilon) + convert(config.n2Epsilon)
      + convert(config.ittEpsilon) + convert(config.rpmEpsilon) + convert(config.powerEpsilon)
      + convert(config.manPressEpsilon) + convert(config.chtEpsilon) + convert(config.trqEpsilon)
      + convert(config.fuelFlowEpsilon) + convert(config.egtEpsilon) + convert(config.oilTempEpsilon)
      + convert(config.oilPressEpsilon) + convert(config.fuelQtyEpsilon) + convert(config.ittGaugeType)
      + convert(config.hasRpm) + convert(config.usePropRpm) + convert(config.hasPower) + convert(config.powerAsPct)
      + convert(config.maxPower) + convert(config.hasManPress) + convert(config.hasCht) + convert(config.chtGaugeType)
      + convert(config.trqAsPct) + convert(config.rpmAsPct) + convert(config.fuelFlowByWeight)
      + convert(config.singleTank) + convert(config.fuelQtyByWeight) + convert(config.hasApu) + convert(config.hasEgt)
      + convert(config.egtGaugeType) + convert(config.hasFlaps) + convert(config.hasSpoilers)
      + convert(config.hasElevTrim) + convert(config.hasRudderTrim) + convert(config.hasAileronTrim);
}

// from binary converters
template<class T>
requires std::is_same_v<T, definitions::ColorZone>

[[nodiscard]] inline definitions::ColorZone convert(QIODevice &data)
{
    return { convert<double>(data), convert<double>(data), convert<QColor>(data) };
}

inline void convert(QIODevice &data, definitions::ColorZone &val)
{
    convert(data, val.start);
    convert(data, val.end);
    convert(data, val.color);
}

template<class T>
requires std::is_same_v<T, definitions::GradDef>

[[nodiscard]] inline definitions::GradDef convert(QIODevice &data)
{
    return { convert<double>(data), convert<bool>(data), convert<QColor>(data) };
}

inline void convert(QIODevice &data, definitions::GradDef &val)
{
    convert(data, val.gradPos);
    convert(data, val.isBig);
    convert(data, val.gradColor);
}


template<class T>
requires std::is_same_v<T, definitions::TextGradDef>

[[nodiscard]] inline definitions::TextGradDef convert(QIODevice &data)
{
    return { convert<double>(data), convert<QString>(data) };
}

inline void convert(QIODevice &data, definitions::TextGradDef &val)
{
    convert(data, val.textGradPos);
    val.gradText = convert<QString>(data);
}


template<class T>
requires std::is_same_v<T, definitions::ReferenceSpeed>

[[nodiscard]] inline definitions::ReferenceSpeed convert(QIODevice &data)
{
    return { convert<uint16_t>(data), convert<QString>(data) };
}

inline void convert(QIODevice &data, definitions::ReferenceSpeed &val)
{
    convert(data, val.speed);
    val.designator = convert<QString>(data);
}


inline void convert(QIODevice &data, FlightPlanWaypoint &val)
{
    val.position = QGeoCoordinate(convert<double>(data), convert<double>(data));
    convert(data, val.alt1);
    convert(data, val.alt2);
    val.ident = convert<QString>(data);
    convert(data, val.wpType);
    convert(data, val.altType);
}

template<class T>
requires std::is_same_v<T, FlightPlanWaypoint>
[[nodiscard]] inline FlightPlanWaypoint convert(QIODevice &data)
{
    FlightPlanWaypoint ret;
    convert(data, ret);
    return ret;
}


inline void convert(QIODevice &data, pages::mfd::FlightPlanWaypoint &val)
{
    val.position = QGeoCoordinate(convert<double>(data), convert<double>(data));
    convert(data, val.alt1);
    convert(data, val.alt2);
    val.ident = convert<QString>(data);
    convert(data, val.wpType);
    convert(data, val.altType);
}

template<class T>
requires std::is_same_v<T, pages::mfd::FlightPlanWaypoint>
[[nodiscard]] inline pages::mfd::FlightPlanWaypoint convert(QIODevice &data)
{
    pages::mfd::FlightPlanWaypoint ret;
    convert(data, ret);
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

template<class T>
requires std::is_same_v<T, AircraftConfig>

[[nodiscard]] inline AircraftConfig convert(QIODevice &data)
{
    AircraftConfig ret;
    convert(data, ret);
    return ret;
}

}  // namespace Converters


#endif  // __STRUCT_CONVERTERS_HPP__