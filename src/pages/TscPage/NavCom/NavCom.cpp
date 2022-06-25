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
    connect(netClient, &NetworkClient::com3AvailChanged, this, &NavCom::updateCom3Avail);
    connect(netClient, &NetworkClient::com1FreqChanged, this, &NavCom::updateCom1Freq);
    connect(netClient, &NetworkClient::com2FreqChanged, this, &NavCom::updateCom2Freq);
    connect(netClient, &NetworkClient::com3FreqChanged, this, &NavCom::updateCom3Freq);
    connect(netClient, &NetworkClient::com1StbyFreqChanged, this, &NavCom::updateCom1StbyFreq);
    connect(netClient, &NetworkClient::com2StbyFreqChanged, this, &NavCom::updateCom2StbyFreq);
    connect(netClient, &NetworkClient::com3StbyFreqChanged, this, &NavCom::updateCom3StbyFreq);

    connect(netClient, &NetworkClient::nav1AvailChanged, this, &NavCom::updateNav1Avail);
    connect(netClient, &NetworkClient::nav2AvailChanged, this, &NavCom::updateNav2Avail);
    connect(netClient, &NetworkClient::nav1FreqChanged, this, &NavCom::updateNav1Freq);
    connect(netClient, &NetworkClient::nav2FreqChanged, this, &NavCom::updateNav2Freq);
    connect(netClient, &NetworkClient::nav1StbyFreqChanged, this, &NavCom::updateNav1StbyFreq);
    connect(netClient, &NetworkClient::nav2StbyFreqChanged, this, &NavCom::updateNav2StbyFreq);

    connect(netClient, &NetworkClient::xpdrAvailChanged, this, &NavCom::updateXpdrAvail);
    connect(netClient, &NetworkClient::xpdrCodeChanged, this, &NavCom::updateXprdCode);
    connect(netClient, &NetworkClient::xpdrStateChanged, this, &NavCom::updateXpdrState);
}

}  // namespace pages::tsc
