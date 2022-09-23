#include "NetworkClient.hpp"

namespace io::network
{

void NetworkClient::updateDefaultSpeedBugs(const QList<definitions::ReferenceSpeed> &newBugs)
{

    uint16_t size = newBugs.size();

    QByteArray dataToSend(reinterpret_cast<const char *>(&size), sizeof(size));

    uint8_t identSize;
    for (const definitions::ReferenceSpeed &bug : newBugs)
    {
        dataToSend.append(reinterpret_cast<const char *>(&bug.speed), sizeof(bug.speed));
        identSize = bug.designator.toUtf8().size();
        dataToSend.append(reinterpret_cast<const char *>(&identSize), sizeof(identSize));
        dataToSend.append(bug.designator.toUtf8());
    }

    size = dataToSend.size();
    dataToSend.prepend(reinterpret_cast<const char *>(&size), sizeof(size));

    constexpr ClientToServerIds clientId = ClientToServerIds::UPDATE_DEFAULT_SPEEDBUGS;
    dataToSend.prepend(reinterpret_cast<const char *>(&clientId), sizeof(clientId));

    d_socket.write(dataToSend);
}

}  // namespace io::network