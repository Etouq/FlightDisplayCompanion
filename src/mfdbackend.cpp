#include "mfdbackend.hpp"

#include <QFile>

#include "binaryutil.hpp"
#include "networkBackend/networkclient.hpp"
#include "settings/settingscontroller.hpp"

const QString MfdBackend::d_defaultPlanePath = "M 37.759575 88.151385 A 12.222 12.222 90 0 1 38.221575 85.463385 A 4.011 4.011 90 0 1 40.111575 83.363385 L 47.608575 80.549385 A 2.247 2.247 90 0 0 48.259575 78.806385 L 47.251575 62.132385 L 20.959575 70.007385 A 0.756 0.756 90 0 1 19.972575 69.335385 C 19.783575 67.235385 19.804575 65.723385 21.484575 64.484385 L 46.726575 46.151385 A 0.924 0.924 90 0 0 47.062575 45.458385 C 47.188575 42.728385 47.776575 27.629385 48.196575 24.458385 A 12.6 12.6 90 0 1 50.548575 17.549385 A 2.415 2.415 90 0 1 53.950575 17.549385 A 12.768 12.768 90 0 1 56.365575 24.437385 C 56.806575 27.692385 57.520575 42.791385 57.667575 45.437385 A 0.84 0.84 90 0 0 58.003575 46.109385 L 83.497575 64.253385 C 85.177575 65.471385 85.219575 67.004385 85.030575 69.083385 A 0.735 0.735 90 0 1 84.064575 69.755385 L 57.709575 62.153385 L 56.848575 78.953385 A 2.1 2.1 90 0 0 57.499575 80.675385 L 65.059575 83.321385 A 4.2 4.2 90 0 1 66.949575 85.421385 A 13.944 13.944 90 0 1 67.432575 88.109385 Z";
const QString MfdBackend::d_cursorIconPath = "M 49.8756259317 71.453499484 Q 52.5 70 55.1243740683 71.453499484 L 80.6260432196 85.5775008601 Q 85 88 82.9189315549 83.4536658584 L 54.5810684451 21.5463341416 Q 52.5 17 50.4189315549 21.5463341416 L 22.0810684451 83.4536658584 Q 20 88 24.3739567804 85.5775008601 Z";
const QString MfdBackend::d_triangleIconPath = "M 80 88 Q 85 88 82.9189315549 83.4536658584 L 54.5810684451 21.5463341416 Q 52.5 17 50.4189315549 21.5463341416 L 22.0810684451 83.4536658584 Q 20 88 25 88 Z";
const QString MfdBackend::d_airlinerIconPath = "M 82.74 60.48 L 68.556 50.304 A 2.76 2.76 0 0 0 68.7 49.416 V 41.88 H 63.42 V 46.68 L 58.068 42.816 A 0.816 0.816 0 0 1 57.756 42.168 C 57.612 39.504 56.988 27.576 56.556 24.408 A 12.216 12.216 0 0 0 54.156 17.712 C 53.7 17.232 53.1 16.44 52.5 16.464 S 51.3 17.232 50.844 17.712 A 12.216 12.216 0 0 0 48.444 24.408 C 48.012 27.576 47.388 39.504 47.244 42.168 A 0.816 0.816 0 0 1 46.932 42.816 L 41.58 46.656 V 41.856 H 36.3 V 49.392 A 2.76 2.76 0 0 0 36.444 50.28 L 22.26 60.456 C 20.628 61.656 20.604 63.144 20.772 65.256 A 0.72 0.72 0 0 0 21.732 65.904 C 25.236 64.32 39.204 58.704 39.204 58.704 L 47.292 58.44 L 48.204 75.096 A 2.4 2.4 0 0 1 47.46 76.92 L 38.196 84.84 C 37.788 85.296 37.932 85.728 37.908 86.28 C 37.908 87.312 38.124 87.792 39.732 87.336 L 50.244 84.936 L 50.58 85.8 C 50.916 86.736 51.276 88.536 52.404 88.536 S 53.892 86.736 54.228 85.8 L 54.564 84.936 L 65.076 87.336 C 66.684 87.792 66.924 87.336 66.9 86.28 C 66.9 85.728 67.02 85.296 66.612 84.84 L 57.348 76.92 A 2.4 2.4 0 0 1 56.604 75.096 L 57.516 58.44 L 65.604 58.704 S 79.572 64.32 83.076 65.904 A 0.72 0.72 0 0 0 84.036 65.256 C 84.396 63.168 84.372 61.68 82.74 60.48 Z";
const QString MfdBackend::d_gliderIconPath = "M 86.751 52.311 V 45.612 L 54.6 42.567 C 54.6 42.168 54.6 41.79 54.6 41.496 A 61.614 61.614 0 0 0 56.511 32.382 C 56.931 23.94 54.201 21 52.5 21 S 48.069 23.94 48.426 32.382 A 61.614 61.614 0 0 0 50.4 41.496 C 50.4 41.79 50.4 42.168 50.4 42.567 L 18.249 45.612 V 52.311 H 50.4 C 50.547 62.706 50.715 76.692 50.904 79.779 L 44.751 81.69 V 84 H 60.081 V 81.69 L 54.012 79.8 C 54.201 76.713 54.369 62.727 54.516 52.332 Z";
const QString MfdBackend::d_glider2IconPath = "M 85.78 60.75 C 85.52 57.33 54.5 41.57 52.5 39.91 C 50.5 41.57 19.48 57.33 19.22 60.75 C 19.02 63.29 21.96 62.75 22.86 62.75 C 24.76 62.75 31.62 61.75 32.4 61.79 L 52.5 60.29 L 72.5 61.71 C 73.28 61.71 80.14 62.67 82.04 62.67 C 83.04 62.67 85.98 63.29 85.78 60.75 Z M 51.36 62.45 L 51.12 62.25 C 50.04 61.01 49.4 62.45 48.98 59.29 C 48.82 58.07 48.62 57.13 48.44 56.29 H 56.5 C 56.32 57.13 56.12 58.07 55.96 59.29 C 55.54 62.45 54.9 61.01 53.82 62.25 L 53.58 62.45 V 64.05 H 59.8 V 65.09 H 45.14 V 64.05 H 51.36 Z";
const QString MfdBackend::d_jetIconPath = "M 75.633 53.666 V 61.102 L 75.215 60.772 L 57.175 48.826 A 0.814 0.814 0 0 1 56.889 48.232 C 56.889 45.856 56.207 36.242 55.833 33.426 C 55.283 29.334 54.381 20.864 52.489 19.5 C 50.597 20.864 49.695 29.334 49.145 33.426 C 48.771 36.242 48.199 45.856 48.089 48.232 A 0.814 0.814 0 0 1 47.803 48.826 L 29.763 60.772 L 29.345 61.102 V 53.666 H 27.563 V 67.9 H 29.345 V 65.986 H 48.089 L 47.649 75.556 A 1.65 1.65 0 0 1 46.901 77.052 L 41.819 79.472 L 39.773 83.762 A 0.968 0.968 0 0 0 39.773 84.224 H 50.069 V 85.5 H 54.777 V 84.114 H 65.073 A 0.968 0.968 0 0 0 65.073 83.652 L 63.027 79.362 L 57.945 76.942 A 1.65 1.65 0 0 1 57.197 75.446 L 56.889 65.876 H 75.655 V 67.9 H 77.437 V 53.666 Z";
const QString MfdBackend::d_propIconPath = "M 58.7858 46.299 L 85.0738 42.9706 V 36.2926 L 57.5138 33.9818 A 0.7208 0.7208 0 0 1 57.217 33.367 C 57.0898 30.8654 56.475 29.5722 56.0722 26.583 S 55.0122 24.8446 53.9522 23.5938 L 53.6978 23.3818 V 21.7706 H 60.0578 V 20.7106 H 44.9422 V 21.7706 H 51.3022 V 23.3818 L 51.0478 23.5938 C 49.9454 24.8446 49.3094 23.3818 48.9278 26.583 S 47.9102 30.823 47.783 33.367 A 0.7208 0.7208 0 0 1 47.4862 33.9818 L 19.9262 36.2926 V 42.9706 L 46.0658 46.299 A 1.8868 1.8868 0 0 1 47.7406 48.101 L 49.6486 70.9546 C 49.6486 71.103 49.6486 71.2302 49.6486 71.3362 A 1.802 1.802 0 0 1 48.4402 72.7778 L 44.497 73.3926 C 44.2638 73.3926 43.5218 73.5198 42.695 73.7106 V 78.2262 A 13.2712 13.2712 0 0 0 44.4546 78.523 H 47.783 A 1.9504 1.9504 0 0 1 50.009 79.5406 C 50.4118 80.3462 51.387 84.1834 52.3834 84.2894 S 54.355 80.3462 54.7578 79.5406 A 1.9504 1.9504 0 0 1 56.9838 78.523 H 60.3122 A 13.2712 13.2712 0 0 0 62.0718 78.2262 V 73.7106 C 61.245 73.5198 60.503 73.4562 60.2698 73.3926 L 56.3266 72.7778 A 1.802 1.802 0 0 1 55.1182 71.3362 C 55.1182 71.2302 55.1182 71.103 55.1182 70.9546 L 57.0262 48.101 A 1.8868 1.8868 0 0 1 58.7858 46.299 Z";
const QString MfdBackend::d_turbopropIconPath = "M 73.378 38.244 V 35.428 A 1.276 1.276 0 0 0 72.124 34.174 H 70.98 V 32.392 H 77.118 V 31.358 H 62.51 V 32.392 H 68.648 V 34.174 H 67.438 A 1.276 1.276 0 0 0 66.184 35.428 V 37.628 L 57.384 36.748 A 0.726 0.726 0 0 1 57.076 36.154 C 56.966 33.712 56.372 29.246 55.998 26.342 A 11 11 0 0 0 53.798 20.226 A 1.87 1.87 0 0 0 51.026 20.226 A 11 11 0 0 0 48.826 26.342 C 48.452 29.246 47.858 33.712 47.748 36.154 A 0.726 0.726 0 0 1 47.44 36.748 L 38.64 37.628 V 35.428 A 1.276 1.276 0 0 0 37.386 34.174 H 36.176 V 32.392 H 42.314 V 31.358 H 27.882 V 32.392 H 34.02 V 34.174 H 32.81 A 1.276 1.276 0 0 0 31.556 35.428 V 38.244 L 24.956 38.882 C 19.434 40.224 16.64 43.568 24.472 45.284 L 31.468 46.428 V 47.66 A 3.344 3.344 0 0 0 34.9 51.004 H 35.428 A 3.366 3.366 0 0 0 38.794 47.66 L 40.51 47.946 L 46.34 48.606 A 1.87 1.87 0 0 1 48.1 50.3 L 49.948 72.498 A 1.936 1.936 0 0 1 49.948 72.85 A 1.716 1.716 0 0 1 48.782 74.258 L 44.954 74.852 C 44.338 75.006 40.4 75.16 40.4 77.624 C 40.4 78.878 42.952 79.648 44.91 79.824 H 48.1 A 1.892 1.892 0 0 1 50.3 80.814 C 50.696 81.606 51.686 85.434 52.654 85.434 C 53.622 85.434 54.612 81.606 55.008 80.814 A 1.892 1.892 0 0 1 57.208 79.824 H 60.442 C 62.4 79.648 64.842 78.878 64.842 77.624 C 64.842 75.16 60.904 75.006 60.288 74.852 L 56.46 74.258 A 1.716 1.716 0 0 1 55.294 72.85 A 1.936 1.936 0 0 1 55.294 72.498 L 57.01 50.3 A 1.87 1.87 0 0 1 58.638 48.54 L 64.468 47.88 L 66.184 47.594 A 3.366 3.366 0 0 0 69.55 50.938 H 70.1 A 3.344 3.344 0 0 0 73.466 47.594 V 46.362 L 80.462 45.218 C 88.294 43.568 85.5 40.224 79.978 38.882 Z";
const QString MfdBackend::d_heliIconPath = "M 81.828 45.828 A 29.328 29.328 0 1 0 49.908 75.012 C 50.052 77.628 50.22 80.148 50.412 82.452 L 39.348 84.612 V 88.5 H 65.748 V 84.612 L 54.684 82.452 C 54.876 80.052 55.044 77.652 55.188 75.012 A 29.352 29.352 0 0 0 81.828 45.828 Z M 25.644 45.828 A 26.856 26.856 0 1 1 55.212 72.54 C 55.212 70.02 55.428 67.428 55.524 64.836 C 58.956 60.804 61.38 50.94 61.38 43.644 C 61.38 34.308 57.42 26.844 52.5 26.652 S 43.62 34.308 43.62 43.644 C 43.62 50.844 46.02 60.804 49.476 64.836 C 49.476 67.428 49.668 70.02 49.788 72.54 A 26.904 26.904 0 0 1 25.644 45.828 Z";

