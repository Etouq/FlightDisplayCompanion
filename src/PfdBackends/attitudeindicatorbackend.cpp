#include "attitudeindicatorbackend.hpp"

AttitudeIndicatorBackend::AttitudeIndicatorBackend(QObject *parent) : QObject(parent)
{
}

double AttitudeIndicatorBackend::bankAngle() const
{
    return d_bankAngle;
}

double AttitudeIndicatorBackend::pitchTransformValue() const
{
    return d_pitchTransformValue;
}

double AttitudeIndicatorBackend::slipSkidTransformValue() const
{
    return d_slipSkidTransformValue;
}

bool AttitudeIndicatorBackend::fdActive() const
{
    return d_fdActive;
}

double AttitudeIndicatorBackend::fdBankAngle() const
{
    return d_fdBankAngle;
}

double AttitudeIndicatorBackend::fdPitchTransformValue() const
{
    return d_fdPitchTransformValue;
}


void AttitudeIndicatorBackend::updateBank(double newValue)
{
    d_bankAngle = newValue;
    emit bankAngleChanged();
    if (d_fdActive)
    {
        d_fdBankAngle = newValue - d_fdBank;
        emit fdBankAngleChanged();
    }
}

void AttitudeIndicatorBackend::updatePitch(double newValue)
{
    d_pitchTransformValue = newValue * d_bankSizeRatio * d_scaleFactor;
    emit pitchTransformValueChanged();
    if (d_fdActive)
    {
        d_fdPitchTransformValue = (newValue - d_fdPitch) * d_bankSizeRatio * d_scaleFactor;
        emit fdPitchTransformValueChanged();
    }
}


void AttitudeIndicatorBackend::updateSlipSkid(double newValue)
{
    d_slipSkidTransformValue = newValue * 40 * d_scaleFactor;
    emit slipSkidTransformValueChanged();
}


void AttitudeIndicatorBackend::updateFdActive(bool newValue)
{
    if (d_fdActive != newValue)
    {
        d_fdActive = newValue;
        emit fdActiveChanged();
        d_fdBankAngle = d_bankAngle - d_fdBank;
        emit fdBankAngleChanged();
        d_fdPitchTransformValue = d_pitchTransformValue - d_fdPitch * d_bankSizeRatio * d_scaleFactor;
        emit fdPitchTransformValueChanged();
    }
}


void AttitudeIndicatorBackend::updateFdBank(double newValue)
{
    d_fdBank = newValue;

    if (d_fdActive)
    {
        d_fdBankAngle = d_bankAngle - newValue;
        emit fdBankAngleChanged();
    }
}


void AttitudeIndicatorBackend::updateFdPitch(double newValue)
{
    d_fdPitch = newValue;

    if (d_fdActive)
    {
        d_fdPitchTransformValue = d_pitchTransformValue - newValue * d_bankSizeRatio * d_scaleFactor;
        emit fdPitchTransformValueChanged();
    }
}
