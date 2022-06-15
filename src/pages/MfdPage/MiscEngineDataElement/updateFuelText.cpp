#include "MiscEngineDataElement.hpp"

#include <QLatin1String>


namespace pages::mfd
{

void MiscEngineDataElement::updateFuelText(float totalFuelflow, float totalFuelQty, float groundSpeed)
{

    d_smoothedSpeed = 0.8 * d_smoothedSpeed + 0.2 * groundSpeed;
    d_smoothedFF = 0.8 * d_smoothedFF + 0.2 * totalFuelflow;

    if (d_smoothedFF <= 0.1)
    {
        if (QLatin1String("--:--") != d_fuelTimeText)
        {
            d_fuelTimeText = QLatin1String("--:--");
            emit fuelTimeTextChanged();
        }
        if (QLatin1String("__._NM") != d_fuelRangeText)
        {
            d_fuelRange = -1;
            d_fuelRangeText = QLatin1String("__._NM");
            emit fuelRangeTextChanged();
            emit fuelRangeChanged();
        }
        return;
    }

    float floatTime = totalFuelQty / d_smoothedFF;
    QString newFuelTime =
      QString("%1:%2")
        .arg(static_cast<int>(floatTime), 2, 10, QChar('0'))
        .arg(static_cast<int>((floatTime - static_cast<int>(floatTime)) * 60.0), 2, 10, QChar('0'));
    if (newFuelTime != d_fuelTimeText)
    {
        d_fuelTimeText = newFuelTime;
        emit fuelTimeTextChanged();
    }

    if (d_smoothedSpeed <= 0.1)
    {
        if (QLatin1String("__._NM") != d_fuelRangeText)
        {
            d_fuelRange = -1;
            d_fuelRangeText = QLatin1String("__._NM");
            emit fuelRangeTextChanged();
            emit fuelRangeChanged();
        }
        return;
    }
    float fuelRangeVal = floatTime * d_smoothedSpeed;
    QString newFuelRange = QString("%1NM").arg(fuelRangeVal,
                                               0,
                                               'f',
                                               fuelRangeVal >= 100    ? 0
                                                 : fuelRangeVal >= 10 ? 1
                                                                      : 2);
    if (newFuelRange != d_fuelRangeText)
    {
        d_fuelRange = fuelRangeVal;
        d_fuelRangeText = newFuelRange;
        emit fuelRangeTextChanged();
        emit fuelRangeChanged();
    }
}

}  // namespace pages::mfd
