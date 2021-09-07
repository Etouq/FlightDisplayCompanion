#include "tscpagebackend.h"

#include "../networkBackend/networkclient.h"

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
