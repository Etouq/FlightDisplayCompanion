#ifndef AIRCRAFTMANAGER_H
#define AIRCRAFTMANAGER_H

#include <QMap>
#include <QObject>

#include "definitions/aircraftDefinition.h"

class NetworkClient;
class QStringList;

// manages all aircraft definitions and the currently loaded (displayed) aircraft
class AircraftManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool aircraftLoaded MEMBER d_aircraftLoaded NOTIFY aircraftLoadedChanged)

    QMap<QString, AircraftDefinition> allAircraft;

    AircraftDefinition currentAircraft;

    bool d_aircraftLoaded = false; // indicates whether an aircraft is currently loaded

public:
    explicit AircraftManager(QObject *parent = nullptr);

    void initialize();   // fill the allAircraft map

    void connectSlots(NetworkClient *netClient);

    void deleteAircraft(const QString &key);   // remove an aircraft including the files

    // functions used by qml to display the current aircraft
    Q_INVOKABLE int getAircraftType() const;

    Q_INVOKABLE int getNumEngines() const;
    Q_INVOKABLE int getNumTanks() const;
    Q_INVOKABLE QString getName() const;

    Q_INVOKABLE void loadAircraft(const QString &key);   // load and display the aircraft with name key

    // functions used to display the list of all aircraft
    Q_INVOKABLE QList<QString> getKeys() const;
    Q_INVOKABLE QString getImagePath(const QString &name) const;

    // used to send the info required to the simconnect server to change the aircraft
    Q_INVOKABLE void sendSelectedAircraftToSim();
    Q_INVOKABLE void startupSim();

    // used to update default speedbugs, updates saved file too
    Q_INVOKABLE void updateDefaultSpeedbugs(int vr, int vx, int vy, int vapp);

signals:
    void updateAircraft(const AircraftDefinition &aircraft);   // tell gauge backend to update
    void updateAircraftList();                                 // tell qml to update the aircraftlist

    // signals to send the info required to the simconnect server to change the aircraft
    void sendSelectedAircraft(const QByteArray &data);
    void startSim(const QByteArray &data);

    // signals to send data to the gauge designer
    void sendAircraftToDesigner(const AircraftDefinition &aircraft);
    void sendAircraftKeys(const QStringList &keys);

    void aircraftLoadedChanged();

public slots:
    void removeAircraftList(const QStringList &keys); // remove all aircraft with names in keys
    void loadAircraftList(const QStringList &keys); // send all aircraft with names in keys to the designer
    void addAircraft(AircraftDefinition &aircraft, QImage &img);
    void sendFirstAircraftKeys(); // used on connection with gauge designer for first time sending of keys
};

#endif   // AIRCRAFTMANAGER_H
