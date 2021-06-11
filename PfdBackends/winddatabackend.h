#ifndef WINDDATABACKEND_H
#define WINDDATABACKEND_H

#include <QObject>

class WindDataBackend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double windDirection READ windDirection NOTIFY windDirectionChanged)
    Q_PROPERTY(double windStrength READ windStrength NOTIFY windStrengthChanged)
    Q_PROPERTY(double windTrueDirection READ windTrueDirection NOTIFY windTrueDirectionChanged)

    double d_wind_direction = 0;
    double d_wind_strength = 0;
    double d_wind_true_direction = 0;

public:
    explicit WindDataBackend(QObject *parent = nullptr);

    double windDirection() const;
    double windStrength() const;
    double windTrueDirection() const;

signals:
    void windDirectionChanged();
    void windStrengthChanged();
    void windTrueDirectionChanged();

public slots:
    void updateWindDirection(double newValue);
    void updateWindStrength(double newValue);
    void updateWindTrueDirection(double newValue);
};

#endif   // WINDDATABACKEND_H
