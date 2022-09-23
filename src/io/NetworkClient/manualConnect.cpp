#include "NetworkClient.hpp"

namespace io::network
{

void NetworkClient::manualConnect(const QString &address, int port)
{
    d_connectionAttemptKiller.stop();
    d_socket.abort();

    d_datagramAddress = QHostAddress(address);
    d_datagramPort = port;

    d_tryConnecting = true;
    qDebug() << "manually connecting to server at address:" << d_datagramAddress << "and port:" << d_datagramPort;

    d_socket.connectToHost(d_datagramAddress, d_datagramPort);

    d_connectionAttemptKiller.start();
}

}  // namespace io::network