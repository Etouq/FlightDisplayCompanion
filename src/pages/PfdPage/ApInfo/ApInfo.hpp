#ifndef _APINFO_HPP__
#define _APINFO_HPP__

#include <QObject>
#include <QString>

namespace io::network
{
class NetworkClient;
}

namespace pages::pfd
{

class ApInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool hasAp READ hasAp NOTIFY hasApChanged)
    Q_PROPERTY(QString apLateralActive READ apLateralActive NOTIFY apLateralActiveChanged)
    Q_PROPERTY(QString apLateralArmed READ apLateralArmed NOTIFY apLateralArmedChanged)
    Q_PROPERTY(bool apStatus READ apStatus NOTIFY apStatusChanged)
    Q_PROPERTY(bool apYdStatus READ apYdStatus NOTIFY apYdStatusChanged)
    Q_PROPERTY(bool apFdActive READ apFdActive NOTIFY apFdActiveChanged)
    Q_PROPERTY(QString apVerticalActive READ apVerticalActive NOTIFY apVerticalActiveChanged)
    Q_PROPERTY(QString apModeReference READ apModeReference NOTIFY apModeReferenceChanged)
    Q_PROPERTY(QString apArmed READ apArmed NOTIFY apArmedChanged)
    Q_PROPERTY(QString apArmedReference READ apArmedReference NOTIFY apArmedReferenceChanged)

public:

    explicit ApInfo(io::network::NetworkClient *netClient, QObject *parent = nullptr);

    bool hasAp() const
    {
        return d_hasAp;
    }

    const QString &apLateralActive() const
    {
        return d_apLateralActive;
    }

    const QString &apLateralArmed() const
    {
        return d_apLateralArmed;
    }

    bool apStatus() const
    {
        return d_apStatus;
    }

    bool apYdStatus() const
    {
        return d_apYdStatus;
    }

    bool apFdActive() const
    {
        return d_apFdActive;
    }

    const QString &apVerticalActive() const
    {
        return d_apVerticalActive;
    }

    const QString &apModeReference() const
    {
        return d_apModeReference;
    }

    const QString &apArmed() const
    {
        return d_apArmed;
    }

    const QString &apArmedReference() const
    {
        return d_apArmedReference;
    }

signals:
    void hasApChanged();
    void apLateralActiveChanged();
    void apLateralArmedChanged();
    void apStatusChanged();
    void apYdStatusChanged();
    void apFdActiveChanged();
    void apVerticalActiveChanged();
    void apModeReferenceChanged();
    void apArmedChanged();
    void apArmedReferenceChanged();


public slots:

    void updateHasAp(bool newValue)
    {
        d_hasAp = newValue;
        emit hasApChanged();
    }

    void updateApLateralActive(const QString &newValue)
    {
        d_apLateralActive = newValue;
        emit apLateralActiveChanged();
    }

    void updateApLateralArmed(const QString &newValue)
    {
        d_apLateralArmed = newValue;
        emit apLateralArmedChanged();
    }

    void updateApStatus(bool newValue)
    {
        d_apStatus = newValue;
        emit apStatusChanged();
    }

    void updateApYdStatus(bool newValue)
    {
        d_apYdStatus = newValue;
        emit apYdStatusChanged();
    }

    void updateApFdActive(bool newValue)
    {
        d_apFdActive = newValue;
        emit apFdActiveChanged();
    }

    void updateApVerticalActive(const QString &newValue)
    {
        d_apVerticalActive = newValue;
        emit apVerticalActiveChanged();
    }

    void updateApModeReference(const QString &newValue)
    {
        d_apModeReference = newValue;
        emit apModeReferenceChanged();
    }

    void updateApArmed(const QString &newValue)
    {
        d_apArmed = newValue;
        emit apArmedChanged();
    }

    void updateApArmedReference(const QString &newValue)
    {
        d_apArmedReference = newValue;
        emit apArmedReferenceChanged();
    }

private:

    bool d_hasAp = false;

    QString d_apLateralActive = "";
    QString d_apLateralArmed = "";

    bool d_apStatus = false;
    bool d_apYdStatus = false;
    bool d_apFdActive = false;

    QString d_apVerticalActive = "";
    QString d_apModeReference = "";

    QString d_apArmed = "";
    QString d_apArmedReference = "";
};

}  // namespace pages::pfd


#endif  // _APINFO_HPP__