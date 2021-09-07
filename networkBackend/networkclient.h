#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H

#include <QObject>
#include <QTcpSocket>

class QString;
class NetworkInterface;
struct AircraftDefinition;
class QGeoCoordinate;
struct FlightPlanWaypoint;

// client that manages all tcp communications with simconnect server and the designer
class NetworkClient : public QObject
{
    Q_OBJECT

    QTcpSocket tcpSocket;

    const uint8_t latestGaugeNetworkVersion = 1;
    const uint8_t latestSimconnectNetworkVersion = 1;

    bool d_connectedToServer = false;

public:
    explicit NetworkClient(QObject *parent = nullptr);

    void connectInterfaceSignals(NetworkInterface *netInterface);

public slots:
    void connectPressed(const QString &address, int port);
    void disconnectPressed();
    void startSim(const QByteArray &data);
    void changeAircraft(const QByteArray &data);
    void sendCommands(const QByteArray &commandString);

    void sendAircraftToDesigner(const AircraftDefinition &aircraft);
    void sendAircraftKeys(const QStringList &keys);

private slots:
    void readInitData();
    void readDesignerData();
    void readSimconnectData();

    void socketDisconnected();

    void newErrorReceived(QAbstractSocket::SocketError socketError);

signals:
    void connectedToSimServer();
    void connectedToGaugeDesigner();
    void displayError(const QString &newError);
    void resetButton();
    void versionError(const QString &msg);

    // airspeed
    void airspeedChanged(double newValue);
    void max_speedChanged(double newValue);
    void true_airspeedChanged(int newValue);
    void ref_speedChanged(int newValue);
    void ap_flcChanged(bool newValue);

    // altitude
    void altitudeChanged(double newValue);
    void radar_altitudeChanged(double newValue);
    void ref_altitudeChanged(int newValue);
    void pressureChanged(double newValue);

    // vspeed
    void vspeedChanged(double newValue);
    void ref_vspeedChanged(int newValue);

    // vert dev
    void vert_dev_modeChanged(int newValue);
    void vert_dev_valueChanged(double newValue);

    // aoa
    void angle_of_attackChanged(double newValue);

    // ap info
    void ap_availableChanged(bool newValue);
    void ap_lateral_activeChanged(QString newValue);
    void ap_lateral_armedChanged(QString newValue);
    void ap_statusChanged(bool newValue);
    void ap_yd_statusChanged(bool newValue);
    void ap_fd_statusChanged(bool newValue);
    void ap_vertical_activeChanged(QString newValue);
    void ap_mode_referenceChanged(QString newValue);
    void ap_armedChanged(QString newValue);
    void ap_armed_referenceChanged(QString newValue);

    // attitude
    void bankChanged(double newValue);
    void pitchChanged(double newValue);
    void slipskidChanged(double newValue);
    void fd_bankChanged(double newValue);
    void fd_pitchChanged(double newValue);

    // bottombar
    void zulu_secondsChanged(int newValue);
    void local_secondsChanged(int newValue);
    void ground_speedChanged(int newValue);
    void total_air_tempChanged(float newValue);

    // hsi
    void rotationChanged(double newValue);
    void headingChanged(double newValue);
    void courseChanged(double newValue);
    void course_deviationChanged(double newValue);
    void display_deviationChanged(bool newValue);
    void turn_rateChanged(double newValue);
    void nav_sourceChanged(int newValue);
    void current_trackChanged(double newValue);
    void to_fromChanged(int newValue);

    // hsi brg
    void nav1_identChanged(QString newValue);
    void nav1_dmeChanged(double newValue);
    void nav1_bearingChanged(double newValue);
    void nav1_has_navChanged(bool newValue);
    void nav1_has_signalChanged(bool newValue);
    void nav1_has_dmeChanged(bool newValue);

    void nav2_identChanged(QString newValue);
    void nav2_dmeChanged(double newValue);
    void nav2_bearingChanged(double newValue);
    void nav2_has_navChanged(bool newValue);
    void nav2_has_signalChanged(bool newValue);
    void nav2_has_dmeChanged(bool newValue);

