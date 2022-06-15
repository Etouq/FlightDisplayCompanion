#include "NetworkClient.hpp"
#include "common/dataIdentifiers.hpp"


namespace io::network
{

void NetworkClient::readInitData()
{
    SharedServerIds identifier = SharedServerIds::GAUGE_DESIGNER_SERVER;
    uint8_t serverVersion = 0;
    if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(identifier) + sizeof(serverVersion))
        return;

    d_socket.read(reinterpret_cast<char *>(&identifier), sizeof(identifier));
    d_socket.read(reinterpret_cast<char *>(&serverVersion), sizeof(serverVersion));

    if (identifier == SharedServerIds::SIMCONNECT_SERVER)
    {
        ClientToServerIds versionId = ClientToServerIds::CLIENT_NETWORK_VERSION;
        d_socket.write(reinterpret_cast<const char *>(&versionId), sizeof(versionId));
        d_socket.write(reinterpret_cast<const char *>(&c_simCommunicationVersion),
                        sizeof(c_simCommunicationVersion));

        if (c_simCommunicationVersion < serverVersion)
        {
            emit newErrorMessage(
              "The network data transfer version of the Simconnect Server is newer than the one "
              "used by this application. Please update this application.");
            d_socket.disconnectFromHost();
            return;
        }
        if (c_simCommunicationVersion > serverVersion)
        {
            emit newErrorMessage(
              "The network data transfer version of the Simconnect Server is older than the one "
              "used by this application. Please update the Simconnect Server.");
            d_socket.disconnectFromHost();
            return;
        }

        disconnect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::readInitData);
        connect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::readSimData);

        d_serverIsSim = true;
        emit serverIsSimChanged(d_serverIsSim);
    }
    else
    {
        ClientToDesignerIds versionId = ClientToDesignerIds::CLIENT_NETWORK_VERSION;
        d_socket.write(reinterpret_cast<const char *>(&versionId), sizeof(versionId));
        d_socket.write(reinterpret_cast<const char *>(&c_designerCommunicationVersion),
                        sizeof(c_designerCommunicationVersion));

        if (c_designerCommunicationVersion < serverVersion)
        {
            emit newErrorMessage(
              "The network data transfer version of the Gauge Designer is newer than the one used "
              "by this application. Please update this application.");
            d_socket.disconnectFromHost();
            return;
        }
        if (c_designerCommunicationVersion > serverVersion)
        {
            emit newErrorMessage(
              "The network data transfer version of the Gauge Designer is older than the one used "
              "by this application. Please update the Gauge Designer.");
            d_socket.disconnectFromHost();
            return;
        }

        disconnect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::readInitData);
        connect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::readDesignerData);

        d_serverIsSim = false;
        emit serverIsSimChanged(d_serverIsSim);
    }
}

}  // namespace io::network