#ifndef __GAUGE_ELEMENT_HPP__
#define __GAUGE_ELEMENT_HPP__

#include "GaugeEngine/GaugeEngine.hpp"
#include "common/definitions/gaugeDefinition/gaugeDefinition.hpp"

#include <QObject>
#include <QFont>
#include <QFontMetrics>
#include <QQmlEngine>

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
    {
        QQmlEngine::setObjectOwnership(&d_engine1, QQmlEngine::CppOwnership);
        QQmlEngine::setObjectOwnership(&d_engine2, QQmlEngine::CppOwnership);
        QQmlEngine::setObjectOwnership(&d_engine3, QQmlEngine::CppOwnership);
        QQmlEngine::setObjectOwnership(&d_engine4, QQmlEngine::CppOwnership);
    }

    void setGaugeParameters(const definitions::GaugeDefinition &gaugeDef, double startAngle, double endAngle)
    {
        d_def = gaugeDef;

        d_startAngle = 360 - startAngle;
        d_endAngle = 360 - endAngle;

        d_engine1.setGaugeParameters(gaugeDef, d_startAngle, d_endAngle);
        d_engine2.setGaugeParameters(gaugeDef, d_startAngle, d_endAngle);
        d_engine3.setGaugeParameters(gaugeDef, d_startAngle, d_endAngle);
        d_engine4.setGaugeParameters(gaugeDef, d_startAngle, d_endAngle);
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

    Q_INVOKABLE GaugeEngine *engine1()
    {
        return &d_engine1;
    }

    Q_INVOKABLE GaugeEngine *engine2()
    {
        return &d_engine2;
    }

    Q_INVOKABLE GaugeEngine *engine3()
    {
        return &d_engine3;
    }

    Q_INVOKABLE GaugeEngine *engine4()
    {
        return &d_engine4;
    }

    // basic gauge info
    Q_INVOKABLE QString getTitle() const
    {
        return d_def.title;
    }
    Q_INVOKABLE int getUnit() const
    {
        return static_cast<int>(d_def.unit);
    }
    Q_INVOKABLE QString getUnitString() const
    {
        return d_def.unitString;
    }
    Q_INVOKABLE double getMinValue() const
    {
        return d_def.minValue;
    }
    Q_INVOKABLE double getMaxValue() const
    {
        return d_def.maxValue;
    }
    Q_INVOKABLE double getRange() const
    {
        return d_def.maxValue - d_def.minValue;
    }

    Q_INVOKABLE double getStartAngle() const
    {
        return d_startAngle;
    }
    Q_INVOKABLE double getEndAngle() const
    {
        return d_endAngle;
    }
    Q_INVOKABLE double getLength() const
    {
        return d_length;
    }

    Q_INVOKABLE double valueToAngle(double value) const
    {
        return d_engine1.valueToAngle(value);
    }
    Q_INVOKABLE int valueMaxSize() const
    {
        if (d_def.noText)
            return 0;

        QString text = QString::number(round(d_def.minValue / d_def.textIncrement) * d_def.textIncrement, 'f', d_def.textNumDigits);
        QFont robotoFont("Roboto Mono", -1, QFont::Bold);
        robotoFont.setPixelSize(18);
        QFontMetrics metrics(robotoFont);

        int minValueWidth = metrics.horizontalAdvance(text);
        text = QString::number(round(d_def.maxValue / d_def.textIncrement) * d_def.textIncrement, 'f', d_def.textNumDigits);
        int maxValueWidth = metrics.horizontalAdvance(text);

        return std::max(minValueWidth, maxValueWidth);
    }
    Q_INVOKABLE int unitWidth() const
    {

        QFont robotoFont("Roboto Mono", -1, QFont::Bold);
        robotoFont.setPixelSize(18);
        QFontMetrics metrics(robotoFont);

        return metrics.horizontalAdvance(d_def.unitString);
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

    Q_INVOKABLE double colorZoneRangeAt(int idx) const
    {
        return d_def.colorZones.at(idx).end - d_def.colorZones.at(idx).start;
    }

    Q_INVOKABLE QColor colorZoneColorAt(int idx) const
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

    Q_INVOKABLE QColor gradColorAt(int idx) const
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

    Q_INVOKABLE QString gradTextAt(int idx) const
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
    Q_INVOKABLE int maxTextGradWidth() const
    {
        int ret = 0;

        QFont robotoFont("Roboto Mono", -1, QFont::Bold);
        robotoFont.setPixelSize(15);
        QFontMetrics metrics(robotoFont);

        for (const definitions::TextGradDef &textGrad : d_def.textGrads)
        {
            int width = metrics.horizontalAdvance(textGrad.gradText);
            if (width > ret)
                ret = width;
        }

        return ret;
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