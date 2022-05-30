#ifndef GAUGEMANAGER_H
#define GAUGEMANAGER_H

#include <QObject>

#include "gaugebase.hpp"
#include "miscedbase.hpp"

class NetworkClient;
struct AircraftDefinition;
class QQmlContext;

// manages all the gauges and updates them
class GaugeManager : public QObject
{
    Q_OBJECT
    GaugeBase n1Gauge;
    GaugeBase n2Gauge;
    GaugeBase ittGauge;
    GaugeBase rpmGauge;
    GaugeBase secondGauge;
    GaugeBase trqGauge;
    GaugeBase fuelQtyGauge;
    GaugeBase fuelFlowGauge;
    GaugeBase oilPressGauge;
    GaugeBase oilTempGauge;
    GaugeBase egtGauge;
    MiscEDBase commonGaugeProperties;

public:
    explicit GaugeManager(QObject *parent = nullptr);

    void addGaugesToContext(QQmlContext *context);

    void connectSlots(NetworkClient *netClient);

    GaugeBase *getN1Gauge();
    GaugeBase *getN2Gauge();
    GaugeBase *getIttGauge();
    GaugeBase *getRpmGauge();
    GaugeBase *getSecondGauge();
    GaugeBase *getTrqGauge();
    GaugeBase *getFuelQtyGauge();
    GaugeBase *getFuelFlowGauge();
    GaugeBase *getOilTempGauge();
    GaugeBase *getOilPressGauge();
    GaugeBase *getEgtGauge();
    MiscEDBase *getCommonGaugeProperties();

signals:
    void gaugesLoaded();

public slots:
    void changeAircraft(const AircraftDefinition &aircraft);
};

#endif   // GAUGEMANAGER_H
