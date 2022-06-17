#ifndef __NETWORK_CLIENT_HPP__
#define __NETWORK_CLIENT_HPP__

#include "common/typeEnums.hpp"
#include <QObject>
#include <qabstractsocket.h>
#include <qobjectdefs.h>
#include <QString>
#include <QTcpSocket>

struct FlightPlanWaypoint;
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

    QTcpSocket d_socket;

    static constexpr uint8_t s_communicationVersion = 3;


    // qml
    QString d_address = "";
    uint d_port = 0;

    QString d_errorString = "";
    ConnectionState d_connectionState = ConnectionState::DISCONNECTED;

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

    Q_INVOKABLE void connectToServer(const QString &address, uint port);

    Q_INVOKABLE void disconnectFromServer();

public slots:

    void startSim(const QByteArray &data);
    void loadAircraft(const QByteArray &data);
    void sendCommandString(const QByteArray &commandString);


private slots:

    void verifyConnectionVersion();

    void readSimData();

    void socketStateChanged(QAbstractSocket::SocketState state);
    void socketErrorOccurred(QAbstractSocket::SocketError error);

signals:

    // qml
    void connectionStateChanged(ConnectionState state);

    void newErrorMessage(const QString &msg);

    // sim
    void simStartReceived();
    void simStopReceived();
    void simStartupFailed();

    // flightplan
    void clearFlightplanReceived();
    void receivedFlightplan(const QList<FlightPlanWaypoint> &wpList);


    // mfd
    void coordinatesChanged(const QGeoCoordinate &newCoord);
    void trueHeadingChanged(double newValue);
    void gpsWpDtkChanged(double newValue);
    void gpsWpEteChanged(int newValue);
    void gpsEteChanged(int newValue);

    void fuelLeftQtyChanged(double newValue);
    void fuelRightQtyChanged(double newValue);

    // engines
    void engineN1Changed(double newValue, uint8_t engineIdx);
    void engineN2Changed(double newValue, uint8_t engineIdx);
    void engineIttChanged(double newValue, uint8_t engineIdx);
    void engineRpmChanged(double newValue, uint8_t engineIdx);
    void enginePowerChanged(double newValue, uint8_t engineIdx);
    void engineManPressChanged(double newValue, uint8_t engineIdx);
    void engineTrqChanged(double newValue, uint8_t engineIdx);
    void engineChtChanged(double newValue, uint8_t engineIdx);
    void engineFuelFlowChanged(double newValue, uint8_t engineIdx);
    void engineEgtChanged(double newValue, uint8_t engineIdx);
    void engineOilTempChanged(double newValue, uint8_t engineIdx);
    void engineOilPressChanged(double newValue, uint8_t engineIdx);

    // misc engine display
    void apuN1Changed(int newValue);
    void fuelTextDataChanged(float totalFuelQty, float totalFuelflow, float groundSpeed);
    void flapsAngleChanged(double newValue);
    void spoilersPctChanged(double newValue);
    void elevTrimChanged(double newValue);
    void ruddTrimChanged(double newValue);
    void ailTrimChanged(double newValue);


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

    // radio info
    void com1AvailChanged(bool newValue);
    void com2AvailChanged(bool newValue);
    void nav1AvailChanged(bool newValue);
    void nav2AvailChanged(bool newValue);
    void com1FreqChanged(float newValue);
    void com2FreqChanged(float newValue);
    void nav1FreqChanged(float newValue);
    void nav2FreqChanged(float newValue);
    void com1StbyChanged(float newFreq);
    void com2StbyChanged(float newFreq);
    void nav1StbyChanged(float newFreq);
    void nav2StbyChanged(float newFreq);
    void xpdrCodeChanged(int newCode);
    void xpdrStateChanged(int newState);

    // wind data
    void windDirectionChanged(double newValue);
    void windStrengthChanged(double newValue);
    void windTrueDirectionChanged(int newValue);

};

}  // namespace io::network

#endif  // __NETWORK_CLIENT_HPP__