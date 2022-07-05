#ifndef __SPEEDBUGS_HPP__
#define __SPEEDBUGS_HPP__

#include "SpeedBugEntry.hpp"
#include "common/definitions/baseTypes.hpp"

#include <QList>
#include <QObject>
#include <QQmlEngine>
#include <QSet>


namespace pages::tsc
{

class SpeedBugs : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int numSpeedbugs READ numSpeedbugs NOTIFY numSpeedbugsChanged)
    Q_PROPERTY(int numActiveSpeedbugs READ numActiveSpeedbugs NOTIFY numActiveSpeedbugsChanged)


public:

    explicit SpeedBugs(QObject *parent = nullptr)
      : QObject(parent)
    {
        fillSpeedbugs(d_speedBugsDefaults);
    }

    ~SpeedBugs()
    {
        d_activeSpeedBugs.clear();
        clearSpeedBugs();
    }

    Q_INVOKABLE void storeSpeedbugsAsDefaults()
    {
        QList<definitions::ReferenceSpeed> newDefaults;
        for (const SpeedBugEntry *entry : d_speedBugs)
        {
            newDefaults.append(*entry);
        }
        emit updateSpeedbugsDefaults(newDefaults);
    }

    Q_INVOKABLE void restoreDefaults()
    {
        fillSpeedbugs(d_speedBugsDefaults);
        d_activeSpeedBugs.clear();

        emit numSpeedbugsChanged();
        emit numActiveSpeedbugsChanged();
    }

    void setSpeedbugs(const QList<definitions::ReferenceSpeed> &speedBugs)
    {
        fillSpeedbugs(speedBugs);
        d_speedBugsDefaults = speedBugs;
        d_activeSpeedBugs.clear();

        emit numSpeedbugsChanged();
        emit numActiveSpeedbugsChanged();
    }

    Q_INVOKABLE SpeedBugEntry *speedBugAt(int idx)
    {
        return d_speedBugs[idx];
    }
    Q_INVOKABLE SpeedBugEntry *activeSpeedBugAt(int idx)
    {
        return d_activeSpeedBugs.at(idx);
    }

    Q_INVOKABLE QString designator(int idx) const
    {
        return d_speedBugs.at(idx)->designator();
    }

    Q_INVOKABLE int speed(int idx) const
    {
        return d_speedBugs.at(idx)->speed();
    }

    Q_INVOKABLE void setSpeed(int idx, int newSpeed)
    {
        d_speedBugs.at(idx)->setSpeed(newSpeed);
    }

    Q_INVOKABLE bool active(int idx) const
    {
        return d_speedBugs.at(idx)->active();
    }

    Q_INVOKABLE void toggleActive(int idx)
    {
        SpeedBugEntry *speedBug = d_speedBugs.at(idx);
        if (speedBug->active())
        {
            d_activeSpeedBugs.removeOne(speedBug);
            speedBug->setActive(false);
        }
        else
        {
            d_activeSpeedBugs.append(speedBug);
            speedBug->setActive(true);
        }

        emit numActiveSpeedbugsChanged();
    }

    Q_INVOKABLE void newSpeedBug(const QString &designator)
    {
        SpeedBugEntry *newBug = new SpeedBugEntry(designator);
        QQmlEngine::setObjectOwnership(newBug, QQmlEngine::CppOwnership);

        d_speedBugs.append(newBug);

        emit numSpeedbugsChanged();
    }

    Q_INVOKABLE void removeSpeedBug(int idx)
    {
        SpeedBugEntry *speedBug = d_speedBugs.at(idx);
        if (speedBug->active()) {
            d_activeSpeedBugs.removeAt(idx);
            emit numActiveSpeedbugsChanged();
        }

        d_speedBugs.removeAt(idx);

        emit numSpeedbugsChanged();

        delete speedBug;
    }

    int numSpeedbugs() const
    {
        return d_speedBugs.size();
    }

    int numActiveSpeedbugs() const
    {
        return d_activeSpeedBugs.size();
    }

signals:

    void numSpeedbugsChanged();
    void numActiveSpeedbugsChanged();

    void updateSpeedbugsDefaults(const QList<definitions::ReferenceSpeed> &newDefaults);

private:

    void clearSpeedBugs()
    {
        for (SpeedBugEntry *entry : d_speedBugs)
            delete entry;

        d_speedBugs.clear();
    }

    void fillSpeedbugs(const QList<definitions::ReferenceSpeed> &speedBugs)
    {
        clearSpeedBugs();

        for (const definitions::ReferenceSpeed &entry : speedBugs)
        {
            SpeedBugEntry *newBug = new SpeedBugEntry(entry);
            QQmlEngine::setObjectOwnership(newBug, QQmlEngine::CppOwnership);
            d_speedBugs.append(newBug);
        }
    }

    QList<SpeedBugEntry *> d_speedBugs;
    QList<definitions::ReferenceSpeed> d_speedBugsDefaults = { { 85, "r" }, { 100, "x" }, { 124, "y" }, { 85, "ap" } };
    QList<SpeedBugEntry *> d_activeSpeedBugs;
};

}  // namespace pages::tsc


#endif  // __SPEEDBUGS_HPP__
