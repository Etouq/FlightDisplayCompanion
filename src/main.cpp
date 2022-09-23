#include "main.hpp"
#include "AircraftLoader/AircraftLoader.hpp"
#include "io/NetworkClient/NetworkClient.hpp"
#include "pages/MfdPage/MfdPage.hpp"
#include "pages/PfdPage/PfdPage.hpp"
#include "pages/TscPage/TscPage.hpp"
#include "io/Logger/Logger.hpp"

#include <QQmlApplicationEngine>
#include <QFontDatabase>
#include <QGuiApplication>
#include <QLocale>
#include <QObject>
#include <QSurfaceFormat>
#include <QNetworkProxy>

int main(int argc, char *argv[])
{
    Logger::init();
    //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//    qSetMessagePattern("[%{time HH:mm:ss.zzz} %{type}] %{if-category}%{category}: %{endif}- %{message}");
    qInstallMessageHandler(Logger::logOutput);

    // initialize application
    QGuiApplication app(argc, argv);
    QGuiApplication::setOrganizationName("nl.Etouq");
    QGuiApplication::setApplicationName("FlightDisplayCompanionTest");
    QGuiApplication::setApplicationDisplayName("Flight Display Companion Test");

    QLocale::setDefault(QLocale::c());
    QNetworkProxy::setApplicationProxy(QNetworkProxy::NoProxy);

    // add roboto font
    QFontDatabase::addApplicationFont(":/fonts/RobotoMono-Bold.ttf");

    QSurfaceFormat format;
    format.setSamples(8);
    QSurfaceFormat::setDefaultFormat(format);

    // prevent screen from turning off
    keepScreenOn(true);

    // register enums so they can be used in qml
    registerQmlEnums();

    // create data managers before the engine (so they outlive it)
    io::network::NetworkClient networkClient;

    // initialize pages
    pages::mfd::MfdPage mfdPage(&networkClient);
    pages::pfd::PfdPage pfdPage(&networkClient);
    pages::tsc::TscPage tscPage(&networkClient);

   AircraftLoader aircraftLoader(mfdPage, pfdPage, tscPage);

   QObject::connect(&networkClient,
                    &io::network::NetworkClient::loadAircraft,
                    &aircraftLoader,
                    &AircraftLoader::loadAircraft);
   QObject::connect(&aircraftLoader,
                    &AircraftLoader::aircraftLoaded,
                    &networkClient,
                    &io::network::NetworkClient::aircraftLoaded);

    qmlRegisterSingletonInstance("Mfd", 1, 0, "MfdRoot", &mfdPage);
    // add networkclient to qml as singleton
    qmlRegisterSingletonInstance("IO.Network", 1, 0, "NetworkClient", &networkClient);

    QQmlApplicationEngine engine;

    engine.load("qrc:/main.qml");

    return app.exec();
}
