#include "Altimeter.hpp"

#include "io/NetworkClient/NetworkClient.hpp"

namespace pages::pfd
{

Altimeter::Altimeter(io::network::NetworkClient *netClient, QObject *parent)
  : QObject(parent)
{
    using io::network::NetworkClient;
    connect(netClient, &NetworkClient::altitudeChanged, this, &Altimeter::updateAltitude);
    connect(netClient, &NetworkClient::radarAltitudeChanged, this, &Altimeter::updateRadarAltitude);
    connect(netClient, &NetworkClient::refAltitudeChanged, this, &Altimeter::updateReferenceAltitude);

    connect(netClient, &NetworkClient::vspeedChanged, this, &Altimeter::updateVspeed);
    connect(netClient, &NetworkClient::refVspeedChanged, this, &Altimeter::updateReferenceVspeed);

    connect(netClient, &NetworkClient::pressureChanged, this, &Altimeter::updatePressure);

    connect(netClient, &NetworkClient::vDevModeChanged, this, &Altimeter::updateVertDevMode);
    connect(netClient, &NetworkClient::vDevValueChanged, this, &Altimeter::updateVertDevValue);
}

}  // namespace pages::pfd
