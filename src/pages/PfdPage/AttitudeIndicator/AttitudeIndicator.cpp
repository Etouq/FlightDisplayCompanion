#include "AttitudeIndicator.hpp"

#include "io/NetworkClient/NetworkClient.hpp"

namespace pages::pfd
{

AttitudeIndicator::AttitudeIndicator(io::network::NetworkClient *netClient, QObject *parent)
  : QObject(parent)
{
    using io::network::NetworkClient;
    connect(netClient, &NetworkClient::attitudeChanged, this, &AttitudeIndicator::updateAttitude);

    connect(netClient, &NetworkClient::apFdStatusChanged, this, &AttitudeIndicator::updateFdActive);
    connect(netClient, &NetworkClient::fdAttitudeChanged, this, &AttitudeIndicator::updateFdAttitude);
}

}  // namespace pages::pfd
