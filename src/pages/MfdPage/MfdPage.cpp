#include "MfdPage.hpp"
#include "io/NetworkClient/NetworkClient.hpp"
#include "GaugeElement/GaugeElement.hpp"
#include <QQmlEngine>

using io::network::NetworkClient;

namespace pages::mfd
{

MfdPage::MfdPage(NetworkClient *networkClient, QObject *parent)
  : QObject(parent),
    d_networkClient(networkClient),
    d_geoMapPage(networkClient),
    d_fpl(networkClient)
{
    qmlRegisterSingletonInstance("Mfd.GeoMapPage", 1, 0, "GeoMapPage", &d_geoMapPage);
    qmlRegisterSingletonInstance("Mfd.Flightplan", 1, 0, "Flightplan", &d_fpl);
    qmlRegisterSingletonInstance("Mfd.Engine", 1, 0, "EngineMisc", &d_miscEngineData);
    qmlRegisterUncreatableType<GaugeElement>("Mfd.Engine", 1, 0, "GaugeData", "Bad Boy");
    qmlRegisterUncreatableType<GaugeEngine>("Mfd.Engine", 1, 0, "GaugeEngine", "Bad Boy");

    QQmlEngine::setObjectOwnership(&d_gauge1, QQmlEngine::CppOwnership);
    QQmlEngine::setObjectOwnership(&d_gauge2, QQmlEngine::CppOwnership);
    QQmlEngine::setObjectOwnership(&d_gauge3, QQmlEngine::CppOwnership);
    QQmlEngine::setObjectOwnership(&d_gauge4, QQmlEngine::CppOwnership);
    QQmlEngine::setObjectOwnership(&d_fuelQtyGauge, QQmlEngine::CppOwnership);
    QQmlEngine::setObjectOwnership(&d_fuelFlowGauge, QQmlEngine::CppOwnership);
    QQmlEngine::setObjectOwnership(&d_oilTempGauge, QQmlEngine::CppOwnership);
    QQmlEngine::setObjectOwnership(&d_oilPressGauge, QQmlEngine::CppOwnership);
    QQmlEngine::setObjectOwnership(&d_miscEngineData, QQmlEngine::CppOwnership);
    QQmlEngine::setObjectOwnership(&d_secondaryTempGauge, QQmlEngine::CppOwnership);

    // connect signals and slots
    connect(d_networkClient,
            &NetworkClient::engineGauge1Changed,
            &d_gauge1,
            &GaugeElement::update);
    connect(d_networkClient,
            &NetworkClient::engineGauge2Changed,
            &d_gauge2,
            &GaugeElement::update);
    connect(d_networkClient,
            &NetworkClient::engineGauge3Changed,
            &d_gauge3,
            &GaugeElement::update);
    connect(d_networkClient,
            &NetworkClient::engineGauge4Changed,
            &d_gauge4,
            &GaugeElement::update);


    connect(d_networkClient,
            &NetworkClient::fuelLeftQtyChanged,
            d_fuelQtyGauge.engine1(),
            &GaugeEngine::update);
    connect(d_networkClient,
            &NetworkClient::fuelRightQtyChanged,
            d_fuelQtyGauge.engine2(),
            &GaugeEngine::update);
    connect(d_networkClient,
            &NetworkClient::engineFuelFlowChanged,
            &d_fuelFlowGauge,
            &GaugeElement::update);

    connect(d_networkClient,
            &NetworkClient::engineOilTempChanged,
            &d_oilTempGauge,
            &GaugeElement::update);
    connect(d_networkClient,
            &NetworkClient::engineSecondaryTempChanged,
            &d_secondaryTempGauge,
            &GaugeElement::update);
    connect(d_networkClient,
            &NetworkClient::engineOilPressChanged,
            &d_oilPressGauge,
            &GaugeElement::update);


    connect(d_networkClient,
            &NetworkClient::fuelTextDataChanged,
            &d_miscEngineData,
            &MiscEngineDataElement::updateFuelText);

    connect(d_networkClient,
            &NetworkClient::apuN1Changed,
            &d_miscEngineData,
            &MiscEngineDataElement::updateApuRpm);

    connect(d_networkClient,
            &NetworkClient::spoilersPctChanged,
            &d_miscEngineData,
            &MiscEngineDataElement::updateSpoilers);
    connect(d_networkClient,
            &NetworkClient::flapsAngleChanged,
            &d_miscEngineData,
            &MiscEngineDataElement::updateFlaps);

    connect(d_networkClient,
            &NetworkClient::elevTrimChanged,
            &d_miscEngineData,
            &MiscEngineDataElement::updateElevTrim);
    connect(d_networkClient,
            &NetworkClient::ruddTrimChanged,
            &d_miscEngineData,
            &MiscEngineDataElement::updateRudderTrim);
    connect(d_networkClient,
            &NetworkClient::ailTrimChanged,
            &d_miscEngineData,
            &MiscEngineDataElement::updateAileronTrim);
}

}  // namespace pages::mfd
