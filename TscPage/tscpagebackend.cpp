#include "tscpagebackend.h"

#include "../networkBackend/networkclient.h"
#include "../aircraftManager/definitions/aircraftDefinition.h"

TscPageBackend::TscPageBackend(QObject *parent) : QObject(parent) {}

void TscPageBackend::connectTscSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::com1_freqChanged, this, &TscPageBackend::updateCom1Active);
    connect(netClient, &NetworkClient::com1_stbyChanged, this, &TscPageBackend::updateCom1Stby);
    connect(netClient, &NetworkClient::com2_freqChanged, this, &TscPageBackend::updateCom2Active);
    connect(netClient, &NetworkClient::com2_stbyChanged, this, &TscPageBackend::updateCom2Stby);
    connect(netClient, &NetworkClient::nav1_freqChanged, this, &TscPageBackend::updateNav1Active);
    connect(netClient, &NetworkClient::nav1_stbyChanged, this, &TscPageBackend::updateNav1Stby);
    connect(netClient, &NetworkClient::nav2_freqChanged, this, &TscPageBackend::updateNav2Active);
    connect(netClient, &NetworkClient::nav2_stbyChanged, this, &TscPageBackend::updateNav2Stby);

    connect(netClient, &NetworkClient::xpdr_codeChanged, this, &TscPageBackend::updateXpdrCode);
    connect(netClient, &NetworkClient::xpdr_stateChanged, this, &TscPageBackend::updateXpdrState);

    connect(this, &TscPageBackend::sendCommandsToSim, netClient, &NetworkClient::sendCommands);
}

void TscPageBackend::resetSpeedBugs()
{
    d_vrSpeed = d_defaultVrSpeed;
    d_vxSpeed = d_defaultVxSpeed;
    d_vySpeed = d_defaultVySpeed;
    d_vappSpeed = d_defaultVappSpeed;

    emit vrSpeedChanged();
    emit vxSpeedChanged();
    emit vySpeedChanged();
    emit vappSpeedChanged();
}


void TscPageBackend::changeAircraft(const AircraftDefinition &aircraft)
{
    d_defaultVrSpeed = aircraft.defaultVr;
    d_defaultVxSpeed = aircraft.defaultVx;
    d_defaultVySpeed = aircraft.defaultVy;
    d_defaultVappSpeed = aircraft.defaultVapp;

    resetSpeedBugs();
}

