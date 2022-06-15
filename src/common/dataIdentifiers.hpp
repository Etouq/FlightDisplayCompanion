#ifndef _DATAIDENTIFIERS_H
#define _DATAIDENTIFIERS_H

#include <cstdint>

enum class SimconnectIds : uint8_t
{
    // flightplan
    CLEAR_FLIGHTPLAN,
    FLIGHTPLAN_LIST,
    // simconnect server
    QUIT,
    SIM_START_EVENT,
    SIM_STOP_EVENT,
    SIM_STARTUP_FAILED,
    ERROR_MSG,
    // pfd
    // airspeed
    AIRSPEED,
    MAX_SPEED,
    TRUE_AIRSPEED,
    REF_SPEED,
    // altimeter
    ALTITUDE,
    RADAR_ALTITUDE,
    REF_ALTITUDE,
    PRESSURE,
    // vspeed
    VSPEED,
    REF_VSPEED,
    // vert dev
    VERT_DEV_MODE,
    VERT_DEV_VALUE,
    // attitude
    ATTITUDE,
    FD_ATTITUDE,
    // aoa
    ANGLE_OF_ATTACK,
    // bottombar
    ZULU_SECONDS,
    LOCAL_SECONDS,
    GROUND_SPEED,
    TOTAL_AIR_TEMP,
    OUTSIDE_AIR_TEMP,
    ISA_AIR_TEMP,
    // hsi
    ROTATION,
    HEADING,
    COURSE,
    COURSE_DEVIATION,
    DISPLAY_DEVIATION,
    TURN_RATE,
    NAV_SOURCE,
    CURRENT_TRACK,
    TO_FROM,
    // hsi brg
    NAV1_IDENT,
    NAV1_DME,
    NAV1_BEARING,
    NAV1_HAS_NAV,
    NAV1_HAS_SIGNAL,
    NAV1_HAS_DME,
    NAV2_IDENT,
    NAV2_DME,
    NAV2_BEARING,
    NAV2_HAS_NAV,
    NAV2_HAS_SIGNAL,
    NAV2_HAS_DME,
    GPS_DISTANCE,
    GPS_BEARING,
    ADF_HAS_SIGNAL,
    ADF_FREQ,
    ADF_RADIAL,
    // nav info
    GPS_IS_ACTIVE_FLIGHTPLAN,
    LEG_IS_DIRECT_TO,
    CURRENT_LEG_TO,
    CURRENT_LEG_FROM,
    // radio info
    COM1_AVAIL,
    COM2_AVAIL,
    NAV1_AVAIL,
    NAV2_AVAIL,
    COM1_FREQ,
    COM2_FREQ,
    NAV1_FREQ,
    NAV2_FREQ,
    COM1_STBY,
    COM2_STBY,
    NAV1_STBY,
    NAV2_STBY,
    XPDR_CODE,
    XPDR_STATE,
    // wind
    WIND_DIRECTION,
    WIND_STRENGTH,
    WIND_TRUE_DIRECTION,
    // ap info
    AP_AVAILABLE,
    AP_LATERAL_ACTIVE,
    AP_LATERAL_ARMED,
    AP_STATUS,
    AP_YD_STATUS,
    AP_FD_STATUS,
    AP_FLC,
    AP_VERTICAL_ACTIVE,
    AP_MODE_REFERENCE,
    AP_ARMED,
    AP_ARMED_REFERENCE,
    // mfd
    COORDINATES,
    TRUE_HEADING,
    GPS_WP_DTK,
    GPS_WP_ETE,
    GPS_ETE,
    FUEL_LEFT_QTY,
    FUEL_RIGHT_QTY,
    // engine (indexed)
    ENGINE_N1,
    ENGINE_N2,
    ENGINE_ITT,
    ENGINE_RPM,
    ENGINE_POWER,
    ENGINE_MANIFOLD_PRESSURE,
    ENGINE_TRQ,
    ENGINE_CHT,
    ENGINE_FUEL_FLOW,
    ENGINE_EGT,
    ENGINE_OIL_TEMP,
    ENGINE_OIL_PRESS,
    // misc engine display
    APU_N1,
    FUEL_TEXT_DATA,
    FLAPS_ANGLE,
    SPOILERS_PCT,
    ELEV_TRIM_PCT,
    RUDD_TRIM_PCT,
    AIL_TRIM_PCT,
    // aliases
    FUEL_TOTAL_QTY = FUEL_LEFT_QTY
};

enum class ClientToServerIds : uint8_t
{
    CLIENT_NETWORK_VERSION,
    QUIT,
    CHANGE_AIRCRAFT,
    START,
    SIM_COMMANDS
};

enum class SimCommandId : uint8_t
{
    SET_COM1_FREQ,
    SET_COM2_FREQ,
    SET_COM3_FREQ,
    SWAP_COM1,
    SWAP_COM2,
    SWAP_COM3,
    SET_NAV1_FREQ,
    SET_NAV2_FREQ,
    SWAP_NAV1,
    SWAP_NAV2,
    SET_XPDR_STATE,
    SET_XPDR_CODE
};


#endif  // DATAIDENTIFIERS_H
