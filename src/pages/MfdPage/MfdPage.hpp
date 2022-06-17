#ifndef __MFD_PAGE_HPP__
#define __MFD_PAGE_HPP__

#include "FlightPlan/FlightPlan.hpp"
#include "GaugeElement/GaugeElement.hpp"
#include "GeoMap/GeoMap.hpp"
#include "MiscEngineDataElement/MiscEngineDataElement.hpp"

#include <QObject>

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

public:

    explicit MfdPage(io::network::NetworkClient *networkClient, QObject *parent = nullptr);

signals:

    void gaugesLoaded();

public slots:

    void loadAircraft(const definitions::AircraftDefinition &aircraft);

    GaugeElement *gauge1()
    {
        return &d_gauge1;
    }

    GaugeElement *gauge2()
    {
        return &d_gauge2;
    }

    GaugeElement *gauge3()
    {
        return &d_gauge3;
    }

    GaugeElement *gauge4()
    {
        return &d_gauge4;
    }

    GaugeElement *fuelQtyGauge()
    {
        return &d_fuelQtyGauge;
    }

    GaugeElement *fuelFlowGauge()
    {
        return &d_fuelFlowGauge;
    }

    GaugeElement *oilTempGauge()
    {
        return &d_oilTempGauge;
    }

    GaugeElement *egtGauge()
    {
        return &d_egtGauge;
    }

    GaugeElement *oilPressGauge()
    {
        return &d_oilPressGauge;
    }

private:

    void updateChangingGaugeConnections(const definitions::AircraftDefinition &aircraft);

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

    GeoMap d_geoMap;
    FlightPlan d_fpl;


    io::network::NetworkClient *d_networkClient;
};

}  // namespace pages::mfd

#endif  // __MFD_PAGE_HPP__