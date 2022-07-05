#ifndef __BASETYPES_HPP__
#define __BASETYPES_HPP__

#include <QColor>
#include <QString>

namespace definitions
{

struct ColorZone
{
    double start;
    double end;
    QColor color;
};

struct GradDef
{
    double gradPos = 0;
    bool isBig = false;
    QColor gradColor = "white";  // to allow for colorlines
};

struct TextGradDef
{
    double textGradPos = 0;
    QString gradText;
};

struct ReferenceSpeed
{
    uint16_t speed;
    QString designator;
};

}  // namespace definitions


#endif  // __BASETYPES_HPP__
