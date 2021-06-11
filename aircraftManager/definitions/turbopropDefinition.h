#ifndef TURBOPROPDEFINITION_H
#define TURBOPROPDEFINITION_H

#include "gaugeDefinition.h"

// used to allow for designated initialization
struct RawTurbopropDefinition
{
    GaugeDefinition n1Gauge;
    GaugeDefinition trqGauge;
    GaugeDefinition ittGauge;
    GaugeDefinition rpmGauge;
    GaugeDefinition egtGauge;

    bool hasEgt = false;

    bool usePropRpm = false;

    bool torqueAsPct = false;
};

struct TurbopropDefinition
{
    GaugeDefinition n1Gauge;
    GaugeDefinition trqGauge;
    GaugeDefinition ittGauge;
    GaugeDefinition rpmGauge;
    GaugeDefinition egtGauge;

    bool hasEgt = false;

    bool usePropRpm = false;

    bool torqueAsPct = false;

    TurbopropDefinition() = default;
    ~TurbopropDefinition() = default;
    TurbopropDefinition(const TurbopropDefinition &) = default;
    TurbopropDefinition(const RawTurbopropDefinition &rhs);
    TurbopropDefinition &operator=(const TurbopropDefinition &) = default;

    QByteArray toBinary() const;

    static TurbopropDefinition fromBinary(QIODevice &data, FileVersion version);

private:
    static TurbopropDefinition fromBinaryV1(QIODevice &data, FileVersion version);
};

Q_DECLARE_METATYPE(TurbopropDefinition)

#endif   // TURBOPROPDEFINITION_H
