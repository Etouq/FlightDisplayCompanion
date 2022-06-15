#ifndef __GAUGE_ENGINE_HPP__
#define __GAUGE_ENGINE_HPP__

#include "unitConverter/unitconverter.hpp"
#include "common/definitions/gaugeDefinition/gaugeDefinition.hpp"

#include <QColor>
#include <QObject>
#include <QString>


namespace pages::mfd
{

class GaugeEngine : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double angle READ angle NOTIFY angleChanged)
    Q_PROPERTY(double transformValue READ transformValue NOTIFY transformValueChanged)
    Q_PROPERTY(QString value READ value NOTIFY valueChanged)
    Q_PROPERTY(QColor color READ color NOTIFY colorChanged)
    Q_PROPERTY(bool redBlink READ redBlink NOTIFY redBlinkChanged)


    void (*convertValue)(double *);

    bool d_isCircular = false;

    definitions::GaugeDefinition d_def;


    double d_cursorPosOffset;
    double d_cursorPosFactor;


    double d_angle;
    double d_transformValue;
    QString d_value;
    QColor d_color;
    bool d_redBlink;

public:

    explicit GaugeEngine(QObject *parent = nullptr)
      : QObject(parent)
    {
        UnitConverter::setConversionFunction(convertValue, Units::NONE);
    }

    void setGaugeParameters(const definitions::GaugeDefinition &gaugeDef, double startAngle, double endAngle);
    void setGaugeParameters(const definitions::GaugeDefinition &gaugeDef, double length);

    void update(double newValue);

    double angle() const
    {
        return d_angle;
    }

    double transformValue() const
    {
        return d_transformValue;
    }

    const QString &value() const
    {
        return d_value;
    }

    const QColor &color() const
    {
        return d_color;
    }

    bool redBlink() const
    {
        return d_redBlink;
    }

signals:
    void angleChanged();
    void transformValueChanged();
    void valueChanged();
    void colorChanged();
    void redBlinkChanged();
};

}  // namespace pages::mfd

#endif  // __GAUGE_ENGINE_HPP__