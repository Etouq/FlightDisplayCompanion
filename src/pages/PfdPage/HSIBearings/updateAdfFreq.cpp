#include "HSIBearings.hpp"

namespace pages::pfd
{

void HSIBearings::updateAdfFreq(double newValue)
{
    d_adfFreq = newValue;
    if (d_adfHasSignal)
    {
        QString newIdent = QString::number(newValue, 'f', 1);
        if (d_adfIdent != newIdent)
        {
            d_adfIdent = newIdent;
            emit adfIdentChanged();
        }
    }
    else if (d_adfIdent != "NO DATA")
    {
        d_adfIdent = "NO DATA";
        emit adfIdentChanged();
    }
}

}  // namespace pages::pfd
