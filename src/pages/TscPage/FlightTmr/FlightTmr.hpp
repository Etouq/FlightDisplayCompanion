#ifndef __FLIGHT_TMR_HPP__
#define __FLIGHT_TMR_HPP__

#include <chrono>
#include <QObject>
#include <QString>
#include <QTimer>
#include <qtimer.h>


namespace pages::tsc
{

class FlightTmr : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString timeString READ timeString NOTIFY timeStringChanged)
    Q_PROPERTY(bool countingDown READ countingDown WRITE setCountingDown NOTIFY countingDownChanged)

public:

    explicit FlightTmr(QObject *parent = nullptr)
      : QObject(parent)
    {
        d_timer.setInterval(1000);
        connect(&d_timer, &QTimer::interval, this, &FlightTmr::update);
    }

    void setCountingDown(bool down)
    {
        if (d_countingDown != down)
        {
            d_countingDown = down;
            d_currentValue = -d_currentValue;
            emit countingDownChanged();
        }
    }

    const QString &timeString() const
    {
        return d_timeString;
    }

    bool countingDown() const
    {
        return d_countingDown;
    }

    Q_INVOKABLE void start()
    {
        // reset last measured time so it doesn't include any paused time
        d_lastMeasuredTime =
          duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();

        // start on the next whole second
        QTimer::singleShot(std::abs(d_currentValue % 1000), &d_timer, qOverload<>(&QTimer::start));
        QTimer::singleShot(std::abs(d_currentValue % 1000), this, &FlightTmr::update);
    }

    // for when the timer has been offscreen but not paused/stopped
    Q_INVOKABLE void startWithoutTimerReset()
    {
        // start on the next whole second
        QTimer::singleShot(std::abs(d_currentValue % 1000), &d_timer, qOverload<>(&QTimer::start));
        QTimer::singleShot(std::abs(d_currentValue % 1000), this, &FlightTmr::update);
    }

    // for when the timer is only moved offscreen (used so we don't update the timer unnecessarily)
    Q_INVOKABLE void stopWithoutTimerReset()
    {
        d_timer.stop();
    }

    Q_INVOKABLE void stop()
    {
        d_timer.stop();

        update(); // to deal with fractional seconds etc
    }

    Q_INVOKABLE void reset()
    {
        d_currentValue = d_inputTime;

        if (d_currentValue < 0 && !d_countingDown)
        {
            d_countingDown = true;
            emit countingDownChanged();
        }
    }

signals:

    void timeStringChanged();
    void countingDownChanged();

private slots:

    void update();

private:

    int d_baseTime = 0;   // number of seconds entered
    int d_beginTime = 0;  // time when counting started
    int d_initialValue = 0;

    int64_t d_inputTime = 0;  // originally input time, negative for counting down, positive for counting up

    int64_t d_lastMeasuredTime = 0;  // used to measure elapsed time to account for inaccuracy in QTimer

    int64_t d_currentValue = 0;  // number of ms, negative for counting down, positive for counting up

    QTimer d_timer;

    QString d_timeString = "00:00:00";
    bool d_countingDown = false;
};

}  // namespace pages::tsc

#endif  // __FLIGHT_TMR_HPP__