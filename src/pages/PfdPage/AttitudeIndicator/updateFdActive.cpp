#include "AttitudeIndicator.hpp"

namespace pages::pfd
{

void AttitudeIndicator::updateFdActive(bool fdActive)
{
    d_fdActive = fdActive;
    emit fdActiveChanged();

    if (d_fdActive)
    {
        updateFdAttitude(d_fdBank, d_fdPitch);
    }
}

}  // namespace pages::pfd
