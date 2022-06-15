#ifndef __GAUGE_ELEMENT_HPP__
#define __GAUGE_ELEMENT_HPP__

#include "GaugeEngine/GaugeEngine.hpp"
#include "common/definitions/gaugeDefinition/gaugeDefinition.hpp"

#include <QObject>

namespace pages::mfd
{

class GaugeElement : public QObject
{
    Q_OBJECT

    definitions::GaugeDefinition d_def;

    double d_startAngle = 0;
    double d_endAngle = 0;
    double d_length = 0;

    GaugeEngine d_engine1;
    GaugeEngine d_engine2;
    GaugeEngine d_engine3;
    GaugeEngine d_engine4;

public:

    explicit GaugeElement(QObject *parent = nullptr)
      : QObject(parent)
    {}

    void setGaugeParameters(const definitions::GaugeDefinition &gaugeDef, double startAngle, double endAngle)
    {
        d_def = gaugeDef;

        d_startAngle = startAngle;
        d_endAngle = endAngle;

        d_engine1.setGaugeParameters(gaugeDef, startAngle, endAngle);
        d_engine2.setGaugeParameters(gaugeDef, startAngle, endAngle);
        d_engine3.setGaugeParameters(gaugeDef, startAngle, endAngle);
        d_engine4.setGaugeParameters(gaugeDef, startAngle, endAngle);
    }

    void setGaugeParameters(const definitions::GaugeDefinition &gaugeDef, double length)
    {
        d_def = gaugeDef;

        d_length = length;

        d_engine1.setGaugeParameters(gaugeDef, length);
        d_engine2.setGaugeParameters(gaugeDef, length);
        d_engine3.setGaugeParameters(gaugeDef, length);
        d_engine4.setGaugeParameters(gaugeDef, length);
    }

    GaugeEngine *engine1()
    {
        return &d_engine1;
    }

    GaugeEngine *engine2()
    {
        return &d_engine2;
    }

    GaugeEngine *engine3()
    {
        return &d_engine3;
    }

    GaugeEngine *engine4()
    {
        return &d_engine4;
    }

    // basic gauge info
    Q_INVOKABLE QString title() const
    {
        return d_def.title;
    }

    Q_INVOKABLE QString unit() const
    {
        return d_def.unitString;
    }

    Q_INVOKABLE double startAngle() const
    {
        return d_startAngle;
    }

    Q_INVOKABLE double endAngle() const
    {
        return d_endAngle;
    }

    Q_INVOKABLE double length() const
    {
        return d_length;
    }

    Q_INVOKABLE double minValue() const
    {
        return d_def.minValue;
    }

    Q_INVOKABLE double maxValue() const
    {
        return d_def.maxValue;
    }

    // colorzones
    Q_INVOKABLE int numColorZones() const
    {
        return d_def.colorZones.size();
    }

    Q_INVOKABLE double colorZoneStartAt(int idx) const
    {
        return d_def.colorZones.at(idx).start;
    }

    Q_INVOKABLE double colorZoneEndAt(int idx) const
    {
        return d_def.colorZones.at(idx).end;
    }

    Q_INVOKABLE const QColor &colorZoneColorAt(int idx) const
    {
        return d_def.colorZones.at(idx).color;
    }

    // grads
    Q_INVOKABLE int numGrads() const
    {
        return d_def.grads.size();
    }

    Q_INVOKABLE double gradValAt(int idx) const
    {
        return d_def.grads.at(idx).gradPos;
    }

    Q_INVOKABLE bool gradIsBigAt(int idx) const
    {
        return d_def.grads.at(idx).isBig;
    }

    Q_INVOKABLE const QColor &gradColorAt(int idx) const
    {
        return d_def.grads.at(idx).gradColor;
    }

    // textgrads
    Q_INVOKABLE int numTextGrads() const
    {
        return d_def.textGrads.size();
    }

    Q_INVOKABLE double textGradValAt(int idx) const
    {
        return d_def.textGrads.at(idx).textGradPos;
    }

    Q_INVOKABLE const QString &gradTextAt(int idx) const
    {
        return d_def.textGrads.at(idx).gradText;
    }

    Q_INVOKABLE bool needsExtraWide() const
    {
        for (int i = 0; i < d_def.textGrads.size(); i++)
            if (d_def.textGrads[i].gradText.size() > 4)
                return true;
        return false;
    }

public slots:

    void update(double newValue, uint8_t engineIdx)
    {
        switch (engineIdx)
        {
            case 1:
                d_engine1.update(newValue);
                break;
            case 2:
                d_engine2.update(newValue);
                break;
            case 3:
                d_engine3.update(newValue);
                break;
            case 4:
                d_engine4.update(newValue);
                break;
            default:
                break;
        }
    }
};

}  // namespace pages::mfd


#endif  // __GAUGE_ELEMENT_HPP__