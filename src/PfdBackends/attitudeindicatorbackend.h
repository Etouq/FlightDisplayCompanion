#ifndef ATTITUDEINDICATORBACKEND_H
#define ATTITUDEINDICATORBACKEND_H

#include <QObject>

class AttitudeIndicatorBackend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double bankAngle READ bankAngle NOTIFY bankAngleChanged)
    Q_PROPERTY(double pitchTransformValue READ pitchTransformValue NOTIFY pitchTransformValueChanged)
    Q_PROPERTY(double slipSkidTransformValue READ slipSkidTransformValue NOTIFY slipSkidTransformValueChanged)
    Q_PROPERTY(bool fdActive READ fdActive NOTIFY fdActiveChanged)
    Q_PROPERTY(double fdBankAngle READ fdBankAngle NOTIFY fdBankAngleChanged)
    Q_PROPERTY(double fdPitchTransformValue READ fdPitchTransformValue NOTIFY fdPitchTransformValueChanged)

    // exposed items
    double d_bankAngle = 0;
    double d_pitchTransformValue = 0;
    double d_slipSkidTransformValue = 0;
    bool d_fdActive = true;
    double d_fdBankAngle = 0;
    double d_fdPitchTransformValue = 0;

    // internal items
    double d_scaleFactor = 1.44;
    double d_bankSizeRatio = -24;
    double d_fdBank = 0;
    double d_fdPitch = 0;

public:
    explicit AttitudeIndicatorBackend(QObject *parent = nullptr);

    double bankAngle() const;
    double pitchTransformValue() const;
    double slipSkidTransformValue() const;
    bool fdActive() const;
    double fdBankAngle() const;
    double fdPitchTransformValue() const;

signals:
    void bankAngleChanged();
    void pitchTransformValueChanged();
    void slipSkidTransformValueChanged();
    void fdActiveChanged();
    void fdBankAngleChanged();
    void fdPitchTransformValueChanged();

public slots:
    void updateBank(double newValue);
    void updatePitch(double newValue);
    void updateSlipSkid(double newValue);
    void updateFdActive(bool newValue);
    void updateFdBank(double newValue);
    void updateFdPitch(double newValue);
};

#endif   // ATTITUDEINDICATORBACKEND_H
