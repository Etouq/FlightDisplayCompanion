#include "networkinterface.h"

#include "settings/settingscontroller.h"


NetworkInterface::NetworkInterface(QObject *parent) : QObject(parent)
{
    d_address = SettingsController::lastUsedAddress();
    d_port = SettingsController::lastUsedPort();
}

QString NetworkInterface::address() const
{
    return d_address;
}

int NetworkInterface::port() const
{
    return d_port;
}

QString NetworkInterface::errorString() const
{
    return d_errorString;
}

int NetworkInterface::connected() const
{
    return d_connected;
}

bool NetworkInterface::serverIsDesigner() const
{
    return d_serverIsDesigner;
}

void NetworkInterface::setAddress(const QString &newAddress)
{
    if (newAddress != d_address)
    {
        d_address = newAddress;
        emit addressChanged();
    }
}
void NetworkInterface::setPort(int newPort)
{
    if (newPort != d_port)
    {
        d_port = newPort;
        emit portChanged();
    }
}

void NetworkInterface::buttonPressed()
{
    if (d_connected)
    {
        d_connected = 3;
        emit connectedChanged();
        emit disconnectPressed();
    }
    else
    {
        d_connected = 2;
        SettingsController::setLastUsedAddress(d_address);
        SettingsController::setLastUsedPort(d_port);
        emit connectedChanged();
        emit connectPressed(d_address, d_port);
    }
}


void NetworkInterface::resetButton()
{
    if (d_connected == 2)
    {
        d_connected = 0;
        emit connectedChanged();
    }
    if (d_connected == 3)
    {
        d_connected = 1;
        emit connectedChanged();
    }
}

void NetworkInterface::setNewErrorString(const QString &newError)
{
    if (d_errorString != newError)
    {
        d_errorString = newError;
        emit errorStringChanged();
    }
}

void NetworkInterface::setConnected()
{
    setNewErrorString("");
    if (d_connected != 1)
    {
        d_connected = 1;
        emit connectedChanged();
    }
}

void NetworkInterface::setDisconnected()
{
    if (d_connected != 0)
    {
        d_connected = 0;
        emit connectedChanged();
    }
}
void NetworkInterface::simConnectionClosed()
{
    emit simConnectClosed();
}

void NetworkInterface::connectedToSim()
{
    d_serverIsDesigner = false;
    emit serverIsDesignerChanged();
}

void NetworkInterface::connectedToDesigner()
{
    d_serverIsDesigner = true;
    emit serverIsDesignerChanged();
}
