#ifndef AIRCRAFTINITIALIZER_H
#define AIRCRAFTINITIALIZER_H

#include <QMap>
#include <QObject>

#include "../definitions/aircraftDefinition.h"
#include "../definitions/jetDefinition.h"
#include "../definitions/propDefinition.h"
#include "../definitions/turbopropDefinition.h"


// manages creation of default aircraft on first time setup
class AircraftInitializer : public QObject
{
    Q_OBJECT
public:
    explicit AircraftInitializer(QObject *parent = nullptr);
    static void initAircraft(QMap<QString, AircraftDefinition> &data);

private:
    static AircraftDefinition initAIRBUS_A320_NEO();
    static AircraftDefinition initAVIAT_PITTS();
    static AircraftDefinition initBARON_G58();
    static AircraftDefinition initBEECHCRAFT_KING_AIR_350I();
    static AircraftDefinition initBOEING_747_8I();
    static AircraftDefinition initBOEING_787_10();
    static AircraftDefinition initBONANZA_G36();
    static AircraftDefinition initCESSNA_152();
    static AircraftDefinition initCESSNA_208B_GRAND_CARAVAN_EX();
    static AircraftDefinition initCESSNA_CJ4_CITATION();
    static AircraftDefinition initCESSNA_LONGITUDE();
    static AircraftDefinition initCESSNA_SKYHAWK();
    static AircraftDefinition initDA40_NG();
    static AircraftDefinition initDA40_TDI();
    static AircraftDefinition initDA62();
    static AircraftDefinition initDR_400();
    static AircraftDefinition initDV20();
    static AircraftDefinition initEXTRA_330();
    static AircraftDefinition initFLIGHTDESIGNCT();
    static AircraftDefinition initICON_A5();
    static AircraftDefinition initMUDRY_CAP_10_C();
    static AircraftDefinition initPIPISTREL_ALPHA_ELECTRO();
    static AircraftDefinition initSAVAGE_CARBON();
    static AircraftDefinition initSAVAGE_CUB();
    static AircraftDefinition initSAVAGE_GRRAVEL();
    static AircraftDefinition initSAVAGE_SHOCK_ULTRA();
    static AircraftDefinition initSR22();
    static AircraftDefinition initTBM_930();
    static AircraftDefinition initVL3();
    static AircraftDefinition initXCUB();
};

#endif   // AIRCRAFTINITIALIZER_H
