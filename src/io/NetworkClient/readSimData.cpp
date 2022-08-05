#include "NetworkClient.hpp"
#include "common/dataIdentifiers.hpp"

namespace io::network
{

void NetworkClient::readSimData()
{
    DataGroupIdentifier id = DataGroupIdentifier::PFD_DATA;
    while (d_socket.bytesAvailable() > 1)
    {
        QByteArray allData = d_socket.peek(d_socket.bytesAvailable());
        if (d_socket.isTransactionStarted())
            qDebug() << "Error: transaction not closed properly:\n\n" << allData.toHex() << "\n\n";
        d_socket.startTransaction();
        d_socket.read(reinterpret_cast<char *>(&id), sizeof(id));

        switch (id)
        {
            case DataGroupIdentifier::PFD_DATA:
            {
                if (!readPfdData())
                {
                    QByteArray remainingData = d_socket.peek(d_socket.bytesAvailable());
                    if (d_socket.isTransactionStarted())
                        qDebug() << "Error: pfd data transaction not rolled back properly";
                    return;
                }
                QByteArray remainingData = d_socket.peek(d_socket.bytesAvailable());
                if (d_socket.isTransactionStarted())
                    qDebug() << "Error: pfd data transaction not committed properly";
                break;
            }
            case DataGroupIdentifier::MFD_DATA:
            {
                if (!readMfdData())
                {
                    QByteArray remainingData = d_socket.peek(d_socket.bytesAvailable());
                    if (d_socket.isTransactionStarted())
                        qDebug() << "Error: mfd data transaction not rolled back properly";
                    return;
                }
                QByteArray remainingData = d_socket.peek(d_socket.bytesAvailable());
                if (d_socket.isTransactionStarted())
                    qDebug() << "Error: mfd data transaction not committed properly";
                break;
            }
            case DataGroupIdentifier::TSC_DATA:
            {
                if (!readTscData())
                {
                    QByteArray remainingData = d_socket.peek(d_socket.bytesAvailable());
                    if (d_socket.isTransactionStarted())
                        qDebug() << "Error: tsc data transaction not rolled back properly";
                    return;
                }
                QByteArray remainingData = d_socket.peek(d_socket.bytesAvailable());
                if (d_socket.isTransactionStarted())
                    qDebug() << "Error: tsc data transaction not committed properly";
                break;
            }
            case DataGroupIdentifier::SERVER_DATA:
            {
                if (!readServerData())
                {
                    QByteArray remainingData = d_socket.peek(d_socket.bytesAvailable());
                    if (d_socket.isTransactionStarted())
                        qDebug() << "Error: server data transaction not rolled back properly";
                    return;
                }
                QByteArray remainingData = d_socket.peek(d_socket.bytesAvailable());
                if (d_socket.isTransactionStarted())
                    qDebug() << "Error: server data transaction not committed properly";
                break;
            }
        }
    }
}

}  // namespace io::network
