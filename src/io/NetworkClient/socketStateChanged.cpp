#include "NetworkClient.hpp"

namespace io::network
{

void NetworkClient::socketStateChanged(QAbstractSocket::SocketState state)
{
    switch (state)
    {
        case QAbstractSocket::UnconnectedState:
            d_connectionState = ConnectionState::DISCONNECTED;
            emit connectionStateChanged(d_connectionState);
            break;
        case QAbstractSocket::HostLookupState:
        case QAbstractSocket::ConnectingState:
            d_connectionState = ConnectionState::CONNECTING;
            emit connectionStateChanged(d_connectionState);
            break;
        case QAbstractSocket::ConnectedState:
            d_connectionState = ConnectionState::CONNECTED;
            emit connectionStateChanged(d_connectionState);
            break;
        case QAbstractSocket::ClosingState:
            d_connectionState = ConnectionState::DISCONNECTING;
            emit connectionStateChanged(d_connectionState);
            break;
        default:
            break;
    }
}

}  // namespace io::network
