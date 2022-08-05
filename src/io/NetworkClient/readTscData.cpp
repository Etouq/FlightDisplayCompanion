#include "NetworkClient.hpp"
#include "common/dataIdentifiers.hpp"

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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
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
            d_socket.read(reinterpret_cast<char *>(&newValue), sizeof(newValue));
            emit xpdrStateChanged(newValue);
            break;
        }
    }

    return true;
}

}  // namespace io::network
