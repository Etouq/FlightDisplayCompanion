#ifndef __DATAIDENTIFIERS_HPP__
#define __DATAIDENTIFIERS_HPP__

#include <cstdint>

enum class DataGroupIdentifier : uint8_t
{
    PFD_DATA = 0,
    MFD_DATA = 1,
    TSC_DATA = 2,
    SERVER_DATA = 3
};

enum class PfdIdentifier : uint8_t
{
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
    AP_ARMED_REFERENCE
};

enum class MfdIdentifier : uint8_t
{
    // map
    COORDINATES,
    TRUE_HEADING,
    // flightplan
    CLEAR_FLIGHTPLAN,
    FLIGHTPLAN_LIST,
    GPS_WP_DTK,
    GPS_WP_ETE,
    GPS_DEST_ETE,
    // fuel
    FUEL_LEFT_QTY,
    FUEL_RIGHT_QTY,
    // engines (indexed)
    ENGINE_FIRST_GAUGE,
    ENGINE_SECOND_GAUGE,
    ENGINE_THIRD_GAUGE,
    ENGINE_FOURTH_GAUGE,
    ENGINE_FUEL_FLOW,
    ENGINE_OIL_TEMP,
    ENGINE_SECONDARY_TEMP,
    ENGINE_OIL_PRESS,
    // misc engine display
    APU_N1,
    FUEL_TEXT_DATA,
    FLAPS_ANGLE,
    SPOILERS_PCT,
    ELEV_TRIM_POSITION,
    RUDD_TRIM_POSITION,
    AIL_TRIM_POSITION
};

enum class TscIdentifier : uint8_t
{
    // radio info
    COM1_AVAIL,
    COM1_FREQ,
    COM1_STBY_FREQ,
    COM2_AVAIL,
    COM2_FREQ,
    COM2_STBY_FREQ,
    COM3_AVAIL,
    COM3_FREQ,
    COM3_STBY_FREQ,
    NAV1_AVAIL,
    NAV1_FREQ,
    NAV1_STBY_FREQ,
    NAV2_AVAIL,
    NAV2_FREQ,
    NAV2_STBY_FREQ,
    XPDR_AVAIL,
    XPDR_CODE,
    XPDR_STATE
};

enum class ServerMessageIdentifier : uint8_t
{
    QUIT,
    LOAD_AIRCRAFT,
    SIM_START_EVENT,
    SIM_STOP_EVENT,
    SIM_STARTUP_FAILED,
    ERROR_MSG
};

enum class ClientToServerIds : uint8_t
{
    CLIENT_NETWORK_VERSION,
    QUIT,
    AIRCRAFT_LOADED,
    START,
    COMMAND_STRING
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
    SET_XPDR_CODE,
    NEXT_CDI_MODE
};


#endif  // __DATAIDENTIFIERS_HPP__
