#ifndef _DATAIDENTIFIERS_H
#define _DATAIDENTIFIERS_H

#include <cstdint>

enum class DataIdentifiers : uint8_t
{
    // server identifier
    SIMCONNECT_SERVER,
    GAUGE_DESIGNER_SERVER,
    // pfd
    // airspeed
    AIRSPEED,
    MAX_SPEED,
    TRUE_AIRSPEED,
    REF_SPEED,
    AP_FLC,
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
    // aoa
    ANGLE_OF_ATTACK,
    // ap info
    AP_AVAILABLE,
    AP_LATERAL_ACTIVE,
    AP_LATERAL_ARMED,
    AP_STATUS,
    AP_YD_STATUS,
    AP_FD_STATUS,
    AP_VERTICAL_ACTIVE,
    AP_MODE_REFERENCE,
    AP_ARMED,
    AP_ARMED_REFERENCE,
    // attitude
    BANK,
    PITCH,
    SLIPSKID,
    FD_BANK,
    FD_PITCH,
    // bottombar
    ZULU_SECONDS,
    LOCAL_SECONDS,
    GROUND_SPEED,
    TOTAL_AIR_TEMP,
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
    CURRENT_LEG_TO,
    CURRENT_LEG_FROM,
    LEG_IS_DIRECT_TO,
    CURRENT_LEG_DISTANCE,
    CURRENT_LEG_BEARING,
    // radio info
    HAS_COM1,
    HAS_COM2,
    HAS_NAV1,
    HAS_NAV2,
    COM1_FREQ,
    COM2_FREQ,
    NAV1_FREQ,
    NAV2_FREQ,
    // wind
    WIND_DIRECTION,
    WIND_STRENGTH,
    WIND_TRUE_DIRECTION,
    // mfd
    COORDINATES,
    TRUE_HEADING,
    GPS_WP_DTK,
    GPS_WP_ETE,
    GPS_ETE,
    // flightplan
    CLEAR_FLIGHTPLAN,
    FLIGHTPLAN_LIST,
    // simconnect server
    QUIT,
    SIM_START_EVENT,
    SIM_STOP_EVENT,
    SIM_CONNECTION_FAILED,
    ERROR_STRING,
    // gauge designer
    REMOVE_AIRCRAFT_LIST,
    LOAD_AIRCRAFT_LIST,
    SAVE_AIRCRAFT,
    // engine
    ENGINE1_N1,
    ENGINE2_N1,
    ENGINE3_N1,
    ENGINE4_N1,
    ENGINE1_N2,
    ENGINE2_N2,
    ENGINE3_N2,
    ENGINE4_N2,
    ENGINE1_ITT,
    ENGINE2_ITT,
    ENGINE3_ITT,
    ENGINE4_ITT,
    ENGINE1_RPM,
    ENGINE2_RPM,
    ENGINE1_SECOND,
    ENGINE2_SECOND,
    ENGINE1_TRQ,
    ENGINE2_TRQ,
    ENGINE1_FUEL_QTY,
    ENGINE2_FUEL_QTY,
    ENGINE1_FUEL_FLOW,
    ENGINE2_FUEL_FLOW,
    ENGINE1_OIL_PRESS,
    ENGINE2_OIL_PRESS,
    ENGINE1_OIL_TEMP,
    ENGINE2_OIL_TEMP,
    ENGINE1_EGT,
    ENGINE2_EGT,
    // misc ed
    APU_RPM_PCT,
    FUEL_TEXT_DATA,
    SPOILERS_PCT,
    FLAPS_ANGLE,
    ELEV_TRIM_PCT,
    RUDD_TRIM_PCT,
    AIL_TRIM_PCT
};

// used for communication from client to server
enum class ClientIds : uint8_t
{
    // simconnect server
    QUIT,
    CHANGE_AIRCRAFT,
    START,
    // gauge designer
    LOAD_AIRCRAFT,
    AIRCRAFT_FILE_LIST
};


#endif   // DATAIDENTIFIERS_H
