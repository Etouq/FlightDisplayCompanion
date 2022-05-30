#include "unitconverter.hpp"

void UnitConverter::convertToCubicCm(double *value)
{
    *value *= 1000.0;
}

void UnitConverter::convertToMl(double *value)
{
    *value *= 1000.0;
}

void UnitConverter::convertToCubicM(double *value)
{
    *value /= 1000.0;
}

void UnitConverter::convertToCubicIn(double *value)
{
    *value *= 61.023744;
}

void UnitConverter::convertToOzUs(double *value)
{
    *value *= 33.814023;
}

void UnitConverter::convertToOzUk(double *value)
{
    *value *= 35.19508;
}

void UnitConverter::convertToQuartUs(double *value)
{
    *value *= 1.056688;
}

void UnitConverter::convertToQuartUk(double *value)
{
    *value *= 0.87987699;
}

void UnitConverter::convertToCubicFt(double *value)
{
    *value *= 0.0353146667;
}

void UnitConverter::convertToCubicYd(double *value)
{
    *value /= 764.5549;
}

void UnitConverter::convertToUsGal(double *value)
{
    *value *= 0.2641720523;
}

void UnitConverter::convertToUkGal(double *value)
{
    *value *= 0.21996925;
}
