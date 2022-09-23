#include "NetworkClient.hpp"

namespace io::network
{

void NetworkClient::sendCommandString(const QByteArray &commandString)
{
    if (d_socket.state() != QTcpSocket::ConnectedState)
        return;

    constexpr ClientToServerIds clientId = ClientToServerIds::COMMAND_STRING;
    QByteArray msg(reinterpret_cast<const char *>(&clientId), sizeof(clientId));

    const uint64_t commandSize = commandString.size();
    msg.append(reinterpret_cast<const char *>(&commandSize), sizeof(commandSize));

    msg += commandString;
    d_socket.write(msg);
}

}  // namespace io::network