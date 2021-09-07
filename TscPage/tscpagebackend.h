#ifndef TSCPAGEBACKEND_H
#define TSCPAGEBACKEND_H

#include <QObject>
#include <QString>

class NetworkClient;

class TscPageBackend : public QObject
{
    Q_OBJECT

    // speedbugs
    Q_PROPERTY(int vrSpeed MEMBER d_vrSpeed NOTIFY vrSpeedChanged)
    Q_PROPERTY(int vxSpeed MEMBER d_vxSpeed NOTIFY vxSpeedChanged)
    Q_PROPERTY(int vySpeed MEMBER d_vySpeed NOTIFY vySpeedChanged)
    Q_PROPERTY(int vappSpeed MEMBER d_vappSpeed NOTIFY vappSpeedChanged)

    Q_PROPERTY(bool vrActive MEMBER d_vrActive NOTIFY vrActiveChanged)
    Q_PROPERTY(bool vxActive MEMBER d_vxActive NOTIFY vxActiveChanged)
    Q_PROPERTY(bool vyActive MEMBER d_vyActive NOTIFY vyActiveChanged)
    Q_PROPERTY(bool vappActive MEMBER d_vappActive NOTIFY vappActiveChanged)

    // timer
    Q_PROPERTY(QString timeString READ timeString NOTIFY timeStringChanged)
    Q_PROPERTY(bool isCounting MEMBER d_isCounting NOTIFY isCountingChanged)
    Q_PROPERTY(
      bool isCountingDown MEMBER d_isCountingDown NOTIFY isCountingDownChanged)

    // radios
    Q_PROPERTY(int com1StbyHz READ com1StbyHz NOTIFY com1StbyHzChanged)
    Q_PROPERTY(int com1ActiveHz READ com1ActiveHz NOTIFY com1ActiveHzChanged)
    Q_PROPERTY(int com2StbyHz READ com2StbyHz NOTIFY com2StbyHzChanged)
    Q_PROPERTY(int com2ActiveHz READ com2ActiveHz NOTIFY com2ActiveHzChanged)
    Q_PROPERTY(int nav1StbyHz READ nav1StbyHz NOTIFY nav1StbyHzChanged)
    Q_PROPERTY(int nav1ActiveHz READ nav1ActiveHz NOTIFY nav1ActiveHzChanged)
    Q_PROPERTY(int nav2StbyHz READ nav2StbyHz NOTIFY nav2StbyHzChanged)
    Q_PROPERTY(int nav2ActiveHz READ nav2ActiveHz NOTIFY nav2ActiveHzChanged)

    Q_PROPERTY(int xpdrCode READ xpdrCode NOTIFY xpdrCodeChanged)
    Q_PROPERTY(int xpdrState READ xpdrState WRITE setXpdrState NOTIFY xpdrStateChanged)


    // speedbugs
    int d_vrSpeed = 85;
    int d_vxSpeed = 100;
    int d_vySpeed = 124;
    int d_vappSpeed = 85;

    bool d_vrActive = false;
    bool d_vxActive = false;
    bool d_vyActive = false;
    bool d_vappActive = false;

    // timer
    int d_baseTime = 0;    // number of seconds entered
    int d_beginTime = 0;   // time when counting started
    int d_initialValue = 0;

    QString d_timeString = "00:00:00";
    bool d_isCounting = false;
    bool d_isCountingDown = false;

    // radios
    int d_com1StbyHz = 118850000;
    int d_com1ActiveHz = 124850000;
    int d_com2StbyHz = 118850000;
    int d_com2ActiveHz = 124850000;
    int d_nav1StbyHz = 113900000;
    int d_nav1ActiveHz = 110500000;
    int d_nav2StbyHz = 113900000;
    int d_nav2ActiveHz = 110500000;

    int d_xpdrCode = 7000;
    int d_xpdrState = 0;   // 0: off, 1: stby, 2: test, 3: on, 4: alt, 5: ground

public:
    explicit TscPageBackend(QObject *parent = nullptr);

    void connectTscSlots(NetworkClient *netClient);

    // timer
    QString timeString() const;

    Q_INVOKABLE void setCountingDown(bool state);
    Q_INVOKABLE void switchCounting();
    Q_INVOKABLE void reset();
    Q_INVOKABLE void endKeyboardCallback(int time);

    Q_INVOKABLE void updateTime();
    Q_INVOKABLE int getCurrentDisplay();

    // radios
    int com1StbyHz() const;
    int com1ActiveHz() const;
    int com2StbyHz() const;
    int com2ActiveHz() const;
    int nav1StbyHz() const;
    int nav1ActiveHz() const;
    int nav2StbyHz() const;
    int nav2ActiveHz() const;

    Q_INVOKABLE void setCom1Freq(int32_t newFreq, bool swap);
    Q_INVOKABLE void setCom2Freq(int32_t newFreq, bool swap);
    Q_INVOKABLE void setNav1Freq(int32_t newFreq, bool swap);
    Q_INVOKABLE void setNav2Freq(int32_t newFreq, bool swap);

    Q_INVOKABLE void swapCom1();
    Q_INVOKABLE void swapCom2();
    Q_INVOKABLE void swapNav1();
    Q_INVOKABLE void swapNav2();

    int xpdrCode() const;
    int xpdrState() const;

    Q_INVOKABLE void setXpdrCode(int32_t newCode);
    void setXpdrState(int8_t newState);

signals:
    // speedbugs
    void vrSpeedChanged();
    void vxSpeedChanged();
    void vySpeedChanged();
    void vappSpeedChanged();

    void vrActiveChanged();
    void vxActiveChanged();
    void vyActiveChanged();
    void vappActiveChanged();

    // timer
    void timeStringChanged();
    void isCountingChanged();
    void isCountingDownChanged();

    // radios
    void com1StbyHzChanged();
    void com1ActiveHzChanged();
    void com2StbyHzChanged();
    void com2ActiveHzChanged();
    void nav1StbyHzChanged();
    void nav1ActiveHzChanged();
    void nav2StbyHzChanged();
    void nav2ActiveHzChanged();

    void xpdrCodeChanged();
    void xpdrStateChanged();

    // network signals
    void sendCommandsToSim(const QByteArray &data);

public slots:
    void updateCom1Stby(float newFreq);
    void updateCom1Active(float newFreq);
    void updateCom2Stby(float newFreq);
    void updateCom2Active(float newFreq);
    void updateNav1Stby(float newFreq);
    void updateNav1Active(float newFreq);
    void updateNav2Stby(float newFreq);
    void updateNav2Active(float newFreq);

    void updateXpdrCode(int newCode);
    void updateXpdrState(int newState);
};

#endif   // TSCPAGEBACKEND_H
