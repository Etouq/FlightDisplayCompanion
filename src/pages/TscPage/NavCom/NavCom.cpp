#include "NavCom.hpp"
#include "io/NetworkClient/NetworkClient.hpp"

namespace pages::tsc
{

NavCom::NavCom(io::network::NetworkClient *netClient, QObject *parent)
  : QObject(parent)
{
    using io::network::NetworkClient;
    connect(netClient, &NetworkClient::com1AvailChanged, this, &NavCom::updateCom1Avail);
    connect(netClient, &NetworkClient::com2AvailChanged, this, &NavCom::updateCom2Avail);
    connect(netClient, &NetworkClient::com1FreqChanged, this, &NavCom::updateCom1Freq);
    connect(netClient, &NetworkClient::com2FreqChanged, this, &NavCom::updateCom2Freq);
    connect(netClient, &NetworkClient::com1StbyChanged, this, &NavCom::updateCom1StbyFreq);
    connect(netClient, &NetworkClient::com2StbyChanged, this, &NavCom::updateCom2StbyFreq);

    connect(netClient, &NetworkClient::nav1AvailChanged, this, &NavCom::updateNav1Avail);
    connect(netClient, &NetworkClient::nav2AvailChanged, this, &NavCom::updateNav2Avail);
    connect(netClient, &NetworkClient::nav1FreqChanged, this, &NavCom::updateNav1Freq);
    connect(netClient, &NetworkClient::nav2FreqChanged, this, &NavCom::updateNav2Freq);
    connect(netClient, &NetworkClient::nav1StbyChanged, this, &NavCom::updateNav1StbyFreq);
    connect(netClient, &NetworkClient::nav2StbyChanged, this, &NavCom::updateNav2StbyFreq);

    connect(netClient, &NetworkClient::xpdrCodeChanged, this, &NavCom::updateXprdCode);
    connect(netClient, &NetworkClient::xpdrStateChanged, this, &NavCom::updateXpdrState);
}

}  // namespace pages::tsc
