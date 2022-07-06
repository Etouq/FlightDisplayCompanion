#include "NetworkClient.hpp"

namespace io::network
{

void NetworkClient::socketStateChanged(QAbstractSocket::SocketState state)
{
    switch (state)
    {
        case QAbstractSocket::UnconnectedState:
            d_connectionState = ConnectionState::DISCONNECTED;
            emit connectionStateChanged();

            connect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::verifyConnectionVersion);

            // restart udp socket if we're not shutting down
            if (!d_closingApplication)
                d_serverDatagramSocket.bind(QHostAddress::Any, 12000, QUdpSocket::DontShareAddress);

            break;
        case QAbstractSocket::HostLookupState:
        case QAbstractSocket::ConnectingState:
            d_connectionState = ConnectionState::CONNECTING;
            emit connectionStateChanged();
            break;
        case QAbstractSocket::ConnectedState:
            d_connectionAttemptKiller.stop();
            d_serverDatagramSocket.close();
            d_tryConnecting = false;
            d_addressOrPortChanged = false;

            setAddress(d_socket.peerAddress().toString());
            setPort(d_socket.peerPort());

            d_connectionState = ConnectionState::CONNECTED;
            emit connectionStateChanged();

            break;
        case QAbstractSocket::ClosingState:
            d_connectionState = ConnectionState::DISCONNECTING;
            emit connectionStateChanged();
            break;
        default:
            break;
    }
}

}  // namespace io::network
