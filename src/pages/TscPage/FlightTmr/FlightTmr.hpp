#ifndef __FLIGHT_TMR_HPP__
#define __FLIGHT_TMR_HPP__

#include <chrono>
#include <QObject>
#include <QString>
#include <QTimer>


namespace pages::tsc
{

class FlightTmr : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString timeString READ timeString NOTIFY timeStringChanged)
    Q_PROPERTY(bool countingDown READ countingDown WRITE setCountingDown NOTIFY countingDownChanged)
    Q_PROPERTY(bool running READ running NOTIFY runningChanged)

public:

    explicit FlightTmr(QObject *parent = nullptr)
      : QObject(parent)
    {
        // set interval too fast to account for 5% interval inaccuracy in QTimer (so we don't miss an update one second
        // because we are a little too early)
        d_timer.setInterval(200);
        connect(&d_timer, &QTimer::timeout, this, &FlightTmr::update);
    }

    void setCountingDown(bool down)
    {
        if (d_countingDown != down)
        {
            d_countingDown = down;
            d_currentValue = -d_currentValue;
            d_lastStartValue = d_currentValue;
            emit countingDownChanged();
        }
    }

    Q_INVOKABLE int getCurrentValue() const
    {
        return std::abs(d_currentValue);
    }

    Q_INVOKABLE void setTime(int value)
    {
        d_inputTime = d_countingDown ? -value : value;
        d_currentValue = d_inputTime;

        if (d_running)
        {
            d_lastStartValue = d_inputTime;
            update();
        }
        else
            updateTimeString(std::abs(d_inputTime) / 1000);
    }

    const QString &timeString() const
    {
        return d_timeString;
    }

    bool countingDown() const
    {
        return d_countingDown;
    }

    bool running() const
    {
        return d_running;
    }

    Q_INVOKABLE void start()
    {
        d_running = true;
        emit runningChanged();

        // reset last measured time so it doesn't include any paused time
        d_lastStartTime = std::chrono::steady_clock::now();
        d_lastStartValue = d_currentValue;

        // start on next whole 200ms portion to align update timer with when next second occurs (+5% inaccuracy)
        QTimer::singleShot(std::abs((d_currentValue + 10) % 200), this, &FlightTmr::startTimer);
    }

    // called when the timer has been offscreen but not paused/stopped
    Q_INVOKABLE void movedOnscreen()
    {
        if (d_onscreen)
            return;
        d_onscreen = true;

        if (d_running)
        {
            // start on next whole 200ms portion to align update timer with when next second occurs (+5% inaccuracy)
            QTimer::singleShot(std::abs((d_currentValue + 10) % 200), this, &FlightTmr::startTimer);

            update();  // just make sure we update right away for up to date ui
        }
    }

    // called when the timer is moved offscreen so we don't update the timer when it's not visible
    Q_INVOKABLE void movedOffscreen()
    {
        d_onscreen = false;
        d_timer.stop();
    }

    // called when user explicitly presses stop
    Q_INVOKABLE void stop()
    {
        d_running = false;
        emit runningChanged();
        d_timer.stop();

        update();  // deal with partial seconds (for when some smartass keeps pushing start and stop quickly)
    }

    Q_INVOKABLE void reset()
    {
        d_currentValue = d_inputTime;
        d_lastStartValue = d_inputTime;

        if (d_currentValue < 0 && !d_countingDown)
        {
            d_countingDown = true;
            emit countingDownChanged();
        }

        updateTimeString(std::abs(d_inputTime) / 1000);
    }

signals:

    void timeStringChanged();
    void countingDownChanged();
    void runningChanged();

private slots:

    void update();

    void startTimer()
    {
        if (d_running && d_onscreen)
        {
            d_timer.start();
            update();
        }
    }

private:

    void updateTimeString(uint64_t seconds)
    {
        const uint64_t hours = seconds / 3600;
        seconds -= hours * 3600;
        const uint64_t mins = seconds / 60;
        seconds -= mins * 60;

        QString timeStr = QString("%1:%2:%3")
                            .arg(hours, 2, 10, QChar('0'))
                            .arg(mins, 2, 10, QChar('0'))
                            .arg(seconds, 2, 10, QChar('0'));


        if (d_timeString != timeStr)
        {
            d_timeString = timeStr;
            emit timeStringChanged();
        }
    }

    int64_t d_inputTime = 0;  // originally input time, negative for counting down, positive for counting up

    // used to measure time since timer was last started to account for inaccuracies
    std::chrono::time_point<std::chrono::steady_clock> d_lastStartTime;
    int64_t d_lastStartValue = 0;  // number of ms on the clock when we last clicked start

    int64_t d_currentValue = 0;  // number of ms, negative for counting down, positive for counting up

    QTimer d_timer;

    QString d_timeString = "00:00:00";
    bool d_countingDown = false;

    bool d_running = false;
    bool d_onscreen = false;
};

}  // namespace pages::tsc

#endif  // __FLIGHT_TMR_HPP__
