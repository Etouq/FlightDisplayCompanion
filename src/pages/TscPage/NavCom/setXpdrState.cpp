#include "NavCom.hpp"

namespace pages::tsc
{

void NavCom::setXpdrState(QmlTransponderState newQmlState)
{
    SimCommandId cmdId = SimCommandId::SET_XPDR_STATE;
    QByteArray dataToSend(reinterpret_cast<const char *>(&cmdId), sizeof(cmdId));

    TransponderState newState = static_cast<TransponderState>(newQmlState);
    dataToSend.append(reinterpret_cast<const char *>(&newState), sizeof(newState));

    emit sendCommandsToSim(dataToSend);
}

}  // namespace pages::tsc
