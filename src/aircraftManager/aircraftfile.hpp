#ifndef AIRCRAFTFILE_H
#define AIRCRAFTFILE_H


#include <QMap>
#include <QString>

#include "definitions/aircraftDefinition.hpp"

class QIODevice;
class QImage;

// manages reading and writing the files for the aircraft definitions
// also creates and reads the formats used to send the definitions with the designer
class AircraftFile
{

    inline static const FileVersion latestVersion = FileVersion::V2;

    inline static QString dataPath = "";

public:
    static void init();

    static void readAllAircraftFiles(QMap<QString, AircraftDefinition> &data);

    static QString createFileName(const AircraftDefinition &aircraft);
    static QString createFileName(const QString &name);

    static QString getImagePath(const QString &name);

    static void saveAircraftToFile(AircraftDefinition &aircraft);
    static void saveAircraftWithImage(AircraftDefinition &aircraft, QImage &image);
    static void readAircraftFromFile(const QString &fileName, AircraftDefinition &aircraft);

    static void readAircraftFromStream(QIODevice &data, AircraftDefinition &aircraft);
    static void readAircraftFromStream(QIODevice &data, AircraftDefinition &aircraft, QImage &image);   // used for network transfer
    static void writeAircraftToStream(QIODevice &data, const AircraftDefinition &aircraft);
    static void writeAircraftToStream(QIODevice &data, const AircraftDefinition &aircraft, const QImage &image);   // used for network transfer

    static void removeAircraft(const QString &name);

private:
    AircraftFile() = default;
};

#endif   // AIRCRAFTFILE_H
