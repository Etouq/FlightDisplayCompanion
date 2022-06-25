#ifndef __NETWORK_CLIENT_HPP__
#define __NETWORK_CLIENT_HPP__

#include "common/typeEnums.hpp"
#include "common/dataIdentifiers.hpp"

#include <QObject>
#include <QString>
#include <QTcpSocket>

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

class ConnectionStateClass
{
    Q_GADGET

public:

    enum ConnectionStateEnum
    {
        DISCONNECTED,
        CONNECTED,
        CONNECTING,
        DISCONNECTING
    };
    Q_ENUM(ConnectionStateEnum)

private:

    explicit ConnectionStateClass()
    {}
};

typedef ConnectionStateClass::ConnectionStateEnum ConnectionState;

class NetworkClient : public QObject
{
    Q_OBJECT

    Q_PROPERTY(ConnectionState connectionState READ connectionState NOTIFY connectionStateChanged)
    Q_PROPERTY(bool simRunning READ simRunning NOTIFY simRunningChanged)

    QTcpSocket d_socket;

    static constexpr uint8_t s_communicationVersion = 3;


    // qml
    QString d_address = "";
    uint d_port = 0;

    QString d_errorString = "";
    ConnectionState d_connectionState = ConnectionState::DISCONNECTED;

    bool d_simRunning = false;

public:

    explicit NetworkClient(QObject *parent = nullptr);

    // qml
    Q_INVOKABLE const QString &address() const
    {
        return d_address;
    }

    Q_INVOKABLE uint port() const
    {
        return d_port;
    }

    Q_INVOKABLE const QString &errorString() const
    {
        return d_errorString;
    }

    Q_INVOKABLE ConnectionState connectionState() const
    {
        return d_connectionState;
    }

    bool simRunning() const
    {
        return d_simRunning;
    }

    Q_INVOKABLE void connectToServer(const QString &address, uint port)
    {
        d_address = address;
        d_port = port;
        d_socket.setSocketOption(QAbstractSocket::KeepAliveOption, 1);
        d_socket.connectToHost(address, port);
        d_socket.setSocketOption(QAbstractSocket::LowDelayOption, 1);
    }

    Q_INVOKABLE void disconnectFromServer()
    {
        ClientToServerIds clientId = ClientToServerIds::QUIT;
        d_socket.write(reinterpret_cast<char *>(&clientId), sizeof(clientId));
        d_socket.disconnectFromHost();
    }

public slots:

    void startSim(const QByteArray &data)
    {
        ClientToServerIds clientId = ClientToServerIds::START;
        QByteArray msg(reinterpret_cast<char *>(&clientId), sizeof(clientId));
        msg += data;
        d_socket.write(msg);
    }

    void loadAircraft(const QByteArray &data)
    {
        ClientToServerIds clientId = ClientToServerIds::LOAD_AIRCRAFT;
        QByteArray msg(reinterpret_cast<char *>(&clientId), sizeof(clientId));
        msg += data;
        d_socket.write(msg);
    }

    void sendCommandString(const QByteArray &commandString)
    {
        ClientToServerIds clientId = ClientToServerIds::COMMAND_STRING;
        QByteArray msg(reinterpret_cast<char *>(&clientId), sizeof(clientId));
        msg += commandString;
        d_socket.write(msg);
    }


private slots:

    void verifyConnectionVersion();

    void readSimData();

    void socketStateChanged(QAbstractSocket::SocketState state);
    void socketErrorOccurred(QAbstractSocket::SocketError error);

private:

    bool readPfdData();
    bool readMfdData();
    bool readTscData();
    bool readServerData();

signals:

    // qml
    void connectionStateChanged(ConnectionState state);

    void newErrorMessage(const QString &msg);

    void simRunningChanged();

    // sim
    void simStartReceived();
    void simStopReceived();
    void simStartupFailed();


    // mfd
    // map
    void coordinatesChanged(const QGeoCoordinate &newCoord);
    void trueHeadingChanged(double newValue);

    // flightplan
    void clearFlightplanReceived();
    void receivedFlightplan(const QList<pages::mfd::FlightPlanWaypoint> &wpList);
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
