#ifndef RADIOINFOBACKEND_H
#define RADIOINFOBACKEND_H

#include <QObject>

class RadioInfoBackend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool hasComm1 READ hasComm1 NOTIFY hasComm1Changed)
    Q_PROPERTY(bool hasComm2 READ hasComm2 NOTIFY hasComm2Changed)
    Q_PROPERTY(float comm1Freq READ comm1Freq NOTIFY comm1FreqChanged)
    Q_PROPERTY(float comm2Freq READ comm2Freq NOTIFY comm2FreqChanged)

    Q_PROPERTY(bool hasNav1 READ hasNav1 NOTIFY hasNav1Changed)
    Q_PROPERTY(bool hasNav2 READ hasNav2 NOTIFY hasNav2Changed)
    Q_PROPERTY(float nav1Freq READ nav1Freq NOTIFY nav1FreqChanged)
    Q_PROPERTY(float nav2Freq READ nav2Freq NOTIFY nav2FreqChanged)

    bool d_hasComm1 = false;
    bool d_hasComm2 = false;
    float d_comm1Freq = 0;
    float d_comm2Freq = 0;

    bool d_hasNav1 = false;
    bool d_hasNav2 = false;
    float d_nav1Freq = 0;
    float d_nav2Freq = 0;

public:
    explicit RadioInfoBackend(QObject *parent = nullptr);

    bool hasComm1() const;
    bool hasComm2() const;
    float comm1Freq() const;
    float comm2Freq() const;

    bool hasNav1() const;
    bool hasNav2() const;
    float nav1Freq() const;
    float nav2Freq() const;

signals:
    void hasComm1Changed();
    void hasComm2Changed();
    void comm1FreqChanged();
    void comm2FreqChanged();

    void hasNav1Changed();
    void hasNav2Changed();
    void nav1FreqChanged();
    void nav2FreqChanged();

public slots:
    void updateComm1State(bool newValue);
    void updateComm2State(bool newValue);
    void updateComm1Freq(float newValue);
    void updateComm2Freq(float newValue);

    void updateNav1State(bool newValue);
    void updateNav2State(bool newValue);
    void updateNav1Freq(float newValue);
    void updateNav2Freq(float newValue);
};

#endif   // RADIOINFOBACKEND_H
