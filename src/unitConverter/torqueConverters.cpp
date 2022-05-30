#include "unitconverter.h"


void UnitConverter::convertToFootPound(double *value)
{
    *value /= 1.355818;
}

void UnitConverter::convertToInchPound(double *value)
{
    *value *= 8.8507457676;
}
