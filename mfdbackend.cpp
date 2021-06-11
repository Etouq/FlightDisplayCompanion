#include "mfdbackend.h"

#include <QFile>

#include "binaryutil.h"
#include "networkBackend/networkclient.h"
#include "settings/settingscontroller.h"

MfdBackend::MfdBackend(QObject *parent) : QObject(parent)
{
}

void MfdBackend::connectSlots(NetworkClient *netClient)
{
    connect(netClient, &NetworkClient::coordinates_Changed, this, &MfdBackend::updateCoordinates);
    connect(netClient, &NetworkClient::true_headingChanged, this, &MfdBackend::updatePlaneTrueHdg);

    connect(netClient, &NetworkClient::gps_wp_desired_trackChanged, this, &MfdBackend::updateDtk);
    connect(netClient, &NetworkClient::zulu_secondsChanged, this, &MfdBackend::updateZulu);
    connect(netClient, &NetworkClient::gps_wp_eteChanged, this, &MfdBackend::updateWpEte);
    connect(netClient, &NetworkClient::gps_eteChanged, this, &MfdBackend::updateEte);

    connect(netClient, &NetworkClient::clear_flightplan_received, this, &MfdBackend::clearFlightplan);
    connect(netClient, &NetworkClient::received_flightplan, this, &MfdBackend::receivedFlightplan);

    connect(netClient, &NetworkClient::sim_start_received, this, &MfdBackend::simStartEvent);
    connect(netClient, &NetworkClient::sim_stop_received, this, &MfdBackend::simStopEvent);
}

void MfdBackend::updateDtk(double newValue)
{
    gps_wp_desired_track = newValue;
    emit gps_dtkChanged();
}

void MfdBackend::updateWpEte(int newValue)
{
    if (newValue == 0)
        gps_wp_ete = "__:__";
    else if (newValue < 3600)
    {
        int sec = newValue % 60;
        gps_wp_ete = QString("%1:%2").arg(sec / 60).arg(sec, 2, 10, QChar('0'));
    }
    else
    {
        int min = (newValue % 3600) / 60;
        gps_wp_ete = QString("%1:%2").arg(newValue / 3600).arg(min, 2, 10, QChar('0'));
    }
    emit eteChanged();
}

void MfdBackend::updateEte(int newValue)
{
    gps_ete = newValue;
    if (gps_ete == 0)
        gps_eta = "__:__UTC";
    else
    {
        int etaSec = (zulu_time + gps_ete) % (24 * 3600);
        int hours = etaSec / 3600;
        int minutes = (etaSec / 60) % 60;
        gps_eta = QString("%1:%2UTC").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0'));
    }
    emit etaChanged();
}

void MfdBackend::updateZulu(int newValue)
{
    zulu_time = newValue;
    if (gps_ete == 0)
        gps_eta = "__:__UTC";
    else
    {
        int etaSec = (zulu_time + gps_ete) % (24 * 3600);
        int hours = etaSec / 3600;
        int minutes = (etaSec / 60) % 60;
        gps_eta = QString("%1:%2UTC").arg(hours, 2, 10, QChar('0')).arg(minutes, 2, 10, QChar('0'));
    }
    emit etaChanged();
}


void MfdBackend::saveFlightplan()
{
    QString dataPath = SettingsController::dataPath();
    QFile flightplanFile(dataPath + "/lastFlightplan.bin");
    flightplanFile.open(QIODevice::WriteOnly | QIODevice::Truncate);

    FlightplanFileVersion version = latestVersion;
    flightplanFile.write(reinterpret_cast<char *>(&version), sizeof(version));

    flightplanFile.write(BinaryUtil::toBinary(flightPlanVec));
}

void MfdBackend::loadFlightplan()
{
    QString dataPath = SettingsController::dataPath();
    QFile flightplanFile(dataPath + "/lastFlightplan.bin");
    if (flightplanFile.exists())
    {
        flightplanFile.open(QIODevice::ReadOnly);
        FlightplanFileVersion version = V1;
        flightplanFile.read(reinterpret_cast<char *>(&version), sizeof(version));

        if (version == latestVersion)
        {
            flightPlanVec = BinaryUtil::readFpVec(flightplanFile);
            emit flightplanChanged();
        }
    }
}

double MfdBackend::planeTrueHdg() const
{
    return plane_hdg_degrees_true;
}

double MfdBackend::gps_dtk() const
{
    return gps_wp_desired_track;
}

QString MfdBackend::ete() const
{
    return gps_wp_ete;
}

QString MfdBackend::eta() const
{
    return gps_eta;
}

int MfdBackend::getFlightPlanSize() const
{
    return static_cast<int>(flightPlanVec.size());
}

QGeoCoordinate MfdBackend::getFpPositionAt(int idx) const
{
    return flightPlanVec[idx].position;
}

int MfdBackend::getFpAltitude1At(int idx) const
{
    return flightPlanVec[idx].alt1;
}

int MfdBackend::getFpAltitude2At(int idx) const
{
    return flightPlanVec[idx].alt2;
}

