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
class BinaryUtil
{
    BinaryUtil() = default;

public:
    // fundamental types
    static QByteArray toBinary(int8_t val);
    static QByteArray toBinary(uint8_t val);
    static QByteArray toBinary(int16_t val);
    static QByteArray toBinary(uint16_t val);
    static QByteArray toBinary(int32_t val);
    static QByteArray toBinary(uint32_t val);
    static QByteArray toBinary(int64_t val);
    static QByteArray toBinary(uint64_t val);

    static QByteArray toBinary(bool bl);

    static QByteArray toBinary(float flt);
    static QByteArray toBinary(double dbl);


    // basic types
    static QByteArray toBinary(const QString &str);

    static QByteArray toBinary(const QColor &col);

    static QByteArray toBinary(Units unit);


    // struct types
    static QByteArray toBinary(const ColorZone &zone);

    static QByteArray toBinary(const GradDef &grad);

    static QByteArray toBinary(const TextGradDef &textGrad);

    static QByteArray toBinary(const FlightPlanWaypoint &wp);


    // vector types
    static QByteArray toBinary(const QVector<ColorZone> &vec);

    static QByteArray toBinary(const QVector<GradDef> &vec);

    static QByteArray toBinary(const QVector<TextGradDef> &vec);

    static QByteArray toBinary(const QList<FlightPlanWaypoint> &wpList);

    static QByteArray toBinary(const QVector<FlightPlanWaypoint> &wpVec);



    // read functions
    // fundamental types
    static int8_t readInt8_t(QIODevice &data);
    static uint8_t readUint8_t(QIODevice &data);
    static int16_t readInt16_t(QIODevice &data);
    static uint16_t readUint16_t(QIODevice &data);
    static int32_t readInt32_t(QIODevice &data);
    static uint32_t readUint32_t(QIODevice &data);
    static int64_t readInt64_t(QIODevice &data);
    static uint64_t readUint64_t(QIODevice &data);

    static bool readBool(QIODevice &data);

    static float readFloat(QIODevice &data);
    static double readDouble(QIODevice &data);


    // basic types
    static QString readString(QIODevice &data);

    static QColor readColor(QIODevice &data);

    static Units readUnit(QIODevice &data);


    // struct types
    static ColorZone readColorZone(QIODevice &data);

    static GradDef readGrad(QIODevice &data);

    static TextGradDef readTextGrad(QIODevice &data);

    static FlightPlanWaypoint readFpWp(QIODevice &data);


    // vector types
    static void readColorZoneVec(QIODevice &data, QVector<ColorZone> &vec);

    static void readGradVec(QIODevice &data, QVector<GradDef> &vec);

    static void readTextGradVec(QIODevice &data, QVector<TextGradDef> &vec);

    static QList<FlightPlanWaypoint> readFpList(QIODevice &data);

    static QVector<FlightPlanWaypoint> readFpVec(QIODevice &data);
};

#endif   // BINARYUTIL_H
