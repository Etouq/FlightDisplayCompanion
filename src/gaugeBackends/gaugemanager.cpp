#include "gaugemanager.hpp"
#include "networkBackend/networkclient.hpp"
#include "aircraftManager/definitions/aircraftDefinition.hpp"
#include <QQmlContext>
#include "aircraftManager/definitions/jetDefinition.hpp"
#include "aircraftManager/definitions/propDefinition.hpp"
#include "aircraftManager/definitions/turbopropDefinition.hpp"

GaugeManager::GaugeManager(QObject *parent) : QObject(parent)
{
}



void GaugeManager::changeAircraft(const AircraftDefinition& aircraft)
{
    if (aircraft.type == AircraftDefinition::AircraftType::JET)//jet
    {
        JetDefinition jet = aircraft.currentType.value<JetDefinition>();
        if(aircraft.numEngines == 1)
        {
            n1Gauge.setGaugeParameters(jet.n1Gauge, 195, 345);
            n2Gauge.setGaugeParameters(jet.n2Gauge, 225, 315);
            ittGauge.setGaugeParameters(jet.ittGauge, 225, 315);

        }
        else if(aircraft.numEngines == 2)
        {
            n1Gauge.setGaugeParameters(jet.n1Gauge, 225, 315);
            n2Gauge.setGaugeParameters(jet.n2Gauge, 225, 315);
            ittGauge.setGaugeParameters(jet.ittGauge, 225, 315);
        }
        else
        {
            n1Gauge.setGaugeParameters(jet.n1Gauge, 120);
            n2Gauge.setGaugeParameters(jet.n2Gauge, 120);
            ittGauge.setGaugeParameters(jet.ittGauge, 120);
        }

        commonGaugeProperties.setParameters(jet.hasApu, false, aircraft.hasFlaps, aircraft.hasSpoilers, aircraft.hasElevatorTrim, aircraft.hasAileronTrim, aircraft.hasRudderTrim);
    }
    else if(aircraft.type == AircraftDefinition::AircraftType::PROP)
    {
        PropDefinition prop = aircraft.currentType.value<PropDefinition>();
        if (aircraft.numEngines == 1)
        {
            rpmGauge.setGaugeParameters(prop.rpmGauge, 195, 345);
            secondGauge.setGaugeParameters(prop.secondGauge, 195, 345);
        }
        else
        {
            rpmGauge.setGaugeParameters(prop.rpmGauge, 225, 315);
            secondGauge.setGaugeParameters(prop.secondGauge, 225, 315);
        }

        egtGauge.setGaugeParameters(prop.egtGauge, 120);

        commonGaugeProperties.setParameters(false, prop.hasEgt, aircraft.hasFlaps, aircraft.hasSpoilers, aircraft.hasElevatorTrim, aircraft.hasAileronTrim, aircraft.hasRudderTrim);
    }
    else if(aircraft.type == AircraftDefinition::AircraftType::TURBOPROP)
    {
        TurbopropDefinition turboprop = aircraft.currentType.value<TurbopropDefinition>();
        n1Gauge.setGaugeParameters(turboprop.n1Gauge, 225, 315);
        trqGauge.setGaugeParameters(turboprop.trqGauge, 225, 315);

        if (aircraft.numEngines == 1)
        {
            ittGauge.setGaugeParameters(turboprop.ittGauge, 225, 315);
            rpmGauge.setGaugeParameters(turboprop.rpmGauge, 225, 315);
        }
        else
        {
            ittGauge.setGaugeParameters(turboprop.ittGauge, 120);
            rpmGauge.setGaugeParameters(turboprop.rpmGauge, 120);
        }

        egtGauge.setGaugeParameters(turboprop.egtGauge, 120);

        commonGaugeProperties.setParameters(false, turboprop.hasEgt, aircraft.hasFlaps, aircraft.hasSpoilers, aircraft.hasElevatorTrim, aircraft.hasAileronTrim, aircraft.hasRudderTrim);
    }
    else
        return;

    fuelQtyGauge.setGaugeParameters(aircraft.fuelQtyGauge, 120);
    fuelFlowGauge.setGaugeParameters(aircraft.fuelFlowGauge, 120);
    oilTempGauge.setGaugeParameters(aircraft.oilTempGauge, 120);
    oilPressGauge.setGaugeParameters(aircraft.oilPressGauge, 120);

    emit gaugesLoaded();
}

