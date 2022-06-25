#include "NetworkClient.hpp"
#include "common/dataIdentifiers.hpp"
#include "common/converters/basicConverters.hpp"
#include <QDataStream>
#include <QImage>
#include "common/definitions/AircraftDefinition/AircraftDefinition.hpp"

namespace io::network
{

bool NetworkClient::readTscData()
{
    TscIdentifier id = TscIdentifier::COM1_AVAIL;
    d_socket.read(reinterpret_cast<char *>(&id), sizeof(id));

    switch (id)
    {
        // radio info
        case TscIdentifier::COM1_AVAIL:
        {
            bool newValue = false;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit com1AvailChanged(newValue);
            break;
        }
        case TscIdentifier::COM1_FREQ:
        {
            float newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit com1FreqChanged(newValue);
            break;
        }
        case TscIdentifier::COM1_STBY_FREQ:
        {
            float newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit com1StbyFreqChanged(newValue);
            break;
        }
        case TscIdentifier::COM2_AVAIL:
        {
            bool newValue = false;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit com2AvailChanged(newValue);
            break;
        }
        case TscIdentifier::COM2_FREQ:
        {
            float newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit com2FreqChanged(newValue);
            break;
        }
        case TscIdentifier::COM2_STBY_FREQ:
        {
            float newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit com2StbyFreqChanged(newValue);
            break;
        }
        case TscIdentifier::COM3_AVAIL:
        {
            bool newValue = false;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit com3AvailChanged(newValue);
            break;
        }
        case TscIdentifier::COM3_FREQ:
        {
            float newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit com3FreqChanged(newValue);
            break;
        }
        case TscIdentifier::COM3_STBY_FREQ:
        {
            float newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit com3StbyFreqChanged(newValue);
            break;
        }
        case TscIdentifier::NAV1_AVAIL:
        {
            bool newValue = false;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit nav1AvailChanged(newValue);
            break;
        }
        case TscIdentifier::NAV1_FREQ:
        {
            float newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit nav1FreqChanged(newValue);
            break;
        }
        case TscIdentifier::NAV1_STBY_FREQ:
        {
            float newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit nav1StbyFreqChanged(newValue);
            break;
        }
        case TscIdentifier::NAV2_AVAIL:
        {
            bool newValue = false;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit nav2AvailChanged(newValue);
            break;
        }
        case TscIdentifier::NAV2_FREQ:
        {
            float newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit nav2FreqChanged(newValue);
            break;
        }
        case TscIdentifier::NAV2_STBY_FREQ:
        {
            float newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit nav2StbyFreqChanged(newValue);
            break;
        }
        case TscIdentifier::XPDR_AVAIL:
        {
            bool newValue = false;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit xpdrAvailChanged(newValue);
            break;
        }
        case TscIdentifier::XPDR_CODE:
        {
            uint32_t newValue = 0;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit xpdrCodeChanged(newValue);
            break;
        }
        case TscIdentifier::XPDR_STATE:
        {
            TransponderState newValue = TransponderState::OFF;

            if (static_cast<uint64_t>(d_socket.bytesAvailable()) < sizeof(newValue))
            {
                d_socket.rollbackTransaction();
                return false;
            }

            d_socket.commitTransaction();
            Converters::convert(d_socket, newValue);
            emit xpdrStateChanged(newValue);
            break;
        }
        // aircraft selection data
        case TscIdentifier::AIRCRAFT_THUMBNAIL_DATA:
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

            // read image
            uint64_t imgSize = 0;
            Converters::convert(d_socket, imgSize);

            QByteArray imgArray = d_socket.read(imgSize);

            QDataStream imgData(&imgArray, QIODevice::ReadOnly);
            imgData.setVersion(QDataStream::Qt_5_15);

            QImage thumbnail;
            imgData >> thumbnail;

            // read aircraft definition
            definitions::AircraftDefinition aircraftDefinition = definitions::AircraftDefinition::fromBinary(d_socket);

            emit receivedNewAircraft(thumbnail, aircraftDefinition);
        }
    }

    return true;
}

}  // namespace io::network
