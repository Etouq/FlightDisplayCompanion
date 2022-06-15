#include "HSIBearings.hpp"

namespace pages::pfd
{

void HSIBearings::updateNav2Ident(const QString &newValue)
{
    d_nav2InternalIdent = newValue;
    if (d_nav2HasNav)
    {
        if (d_nav2HasSignal)
        {
            if (d_nav2Ident != newValue)
            {
                d_nav2Ident = newValue;
                emit nav2IdentChanged();
            }
        }
        else
        {
            if (d_nav2Ident != "")
            {
                d_nav2Ident = "";
                emit nav2IdentChanged();
            }
        }
    }
    else if (d_nav2Ident != "NO DATA")
    {
        d_nav2Ident = "NO DATA";
        emit nav2IdentChanged();
    }
}

}  // namespace pages::pfd