void GaugeManager::connectSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::engine1_n1Changed, &n1Gauge, &GaugeBase::updateEngine1);
    connect(netClient, &NetworkClient::engine2_n1Changed, &n1Gauge, &GaugeBase::updateEngine2);
    connect(netClient, &NetworkClient::engine3_n1Changed, &n1Gauge, &GaugeBase::updateEngine3);
    connect(netClient, &NetworkClient::engine4_n1Changed, &n1Gauge, &GaugeBase::updateEngine4);

    connect(netClient, &NetworkClient::engine1_n2Changed, &n2Gauge, &GaugeBase::updateEngine1);
    connect(netClient, &NetworkClient::engine2_n2Changed, &n2Gauge, &GaugeBase::updateEngine2);
    connect(netClient, &NetworkClient::engine3_n2Changed, &n2Gauge, &GaugeBase::updateEngine3);
    connect(netClient, &NetworkClient::engine4_n2Changed, &n2Gauge, &GaugeBase::updateEngine4);

    connect(netClient, &NetworkClient::engine1_ittChanged, &ittGauge, &GaugeBase::updateEngine1);
    connect(netClient, &NetworkClient::engine2_ittChanged, &ittGauge, &GaugeBase::updateEngine2);
    connect(netClient, &NetworkClient::engine3_ittChanged, &ittGauge, &GaugeBase::updateEngine3);
    connect(netClient, &NetworkClient::engine4_ittChanged, &ittGauge, &GaugeBase::updateEngine4);

    connect(netClient, &NetworkClient::engine1_rpmChanged, &rpmGauge, &GaugeBase::updateEngine1);
    connect(netClient, &NetworkClient::engine2_rpmChanged, &rpmGauge, &GaugeBase::updateEngine2);

    connect(netClient, &NetworkClient::engine1_secondChanged, &secondGauge, &GaugeBase::updateEngine1);
    connect(netClient, &NetworkClient::engine2_secondChanged, &secondGauge, &GaugeBase::updateEngine2);

    connect(netClient, &NetworkClient::engine1_trqChanged, &trqGauge, &GaugeBase::updateEngine1);
    connect(netClient, &NetworkClient::engine2_trqChanged, &trqGauge, &GaugeBase::updateEngine2);

    connect(netClient, &NetworkClient::engine1_fuel_qtyChanged, &fuelQtyGauge, &GaugeBase::updateEngine1);
    connect(netClient, &NetworkClient::engine2_fuel_qtyChanged, &fuelQtyGauge, &GaugeBase::updateEngine2);

    connect(netClient, &NetworkClient::engine1_fuel_flowChanged, &fuelFlowGauge, &GaugeBase::updateEngine1);
    connect(netClient, &NetworkClient::engine2_fuel_flowChanged, &fuelFlowGauge, &GaugeBase::updateEngine2);

    connect(netClient, &NetworkClient::engine1_oil_tempChanged, &oilTempGauge, &GaugeBase::updateEngine1);
    connect(netClient, &NetworkClient::engine2_oil_tempChanged, &oilTempGauge, &GaugeBase::updateEngine2);

    connect(netClient, &NetworkClient::engine1_oil_pressChanged, &oilPressGauge, &GaugeBase::updateEngine1);
    connect(netClient, &NetworkClient::engine2_oil_pressChanged, &oilPressGauge, &GaugeBase::updateEngine2);

    connect(netClient, &NetworkClient::engine1_egtChanged, &egtGauge, &GaugeBase::updateEngine1);
    connect(netClient, &NetworkClient::engine2_egtChanged, &egtGauge, &GaugeBase::updateEngine2);

    connect(netClient, &NetworkClient::spoilers_pctChanged, &commonGaugeProperties, &MiscEDBase::updateSpoilers);
    connect(netClient, &NetworkClient::flaps_angleChanged, &commonGaugeProperties, &MiscEDBase::updateFlaps);
    connect(netClient, &NetworkClient::elev_trim_pctChanged, &commonGaugeProperties, &MiscEDBase::updateElevTrim);
    connect(netClient, &NetworkClient::rudd_trim_pctChanged, &commonGaugeProperties, &MiscEDBase::updateRudderTrim);
    connect(netClient, &NetworkClient::ail_trim_pctChanged, &commonGaugeProperties, &MiscEDBase::updateAileronTrim);
    connect(netClient, &NetworkClient::apu_rpmChanged, &commonGaugeProperties, &MiscEDBase::updateApuRpm);
    connect(netClient, &NetworkClient::fuel_text_dataChanged, &commonGaugeProperties, &MiscEDBase::updateFuelText);
}

void GaugeManager::addGaugesToContext(QQmlContext *context)
{
    context->setContextProperty("n1GaugeItem", &n1Gauge);
    context->setContextProperty("n2GaugeItem", &n2Gauge);
    context->setContextProperty("ittGaugeItem", &ittGauge);

    context->setContextProperty("rpmGaugeItem", &rpmGauge);
    context->setContextProperty("secondGaugeItem", &secondGauge);

    context->setContextProperty("trqGaugeItem", &trqGauge);

    context->setContextProperty("fuelQtyGaugeItem", &fuelQtyGauge);
    context->setContextProperty("fuelFlowGaugeItem", &fuelFlowGauge);

    context->setContextProperty("oilTempGaugeItem", &oilTempGauge);
    context->setContextProperty("oilPressGaugeItem", &oilPressGauge);
    context->setContextProperty("egtGaugeItem", &egtGauge);

    context->setContextProperty("commonGaugeProperties", &commonGaugeProperties);

    context->setContextProperty("gaugeInterface", this);
}

GaugeBase* GaugeManager::getN1Gauge() { return &n1Gauge; }
GaugeBase* GaugeManager::getN2Gauge() { return &n2Gauge; }
GaugeBase* GaugeManager::getIttGauge() { return &ittGauge; }
GaugeBase* GaugeManager::getRpmGauge() { return &rpmGauge; }
GaugeBase* GaugeManager::getSecondGauge() { return &secondGauge; }
GaugeBase* GaugeManager::getTrqGauge() { return &trqGauge; }
GaugeBase* GaugeManager::getFuelQtyGauge() { return &fuelQtyGauge; }
GaugeBase* GaugeManager::getFuelFlowGauge() { return &fuelFlowGauge; }
GaugeBase* GaugeManager::getOilTempGauge() { return &oilTempGauge; }
GaugeBase* GaugeManager::getOilPressGauge() { return &oilPressGauge; }
GaugeBase* GaugeManager::getEgtGauge() { return &egtGauge; }
MiscEDBase* GaugeManager::getCommonGaugeProperties() { return &commonGaugeProperties; }




