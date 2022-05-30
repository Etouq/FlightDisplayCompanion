#include "hsindicatorbearingsbackend.hpp"

#include <cmath>

HSIndicatorBearingsBackend::HSIndicatorBearingsBackend(QObject *parent) : QObject(parent)
{
}



QString HSIndicatorBearingsBackend::nav1Ident() const
{
    return d_nav1Ident;
}

QString HSIndicatorBearingsBackend::nav1Distance() const
{
    return d_nav1Distance;
}

double HSIndicatorBearingsBackend::nav1Bearing() const
{
    return d_nav1Bearing;
}

bool HSIndicatorBearingsBackend::showNav1Bearing() const
{
    return d_nav1HasNav;
}

QString HSIndicatorBearingsBackend::nav2Ident() const
{
    return d_nav2Ident;
}

QString HSIndicatorBearingsBackend::nav2Distance() const
{
    return d_nav2Distance;
}

double HSIndicatorBearingsBackend::nav2Bearing() const
{
    return d_nav2Bearing;
}

bool HSIndicatorBearingsBackend::showNav2Bearing() const
{
    return d_nav2HasNav;
}

QString HSIndicatorBearingsBackend::gpsIdent() const
{
    return d_gpsIdent;
}

QString HSIndicatorBearingsBackend::gpsDistance() const
{
    return d_gpsDistance;
}

double HSIndicatorBearingsBackend::gpsBearing() const
{
    return d_gpsBearing;
}

QString HSIndicatorBearingsBackend::adfIdent() const
{
    return d_adfIdent;
}

double HSIndicatorBearingsBackend::adfBearing() const
{
    return d_adfBearing;
}

bool HSIndicatorBearingsBackend::showAdfBearing() const
{
    return d_adfHasSignal;
}

QString HSIndicatorBearingsBackend::nav1Freq() const
{
    return d_nav1Freq;
}

QString HSIndicatorBearingsBackend::nav1Dme() const
{
    return d_nav1Dme;
}

QString HSIndicatorBearingsBackend::nav2Freq() const
{
    return d_nav2Freq;
}

QString HSIndicatorBearingsBackend::nav2Dme() const
{
    return d_nav2Dme;
}

void HSIndicatorBearingsBackend::updateNav1Ident(QString const &newValue)
{
    d_nav1InternalIdent = newValue;
    if (d_nav1HasNav)
    {
        if (d_nav1HasSignal)
        {
            if (d_nav1Ident != newValue)
            {
                d_nav1Ident = newValue;
                emit nav1IdentChanged();
            }
        }
        else
        {
            if (d_nav1Ident != "")
            {
                d_nav1Ident = "";
                emit nav1IdentChanged();
            }
        }
    }
    else if (d_nav1Ident != "NO DATA")
    {
        d_nav1Ident = "NO DATA";
        emit nav1IdentChanged();
    }
}

void HSIndicatorBearingsBackend::updateNav1Dme(double newValue)
{
    d_nav1DmeDist = newValue;
    if (d_nav1HasNav)
    {
        QString newDist = d_nav1HasDme ? QString::number(d_nav1DmeDist, 'f', 1) + " NM" : "";
        if (d_nav1Distance != newDist)
        {
            d_nav1Distance = newDist;
            emit nav1DistanceChanged();
        }
    }
    else if (d_nav1Distance != "")
    {
        d_nav1Distance = "";
        emit nav1DistanceChanged();
    }
    if (d_nav1HasDme && d_nav1HasSignal)
    {
        QString newDist = QString::number(d_nav1DmeDist, 'f', 1) + " NM";
        if (d_nav1Dme != newDist)
        {
            d_nav1Dme = newDist;
            emit nav1DmeChanged();
        }
    }
    else
    {
        if (d_nav1Dme != "")
        {
            d_nav1Dme = "";
            emit nav1DmeChanged();
        }
    }
}

void HSIndicatorBearingsBackend::updateNav1Bearing(double newValue)
{
    d_nav1Bearing = newValue;
    if (d_nav1HasNav)
        emit nav1BearingChanged();
}

void HSIndicatorBearingsBackend::updateNav1HasNav(bool newValue)
{
    if (d_nav1HasNav != newValue)
    {
        d_nav1HasNav = newValue;
        updateNav1Ident(d_nav1InternalIdent);
        updateNav1Dme(d_nav1DmeDist);
        updateNav1Bearing(d_nav1Bearing);
        emit showNav1BearingChanged();
    }
}

void HSIndicatorBearingsBackend::updateNav1HasSignal(bool newValue)
{
    if (d_nav1HasSignal != newValue)
    {
        d_nav1HasSignal = newValue;
        updateNav1Ident(d_nav1InternalIdent);
        updateNav1Dme(d_nav1DmeDist);
        updateNav1Freq(d_nav1InternalFreq);
    }
}

void HSIndicatorBearingsBackend::updateNav1HasDme(bool newValue)
{
    if (d_nav1HasDme != newValue)
    {
        d_nav1HasDme = newValue;
        updateNav1Dme(d_nav1DmeDist);
        updateNav1Freq(d_nav1InternalFreq);
    }
}


