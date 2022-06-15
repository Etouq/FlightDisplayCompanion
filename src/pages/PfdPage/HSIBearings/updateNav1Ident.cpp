#include "HSIBearings.hpp"

namespace pages::pfd
{

void HSIBearings::updateNav1Ident(const QString &newValue)
{
    d_nav1InternalIdent = newValue;
    if (d_nav1HasNav)
    {
        if (d_nav1HasSignal)
        {
            if (d_nav1Ident != newValue)
            {
                d_nav1Ident = newValue;
                emit nav1IdentChanged();
            }
        }
        else
        {
            if (d_nav1Ident != "")
            {
                d_nav1Ident = "";
                emit nav1IdentChanged();
            }
        }
    }
    else if (d_nav1Ident != "NO DATA")
    {
        d_nav1Ident = "NO DATA";
        emit nav1IdentChanged();
    }
}

}  // namespace pages::pfd
