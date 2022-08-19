#include "AircraftDefinition.hpp"
#include <QIODevice>

namespace definitions
{

AircraftDefinition AircraftDefinition::fromBinary(QIODevice &data)
{
    AircraftDefinition ret;

    data.read(reinterpret_cast<char *>(&ret.type), sizeof(ret.type));

    uint8_t stringSize = 0;
    data.read(reinterpret_cast<char *>(&stringSize), sizeof(stringSize));
    ret.name = QString::fromUtf8(data.read(stringSize));


    ret.firstGauge = GaugeDefinition::fromBinary(data);
    ret.secondGauge = GaugeDefinition::fromBinary(data);
    ret.thirdGauge = GaugeDefinition::fromBinary(data);
    ret.fourthGauge = GaugeDefinition::fromBinary(data);

    ret.fuelQtyGauge = GaugeDefinition::fromBinary(data);
    ret.fuelFlowGauge = GaugeDefinition::fromBinary(data);
    ret.oilTempGauge = GaugeDefinition::fromBinary(data);
    ret.secondaryTempGauge = GaugeDefinition::fromBinary(data);
    ret.oilPressGauge = GaugeDefinition::fromBinary(data);


    data.read(reinterpret_cast<char *>(&ret.gauge1Type), sizeof(ret.gauge1Type));
    data.read(reinterpret_cast<char *>(&ret.gauge2Type), sizeof(ret.gauge2Type));
    data.read(reinterpret_cast<char *>(&ret.gauge3Type), sizeof(ret.gauge3Type));
    data.read(reinterpret_cast<char *>(&ret.gauge4Type), sizeof(ret.gauge4Type));

    data.read(reinterpret_cast<char *>(&ret.engineTempType), sizeof(ret.engineTempType));


    data.read(reinterpret_cast<char *>(&ret.maxPower), sizeof(ret.maxPower));
    data.read(reinterpret_cast<char *>(&ret.maxTorque), sizeof(ret.maxTorque));


    data.read(reinterpret_cast<char *>(&ret.hasApu), sizeof(ret.hasApu));


    data.read(reinterpret_cast<char *>(&ret.hasFlaps), sizeof(ret.hasFlaps));
    data.read(reinterpret_cast<char *>(&ret.hasSpoilers), sizeof(ret.hasSpoilers));

    data.read(reinterpret_cast<char *>(&ret.hasElevatorTrim), sizeof(ret.hasElevatorTrim));
    data.read(reinterpret_cast<char *>(&ret.hasRudderTrim), sizeof(ret.hasRudderTrim));
    data.read(reinterpret_cast<char *>(&ret.hasAileronTrim), sizeof(ret.hasAileronTrim));

    data.read(reinterpret_cast<char *>(&ret.hasSecondaryTempGauge), sizeof(ret.hasSecondaryTempGauge));
    data.read(reinterpret_cast<char *>(&ret.secondaryTempType), sizeof(ret.secondaryTempType));

    data.read(reinterpret_cast<char *>(&ret.numEngines), sizeof(ret.numEngines));
    data.read(reinterpret_cast<char *>(&ret.singleTank), sizeof(ret.singleTank));


    data.read(reinterpret_cast<char *>(&ret.lowLimit), sizeof(ret.lowLimit));
    data.read(reinterpret_cast<char *>(&ret.flapsBegin), sizeof(ret.flapsBegin));
    data.read(reinterpret_cast<char *>(&ret.flapsEnd), sizeof(ret.flapsEnd));
    data.read(reinterpret_cast<char *>(&ret.greenBegin), sizeof(ret.greenBegin));
    data.read(reinterpret_cast<char *>(&ret.greenEnd), sizeof(ret.greenEnd));
    data.read(reinterpret_cast<char *>(&ret.yellowBegin), sizeof(ret.yellowBegin));
    data.read(reinterpret_cast<char *>(&ret.yellowEnd), sizeof(ret.yellowEnd));
    data.read(reinterpret_cast<char *>(&ret.redBegin), sizeof(ret.redBegin));
    data.read(reinterpret_cast<char *>(&ret.redEnd), sizeof(ret.redEnd));
    data.read(reinterpret_cast<char *>(&ret.highLimit), sizeof(ret.highLimit));

    data.read(reinterpret_cast<char *>(&ret.noColors), sizeof(ret.noColors));
    data.read(reinterpret_cast<char *>(&ret.hasLowLimit), sizeof(ret.hasLowLimit));
    data.read(reinterpret_cast<char *>(&ret.hasFlapsSpeed), sizeof(ret.hasFlapsSpeed));
    data.read(reinterpret_cast<char *>(&ret.hasGreenSpeed), sizeof(ret.hasGreenSpeed));
    data.read(reinterpret_cast<char *>(&ret.hasYellowSpeed), sizeof(ret.hasYellowSpeed));
    data.read(reinterpret_cast<char *>(&ret.hasRedSpeed), sizeof(ret.hasRedSpeed));
    data.read(reinterpret_cast<char *>(&ret.hasHighLimit), sizeof(ret.hasHighLimit));
    data.read(reinterpret_cast<char *>(&ret.dynamicBarberpole), sizeof(ret.dynamicBarberpole));

    uint8_t listSize = 0;
    data.read(reinterpret_cast<char *>(&listSize), sizeof(listSize));

    ret.refSpeedDefaults.clear();

    uint16_t bugSetting = 0;

    while (listSize--)
    {
        data.read(reinterpret_cast<char *>(&bugSetting), sizeof(bugSetting));
        data.read(reinterpret_cast<char *>(&stringSize), sizeof(stringSize));
        ret.refSpeedDefaults.push_back({ bugSetting, QString::fromUtf8(data.read(stringSize)) });
    }


    return ret;
}

}  // namespace definitions