void HSIndicatorBearingsBackend::updateNav2Ident(QString const &newValue)
{
    d_nav2InternalIdent = newValue;
    if (d_nav2HasNav)
    {
        if (d_nav2HasSignal)
        {
            if (d_nav2Ident != newValue)
            {
                d_nav2Ident = newValue;
                emit nav2IdentChanged();
            }
        }
        else
        {
            if (d_nav2Ident != "")
            {
                d_nav2Ident = "";
                emit nav2IdentChanged();
            }
        }
    }
    else if (d_nav2Ident != "NO DATA")
    {
        d_nav2Ident = "NO DATA";
        emit nav2IdentChanged();
    }
}

void HSIndicatorBearingsBackend::updateNav2Dme(double newValue)
{
    d_nav2DmeDist = newValue;
    if (d_nav2HasNav)
    {
        QString newDist = d_nav2HasDme ? QString::number(d_nav2DmeDist, 'f', 1) + " NM" : "";
        if (d_nav2Distance != newDist)
        {
            d_nav2Distance = newDist;
            emit nav2DistanceChanged();
        }
    }
    else if (d_nav2Distance != "")
    {
        d_nav2Distance = "";
        emit nav2DistanceChanged();
    }
    if (d_nav2HasDme && d_nav2HasSignal)
    {
        QString newDist = QString::number(d_nav2DmeDist, 'f', 1) + " NM";
        if (d_nav2Dme != newDist)
        {
            d_nav2Dme = newDist;
            emit nav2DmeChanged();
        }
    }
    else
    {
        if (d_nav2Dme != "")
        {
            d_nav2Dme = "";
            emit nav2DmeChanged();
        }
    }
}

void HSIndicatorBearingsBackend::updateNav2Bearing(double newValue)
{
    d_nav2Bearing = newValue;
    if (d_nav2HasNav)
        emit nav2BearingChanged();
}

void HSIndicatorBearingsBackend::updateNav2HasNav(bool newValue)
{
    if (d_nav2HasNav != newValue)
    {
        d_nav2HasNav = newValue;
        updateNav2Ident(d_nav2InternalIdent);
        updateNav2Dme(d_nav2DmeDist);
        updateNav2Bearing(d_nav2Bearing);
        emit showNav2BearingChanged();
    }
}

void HSIndicatorBearingsBackend::updateNav2HasSignal(bool newValue)
{
    if (d_nav2HasSignal != newValue)
    {
        d_nav2HasSignal = newValue;
        updateNav2Ident(d_nav2InternalIdent);
        updateNav2Dme(d_nav2DmeDist);
        updateNav2Freq(d_nav2InternalFreq);
    }
}

void HSIndicatorBearingsBackend::updateNav2HasDme(bool newValue)
{
    if (d_nav2HasDme != newValue)
    {
        d_nav2HasDme = newValue;
        updateNav2Dme(d_nav2DmeDist);
        updateNav2Freq(d_nav2InternalFreq);
    }
}


void HSIndicatorBearingsBackend::updateGpsIdent(QString const &newValue)
{
    if (d_gpsIdent != newValue)
    {
        d_gpsIdent = newValue;
        emit gpsIdentChanged();
    }
}

void HSIndicatorBearingsBackend::updateGpsDistance(double newValue)
{
    QString newDist = QString::number(newValue, 'f', 1) + " NM";
    if (d_gpsDistance != newDist)
    {
        d_gpsDistance = newDist;
        emit gpsDistanceChanged();
    }
}

void HSIndicatorBearingsBackend::updateGpsBearing(double newValue)
{
    d_gpsBearing = newValue;
    emit gpsBearingChanged();
}


void HSIndicatorBearingsBackend::updateAdfHasSignal(bool newValue)
{
    if (d_adfHasSignal != newValue)
    {
        d_adfHasSignal = newValue;
        updateAdfFreq(d_adfFreq);
        emit adfBearingChanged();
        emit showAdfBearingChanged();
    }
}

void HSIndicatorBearingsBackend::updateAdfFreq(double newValue)
{
    d_adfFreq = newValue;
    if (d_adfHasSignal)
    {
        QString newIdent = QString::number(newValue, 'f', 1);
        if (d_adfIdent != newIdent)
        {
            d_adfIdent = newIdent;
            emit adfIdentChanged();
        }
    }
    else if (d_adfIdent != "NO DATA")
    {
        d_adfIdent = "NO DATA";
        emit adfIdentChanged();
    }
}

void HSIndicatorBearingsBackend::updateAdfRadial(double newValue)
{
    d_adfBearing = newValue;
    if (d_adfHasSignal)
        emit adfBearingChanged();
}


void HSIndicatorBearingsBackend::updateNav1Freq(double newValue)
{
    d_nav1InternalFreq = newValue;
    if (d_nav1HasSignal && d_nav1HasDme)
    {
        QString newFreq = QString::number(newValue, 'f', 2);
        if (d_nav1Freq != newFreq)
        {
            d_nav1Freq = newFreq;
            emit nav1FreqChanged();
        }
    }
    else
    {
        if (d_nav1Freq != "")
        {
            d_nav1Freq = "";
            emit nav1FreqChanged();
        }
    }
}

void HSIndicatorBearingsBackend::updateNav2Freq(double newValue)
{
    d_nav2InternalFreq = newValue;
    if (d_nav2HasSignal && d_nav2HasDme)
    {
        QString newFreq = QString::number(newValue, 'f', 2);
        if (d_nav2Freq != newFreq)
        {
            d_nav2Freq = newFreq;
            emit nav2FreqChanged();
        }
    }
    else
    {
        if (d_nav2Freq != "")
        {
            d_nav2Freq = "";
            emit nav2FreqChanged();
        }
    }
}
