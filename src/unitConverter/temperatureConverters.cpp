#include "unitconverter.hpp"



void UnitConverter::convertToFahrenheit(double *value)
{
    *value = *value * 1.8 + 32.0;
}

void UnitConverter::convertToKelvin(double *value)
{
    *value += 273.15;
}

void UnitConverter::convertToRankine(double *value)
{
    *value = (*value + 273.15) * 1.8;
}
