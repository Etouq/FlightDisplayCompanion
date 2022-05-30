#include "aircraftmanager.h"

#include <QStringList>

#include "aircraftInitializer/aircraftinitializer.h"
#include "aircraftfile.h"
#include "networkBackend/networkclient.h"
#include "settings/settingscontroller.h"


AircraftManager::AircraftManager(QObject *parent) : QObject(parent)
{
}

void AircraftManager::connectSlots(NetworkClient *netClient)
{
    connect(this, &AircraftManager::sendSelectedAircraft, netClient, &NetworkClient::changeAircraft);
    connect(this, &AircraftManager::startSim, netClient, &NetworkClient::startSim);

    connect(this, &AircraftManager::sendAircraftToDesigner, netClient, &NetworkClient::sendAircraftToDesigner);
    connect(this, &AircraftManager::sendAircraftKeys, netClient, &NetworkClient::sendAircraftKeys);

    connect(netClient, &NetworkClient::remove_aircraft_list, this, &AircraftManager::removeAircraftList);
    connect(netClient, &NetworkClient::load_aircraft_list, this, &AircraftManager::loadAircraftList);
    connect(netClient, &NetworkClient::save_aircraft, this, &AircraftManager::addAircraft);
    connect(netClient, &NetworkClient::connectedToGaugeDesigner, this, &AircraftManager::sendFirstAircraftKeys);
}

void AircraftManager::addAircraft(AircraftDefinition &aircraft, QImage &img)
{
    allAircraft[aircraft.name] = aircraft;
    if (currentAircraft.name == aircraft.name)
    {
        currentAircraft = aircraft;
        emit updateAircraft(currentAircraft);
    }
    AircraftFile::saveAircraftWithImage(aircraft, img);
    emit sendAircraftKeys(allAircraft.keys());
    emit updateAircraftList();
}

void AircraftManager::initialize()
{
    AircraftFile::init();
    if (!SettingsController::firstTimeSetupCompleted())
    {
        AircraftInitializer::initAircraft(allAircraft);
        SettingsController::setFirstTimeSetupCompleted(true);
    }
    else
        AircraftFile::readAllAircraftFiles(allAircraft);
    emit updateAircraftList();
}

void AircraftManager::removeAircraftList(const QStringList &keys)
{
    for (int i = 0; i < keys.size(); i++)
    {
        allAircraft.remove(keys[i]);
        AircraftFile::removeAircraft(keys[i]);
    }

    emit sendAircraftKeys(allAircraft.keys());
    emit updateAircraftList();
}

void AircraftManager::loadAircraftList(const QStringList &keys)
{
    for (int i = 0; i < keys.size(); i++)
    {
        emit sendAircraftToDesigner(allAircraft[keys[i]]);
    }
}

int AircraftManager::getAircraftType() const
{
    switch (currentAircraft.type)
    {
        case AircraftDefinition::AircraftType::JET:
            return 0;
        case AircraftDefinition::AircraftType::PROP:
            return 1;
        case AircraftDefinition::AircraftType::TURBOPROP:
            return 2;
        case AircraftDefinition::AircraftType::INVALID:
            return -1;
    }
}

void AircraftManager::loadAircraft(const QString &key)
{
    currentAircraft = allAircraft[key];
    emit updateAircraft(currentAircraft);
}

QList<QString> AircraftManager::getKeys() const
{
    return allAircraft.keys();
}

void AircraftManager::sendSelectedAircraftToSim()
{
    emit sendSelectedAircraft(currentAircraft.toNetworkData());
}

void AircraftManager::startupSim()
{
    emit startSim(currentAircraft.toNetworkData());
}

void AircraftManager::updateDefaultSpeedbugs(int vr, int vx, int vy, int vapp)
{
    currentAircraft.defaultVr = vr;
    currentAircraft.defaultVx = vx;
    currentAircraft.defaultVy = vy;
    currentAircraft.defaultVapp = vapp;

    allAircraft[currentAircraft.name].defaultVr = vr;
    allAircraft[currentAircraft.name].defaultVx = vx;
    allAircraft[currentAircraft.name].defaultVy = vy;
    allAircraft[currentAircraft.name].defaultVapp = vapp;

    AircraftFile::saveAircraftToFile(currentAircraft);
    emit updateAircraft(currentAircraft);
}

QString AircraftManager::getImagePath(const QString &name) const
{
    return "file:/" + AircraftFile::getImagePath(name);
}

void AircraftManager::deleteAircraft(const QString &key)
{
    allAircraft.remove(key);
    AircraftFile::removeAircraft(key);
    emit sendAircraftKeys(allAircraft.keys());
    emit updateAircraftList();
}

void AircraftManager::sendFirstAircraftKeys()
{
    emit sendAircraftKeys(allAircraft.keys());
}


int AircraftManager::getNumEngines() const
{
    return currentAircraft.numEngines;
}

int AircraftManager::getNumTanks() const
{
    return currentAircraft.numTanks;
}

QString AircraftManager::getName() const
{
    return currentAircraft.name;
}
