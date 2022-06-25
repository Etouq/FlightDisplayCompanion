#ifndef __MFD_PAGE_HPP__
#define __MFD_PAGE_HPP__

#include "FlightPlan/FlightPlan.hpp"
#include "GaugeElement/GaugeElement.hpp"
#include "GeoMapPage/GeoMapPage.hpp"
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

    void loadAircraft(const definitions::AircraftDefinition &aircraft);

signals:

    void gaugesLoaded(const QString &layoutPath);

public slots:

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

    GaugeElement *oilPressGauge()
    {
        return &d_oilPressGauge;
    }

    GaugeElement *secondaryTempGauge()
    {
        return &d_secondaryTempGauge;
    }

private:

    // changing gauges
    GaugeElement d_gauge1;
    GaugeElement d_gauge2;
    GaugeElement d_gauge3;
    GaugeElement d_gauge4;


    // regular, mostly present gauges
    GaugeElement d_fuelQtyGauge;
    GaugeElement d_fuelFlowGauge;

    GaugeElement d_oilTempGauge;
    GaugeElement d_secondaryTempGauge;
    GaugeElement d_oilPressGauge;

    MiscEngineDataElement d_miscEngineData;

    GeoMapPage d_geoMapPage;
    FlightPlan d_fpl;


    io::network::NetworkClient *d_networkClient;
};

}  // namespace pages::mfd

#endif  // __MFD_PAGE_HPP__
