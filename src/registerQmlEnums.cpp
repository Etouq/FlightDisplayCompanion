#include "main.hpp"
#include "common/QmlEnums.hpp"
#include <QtQml>

void registerQmlEnums()
{
    qRegisterMetaType<QmlHsiNavSource>("QmlHsiNavSource");
    qmlRegisterUncreatableType<QmlHsiNavSourceClass>("TypeEnums",
                                                     1,
                                                     0,
                                                     "HsiNavSource",
                                                     "Not creatable as it is an enum type");

    qRegisterMetaType<QmlVerticalDeviationMode>("QmlVerticalDeviationMode");
    qmlRegisterUncreatableType<QmlVerticalDeviationModeClass>("TypeEnums",
                                                              1,
                                                              0,
                                                              "VerticalDeviationMode",
                                                              "Not creatable as it is an enum type");

    qRegisterMetaType<QmlTransponderState>("QmlTransponderState");
    qmlRegisterUncreatableType<QmlTransponderStateClass>("TypeEnums",
                                                         1,
                                                         0,
                                                         "TransponderState",
                                                         "Not creatable as it is an enum type");

    qRegisterMetaType<MapRotationMode>("MapRotationMode");
    qmlRegisterUncreatableType<QmlMapRotationModeClass>("TypeEnums",
                                                     1,
                                                     0,
                                                     "MapRotationMode",
                                                     "Not creatable as it is an enum type");

    qRegisterMetaType<QmlWaypointType>("QmlWaypointType");
    qmlRegisterUncreatableType<QmlWaypointTypeClass>("TypeEnums",
                                                     1,
                                                     0,
                                                     "WaypointType",
                                                     "Not creatable as it is an enum type");

    qRegisterMetaType<QmlWpAltitudeType>("QmlWpAltitudeType");
    qmlRegisterUncreatableType<QmlWpAltitudeTypeClass>("TypeEnums",
                                                     1,
                                                     0,
                                                     "WpAltitudeType",
                                                     "Not creatable as it is an enum type");

    qRegisterMetaType<BearingMode>("BearingMode");
    qmlRegisterUncreatableType<QmlBearingModeClass>("TypeEnums",
                                                     1,
                                                     0,
                                                     "BearingMode",
                                                     "Not creatable as it is an enum type");

    qRegisterMetaType<WindMode>("WindMode");
    qmlRegisterUncreatableType<QmlWindModeClass>("TypeEnums",
                                                     1,
                                                     0,
                                                     "WindMode",
                                                     "Not creatable as it is an enum type");

    qRegisterMetaType<BottomTemperatureType>("BottomTemperatureType");
    qmlRegisterUncreatableType<QmlBottomTemperatureTypeClass>("TypeEnums",
                                                     1,
                                                     0,
                                                     "BottomTemperatureType",
                                                     "Not creatable as it is an enum type");

    qRegisterMetaType<TimeType>("TimeType");
    qmlRegisterUncreatableType<QmlTimeTypeClass>("TypeEnums",
                                                     1,
                                                     0,
                                                     "TimeType",
                                                     "Not creatable as it is an enum type");

    qRegisterMetaType<io::network::ConnectionState>("ConnectionState");
    qmlRegisterUncreatableType<io::network::ConnectionStateClass>("TypeEnums",
                                                     1,
                                                     0,
                                                     "ConnectionState",
                                                     "Not creatable as it is an enum type");
}
