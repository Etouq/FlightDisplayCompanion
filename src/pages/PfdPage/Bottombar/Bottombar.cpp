#include "Bottombar.hpp"

#include "io/NetworkClient/NetworkClient.hpp"

namespace pages::pfd
{

Bottombar::Bottombar(io::network::NetworkClient *netClient, QObject *parent)
  : QObject(parent)
{
    using io::network::NetworkClient;
    connect(netClient, &NetworkClient::zuluSecondsChanged, this, &Bottombar::updateZuluTime);
    connect(netClient, &NetworkClient::localSecondsChanged, this, &Bottombar::updateLocalTime);
    connect(netClient, &NetworkClient::groundSpeedChanged, this, &Bottombar::updateGroundSpeed);
    connect(netClient, &NetworkClient::totalAirTempChanged, this, &Bottombar::updateTotalAirTemp);
    connect(netClient, &NetworkClient::outsideAirTempChanged, this, &Bottombar::updateOutsideAirTemp);
    connect(netClient, &NetworkClient::isaTempChanged, this, &Bottombar::updateStdAtmAirTemp);
}

}  // namespace pages::pfd
