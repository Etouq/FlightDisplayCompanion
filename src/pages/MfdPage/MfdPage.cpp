#include "MfdPage.hpp"
#include "io/NetworkClient/NetworkClient.hpp"
#include "pages/MfdPage/GaugeElement/GaugeElement.hpp"

using io::network::NetworkClient;

namespace pages::mfd
{

MfdPage::MfdPage(NetworkClient *networkClient, QObject *parent)
  : QObject(parent),
    d_networkClient(networkClient)
{
    // connect signals and slots
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
            &NetworkClient::engineEgtChanged,
            &d_egtGauge,
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