    void gps_identChanged(QString newValue);
    void gps_distanceChanged(double newValue);
    void gps_bearingChanged(double newValue);

    void adf_has_signalChanged(bool newValue);
    void adf_freqChanged(double newValue);
    void adf_radialChanged(double newValue);

    // nav info
    void gps_is_active_flightplanChanged(bool newValue);
    void current_leg_toChanged(QString newValue);
    void current_leg_fromChanged(QString newValue);
    void leg_is_direct_toChanged(bool newValue);
    void current_leg_distanceChanged(double newValue);
    void current_leg_bearingChanged(double newValue);

    // radio info
    void has_com1Changed(bool newValue);
    void has_com2Changed(bool newValue);
    void has_nav1Changed(bool newValue);
    void has_nav2Changed(bool newValue);
    void com1_freqChanged(double newValue);
    void com2_freqChanged(double newValue);
    void nav1_freqChanged(double newValue);
    void nav2_freqChanged(double newValue);

    // wind data
    void wind_directionChanged(double newValue);
    void wind_strengthChanged(double newValue);
    void wind_true_directionChanged(int newValue);

    // mfd
    void coordinates_Changed(const QGeoCoordinate &newCoord);
    void true_headingChanged(double newValue);
    void gps_wp_desired_trackChanged(double newValue);
    void gps_wp_eteChanged(int newValue);
    void gps_eteChanged(int newValue);

    // flightplan
    void clear_flightplan_received();
    void received_flightplan(const QList<FlightPlanWaypoint> &wpList);

    // tscPage
    void com1_stbyChanged(float newFreq);
    void com2_stbyChanged(float newFreq);
    void nav1_stbyChanged(float newFreq);
    void nav2_stbyChanged(float newFreq);
    void xpdr_codeChanged(int newCode);
    void xpdr_stateChanged(int newState);

    // simconnect server
    void sim_start_received();
    void sim_stop_received();
    void simConnectionFailed();

    // gauge designer
    void remove_aircraft_list(const QStringList &keys);
    void load_aircraft_list(const QStringList &keys);
    void save_aircraft(AircraftDefinition &aircraft, QImage &image);

    // engine data
    // n1
    void engine1_n1Changed(double newValue);
    void engine2_n1Changed(double newValue);
    void engine3_n1Changed(double newValue);
    void engine4_n1Changed(double newValue);
    // n2
    void engine1_n2Changed(double newValue);
    void engine2_n2Changed(double newValue);
    void engine3_n2Changed(double newValue);
    void engine4_n2Changed(double newValue);
    // itt
    void engine1_ittChanged(double newValue);
    void engine2_ittChanged(double newValue);
    void engine3_ittChanged(double newValue);
    void engine4_ittChanged(double newValue);
    // rpm
    void engine1_rpmChanged(double newValue);
    void engine2_rpmChanged(double newValue);
    // second
    void engine1_secondChanged(double newValue);
    void engine2_secondChanged(double newValue);
    // trq
    void engine1_trqChanged(double newValue);
    void engine2_trqChanged(double newValue);
    // fuel qty
    void engine1_fuel_qtyChanged(double newValue);
    void engine2_fuel_qtyChanged(double newValue);
    // fuel flow
    void engine1_fuel_flowChanged(double newValue);
    void engine2_fuel_flowChanged(double newValue);
    // oil press
    void engine1_oil_pressChanged(double newValue);
    void engine2_oil_pressChanged(double newValue);
    // oil temp
    void engine1_oil_tempChanged(double newValue);
    void engine2_oil_tempChanged(double newValue);
    // egt
    void engine1_egtChanged(double newValue);
    void engine2_egtChanged(double newValue);
    // misc ed
    void fuel_text_dataChanged(float totalFuelflow, float totalFuelQty, float groundSpeed);
    void spoilers_pctChanged(double newValue);
    void flaps_angleChanged(double newValue);
    void elev_trim_pctChanged(double newValue);
    void rudd_trim_pctChanged(double newValue);
    void ail_trim_pctChanged(double newValue);
    void apu_rpmChanged(int newValue);
};

#endif   // NETWORKCLIENT_H
