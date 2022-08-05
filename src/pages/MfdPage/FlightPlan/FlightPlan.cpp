#include "FlightPlan.hpp"
#include "io/NetworkClient/NetworkClient.hpp"
#include <QQmlEngine>

namespace pages::mfd
{

FlightPlan::FlightPlan(io::network::NetworkClient *netClient, QObject *parent)
  : QObject(parent)
{

    qmlRegisterSingletonInstance("Mfd.Flightplan", 1, 0, "FlightplanModel", &d_wpModel);

    connect(netClient, &io::network::NetworkClient::gpsWpDtkChanged, this, &FlightPlan::updateWpDtk);
    connect(netClient, &io::network::NetworkClient::gpsWpEteChanged, this, &FlightPlan::updateWpEte);
    connect(netClient, &io::network::NetworkClient::gpsDestEteChanged, this, &FlightPlan::updateDestEte);
    connect(netClient, &io::network::NetworkClient::zuluSecondsChanged, this, &FlightPlan::updateZuluTime);

    connect(netClient, &io::network::NetworkClient::clearFlightplanReceived, this, &FlightPlan::clearFlightplan);
    connect(netClient, &io::network::NetworkClient::receivedFlightplan, this, &FlightPlan::receivedFlightplan);
    connect(netClient, &io::network::NetworkClient::activeLegIdxChanged, this, &FlightPlan::updateActiveLegIdx);
}

}  // namespace pages::mfd
