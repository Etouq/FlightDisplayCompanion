#include "unitconverter.h"


void UnitConverter::setConversionFunction(void (*&convertValue)(double *), Units unit)
{
    switch (unit)
    {
        case Units::NONE:
        case Units::PERCENT:
        case Units::RPM:
        case Units::CELSIUS:
        case Units::KILOPASCAL:
        case Units::NEWTONMETER:
        case Units::LITRES:
        case Units::CUBICDM:
        case Units::KG:
        case Units::LITRES_PER_HOUR:
        case Units::CUBICDM_PER_HOUR:
        case Units::KG_PER_HOUR:
            convertValue = &doNothing;
            break;
        // temperature
        case Units::FAHRENHEIT:
            convertValue = &convertToFahrenheit;
            break;
        case Units::KELVIN:
            convertValue = &convertToKelvin;
            break;
        case Units::RANKINE:
            convertValue = &convertToRankine;
            break;
        // pressure
        case Units::INHG:
            convertValue = &convertToInHg;
            break;
        case Units::BAR:
            convertValue = &convertToBar;
            break;
        case Units::PSI:
            convertValue = &convertToPsi;
            break;
        case Units::PASCAL_UNIT:
            convertValue = &convertToPascal;
            break;
        case Units::MMHG:
            convertValue = &convertToMmHg;
            break;
        case Units::CMHG:
            convertValue = &convertToCmHg;
            break;
        case Units::ATM:
            convertValue = &convertToAtm;
            break;
        case Units::PSF:
            convertValue = &convertToPsf;
            break;
        case Units::MBAR:
            convertValue = &convertToMbar;
            break;
        case Units::HECTOPASCAL:
            convertValue = &convertToHectoPascal;
            break;
        case Units::MMH2O:
            convertValue = &convertToMmH2O;
            break;
        case Units::CMH2O:
            convertValue = &convertToCmH2O;
            break;
        case Units::INH2O:
            convertValue = &convertToInH2O;
            break;
        // torque
        case Units::FOOTPOUND:
            convertValue = &convertToFootPound;
            break;
        case Units::INCHPOUND:
            convertValue = &convertToInchPound;
            break;
        // volume
        case Units::CUBICCM:
        case Units::CUBICCM_PER_HOUR:
            convertValue = &convertToCubicCm;
            break;
        case Units::ML:
        case Units::ML_PER_HOUR:
            convertValue = &convertToMl;
            break;
        case Units::CUBICM:
        case Units::CUBICM_PER_HOUR:
            convertValue = &convertToCubicM;
            break;
        case Units::CUBICIN:
        case Units::CUBICIN_PER_HOUR:
            convertValue = &convertToCubicIn;
            break;
        case Units::OZUS:
        case Units::OZUS_PER_HOUR:
            convertValue = &convertToOzUs;
            break;
        case Units::OZUK:
        case Units::OZUK_PER_HOUR:
            convertValue = &convertToOzUk;
            break;
        case Units::QUARTUS:
        case Units::QUARTUS_PER_HOUR:
            convertValue = &convertToQuartUs;
            break;
        case Units::QUARTUK:
        case Units::QUARTUK_PER_HOUR:
            convertValue = &convertToQuartUk;
            break;
        case Units::CUBICFT:
        case Units::CUBICFT_PER_HOUR:
            convertValue = &convertToCubicFt;
            break;
        case Units::CUBICYD:
        case Units::CUBICYD_PER_HOUR:
            convertValue = &convertToCubicYd;
            break;
        case Units::USGAL:
        case Units::USGAL_PER_HOUR:
            convertValue = &convertToUsGal;
            break;
        case Units::UKGAL:
        case Units::UKGAL_PER_HOUR:
            convertValue = &convertToUkGal;
            break;
        // weight
        case Units::TONNE:
        case Units::TONNE_PER_HOUR:
            convertValue = &convertToTonne;
            break;
        case Units::SLUG:
        case Units::SLUG_PER_HOUR:
            convertValue = &convertToSlug;
            break;
        case Units::GRAM:
        case Units::GRAM_PER_HOUR:
            convertValue = &convertToGram;
            break;
        case Units::LBS:
        case Units::LBS_PER_HOUR:
            convertValue = &convertToLbs;
            break;
        case Units::USTONNE:
        case Units::USTONNE_PER_HOUR:
            convertValue = &convertToUsTonne;
            break;
        case Units::UKTONNE:
        case Units::UKTONNE_PER_HOUR:
            convertValue = &convertToUkTonne;
            break;
        // volume rate
        case Units::LITRES_PER_MINUTE:
        case Units::CUBICDM_PER_MINUTE:
            convertValue = &convertToLitresPerMin;
            break;
        case Units::CUBICCM_PER_MINUTE:
            convertValue = &convertToCubicCmPerMin;
            break;
        case Units::ML_PER_MINUTE:
            convertValue = &convertToMlPerMin;
            break;
        case Units::CUBICM_PER_MINUTE:
            convertValue = &convertToCubicMPerMin;
            break;
        case Units::CUBICIN_PER_MINUTE:
            convertValue = &convertToCubicInPerMin;
            break;
        case Units::OZUS_PER_MINUTE:
            convertValue = &convertToOzUsPerMin;
            break;
        case Units::OZUK_PER_MINUTE:
            convertValue = &convertToOzUkPerMin;
            break;
        case Units::QUARTUS_PER_MINUTE:
            convertValue = &convertToQuartUsPerMin;
            break;
        case Units::QUARTUK_PER_MINUTE:
            convertValue = &convertToQuartUkPerMin;
            break;
        case Units::CUBICFT_PER_MINUTE:
            convertValue = &convertToCubicFtPerMin;
            break;
        case Units::CUBICYD_PER_MINUTE:
            convertValue = &convertToCubicYdPerMin;
            break;
        case Units::USGAL_PER_MINUTE:
            convertValue = &convertToUsGalPerMin;
            break;
        case Units::UKGAL_PER_MINUTE:
            convertValue = &convertToUkGalPerMin;
            break;
        case Units::LITRES_PER_SECOND:
        case Units::CUBICDM_PER_SECOND:
            convertValue = &convertToLitresPerSec;
            break;
        case Units::CUBICCM_PER_SECOND:
            convertValue = &convertToCubicCmPerSec;
            break;
        case Units::ML_PER_SECOND:
            convertValue = &convertToMlPerSec;
            break;
        case Units::CUBICM_PER_SECOND:
            convertValue = &convertToCubicMPerSec;
            break;
        case Units::CUBICIN_PER_SECOND:
            convertValue = &convertToCubicInPerSec;
            break;
        case Units::OZUS_PER_SECOND:
            convertValue = &convertToOzUsPerSec;
            break;
        case Units::OZUK_PER_SECOND:
            convertValue = &convertToOzUkPerSec;
            break;
        case Units::QUARTUS_PER_SECOND:
            convertValue = &convertToQuartUsPerSec;
            break;
        case Units::QUARTUK_PER_SECOND:
            convertValue = &convertToQuartUkPerSec;
            break;
        case Units::CUBICFT_PER_SECOND:
            convertValue = &convertToCubicFtPerSec;
            break;
        case Units::CUBICYD_PER_SECOND:
            convertValue = &convertToCubicYdPerSec;
            break;
        case Units::USGAL_PER_SECOND:
            convertValue = &convertToUsGalPerSec;
            break;
        case Units::UKGAL_PER_SECOND:
            convertValue = &convertToUkGalPerSec;
            break;
        // weight rate
        case Units::KG_PER_MINUTE:
            convertValue = &convertToKgPerMin;
            break;
        case Units::TONNE_PER_MINUTE:
            convertValue = &convertToTonnePerMin;
            break;
        case Units::SLUG_PER_MINUTE:
            convertValue = &convertToSlugPerMin;
            break;
        case Units::GRAM_PER_MINUTE:
            convertValue = &convertToGramPerMin;
            break;
        case Units::LBS_PER_MINUTE:
            convertValue = &convertToLbsPerMin;
            break;
        case Units::USTONNE_PER_MINUTE:
            convertValue = &convertToUsTonnePerMin;
            break;
        case Units::UKTONNE_PER_MINUTE:
            convertValue = &convertToUkTonnePerMin;
            break;
        case Units::KG_PER_SECOND:
            convertValue = &convertToKgPerSec;
            break;
        case Units::TONNE_PER_SECOND:
            convertValue = &convertToTonnePerSec;
            break;
        case Units::SLUG_PER_SECOND:
            convertValue = &convertToSlugPerSec;
            break;
        case Units::GRAM_PER_SECOND:
            convertValue = &convertToGramPerSec;
            break;
        case Units::LBS_PER_SECOND:
            convertValue = &convertToLbsPerSec;
            break;
        case Units::USTONNE_PER_SECOND:
            convertValue = &convertToUsTonnePerSec;
            break;
        case Units::UKTONNE_PER_SECOND:
            convertValue = &convertToUkTonnePerSec;
            break;
    }
}

void UnitConverter::doNothing(double *value)
{
    *value = *value;
    return;
}
