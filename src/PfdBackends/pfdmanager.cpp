#include "pfdmanager.h"

#include <QQmlContext>

#include "aircraftManager/definitions/aircraftDefinition.h"


PfdManager::PfdManager(QObject *parent) : QObject(parent)
{
}

void PfdManager::changeAircraft(const AircraftDefinition &aircraft)
{
    iasInterface.updateColors(aircraft.lowLimit,
                              aircraft.flapsBegin,
                              aircraft.flapsEnd,
                              aircraft.greenBegin,
                              aircraft.greenEnd,
                              aircraft.yellowBegin,
                              aircraft.yellowEnd,
                              aircraft.redBegin,
                              aircraft.redEnd,
                              aircraft.highLimit,
                              aircraft.noColors,
                              aircraft.dynamicBarberpole);

    emit pfdLoaded();
}

void PfdManager::connectPfdSlots(NetworkClient *netClient)
{
    connectAirspeedSlots(netClient);
    connectAltimeterSlots(netClient);
    connectAoaSlots(netClient);
    connectApSlots(netClient);
    connectAttitudeSlots(netClient);
    connectBottombarSlots(netClient);
    connectHsiSlots(netClient);
    connectHsiBrgSlots(netClient);
    connectNavSlots(netClient);
    connectRadioInfoSlots(netClient);
    connectWindDataSlots(netClient);
}

void PfdManager::addPfdToContext(QQmlContext *context)
{
    context->setContextProperty("iasInterface", &iasInterface);
    context->setContextProperty("altInterface", &altInterface);
    context->setContextProperty("aoaInterface", &aoaInterface);
    context->setContextProperty("apInterface", &apInterface);
    context->setContextProperty("attInterface", &attInterface);
    context->setContextProperty("bottomInterface", &bottomInterface);
    context->setContextProperty("hsiInterface", &hsiInterface);
    context->setContextProperty("hsiBrgInterface", &hsiBrgInterface);
    context->setContextProperty("navInterface", &navInterface);
    context->setContextProperty("radioInterface", &radioInterface);
    context->setContextProperty("windInterface", &windInterface);
}

AirspeedIndicatorBackend *PfdManager::getIasInterface()
{
    return &iasInterface;
}

AltimeterBackend *PfdManager::getAltInterface()
{
    return &altInterface;
}

AngleOfAttackIndicatorBackend *PfdManager::getAoaInterface()
{
    return &aoaInterface;
}

ApInfoBackend *PfdManager::getApInterface()
{
    return &apInterface;
}

AttitudeIndicatorBackend *PfdManager::getAttInterface()
{
    return &attInterface;
}

BottombarBackend *PfdManager::getBottomInterface()
{
    return &bottomInterface;
}

HSIndicatorBackend *PfdManager::getHsiInterface()
{
    return &hsiInterface;
}

HSIndicatorBearingsBackend *PfdManager::getHsiBrgInterface()
{
    return &hsiBrgInterface;
}

navInfoBackend *PfdManager::getNavInterface()
{
    return &navInterface;
}

RadioInfoBackend *PfdManager::getRadioInterface()
{
    return &radioInterface;
}

WindDataBackend *PfdManager::getWindInterface()
{
    return &windInterface;
}

void PfdManager::connectAirspeedSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::airspeedChanged, &iasInterface, &AirspeedIndicatorBackend::updateAirspeed);
    connect(netClient, &NetworkClient::max_speedChanged, &iasInterface, &AirspeedIndicatorBackend::updateDynamicMaxSpeed);
    connect(netClient, &NetworkClient::true_airspeedChanged, &iasInterface, &AirspeedIndicatorBackend::updateTrueAirspeed);
    connect(netClient, &NetworkClient::ref_speedChanged, &iasInterface, &AirspeedIndicatorBackend::updateRefSpeed);
}

void PfdManager::connectAltimeterSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::altitudeChanged, &altInterface, &AltimeterBackend::updateAltitude);
    connect(netClient, &NetworkClient::radar_altitudeChanged, &altInterface, &AltimeterBackend::updateRadarAltitude);
    connect(netClient, &NetworkClient::ref_altitudeChanged, &altInterface, &AltimeterBackend::updateReferenceAltitude);

    connect(netClient, &NetworkClient::vspeedChanged, &altInterface, &AltimeterBackend::updateVspeed);
    connect(netClient, &NetworkClient::ref_vspeedChanged, &altInterface, &AltimeterBackend::updateReferenceVspeed);

    connect(netClient, &NetworkClient::pressureChanged, &altInterface, &AltimeterBackend::updatePressure);

    connect(netClient, &NetworkClient::vert_dev_modeChanged, &altInterface, &AltimeterBackend::updateVerticalDeviationMode);
    connect(netClient, &NetworkClient::vert_dev_valueChanged, &altInterface, &AltimeterBackend::updateVerticalDeviationValue);
}

