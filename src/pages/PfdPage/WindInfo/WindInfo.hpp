#ifndef __WIND_INFO_HPP__
#define __WIND_INFO_HPP__

#include "io/NetworkClient/NetworkClient.hpp"

#include <QObject>

namespace pages::pfd
{

class WindInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double windDirection READ windDirection NOTIFY windDirectionChanged)
    Q_PROPERTY(double windStrength READ windStrength NOTIFY windStrengthChanged)
    Q_PROPERTY(double windTrueDirection READ windTrueDirection NOTIFY windTrueDirectionChanged)

public:

    explicit WindInfo(io::network::NetworkClient *netClient, QObject *parent)
      : QObject(parent)
    {
        using io::network::NetworkClient;
        connect(netClient, &NetworkClient::windDirectionChanged, this, &WindInfo::updateWindDirection);
        connect(netClient, &NetworkClient::windStrengthChanged, this, &WindInfo::updateWindStrength);
        connect(netClient, &NetworkClient::windTrueDirectionChanged, this, &WindInfo::updateWindTrueDirection);
    }

    double windDirection() const
    {
        return d_windDirection;
    }

    double windStrength() const
    {
        return d_windStrength;
    }

    double windTrueDirection() const
    {
        return d_windTrueDirection;
    }

signals:

    void windDirectionChanged();
    void windStrengthChanged();
    void windTrueDirectionChanged();

public slots:

    void updateWindDirection(double newValue)
    {
        d_windDirection = newValue;
        emit windDirectionChanged();
    }

    void updateWindStrength(double newValue)
    {
        d_windStrength = newValue;
        emit windStrengthChanged();
    }

    void updateWindTrueDirection(double newValue)
    {
        d_windTrueDirection = newValue;
        emit windTrueDirectionChanged();
    }

private:

    double d_windDirection = 0;
    double d_windStrength = 0;
    double d_windTrueDirection = 0;
};

}  // namespace pages::pfd

#endif  // __WIND_INFO_HPP__