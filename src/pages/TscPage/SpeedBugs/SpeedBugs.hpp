#ifndef __SPEEDBUGS_HPP__
#define __SPEEDBUGS_HPP__

#include <QObject>
#include <QList>
#include <QSet>
#include "common/definitions/baseTypes.hpp"

namespace io::network
{
class NetworkClient;
}

namespace pages::tsc
{

class SpeedBugs : public QObject
{
    Q_OBJECT


public:

    explicit SpeedBugs(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE const QString &designator(int idx) const
    {
        return d_speedBugs.at(idx).designator;
    }

    Q_INVOKABLE int speed(int idx) const
    {
        return d_speedBugs.at(idx).speed;
    }

    Q_INVOKABLE void setSpeed(int idx, int newSpeed)
    {
        d_speedBugs[idx].speed = newSpeed;
    }

    Q_INVOKABLE bool active(int idx) const
    {
        return d_activeSpeedBugIds.contains(idx);
    }

    Q_INVOKABLE void setActive(int idx, bool newActive)
    {
        if (newActive)
        {
            d_activeSpeedBugIds.insert(idx);
        }
        else
        {
            d_activeSpeedBugIds.remove(idx);
        }

        emit activeSpeedBugsChanged();
    }

    Q_INVOKABLE void newSpeedBug(const QString &designator, uint16_t speed)
    {
        d_speedBugs.append({ speed, designator });
        emit speedBugsChanged();
    }

    Q_INVOKABLE QList<int> getActiveIds() const
    {
        return QList<int>(d_activeSpeedBugIds.constBegin(), d_activeSpeedBugIds.constEnd());
    }

signals:

    void speedBugsChanged();
    void activeSpeedBugsChanged();

private:

    QList<definitions::ReferenceSpeed> d_speedBugs;
    QSet<int> d_activeSpeedBugIds;
};

}  // namespace pages::tsc


#endif  // __SPEEDBUGS_HPP__