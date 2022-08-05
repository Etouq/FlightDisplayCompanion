#include "NetworkClient.hpp"

namespace io::network
{

void NetworkClient::socketErrorOccurred(QAbstractSocket::SocketError error)
{
    qDebug() << "socket error:" << error << d_socket.errorString();
    switch (error)
    {
        case QAbstractSocket::ConnectionRefusedError:
            emit newErrorMessage(
              "The connection was refused by the peer (or timed out). Make sure the server is running.");
            break;
        case QAbstractSocket::RemoteHostClosedError:
            emit newErrorMessage("The remote host (simconnect server) closed the connection.");
            break;
        case QAbstractSocket::SocketTimeoutError:
            emit newErrorMessage("The connection timed out. Make sure the server is running.");
            break;
        default:
            emit newErrorMessage(d_socket.errorString());
            break;
    }
}

}  // namespace io::network
