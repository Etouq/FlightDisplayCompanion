#include "tscpagebackend.h"

#include <chrono>

QString TscPageBackend::timeString() const
{
    return d_timeString;
}

void TscPageBackend::setCountingDown(bool state)
{
    int currTime = duration_cast<std::chrono::milliseconds>(
                     std::chrono::system_clock::now().time_since_epoch())
                     .count();

    if (d_isCounting)
    {
        d_baseTime = d_isCountingDown ? d_baseTime + d_beginTime - currTime
                                      : d_baseTime - d_beginTime + currTime;
        d_beginTime = currTime;
    }

    d_isCountingDown = state;

    emit isCountingDownChanged();
}

void TscPageBackend::switchCounting()
{
    int currTime = duration_cast<std::chrono::milliseconds>(
                     std::chrono::system_clock::now().time_since_epoch())
                     .count();
    d_isCounting = !d_isCounting;

    if (d_isCounting)
        d_beginTime = currTime;
    else
        d_baseTime = d_isCountingDown ? d_baseTime + d_beginTime - currTime
                                      : d_baseTime - d_beginTime + currTime;

    emit isCountingChanged();
}

void TscPageBackend::reset()
{
    if (d_isCounting)
        switchCounting();

    d_baseTime = d_isCountingDown ? d_initialValue : 0;

    updateTime();
}

void TscPageBackend::endKeyboardCallback(int time)
{
    d_baseTime = time;
    d_beginTime = duration_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now().time_since_epoch())
                    .count();
    d_initialValue = time;

    updateTime();
}

void TscPageBackend::updateTime()
{
    int time = getCurrentDisplay();

    QString newTime = QString("%1:%2:%3")
                        .arg((time / 3600000) % 24, 2, 10, QChar('0'))
                        .arg((time / 60000) % 60, 2, 10, QChar('0'))
                        .arg((time / 1000) % 60, 2, 10, QChar('0'));

    if (d_timeString != newTime)
    {
        d_timeString = newTime;
        emit timeStringChanged();
    }
}

int TscPageBackend::getCurrentDisplay()
{
    if (!d_isCounting)
        return d_baseTime;

    int currTime = duration_cast<std::chrono::milliseconds>(
                     std::chrono::system_clock::now().time_since_epoch())
                     .count();

    if (d_isCountingDown && d_baseTime + d_beginTime - currTime <= 0)
    {
        setCountingDown(false);
        d_baseTime = 0;
        d_beginTime = currTime;
    }

    if (!d_isCountingDown && d_baseTime - d_beginTime + currTime >= 86400000)
    {
        d_baseTime = 0;
        d_beginTime = currTime;
    }

    return d_isCountingDown ? d_baseTime + d_beginTime - currTime
                            : d_baseTime - d_beginTime + currTime;
}
