#ifndef HYBRIDGAUGEBASE_H
#define HYBRIDGAUGEBASE_H

#include <QColor>
#include <QObject>
#include <QString>

#include "aircraftManager/definitions/gaugeDefinition.hpp"

// interface class for qml to obtain values to display the gauges
class GaugeBase : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double engine1Angle READ engine1Angle NOTIFY engine1AngleChanged)
    Q_PROPERTY(double engine1TransformValue READ engine1TransformValue NOTIFY engine1TransformValueChanged)
    Q_PROPERTY(QString engine1Value READ engine1Value NOTIFY engine1ValueChanged)
    Q_PROPERTY(QColor engine1Color READ engine1Color NOTIFY engine1ColorChanged)
    Q_PROPERTY(bool engine1RedBlink READ engine1RedBlink NOTIFY engine1RedBlinkChanged)

    Q_PROPERTY(double engine2Angle READ engine2Angle NOTIFY engine2AngleChanged)
    Q_PROPERTY(double engine2TransformValue READ engine2TransformValue NOTIFY engine2TransformValueChanged)
    Q_PROPERTY(QString engine2Value READ engine2Value NOTIFY engine2ValueChanged)
    Q_PROPERTY(QColor engine2Color READ engine2Color NOTIFY engine2ColorChanged)
    Q_PROPERTY(bool engine2RedBlink READ engine2RedBlink NOTIFY engine2RedBlinkChanged)

    Q_PROPERTY(double engine3Angle READ engine3Angle NOTIFY engine3AngleChanged)
    Q_PROPERTY(double engine3TransformValue READ engine3TransformValue NOTIFY engine3TransformValueChanged)
    Q_PROPERTY(QString engine3Value READ engine3Value NOTIFY engine3ValueChanged)
    Q_PROPERTY(QColor engine3Color READ engine3Color NOTIFY engine3ColorChanged)
    Q_PROPERTY(bool engine3RedBlink READ engine3RedBlink NOTIFY engine3RedBlinkChanged)

    Q_PROPERTY(double engine4Angle READ engine4Angle NOTIFY engine4AngleChanged)
    Q_PROPERTY(double engine4TransformValue READ engine4TransformValue NOTIFY engine4TransformValueChanged)
    Q_PROPERTY(QString engine4Value READ engine4Value NOTIFY engine4ValueChanged)
    Q_PROPERTY(QColor engine4Color READ engine4Color NOTIFY engine4ColorChanged)
    Q_PROPERTY(bool engine4RedBlink READ engine4RedBlink NOTIFY engine4RedBlinkChanged)


    void (*convertValue)(double *);


    bool d_isCircular = false;

    GaugeDefinition def;


    double d_startAngle = 0;
    double d_endAngle;
    double d_length;


    double d_cursorPosOffset;
    double d_cursorPosFactor;

    // engine1
    bool d_engine1RedBlink;
    double d_engine1Angle;
    double d_engine1TransformValue;
    QString d_engine1Value;
    QColor d_engine1Color;


    // engine2
    bool d_engine2RedBlink;
    double d_engine2Angle;
    double d_engine2TransformValue;
    QString d_engine2Value;
    QColor d_engine2Color;


    // engine3
    bool d_engine3RedBlink;
    double d_engine3Angle;
    double d_engine3TransformValue;
    QString d_engine3Value;
    QColor d_engine3Color;


    // engine4
    bool d_engine4RedBlink;
    double d_engine4Angle;
    double d_engine4TransformValue;
    QString d_engine4Value;
    QColor d_engine4Color;


public:
    explicit GaugeBase(QObject *parent = nullptr);

    void setGaugeParameters(const GaugeDefinition &gaugeDef, double startAngle, double endAngle);
    void setGaugeParameters(const GaugeDefinition &gaugeDef, double length);

    // basic gauge info
    Q_INVOKABLE QString getName() const;
    Q_INVOKABLE QString getUnit() const;
    Q_INVOKABLE double getStartAngle() const;
    Q_INVOKABLE double getEndAngle() const;
    Q_INVOKABLE double getLength() const;
    Q_INVOKABLE double getMinValue() const;
    Q_INVOKABLE double getMaxValue() const;


    // colorzones
    Q_INVOKABLE int numColorZones() const;

    Q_INVOKABLE double colorZoneStartAt(int idx) const;

    Q_INVOKABLE double colorZoneEndAt(int idx) const;

    Q_INVOKABLE QColor colorZoneColorAt(int idx) const;


    // grads
    Q_INVOKABLE int numGrads() const;

    Q_INVOKABLE double gradValAt(int idx) const;

    Q_INVOKABLE bool gradIsBigAt(int idx) const;

    Q_INVOKABLE QColor gradColorAt(int idx) const;


    // textgrads
    Q_INVOKABLE int numTextGrads() const;

    Q_INVOKABLE double textGradValAt(int idx) const;

    Q_INVOKABLE QString gradTextAt(int idx) const;

    Q_INVOKABLE bool needsExtraWide() const;

    // engine 1 values
    double engine1Angle() const;
    double engine1TransformValue() const;
    const QString &engine1Value() const;
    const QColor &engine1Color() const;
    bool engine1RedBlink() const;

    // engine 2 values
    double engine2Angle() const;
    double engine2TransformValue() const;
    const QString &engine2Value() const;
    const QColor &engine2Color() const;
    bool engine2RedBlink() const;

    // engine 3 values
    double engine3Angle() const;
    double engine3TransformValue() const;
    const QString &engine3Value() const;
    const QColor &engine3Color() const;
    bool engine3RedBlink() const;

    // engine 4 values
    double engine4Angle() const;
    double engine4TransformValue() const;
    const QString &engine4Value() const;
    const QColor &engine4Color() const;
    bool engine4RedBlink() const;


signals:
    void engine1AngleChanged();
    void engine1TransformValueChanged();
    void engine1ValueChanged();
    void engine1ColorChanged();
    void engine1RedBlinkChanged();

    void engine2AngleChanged();
    void engine2TransformValueChanged();
    void engine2ValueChanged();
    void engine2ColorChanged();
    void engine2RedBlinkChanged();

    void engine3AngleChanged();
    void engine3TransformValueChanged();
    void engine3ValueChanged();
    void engine3ColorChanged();
    void engine3RedBlinkChanged();

    void engine4AngleChanged();
    void engine4TransformValueChanged();
    void engine4ValueChanged();
    void engine4ColorChanged();
    void engine4RedBlinkChanged();

    void colorZonesChanged();   // emitted if only the colorzones changed

    void gaugeNeedsCompleteRedraw();   // emitted if names and grads etc changed

public slots:
    void updateEngine1(double newVal);
    void updateEngine2(double newVal);
    void updateEngine3(double newVal);
    void updateEngine4(double newVal);
};

#endif   // HYBRIDGAUGEBASE_H
