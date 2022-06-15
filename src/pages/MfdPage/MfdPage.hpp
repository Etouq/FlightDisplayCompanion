#ifndef __MFD_PAGE_HPP__
#define __MFD_PAGE_HPP__

#include "GaugeElement/GaugeElement.hpp"
#include "MiscEngineDataElement/MiscEngineDataElement.hpp"
#include "pages/MfdPage/GaugeElement/GaugeEngine/GaugeEngine.hpp"

#include <QObject>
#include <QQmlContext>

namespace io::network
{
class NetworkClient;
}

namespace definitions
{
struct AircraftDefinition;
}

namespace pages::mfd
{

class MfdPage : public QObject
{
    Q_OBJECT

    // changing gauges
    GaugeElement d_gauge1;
    GaugeElement d_gauge2;
    GaugeElement d_gauge3;
    GaugeElement d_gauge4;

    // regular, mostly present gauges
    GaugeElement d_fuelQtyGauge;
    GaugeElement d_fuelFlowGauge;

    GaugeElement d_oilTempGauge;
    GaugeElement d_egtGauge;
    GaugeElement d_oilPressGauge;

    MiscEngineDataElement d_miscEngineData;


    io::network::NetworkClient *d_networkClient;

public:

    explicit MfdPage(io::network::NetworkClient *networkClient, QObject *parent = nullptr);

    void setContext(QQmlContext *context)
    {
        GaugeElement *gauges[4] = { &d_gauge1, &d_gauge2, &d_gauge3, &d_gauge4 };
        for (size_t gaugeIdx = 0; gaugeIdx <= 3; ++gaugeIdx)
        {
            QString gaugeStr = "gauge" + QString::number(gaugeIdx + 1);
            GaugeElement *gauge = gauges[gaugeIdx];
            GaugeEngine *engines[4] = { gauge->engine1(), gauge->engine2(), gauge->engine3(), gauge->engine4() };
            for (size_t engineIdx = 0; engineIdx <= 3; ++engineIdx)
            {
                QString propertyName = gaugeStr + "Engine" + QString::number(engineIdx + 1);
                context->setContextProperty(propertyName, engines[engineIdx]);
            }
        }

        context->setContextProperty("fuelQtyGauge", &d_fuelQtyGauge);
        context->setContextProperty("fuelFlowGauge", &d_fuelFlowGauge);

        context->setContextProperty("oilTempGauge", &d_oilTempGauge);
        context->setContextProperty("egtGauge", &d_egtGauge);
        context->setContextProperty("oilPressGauge", &d_oilPressGauge);

        context->setContextProperty("miscEngineData", &d_miscEngineData);

        context->setContextProperty("gaugeInterface", this);
    }

private:
    void updateChangingGaugeConnections(const definitions::AircraftDefinition &aircraft);

signals:

    void gaugesLoaded();

public slots:

    void loadAircraft(const definitions::AircraftDefinition &aircraft);

};

}  // namespace pages::mfd

#endif  // __MFD_PAGE_HPP__