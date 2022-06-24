#include "main.hpp"
#include "common/QmlEnums.hpp"

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
}