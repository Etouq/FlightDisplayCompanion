#include "NetworkClient.hpp"
#include "common/dataIdentifiers.hpp"
#include <QAndroidJniObject>

namespace io::network
{

void NetworkClient::verifyConnectionVersion()
{
    uint8_t serverVersion = 0;
    if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(serverVersion))
        return;

    d_socket.read(reinterpret_cast<char *>(&serverVersion), sizeof(serverVersion));


    // tell server about our name and protocol version
    QByteArray modelName = QAndroidJniObject::getStaticObjectField<jstring>("android/os/Build", "MODEL").toString().toUtf8();

    uint8_t messageSize = modelName.size();

    ClientToServerIds versionId = ClientToServerIds::HANDSHAKE;
    d_socket.write(reinterpret_cast<const char *>(&versionId), sizeof(versionId));
    d_socket.write(reinterpret_cast<const char *>(&messageSize), sizeof(messageSize));
    d_socket.write(reinterpret_cast<const char *>(&s_communicationVersion), sizeof(s_communicationVersion));
    d_socket.write(modelName.constData(), messageSize);

    // check if protocols match
    if (s_communicationVersion < serverVersion)
    {
        qDebug() << "local version:" << s_communicationVersion << "server version:" << serverVersion;
        emit newErrorMessage("The network protocol of the Simconnect Server is newer than the one "
                             "used by this application. Please update this application.");
        d_socket.disconnectFromHost();
        return;
    }
    if (s_communicationVersion > serverVersion)
    {
        qDebug() << "local version:" << s_communicationVersion << "server version:" << serverVersion;
        emit newErrorMessage("The network protocol of the Simconnect Server is older than the one "
                             "used by this application. Please update the Simconnect Server.");
        d_socket.disconnectFromHost();
        return;
    }

    // switch over data reading function
    disconnect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::verifyConnectionVersion);
    connect(&d_socket, &QTcpSocket::readyRead, this, &NetworkClient::readSimData);

    // read any data left in the buffer
    if (d_socket.bytesAvailable())
        readSimData();
}

}  // namespace io::network