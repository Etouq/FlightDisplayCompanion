#include "AttitudeIndicator.hpp"


namespace pages::pfd
{

void AttitudeIndicator::updateFdAttitude(double bank, double pitch)
{
    d_fdBank = bank;
    d_fdPitch = pitch;

    if (d_fdActive)
    {
        d_fdBankAngle = d_bankAngle - bank;
        d_fdPitchTransformValue = d_pitchTransformValue - pitch * d_bankSizeRatio * d_scaleFactor;
        emit fdAttitudeChanged();
    }
}

}  // namespace pages::pfd
