#include "hsindicatorbackend.h"

#include <cmath>

HSIndicatorBackend::HSIndicatorBackend(QObject *parent) : QObject(parent)
{
}

double HSIndicatorBackend::rotation() const
{
    return d_rotation;
}

QString HSIndicatorBackend::rotationText() const
{
    return d_rotationText;
}

double HSIndicatorBackend::headingBugRotation() const
{
    return d_heading_bug_rotation;
}

QString HSIndicatorBackend::headingText() const
{
    return d_headingText;
}

double HSIndicatorBackend::course() const
{
    return d_course;
}

QString HSIndicatorBackend::courseText() const
{
    return d_courseText;
}

double HSIndicatorBackend::courseDeviation() const
{
    return d_course_deviation;
}

double HSIndicatorBackend::crossTrackError() const
{
    return d_cross_track_error;
}

bool HSIndicatorBackend::displayDeviation() const
{
    return d_display_deviation;
}

double HSIndicatorBackend::turnRate() const
{
    return d_turn_rate;
}

int HSIndicatorBackend::navSource() const
{
    return d_navSource;
}

double HSIndicatorBackend::currentTrackAngle() const
{
    return d_current_track_angle;
}

int HSIndicatorBackend::toFrom() const
{
    return d_to_from;
}



void HSIndicatorBackend::updateRotation(double newValue)
{
    d_rotation = newValue;
    emit rotationChanged();

    int intVal = lround(newValue);
    if (intVal == 0)
        intVal = 360;

    // intVal = intVal == 0 ? 360 : intVal;

    QString newText = QString("%1°").arg(intVal, 3, 10, QChar('0'));
    if (newText != d_rotationText)
    {
        d_rotationText = newText;
        emit rotationTextChanged();
    }
}

void HSIndicatorBackend::updateHeading(double newValue)
{
    d_heading_bug_rotation = newValue;
    emit headingBugRotationChanged();

    int intVal = lround(newValue);
    if (intVal == 0)
        intVal = 360;

    QString newText = QString("%1°").arg(intVal, 3, 10, QChar('0'));
    if (newText != d_headingText)
    {
        d_headingText = newText;
        emit headingTextChanged();
    }
}

void HSIndicatorBackend::updateCourse(double newValue)
{
    d_course = newValue;
    emit courseChanged();

    int intVal = lround(newValue);

    QString newText = QString("%1°").arg(intVal, 3, 10, QChar('0'));
    if (newText != d_courseText)
    {
        d_courseText = newText;
        emit courseTextChanged();
    }
}


void HSIndicatorBackend::updateCourseDeviation(double newValue)
{
    d_cross_track_error = std::abs(newValue);
    emit crossTrackErrorChanged();

    if (d_navSource == 0)
        d_course_deviation = newValue <= -2 ? -20 : newValue >= 2 ? 20 : newValue * 10;
    else
        d_course_deviation = newValue <= -1 ? -20 : newValue >= 1 ? 20 : newValue * 20;
    emit courseDeviationChanged();
}


void HSIndicatorBackend::updateDisplayDeviation(bool newValue)
{
    d_display_deviation = newValue;
    emit displayDeviationChanged();
}


void HSIndicatorBackend::updateTurnRate(double newValue)
{
    d_turn_rate = newValue <= -4 ? -24.5 : newValue >= 4 ? 24.5 : newValue * 6;
    emit turnRateChanged();
}


void HSIndicatorBackend::updateNavSource(int newValue)
{
    d_navSource = newValue;
    emit navSourceChanged();
}


void HSIndicatorBackend::updateCurrentTrack(double newValue)
{
    d_current_track_angle = newValue;
    emit currentTrackAngleChanged();
}


void HSIndicatorBackend::updateToFrom(int newValue)
{
    d_to_from = newValue;
    emit toFromChanged();
}
