#include "dataIdentifiers.h"
#include "networkclient.h"

void NetworkClient::readInitData()
{
    SharedServerIds identifier = SharedServerIds::GAUGE_DESIGNER_SERVER;
    uint8_t serverVersion = 0;
    if (tcpSocket.bytesAvailable() < sizeof(identifier) + sizeof(serverVersion))
        return;

    tcpSocket.read(reinterpret_cast<char *>(&identifier), sizeof(identifier));
    tcpSocket.read(reinterpret_cast<char *>(&serverVersion), sizeof(serverVersion));

    if (identifier == SharedServerIds::SIMCONNECT_SERVER)
    {
        ClientToServerIds versionId = ClientToServerIds::CLIENT_NETWORK_VERSION;
        tcpSocket.write(reinterpret_cast<const char *>(&versionId), sizeof(versionId));
        tcpSocket.write(reinterpret_cast<const char *>(&latestSimconnectNetworkVersion),
                        sizeof(latestSimconnectNetworkVersion));

        if (latestSimconnectNetworkVersion < serverVersion)
        {
            emit versionError(
              "The network data transfer version of the Simconnect Server is newer than the one "
              "used by this application. Please update this application.");
            tcpSocket.disconnectFromHost();
            return;
        }
        if (latestSimconnectNetworkVersion > serverVersion)
        {
            emit versionError(
              "The network data transfer version of the Simconnect Server is older than the one "
              "used by this application. Please update the Simconnect Server.");
            tcpSocket.disconnectFromHost();
            return;
        }

        disconnect(&tcpSocket, &QTcpSocket::readyRead, this, &NetworkClient::readInitData);
        connect(&tcpSocket, &QTcpSocket::readyRead, this, &NetworkClient::readSimconnectData);

        d_connectedToServer = true;
        emit connectedToSimServer();
    }
    else
    {
        ClientToDesignerIds versionId = ClientToDesignerIds::CLIENT_NETWORK_VERSION;
        tcpSocket.write(reinterpret_cast<const char *>(&versionId), sizeof(versionId));
        tcpSocket.write(reinterpret_cast<const char *>(&latestGaugeNetworkVersion),
                        sizeof(latestGaugeNetworkVersion));

        if (latestGaugeNetworkVersion < serverVersion)
        {
            emit versionError(
              "The network data transfer version of the Gauge Designer is newer than the one used "
              "by this application. Please update this application.");
            tcpSocket.disconnectFromHost();
            return;
        }
        if (latestGaugeNetworkVersion > serverVersion)
        {
            emit versionError(
              "The network data transfer version of the Gauge Designer is older than the one used "
              "by this application. Please update the Gauge Designer.");
            tcpSocket.disconnectFromHost();
            return;
        }

        disconnect(&tcpSocket, &QTcpSocket::readyRead, this, &NetworkClient::readInitData);
        connect(&tcpSocket, &QTcpSocket::readyRead, this, &NetworkClient::readDesignerData);

        d_connectedToServer = false;
        emit connectedToGaugeDesigner();
    }
}
