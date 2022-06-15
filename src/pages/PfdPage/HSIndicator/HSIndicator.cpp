#include "HSIndicator.hpp"

#include "io/NetworkClient/NetworkClient.hpp"

namespace pages::pfd
{

HSIndicator::HSIndicator(io::network::NetworkClient *netClient, QObject *parent)
  : QObject(parent)
{
    using io::network::NetworkClient;
    connect(netClient, &NetworkClient::rotationChanged, this, &HSIndicator::updateRotation);
    connect(netClient, &NetworkClient::turnRateChanged, this, &HSIndicator::updateTurnRate);
    connect(netClient, &NetworkClient::headingChanged, this, &HSIndicator::updateHeading);
    connect(netClient, &NetworkClient::courseChanged, this, &HSIndicator::updateCourse);
    connect(netClient, &NetworkClient::courseDeviationChanged, this, &HSIndicator::updateCourseDeviation);
    connect(netClient, &NetworkClient::displayDeviationChanged, this, &HSIndicator::updateDisplayDeviation);
    connect(netClient, &NetworkClient::navSourceChanged, this, &HSIndicator::updateNavSource);
    connect(netClient, &NetworkClient::currentTrackChanged, this, &HSIndicator::updateCurrentTrack);
    connect(netClient, &NetworkClient::toFromChanged, this, &HSIndicator::updateToFrom);
}

}  // namespace pages::pfd
