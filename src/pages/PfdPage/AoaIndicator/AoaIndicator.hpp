#ifndef __AOAINDICATOR_HPP__
#define __AOAINDICATOR_HPP__

#include "io/NetworkClient/NetworkClient.hpp"

#include <QColor>
#include <QObject>

namespace pages::pfd
{

class AoaIndicator : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double aoaAngle READ aoaAngle NOTIFY aoaAngleChanged)
    Q_PROPERTY(QColor cursorColor READ cursorColor NOTIFY cursorColorChanged)

public:

    explicit AoaIndicator(io::network::NetworkClient *netClient, QObject *parent = nullptr)
      : QObject(parent)
    {
        connect(netClient, &io::network::NetworkClient::angleOfAttackChanged, this, &AoaIndicator::updateAoa);
    }

    double aoaAngle() const
    {
        return d_aoaAngle;
    }

    const QColor &cursorColor() const
    {
        return d_cursorColor;
    }

signals:

    void aoaAngleChanged();
    void cursorColorChanged();

public slots:
    void updateAoa(double newValue);

private:

    // exposed items
    double d_aoaAngle = 50;
    QColor d_cursorColor = "white";

    // internal items
    static constexpr double d_redPercent = 17;
};

}  // namespace pages::pfd

#endif  // __AOAINDICATOR_HPP__