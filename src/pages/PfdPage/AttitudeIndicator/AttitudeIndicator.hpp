#ifndef __ATTITUDEINDICATOR_HPP__
#define __ATTITUDEINDICATOR_HPP__

#include <QObject>

namespace io::network
{
class NetworkClient;
}

namespace pages::pfd
{

class AttitudeIndicator : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double bankAngle READ bankAngle NOTIFY attitudeChanged)
    Q_PROPERTY(double pitchTransformValue READ pitchTransformValue NOTIFY attitudeChanged)
    Q_PROPERTY(double slipSkidTransformValue READ slipSkidTransformValue NOTIFY attitudeChanged)
    Q_PROPERTY(bool fdActive READ fdActive NOTIFY fdActiveChanged)
    Q_PROPERTY(double fdBankAngle READ fdBankAngle NOTIFY fdAttitudeChanged)
    Q_PROPERTY(double fdPitchTransformValue READ fdPitchTransformValue NOTIFY fdAttitudeChanged)

public:

    explicit AttitudeIndicator(io::network::NetworkClient *netClient, QObject *parent = nullptr);

    double bankAngle() const
    {
        return d_bankAngle;
    }

    double pitchTransformValue() const
    {
        return d_pitchTransformValue;
    }

    double slipSkidTransformValue() const
    {
        return d_slipSkidTransformValue;
    }

    bool fdActive() const
    {
        return d_fdActive;
    }

    double fdBankAngle() const
    {
        return d_fdBankAngle;
    }

    double fdPitchTransformValue() const
    {
        return d_fdPitchTransformValue;
    }

signals:
    void attitudeChanged();

    void fdActiveChanged();
    void fdAttitudeChanged();

public slots:
    void updateAttitude(double bank, double pitch, double slipSkid);

    void updateFdActive(bool newValue);
    void updateFdAttitude(double bank, double pitch);

private:

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
};

}  // namespace pages::pfd


#endif  // __ATTITUDEINDICATOR_HPP__