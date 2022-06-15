#include "NetworkClient.hpp"
#include "aircraftManager/aircraftfile.hpp"
#include "common/dataIdentifiers.hpp"

#include <QImage>


namespace io::network
{

void NetworkClient::readDesignerData()
{
    while (!d_socket.atEnd())
    {
        d_socket.startTransaction();
        DesignerIds identifier = DesignerIds::REMOVE_AIRCRAFT_LIST;
        d_socket.read(reinterpret_cast<char *>(&identifier), sizeof(identifier));

        // they all start with bytesize check so it can be moved out of the switch
        // we break if there is not enough data ready
        int64_t byteSize = 0;
        if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(byteSize))
        {
            d_socket.rollbackTransaction();
            break;
        }
        d_socket.read(reinterpret_cast<char *>(&byteSize), sizeof(byteSize));
        if (d_socket.bytesAvailable() < byteSize)
        {
            d_socket.rollbackTransaction();
            break;
        }

        switch (identifier)
        {
            case DesignerIds::REMOVE_AIRCRAFT_LIST:
            {
                uint16_t listSize = 0;
                d_socket.read(reinterpret_cast<char *>(&listSize), sizeof(listSize));
                QStringList keys;

                for (int i = 0; i < listSize; i++)
                {
                    uint8_t strSize = 0;
                    d_socket.read(reinterpret_cast<char *>(&strSize), sizeof(strSize));
                    keys.append(d_socket.read(strSize));
                }

                d_socket.commitTransaction();
                // emit remove_aircraft_list(keys);
                break;
            }
            case DesignerIds::LOAD_AIRCRAFT_LIST:
            {
                uint16_t listSize = 0;
                d_socket.read(reinterpret_cast<char *>(&listSize), sizeof(listSize));
                QStringList keys;

                for (int i = 0; i < listSize; i++)
                {
                    uint8_t strSize = 0;
                    d_socket.read(reinterpret_cast<char *>(&strSize), sizeof(strSize));
                    keys.append(d_socket.read(strSize));
                }

                d_socket.commitTransaction();
                // emit load_aircraft_list(keys);
                break;
            }
            case DesignerIds::SAVE_AIRCRAFT:
            {
                AircraftDefinition aircraft;
                QImage image;

                AircraftFile::readAircraftFromStream(d_socket, aircraft, image);
                d_socket.commitTransaction();
                // emit save_aircraft(aircraft, image);
                break;
            }
        }
    }
}

}  // namespace io::network