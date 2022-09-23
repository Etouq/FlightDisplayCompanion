#ifndef __NETWORK_CLIENT_HPP__
#define __NETWORK_CLIENT_HPP__

#include "common/typeEnums.hpp"
#include "common/QmlEnums.hpp"
#include "common/dataIdentifiers.hpp"
#include "common/definitions/baseTypes.hpp"

#include <QObject>
#include <QString>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QTimer>

namespace definitions
{
    struct AircraftDefinition;
}

namespace pages::mfd
{
struct FlightPlanWaypoint;
}
class QGeoCoordinate;

namespace io::network
{

class NetworkClient : public QObject
{
    Q_OBJECT

    Q_PROPERTY(io::network::ConnectionStateClass::Value connectionState READ connectionState NOTIFY connectionStateChanged)
    Q_PROPERTY(bool simRunning READ simRunning NOTIFY simRunningChanged)

    Q_PROPERTY(QString address READ address NOTIFY addressChanged)
    Q_PROPERTY(int port READ port NOTIFY portChanged)


    QTcpSocket d_socket;

    QUdpSocket d_serverDatagramSocket;

    static constexpr uint8_t s_communicationVersion = 3;
    bool d_versionVerified = false;

    bool d_tryConnecting = false;
    bool d_addressOrPortChanged = false;

    QHostAddress d_datagramAddress;
    quint16 d_datagramPort;

    QTimer d_connectionAttemptKiller;

    // qml
    QString d_address = "";
    quint16 d_port = 0;

    QString d_errorString = "";
    ConnectionState d_connectionState = ConnectionState::DISCONNECTED;

    bool d_simRunning = false;

    // to prevent restarting of udp socket when we want to shut down
    bool d_closingApplication = false;

public:

    explicit NetworkClient(QObject *parent = nullptr);

    ~NetworkClient();

    // qml
    const QString &address() const
    {
        return d_address;
    }

    int port() const
    {
        return d_port;
    }

    void setAddress(const QString &newAddress)
    {
        d_address = newAddress;
        emit addressChanged();
    }
    void setPort(int newPort)
    {
        d_port = newPort;
        emit portChanged();
    }

    Q_INVOKABLE const QString &errorString() const
    {
        return d_errorString;
    }

    ConnectionState connectionState() const
    {
        return d_connectionState;
    }

    bool simRunning() const
    {
        return d_simRunning;
    }

    Q_INVOKABLE void manualConnect(const QString &address, int port);


public slots:

    void aircraftLoaded()
    {
        constexpr ClientToServerIds clientId = ClientToServerIds::AIRCRAFT_LOADED;
        d_socket.write(reinterpret_cast<const char *>(&clientId), sizeof(clientId));
    }

    void sendCommandString(const QByteArray &commandString);

    void updateDefaultSpeedBugs(const QList<definitions::ReferenceSpeed> &newBugs);



private slots:

    void verifyConnectionVersion();

    void readSimData();

    void socketStateChanged(QAbstractSocket::SocketState state);
    void socketErrorOccurred(QAbstractSocket::SocketError error);

    void udpSocketStateChanged(QAbstractSocket::SocketState state);
    void udpSocketErrorOccurred(QAbstractSocket::SocketError error);

    void broadcastReceived();

    void abortConnectionAttempt();

private:

    bool readPfdData();
    bool readMfdData();
    bool readTscData();
    bool readServerData();

    void connectToServer();

signals:

    // qml
    void connectionStateChanged();

    void newErrorMessage(const QString &msg);

    void simRunningChanged();

    void addressChanged();
    void portChanged();

    // sim
    void simStartupFailed();

    void loadAircraft(const definitions::AircraftDefinition &definition);


    // mfd
    // map
    void coordinatesChanged(const QGeoCoordinate &newCoord);
    void trueHeadingChanged(double newValue);

    // flightplan
    void clearFlightplanReceived();
    void receivedFlightplan(const QList<pages::mfd::FlightPlanWaypoint> &wpList);
    void activeLegIdxChanged(int32_t newIdx);
    void gpsWpDtkChanged(double newValue);
    void gpsWpEteChanged(int newValue);
    void gpsDestEteChanged(int newValue);

    // fuel
    void fuelLeftQtyChanged(double newValue);
    void fuelRightQtyChanged(double newValue);

    // engines
    void engineGauge1Changed(double newValue, uint8_t engineIdx);
    void engineGauge2Changed(double newValue, uint8_t engineIdx);
    void engineGauge3Changed(double newValue, uint8_t engineIdx);
    void engineGauge4Changed(double newValue, uint8_t engineIdx);

    void engineFuelFlowChanged(double newValue, uint8_t engineIdx);
    void engineOilTempChanged(double newValue, uint8_t engineIdx);
    void engineSecondaryTempChanged(double newValue, uint8_t engineIdx);
    void engineOilPressChanged(double newValue, uint8_t engineIdx);

