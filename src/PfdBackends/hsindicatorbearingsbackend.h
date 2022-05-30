#ifndef HSINDICATORBEARINGSBACKEND_H
#define HSINDICATORBEARINGSBACKEND_H

#include <QObject>
#include <QString>

class HSIndicatorBearingsBackend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString nav1Ident READ nav1Ident NOTIFY nav1IdentChanged)
    Q_PROPERTY(QString nav1Distance READ nav1Distance NOTIFY nav1DistanceChanged)
    Q_PROPERTY(double nav1Bearing READ nav1Bearing NOTIFY nav1BearingChanged)
    Q_PROPERTY(bool showNav1Bearing READ showNav1Bearing NOTIFY showNav1BearingChanged)

    Q_PROPERTY(QString nav2Ident READ nav2Ident NOTIFY nav2IdentChanged)
    Q_PROPERTY(QString nav2Distance READ nav2Distance NOTIFY nav2DistanceChanged)
    Q_PROPERTY(double nav2Bearing READ nav2Bearing NOTIFY nav2BearingChanged)
    Q_PROPERTY(bool showNav2Bearing READ showNav2Bearing NOTIFY showNav2BearingChanged)

    Q_PROPERTY(QString gpsIdent READ gpsIdent NOTIFY gpsIdentChanged)
    Q_PROPERTY(QString gpsDistance READ gpsDistance NOTIFY gpsDistanceChanged)
    Q_PROPERTY(double gpsBearing READ gpsBearing NOTIFY gpsBearingChanged)

    Q_PROPERTY(QString adfIdent READ adfIdent NOTIFY adfIdentChanged)
    Q_PROPERTY(double adfBearing READ adfBearing NOTIFY adfBearingChanged)
    Q_PROPERTY(bool showAdfBearing READ showAdfBearing NOTIFY showAdfBearingChanged)

    Q_PROPERTY(QString nav1Freq READ nav1Freq NOTIFY nav1FreqChanged)
    Q_PROPERTY(QString nav1Dme READ nav1Dme NOTIFY nav1DmeChanged)

    Q_PROPERTY(QString nav2Freq READ nav2Freq NOTIFY nav2FreqChanged)
    Q_PROPERTY(QString nav2Dme READ nav2Dme NOTIFY nav2DmeChanged)

    Q_PROPERTY(int brg1Mode MEMBER d_brg1Mode NOTIFY brg1ModeChanged)
    Q_PROPERTY(int brg2Mode MEMBER d_brg2Mode NOTIFY brg2ModeChanged)

    // exposed items
    QString d_nav1Ident = "";
    QString d_nav1Distance = "";
    double d_nav1Bearing = 0;

    QString d_nav2Ident = "";
    QString d_nav2Distance = "";
    double d_nav2Bearing = 0;

    QString d_gpsIdent = "";
    QString d_gpsDistance = "";
    double d_gpsBearing = 0;

    QString d_adfIdent = "";
    double d_adfBearing = 0;

    QString d_nav1Freq = "";
    QString d_nav1Dme = "";

    QString d_nav2Freq = "";
    QString d_nav2Dme = "";


    int d_brg1Mode = 0;
    int d_brg2Mode = 0;

    // internal items
    bool d_nav1HasNav = false;
    bool d_nav1HasSignal = false;
    QString d_nav1InternalIdent = "";
    bool d_nav1HasDme = false;
    double d_nav1DmeDist = 0;

    bool d_nav2HasNav = false;
    bool d_nav2HasSignal = false;
    QString d_nav2InternalIdent = "";
    bool d_nav2HasDme = false;
    double d_nav2DmeDist = 0;

    bool d_adfHasSignal = false;
    double d_adfFreq = 0;

    double d_nav1InternalFreq = 0;
    double d_nav2InternalFreq = 0;



public:
    explicit HSIndicatorBearingsBackend(QObject *parent = nullptr);

    QString nav1Ident() const;
    QString nav1Distance() const;
    double nav1Bearing() const;
    bool showNav1Bearing() const;

    QString nav2Ident() const;
    QString nav2Distance() const;
    double nav2Bearing() const;
    bool showNav2Bearing() const;

    QString gpsIdent() const;
    QString gpsDistance() const;
    double gpsBearing() const;

    QString adfIdent() const;
    double adfBearing() const;
    bool showAdfBearing() const;

    QString nav1Freq() const;
    QString nav1Dme() const;

    QString nav2Freq() const;
    QString nav2Dme() const;

signals:
    void nav1IdentChanged();
    void nav1DistanceChanged();
    void nav1BearingChanged();
    void showNav1BearingChanged();

    void nav2IdentChanged();
    void nav2DistanceChanged();
    void nav2BearingChanged();
    void showNav2BearingChanged();

    void gpsIdentChanged();
    void gpsDistanceChanged();
    void gpsBearingChanged();

    void adfIdentChanged();
    void adfBearingChanged();
    void showAdfBearingChanged();

    void nav1FreqChanged();
    void nav1DmeChanged();

    void nav2FreqChanged();
    void nav2DmeChanged();

    void brg1ModeChanged();
    void brg2ModeChanged();

public slots:
    void updateNav1Ident(QString const &newValue);
    void updateNav1Dme(double newValue);
    void updateNav1Bearing(double newValue);
    void updateNav1HasNav(bool newValue);
    void updateNav1HasSignal(bool newValue);
    void updateNav1HasDme(bool newValue);

    void updateNav2Ident(QString const &newValue);
    void updateNav2Dme(double newValue);
    void updateNav2Bearing(double newValue);
    void updateNav2HasNav(bool newValue);
    void updateNav2HasSignal(bool newValue);
    void updateNav2HasDme(bool newValue);

    void updateGpsIdent(QString const &newValue);
    void updateGpsDistance(double newValue);
    void updateGpsBearing(double newValue);

    void updateAdfHasSignal(bool newValue);
    void updateAdfFreq(double newValue);
    void updateAdfRadial(double newValue);

    void updateNav1Freq(double newValue);
    void updateNav2Freq(double newValue);
};

#endif   // HSINDICATORBEARINGSBACKEND_H
