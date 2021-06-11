#include "miscedbase.h"
#include <cmath>
#include <algorithm>
using namespace std;

double MiscEDBase::fuelRange() const
{
    return d_fuelRange;
}

MiscEDBase::MiscEDBase(QObject *parent) : QObject(parent)
{

}



void MiscEDBase::setParameters(bool hasApu, bool hasEgt, bool hasFlaps, bool hasSpoilers, bool hasElevatorTrim, bool hasAileronTrim, bool hasRudderTrim)
{
    d_hasApu = hasApu;
    d_hasEgt = hasEgt;
    d_hasFlaps = hasFlaps;
    d_hasSpoilers = hasSpoilers;
    d_hasElevatorTrim = hasElevatorTrim;
    d_hasAileronTrim = hasAileronTrim;
    d_hasRudderTrim = hasRudderTrim;

    emit redrawNeeded();

    double totalFuelflow = 0;
    double totalFuelQty = 0;
    double groundSpeed = 0;
    QString newFuelTime;
    QString newFuelRange;

    if(totalFuelflow <= 0)
    {
        newFuelTime = "--:--";
        newFuelRange = "__._NM";
        if (newFuelTime != d_fuelTimeText)
        {
            d_fuelTimeText = newFuelTime;
            emit fuelTimeTextChanged();
        }
        if(newFuelRange != d_fuelRangeText)
        {
            d_fuelRangeText = newFuelRange;
            emit fuelRangeTextChanged();
        }
    }
    else
    {
        double doubleTime = totalFuelQty / totalFuelflow;
        newFuelTime = QString("%1:%2").arg(static_cast<int>(doubleTime), 2, 10, QChar('0')).arg(static_cast<int>((doubleTime - static_cast<int>(doubleTime)) * 60.0), 2, 10, QChar('0'));
        if (newFuelTime != d_fuelTimeText)
        {
            d_fuelTimeText = newFuelTime;
            emit fuelTimeTextChanged();
        }

        if (groundSpeed <= 0)
        {
            newFuelRange = "__._NM";
            if(newFuelRange != d_fuelRangeText)
            {
                d_fuelRangeText = newFuelRange;
                emit fuelRangeTextChanged();
            }
        }
        else
        {
            double fuelRange = doubleTime * groundSpeed;
            newFuelRange = QString("%1NM").arg(fuelRange, 0, 'f', fuelRange >= 100 ? 0 : fuelRange >= 10 ? 1 : 2);
            if(newFuelRange != d_fuelRangeText)
            {
                d_fuelRangeText = newFuelRange;
                emit fuelRangeTextChanged();
            }
        }

    }



}


void MiscEDBase::updateFuelText(double totalFuelflow, double totalFuelQty, double groundSpeed)
{
    QString newFuelTime;
    QString newFuelRange;

    d_smoothedSpeed = 0.9 * d_smoothedSpeed + 0.1 * groundSpeed;
    d_smoothedFF = 0.9 * d_smoothedFF + 0.1 * totalFuelflow;

    if(d_smoothedFF <= 0.1)
    {
        newFuelTime = "--:--";
        newFuelRange = "__._NM";
        if (newFuelTime != d_fuelTimeText)
        {
            d_fuelTimeText = newFuelTime;
            emit fuelTimeTextChanged();
        }
        if(newFuelRange != d_fuelRangeText)
        {
            d_fuelRange = -1;
            d_fuelRangeText = newFuelRange;
            emit fuelRangeTextChanged();
            emit fuelRangeChanged();
        }
        return;
    }

    double doubleTime = totalFuelQty / d_smoothedFF;
    newFuelTime = QString("%1:%2").arg(static_cast<int>(doubleTime), 2, 10, QChar('0')).arg(static_cast<int>((doubleTime - static_cast<int>(doubleTime)) * 60.0), 2, 10, QChar('0'));
    if (newFuelTime != d_fuelTimeText)
    {
        d_fuelTimeText = newFuelTime;
        emit fuelTimeTextChanged();
    }

    if (d_smoothedSpeed <= 0.1)
    {
        newFuelRange = "__._NM";
        if(newFuelRange != d_fuelRangeText)
        {
            d_fuelRange = -1;
            d_fuelRangeText = newFuelRange;
            emit fuelRangeTextChanged();
            emit fuelRangeChanged();
        }
        return;
    }
    double fuelRangeVal = doubleTime * d_smoothedSpeed;
    newFuelRange = QString("%1NM").arg(fuelRangeVal, 0, 'f', fuelRangeVal >= 100 ? 0 : fuelRangeVal >= 10 ? 1 : 2);
    if(newFuelRange != d_fuelRangeText)
    {
        d_fuelRange = fuelRangeVal;
        d_fuelRangeText = newFuelRange;
        emit fuelRangeTextChanged();
        emit fuelRangeChanged();
    }
}

