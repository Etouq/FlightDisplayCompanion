#include "AirspeedIndicator.hpp"

#include "io/NetworkClient/NetworkClient.hpp"

namespace pages::pfd
{

AirspeedIndicator::AirspeedIndicator(io::network::NetworkClient *netClient, QObject *parent)
  : QObject(parent),
    d_previousTime()
{
    using io::network::NetworkClient;
    connect(netClient, &NetworkClient::airspeedChanged, this, &AirspeedIndicator::updateAirspeed);
    connect(netClient, &NetworkClient::maxSpeedChanged, this, &AirspeedIndicator::updateMaxSpeed);
    connect(netClient, &NetworkClient::trueAirspeedChanged, this, &AirspeedIndicator::updateTrueAirspeed);
    connect(netClient, &NetworkClient::refSpeedChanged, this, &AirspeedIndicator::updateRefSpeed);
}

}  // namespace pages::pfd
