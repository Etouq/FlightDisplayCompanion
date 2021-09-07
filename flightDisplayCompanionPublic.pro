QT += core qml quick androidextras network positioning location svg gui sql quickcontrols2
TEMPLATE = app
CONFIG += c++latest console


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
        TscPage/radiofunctions.cpp \
        TscPage/timerfunctions.cpp \
        TscPage/tscpagebackend.cpp \
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
        keepawakehelper.cpp \
        main.cpp \
        mfdbackend.cpp \
        networkBackend/networkclient.cpp \
        networkBackend/networkinterface.cpp \
        networkBackend/readdesignerdata.cpp \
        networkBackend/readinitdata.cpp \
        networkBackend/readsimconnectdata.cpp \
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
    android/res/values/libs.xml \
    qml/main.qml \
    qml/deniedAccessDialog.qml \
    qml/mfdPage/engineDisplay/JetDouble.qml \
    qml/mfdPage/engineDisplay/JetQuad.qml \
    qml/mfdPage/engineDisplay/JetSingle.qml \
    qml/mfdPage/engineDisplay/PropDouble.qml \
    qml/mfdPage/engineDisplay/PropSingle.qml \
    qml/mfdPage/engineDisplay/TurbopropDouble.qml \
    qml/mfdPage/engineDisplay/TurbopropSingle.qml \
    qml/mfdPage/engineDisplay/gauges/CircularGauge.qml \
    qml/mfdPage/engineDisplay/gauges/VerticalGauge.qml \
    qml/mfdPage/engineDisplay/gauges/VerticalDoubleGauge.qml \
    qml/mfdPage/engineDisplay/gauges/FuelText.qml \
    qml/mfdPage/engineDisplay/gauges/FlapsGauge.qml \
    qml/mfdPage/engineDisplay/gauges/FlapsSpoilersGauge.qml \
    qml/mfdPage/engineDisplay/gauges/TrimGauges.qml \
    qml/mfdPage/engineDisplay/gauges/ElevatorTrimGauge.qml \
    qml/mfdPage/engineDisplay/gauges/RudderTrimGauge.qml \
    qml/mfdPage/engineDisplay/gauges/AileronTrimGauge.qml \
    qml/mfdPage/engineDisplay/gauges/FuelSingleTankGauge.qml \
    qml/mfdPage/engineDisplay/gauges/FuelDoubleTankGauge.qml \
    qml/mfdPage/map/MapItem.qml \
    qml/mfdPage/map/RangeCircles.qml \
    qml/mfdPage/map/FlightplanWpIcons.qml \
    qml/mfdPage/map/MapButtons.qml \
    qml/mfdPage/MfdPage.qml \
    qml/mfdPage/NavTopBar.qml \
    qml/pfdPage/PfdPage.qml \
    qml/pfdPage/pfdElements/AirspeedIndicator/AirspeedReferenceGroup.qml \
    qml/pfdPage/pfdElements/AirspeedIndicator/CenterGroup.qml \
    qml/pfdPage/pfdElements/AngleOfAttackIndicator.qml \
    qml/pfdPage/pfdElements/AttitudeIndicator/AttitudeBackground.qml \
    qml/pfdPage/pfdElements/AttitudeIndicator/AttitudeBank.qml \
    qml/pfdPage/pfdElements/AttitudeIndicator/AttitudeIndicator.qml \
    qml/pfdPage/pfdElements/AttitudeIndicator/AttitudePitch.qml \
    qml/pfdPage/pfdElements/AttitudeIndicator/AttitudePitchContainer.qml \
    qml/pfdPage/pfdElements/AttitudeIndicator/Cursors.qml \
    qml/pfdPage/pfdElements/AttitudeIndicator/FlightDirector.qml \
    qml/pfdPage/pfdElements/AutopilotInfos.qml \
    qml/pfdPage/pfdElements/BottomBar.qml \
    qml/pfdPage/pfdElements/ComInfos.qml \
    qml/pfdPage/pfdElements/HsiIndicator/BackgroundCircle.qml \
    qml/pfdPage/pfdElements/HsiIndicator/Bearing1FixedGroup.qml \
    qml/pfdPage/pfdElements/HsiIndicator/Bearing2FixedGroup.qml \
    qml/pfdPage/pfdElements/HsiIndicator/BgCircleItems.qml \
    qml/pfdPage/pfdElements/HsiIndicator/Course.qml \
    qml/pfdPage/pfdElements/HsiIndicator/DmeGroup.qml \
    qml/pfdPage/pfdElements/HsiIndicator/HSIndicator.qml \
    qml/pfdPage/pfdElements/HsiIndicator/StaticParts.qml \
    qml/pfdPage/pfdElements/HsiIndicator/Turnrate.qml \
    qml/pfdPage/pfdElements/NavFreqInfos.qml \
    qml/pfdPage/pfdElements/NavInfos.qml \
    qml/pfdPage/pfdElements/RadarAltitude.qml \
    qml/pfdPage/pfdElements/WindDataDisplay.qml \
    qml/settingsPage/flightplan/FlightplanPage.qml \
    qml/settingsPage/flightplan/FlightplanTable.qml \
    qml/settingsPage/flightplan/FlightplanTableCell.qml \
    qml/settingsPage/flightplan/FlightplanInput.qml \
    qml/settingsPage/flightplan/StyledButton.qml \
    qml/settingsPage/flightplan/StyledComboBox.qml \
    qml/settingsPage/ThumbnailView.qml \
    qml/settingsPage/StyledCheckBox.qml \
    qml/settingsPage/connection/ConnectionInput.qml \
    qml/settingsPage/SettingsPage.qml \
    qml/tscPage/HomePage.qml \
    qml/tscPage/TscPage.qml \
    qml/tscPage/TscPageBase.qml \
    qml/tscPage/images/DoubleArrowVerticalWhite.svg \
    qml/tscPage/images/ICON_MAP_BKSP.png \
    qml/tscPage/images/ICON_MAP_BUTTONBAR_BACK_1.png \
    qml/tscPage/images/ICON_MAP_BUTTONBAR_HOME.png \
    qml/tscPage/images/ICON_MAP_ENTER.png \
    qml/tscPage/images/ICON_MAP_MINIMUMS.png \
    qml/tscPage/images/ICON_MAP_SETTINGS_1.png \
    qml/tscPage/images/ICON_MAP_SMALL_BEARING_1.png \
    qml/tscPage/images/ICON_MAP_SMALL_BEARING_2_1.png \
    qml/tscPage/images/ICON_MAP_SMALL_TIMERS.png \
    qml/tscPage/images/ICON_MAP_SPEED_BUG.png \
    qml/tscPage/navcom_page/FrequencyKeyboard.qml \
    qml/tscPage/navcom_page/NavComHome.qml \
    qml/tscPage/navcom_page/RadioRow.qml \
    qml/tscPage/navcom_page/TransponderKeyboard.qml \
    qml/tscPage/pfd_page/Minimums.qml \
    qml/tscPage/pfd_page/MinimumsSource.qml \
    qml/tscPage/pfd_page/SpeedBugs.qml \
    qml/tscPage/pfd_page/SpeedKeyboard.qml \
    qml/tscPage/pfd_page/TimeKeyboard.qml \
    qml/tscPage/pfd_page/Timers.qml \
    qml/tscPage/pfd_page/Timers.qml.CMhbaz \
    qml/tscPage/styled_controls/GradientButton.qml \
    qml/tscPage/styled_controls/GradientRoundButton.qml \
    qml/tscPage/styled_controls/gradientButtonElements/CenterImg.qml \
    qml/tscPage/styled_controls/gradientButtonElements/GradientStatusBar.qml \
    qml/tscPage/styled_controls/gradientButtonElements/Img.qml \
    qml/tscPage/styled_controls/gradientButtonElements/ImgSmall.qml \
    qml/tscPage/styled_controls/gradientButtonElements/LowerImg.qml \
    qml/tscPage/styled_controls/gradientButtonElements/LowerValue.qml \
    qml/tscPage/styled_controls/gradientButtonElements/MainNumber.qml \
    qml/tscPage/styled_controls/gradientButtonElements/MainText.qml \
    qml/tscPage/styled_controls/gradientButtonElements/Title.qml \
    qml/tscPage/styled_controls/gradientButtonElements/TopText.qml \
    qml/tscPage/styled_controls/gradientButtonElements/UpperTitle.qml

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
    TscPage/tscpagebackend.h \
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
    keepawakehelper.h \
    mfdbackend.h \
    networkBackend/dataIdentifiers.h \
    networkBackend/networkclient.h \
    networkBackend/networkinterface.h \
    settings/settingscontroller.h \
    settings/settingsinterface.h \
    unitConverter/unitconverter.h \
    unitConverter/units.h
android: include(D:/android_openssl-master/openssl.pri)
