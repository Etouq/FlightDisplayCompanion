#ifndef BINARYUTIL_H
#define BINARYUTIL_H


#include <QVector>
#include <cstdint>

#include "unitConverter/units.h"

class QByteArray;
class QString;
class QColor;
struct ColorZone;
struct GradDef;
struct TextGradDef;
struct FlightPlanWaypoint;
class QIODevice;


// utility function for conversion to and from binary format
namespace BinaryUtil
{
// fundamental types
QByteArray toBinary(int8_t val);
QByteArray toBinary(uint8_t val);
QByteArray toBinary(int16_t val);
QByteArray toBinary(uint16_t val);
QByteArray toBinary(int32_t val);
QByteArray toBinary(uint32_t val);
QByteArray toBinary(int64_t val);
QByteArray toBinary(uint64_t val);

QByteArray toBinary(bool bl);

QByteArray toBinary(float flt);
QByteArray toBinary(double dbl);


// basic types
QByteArray toBinary(const QString &str);

QByteArray toBinary(const QColor &col);

QByteArray toBinary(Units unit);


// struct types
QByteArray toBinary(const ColorZone &zone);

QByteArray toBinary(const GradDef &grad);

QByteArray toBinary(const TextGradDef &textGrad);

QByteArray toBinary(const FlightPlanWaypoint &wp);


// vector types
QByteArray toBinary(const QVector<ColorZone> &vec);

QByteArray toBinary(const QVector<GradDef> &vec);

QByteArray toBinary(const QVector<TextGradDef> &vec);

QByteArray toBinary(const QList<FlightPlanWaypoint> &wpList);

QByteArray toBinary(const QVector<FlightPlanWaypoint> &wpVec);



// read functions
// fundamental types
int8_t readInt8_t(QIODevice &data);
uint8_t readUint8_t(QIODevice &data);
int16_t readInt16_t(QIODevice &data);
uint16_t readUint16_t(QIODevice &data);
int32_t readInt32_t(QIODevice &data);
uint32_t readUint32_t(QIODevice &data);
int64_t readInt64_t(QIODevice &data);
uint64_t readUint64_t(QIODevice &data);

bool readBool(QIODevice &data);

float readFloat(QIODevice &data);
double readDouble(QIODevice &data);


// basic types
QString readString(QIODevice &data);

QColor readColor(QIODevice &data);

Units readUnit(QIODevice &data);


// struct types
ColorZone readColorZone(QIODevice &data);

GradDef readGrad(QIODevice &data);

TextGradDef readTextGrad(QIODevice &data);

FlightPlanWaypoint readFpWp(QIODevice &data);


// vector types
void readColorZoneVec(QIODevice &data, QVector<ColorZone> &vec);

void readGradVec(QIODevice &data, QVector<GradDef> &vec);

void readTextGradVec(QIODevice &data, QVector<TextGradDef> &vec);

QList<FlightPlanWaypoint> readFpList(QIODevice &data);

QVector<FlightPlanWaypoint> readFpVec(QIODevice &data);
}

#endif   // BINARYUTIL_H
