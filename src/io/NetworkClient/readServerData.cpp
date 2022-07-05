#include "NetworkClient.hpp"
#include "common/dataIdentifiers.hpp"
#include "common/converters/basicConverters.hpp"
#include "common/definitions/AircraftDefinition/AircraftDefinition.hpp"

#include <QGeoCoordinate>

namespace io::network
{

bool NetworkClient::readServerData()
{
    ServerMessageIdentifier id = ServerMessageIdentifier::QUIT;
    d_socket.read(reinterpret_cast<char *>(&id), sizeof(id));


    switch (id)
    {
        case ServerMessageIdentifier::QUIT:
        {
            d_socket.commitTransaction();
            emit newErrorMessage("Sim closed");
            d_socket.disconnectFromHost();
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

            Converters::convert(d_socket, dataSize);

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
            emit simStartReceived();
            break;
        }
        case ServerMessageIdentifier::SIM_STOP_EVENT:
        {
            d_socket.commitTransaction();
            emit simStopReceived();
            break;
        }
        case ServerMessageIdentifier::SIM_STARTUP_FAILED:
        {
            d_socket.commitTransaction();
            emit newErrorMessage("Could not connect to sim");
            emit simStartupFailed();
            break;
        }
        case ServerMessageIdentifier::ERROR_MSG:
        {
            uint8_t size = 0;
            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }
            Converters::convert(d_socket, size);

            if (d_socket.bytesAvailable() < static_cast<int64_t>(size))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();

            if (size > 0) [[likely]]
            {
                emit newErrorMessage(Converters::convertString(d_socket, size));
            }

            break;
        }
    }

    return true;
}

}  // namespace io::network
