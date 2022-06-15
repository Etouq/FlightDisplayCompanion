#include "HSIndicator.hpp"

#include <cmath>

namespace pages::pfd
{

void HSIndicator::updateHeading(double newValue)
{
    d_headingBugRotation = newValue;
    emit headingBugRotationChanged();

    int intVal = std::lround(newValue);
    if (intVal == 0)
        intVal = 360;

    QString newText = QString("%1°").arg(intVal, 3, 10, QChar('0'));
    if (newText != d_headingText)
    {
        d_headingText = newText;
        emit headingTextChanged();
    }
}

}  // namespace pages::pfd
