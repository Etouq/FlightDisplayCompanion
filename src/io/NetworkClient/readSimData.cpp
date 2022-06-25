#include "NetworkClient.hpp"
#include "common/dataIdentifiers.hpp"

namespace io::network
{

void NetworkClient::readSimData()
{
    DataGroupIdentifier id = DataGroupIdentifier::PFD_DATA;
    while (d_socket.bytesAvailable() > 1)
    {
        d_socket.startTransaction();
        d_socket.read(reinterpret_cast<char *>(&id), sizeof(id));

        switch (id)
        {
            case DataGroupIdentifier::PFD_DATA:
                if (!readPfdData())
                    return;
                break;
            case DataGroupIdentifier::MFD_DATA:
                if (!readMfdData())
                    return;
                break;
            case DataGroupIdentifier::TSC_DATA:
                if (!readTscData())
                    return;
                break;
            case DataGroupIdentifier::SERVER_DATA:
                if (!readServerData())
                    return;
                break;
        }
    }
}

}  // namespace io::network