void MiscEDBase::updateApuRpm(int newVal)
{
    if(d_hasApu)
    {
        QString newApuRpm = QString::number(newVal) + "%";
        if(newApuRpm != d_apuRpmText)
        {
            d_apuRpmText = newApuRpm;
            emit apuRpmTextChanged();
        }
    }
}


void MiscEDBase::updateSpoilers(double newVal)
{
    if(d_hasSpoilers)
    {
        d_spoilersAngle = (newVal) * d_spoilersMaxAngle;
        emit spoilersAngleChanged();
        int pctValue = lround(newVal * 100.0);
        bool newShowSpoilersText = pctValue > 0;
        if(d_showSpoilersText != newShowSpoilersText)
        {
            d_showSpoilersText = newShowSpoilersText;
            emit showSpoilersTextChanged();
        }
        if (d_showSpoilersText)
        {
            d_spoilersValue = QString::number(pctValue) + "%";
            emit spoilersValueChanged();
        }
    }
}

void MiscEDBase::updateFlaps(double newVal)
{
    if(d_hasFlaps)
    {
        d_flapsAngle = newVal;
        emit flapsAngleChanged();
        int roundedAngle = lround(newVal);
        bool newShowFlapsText = roundedAngle != 0;
        if(d_showFlapsText != newShowFlapsText)
        {
            d_showFlapsText = newShowFlapsText;
            emit showFlapsTextChanged();
        }
        if(d_showFlapsText)
        {
            QString newFlapsValue = QString::number(roundedAngle) + "º";
            if(d_flapsValue != newFlapsValue)
            {
                d_flapsValue = newFlapsValue;
                emit flapsValueChanged();
            }
        }
    }
}


void MiscEDBase::updateElevTrim(double newVal)
{
    d_elevTrimTransformValue = newVal * 60.0;
    emit elevTrimTransformValueChanged();
}

void MiscEDBase::updateAileronTrim(double newVal)
{
    if(d_hasAileronTrim)
    {
        d_aileronTrimTransformValue = newVal * 60.0;
        emit aileronTrimTransformValueChanged();
    }
}

void MiscEDBase::updateRudderTrim(double newVal)
{
    if(d_hasRudderTrim)
    {
        d_rudderTrimTransformValue = newVal * 60.0;
        emit rudderTrimTransformValueChanged();
    }
}



bool MiscEDBase::getHasApu() const
{
    return d_hasApu;
}
bool MiscEDBase::getHasEgt() const
{
    return d_hasEgt;
}
bool MiscEDBase::getHasSpoilers() const
{
    return d_hasSpoilers;
}
bool MiscEDBase::getHasFlaps() const
{
    return d_hasFlaps;
}
bool MiscEDBase::getHasElevatorTrim() const
{
    return d_hasElevatorTrim;
}
bool MiscEDBase::getHasAileronTrim() const
{
    return d_hasAileronTrim;
}
bool MiscEDBase::getHasRudderTrim() const
{
    return d_hasRudderTrim;
}

const QString& MiscEDBase::fuelRangeText() const
{
    return d_fuelRangeText;
}
const QString& MiscEDBase::fuelTimeText() const
{
    return d_fuelTimeText;
}
const QString& MiscEDBase::apuRpmText() const
{
    return d_apuRpmText;
}

double MiscEDBase::spoilersAngle() const
{
    return d_spoilersAngle;
}
const QString& MiscEDBase::spoilersValue() const
{
    return d_spoilersValue;
}
bool MiscEDBase::showSpoilersText() const
{
    return d_showSpoilersText;
}
double MiscEDBase::flapsAngle() const
{
    return d_flapsAngle;
}
const QString& MiscEDBase::flapsValue() const
{
    return d_flapsValue;
}
bool MiscEDBase::showFlapsText() const
{
    return d_showFlapsText;
}

double MiscEDBase::elevTrimTransformValue() const
{
    return d_elevTrimTransformValue;
}
double MiscEDBase::aileronTrimTransformValue() const
{
    return d_aileronTrimTransformValue;
}
double MiscEDBase::rudderTrimTransformValue() const
{
    return d_rudderTrimTransformValue;
}



