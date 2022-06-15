#include "HSIBearings.hpp"

#include "io/NetworkClient/NetworkClient.hpp"
#include <qobject.h>

namespace pages::pfd
{

HSIBearings::HSIBearings(io::network::NetworkClient *netClient, QObject *parent)
: QObject(parent)
{
    using io::network::NetworkClient;
    connect(netClient, &NetworkClient::nav1IdentChanged, this, &HSIBearings::updateNav1Ident);
    connect(netClient, &NetworkClient::nav1DmeChanged, this, &HSIBearings::updateNav1Dme);
    connect(netClient, &NetworkClient::nav1BearingChanged, this, &HSIBearings::updateNav1Bearing);
    connect(netClient, &NetworkClient::nav1HasNavChanged, this, &HSIBearings::updateNav1HasNav);
    connect(netClient, &NetworkClient::nav1HasSignalChanged, this, &HSIBearings::updateNav1HasSignal);
    connect(netClient, &NetworkClient::nav1HasDmeChanged, this, &HSIBearings::updateNav1HasDme);
    connect(netClient, &NetworkClient::nav1FreqChanged, this, &HSIBearings::updateNav1Freq);

    connect(netClient, &NetworkClient::nav2IdentChanged, this, &HSIBearings::updateNav2Ident);
    connect(netClient, &NetworkClient::nav2DmeChanged, this, &HSIBearings::updateNav2Dme);
    connect(netClient, &NetworkClient::nav2BearingChanged, this, &HSIBearings::updateNav2Bearing);
    connect(netClient, &NetworkClient::nav2HasNavChanged, this, &HSIBearings::updateNav2HasNav);
    connect(netClient, &NetworkClient::nav2HasSignalChanged, this, &HSIBearings::updateNav2HasSignal);
    connect(netClient, &NetworkClient::nav2HasDmeChanged, this, &HSIBearings::updateNav2HasDme);
    connect(netClient, &NetworkClient::nav2FreqChanged, this, &HSIBearings::updateNav2Freq);

    connect(netClient, &NetworkClient::currentLegToChanged, this, &HSIBearings::updateGpsIdent);
    connect(netClient, &NetworkClient::gpsDistanceChanged, this, &HSIBearings::updateGpsDistance);
    connect(netClient, &NetworkClient::gpsBearingChanged, this, &HSIBearings::updateGpsBearing);

    connect(netClient, &NetworkClient::adfHasSignalChanged, this, &HSIBearings::updateAdfHasSignal);
    connect(netClient, &NetworkClient::adfFreqChanged, this, &HSIBearings::updateAdfFreq);
    connect(netClient, &NetworkClient::adfRadialChanged, this, &HSIBearings::updateAdfRadial);

}

}
