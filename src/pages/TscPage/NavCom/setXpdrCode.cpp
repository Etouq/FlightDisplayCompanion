#include "NavCom.hpp"

namespace pages::tsc
{

void NavCom::setXpdrCode(int newCode)
{
    SimCommandId cmdId = SimCommandId::SET_XPDR_CODE;
    QByteArray dataToSend(reinterpret_cast<const char *>(&cmdId), sizeof(cmdId));

    uint32_t newVal = newCode;
    dataToSend.append(reinterpret_cast<const char *>(&newVal), sizeof(newVal));

    emit sendCommandsToSim(dataToSend);
}

}  // namespace pages::tsc
