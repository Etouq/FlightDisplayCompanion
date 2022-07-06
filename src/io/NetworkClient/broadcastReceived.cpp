#include "NetworkClient.hpp"

#include <QJsonDocument>
#include <QVariant>

#include <QDebug>


namespace io::network
{

void NetworkClient::broadcastReceived()
{
    while (d_serverDatagramSocket.hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(d_serverDatagramSocket.pendingDatagramSize());

        d_serverDatagramSocket.readDatagram(datagram.data(), datagram.size());

        if (d_connectionState == ConnectionState::CONNECTED)
        {
            // already connected so just read to empty the buffer
            continue;
        }

        QJsonParseError parseError;
        QJsonDocument doc = QJsonDocument::fromJson(datagram, &parseError);

        if (doc.isNull())
        {
            emit newErrorMessage("datagram error: " + parseError.errorString());
            continue;
        }

        // emit newErrorMessage("received datagram:\n" + datagram);

        QVariantHash datagramData = doc.toVariant().toHash();

        if (!datagramData.contains("serverId")
            || !datagramData.contains("serverAddress")
            || !datagramData.contains("serverPort")
            || !datagramData.value("serverId").canConvert(QMetaType::QByteArray)
            || !datagramData.value("serverAddress").canConvert(QMetaType::QString)
            || !datagramData.value("serverPort").canConvert(QMetaType::UInt)
            || datagramData.value("serverId").toByteArray() != "Simconnect Server")
        {
            qDebug() << "contains serverid:" << datagramData.contains("serverId");
            qDebug() << "contains serverAddress:" << datagramData.contains("serverAddress");
            qDebug() << "contains serverPort:" << datagramData.contains("serverPort");
            qDebug() << "serverId is bytearray:" << (static_cast<QMetaType::Type>(datagramData.value("serverId").type()) != QMetaType::QByteArray) << "id type value:" << static_cast<QMetaType::Type>(datagramData.value("serverId").type());
            qDebug() << "serverAddress is string:" << (static_cast<QMetaType::Type>(datagramData.value("serverAddress").type()) != QMetaType::QString) << "address type value:" << static_cast<QMetaType::Type>(datagramData.value("serverAddress").type());
            qDebug() << "port convert to uint:" << datagramData.value("serverPort").canConvert(QMetaType::UInt) << "port type:" << static_cast<QMetaType::Type>(datagramData.value("serverPort").type());
            continue;
        }


        if (d_tryConnecting)
        {
            QHostAddress newAddress = QHostAddress(datagramData.value("serverAddress").toString());
            quint16 newPort = datagramData.value("serverPort").toUInt();

            // port or address already changed while trying to connect so don't overwrite
            if (!d_addressOrPortChanged)
                return;

            if (newAddress != d_datagramAddress || newPort != d_datagramPort)
            {
                // address or port changed so mark as new server to try if current connection fails
                d_addressOrPortChanged = true;
                d_datagramAddress = newAddress;
                d_datagramPort = newPort;
            }

            return;
        }

        // we're not already trying to connect to a server so start now
        d_addressOrPortChanged = false;

        d_datagramAddress = QHostAddress(datagramData.value("serverAddress").toString());
        d_datagramPort = datagramData.value("serverPort").toUInt();

        connectToServer();

    }
}

}  // namespace io::network