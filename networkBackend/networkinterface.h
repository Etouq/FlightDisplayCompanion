#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H


#include <QObject>
#include <QString>

// interface for qml to get connection state etc.
class NetworkInterface : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(int port READ port WRITE setPort NOTIFY portChanged)
    Q_PROPERTY(QString errorString READ errorString NOTIFY errorStringChanged)
    Q_PROPERTY(int connected READ connected NOTIFY connectedChanged)
    Q_PROPERTY(bool serverIsDesigner READ serverIsDesigner NOTIFY serverIsDesignerChanged)

    QString d_address = "";
    int d_port = -1;
    QString d_errorString = "";
    int d_connected = 0;   // 0: not connected, 1: connected, 2: waiting for connect completion, 3: waiting for disconnect completion

    bool d_serverIsDesigner = true;

public:
    explicit NetworkInterface(QObject *parent = nullptr);

    QString address() const;
    int port() const;
    QString errorString() const;
    int connected() const;
    bool serverIsDesigner() const;


    void setAddress(const QString &newAddress);
    void setPort(int newPort);

    Q_INVOKABLE void buttonPressed();



signals:
    void addressChanged();
    void portChanged();
    void errorStringChanged();
    void connectedChanged();
    void simConnectClosed();

    void connectPressed(const QString &address, int port);
    void disconnectPressed();

    void serverIsDesignerChanged();

public slots:
    void resetButton();
    void setNewErrorString(const QString &newError);
    void setConnected();
    void setDisconnected();
    void simConnectionClosed();
    void connectedToSim();
    void connectedToDesigner();
};

#endif   // NETWORKINTERFACE_H
