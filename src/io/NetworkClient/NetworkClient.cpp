#include "NetworkClient.hpp"

#include <QNetworkProxy>
#include <QSettings>

namespace io::network
{

NetworkClient::NetworkClient(QObject *parent)
  : QObject(parent)
{
    d_socket.setProxy(QNetworkProxy::NoProxy);
    d_serverDatagramSocket.setProxy(QNetworkProxy::NoProxy);

    d_socket.setSocketOption(QAbstractSocket::KeepAliveOption, 1);
    d_socket.setSocketOption(QAbstractSocket::LowDelayOption, 1);

    d_versionVerified = false;
    connect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::verifyConnectionVersion);
    connect(&d_socket, &QTcpSocket::stateChanged, this, &NetworkClient::socketStateChanged);
    connect(&d_socket, &QTcpSocket::errorOccurred, this, &NetworkClient::socketErrorOccurred);
    connect(&d_serverDatagramSocket, &QUdpSocket::stateChanged, this, &NetworkClient::udpSocketStateChanged);
    connect(&d_serverDatagramSocket, &QUdpSocket::errorOccurred, this, &NetworkClient::udpSocketErrorOccurred);

    d_connectionAttemptKiller.setInterval(5000);
    d_connectionAttemptKiller.setSingleShot(true);
    connect(&d_connectionAttemptKiller, &QTimer::timeout, this, &NetworkClient::abortConnectionAttempt);

    QSettings settings;

    if (settings.contains("lastUsedAddress") && settings.contains("lastUsedPort"))
    {
        d_datagramAddress = QHostAddress(settings.value("lastUsedAddress").toString());
        d_datagramPort = settings.value("lastUsedPort").toInt();
        connectToServer();
    }

    // d_serverDatagramSocket.bind(QHostAddress::Any, 11999, QUdpSocket::DontShareAddress);
    if (!d_serverDatagramSocket.bind(QHostAddress::Any,
                                     12000,
                                     QUdpSocket::DontShareAddress | QUdpSocket::ReuseAddressHint))
        qWarning() << "\n\nfailed to bind with error:" << d_serverDatagramSocket.errorString() << "\n\n";
    else
        qDebug() << "\n\nbind success\n\n";

    connect(&d_serverDatagramSocket, &QUdpSocket::readyRead, this, &NetworkClient::broadcastReceived);
    // d_socket.connectToHost(QHostAddress("fe80::5d5f:b02e:e0ae:935c%6"), 12000);
}

NetworkClient::~NetworkClient()
{
    d_closingApplication = true;

    d_serverDatagramSocket.abort();

    d_socket.disconnectFromHost();
    if (d_socket.state() != QAbstractSocket::UnconnectedState && !d_socket.waitForDisconnected(1000))
    {
        d_socket.abort();
    }
}

}  // namespace io::network
