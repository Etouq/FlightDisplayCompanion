#include "radioinfobackend.h"

RadioInfoBackend::RadioInfoBackend(QObject *parent) : QObject(parent)
{
}

bool RadioInfoBackend::hasComm1() const
{
    return d_hasComm1;
}

bool RadioInfoBackend::hasComm2() const
{
    return d_hasComm2;
}

float RadioInfoBackend::comm1Freq() const
{
    return d_comm1Freq;
}

float RadioInfoBackend::comm2Freq() const
{
    return d_comm2Freq;
}

bool RadioInfoBackend::hasNav1() const
{
    return d_hasNav1;
}

bool RadioInfoBackend::hasNav2() const
{
    return d_hasNav2;
}

float RadioInfoBackend::nav1Freq() const
{
    return d_nav1Freq;
}

float RadioInfoBackend::nav2Freq() const
{
    return d_nav2Freq;
}

void RadioInfoBackend::updateComm1State(bool newValue)
{
    if (newValue != d_hasComm1)
    {
        d_hasComm1 = newValue;
        emit hasComm1Changed();
    }
}

void RadioInfoBackend::updateComm2State(bool newValue)
{
    if (newValue != d_hasComm2)
    {
        d_hasComm2 = newValue;
        emit hasComm2Changed();
    }
}

void RadioInfoBackend::updateComm1Freq(float newValue)
{
    d_comm1Freq = newValue;
    if (d_hasComm1)
        emit comm1FreqChanged();
}

void RadioInfoBackend::updateComm2Freq(float newValue)
{
    d_comm2Freq = newValue;
    if (d_hasComm2)
        emit comm2FreqChanged();
}


void RadioInfoBackend::updateNav1State(bool newValue)
{
    if (newValue != d_hasNav1)
    {
        d_hasNav1 = newValue;
        emit hasNav1Changed();
    }
}

void RadioInfoBackend::updateNav2State(bool newValue)
{
    if (newValue != d_hasNav2)
    {
        d_hasNav2 = newValue;
        emit hasNav2Changed();
    }
}

void RadioInfoBackend::updateNav1Freq(float newValue)
{
    d_nav1Freq = newValue;
    if (d_hasNav1)
        emit nav1FreqChanged();
}

void RadioInfoBackend::updateNav2Freq(float newValue)
{
    d_nav2Freq = newValue;
    if (d_hasNav2)
        emit nav2FreqChanged();
}
