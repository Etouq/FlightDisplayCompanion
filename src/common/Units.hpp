#ifndef __UNITS_HPP__
#define __UNITS_HPP__

#include <cstdint>

enum class Units : uint8_t
{
    // misc
    NONE,
    PERCENT,
    RPM,
    // temperature
    CELSIUS,  // default
    FAHRENHEIT,
    KELVIN,
    RANKINE,
    // pressure
    KILOPASCAL,  // default
    INHG,
    BAR,
    PSI,
    PASCAL_UNIT,  // to get around windows pascal preprocesser macro
    MMHG,
    CMHG,
    ATM,
    PSF,
    MBAR,
    HECTOPASCAL,
    MMH2O,
    CMH2O,
    INH2O,
    // torque
    NEWTONMETER,  // default
    FOOTPOUND,
    INCHPOUND,
    // volume
    LITRES,  // default
    CUBICCM,
    ML,
    CUBICM,
    CUBICIN,
    CUBICDM,
    OZUS,
    OZUK,
    QUARTUS,
    QUARTUK,
    CUBICFT,
    CUBICYD,
    USGAL,
    UKGAL,
    // weight
    KG,  // default
    TONNE,
    SLUG,
    GRAM,
    LBS,
    USTONNE,
    UKTONNE,
    // volume rate
    LITRES_PER_HOUR,  // default
    CUBICCM_PER_HOUR,
    ML_PER_HOUR,
    CUBICM_PER_HOUR,
    CUBICIN_PER_HOUR,
    CUBICDM_PER_HOUR,
    OZUS_PER_HOUR,
    OZUK_PER_HOUR,
    QUARTUS_PER_HOUR,
    QUARTUK_PER_HOUR,
    CUBICFT_PER_HOUR,
    CUBICYD_PER_HOUR,
    USGAL_PER_HOUR,
    UKGAL_PER_HOUR,
    LITRES_PER_MINUTE,
    CUBICCM_PER_MINUTE,
    ML_PER_MINUTE,
    CUBICM_PER_MINUTE,
    CUBICIN_PER_MINUTE,
    CUBICDM_PER_MINUTE,
    OZUS_PER_MINUTE,
    OZUK_PER_MINUTE,
    QUARTUS_PER_MINUTE,
    QUARTUK_PER_MINUTE,
    CUBICFT_PER_MINUTE,
    CUBICYD_PER_MINUTE,
    USGAL_PER_MINUTE,
    UKGAL_PER_MINUTE,
    LITRES_PER_SECOND,
    CUBICCM_PER_SECOND,
    ML_PER_SECOND,
    CUBICM_PER_SECOND,
    CUBICIN_PER_SECOND,
    CUBICDM_PER_SECOND,
    OZUS_PER_SECOND,
    OZUK_PER_SECOND,
    QUARTUS_PER_SECOND,
    QUARTUK_PER_SECOND,
    CUBICFT_PER_SECOND,
    CUBICYD_PER_SECOND,
    USGAL_PER_SECOND,
    UKGAL_PER_SECOND,
    // weight rate
    KG_PER_HOUR,  // default
    TONNE_PER_HOUR,
    SLUG_PER_HOUR,
    GRAM_PER_HOUR,
    LBS_PER_HOUR,
    USTONNE_PER_HOUR,
    UKTONNE_PER_HOUR,
    KG_PER_MINUTE,
    TONNE_PER_MINUTE,
    SLUG_PER_MINUTE,
    GRAM_PER_MINUTE,
    LBS_PER_MINUTE,
    USTONNE_PER_MINUTE,
    UKTONNE_PER_MINUTE,
    KG_PER_SECOND,
    TONNE_PER_SECOND,
    SLUG_PER_SECOND,
    GRAM_PER_SECOND,
    LBS_PER_SECOND,
    USTONNE_PER_SECOND,
    UKTONNE_PER_SECOND,
    // power
    HP_IMPERIAL, // default, also called mechanical hp
    HP_METRIC,
    WATT,
    KILOWATT,
    FT_LBF_HOUR,
    FT_LBF_MIN,
    FT_LBF_SEC,
};

#endif  //__UNITS_HPP__