QString MfdBackend::getFpIdentAt(int idx) const
{
    return flightPlanVec[idx].ident;
}

int MfdBackend::getFpWpTypeAt(int idx) const
{
    return flightPlanVec[idx].wpType;
}

int MfdBackend::getFpAltTypeAt(int idx) const
{
    return flightPlanVec[idx].altType;
}

double MfdBackend::getFpLegDistanceAt(int idx) const
{
    if (idx == 0)
        return -1.0;
    return flightPlanVec[idx - 1].position.distanceTo(flightPlanVec[idx].position) / 1852.0;
}

double MfdBackend::getFpCumulativeDistanceAt(int idx) const
{
    if (idx == 0)
        return -1.0;
    double totalDist = 0.0;
    for (int i = 1; i <= idx; i++)
        totalDist += flightPlanVec[i - 1].position.distanceTo(flightPlanVec[i].position);
    return totalDist / 1852.0;
}

int MfdBackend::getFpBearingAt(int idx) const
{
    if (idx == 0)
        return -1.0;
    return static_cast<int>(flightPlanVec[idx - 1].position.azimuthTo(flightPlanVec[idx].position) + 0.5);
}

void MfdBackend::qmlClearFlightPlan()
{
    flightPlanVec.clear();
    emit flightplanChanged();
}

void MfdBackend::qmlAppendFpWaypoint(double lat, double lon, QString ident, int wpType, int alt1, int alt2, int altType)
{
    FlightPlanWaypoint newWp;
    newWp.position = QGeoCoordinate(lat, lon);
    newWp.ident = ident.toUpper();
    newWp.wpType = wpType;
    newWp.alt1 = alt1;
    newWp.alt2 = alt2;
    newWp.altType = altType;
    flightPlanVec.push_back(newWp);
    emit flightplanChanged();
}

void MfdBackend::qmlInsertFpWaypoint(int idx, double lat, double lon, QString ident, int wpType, int alt1, int alt2, int altType)
{
    FlightPlanWaypoint newWp;
    newWp.position = QGeoCoordinate(lat, lon);
    newWp.ident = ident.toUpper();
    newWp.wpType = wpType;
    newWp.alt1 = alt1;
    newWp.alt2 = alt2;
    newWp.altType = altType;
    flightPlanVec.insert(flightPlanVec.begin() + idx, newWp);
    emit flightplanChanged();
}

void MfdBackend::qmlDeleteFpWaypoint(int idx)
{
    flightPlanVec.erase(flightPlanVec.begin() + idx);
    emit flightplanChanged();
}

void MfdBackend::qmlEditFpWaypoint(int idx, double lat, double lon, QString ident, int wpType, int alt1, int alt2, int altType)
{
    flightPlanVec[idx].position = QGeoCoordinate(lat, lon);
    flightPlanVec[idx].ident = ident.toUpper();
    flightPlanVec[idx].wpType = wpType;
    flightPlanVec[idx].alt1 = alt1;
    flightPlanVec[idx].alt2 = alt2;
    flightPlanVec[idx].altType = altType;
    emit flightplanChanged();
}

void MfdBackend::qmlDirectTo(double lat, double lon, QString ident, int wpType, int alt1, int alt2, int altType, int currAlt)
{
    flightPlanVec.clear();
    FlightPlanWaypoint currWp;
    currWp.position = d_currCoordinates;
    currWp.ident = "USER";
    currWp.wpType = 3;
    currWp.alt1 = currAlt;
    currWp.alt2 = 0;
    currWp.altType = 0;
    flightPlanVec.push_back(currWp);

    FlightPlanWaypoint newWp;
    newWp.position = QGeoCoordinate(lat, lon);
    newWp.ident = ident.toUpper();
    newWp.wpType = wpType;
    newWp.alt1 = alt1;
    newWp.alt2 = alt2;
    newWp.altType = altType;
    flightPlanVec.push_back(newWp);
    emit flightplanChanged();
}

QGeoCoordinate MfdBackend::currCoordinates() const
{
    return d_currCoordinates;
}

bool MfdBackend::simRunning() const
{
    return d_simRunning;
}

void MfdBackend::updatePlaneTrueHdg(double newValue)
{
    plane_hdg_degrees_true = newValue;
    emit planeTrueHdgChanged();
}

void MfdBackend::updateCoordinates(const QGeoCoordinate &newCoord)
{
    d_currCoordinates = newCoord;
    emit currCoordinatesChanged();
}

void MfdBackend::simStartEvent()
{
    d_simRunning = true;
    emit simRunningChanged();
}

void MfdBackend::simStopEvent()
{
    d_simRunning = false;
    emit simRunningChanged();
}

void MfdBackend::clearFlightplan()
{
    flightPlanVec.clear();
    emit flightplanChanged();
}

void MfdBackend::receivedFlightplan(const QList<FlightPlanWaypoint> &wpList)
{
    flightPlanVec = wpList.toVector();
    emit flightplanChanged();
}
