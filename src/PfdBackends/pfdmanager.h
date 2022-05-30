#ifndef PFDMANAGER_H
#define PFDMANAGER_H

#include <QObject>

#include "airspeedindicatorbackend.h"
#include "altimeterbackend.h"
#include "angleofattackindicatorbackend.h"
#include "apinfobackend.h"
#include "attitudeindicatorbackend.h"
#include "bottombarbackend.h"
#include "hsindicatorbackend.h"
#include "hsindicatorbearingsbackend.h"
#include "navinfobackend.h"
#include "networkBackend/networkclient.h"
#include "radioinfobackend.h"
#include "winddatabackend.h"

class QQmlContext;

// manages all the pfd elements
class PfdManager : public QObject
{
    Q_OBJECT

    AirspeedIndicatorBackend iasInterface;
    AltimeterBackend altInterface;
    AngleOfAttackIndicatorBackend aoaInterface;
    ApInfoBackend apInterface;
    AttitudeIndicatorBackend attInterface;
    BottombarBackend bottomInterface;
    HSIndicatorBackend hsiInterface;
    HSIndicatorBearingsBackend hsiBrgInterface;
    navInfoBackend navInterface;
    RadioInfoBackend radioInterface;
    WindDataBackend windInterface;


public:
    explicit PfdManager(QObject *parent = nullptr);

    void connectPfdSlots(NetworkClient *netClient);

    void addPfdToContext(QQmlContext *context);

    AirspeedIndicatorBackend *getIasInterface();
    AltimeterBackend *getAltInterface();
    AngleOfAttackIndicatorBackend *getAoaInterface();
    ApInfoBackend *getApInterface();
    AttitudeIndicatorBackend *getAttInterface();
    BottombarBackend *getBottomInterface();
    HSIndicatorBackend *getHsiInterface();
    HSIndicatorBearingsBackend *getHsiBrgInterface();
    navInfoBackend *getNavInterface();
    RadioInfoBackend *getRadioInterface();
    WindDataBackend *getWindInterface();

signals:
    void pfdLoaded();

public slots:
    void changeAircraft(const AircraftDefinition &aircraft);

private:
    void connectAirspeedSlots(NetworkClient *netClient);
    void connectAltimeterSlots(NetworkClient *netClient);
    void connectAoaSlots(NetworkClient *netClient);
    void connectApSlots(NetworkClient *netClient);
    void connectAttitudeSlots(NetworkClient *netClient);
    void connectBottombarSlots(NetworkClient *netClient);
    void connectHsiSlots(NetworkClient *netClient);
    void connectHsiBrgSlots(NetworkClient *netClient);
    void connectNavSlots(NetworkClient *netClient);
    void connectRadioInfoSlots(NetworkClient *netClient);
    void connectWindDataSlots(NetworkClient *netClient);
};

#endif   // PFDMANAGER_H
