#include "gaugeDefinition.hpp"
#include "unitConverter/unitconverter.hpp"

namespace definitions
{

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

}  // namespace definitions
