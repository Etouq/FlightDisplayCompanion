#include "unitconverter.hpp"


void UnitConverter::convertToTonne(double *value)
{
    *value /= 1000.0;
}

void UnitConverter::convertToSlug(double *value)
{
    *value /= 14.59390;
}

void UnitConverter::convertToGram(double *value)
{
    *value *= 1000.0;
}

void UnitConverter::convertToLbs(double *value)
{
    *value /= 0.45359237;
}

void UnitConverter::convertToUsTonne(double *value)
{
    *value /= 907.18474;
}

void UnitConverter::convertToUkTonne(double *value)
{
    *value /= 1016.0469;
}
