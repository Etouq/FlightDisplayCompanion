#include "unitconverter.h"



void UnitConverter::convertToInHg(double *value)
{
    *value /= 3.38639;
}

void UnitConverter::convertToBar(double *value)
{
    *value /= 100.0;
}

void UnitConverter::convertToPsi(double *value)
{
    *value /= 6.894757;
}

void UnitConverter::convertToPascal(double *value)
{
    *value *= 1000.0;
}

void UnitConverter::convertToMmHg(double *value)
{
    *value /= 0.133322387415;
}

void UnitConverter::convertToCmHg(double *value)
{
    *value /= 1.33322387415;
}

void UnitConverter::convertToAtm(double *value)
{
    *value /= 101.325;
}

void UnitConverter::convertToPsf(double *value)
{
    *value /= 20.88543423315;
}

void UnitConverter::convertToMbar(double *value)
{
    *value *= 10.0;
}

void UnitConverter::convertToHectoPascal(double *value)
{
    *value *= 10.0;
}

void UnitConverter::convertToMmH2O(double *value)
{
    *value /= 0.00980665;
}

void UnitConverter::convertToCmH2O(double *value)
{
    *value /= 0.0980665;
}

void UnitConverter::convertToInH2O(double *value)
{
    *value /= 0.24884;
}
