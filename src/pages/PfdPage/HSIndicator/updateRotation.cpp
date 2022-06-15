#include "HSIndicator.hpp"

#include <cmath>

namespace pages::pfd
{

void HSIndicator::updateRotation(double newValue)
{
    d_rotation = newValue;
    emit rotationChanged();

    int intVal = std::lround(newValue);
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

}  // namespace pages::pfd
