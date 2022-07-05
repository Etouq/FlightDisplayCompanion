#ifndef __SPEED_BUG_ENTRY_HPP__
#define __SPEED_BUG_ENTRY_HPP__


#include <QObject>
#include "common/definitions/baseTypes.hpp"

namespace pages::tsc
{

class SpeedBugEntry : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged)


public:

    SpeedBugEntry(const definitions::ReferenceSpeed &refSpeed)
      : QObject(nullptr),
        d_designator(refSpeed.designator),
        d_speed(refSpeed.speed)
    {
    }

    SpeedBugEntry(const QString &designator)
    : QObject(nullptr),
      d_designator(designator)
    {
    }

    operator definitions::ReferenceSpeed() const
    {
        return { static_cast<uint16_t>(d_speed), d_designator };
    }

    Q_INVOKABLE QString designator() const
    {
        return d_designator;
    }

    bool active() const
    {
        return d_active;
    }

    int speed() const
    {
        return d_speed;
    }

    void setActive(bool active)
    {
        d_active = active;
        emit activeChanged();
    }
    void toggleActive()
    {
        d_active = !d_active;
        emit activeChanged();
    }

    void setSpeed(int speed)
    {
        d_speed = speed;
        emit speedChanged();
    }

signals:

    void activeChanged();
    void speedChanged();

private:

    const QString d_designator;
    bool d_active = false;
    int d_speed = 85;


};

}  // namespace pages::tsc

#endif  // __SPEED_BUG_ENTRY_HPP__
