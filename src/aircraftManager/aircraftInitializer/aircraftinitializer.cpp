#include "aircraftinitializer.h"
#include "../aircraftfile.h"
#include <QImage>

AircraftInitializer::AircraftInitializer(QObject *parent) : QObject(parent)
{
}

void AircraftInitializer::initAircraft(QMap<QString, AircraftDefinition> &data)
{
    AircraftDefinition temp = initAIRBUS_A320_NEO();
    data[temp.name] = temp;
    QImage tempImg(":/images/thumbnails/AIRBUS_A320_NEO.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initAVIAT_PITTS();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/AVIAT_PITTS.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initBARON_G58();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/BARON_G58.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initBEECHCRAFT_KING_AIR_350I();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/BEECHCRAFT_KING_AIR_350I.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initBOEING_747_8I();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/BOEING_747_8I.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initBOEING_787_10();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/BOEING_787_10.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initBONANZA_G36();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/BONANZA_G36.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initCESSNA_152();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/CESSNA_152.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initCESSNA_208B_GRAND_CARAVAN_EX();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/CESSNA_208B_GRAND_CARAVAN_EX.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initCESSNA_CJ4_CITATION();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/CESSNA_CJ4_CITATION.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initCESSNA_LONGITUDE();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/CESSNA_LONGITUDE.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initCESSNA_SKYHAWK();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/CESSNA_SKYHAWK.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initDA40_NG();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/DA40_NG.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initDA40_TDI();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/DA40_TDI.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initDA62();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/DA62.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initDR_400();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/DR_400.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initDV20();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/DV20.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initEXTRA_330();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/EXTRA_330.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initFLIGHTDESIGNCT();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/FLIGHTDESINGCT.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initICON_A5();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/ICON_A5.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initMUDRY_CAP_10_C();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/MUDRY_CAP_10_C.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initPIPISTREL_ALPHA_ELECTRO();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/PIPISTREL_ALPHA_ELECTRO.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initSAVAGE_CARBON();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/SAVAGE_CARBON.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initSAVAGE_CUB();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/SAVAGE_CUB.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initSAVAGE_GRRAVEL();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/SAVAGE_GRRAVEL.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initSAVAGE_SHOCK_ULTRA();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/SAVAGE_SHOCK_ULTRA.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initSR22();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/SR22.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initTBM_930();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/TBM_930.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initVL3();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/VL3.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);

    temp = initXCUB();
    data[temp.name] = temp;
    tempImg = QImage(":/images/thumbnails/XCUB.JPG");
    AircraftFile::saveAircraftWithImage(temp, tempImg);
}
