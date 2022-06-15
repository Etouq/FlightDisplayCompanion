#include "HSIndicator.hpp"
#include "common/typeEnums.hpp"

#include <cmath>

namespace pages::pfd
{

void HSIndicator::updateCourseDeviation(double newValue)
{
    d_crossTrackError = std::abs(newValue);
    emit crossTrackErrorChanged();

    if (d_navSource == HsiNavSource::GPS)
        d_courseDeviation = newValue <= -2 ? -20 : newValue >= 2 ? 20 : newValue * 10;
    else
        d_courseDeviation = newValue <= -1 ? -20 : newValue >= 1 ? 20 : newValue * 20;
    emit courseDeviationChanged();
}

}  // namespace pages::pfd
