#include "main.hpp"
#include "common/typeEnums.hpp"

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
}