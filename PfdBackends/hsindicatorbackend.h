#ifndef HSINDICATORBACKEND_H
#define HSINDICATORBACKEND_H

#include <QObject>
#include <QString>

class HSIndicatorBackend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double rotation READ rotation NOTIFY rotationChanged)
    Q_PROPERTY(QString rotationText READ rotationText NOTIFY rotationTextChanged)
    Q_PROPERTY(double headingBugRotation READ headingBugRotation NOTIFY headingBugRotationChanged)
    Q_PROPERTY(QString headingText READ headingText NOTIFY headingTextChanged)
    Q_PROPERTY(double course READ course NOTIFY courseChanged)
    Q_PROPERTY(QString courseText READ courseText NOTIFY courseTextChanged)
    Q_PROPERTY(double courseDeviation READ courseDeviation NOTIFY courseDeviationChanged)
    Q_PROPERTY(double crossTrackError READ crossTrackError NOTIFY crossTrackErrorChanged)
    Q_PROPERTY(bool displayDeviation READ displayDeviation NOTIFY displayDeviationChanged)
    Q_PROPERTY(double turnRate READ turnRate NOTIFY turnRateChanged)
    Q_PROPERTY(int navSource READ navSource NOTIFY navSourceChanged)
    Q_PROPERTY(double currentTrackAngle READ currentTrackAngle NOTIFY currentTrackAngleChanged)
    Q_PROPERTY(int toFrom READ toFrom NOTIFY toFromChanged)


    // exposed items
    double d_rotation = 0;
    QString d_rotationText = "000°";
    double d_heading_bug_rotation = 0;
    QString d_headingText = "000°";
    double d_course = 0;
    QString d_courseText = "000°";

    double d_course_deviation = 0;
    double d_cross_track_error = 0;

    bool d_display_deviation = false;

    double d_turn_rate = 0;

    int d_navSource = -1;   // 0: GPS, 1: VOR1, 2: LOC1, 3: VOR2, 4: LOC2

    double d_current_track_angle = 0;

    int d_to_from = 0;   // 0: none, 1: to, 2: from

    // server determines cdi source and from that, nav source and course etc

    // internal items



public:
    explicit HSIndicatorBackend(QObject *parent = nullptr);

    double rotation() const;
    QString rotationText() const;
    double headingBugRotation() const;
    QString headingText() const;
    double course() const;
    QString courseText() const;

    double courseDeviation() const;
    double crossTrackError() const;

    bool displayDeviation() const;

    double turnRate() const;

    int navSource() const;

    double currentTrackAngle() const;

    int toFrom() const;

    Q_INVOKABLE void qmlArrowCompleted() { updateNavSource(0); }

signals:
    void rotationChanged();
    void rotationTextChanged();
    void headingBugRotationChanged();
    void headingTextChanged();
    void courseChanged();
    void courseTextChanged();

    void courseDeviationChanged();
    void crossTrackErrorChanged();

    void displayDeviationChanged();

    void turnRateChanged();

    void navSourceChanged();

    void currentTrackAngleChanged();

    void toFromChanged();

public slots:
    void updateRotation(double newValue);
    void updateHeading(double newValue);
    void updateCourse(double newValue);

    void updateCourseDeviation(double newValue);

    void updateDisplayDeviation(bool newValue);

    void updateTurnRate(double newValue);

    void updateNavSource(int newValue);

    void updateCurrentTrack(double newValue);

    void updateToFrom(int newValue);
};

#endif   // HSINDICATORBACKEND_H
