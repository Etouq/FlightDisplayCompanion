#include "RadioInfo.hpp"
#include "io/NetworkClient/NetworkClient.hpp"

namespace pages::pfd
{

RadioInfo::RadioInfo(io::network::NetworkClient *netClient, QObject *parent)
  : QObject(parent)
{
    using io::network::NetworkClient;
    connect(netClient, &NetworkClient::com1AvailChanged, this, &RadioInfo::updateCom1Avail);
    connect(netClient, &NetworkClient::com2AvailChanged, this, &RadioInfo::updateCom2Avail);
    connect(netClient, &NetworkClient::com3AvailChanged, this, &RadioInfo::updateCom3Avail);
    connect(netClient, &NetworkClient::com1FreqChanged, this, &RadioInfo::updateCom1Freq);
    connect(netClient, &NetworkClient::com2FreqChanged, this, &RadioInfo::updateCom2Freq);
    connect(netClient, &NetworkClient::com3FreqChanged, this, &RadioInfo::updateCom3Freq);

    connect(netClient, &NetworkClient::nav1AvailChanged, this, &RadioInfo::updateNav1Avail);
    connect(netClient, &NetworkClient::nav2AvailChanged, this, &RadioInfo::updateNav2Avail);
    connect(netClient, &NetworkClient::nav1FreqChanged, this, &RadioInfo::updateNav1Freq);
    connect(netClient, &NetworkClient::nav2FreqChanged, this, &RadioInfo::updateNav2Freq);
}

}  // namespace pages::pfd