void PfdManager::connectAoaSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::angle_of_attackChanged, &aoaInterface, &AngleOfAttackIndicatorBackend::updateAoa);
}

void PfdManager::connectApSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::ap_availableChanged, &apInterface, &ApInfoBackend::updateHas_ap);
    connect(netClient, &NetworkClient::ap_lateral_activeChanged, &apInterface, &ApInfoBackend::updateAp_lateralActive);
    connect(netClient, &NetworkClient::ap_lateral_armedChanged, &apInterface, &ApInfoBackend::updateAp_lateralArmed);
    connect(netClient, &NetworkClient::ap_statusChanged, &apInterface, &ApInfoBackend::updateAp_status);
    connect(netClient, &NetworkClient::ap_yd_statusChanged, &apInterface, &ApInfoBackend::updateAp_ydStatus);
    connect(netClient, &NetworkClient::ap_fd_statusChanged, &apInterface, &ApInfoBackend::updateAp_fdActive);
    connect(netClient, &NetworkClient::ap_vertical_activeChanged, &apInterface, &ApInfoBackend::updateAp_verticalActive);
    connect(netClient, &NetworkClient::ap_mode_referenceChanged, &apInterface, &ApInfoBackend::updateAp_modeReference);
    connect(netClient, &NetworkClient::ap_armedChanged, &apInterface, &ApInfoBackend::updateAp_armed);
    connect(netClient, &NetworkClient::ap_armed_referenceChanged, &apInterface, &ApInfoBackend::updateAp_armedReference);
}

void PfdManager::connectAttitudeSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::bankChanged, &attInterface, &AttitudeIndicatorBackend::updateBank);
    connect(netClient, &NetworkClient::pitchChanged, &attInterface, &AttitudeIndicatorBackend::updatePitch);
    connect(netClient, &NetworkClient::slipskidChanged, &attInterface, &AttitudeIndicatorBackend::updateSlipSkid);

    connect(netClient, &NetworkClient::ap_fd_statusChanged, &attInterface, &AttitudeIndicatorBackend::updateFdActive);
    connect(netClient, &NetworkClient::fd_bankChanged, &attInterface, &AttitudeIndicatorBackend::updateFdBank);
    connect(netClient, &NetworkClient::fd_pitchChanged, &attInterface, &AttitudeIndicatorBackend::updateFdPitch);
}

void PfdManager::connectBottombarSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::zulu_secondsChanged, &bottomInterface, &BottombarBackend::updateZuluTime);
    connect(netClient, &NetworkClient::local_secondsChanged, &bottomInterface, &BottombarBackend::updateLocalTime);
    connect(netClient, &NetworkClient::ground_speedChanged, &bottomInterface, &BottombarBackend::updateGroundSpeed);
    connect(netClient, &NetworkClient::total_air_tempChanged, &bottomInterface, &BottombarBackend::updateTotalAirTemp);
}

void PfdManager::connectHsiSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::rotationChanged, &hsiInterface, &HSIndicatorBackend::updateRotation);
    connect(netClient, &NetworkClient::headingChanged, &hsiInterface, &HSIndicatorBackend::updateHeading);
    connect(netClient, &NetworkClient::courseChanged, &hsiInterface, &HSIndicatorBackend::updateCourse);

    connect(netClient, &NetworkClient::course_deviationChanged, &hsiInterface, &HSIndicatorBackend::updateCourseDeviation);

    connect(netClient, &NetworkClient::display_deviationChanged, &hsiInterface, &HSIndicatorBackend::updateDisplayDeviation);

    connect(netClient, &NetworkClient::turn_rateChanged, &hsiInterface, &HSIndicatorBackend::updateTurnRate);

    connect(netClient, &NetworkClient::nav_sourceChanged, &hsiInterface, &HSIndicatorBackend::updateNavSource);

    connect(netClient, &NetworkClient::current_trackChanged, &hsiInterface, &HSIndicatorBackend::updateCurrentTrack);

    connect(netClient, &NetworkClient::to_fromChanged, &hsiInterface, &HSIndicatorBackend::updateToFrom);
}

