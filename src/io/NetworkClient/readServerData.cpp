#include "NetworkClient.hpp"
#include "common/dataIdentifiers.hpp"
#include "common/definitions/AircraftDefinition/AircraftDefinition.hpp"

#include <QGeoCoordinate>

namespace io::network
{

bool NetworkClient::readServerData()
{
    ServerMessageIdentifier id = ServerMessageIdentifier::SERVER_CLOSING;
    d_socket.read(reinterpret_cast<char *>(&id), sizeof(id));


    switch (id)
    {
        case ServerMessageIdentifier::SERVER_CLOSING:
        {
            d_socket.commitTransaction();
            d_socket.disconnectFromHost();
            emit newErrorMessage("Server closed");
            break;
        }
        case ServerMessageIdentifier::LOAD_AIRCRAFT:
        {
            uint64_t dataSize = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(dataSize))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.read(reinterpret_cast<char *>(&dataSize), sizeof(dataSize));

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < dataSize)
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            definitions::AircraftDefinition aircraftDefinition = definitions::AircraftDefinition::fromBinary(d_socket);

            emit loadAircraft(aircraftDefinition);
            break;
        }
        case ServerMessageIdentifier::SIM_START_EVENT:
        {
            d_socket.commitTransaction();
            d_simRunning = true;
            emit simRunningChanged();
            break;
        }
        case ServerMessageIdentifier::SIM_STOP_EVENT:
        {
            d_socket.commitTransaction();
            d_simRunning = false;
            emit simRunningChanged();
            break;
        }
        case ServerMessageIdentifier::ERROR_MSG:
        {
            uint64_t size = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            d_socket.read(reinterpret_cast<char *>(&size), sizeof(size));

            if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            if (size > 0) [[likely]]
            {
                emit newErrorMessage(QString::fromUtf8(d_socket.read(size)));
            }

            break;
        }
    }

    return true;
}

}  // namespace io::network
