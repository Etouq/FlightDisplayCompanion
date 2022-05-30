#include <QGuiApplication>
#include <QLocale>
#include <QQmlContext>
#include <QQuickView>
#include <QSurfaceFormat>
#include <QtAndroid>
#include <QQmlApplicationEngine>
#include <QAndroidJniEnvironment>

#include "PfdBackends/pfdmanager.hpp"
#include "aircraftManager/aircraftmanager.hpp"
#include "gaugeBackends/gaugemanager.hpp"
#include "mfdbackend.hpp"
#include "networkBackend/networkclient.hpp"
#include "networkBackend/networkinterface.hpp"
#include "settings/settingscontroller.hpp"
#include "settings/settingsinterface.hpp"
#include "TscPage/tscpagebackend.hpp"

void keep_screen_on(bool on) {
    QtAndroid::runOnAndroidThread([on]{
        QAndroidJniObject activity = QtAndroid::androidActivity();
        if (activity.isValid()) {
            QAndroidJniObject window =
              activity.callObjectMethod("getWindow", "()Landroid/view/Window;");

            if (window.isValid()) {
                const int FLAG_KEEP_SCREEN_ON = 128;
                if (on) {
                    window.callMethod<void>("addFlags", "(I)V", FLAG_KEEP_SCREEN_ON);
                } else {
                    window.callMethod<void>("clearFlags", "(I)V", FLAG_KEEP_SCREEN_ON);
                }
            }
        }
        QAndroidJniEnvironment env;
        if (env->ExceptionCheck()) {
            env->ExceptionClear();
        }
    });
}

int main(int argc, char *argv[])
{


    QGuiApplication app(argc, argv);
    QLocale::setDefault(QLocale::c());
    app.setOrganizationName("MKootstra");
    //app.setApplicationName("FlightDisplayCompanion");
    app.setApplicationDisplayName("Flight Display Companion");


    QSurfaceFormat format;
    format.setSamples(8);
    QSurfaceFormat::setDefaultFormat(format);


    QtAndroid::requestPermissionsSync({ "android.permission.WRITE_EXTERNAL_STORAGE", "android.permission.READ_EXTERNAL_STORAGE" });

    if (QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE") == QtAndroid::PermissionResult::Denied
        || QtAndroid::checkPermission("android.permission.READ_EXTERNAL_STORAGE") == QtAndroid::PermissionResult::Denied)
    {
        QQmlApplicationEngine engine;
        QObject::connect(&engine, &QQmlEngine::quit, &app, &QGuiApplication::quit);
        engine.load("qrc:/deniedAccessDialog.qml");
        app.exec();
        return -1;
    }

    keep_screen_on(true);

    SettingsController::init();

    PfdManager pfdInterfaceManager;
    GaugeManager gaugeManager;
    MfdBackend mfdInterface;
    AircraftManager planeManager;
    NetworkClient netClient;
    NetworkInterface netInterface;
    SettingsInterface settingsInterface;
    TscPageBackend tscBackend;


    pfdInterfaceManager.connectPfdSlots(&netClient);
    gaugeManager.connectSlots(&netClient);
    mfdInterface.connectSlots(&netClient);
    planeManager.connectSlots(&netClient);
    QObject::connect(&planeManager, &AircraftManager::updateAircraft, &gaugeManager, &GaugeManager::changeAircraft);
    QObject::connect(&planeManager, &AircraftManager::updateAircraft, &pfdInterfaceManager, &PfdManager::changeAircraft);
    QObject::connect(&planeManager, &AircraftManager::updateAircraft, &tscBackend, &TscPageBackend::changeAircraft);
    netClient.connectInterfaceSignals(&netInterface);
    tscBackend.connectTscSlots(&netClient);

    QObject::connect(&settingsInterface, &SettingsInterface::temperatureUnitChanged, pfdInterfaceManager.getBottomInterface(), &BottombarBackend::updateTemperatureUnit);


    planeManager.initialize();
    mfdInterface.loadFlightplan();


    QQmlApplicationEngine engine;


    gaugeManager.addGaugesToContext(engine.rootContext());
    pfdInterfaceManager.addPfdToContext(engine.rootContext());

    engine.rootContext()->setContextProperty("aircraftInterface", &planeManager);
    engine.rootContext()->setContextProperty("netInterface", &netInterface);
    engine.rootContext()->setContextProperty("mfdInterface", &mfdInterface);
    engine.rootContext()->setContextProperty("settingsInterface", &settingsInterface);
    engine.rootContext()->setContextProperty("tscBackend", &tscBackend);


    engine.load("qrc:/main.qml");

    int ret = app.exec();
    mfdInterface.saveFlightplan();

    return ret;
}
