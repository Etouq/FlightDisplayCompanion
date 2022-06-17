#ifndef __RADIOINFO_HPP__
#define __RADIOINFO_HPP__

#include <QObject>

namespace io::network
{
class NetworkClient;
}

namespace pages::pfd
{

class RadioInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool com1Avail READ com1Avail NOTIFY com1AvailChanged)
    Q_PROPERTY(bool com2Avail READ com2Avail NOTIFY com2AvailChanged)
    Q_PROPERTY(bool com3Avail READ com3Avail NOTIFY com3AvailChanged)
    Q_PROPERTY(float com1Freq READ com1Freq NOTIFY com1FreqChanged)
    Q_PROPERTY(float com2Freq READ com2Freq NOTIFY com2FreqChanged)
    Q_PROPERTY(float com3Freq READ com3Freq NOTIFY com3FreqChanged)

    Q_PROPERTY(bool nav1Avail READ nav1Avail NOTIFY nav1AvailChanged)
    Q_PROPERTY(bool nav2Avail READ nav2Avail NOTIFY nav2AvailChanged)
    Q_PROPERTY(float nav1Freq READ nav1Freq NOTIFY nav1FreqChanged)
    Q_PROPERTY(float nav2Freq READ nav2Freq NOTIFY nav2FreqChanged)

public:

    explicit RadioInfo(io::network::NetworkClient *netClient, QObject *parent = nullptr);

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

signals:

    void com1AvailChanged();
    void com2AvailChanged();
    void com3AvailChanged();
    void com1FreqChanged();
    void com2FreqChanged();
    void com3FreqChanged();

    void nav1AvailChanged();
    void nav2AvailChanged();
    void nav1FreqChanged();
    void nav2FreqChanged();

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

private:

    bool d_com1Avail = false;
    bool d_com2Avail = false;
    bool d_com3Avail = false;
    float d_com1Freq = 0;
    float d_com2Freq = 0;
    float d_com3Freq = 0;

    bool d_nav1Avail = false;
    bool d_nav2Avail = false;
    float d_nav1Freq = 0;
    float d_nav2Freq = 0;
};

}  // namespace pages::pfd


#endif  // __RADIOINFO_HPP__