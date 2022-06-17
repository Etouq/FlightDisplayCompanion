#include "main.hpp"

#include "io/NetworkClient/NetworkClient.hpp"
#include "pages/MfdPage/MfdPage.hpp"
#include "pages/PfdPage/PfdPage.hpp"
#include "pages/TscPage/TscPage.hpp"

#include <QGuiApplication>
#include <QLocale>
#include <QSurfaceFormat>
#include <QFontDatabase>


int main(int argc, char *argv[])
{
    // initialize application
    QGuiApplication app(argc, argv);
    QGuiApplication::setOrganizationName("nl.Etouq");
    QGuiApplication::setApplicationName("FlightDisplayCompanion");
    QGuiApplication::setApplicationDisplayName("Flight Display Companion");

    QLocale::setDefault(QLocale::c());

    // add roboto font
    QFontDatabase::addApplicationFont("qrc:/fonts/RobotoMono-VariableFont_wght.ttf");

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

    // add networkclient to qml as singleton
    qmlRegisterSingletonInstance("IO.Network", 1, 0, "NetworkClient", &networkClient);


    QQmlApplicationEngine engine;

    engine.load("qrc:/main.qml");

    return app.exec();
}
