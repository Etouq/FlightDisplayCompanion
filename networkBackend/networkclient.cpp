#include "networkclient.h"

#include <QFile>
#include <QImage>
#include <QString>

#include "aircraftManager/aircraftfile.h"
#include "dataIdentifiers.h"
#include "networkinterface.h"

NetworkClient::NetworkClient(QObject *parent) : QObject(parent)
{
    connect(&tcpSocket, &QAbstractSocket::errorOccurred, this, &NetworkClient::newErrorReceived);
    connect(&tcpSocket, &QIODevice::readyRead, this, &NetworkClient::readData);
}


void NetworkClient::connectInterfaceSignals(NetworkInterface *netInterface)
{

    connect(this, &NetworkClient::resetButton, netInterface, &NetworkInterface::resetButton);
    connect(this, &NetworkClient::displayError, netInterface, &NetworkInterface::setNewErrorString);
    connect(&tcpSocket, &QAbstractSocket::connected, netInterface, &NetworkInterface::setConnected);
    connect(&tcpSocket, &QAbstractSocket::disconnected, netInterface, &NetworkInterface::setDisconnected);
    connect(&tcpSocket, &QAbstractSocket::stateChanged, netInterface, &NetworkInterface::stateChanged);
    connect(this, &NetworkClient::simConnectionFailed, netInterface, &NetworkInterface::simConnectionClosed);
    connect(this, &NetworkClient::connectedToSimServer, netInterface, &NetworkInterface::connectedToSim);
    connect(this, &NetworkClient::connectedToGaugeDesigner, netInterface, &NetworkInterface::connectedToDesigner);

    connect(netInterface, &NetworkInterface::connectPressed, this, &NetworkClient::connectPressed);
    connect(netInterface, &NetworkInterface::disconnectPressed, this, &NetworkClient::disconnectPressed);
}

void NetworkClient::newErrorReceived(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
        case QAbstractSocket::ConnectionRefusedError:
            emit displayError(
              "The connection was refused by the peer (or timed out). Make sure the server is running and that the address and port are right.");
            emit resetButton();
            break;
        case QAbstractSocket::RemoteHostClosedError:
            emit displayError("The remote host (simconnect server) closed the connection.");
            break;
        case QAbstractSocket::SocketTimeoutError:
            emit displayError("The connection timed out. Make sure the server is running and that the address and port are right.");
            emit resetButton();
            break;
        default:
            emit displayError(tcpSocket.errorString());
            emit resetButton();
            break;
    }
}

void NetworkClient::connectPressed(const QString &address, int port)
{
    tcpSocket.setSocketOption(QAbstractSocket::KeepAliveOption, 1);
    tcpSocket.setSocketOption(QAbstractSocket::LowDelayOption, 1);
    tcpSocket.connectToHost(address, port);
}

void NetworkClient::disconnectPressed()
{
    ClientIds clientId = ClientIds::QUIT;
    tcpSocket.write(reinterpret_cast<char *>(&clientId), sizeof(clientId));
    tcpSocket.disconnectFromHost();
}

void NetworkClient::startSim(const QByteArray &data)
{
    ClientIds clientId = ClientIds::START;
    QByteArray msg(reinterpret_cast<char *>(&clientId), sizeof(clientId));
    msg += data;
    tcpSocket.write(msg);
}

void NetworkClient::changeAircraft(const QByteArray &data)
{
    ClientIds clientId = ClientIds::CHANGE_AIRCRAFT;
    QByteArray msg(reinterpret_cast<char *>(&clientId), sizeof(clientId));
    msg += data;
    tcpSocket.write(msg);
}

void NetworkClient::sendAircraftToDesigner(const AircraftDefinition &aircraft)
{
    QString imagePath = AircraftFile::getImagePath(aircraft.name);
    if (!QFile(imagePath).exists())
        imagePath = ":/DefaultImage.png";

    QImage img(imagePath);
    ClientIds id = ClientIds::LOAD_AIRCRAFT;
    tcpSocket.write(reinterpret_cast<char *>(&id), sizeof(id));
    AircraftFile::writeAircraftToStream(tcpSocket, aircraft, img);
}

void NetworkClient::sendAircraftKeys(const QStringList &keys)
{
    uint16_t size = keys.size();
    QByteArray dataToSend = BinaryUtil::toBinary(size);
    for (int idx = 0; idx < size; idx++)
    {
        dataToSend += BinaryUtil::toBinary(keys[idx]);
    }
    int64_t totalSize = dataToSend.size();
    dataToSend.prepend(BinaryUtil::toBinary(totalSize));
    ClientIds id = ClientIds::AIRCRAFT_FILE_LIST;
    dataToSend.prepend(reinterpret_cast<char *>(&id), sizeof(id));
    tcpSocket.write(dataToSend);
}
