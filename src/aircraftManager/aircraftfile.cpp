#include "aircraftfile.hpp"

#include <QBuffer>
#include <QCoreApplication>
#include <QDataStream>
#include <QDir>
#include <QFile>
#include <QIODevice>
#include <QImage>
#include <QStandardPaths>

#include "settings/settingscontroller.hpp"


QString AircraftFile::createFileName(const AircraftDefinition &aircraft)
{
    return createFileName(aircraft.name);
}

QString AircraftFile::createFileName(const QString &name)
{
    return QString::fromUtf8(name.toUtf8().toHex());
}

QString AircraftFile::getImagePath(const QString &name)
{
    return dataPath + "/Thumbnails/" + createFileName(name) + ".png";
}

void AircraftFile::init()
{
    if (dataPath == "")
        dataPath = SettingsController::dataPath();
    if (dataPath == "")
    {
        dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
        SettingsController::setDataPath(dataPath);
    }
    QDir dir(dataPath);
    dir.mkpath("Definitions");
    dir.mkdir("Thumbnails");
}

void AircraftFile::saveAircraftToFile(AircraftDefinition &aircraft)
{

    QFile defFile(dataPath + "/Definitions/" + createFileName(aircraft.name) + ".gaugeDef");
    defFile.open(QIODevice::WriteOnly | QIODevice::Truncate);

    FileVersion version = latestVersion;
    defFile.write(reinterpret_cast<char *>(&version), sizeof(version));

    defFile.write(aircraft.toBinary());
}

void AircraftFile::saveAircraftWithImage(AircraftDefinition &aircraft, QImage &image)
{
    saveAircraftToFile(aircraft);

    image.save(dataPath + "/Thumbnails/" + createFileName(aircraft.name) + ".png", nullptr, 100);
}

void AircraftFile::readAircraftFromFile(const QString &fileName, AircraftDefinition &aircraft)
{
    QFile defFile(dataPath + "/Definitions/" + fileName);

    defFile.open(QIODevice::ReadOnly);

    readAircraftFromStream(defFile, aircraft);
}

void AircraftFile::readAircraftFromStream(QIODevice &data, AircraftDefinition &aircraft)
{
    FileVersion version = FileVersion::V1;
    data.read(reinterpret_cast<char *>(&version), sizeof(version));

    aircraft = AircraftDefinition::fromBinary(data, version);
}

void AircraftFile::readAircraftFromStream(QIODevice &data, AircraftDefinition &aircraft, QImage &image)
{
    // read image
    uint64_t imgSize = 0;
    data.read(reinterpret_cast<char *>(&imgSize), sizeof(imgSize));

    QByteArray imgArray = data.read(imgSize);

    QDataStream imgData(&imgArray, QIODevice::ReadOnly);
    imgData.setVersion(QDataStream::Qt_5_15);
    imgData >> image;

    // read aircraft
    aircraft = AircraftDefinition::fromBinary(data, latestVersion);
}

void AircraftFile::writeAircraftToStream(QIODevice &data, const AircraftDefinition &aircraft)
{
    QByteArray buff;
    FileVersion vers = latestVersion;
    buff.append(reinterpret_cast<char *>(&vers), sizeof(vers));

    buff.append(aircraft.toBinary());

    data.write(buff);
}

void AircraftFile::writeAircraftToStream(QIODevice &data, const AircraftDefinition &aircraft, const QImage &image)
{
    // write image
    QByteArray buff;
    QDataStream imgStream(&buff, QIODevice::WriteOnly);
    imgStream.setVersion(QDataStream::Qt_5_15);
    imgStream << image;

    // image size
    uint64_t imgSize = buff.size();
    buff.prepend(reinterpret_cast<char *>(&imgSize), sizeof(imgSize));

    buff.append(aircraft.toBinary());

    // total size (so it is not read before completely received)
    uint64_t size = buff.size();
    buff.prepend(reinterpret_cast<char *>(&size), sizeof(size));

    data.write(buff);
}

void AircraftFile::readAllAircraftFiles(QMap<QString, AircraftDefinition> &data)
{
    QDir dir(dataPath + "/Definitions");
    QStringList fileList = dir.entryList({ "*.gaugeDef" }, QDir::Files);
    for (int idx = 0; idx < fileList.size(); idx++)
    {
        AircraftDefinition def;
        readAircraftFromFile(fileList[idx], def);
        data[def.name] = def;
    }
}

void AircraftFile::removeAircraft(const QString &name)
{
    QString filename = createFileName(name);

    QDir dir(dataPath + "/Definitions");
    dir.remove(filename + ".gaugeDef");
    dir.cdUp();
    dir.cd("Thumbnails");
    dir.remove(filename + ".png");
}
