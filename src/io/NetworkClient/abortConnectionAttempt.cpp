#include "NetworkClient.hpp"

namespace io::network
{

void NetworkClient::abortConnectionAttempt()
{
    d_tryConnecting = false;
    if (d_socket.state() != QTcpSocket::ConnectedState && d_socket.state() != QTcpSocket::ConnectingState)
    {
        qDebug() << "aborting connection attempt";
        d_socket.abort();

        // address or port changed so try again with new address and port
        if (d_addressOrPortChanged)
        {
            d_addressOrPortChanged = false;

            connectToServer();
        }
    }
}

}  // namespace io::network