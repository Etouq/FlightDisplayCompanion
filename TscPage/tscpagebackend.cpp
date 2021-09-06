#include "tscpagebackend.h"

#include <chrono>
#include <algorithm>
#include "../networkBackend/dataIdentifiers.h"

TscPageBackend::TscPageBackend(QObject *parent) : QObject(parent) {}

QString TscPageBackend::timeString() const
{
    return d_timeString;
}

void TscPageBackend::setCountingDown(bool state)
{
    int currTime = duration_cast<std::chrono::milliseconds>(
                     std::chrono::system_clock::now().time_since_epoch())
                     .count();

    if (d_isCounting)
    {
        d_baseTime = d_isCountingDown ? d_baseTime + d_beginTime - currTime
                                      : d_baseTime - d_beginTime + currTime;
        d_beginTime = currTime;
    }

    d_isCountingDown = state;

    emit isCountingDownChanged();
}

void TscPageBackend::switchCounting()
{
    int currTime = duration_cast<std::chrono::milliseconds>(
                     std::chrono::system_clock::now().time_since_epoch())
                     .count();
    d_isCounting = !d_isCounting;

    if (d_isCounting)
        d_beginTime = currTime;
    else
        d_baseTime = d_isCountingDown ? d_baseTime + d_beginTime - currTime
                                      : d_baseTime - d_beginTime + currTime;

    emit isCountingChanged();
}

void TscPageBackend::reset()
{
    if (d_isCounting)
        switchCounting();

    d_baseTime = d_isCountingDown ? d_initialValue : 0;

    updateTime();
}

void TscPageBackend::endKeyboardCallback(int time)
{
    d_baseTime = time;
    d_beginTime = duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch())
                    .count();
    d_initialValue = time;

    updateTime();
}

void TscPageBackend::updateTime()
{
    int time = getCurrentDisplay();

    QString newTime = QString("%1:%2:%3")
                        .arg((time / 3600000) % 24, 2, 10, QChar('0'))
                        .arg((time / 60000) % 60, 2, 10, QChar('0'))
                        .arg((time / 1000) % 60, 2, 10, QChar('0'));

    if (d_timeString != newTime)
    {
        d_timeString = newTime;
        emit timeStringChanged();
    }
}

int TscPageBackend::getCurrentDisplay()
{
    if (!d_isCounting)
        return d_baseTime;

    int currTime = duration_cast<std::chrono::milliseconds>(
                     std::chrono::system_clock::now().time_since_epoch())
                     .count();

    if (d_isCountingDown && d_baseTime + d_beginTime - currTime <= 0)
    {
        setCountingDown(false);
        d_baseTime = 0;
        d_beginTime = currTime;
    }

    if (!d_isCountingDown && d_baseTime - d_beginTime + currTime >= 86400000)
    {
        d_baseTime = 0;
        d_beginTime = currTime;
    }

    return d_isCountingDown ? d_baseTime + d_beginTime - currTime
                            : d_baseTime - d_beginTime + currTime;
}

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

void TscPageBackend::setCom1Freq(int32_t newFreq, bool swap)
{
    ClientToServerIds command_ids = ClientToServerIds::SET_COM1_FREQ;
    QByteArray dataToSend(reinterpret_cast<const char *>(&command_ids), sizeof(command_ids));
    // format: 32 bit int for hz, bool for swap
    dataToSend.append(reinterpret_cast<const char *>(&newFreq), sizeof(newFreq));
    dataToSend.append(reinterpret_cast<const char *>(&swap), sizeof(swap));

    emit sendCommandsToSim(dataToSend);
}

void TscPageBackend::setCom2Freq(int32_t newFreq, bool swap)
{
    ClientToServerIds command_ids = ClientToServerIds::SET_COM2_FREQ;
    QByteArray dataToSend(reinterpret_cast<const char *>(&command_ids), sizeof(command_ids));
    // format: 32 bit int for hz, bool for swap
    dataToSend.append(reinterpret_cast<const char *>(&newFreq), sizeof(newFreq));
    dataToSend.append(reinterpret_cast<const char *>(&swap), sizeof(swap));

    emit sendCommandsToSim(dataToSend);
}

