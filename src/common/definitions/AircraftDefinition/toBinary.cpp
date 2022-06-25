#include "AircraftDefinition.hpp"
#include "common/converters/listConverters.hpp"


namespace definitions
{

QByteArray AircraftDefinition::toBinary() const
{
    QByteArray ret = Converters::convert(type);

    Converters::convert(name);

    ret += firstGauge.toBinary();
    ret += secondGauge.toBinary();
    ret += thirdGauge.toBinary();
    ret += fourthGauge.toBinary();

    ret += fuelQtyGauge.toBinary();
    ret += fuelFlowGauge.toBinary();
    ret += oilTempGauge.toBinary();
    ret += secondaryTempGauge.toBinary();
    ret += oilPressGauge.toBinary();

    ret += Converters::convert(gauge1Type);
    ret += Converters::convert(gauge2Type);
    ret += Converters::convert(gauge3Type);
    ret += Converters::convert(gauge4Type);

    ret += Converters::convert(engineTempType);

    ret += Converters::convert(maxPower);

    ret += Converters::convert(hasApu);

    ret += Converters::convert(hasFlaps);
    ret += Converters::convert(hasSpoilers);

    ret += Converters::convert(hasElevatorTrim);
    ret += Converters::convert(hasRudderTrim);
    ret += Converters::convert(hasAileronTrim);

    ret += Converters::convert(fuelQtyByWeight);
    ret += Converters::convert(fuelFlowByWeight);

    ret += Converters::convert(hasSecondaryTempGauge);
    ret += Converters::convert(secondaryTempType);

    ret += Converters::convert(numEngines);
    ret += Converters::convert(singleTank);

    ret += Converters::convert(lowLimit);
    ret += Converters::convert(flapsBegin);
    ret += Converters::convert(flapsEnd);
    ret += Converters::convert(greenBegin);
    ret += Converters::convert(greenEnd);
    ret += Converters::convert(yellowBegin);
    ret += Converters::convert(yellowEnd);
    ret += Converters::convert(redBegin);
    ret += Converters::convert(redEnd);
    ret += Converters::convert(highLimit);
    ret += Converters::convert(noColors);
    ret += Converters::convert(dynamicBarberpole);

    ret += Converters::convert(refSpeedDefaults);

    return ret;
}



}
