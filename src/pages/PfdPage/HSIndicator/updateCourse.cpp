#include "HSIndicator.hpp"

#include <cmath>

namespace pages::pfd
{

void HSIndicator::updateCourse(double newValue)
{
    d_course = newValue;
    emit courseChanged();

    int intVal = std::lround(newValue);

    QString newText = QString("%1°").arg(intVal, 3, 10, QChar('0'));
    if (newText != d_courseText)
    {
        d_courseText = newText;
        emit courseTextChanged();
    }
}

}  // namespace pages::pfd
