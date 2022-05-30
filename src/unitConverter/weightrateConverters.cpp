#include "unitconverter.hpp"

void UnitConverter::convertToKgPerMin(double *value)
{
    *value /= 60.0;
}

void UnitConverter::convertToTonnePerMin(double *value)
{
    *value /= 1000.0 * 60.0;
}

void UnitConverter::convertToSlugPerMin(double *value)
{
    *value /= 14.59390 * 60.0;
}

void UnitConverter::convertToGramPerMin(double *value)
{
    *value *= 1000.0 / 60.0;
}

void UnitConverter::convertToLbsPerMin(double *value)
{
    *value /= 0.45359237 * 60.0;
}

void UnitConverter::convertToUsTonnePerMin(double *value)
{
    *value /= 907.18474 * 60.0;
}

void UnitConverter::convertToUkTonnePerMin(double *value)
{
    *value /= 1016.0469 * 60.0;
}


void UnitConverter::convertToKgPerSec(double *value)
{
    *value /= 3600.0;
}

void UnitConverter::convertToTonnePerSec(double *value)
{
    *value /= 1000.0 * 3600.0;
}

void UnitConverter::convertToSlugPerSec(double *value)
{
    *value /= 14.59390 * 3600.0;
}

void UnitConverter::convertToGramPerSec(double *value)
{
    *value *= 1000.0 / 3600.0;
}

void UnitConverter::convertToLbsPerSec(double *value)
{
    *value /= 0.45359237 * 3600.0;
}

void UnitConverter::convertToUsTonnePerSec(double *value)
{
    *value /= 907.18474 * 3600.0;
}

void UnitConverter::convertToUkTonnePerSec(double *value)
{
    *value /= 1016.0469 * 3600.0;
}
