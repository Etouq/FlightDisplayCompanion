#ifndef __UNIT_CONVERTER_HPP__
#define __UNIT_CONVERTER_HPP__

#include "common/Units.hpp"

namespace UnitConverter
{

inline double getMultiplier(Units unit)
{
    double multiplier = 1.0;
    switch (unit)
    {
        case Units::NONE:
        case Units::PERCENT:
        case Units::RPM:
        case Units::CELSIUS:
        case Units::KELVIN:
        case Units::KILOPASCAL:
        case Units::NEWTONMETER:
        case Units::FT_LBF_SEC:
            return 1.0;
        case Units::LITRES:
        case Units::LITRES_PER_SECOND:
        case Units::LITRES_PER_MINUTE:
        case Units::LITRES_PER_HOUR:
        case Units::CUBICDM:
        case Units::CUBICDM_PER_SECOND:
        case Units::CUBICDM_PER_MINUTE:
        case Units::CUBICDM_PER_HOUR:
        case Units::KG:
        case Units::KG_PER_SECOND:
        case Units::KG_PER_MINUTE:
        case Units::KG_PER_HOUR:
            break;
        // temperature
        case Units::FAHRENHEIT:
        case Units::RANKINE:
            return 1.8;
        // pressure
        case Units::INHG:
            return 1.0 / 3.386'39;
        case Units::BAR:
            return 0.01;
        case Units::PSI:
            return 1.0 / 6.894'757;
        case Units::PASCAL_UNIT:
            return 1000.0;
        case Units::MMHG:
            return 1.0 / 0.133'322'4;
        case Units::CMHG:
            return 1.0 / 0.333'224;
        case Units::ATM:
            return 1.0 / 101.325;
        case Units::PSF:
            return 1.0 / 20.885'434'233'15;
        case Units::MBAR:
        case Units::HECTOPASCAL:
            return 10.0;
        case Units::MMH2O:
            return 1.0 / 0.009'806'65;
        case Units::CMH2O:
            return 1.0 / 0.098'066'5;
        case Units::INH2O:
            return 1.0 / 0.248'84;
        // torque
        case Units::FOOTPOUND:
            return 1.0 / 1.355'818;
        case Units::INCHPOUND:
            return 8.850'745'767'6;
        // power
        case Units::HP_IMPERIAL:
            return 1.0 / 550.0;
        case Units::HP_METRIC:
            return 1.0 / 542.476'038'840'742;
        case Units::WATT:
            return 1.0 / 1.355'817'948'331'400'4;
        case Units::KILOWATT:
            return 1000.0 / 1.355'817'948'331'400'4;
        case Units::FT_LBF_HOUR:
            return 3600.0;
        case Units::FT_LBF_MIN:
            return 60.0;
        // volume
        case Units::CUBICCM:
        case Units::CUBICCM_PER_HOUR:
        case Units::CUBICCM_PER_MINUTE:
        case Units::CUBICCM_PER_SECOND:
        case Units::ML:
        case Units::ML_PER_HOUR:
        case Units::ML_PER_MINUTE:
        case Units::ML_PER_SECOND:
            multiplier = 1000.0;
            break;
        case Units::CUBICM:
        case Units::CUBICM_PER_HOUR:
        case Units::CUBICM_PER_MINUTE:
        case Units::CUBICM_PER_SECOND:
            multiplier = 0.001;
            break;
        case Units::CUBICIN:
        case Units::CUBICIN_PER_HOUR:
        case Units::CUBICIN_PER_MINUTE:
        case Units::CUBICIN_PER_SECOND:
            multiplier = 1.0 / 0.016'387'064;
            break;
        case Units::OZUS:
        case Units::OZUS_PER_HOUR:
        case Units::OZUS_PER_MINUTE:
        case Units::OZUS_PER_SECOND:
            multiplier = 1.0 / 0.029'573'529'562'5;
            break;
        case Units::OZUK:
        case Units::OZUK_PER_HOUR:
        case Units::OZUK_PER_MINUTE:
        case Units::OZUK_PER_SECOND:
            multiplier = 1.0 / 0.028'413'062'5;
            break;
        case Units::QUARTUS:
        case Units::QUARTUS_PER_HOUR:
        case Units::QUARTUS_PER_MINUTE:
        case Units::QUARTUS_PER_SECOND:
            multiplier = 1.0 / 0.946'352'946;
            break;
        case Units::QUARTUK:
        case Units::QUARTUK_PER_HOUR:
        case Units::QUARTUK_PER_MINUTE:
        case Units::QUARTUK_PER_SECOND:
            multiplier = 1.0 / 1.136'522'5;
            break;
        case Units::CUBICFT:
        case Units::CUBICFT_PER_HOUR:
        case Units::CUBICFT_PER_MINUTE:
        case Units::CUBICFT_PER_SECOND:
            multiplier = 1.0 / 28.316'846'592;
            break;
        case Units::CUBICYD:
        case Units::CUBICYD_PER_HOUR:
        case Units::CUBICYD_PER_MINUTE:
        case Units::CUBICYD_PER_SECOND:
            multiplier = 1.0 / 764.554'857'984;
            break;
        case Units::USGAL:
        case Units::USGAL_PER_HOUR:
        case Units::USGAL_PER_MINUTE:
        case Units::USGAL_PER_SECOND:
            multiplier = 1.0 / 3.785'411'784;
            break;
        case Units::UKGAL:
        case Units::UKGAL_PER_HOUR:
        case Units::UKGAL_PER_MINUTE:
        case Units::UKGAL_PER_SECOND:
            multiplier = 1.0 / 4.546'09;
            break;
        // weight
        case Units::TONNE:
        case Units::TONNE_PER_HOUR:
        case Units::TONNE_PER_MINUTE:
        case Units::TONNE_PER_SECOND:
            multiplier = 0.001;
            break;
        case Units::SLUG:
        case Units::SLUG_PER_HOUR:
        case Units::SLUG_PER_MINUTE:
        case Units::SLUG_PER_SECOND:
            multiplier = 1.0 / 14.593'903;
            break;
        case Units::GRAM:
        case Units::GRAM_PER_HOUR:
        case Units::GRAM_PER_MINUTE:
        case Units::GRAM_PER_SECOND:
            multiplier = 1000.0;
            break;
        case Units::LBS:
        case Units::LBS_PER_HOUR:
        case Units::LBS_PER_MINUTE:
        case Units::LBS_PER_SECOND:
            multiplier = 1.0 / 0.453'592'37;
            break;
        case Units::USTONNE:  // also short ton
        case Units::USTONNE_PER_HOUR:
        case Units::USTONNE_PER_MINUTE:
        case Units::USTONNE_PER_SECOND:
            multiplier = 1.0 / 907.184'74;
            break;
        case Units::UKTONNE:  // also long ton
        case Units::UKTONNE_PER_HOUR:
        case Units::UKTONNE_PER_MINUTE:
        case Units::UKTONNE_PER_SECOND:
            multiplier = 1.0 / 1016.046'908'8;
            break;
    }

    // convert time units
    switch (unit)
    {
        case Units::LITRES:
        case Units::CUBICDM:
        case Units::KG:
        case Units::CUBICCM:
        case Units::ML:
        case Units::CUBICM:
        case Units::CUBICIN:
        case Units::OZUS:
        case Units::OZUK:
        case Units::QUARTUS:
        case Units::QUARTUK:
        case Units::CUBICFT:
        case Units::CUBICYD:
        case Units::USGAL:
        case Units::UKGAL:
        case Units::TONNE:
        case Units::SLUG:
        case Units::GRAM:
        case Units::LBS:
        case Units::USTONNE:
        case Units::UKTONNE:
        case Units::LITRES_PER_HOUR:
        case Units::CUBICDM_PER_HOUR:
        case Units::KG_PER_HOUR:
        case Units::CUBICCM_PER_HOUR:
        case Units::ML_PER_HOUR:
        case Units::CUBICM_PER_HOUR:
        case Units::CUBICIN_PER_HOUR:
        case Units::OZUS_PER_HOUR:
        case Units::OZUK_PER_HOUR:
        case Units::QUARTUS_PER_HOUR:
        case Units::QUARTUK_PER_HOUR:
        case Units::CUBICFT_PER_HOUR:
        case Units::CUBICYD_PER_HOUR:
        case Units::USGAL_PER_HOUR:
        case Units::UKGAL_PER_HOUR:
        case Units::TONNE_PER_HOUR:
        case Units::SLUG_PER_HOUR:
        case Units::GRAM_PER_HOUR:
        case Units::LBS_PER_HOUR:
        case Units::USTONNE_PER_HOUR:
        case Units::UKTONNE_PER_HOUR:
            return multiplier;
        case Units::LITRES_PER_MINUTE:
        case Units::CUBICDM_PER_MINUTE:
        case Units::KG_PER_MINUTE:
        case Units::CUBICCM_PER_MINUTE:
        case Units::ML_PER_MINUTE:
        case Units::CUBICM_PER_MINUTE:
        case Units::CUBICIN_PER_MINUTE:
        case Units::OZUS_PER_MINUTE:
        case Units::OZUK_PER_MINUTE:
        case Units::QUARTUS_PER_MINUTE:
        case Units::QUARTUK_PER_MINUTE:
        case Units::CUBICFT_PER_MINUTE:
        case Units::CUBICYD_PER_MINUTE:
        case Units::USGAL_PER_MINUTE:
        case Units::UKGAL_PER_MINUTE:
        case Units::TONNE_PER_MINUTE:
        case Units::SLUG_PER_MINUTE:
        case Units::GRAM_PER_MINUTE:
        case Units::LBS_PER_MINUTE:
        case Units::USTONNE_PER_MINUTE:
        case Units::UKTONNE_PER_MINUTE:
            return multiplier * 60.0;
        case Units::LITRES_PER_SECOND:
        case Units::CUBICDM_PER_SECOND:
        case Units::KG_PER_SECOND:
        case Units::CUBICCM_PER_SECOND:
        case Units::ML_PER_SECOND:
        case Units::CUBICM_PER_SECOND:
        case Units::CUBICIN_PER_SECOND:
        case Units::OZUS_PER_SECOND:
        case Units::OZUK_PER_SECOND:
        case Units::QUARTUS_PER_SECOND:
        case Units::QUARTUK_PER_SECOND:
        case Units::CUBICFT_PER_SECOND:
        case Units::CUBICYD_PER_SECOND:
        case Units::USGAL_PER_SECOND:
        case Units::UKGAL_PER_SECOND:
        case Units::TONNE_PER_SECOND:
        case Units::SLUG_PER_SECOND:
        case Units::GRAM_PER_SECOND:
        case Units::LBS_PER_SECOND:
        case Units::USTONNE_PER_SECOND:
        case Units::UKTONNE_PER_SECOND:
            return multiplier * 3600.0;
        default:
            return -1.0;
    }
}

}


#endif  // __UNIT_CONVERTER_HPP__