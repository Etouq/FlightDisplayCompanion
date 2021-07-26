#include <QImage>
#include <QString>

#include "networkclient.h"
#include "aircraftManager/aircraftfile.h"
#include "dataIdentifiers.h"

void NetworkClient::readDesignerData()
{
    while (!tcpSocket.atEnd())
    {
        tcpSocket.startTransaction();
        DesignerIds identifier = DesignerIds::REMOVE_AIRCRAFT_LIST;
        tcpSocket.read(reinterpret_cast<char *>(&identifier), sizeof(identifier));

        // they all start with bytesize check so it can be moved out of the switch
        // we break if there is not enough data ready
        int64_t byteSize = 0;
        if (tcpSocket.bytesAvailable() < sizeof(byteSize))
        {
            tcpSocket.rollbackTransaction();
            break;
        }
        tcpSocket.read(reinterpret_cast<char *>(&byteSize), sizeof(byteSize));
        if (tcpSocket.bytesAvailable() < byteSize)
        {
            tcpSocket.rollbackTransaction();
            break;
        }

        switch (identifier)
        {
            case DesignerIds::REMOVE_AIRCRAFT_LIST:
            {
                uint16_t listSize = 0;
                tcpSocket.read(reinterpret_cast<char *>(&listSize), sizeof(listSize));
                QStringList keys;

                for (int i = 0; i < listSize; i++)
                {
                    uint8_t strSize = 0;
                    tcpSocket.read(reinterpret_cast<char *>(&strSize), sizeof(strSize));
                    keys.append(tcpSocket.read(strSize));
                }

                tcpSocket.commitTransaction();
                emit remove_aircraft_list(keys);
                break;
            }
            case DesignerIds::LOAD_AIRCRAFT_LIST:
            {
                uint16_t listSize = 0;
                tcpSocket.read(reinterpret_cast<char *>(&listSize), sizeof(listSize));
                QStringList keys;

                for (int i = 0; i < listSize; i++)
                {
                    uint8_t strSize = 0;
                    tcpSocket.read(reinterpret_cast<char *>(&strSize), sizeof(strSize));
                    keys.append(tcpSocket.read(strSize));
                }

                tcpSocket.commitTransaction();
                emit load_aircraft_list(keys);
                break;
            }
            case DesignerIds::SAVE_AIRCRAFT:
            {
                AircraftDefinition aircraft;
                QImage image;

                AircraftFile::readAircraftFromStream(tcpSocket, aircraft, image);
                tcpSocket.commitTransaction();
                emit save_aircraft(aircraft, image);
                break;
            }
        }

    }
}
