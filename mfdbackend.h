#ifndef MFDBACKEND_H
#define MFDBACKEND_H

#include <QGeoCoordinate>
#include <QObject>
#include <QVector>
#include <QColor>

struct FlightPlanWaypoint
{
    QGeoCoordinate position = QGeoCoordinate(0, 0);
    int32_t alt1 = 0;
    int32_t alt2 = 0;
    QString ident = "";
    int8_t wpType = 0;    // 0: airport, 1: intersection, 2: ndb, 3: user, 4: vor TODO: look into more types such as vor-dme etc
    int8_t altType = 0;   // -1: none/invalid, 0: at, 1: at or below, 2: at or above, 3: between
};

class NetworkClient;

// backend managing flightplan and map
class MfdBackend : public QObject
{
    Q_OBJECT

    enum FlightplanFileVersion
    {
        V1
    };

    const FlightplanFileVersion latestVersion = V1;

    Q_PROPERTY(double planeTrueHdg READ planeTrueHdg NOTIFY planeTrueHdgChanged)
    Q_PROPERTY(QGeoCoordinate currCoordinates READ currCoordinates NOTIFY currCoordinatesChanged)
    Q_PROPERTY(bool simRunning READ simRunning NOTIFY simRunningChanged)
    Q_PROPERTY(double gps_dtk READ gps_dtk NOTIFY gps_dtkChanged)
    Q_PROPERTY(QString ete READ ete NOTIFY eteChanged)
    Q_PROPERTY(QString eta READ eta NOTIFY etaChanged)

    Q_PROPERTY(double planeIconScaleFactor MEMBER d_planeIconScaleFactor NOTIFY planeIconScaleFactorChanged)
    Q_PROPERTY(QColor planeIconColor MEMBER d_planeIconColor NOTIFY planeIconColorChanged)
    Q_PROPERTY(QColor planeIconBorderColor MEMBER d_planeIconBorderColor NOTIFY planeIconBorderColorChanged)
    Q_PROPERTY(int mapOrientationMode MEMBER d_mapOrientationMode NOTIFY mapOrientationModeChanged)


    double plane_hdg_degrees_true = 0;

    QGeoCoordinate d_currCoordinates = QGeoCoordinate(0, 0);

    bool d_simRunning = true;

    double gps_wp_desired_track = 0;

    QString gps_wp_ete = "__:__";
    QString gps_eta = "__:__UTC";

    int gps_ete = 0;
    int zulu_time = 0;


    QVector<FlightPlanWaypoint> flightPlanVec;


    double d_planeIconScaleFactor = 1;
    QColor d_planeIconColor = "white";
    QColor d_planeIconBorderColor = "black";

    int d_mapOrientationMode = 0;   // 0: north up, 1: heading up, 2: track up


public:
    explicit MfdBackend(QObject *parent = nullptr);

    void connectSlots(NetworkClient *netClient);

    void saveFlightplan();
    void loadFlightplan();

    double planeTrueHdg() const;

    double gps_dtk() const;
    QString ete() const;
    QString eta() const;

    Q_INVOKABLE int getFlightPlanSize() const;

    Q_INVOKABLE QGeoCoordinate getFpPositionAt(int idx) const;
    Q_INVOKABLE int getFpAltitude1At(int idx) const;
    Q_INVOKABLE int getFpAltitude2At(int idx) const;
    Q_INVOKABLE QString getFpIdentAt(int idx) const;
    Q_INVOKABLE int getFpWpTypeAt(int idx) const;
    Q_INVOKABLE int getFpAltTypeAt(int idx) const;
    Q_INVOKABLE double getFpLegDistanceAt(int idx) const;
    Q_INVOKABLE double getFpCumulativeDistanceAt(int idx) const;
    Q_INVOKABLE int getFpBearingAt(int idx) const;

    Q_INVOKABLE void qmlClearFlightPlan();

    Q_INVOKABLE void qmlAppendFpWaypoint(double lat, double lon, QString ident, int wpType, int alt1, int alt2, int altType);

    Q_INVOKABLE void qmlInsertFpWaypoint(int idx, double lat, double lon, QString ident, int wpType, int alt1, int alt2, int altType);

    Q_INVOKABLE void qmlDeleteFpWaypoint(int idx);

    Q_INVOKABLE void qmlEditFpWaypoint(int idx, double lat, double lon, QString ident, int wpType, int alt1, int alt2, int altType);

    Q_INVOKABLE void qmlDirectTo(double lat, double lon, QString ident, int wpType, int alt1, int alt2, int altType, int currAlt);

    QGeoCoordinate currCoordinates() const;

    bool simRunning() const;

signals:
    void planeTrueHdgChanged();
    void currCoordinatesChanged();
    void simRunningChanged();
    void flightplanChanged();
    void gps_dtkChanged();
    void eteChanged();
    void etaChanged();

    void planeIconScaleFactorChanged();
    void planeIconColorChanged();
    void planeIconBorderColorChanged();
    void mapOrientationModeChanged();

public slots:
    void updatePlaneTrueHdg(double newValue);
    void updateCoordinates(const QGeoCoordinate &newCoord);
    void simStartEvent();
    void simStopEvent();
    void clearFlightplan();
    void receivedFlightplan(const QList<FlightPlanWaypoint> &wpList);
    void updateDtk(double newValue);
    void updateWpEte(int newValue);
    void updateEte(int newValue);
    void updateZulu(int newValue);
};

#endif   // MFDBACKEND_H
