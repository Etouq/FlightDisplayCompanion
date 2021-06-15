#ifndef APINFOBACKEND_H
#define APINFOBACKEND_H

#include <QObject>
#include <QString>

class ApInfoBackend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool has_ap READ has_ap NOTIFY has_apChanged)
    Q_PROPERTY(QString ap_lateralActive READ ap_lateralActive NOTIFY ap_lateralActiveChanged)
    Q_PROPERTY(QString ap_lateralArmed READ ap_lateralArmed NOTIFY ap_lateralArmedChanged)
    Q_PROPERTY(bool ap_status READ ap_status NOTIFY ap_statusChanged)
    Q_PROPERTY(bool ap_ydStatus READ ap_ydStatus NOTIFY ap_ydStatusChanged)
    Q_PROPERTY(bool ap_fdActive READ ap_fdActive NOTIFY ap_fdActiveChanged)
    Q_PROPERTY(QString ap_verticalActive READ ap_verticalActive NOTIFY ap_verticalActiveChanged)
    Q_PROPERTY(QString ap_modeReference READ ap_modeReference NOTIFY ap_modeReferenceChanged)
    Q_PROPERTY(QString ap_armed READ ap_armed NOTIFY ap_armedChanged)
    Q_PROPERTY(QString ap_armedReference READ ap_armedReference NOTIFY ap_armedReferenceChanged)


    bool d_has_ap = false;

    QString d_ap_lateralActive = "";
    QString d_ap_lateralArmed = "";

    bool d_ap_status = false;
    bool d_ap_ydStatus = false;
    bool d_ap_fdActive = false;

    QString d_ap_verticalActive = "";
    QString d_ap_modeReference = "";

    QString d_ap_armed = "";
    QString d_ap_armedReference = "";

    // strings are sent over from server



public:
    explicit ApInfoBackend(QObject *parent = nullptr);

    bool has_ap() const;
    QString ap_lateralActive() const;
    QString ap_lateralArmed() const;
    bool ap_status() const;
    bool ap_ydStatus() const;
    bool ap_fdActive() const;
    QString ap_verticalActive() const;
    QString ap_modeReference() const;
    QString ap_armed() const;
    QString ap_armedReference() const;

signals:
    void has_apChanged();
    void ap_lateralActiveChanged();
    void ap_lateralArmedChanged();
    void ap_statusChanged();
    void ap_ydStatusChanged();
    void ap_fdActiveChanged();
    void ap_verticalActiveChanged();
    void ap_modeReferenceChanged();
    void ap_armedChanged();
    void ap_armedReferenceChanged();

public slots:
    void updateHas_ap(bool newValue);
    void updateAp_lateralActive(QString const &newValue);
    void updateAp_lateralArmed(QString const &newValue);
    void updateAp_status(bool newValue);
    void updateAp_ydStatus(bool newValue);
    void updateAp_fdActive(bool newValue);
    void updateAp_verticalActive(QString const &newValue);
    void updateAp_modeReference(QString const &newValue);
    void updateAp_armed(QString const &newValue);
    void updateAp_armedReference(QString const &newValue);
};

#endif   // APINFOBACKEND_H
