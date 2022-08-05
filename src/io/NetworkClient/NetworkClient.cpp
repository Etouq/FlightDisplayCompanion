#include "NetworkClient.hpp"

namespace io::network
{
NetworkClient::NetworkClient(QObject *parent)
  : QObject(parent)
{

    d_socket.setSocketOption(QAbstractSocket::KeepAliveOption, 1);
    d_socket.setSocketOption(QAbstractSocket::LowDelayOption, 1);

    connect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::verifyConnectionVersion);
    connect(&d_socket, &QTcpSocket::stateChanged, this, &NetworkClient::socketStateChanged);
    connect(&d_socket, &QTcpSocket::errorOccurred, this, &NetworkClient::socketErrorOccurred);

    d_connectionAttemptKiller.setInterval(5000);
    d_connectionAttemptKiller.setSingleShot(true);
    connect(&d_connectionAttemptKiller, &QTimer::timeout, this, &NetworkClient::abortConnectionAttempt);

    //d_serverDatagramSocket.bind(QHostAddress::Any, 11999, QUdpSocket::DontShareAddress);
    if (!d_serverDatagramSocket.bind(QHostAddress::Any, 11999, QUdpSocket::DontShareAddress | QUdpSocket::ReuseAddressHint))
        qDebug() << "\n\nfailed to bind\n\n";

    connect(&d_serverDatagramSocket, &QUdpSocket::readyRead, this, &NetworkClient::broadcastReceived);
}
}  // namespace io::network
