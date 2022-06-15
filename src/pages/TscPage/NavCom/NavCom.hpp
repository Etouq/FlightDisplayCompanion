#ifndef __NAV_COM_HPP__
#define __NAV_COM_HPP__

#include "common/dataIdentifiers.hpp"
#include "common/typeEnums.hpp"

#include <QByteArray>
#include <QObject>

namespace io::network
{
class NetworkClient;
}

namespace pages::tsc
{

class NavCom : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool com1Avail READ com1Avail NOTIFY com1AvailChanged)
    Q_PROPERTY(bool com2Avail READ com2Avail NOTIFY com2AvailChanged)
    // Q_PROPERTY(bool com3Avail READ com3Avail NOTIFY com3AvailChanged)
    Q_PROPERTY(float com1Freq READ com1Freq NOTIFY com1FreqChanged)
    Q_PROPERTY(float com2Freq READ com2Freq NOTIFY com2FreqChanged)
    // Q_PROPERTY(float com3Freq READ com3Freq NOTIFY com3FreqChanged)
    Q_PROPERTY(float com1StbyFreq READ com1StbyFreq NOTIFY com1StbyFreqChanged)
    Q_PROPERTY(float com2StbyFreq READ com2StbyFreq NOTIFY com2StbyFreqChanged)
    // Q_PROPERTY(float com3StbyFreq READ com3StbyFreq NOTIFY com3StbyFreqChanged)

    Q_PROPERTY(bool nav1Avail READ nav1Avail NOTIFY nav1AvailChanged)
    Q_PROPERTY(bool nav2Avail READ nav2Avail NOTIFY nav2AvailChanged)
    Q_PROPERTY(float nav1Freq READ nav1Freq NOTIFY nav1FreqChanged)
    Q_PROPERTY(float nav2Freq READ nav2Freq NOTIFY nav2FreqChanged)
    Q_PROPERTY(float nav1StbyFreq READ nav1StbyFreq NOTIFY nav1StbyFreqChanged)
    Q_PROPERTY(float nav2StbyFreq READ nav2StbyFreq NOTIFY nav2StbyFreqChanged)

    // Q_PROPERTY(bool xpdrAvail READ xpdrAvail NOTIFY xpdrAvailChanged)
    Q_PROPERTY(int xpdrCode READ xpdrCode WRITE setXpdrCode NOTIFY xpdrCodeChanged)
    Q_PROPERTY(TransponderState xpdrState READ xpdrState WRITE setXpdrState NOTIFY xpdrStateChanged)

public:

    explicit NavCom(io::network::NetworkClient *netClient, QObject *parent);

    Q_INVOKABLE void setCom1Freq(int newFreq, bool swap);
    Q_INVOKABLE void setCom2Freq(int newFreq, bool swap);
    // Q_INVOKABLE void setCom3Freq(int newFreq, bool swap);
    Q_INVOKABLE void setNav1Freq(int newFreq, bool swap);
    Q_INVOKABLE void setNav2Freq(int newFreq, bool swap);

    Q_INVOKABLE void swapCom1()
    {
        SimCommandId cmdId = SimCommandId::SWAP_COM1;

        emit sendCommandsToSim(QByteArray(reinterpret_cast<const char *>(&cmdId), sizeof(cmdId)));
    }

    Q_INVOKABLE void swapCom2()
    {
        SimCommandId cmdId = SimCommandId::SWAP_COM2;

        emit sendCommandsToSim(QByteArray(reinterpret_cast<const char *>(&cmdId), sizeof(cmdId)));
    }

    // Q_INVOKABLE void swapCom3();
    Q_INVOKABLE void swapNav1()
    {
        SimCommandId cmdId = SimCommandId::SWAP_NAV1;

        emit sendCommandsToSim(QByteArray(reinterpret_cast<const char *>(&cmdId), sizeof(cmdId)));
    }

    Q_INVOKABLE void swapNav2()
    {
        SimCommandId cmdId = SimCommandId::SWAP_NAV2;

        emit sendCommandsToSim(QByteArray(reinterpret_cast<const char *>(&cmdId), sizeof(cmdId)));
    }

    void setXpdrCode(int newCode);
    void setXpdrState(TransponderState newState);

    bool com1Avail() const
    {
        return d_com1Avail;
    }

    bool com2Avail() const
    {
        return d_com2Avail;
    }

    bool com3Avail() const
    {
        return d_com3Avail;
    }

    float com1Freq() const
    {
        return d_com1Freq;
    }

    float com2Freq() const
    {
        return d_com2Freq;
    }

    float com3Freq() const
    {
        return d_com3Freq;
    }

    float com1StbyFreq() const
    {
        return d_com1StbyFreq;
    }

    float com2StbyFreq() const
    {
        return d_com2StbyFreq;
    }

    float com3StbyFreq() const
    {
        return d_com3StbyFreq;
    }

    bool nav1Avail() const
    {
        return d_nav1Avail;
    }

    bool nav2Avail() const
    {
        return d_nav2Avail;
    }

    float nav1Freq() const
    {
        return d_nav1Freq;
    }

    float nav2Freq() const
    {
        return d_nav2Freq;
    }

    float nav1StbyFreq() const
    {
        return d_nav1StbyFreq;
    }

    float nav2StbyFreq() const
    {
        return d_nav2StbyFreq;
    }

    int xpdrCode() const
    {
        return d_xpdrCode;
    }

    TransponderState xpdrState() const
    {
        return d_xpdrState;
    }

