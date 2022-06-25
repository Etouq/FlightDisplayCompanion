#ifndef __SPEEDBUGS_HPP__
#define __SPEEDBUGS_HPP__

#include <QObject>
#include <QList>
#include <QSet>
#include "common/definitions/baseTypes.hpp"

namespace pages::tsc
{

class SpeedBugs : public QObject
{
    Q_OBJECT


public:

    explicit SpeedBugs(QObject *parent = nullptr) : QObject(parent) {}

    void setSpeedbugs(const QList<definitions::ReferenceSpeed> &speedBugs)
    {
        d_speedBugs = speedBugs;
        d_activeSpeedBugIds.clear();
        emit speedBugsChanged();
        emit activeSpeedBugsChanged();
    }

    Q_INVOKABLE QString designator(int idx) const
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

        emit speedBugsChanged();

        if (d_activeSpeedBugIds.contains(idx))
            emit activeSpeedBugsChanged();

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

        emit speedBugsChanged();
        emit activeSpeedBugsChanged();
    }

    Q_INVOKABLE void toggleActive(int idx)
    {
        if (d_activeSpeedBugIds.contains(idx))
        {
            d_activeSpeedBugIds.remove(idx);
        }
        else
        {
            d_activeSpeedBugIds.insert(idx);
        }

        emit speedBugsChanged();
        emit activeSpeedBugsChanged();
    }

    Q_INVOKABLE void newSpeedBug(const QString &designator, uint16_t speed)
    {
        d_speedBugs.append({ speed, designator });
        emit speedBugsChanged();
    }
    Q_INVOKABLE void removeSpeedBug(int idx)
    {
        d_speedBugs.removeAt(idx);

        QList<int> activeIds(d_activeSpeedBugIds.constBegin(), d_activeSpeedBugIds.constEnd());

        d_activeSpeedBugIds.clear();

        for (int index : activeIds)
        {
            if (index < idx)
                d_activeSpeedBugIds.insert(index);
            else if (index > idx)
                d_activeSpeedBugIds.insert(index - 1);

        }

        emit speedBugsChanged();
        emit activeSpeedBugsChanged();
    }

    Q_INVOKABLE QList<int> getActiveIds() const
    {
        return QList<int>(d_activeSpeedBugIds.constBegin(), d_activeSpeedBugIds.constEnd());
    }

    Q_INVOKABLE int numSpeedbugs() const
    {
        return d_speedBugs.size();
    }

signals:

    void speedBugsChanged();
    void activeSpeedBugsChanged();

private:

    QList<definitions::ReferenceSpeed> d_speedBugs = { { 85, "R" }, { 100, "X" }, { 124, "Y" }, { 85, "AP" } };
    QSet<int> d_activeSpeedBugIds;
};

}  // namespace pages::tsc


#endif  // __SPEEDBUGS_HPP__
