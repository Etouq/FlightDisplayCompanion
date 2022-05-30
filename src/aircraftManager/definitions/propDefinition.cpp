#include "propDefinition.hpp"

PropDefinition::PropDefinition(const RawPropDefinition &rhs)
{
    rpmGauge = rhs.rpmGauge;
    secondGauge = rhs.secondGauge;
    egtGauge = rhs.egtGauge;
    hasEgt = rhs.hasEgt;
    usePropRpm = rhs.usePropRpm;
    secondIsLoad = rhs.secondIsLoad;
    maxHp = rhs.maxHp;
}

QByteArray PropDefinition::toBinary() const
{
    QByteArray ret = rpmGauge.toBinary();
    ret += secondGauge.toBinary();
    ret += egtGauge.toBinary();
    ret += BinaryUtil::toBinary(hasEgt);
    ret += BinaryUtil::toBinary(usePropRpm);
    ret += BinaryUtil::toBinary(secondIsLoad);
    ret += BinaryUtil::toBinary(maxHp);
    return ret;
}

PropDefinition PropDefinition::fromBinary(QIODevice &data, FileVersion version)
{
    switch (version)
    {
        case FileVersion::V1:
        case FileVersion::V2:
            return fromBinaryV1(data, version);
            break;
    }
}

PropDefinition PropDefinition::fromBinaryV1(QIODevice &data, FileVersion version)
{
    PropDefinition ret;
    ret.rpmGauge = GaugeDefinition::fromBinary(data, version);
    ret.secondGauge = GaugeDefinition::fromBinary(data, version);
    ret.egtGauge = GaugeDefinition::fromBinary(data, version);
    ret.hasEgt = BinaryUtil::readBool(data);
    ret.usePropRpm = BinaryUtil::readBool(data);
    ret.secondIsLoad = BinaryUtil::readBool(data);
    ret.maxHp = BinaryUtil::readDouble(data);
    return ret;
}
