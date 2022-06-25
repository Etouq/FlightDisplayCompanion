#ifndef GAUGEDEFINITION_H
#define GAUGEDEFINITION_H

#include "../baseTypes.hpp"
#include "unitConverter/units.hpp"

#include <cstdint>
#include <QColor>
#include <QMetaType>
#include <QString>
#include <QList>

class QIODevice;
class QByteArray;

namespace definitions
{
// used to allow for designated initialization
struct RawGaugeDefinition
{
    QString title = "";
    QString unitString = "";
    double minValue = 0;
    double maxValue = 0;
    QList<ColorZone> colorZones;
    QList<GradDef> grads;
    QList<TextGradDef> textGrads;
    double textIncrement = 1;
    int textNumDigits = 0;
    bool forceTextColor = false;
    QColor textForcedColor = QColor();
    bool hasMinRedBlink = false;
    double minRedBlinkThreshold = 0;
    bool hasMaxRedBlink = false;
    double maxRedBlinkThreshold = 0;
    bool noText = false;
    Units unit = Units::NONE;
};

// definition used to display a gauge
struct GaugeDefinition
{
    QString title = "";
    QString unitString = "";

    double minValue = 0;
    double maxValue = 0;

    QList<ColorZone> colorZones;
    QList<GradDef> grads;
    QList<TextGradDef> textGrads;

    double textIncrement = 1;
    int8_t textNumDigits = 0;

    bool forceTextColor = false;
    QColor textForcedColor = QColor();

    bool hasMinRedBlink = false;
    double minRedBlinkThreshold = 0;
    bool hasMaxRedBlink = false;
    double maxRedBlinkThreshold = 0;

    bool noText = false;

    Units unit = Units::NONE;

    GaugeDefinition() = default;
    ~GaugeDefinition() = default;
    GaugeDefinition(const GaugeDefinition &) = default;
    GaugeDefinition(const RawGaugeDefinition &rhs);
    GaugeDefinition &operator=(const GaugeDefinition &) = default;

    QByteArray toBinary() const;

    static GaugeDefinition fromBinary(QIODevice &data, FileVersion version = FileVersion::V3)
    {
        switch (version)
        {
            case FileVersion::V1:
            case FileVersion::V2:
            case FileVersion::V3:
                return fromBinaryV1(data);
                break;
        }
    }

    double getEpsilon(bool isCircular) const;

private:

    static GaugeDefinition fromBinaryV1(QIODevice &data);
};

}  // namespace definitions
Q_DECLARE_METATYPE(definitions::GaugeDefinition)

#endif  // GAUGEDEFINITION_H
