#include "NetworkClient.hpp"

namespace io::network
{

void NetworkClient::socketErrorOccurred(QAbstractSocket::SocketError error)
{
    switch (error)
    {
        case QAbstractSocket::ConnectionRefusedError:
            emit newErrorMessage(
              "The connection was refused by the peer (or timed out). Make sure the server is running and that the address and port are right.");
            break;
        case QAbstractSocket::RemoteHostClosedError:
            emit newErrorMessage("The remote host (simconnect server) closed the connection.");
            break;
        case QAbstractSocket::SocketTimeoutError:
            emit newErrorMessage("The connection timed out. Make sure the server is running and that the address and port are right.");
            break;
        default:
            emit newErrorMessage(d_socket.errorString());
            break;
    }
}

}  // namespace io::network
