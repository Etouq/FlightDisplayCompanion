#include "NetworkClient.hpp"

namespace io::network
{

void NetworkClient::connectToServer()
{
    d_tryConnecting = true;
    qDebug() << "connecting to server at address:" << d_datagramAddress << "and port:" << d_datagramPort;

    d_socket.connectToHost(d_datagramAddress, d_datagramPort);

    d_connectionAttemptKiller.start();
}

}  // namespace io::network