signals:

    void com1AvailChanged();
    void com2AvailChanged();
    void com3AvailChanged();
    void com1FreqChanged();
    void com2FreqChanged();
    void com3FreqChanged();
    void com1StbyFreqChanged();
    void com2StbyFreqChanged();
    void com3StbyFreqChanged();

    void nav1AvailChanged();
    void nav2AvailChanged();
    void nav1FreqChanged();
    void nav2FreqChanged();
    void nav1StbyFreqChanged();
    void nav2StbyFreqChanged();

    void xpdrCodeChanged();
    void xpdrStateChanged();


    void sendCommandsToSim(const QByteArray &data);

public slots:

    void updateCom1Avail(bool newValue)
    {
        d_com1Avail = newValue;
        emit com1AvailChanged();
    }

    void updateCom2Avail(bool newValue)
    {
        d_com2Avail = newValue;
        emit com2AvailChanged();
    }

    void updateCom3Avail(bool newValue)
    {
        d_com3Avail = newValue;
        emit com3AvailChanged();
    }

    void updateCom1Freq(float newValue)
    {
        d_com1Freq = newValue;
        if (d_com1Avail)
            emit com1FreqChanged();
    }

    void updateCom2Freq(float newValue)
    {
        d_com2Freq = newValue;
        if (d_com2Avail)
            emit com2FreqChanged();
    }

    void updateCom3Freq(float newValue)
    {
        d_com3Freq = newValue;
        if (d_com3Avail)
            emit com3FreqChanged();
    }

    void updateCom1StbyFreq(float newValue)
    {
        d_com1StbyFreq = newValue;
        if (d_com1Avail)
            emit com1StbyFreqChanged();
    }

    void updateCom2StbyFreq(float newValue)
    {
        d_com2StbyFreq = newValue;
        if (d_com2Avail)
            emit com2StbyFreqChanged();
    }

    void updateCom3StbyFreq(float newValue)
    {
        d_com3StbyFreq = newValue;
        if (d_com3Avail)
            emit com3StbyFreqChanged();
    }

    void updateNav1Avail(bool newValue)
    {
        d_nav1Avail = newValue;
        emit nav1AvailChanged();
    }

    void updateNav2Avail(bool newValue)
    {
        d_nav2Avail = newValue;
        emit nav2AvailChanged();
    }

    void updateNav1Freq(float newValue)
    {
        d_nav1Freq = newValue;
        if (d_nav1Avail)
            emit nav1FreqChanged();
    }

    void updateNav2Freq(float newValue)
    {
        d_nav2Freq = newValue;
        if (d_nav2Avail)
            emit nav2FreqChanged();
    }

    void updateNav1StbyFreq(float newValue)
    {
        d_nav1StbyFreq = newValue;
        if (d_nav1Avail)
            emit nav1FreqChanged();
    }

    void updateNav2StbyFreq(float newValue)
    {
        d_nav2StbyFreq = newValue;
        if (d_nav2Avail)
            emit nav2StbyFreqChanged();
    }

    void updateXprdCode(int newValue)
    {
        d_xpdrCode = newValue;
        emit xpdrCodeChanged();
    }

    void updateXpdrState(TransponderState newValue)
    {
        d_xpdrState = newValue;
        emit xpdrStateChanged();
    }

private:

    bool d_com1Avail = false;
    bool d_com2Avail = false;
    bool d_com3Avail = false;
    float d_com1Freq = 0;
    float d_com2Freq = 0;
    float d_com3Freq = 0;
    float d_com1StbyFreq = 0;
    float d_com2StbyFreq = 0;
    float d_com3StbyFreq = 0;

    bool d_nav1Avail = false;
    bool d_nav2Avail = false;
    float d_nav1Freq = 0;
    float d_nav2Freq = 0;
    float d_nav1StbyFreq = 0;
    float d_nav2StbyFreq = 0;

    int d_xpdrCode = 7000;
    TransponderState d_xpdrState = TransponderState::OFF;
};

}  // namespace pages::tsc

#endif  // __NAV_COM_HPP__