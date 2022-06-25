#include "AircraftLoader.hpp"
#include "pages/TscPage/TscPage.hpp"


AircraftLoader::AircraftLoader(pages::mfd::MfdPage &mfdPage,
                               pages::pfd::PfdPage &pfdPage,
                               pages::tsc::TscPage &tscPage,
                               QObject *parent)
  : QObject(parent),
    d_mfdPage(mfdPage),
    d_pfdPage(pfdPage),
    d_tscPage(tscPage)
{
    connect(tscPage.getSelector(), &pages::tsc::AircraftSelector::loadAircraft, this, &AircraftLoader::loadAircraft);
}
