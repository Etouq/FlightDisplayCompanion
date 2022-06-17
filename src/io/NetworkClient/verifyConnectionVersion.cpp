#include "NetworkClient.hpp"
#include "common/dataIdentifiers.hpp"

namespace io::network
{

void NetworkClient::verifyConnectionVersion()
{
    uint8_t serverVersion = 0;
    if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(serverVersion))
        return;

    d_socket.read(reinterpret_cast<char *>(&serverVersion), sizeof(serverVersion));

    // let server know about potential type incompatibility too
    ClientToServerIds versionId = ClientToServerIds::CLIENT_NETWORK_VERSION;
    d_socket.write(reinterpret_cast<const char *>(&versionId), sizeof(versionId));
    d_socket.write(reinterpret_cast<const char *>(&s_communicationVersion), sizeof(s_communicationVersion));

    if (s_communicationVersion < serverVersion)
    {
        emit newErrorMessage("The network data transfer version of the Simconnect Server is newer than the one "
                             "used by this application. Please update this application.");
        d_socket.disconnectFromHost();
        return;
    }
    if (s_communicationVersion > serverVersion)
    {
        emit newErrorMessage("The network data transfer version of the Simconnect Server is older than the one "
                             "used by this application. Please update the Simconnect Server.");
        d_socket.disconnectFromHost();
        return;
    }

    disconnect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::verifyConnectionVersion);
    connect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::readSimData);
}

}  // namespace io::network