#include "NavCom.hpp"

namespace pages::tsc
{

void NavCom::setXpdrState(TransponderState newState)
{
    SimCommandId cmdId = SimCommandId::SET_XPDR_STATE;
    QByteArray dataToSend(reinterpret_cast<const char *>(&cmdId), sizeof(cmdId));

    dataToSend.append(reinterpret_cast<const char *>(&newState), sizeof(newState));

    emit sendCommandsToSim(dataToSend);
}

}  // namespace pages::tsc
