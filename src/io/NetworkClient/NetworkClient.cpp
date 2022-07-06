#include "NetworkClient.hpp"

namespace io::network
{
NetworkClient::NetworkClient(QObject *parent)
  : QObject(parent)
{

    connect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::verifyConnectionVersion);
    connect(&d_socket, &QTcpSocket::stateChanged, this, &NetworkClient::socketStateChanged);
    connect(&d_socket, &QTcpSocket::errorOccurred, this, &NetworkClient::socketErrorOccurred);

    d_connectionAttemptKiller.setInterval(5000);
    d_connectionAttemptKiller.setSingleShot(true);
    connect(&d_connectionAttemptKiller, &QTimer::timeout, this, &NetworkClient::abortConnectionAttempt);

    d_serverDatagramSocket.bind(QHostAddress::Any, 12000, QUdpSocket::DontShareAddress);

    connect(&d_serverDatagramSocket, &QUdpSocket::readyRead, this, &NetworkClient::broadcastReceived);
}
}  // namespace io::network
