#ifndef UNITCONVERTER_H
#define UNITCONVERTER_H

#include "units.hpp"

// provides conversion functions to allow for custom units
class UnitConverter
{
public:
    static void setConversionFunction(void (*&convertValue)(double *), Units unit);

    // for default values
    static void doNothing(double *value);

    // temperature
    static void convertToFahrenheit(double *value);
    static void convertToKelvin(double *value);
    static void convertToRankine(double *value);

    // pressure
    static void convertToInHg(double *value);
    static void convertToBar(double *value);
    static void convertToPsi(double *value);
    static void convertToPascal(double *value);
    static void convertToMmHg(double *value);
    static void convertToCmHg(double *value);
    static void convertToAtm(double *value);
    static void convertToPsf(double *value);
    static void convertToMbar(double *value);
    static void convertToHectoPascal(double *value);
    static void convertToMmH2O(double *value);
    static void convertToCmH2O(double *value);
    static void convertToInH2O(double *value);

    // torque
    static void convertToFootPound(double *value);
    static void convertToInchPound(double *value);

    // volume
    static void convertToCubicCm(double *value);
    static void convertToMl(double *value);
    static void convertToCubicM(double *value);
    static void convertToCubicIn(double *value);
    static void convertToOzUs(double *value);
    static void convertToOzUk(double *value);
    static void convertToQuartUs(double *value);
    static void convertToQuartUk(double *value);
    static void convertToCubicFt(double *value);
    static void convertToCubicYd(double *value);
    static void convertToUsGal(double *value);
    static void convertToUkGal(double *value);

    // weight
    static void convertToTonne(double *value);
    static void convertToSlug(double *value);
    static void convertToGram(double *value);
    static void convertToLbs(double *value);
    static void convertToUsTonne(double *value);
    static void convertToUkTonne(double *value);

    // volume rate
    static void convertToLitresPerMin(double *value);
    static void convertToCubicCmPerMin(double *value);
    static void convertToMlPerMin(double *value);
    static void convertToCubicMPerMin(double *value);
    static void convertToCubicInPerMin(double *value);
    static void convertToOzUsPerMin(double *value);
    static void convertToOzUkPerMin(double *value);
    static void convertToQuartUsPerMin(double *value);
    static void convertToQuartUkPerMin(double *value);
    static void convertToCubicFtPerMin(double *value);
    static void convertToCubicYdPerMin(double *value);
    static void convertToUsGalPerMin(double *value);
    static void convertToUkGalPerMin(double *value);

    static void convertToLitresPerSec(double *value);
    static void convertToCubicCmPerSec(double *value);
    static void convertToMlPerSec(double *value);
    static void convertToCubicMPerSec(double *value);
    static void convertToCubicInPerSec(double *value);
    static void convertToOzUsPerSec(double *value);
    static void convertToOzUkPerSec(double *value);
    static void convertToQuartUsPerSec(double *value);
    static void convertToQuartUkPerSec(double *value);
    static void convertToCubicFtPerSec(double *value);
    static void convertToCubicYdPerSec(double *value);
    static void convertToUsGalPerSec(double *value);
    static void convertToUkGalPerSec(double *value);

    // weight rate
    static void convertToKgPerMin(double *value);
    static void convertToTonnePerMin(double *value);
    static void convertToSlugPerMin(double *value);
    static void convertToGramPerMin(double *value);
    static void convertToLbsPerMin(double *value);
    static void convertToUsTonnePerMin(double *value);
    static void convertToUkTonnePerMin(double *value);

    static void convertToKgPerSec(double *value);
    static void convertToTonnePerSec(double *value);
    static void convertToSlugPerSec(double *value);
    static void convertToGramPerSec(double *value);
    static void convertToLbsPerSec(double *value);
    static void convertToUsTonnePerSec(double *value);
    static void convertToUkTonnePerSec(double *value);

private:
    UnitConverter() = default;
};


#endif   // UNITCONVERTER_H
