#ifndef BASETYPES_H
#define BASETYPES_H

#include <QColor>
#include <QString>

// fileversion for aircraft definition files
enum class FileVersion : int16_t
{
    V1,
    V2
};

struct ColorZone
{
    double start = 0;
    double end = 0;
    QColor color;
};

struct GradDef
{
    double gradPos = 0;
    bool isBig = false;
    QColor gradColor = "white";   // to allow for colorlines
};

struct TextGradDef
{
    double textGradPos = 0;
    QString gradText;
};

#endif   // BASETYPES_H