MfdBackend::MfdBackend(QObject *parent) : QObject(parent)
{
    selectIcon(SettingsController::iconIdx());
    d_planeIconScaleFactor = SettingsController::iconSize();
    d_planeIconColor = SettingsController::iconColor();
    d_planeIconBorderColor = SettingsController::iconBorderColor();
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

const QString MfdBackend::getIconPathAt(int idx) const
{
    switch (idx)
    {
        case 0:
            return d_defaultPlanePath;
        case 1:
            return d_cursorIconPath;
        case 2:
            return d_triangleIconPath;
        case 3:
            return d_airlinerIconPath;
        case 4:
            return d_gliderIconPath;
        case 5:
            return d_glider2IconPath;
        case 6:
            return d_jetIconPath;
        case 7:
            return d_propIconPath;
        case 8:
            return d_turbopropIconPath;
        case 9:
            return d_heliIconPath;
        default:
            return "";
    }
}

void MfdBackend::selectIcon(int idx)
{
    switch (idx)
    {
        case 0:
            d_planeIconPath = d_defaultPlanePath;
            break;
        case 1:
            d_planeIconPath = d_cursorIconPath;
            break;
        case 2:
            d_planeIconPath = d_triangleIconPath;
            break;
        case 3:
            d_planeIconPath = d_airlinerIconPath;
            break;
        case 4:
            d_planeIconPath = d_gliderIconPath;
            break;
        case 5:
            d_planeIconPath = d_glider2IconPath;
            break;
        case 6:
            d_planeIconPath = d_jetIconPath;
            break;
        case 7:
            d_planeIconPath = d_propIconPath;
            break;
        case 8:
            d_planeIconPath = d_turbopropIconPath;
            break;
        case 9:
            d_planeIconPath = d_heliIconPath;
            break;
    }

    SettingsController::setIconIdx(idx);

    emit planeIconPathChanged();
}

const QString &MfdBackend::planeIconPath() const
{
    return d_planeIconPath;
}

double MfdBackend::planeIconScaleFactor() const
{
    return d_planeIconScaleFactor;
}

const QColor &MfdBackend::planeIconColor() const
{
    return d_planeIconColor;
}

const QColor &MfdBackend::planeIconBorderColor() const
{
    return d_planeIconBorderColor;
}

void MfdBackend::setPlaneIconScaleFactor(double scalefactor)
{
    d_planeIconScaleFactor = scalefactor;
    SettingsController::setIconSize(scalefactor);
    emit planeIconScaleFactorChanged();
}

void MfdBackend::setPlaneIconColor(QColor iconColor)
{
    d_planeIconColor = iconColor;
    SettingsController::setIconColor(iconColor.name());
    emit planeIconColorChanged();
}

void MfdBackend::setPlaneIconBorderColor(QColor borderColor)
{
    d_planeIconBorderColor = borderColor;
    SettingsController::setIconBorderColor(borderColor.name());
    emit planeIconBorderColorChanged();
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
