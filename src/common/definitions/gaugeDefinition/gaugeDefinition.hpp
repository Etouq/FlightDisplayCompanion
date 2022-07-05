#ifndef GAUGEDEFINITION_H
#define GAUGEDEFINITION_H

#include "../baseTypes.hpp"
#include "common/Units.hpp"

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

    QByteArray toBinary() const;

    static GaugeDefinition fromBinary(QIODevice &data);

    double getEpsilon(bool isCircular) const;

};

}  // namespace definitions


#endif  // GAUGEDEFINITION_H
