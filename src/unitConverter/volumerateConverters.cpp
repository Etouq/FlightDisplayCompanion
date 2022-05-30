#include "unitconverter.h"


void UnitConverter::convertToLitresPerMin(double *value)
{
    *value /= 60.0;
}

void UnitConverter::convertToCubicCmPerMin(double *value)
{
    *value *= 1000.0 / 60.0;
}

void UnitConverter::convertToMlPerMin(double *value)
{
    *value *= 1000.0 / 60.0;
}

void UnitConverter::convertToCubicMPerMin(double *value)
{
    *value /= 1000.0 * 60.0;
}

void UnitConverter::convertToCubicInPerMin(double *value)
{
    *value *= 61.023744 / 60.0;
}

void UnitConverter::convertToOzUsPerMin(double *value)
{
    *value *= 33.814023 / 60.0;
}

void UnitConverter::convertToOzUkPerMin(double *value)
{
    *value *= 35.19508 / 60.0;
}

void UnitConverter::convertToQuartUsPerMin(double *value)
{
    *value *= 1.056688 / 60.0;
}

void UnitConverter::convertToQuartUkPerMin(double *value)
{
    *value *= 0.87987699 / 60.0;
}

void UnitConverter::convertToCubicFtPerMin(double *value)
{
    *value *= 0.0353146667 / 60.0;
}

void UnitConverter::convertToCubicYdPerMin(double *value)
{
    *value /= 764.5549 * 60.0;
}

void UnitConverter::convertToUsGalPerMin(double *value)
{
    *value *= 0.2641720523 / 60.0;
}

void UnitConverter::convertToUkGalPerMin(double *value)
{
    *value *= 0.21996925 / 60.0;
}


void UnitConverter::convertToLitresPerSec(double *value)
{
    *value /= 3600.0;
}

void UnitConverter::convertToCubicCmPerSec(double *value)
{
    *value *= 1000.0 / 3600.0;
}

void UnitConverter::convertToMlPerSec(double *value)
{
    *value *= 1000.0 / 3600.0;
}

void UnitConverter::convertToCubicMPerSec(double *value)
{
    *value /= 1000.0 * 3600.0;
}

void UnitConverter::convertToCubicInPerSec(double *value)
{
    *value *= 61.023744 / 3600.0;
}

void UnitConverter::convertToOzUsPerSec(double *value)
{
    *value *= 33.814023 / 3600.0;
}

void UnitConverter::convertToOzUkPerSec(double *value)
{
    *value *= 35.19508 / 3600.0;
}

void UnitConverter::convertToQuartUsPerSec(double *value)
{
    *value *= 1.056688 / 3600.0;
}

void UnitConverter::convertToQuartUkPerSec(double *value)
{
    *value *= 0.87987699 / 3600.0;
}

void UnitConverter::convertToCubicFtPerSec(double *value)
{
    *value *= 0.0353146667 / 3600.0;
}

void UnitConverter::convertToCubicYdPerSec(double *value)
{
    *value /= 764.5549 * 3600.0;
}

void UnitConverter::convertToUsGalPerSec(double *value)
{
    *value *= 0.2641720523 / 3600.0;
}

void UnitConverter::convertToUkGalPerSec(double *value)
{
    *value *= 0.21996925 / 3600.0;
}
