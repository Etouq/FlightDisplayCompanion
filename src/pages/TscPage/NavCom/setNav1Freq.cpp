#include "NavCom.hpp"

namespace pages::tsc
{

void NavCom::setNav1Freq(int newFreq, bool swap)
{
    SimCommandId cmdId = SimCommandId::SET_NAV1_FREQ;
    QByteArray dataToSend(reinterpret_cast<const char *>(&cmdId), sizeof(cmdId));
    // format: 32 bit int for hz, bool for swap
    uint32_t newVal = newFreq;
    dataToSend.append(reinterpret_cast<const char *>(&newVal), sizeof(newVal));
    dataToSend.append(reinterpret_cast<const char *>(&swap), sizeof(swap));

    emit sendCommandsToSim(dataToSend);
}

}  // namespace pages::tsc
