#include "ApInfo.hpp"

#include "io/NetworkClient/NetworkClient.hpp"

namespace pages::pfd
{

ApInfo::ApInfo(io::network::NetworkClient *netClient, QObject *parent)
  : QObject(parent)
{
    using io::network::NetworkClient;
    connect(netClient, &NetworkClient::apAvailableChanged, this, &ApInfo::updateHasAp);
    connect(netClient, &NetworkClient::apLateralActiveChanged, this, &ApInfo::updateApLateralActive);
    connect(netClient, &NetworkClient::apLateralArmedChanged, this, &ApInfo::updateApLateralArmed);
    connect(netClient, &NetworkClient::apStatusChanged, this, &ApInfo::updateApStatus);
    connect(netClient, &NetworkClient::apYdStatusChanged, this, &ApInfo::updateApYdStatus);
    connect(netClient, &NetworkClient::apFdStatusChanged, this, &ApInfo::updateApFdActive);
    connect(netClient, &NetworkClient::apVerticalActiveChanged, this, &ApInfo::updateApVerticalActive);
    connect(netClient, &NetworkClient::apModeReferenceChanged, this, &ApInfo::updateApModeReference);
    connect(netClient, &NetworkClient::apArmedChanged, this, &ApInfo::updateApArmed);
    connect(netClient, &NetworkClient::apArmedReferenceChanged, this, &ApInfo::updateApArmedReference);
}

}  // namespace pages::pfd
