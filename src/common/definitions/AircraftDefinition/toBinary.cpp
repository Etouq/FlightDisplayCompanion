#include "AircraftDefinition.hpp"
#include "common/converters/listConverters.hpp"


namespace definitions
{

QByteArray AircraftDefinition::toBinary() const
{
    QByteArray ret = Converters::convert(name);
    ret += fuelQtyGauge.toBinary();
    ret += fuelFlowGauge.toBinary();
    ret += oilTempGauge.toBinary();
    ret += oilPressGauge.toBinary();
    ret += egtGauge.toBinary();

    ret += Converters::convert(hasFlaps);
    ret += Converters::convert(hasSpoilers);

    ret += Converters::convert(hasElevatorTrim);
    ret += Converters::convert(hasRudderTrim);
    ret += Converters::convert(hasAileronTrim);

    ret += Converters::convert(fuelQtyByWeight);
    ret += Converters::convert(fuelFlowByWeight);

    ret += Converters::convert(hasEgt);
    ret += Converters::convert(egtGaugeType);


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
