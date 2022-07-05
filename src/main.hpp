#ifndef __FLIGHT_DISPLAY_COMPANION_HPP__
#define __FLIGHT_DISPLAY_COMPANION_HPP__

#include <QQmlApplicationEngine>

void keepScreenOn(bool on);

void registerQmlEnums();

namespace definitions
{
    class AircraftDefinition;
}

definitions::AircraftDefinition createTestDefinition();

#endif  // __FLIGHT_DISPLAY_COMPANION_HPP__
