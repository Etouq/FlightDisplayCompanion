#ifndef ANGLEOFATTACKINDICATORBACKEND_H
#define ANGLEOFATTACKINDICATORBACKEND_H

#include <QColor>
#include <QObject>

class AngleOfAttackIndicatorBackend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double aoaAngle READ aoaAngle NOTIFY aoaAngleChanged)
    Q_PROPERTY(QColor cursorColor READ cursorColor NOTIFY cursorColorChanged)

    // exposed items
    double d_aoaAngle = 50;
    QColor d_cursorColor = "white";

    // internal items
    double d_redPercent = 17;


public:
    explicit AngleOfAttackIndicatorBackend(QObject *parent = nullptr);

    double aoaAngle() const;
    QColor cursorColor() const;

signals:
    void aoaAngleChanged();
    void cursorColorChanged();

public slots:
    void updateAoa(double newValue);
};

#endif   // ANGLEOFATTACKINDICATORBACKEND_H
