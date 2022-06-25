#include "AircraftLoader.hpp"

#include "pages/MfdPage/MfdPage.hpp"
#include "pages/PfdPage/PfdPage.hpp"
#include "pages/TscPage/TscPage.hpp"
#include "common/definitions/AircraftDefinition/AircraftDefinition.hpp"
#include "common/converters/basicConverters.hpp"

void AircraftLoader::loadAircraft(const definitions::AircraftDefinition &aircraft)
{
    d_mfdPage.loadAircraft(aircraft);
    d_pfdPage.loadAircraft(aircraft);
    d_tscPage.loadAircraft(aircraft);

    emit aircraftLoaded(Converters::convert(aircraft.name));
}
