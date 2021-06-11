#include "turbopropDefinition.h"

TurbopropDefinition::TurbopropDefinition(const RawTurbopropDefinition &rhs)
{
    n1Gauge = rhs.n1Gauge;
    trqGauge = rhs.trqGauge;
    ittGauge = rhs.ittGauge;
    rpmGauge = rhs.rpmGauge;
    egtGauge = rhs.egtGauge;
    hasEgt = rhs.hasEgt;
    usePropRpm = rhs.usePropRpm;
    torqueAsPct = rhs.torqueAsPct;
}

QByteArray TurbopropDefinition::toBinary() const
{
    QByteArray ret = n1Gauge.toBinary();
    ret += trqGauge.toBinary();
    ret += ittGauge.toBinary();
    ret += rpmGauge.toBinary();
    ret += egtGauge.toBinary();
    ret += BinaryUtil::toBinary(hasEgt);
    ret += BinaryUtil::toBinary(usePropRpm);
    ret += BinaryUtil::toBinary(torqueAsPct);
    return ret;
}

TurbopropDefinition TurbopropDefinition::fromBinary(QIODevice &data, FileVersion version)
{
    switch (version)
    {
        case FileVersion::V1:
        default:
            return fromBinaryV1(data, version);
            break;
    }
}

TurbopropDefinition TurbopropDefinition::fromBinaryV1(QIODevice &data, FileVersion version)
{
    TurbopropDefinition ret;
    ret.n1Gauge = GaugeDefinition::fromBinary(data, version);
    ret.trqGauge = GaugeDefinition::fromBinary(data, version);
    ret.ittGauge = GaugeDefinition::fromBinary(data, version);
    ret.rpmGauge = GaugeDefinition::fromBinary(data, version);
    ret.egtGauge = GaugeDefinition::fromBinary(data, version);
    ret.hasEgt = BinaryUtil::readBool(data);
    ret.usePropRpm = BinaryUtil::readBool(data);
    ret.torqueAsPct = BinaryUtil::readBool(data);
    return ret;
}
