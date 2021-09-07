#include "tscpagebackend.h"

enum class CommandIds : uint8_t
{
    SET_COM1_FREQ,
    SET_COM2_FREQ,
    SET_NAV1_FREQ,
    SET_NAV2_FREQ,
    SWAP_COM1,
    SWAP_COM2,
    SWAP_NAV1,
    SWAP_NAV2,
    SET_XPDR_CODE,
    SET_XPDR_STATE
};

int TscPageBackend::com1StbyHz() const
{
    return d_com1StbyHz;
}

int TscPageBackend::com1ActiveHz() const
{
    return d_com1ActiveHz;
}

int TscPageBackend::com2StbyHz() const
{
    return d_com2StbyHz;
}

int TscPageBackend::com2ActiveHz() const
{
    return d_com2ActiveHz;
}

int TscPageBackend::nav1StbyHz() const
{
    return d_nav1StbyHz;
}

int TscPageBackend::nav1ActiveHz() const
{
    return d_nav1ActiveHz;
}

int TscPageBackend::nav2StbyHz() const
{
    return d_nav2StbyHz;
}

int TscPageBackend::nav2ActiveHz() const
{
    return d_nav2ActiveHz;
}

void TscPageBackend::setCom1Freq(int newFreq, bool swap)
{
    CommandIds command_ids = CommandIds::SET_COM1_FREQ;
    QByteArray dataToSend(reinterpret_cast<const char *>(&command_ids), sizeof(command_ids));
    // format: 32 bit int for hz, bool for swap
    int32_t newVal = newFreq;
    dataToSend.append(reinterpret_cast<const char *>(&newVal), sizeof(newVal));
    dataToSend.append(reinterpret_cast<const char *>(&swap), sizeof(swap));

    emit sendCommandsToSim(dataToSend);
}

void TscPageBackend::setCom2Freq(int newFreq, bool swap)
{
    CommandIds command_ids = CommandIds::SET_COM2_FREQ;
    QByteArray dataToSend(reinterpret_cast<const char *>(&command_ids), sizeof(command_ids));
    // format: 32 bit int for hz, bool for swap
    int32_t newVal = newFreq;
    dataToSend.append(reinterpret_cast<const char *>(&newVal), sizeof(newVal));
    dataToSend.append(reinterpret_cast<const char *>(&swap), sizeof(swap));

    emit sendCommandsToSim(dataToSend);
}

void TscPageBackend::setNav1Freq(int newFreq, bool swap)
{
    CommandIds command_ids = CommandIds::SET_NAV1_FREQ;
    QByteArray dataToSend(reinterpret_cast<const char *>(&command_ids), sizeof(command_ids));
    // format: 32 bit int for hz, bool for swap
    int32_t newVal = newFreq;
    dataToSend.append(reinterpret_cast<const char *>(&newVal), sizeof(newVal));
    dataToSend.append(reinterpret_cast<const char *>(&swap), sizeof(swap));

    emit sendCommandsToSim(dataToSend);
}

void TscPageBackend::setNav2Freq(int newFreq, bool swap)
{
    CommandIds command_ids = CommandIds::SET_NAV2_FREQ;
    QByteArray dataToSend(reinterpret_cast<const char *>(&command_ids), sizeof(command_ids));
    // format: 32 bit int for hz, bool for swap
    int32_t newVal = newFreq;
    dataToSend.append(reinterpret_cast<const char *>(&newVal), sizeof(newVal));
    dataToSend.append(reinterpret_cast<const char *>(&swap), sizeof(swap));

    emit sendCommandsToSim(dataToSend);
}

void TscPageBackend::swapCom1()
{
    CommandIds command_id = CommandIds::SWAP_COM1;

    emit sendCommandsToSim(
      QByteArray(reinterpret_cast<const char *>(&command_id), sizeof(command_id)));
}

void TscPageBackend::swapCom2()
{
    CommandIds command_id = CommandIds::SWAP_COM2;

    emit sendCommandsToSim(
      QByteArray(reinterpret_cast<const char *>(&command_id), sizeof(command_id)));
}

void TscPageBackend::swapNav1()
{
    CommandIds command_id = CommandIds::SWAP_NAV1;

    emit sendCommandsToSim(
      QByteArray(reinterpret_cast<const char *>(&command_id), sizeof(command_id)));
}

void TscPageBackend::swapNav2()
{
    CommandIds command_id = CommandIds::SWAP_NAV2;

    emit sendCommandsToSim(
      QByteArray(reinterpret_cast<const char *>(&command_id), sizeof(command_id)));
}

int TscPageBackend::xpdrCode() const
{
    return d_xpdrCode;
}

int TscPageBackend::xpdrState() const
{
    return d_xpdrState;
}

void TscPageBackend::setXpdrCode(int newCode)
{
    CommandIds command_id = CommandIds::SET_XPDR_CODE;
    QByteArray dataToSend(reinterpret_cast<const char *>(&command_id), sizeof(command_id));
    int32_t newVal = newCode;
    dataToSend.append(reinterpret_cast<const char *>(&newVal), sizeof(newVal));

    emit sendCommandsToSim(dataToSend);
}

void TscPageBackend::setXpdrState(int newState)
{
    CommandIds command_id = CommandIds::SET_XPDR_STATE;
    QByteArray dataToSend(reinterpret_cast<const char *>(&command_id), sizeof(command_id));
    int8_t newVal = newState;
    dataToSend.append(reinterpret_cast<const char *>(&newVal), sizeof(newVal));

    emit sendCommandsToSim(dataToSend);
}


void TscPageBackend::updateCom1Active(float newFreq)
{
    d_com1ActiveHz = newFreq * 1000000;
    emit com1ActiveHzChanged();
}

void TscPageBackend::updateCom1Stby(float newFreq)
{
    d_com1StbyHz = newFreq * 1000000;
    emit com1StbyHzChanged();
}

void TscPageBackend::updateCom2Active(float newFreq)
{
    d_com2ActiveHz = newFreq * 1000000;
    emit com2ActiveHzChanged();
}

void TscPageBackend::updateCom2Stby(float newFreq)
{
    d_com2StbyHz = newFreq * 1000000;
    emit com2StbyHzChanged();
}

void TscPageBackend::updateNav1Active(float newFreq)
{
    d_nav1ActiveHz = newFreq * 1000000;
    emit nav1ActiveHzChanged();
}

void TscPageBackend::updateNav1Stby(float newFreq)
{
    d_nav1StbyHz = newFreq * 1000000;
    emit nav1StbyHzChanged();
}

void TscPageBackend::updateNav2Active(float newFreq)
{
    d_nav2ActiveHz = newFreq * 1000000;
    emit nav2ActiveHzChanged();
}

void TscPageBackend::updateNav2Stby(float newFreq)
{
    d_nav2StbyHz = newFreq * 1000000;
    emit nav2StbyHzChanged();
}

void TscPageBackend::updateXpdrCode(int newCode)
{
    d_xpdrCode = newCode;
    emit xpdrCodeChanged();
}

void TscPageBackend::updateXpdrState(int newState)
{
    d_xpdrState = newState;
    emit xpdrStateChanged();
}
