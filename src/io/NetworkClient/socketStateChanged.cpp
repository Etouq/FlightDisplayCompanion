#include "NetworkClient.hpp"

#include <QDebug>
#include <QSettings>

namespace io::network
{

void NetworkClient::socketStateChanged(QAbstractSocket::SocketState state)
{
    qDebug() << "tcp state changed to:" << state;
    switch (state)
    {
        case QAbstractSocket::UnconnectedState:
        {
            d_connectionState = ConnectionState::DISCONNECTED;
            emit connectionStateChanged();

            // if we made a succesfull connection that means we switched the connected functions, so we now need to
            // switch back
            if (d_versionVerified)
            {
                d_versionVerified = false;
                disconnect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::readSimData);
                connect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::verifyConnectionVersion);
            }

            // restart udp socket if we're not shutting down
            if (!d_closingApplication && d_serverDatagramSocket.state() == QUdpSocket::UnconnectedState)
                d_serverDatagramSocket.bind(QHostAddress::Any,
                                            12000,
                                            QUdpSocket::DontShareAddress | QUdpSocket::ReuseAddressHint);

            break;
        }
        case QAbstractSocket::HostLookupState:
        case QAbstractSocket::ConnectingState:
        {
            d_connectionState = ConnectionState::CONNECTING;
            emit connectionStateChanged();
            break;
        }
        case QAbstractSocket::ConnectedState:
        {
            d_connectionAttemptKiller.stop();
            d_serverDatagramSocket.close();

            d_tryConnecting = false;
            d_addressOrPortChanged = false;

            QSettings settings;

            settings.setValue("lastUsedAddress", d_socket.peerAddress().toString());
            settings.setValue("lastUsedPort", d_socket.peerPort());

            setAddress(d_socket.peerAddress().toString());
            setPort(d_socket.peerPort());

            d_connectionState = ConnectionState::CONNECTED;
            emit connectionStateChanged();

            break;
        }
        case QAbstractSocket::ClosingState:
        {
            d_connectionState = ConnectionState::DISCONNECTING;
            emit connectionStateChanged();
            break;
        }
        default:
            break;
    }
}

void NetworkClient::udpSocketStateChanged(QAbstractSocket::SocketState state)
{
    qDebug() << "udp state changed to:" << state;
}

}  // namespace io::network
