#include "AttitudeIndicator.hpp"


namespace pages::pfd
{

void AttitudeIndicator::updateAttitude(double bank, double pitch, double slipSkid)
{
    d_bankAngle = bank;
    d_pitchTransformValue = pitch * d_bankSizeRatio * d_scaleFactor;
    d_slipSkidTransformValue = slipSkid * 40 * d_scaleFactor;

    emit attitudeChanged();

    if (d_fdActive)
    {
        d_fdBankAngle = bank - d_fdBank;
        d_fdPitchTransformValue = (pitch - d_fdPitch) * d_bankSizeRatio * d_scaleFactor;
        emit fdAttitudeChanged();
    }
}

}  // namespace pages::pfd
