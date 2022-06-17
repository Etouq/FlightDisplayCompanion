#include "FlightPlan.hpp"
#include "io/NetworkClient/NetworkClient.hpp"

namespace pages::mfd
{

FlightPlan::FlightPlan(io::network::NetworkClient *netClient, QObject *parent)
  : QObject(parent)
{
    connect(netClient, &io::network::NetworkClient::gpsWpDtkChanged, this, &FlightPlan::updateWpDtk);
    connect(netClient, &io::network::NetworkClient::gpsWpEteChanged, this, &FlightPlan::updateWpEte);
    connect(netClient, &io::network::NetworkClient::gpsEteChanged, this, &FlightPlan::updateDestEte);
    connect(netClient, &io::network::NetworkClient::zuluSecondsChanged, this, &FlightPlan::updateZuluTime);

    connect(netClient, &io::network::NetworkClient::clearFlightplanReceived, this, &FlightPlan::clearFlightplan);
    connect(netClient, &io::network::NetworkClient::receivedFlightplan, this, &FlightPlan::receivedFlightplan);
}

}  // namespace pages::mfd