void TscPageBackend::setNav1Freq(int32_t newFreq, bool swap)
{
    ClientToServerIds command_ids = ClientToServerIds::SET_NAV1_FREQ;
    QByteArray dataToSend(reinterpret_cast<const char *>(&command_ids), sizeof(command_ids));
    // format: 32 bit int for hz, bool for swap
    dataToSend.append(reinterpret_cast<const char *>(&newFreq), sizeof(newFreq));
    dataToSend.append(reinterpret_cast<const char *>(&swap), sizeof(swap));

    emit sendCommandsToSim(dataToSend);
}

void TscPageBackend::setNav2Freq(int32_t newFreq, bool swap)
{
    ClientToServerIds command_ids = ClientToServerIds::SET_NAV2_FREQ;
    QByteArray dataToSend(reinterpret_cast<const char *>(&command_ids), sizeof(command_ids));
    // format: 32 bit int for hz, bool for swap
    dataToSend.append(reinterpret_cast<const char *>(&newFreq), sizeof(newFreq));
    dataToSend.append(reinterpret_cast<const char *>(&swap), sizeof(swap));

    emit sendCommandsToSim(dataToSend);
}

void TscPageBackend::swapCom1()
{
    ClientToServerIds command_id = ClientToServerIds::SWAP_COM1;

    emit sendCommandsToSim(QByteArray(reinterpret_cast<const char *>(&command_id), sizeof(command_id)));
}

void TscPageBackend::swapCom2()
{
    ClientToServerIds command_id = ClientToServerIds::SWAP_COM2;

    emit sendCommandsToSim(QByteArray(reinterpret_cast<const char *>(&command_id), sizeof(command_id)));
}

void TscPageBackend::swapNav1()
{
    ClientToServerIds command_id = ClientToServerIds::SWAP_NAV1;

    emit sendCommandsToSim(QByteArray(reinterpret_cast<const char *>(&command_id), sizeof(command_id)));
}

void TscPageBackend::swapNav2()
{
    ClientToServerIds command_id = ClientToServerIds::SWAP_NAV2;

    emit sendCommandsToSim(QByteArray(reinterpret_cast<const char *>(&command_id), sizeof(command_id)));
}

int TscPageBackend::xpdrCode() const
{
    return d_xpdrCode;
}

int TscPageBackend::xpdrState() const
{
    return d_xpdrState;
}

void TscPageBackend::setXpdrCode(int32_t newCode)
{
    ClientToServerIds command_id = ClientToServerIds::SET_XPDR_CODE;
    QByteArray dataToSend(reinterpret_cast<const char *>(&command_id), sizeof(command_id));
    dataToSend.append(reinterpret_cast<const char *>(&newCode), sizeof(newCode));

    emit sendCommandsToSim(dataToSend);
}

void TscPageBackend::setXpdrState(int8_t newState)
{
    ClientToServerIds command_id = ClientToServerIds::SET_XPDR_STATE;
    QByteArray dataToSend(reinterpret_cast<const char *>(&command_id), sizeof(command_id));
    dataToSend.append(reinterpret_cast<const char *>(&newState), sizeof(newState));

    emit sendCommandsToSim(dataToSend);
}

void TscPageBackend::updateCom1Stby(float newFreq)
{
    d_com1StbyHz = newFreq * 1000000;
    emit com1StbyHzChanged();
}

void TscPageBackend::updateCom1Active(float newFreq)
{
    d_com1ActiveHz = newFreq * 1000000;
    emit com1ActiveHzChanged();
}

void TscPageBackend::updateCom2Stby(float newFreq)
{
    d_com2StbyHz = newFreq * 1000000;
    emit com2StbyHzChanged();
}

void TscPageBackend::updateCom2Active(float newFreq)
{
    d_com2ActiveHz = newFreq * 1000000;
    emit com2ActiveHzChanged();
}

void TscPageBackend::updateNav1Stby(float newFreq)
{
    d_nav1StbyHz = newFreq * 1000000;
    emit nav1StbyHzChanged();
}

void TscPageBackend::updateNav1Active(float newFreq)
{
    d_nav1ActiveHz = newFreq * 1000000;
    emit nav1ActiveHzChanged();
}

void TscPageBackend::updateNav2Stby(float newFreq)
{
    d_nav2StbyHz = newFreq * 1000000;
    emit nav2StbyHzChanged();
}

void TscPageBackend::updateNav2Active(float newFreq)
{
    d_nav2ActiveHz = newFreq * 1000000;
    emit nav2ActiveHzChanged();
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
