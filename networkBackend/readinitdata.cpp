#include "networkclient.h"
#include "dataIdentifiers.h"

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
        ClientIds versionId = ClientIds::CLIENT_NETWORK_VERSION;
        tcpSocket.write(reinterpret_cast<const char *>(&versionId), sizeof(versionId));
        tcpSocket.write(reinterpret_cast<const char *>(&latestSimconnectNetworkVersion), sizeof(latestSimconnectNetworkVersion));

        if (latestSimconnectNetworkVersion < serverVersion)
        {
            emit versionError("The network data transfer version of the Simconnect Server is newer than the one used by this application. Either update this application or revert the Simconnect Server to the last working version.");
            tcpSocket.disconnectFromHost();
            return;
        }
        if (latestSimconnectNetworkVersion > serverVersion)
        {
            emit versionError("The network data transfer version of the Simconnect Server is older than the one used by this application. Either update the Simconnect Server or revert this application to the last working version.");
            tcpSocket.disconnectFromHost();
            return;
        }

        disconnect(&tcpSocket, &QTcpSocket::readyRead, this, &NetworkClient::readInitData);
        connect(&tcpSocket, &QTcpSocket::readyRead, this, &NetworkClient::readSimconnectData);

        emit connectedToSimServer();
    }
    else
    {
        ClientIds versionId = ClientIds::CLIENT_NETWORK_VERSION;
        tcpSocket.write(reinterpret_cast<const char *>(&versionId), sizeof(versionId));
        tcpSocket.write(reinterpret_cast<const char *>(&latestGaugeNetworkVersion), sizeof(latestGaugeNetworkVersion));

        if (latestGaugeNetworkVersion < serverVersion)
        {
            emit versionError("The network data transfer version of the Gauge Designer is newer than the one used by this application. Either update this application or revert the Gauge Designer to the last working version.");
            tcpSocket.disconnectFromHost();
            return;
        }
        if (latestGaugeNetworkVersion > serverVersion)
        {
            emit versionError("The network data transfer version of the Gauge Designer is older than the one used by this application. Either update the Gauge Designer or revert this application to the last working version.");
            tcpSocket.disconnectFromHost();
            return;
        }

        disconnect(&tcpSocket, &QTcpSocket::readyRead, this, &NetworkClient::readInitData);
        connect(&tcpSocket, &QTcpSocket::readyRead, this, &NetworkClient::readDesignerData);

        emit connectedToGaugeDesigner();
    }
}
