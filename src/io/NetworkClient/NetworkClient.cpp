#include "NetworkClient.hpp"
#include <QQmlEngine>

namespace io::network
{
NetworkClient::NetworkClient(QObject *parent)
  : QObject(parent)
{
    qmlRegisterSingletonInstance("IO.Network", 1, 0, "NetworkClient", this);
}
}  // namespace io::network
