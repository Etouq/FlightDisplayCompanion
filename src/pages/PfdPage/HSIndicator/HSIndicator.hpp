#ifndef __HSINDICATOR_HPP__
#define __HSINDICATOR_HPP__

#include "common/typeEnums.hpp"

#include <QObject>

namespace io::network
{
class NetworkClient;
}

namespace pages::pfd
{

class HSIndicator : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double rotation READ rotation NOTIFY rotationChanged)
    Q_PROPERTY(QString rotationText READ rotationText NOTIFY rotationTextChanged)
    Q_PROPERTY(double turnRate READ turnRate NOTIFY turnRateChanged)

    Q_PROPERTY(double headingBugRotation READ headingBugRotation NOTIFY headingBugRotationChanged)
    Q_PROPERTY(QString headingText READ headingText NOTIFY headingTextChanged)

    Q_PROPERTY(double course READ course NOTIFY courseChanged)
    Q_PROPERTY(QString courseText READ courseText NOTIFY courseTextChanged)

    Q_PROPERTY(double courseDeviation READ courseDeviation NOTIFY courseDeviationChanged)
    Q_PROPERTY(double crossTrackError READ crossTrackError NOTIFY crossTrackErrorChanged)

    Q_PROPERTY(bool displayDeviation READ displayDeviation NOTIFY displayDeviationChanged)
    Q_PROPERTY(HsiNavSource navSource READ navSource NOTIFY navSourceChanged)
    Q_PROPERTY(double currentTrackAngle READ currentTrackAngle NOTIFY currentTrackAngleChanged)

    Q_PROPERTY(int toFrom READ toFrom NOTIFY toFromChanged)

public:

    explicit HSIndicator(io::network::NetworkClient *netClient, QObject *parent = nullptr);

    double rotation() const
    {
        return d_rotation;
    }

    const QString &rotationText() const
    {
        return d_rotationText;
    }

    double turnRate() const
    {
        return d_turnRate;
    }

    double headingBugRotation() const
    {
        return d_headingBugRotation;
    }

    const QString &headingText() const
    {
        return d_headingText;
    }

    double course() const
    {
        return d_course;
    }

    const QString &courseText() const
    {
        return d_courseText;
    }

    double courseDeviation() const
    {
        return d_courseDeviation;
    }

    double crossTrackError() const
    {
        return d_crossTrackError;
    }

    bool displayDeviation() const
    {
        return d_displayDeviation;
    }

    HsiNavSource navSource() const
    {
        return d_navSource;
    }

    double currentTrackAngle() const
    {
        return d_currentTrackAngle;
    }

    int toFrom() const
    {
        return d_toFrom;
    }

signals:
    void rotationChanged();
    void rotationTextChanged();
    void turnRateChanged();

    void headingBugRotationChanged();
    void headingTextChanged();

    void courseChanged();
    void courseTextChanged();

    void courseDeviationChanged();
    void crossTrackErrorChanged();

    void displayDeviationChanged();
    void navSourceChanged();
    void currentTrackAngleChanged();

    void toFromChanged();


public slots:
    void updateRotation(double newValue);

    void updateTurnRate(double newValue)
    {
        d_turnRate = newValue <= -4 ? -24.5 : newValue >= 4 ? 24.5 : newValue * 6;
        emit turnRateChanged();
    }

    void updateHeading(double newValue);

    void updateCourse(double newValue);

    void updateCourseDeviation(double newValue);

    void updateDisplayDeviation(bool newValue)
    {
        d_displayDeviation = newValue;
        emit displayDeviationChanged();
    }

    void updateNavSource(HsiNavSource newValue)
    {
        d_navSource = newValue;
        emit navSourceChanged();
    }

    void updateCurrentTrack(double newValue)
    {
        d_currentTrackAngle = newValue;
        emit currentTrackAngleChanged();
    }

    void updateToFrom(int newValue)
    {
        d_toFrom = newValue;
        emit toFromChanged();
    }

private:

    // exposed items
    double d_rotation = 0;
    QString d_rotationText = "000°";
    double d_turnRate = 0;

    double d_headingBugRotation = 0;
    QString d_headingText = "000°";

    double d_course = 0;
    QString d_courseText = "000°";

    double d_courseDeviation = 0;
    double d_crossTrackError = 0;

    bool d_displayDeviation = false;
    HsiNavSource d_navSource = HsiNavSource::NONE;
    double d_currentTrackAngle = 0;

    int d_toFrom = 0;  // 0: none, 1: to, 2: from
};

}  // namespace pages::pfd


#endif  // __HSINDICATOR_HPP__