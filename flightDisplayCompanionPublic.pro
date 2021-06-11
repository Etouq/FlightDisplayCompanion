QT += core qml quick androidextras network positioning location svg gui sql quickcontrols2
TEMPLATE = app
CONFIG += c++latest


#android: include(C:/Users/Mikey/Downloads/android_openssl-master/android_openssl-master/openssl.pri)

# Workaround for QTBUG-38735
QT_FOR_CONFIG += location-private
qtConfig(geoservices_mapboxgl): QT += sql
qtConfig(geoservices_osm): QT += concurrent

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        PfdBackends/airspeedindicatorbackend.cpp \
        PfdBackends/altimeterbackend.cpp \
        PfdBackends/angleofattackindicatorbackend.cpp \
        PfdBackends/apinfobackend.cpp \
        PfdBackends/attitudeindicatorbackend.cpp \
        PfdBackends/bottombarbackend.cpp \
        PfdBackends/hsindicatorbackend.cpp \
        PfdBackends/hsindicatorbearingsbackend.cpp \
        PfdBackends/navinfobackend.cpp \
        PfdBackends/pfdmanager.cpp \
        PfdBackends/radioinfobackend.cpp \
        PfdBackends/winddatabackend.cpp \
        aircraftManager/aircraftInitializer/aircraftinitializer.cpp \
        aircraftManager/aircraftInitializer/initairbus_a320_neo.cpp \
        aircraftManager/aircraftInitializer/initaviat_pitts.cpp \
        aircraftManager/aircraftInitializer/initbaron_g58.cpp \
        aircraftManager/aircraftInitializer/initbeechcraft_king_air_350i.cpp \
        aircraftManager/aircraftInitializer/initboeing_747_8i.cpp \
        aircraftManager/aircraftInitializer/initboeing_787_10.cpp \
        aircraftManager/aircraftInitializer/initbonanza_g36.cpp \
        aircraftManager/aircraftInitializer/initcessna_152.cpp \
        aircraftManager/aircraftInitializer/initcessna_208b_grand_caravan_ex.cpp \
        aircraftManager/aircraftInitializer/initcessna_cj4_citation.cpp \
        aircraftManager/aircraftInitializer/initcessna_longitude.cpp \
        aircraftManager/aircraftInitializer/initcessna_skyhawk.cpp \
        aircraftManager/aircraftInitializer/initda40_ng.cpp \
        aircraftManager/aircraftInitializer/initda40_tdi.cpp \
        aircraftManager/aircraftInitializer/initda62.cpp \
        aircraftManager/aircraftInitializer/initdr_400.cpp \
        aircraftManager/aircraftInitializer/initdv20.cpp \
        aircraftManager/aircraftInitializer/initextra_330.cpp \
        aircraftManager/aircraftInitializer/initflightdesignct.cpp \
        aircraftManager/aircraftInitializer/initicon_a5.cpp \
        aircraftManager/aircraftInitializer/initmudry_cap_10_c.cpp \
        aircraftManager/aircraftInitializer/initpipistrel_alpha_electro.cpp \
        aircraftManager/aircraftInitializer/initsavage_carbon.cpp \
        aircraftManager/aircraftInitializer/initsavage_cub.cpp \
        aircraftManager/aircraftInitializer/initsavage_grravel.cpp \
        aircraftManager/aircraftInitializer/initsavage_shock_ultra.cpp \
        aircraftManager/aircraftInitializer/initsr22.cpp \
        aircraftManager/aircraftInitializer/inittbm_930.cpp \
        aircraftManager/aircraftInitializer/initvl3.cpp \
        aircraftManager/aircraftInitializer/initxcub.cpp \
        aircraftManager/aircraftfile.cpp \
        aircraftManager/aircraftmanager.cpp \
        aircraftManager/definitions/aircraftDefinition.cpp \
        aircraftManager/definitions/gaugeDefinition.cpp \
        aircraftManager/definitions/jetDefinition.cpp \
        aircraftManager/definitions/propDefinition.cpp \
        aircraftManager/definitions/turbopropDefinition.cpp \
        binaryutil.cpp \
        gaugeBackends/gaugebase.cpp \
        gaugeBackends/gaugemanager.cpp \
        gaugeBackends/gaugeqmlfunctions.cpp \
        gaugeBackends/miscedbase.cpp \
        main.cpp \
        mfdbackend.cpp \
        networkBackend/networkclient.cpp \
        networkBackend/networkinterface.cpp \
        networkBackend/readnetworkdata.cpp \
        settings/settingscontroller.cpp \
        settings/settingsinterface.cpp \
        unitConverter/pressureConverters.cpp \
        unitConverter/temperatureConverters.cpp \
        unitConverter/torqueConverters.cpp \
        unitConverter/unitconverter.cpp \
        unitConverter/volumeConverters.cpp \
        unitConverter/volumerateConverters.cpp \
        unitConverter/weightConverters.cpp \
        unitConverter/weightrateConverters.cpp

RESOURCES += qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

HEADERS += \
    PfdBackends/airspeedindicatorbackend.h \
    PfdBackends/altimeterbackend.h \
    PfdBackends/angleofattackindicatorbackend.h \
    PfdBackends/apinfobackend.h \
    PfdBackends/attitudeindicatorbackend.h \
    PfdBackends/bottombarbackend.h \
    PfdBackends/hsindicatorbackend.h \
    PfdBackends/hsindicatorbearingsbackend.h \
    PfdBackends/navinfobackend.h \
    PfdBackends/pfdmanager.h \
    PfdBackends/radioinfobackend.h \
    PfdBackends/winddatabackend.h \
    aircraftManager/aircraftInitializer/aircraftinitializer.h \
    aircraftManager/aircraftfile.h \
    aircraftManager/aircraftmanager.h \
    aircraftManager/definitions/aircraftDefinition.h \
    aircraftManager/definitions/basetypes.h \
    aircraftManager/definitions/gaugeDefinition.h \
    aircraftManager/definitions/jetDefinition.h \
    aircraftManager/definitions/propDefinition.h \
    aircraftManager/definitions/turbopropDefinition.h \
    binaryutil.h \
    gaugeBackends/gaugebase.h \
    gaugeBackends/gaugemanager.h \
    gaugeBackends/miscedbase.h \
    mfdbackend.h \
    networkBackend/dataIdentifiers.h \
    networkBackend/networkclient.h \
    networkBackend/networkinterface.h \
    settings/settingscontroller.h \
    settings/settingsinterface.h \
    unitConverter/unitconverter.h \
    unitConverter/units.h
android: include(D:/android_SDK/android_openssl/openssl.pri)