    // misc engine display
    void apuN1Changed(int newValue);
    void fuelTextDataChanged(float totalFuelQty, float totalFuelflow, float groundSpeed);
    void flapsAngleChanged(double newValue);
    void spoilersPctChanged(double newValue);
    void elevTrimChanged(double newPct, int newAngle);
    void ruddTrimChanged(double newPct, int newAngle);
    void ailTrimChanged(double newPct, int newAngle);


    // tsc
    // radio info
    //com
    void com1AvailChanged(bool newValue);
    void com1FreqChanged(float newValue);
    void com1StbyFreqChanged(float newFreq);
    void com2AvailChanged(bool newValue);
    void com2FreqChanged(float newValue);
    void com2StbyFreqChanged(float newFreq);
    void com3AvailChanged(bool newValue);
    void com3FreqChanged(float newValue);
    void com3StbyFreqChanged(float newFreq);
    //nav
    void nav1AvailChanged(bool newValue);
    void nav1FreqChanged(float newValue);
    void nav1StbyFreqChanged(float newFreq);
    void nav2AvailChanged(bool newValue);
    void nav2FreqChanged(float newValue);
    void nav2StbyFreqChanged(float newFreq);
    //xpdr
    void xpdrAvailChanged(bool newValue);
    void xpdrCodeChanged(int newCode);
    void xpdrStateChanged(TransponderState newState);

    // aircraft selection data
    void receivedNewAircraft(const QImage &thumbnail, const definitions::AircraftDefinition &definition);


    // pfd
    // airspeed
    void airspeedChanged(double newValue);
    void maxSpeedChanged(double newValue);
    void trueAirspeedChanged(int newValue);
    void refSpeedChanged(int newValue);

    // altitude
    void altitudeChanged(double newValue);
    void radarAltitudeChanged(double newValue);
    void refAltitudeChanged(int newValue);
    void pressureChanged(double newValue);

    // vspeed
    void vspeedChanged(double newValue);
    void refVspeedChanged(int newValue);

    // vert dev
    void vDevModeChanged(VerticalDeviationMode newValue);
    void vDevValueChanged(double newValue);

    // aoa
    void angleOfAttackChanged(double newValue);

    // ap info
    void apAvailableChanged(bool newValue);
    void apLateralActiveChanged(const QString &newValue);
    void apLateralArmedChanged(const QString &newValue);
    void apStatusChanged(bool newValue);
    void apYdStatusChanged(bool newValue);
    void apFdStatusChanged(bool newValue);
    void apFlcChanged(bool newValue);
    void apVerticalActiveChanged(const QString &newValue);
    void apModeReferenceChanged(const QString &newValue);
    void apArmedChanged(const QString &newValue);
    void apArmedReferenceChanged(const QString &newValue);

    // attitude
    void attitudeChanged(double bank, double pitch, double slipSkid);
    void fdAttitudeChanged(double bank, double pitch);

    // bottombar
    void zuluSecondsChanged(int newValue);
    void localSecondsChanged(int newValue);
    void groundSpeedChanged(int newValue);
    void totalAirTempChanged(float newValue);
    void outsideAirTempChanged(float newValue);
    void isaTempChanged(float newValue);

    // hsi
    void rotationChanged(double newValue);
    void headingChanged(double newValue);
    void courseChanged(double newValue);
    void courseDeviationChanged(double newValue);
    void displayDeviationChanged(bool newValue);
    void turnRateChanged(double newValue);
    void navSourceChanged(HsiNavSource newValue);
    void currentTrackChanged(double newValue);
    void toFromChanged(int newValue);

    // bearings
    void nav1IdentChanged(const QString &newValue);
    void nav1DmeChanged(double newValue);
    void nav1BearingChanged(double newValue);
    void nav1HasNavChanged(bool newValue);
    void nav1HasSignalChanged(bool newValue);
    void nav1HasDmeChanged(bool newValue);

    void nav2IdentChanged(const QString &newValue);
    void nav2DmeChanged(double newValue);
    void nav2BearingChanged(double newValue);
    void nav2HasNavChanged(bool newValue);
    void nav2HasSignalChanged(bool newValue);
    void nav2HasDmeChanged(bool newValue);

    void gpsDistanceChanged(double newValue);
    void gpsBearingChanged(double newValue);

    void adfHasSignalChanged(bool newValue);
    void adfFreqChanged(double newValue);
    void adfRadialChanged(double newValue);

    // nav info
    void gpsIsActiveFlightplanChanged(bool newValue);
    void currentLegToChanged(const QString &newValue);
    void currentLegFromChanged(const QString &newValue);
    void legIsDirectToChanged(bool newValue);

    // wind data
    void windDirectionChanged(double newValue);
    void windStrengthChanged(double newValue);
    void windTrueDirectionChanged(int newValue);
};

}  // namespace io::network

#endif  // __NETWORK_CLIENT_HPP__