void PfdManager::connectHsiBrgSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::nav1_identChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav1Ident);
    connect(netClient, &NetworkClient::nav1_dmeChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav1Dme);
    connect(netClient, &NetworkClient::nav1_bearingChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav1Bearing);
    connect(netClient, &NetworkClient::nav1_has_navChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav1HasNav);
    connect(netClient, &NetworkClient::nav1_has_signalChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav1HasSignal);
    connect(netClient, &NetworkClient::nav1_has_dmeChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav1HasDme);

    connect(netClient, &NetworkClient::nav2_identChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav2Ident);
    connect(netClient, &NetworkClient::nav2_dmeChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav2Dme);
    connect(netClient, &NetworkClient::nav2_bearingChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav2Bearing);
    connect(netClient, &NetworkClient::nav2_has_navChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav2HasNav);
    connect(netClient, &NetworkClient::nav2_has_signalChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav2HasSignal);
    connect(netClient, &NetworkClient::nav2_has_dmeChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav2HasDme);

    connect(netClient, &NetworkClient::current_leg_toChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateGpsIdent);
    connect(netClient, &NetworkClient::gps_distanceChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateGpsDistance);
    connect(netClient, &NetworkClient::gps_bearingChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateGpsBearing);

    connect(netClient, &NetworkClient::adf_has_signalChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateAdfHasSignal);
    connect(netClient, &NetworkClient::adf_freqChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateAdfFreq);
    connect(netClient, &NetworkClient::adf_radialChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateAdfRadial);

    connect(netClient, &NetworkClient::nav1_freqChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav1Freq);
    connect(netClient, &NetworkClient::nav2_freqChanged, &hsiBrgInterface, &HSIndicatorBearingsBackend::updateNav2Freq);
}

void PfdManager::connectNavSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::gps_is_active_flightplanChanged, &navInterface, &navInfoBackend::updateGpsIsActiveFlightPlan);
    connect(netClient, &NetworkClient::current_leg_toChanged, &navInterface, &navInfoBackend::updateCurrentLegTo);
    connect(netClient, &NetworkClient::current_leg_fromChanged, &navInterface, &navInfoBackend::updateCurrentLegFrom);
    connect(netClient, &NetworkClient::leg_is_direct_toChanged, &navInterface, &navInfoBackend::updateLegIsDirectTo);
    connect(netClient, &NetworkClient::gps_distanceChanged, &navInterface, &navInfoBackend::updateCurrentLegDistance);
    connect(netClient, &NetworkClient::gps_bearingChanged, &navInterface, &navInfoBackend::updateCurrentLegBearing);
}

void PfdManager::connectRadioInfoSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::has_com1Changed, &radioInterface, &RadioInfoBackend::updateComm1State);
    connect(netClient, &NetworkClient::has_com2Changed, &radioInterface, &RadioInfoBackend::updateComm2State);
    connect(netClient, &NetworkClient::com1_freqChanged, &radioInterface, &RadioInfoBackend::updateComm1Freq);
    connect(netClient, &NetworkClient::com2_freqChanged, &radioInterface, &RadioInfoBackend::updateComm2Freq);

    connect(netClient, &NetworkClient::has_nav1Changed, &radioInterface, &RadioInfoBackend::updateNav1State);
    connect(netClient, &NetworkClient::has_nav2Changed, &radioInterface, &RadioInfoBackend::updateNav2State);
    connect(netClient, &NetworkClient::nav1_freqChanged, &radioInterface, &RadioInfoBackend::updateNav1Freq);
    connect(netClient, &NetworkClient::nav2_freqChanged, &radioInterface, &RadioInfoBackend::updateNav2Freq);
}

void PfdManager::connectWindDataSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::wind_true_directionChanged, &windInterface, &WindDataBackend::updateWindTrueDirection);
    connect(netClient, &NetworkClient::wind_directionChanged, &windInterface, &WindDataBackend::updateWindDirection);
    connect(netClient, &NetworkClient::wind_strengthChanged, &windInterface, &WindDataBackend::updateWindStrength);
}
