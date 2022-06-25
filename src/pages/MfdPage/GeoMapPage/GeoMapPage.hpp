#ifndef __GEOMAP_HPP__
#define __GEOMAP_HPP__

#include <QColor>
#include <QGeoCoordinate>
#include <QObject>
//#include <QSettings>
#include "common/QmlEnums.hpp"

namespace io::network
{
class NetworkClient;
}

namespace pages::mfd
{

class GeoMapPage : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double trueHeading READ trueHeading NOTIFY trueHeadingChanged)
    Q_PROPERTY(QGeoCoordinate userPosition READ userPosition NOTIFY userPositionChanged)

    Q_PROPERTY(QString iconPath READ iconPath NOTIFY iconPathChanged)
    Q_PROPERTY(double iconScale READ iconScale WRITE setIconScale NOTIFY iconScaleChanged)
    Q_PROPERTY(QColor iconColor READ iconColor WRITE setIconColor NOTIFY iconColorChanged)
    Q_PROPERTY(QColor iconBorder READ iconBorder WRITE setIconBorder NOTIFY iconBorderChanged)
    Q_PROPERTY(QmlMapRotationModeClass::Value rotationMode READ rotationMode WRITE setRotationMode NOTIFY rotationModeChanged)

public:

    explicit GeoMapPage(io::network::NetworkClient *netClient, QObject *parent = nullptr);

    double trueHeading() const
    {
        return d_trueHeading;
    }

    const QGeoCoordinate &userPosition() const
    {
        return d_userPosition;
    }

    Q_INVOKABLE int iconCount() const
    {
        return 1;//s_iconPaths.size();
    }

    Q_INVOKABLE const QString iconAt(int idx) const
    {
        return d_iconPath;//s_iconPaths.at(idx);
    }

    Q_INVOKABLE void selectIcon(int idx)
    {
        //d_iconPath = s_iconPaths.at(idx);
        //QSettings().setValue("pages/mfd/geomap/iconIdx", idx);
        emit iconPathChanged();
    }

    const QString &iconPath() const
    {
        return d_iconPath;
    }

    double iconScale() const
    {
        return d_iconScale;
    }

    const QColor &iconColor() const
    {
        return d_iconColor;
    }

    const QColor &iconBorder() const
    {
        return d_iconBorder;
    }

    MapRotationMode rotationMode() const
    {
        return d_rotationMode;
    }

    void setIconScale(double iconScale)
    {
        d_iconScale = iconScale;
        //QSettings().setValue("pages/mfd/geomap/iconScale", iconScale);
        emit iconScaleChanged();
    }

    void setIconColor(const QColor &iconColor)
    {
        d_iconColor = iconColor;
        //QSettings().setValue("pages/mfd/geomap/iconColor", iconColor);
        emit iconColorChanged();
    }

    void setIconBorder(const QColor &iconBorder)
    {
        d_iconBorder = iconBorder;
        //QSettings().setValue("pages/mfd/geomap/iconBorder", iconBorder);
        emit iconBorderChanged();
    }

    void setRotationMode(MapRotationMode rotationMode)
    {
        d_rotationMode = rotationMode;
        //QSettings().setValue("pages/mfd/geomap/rotationMode", QVariant::fromValue(rotationMode));
        emit rotationModeChanged();
    }

signals:

    void trueHeadingChanged();
    void userPositionChanged();

    void iconPathChanged();
    void iconScaleChanged();
    void iconColorChanged();
    void iconBorderChanged();
    void rotationModeChanged();

public slots:

    void updateTrueHeading(double newValue)
    {
        d_trueHeading = newValue;
        emit trueHeadingChanged();
    }

    void updateUserPosition(const QGeoCoordinate &newCoord)
    {
        d_userPosition = newCoord;
        emit userPositionChanged();
    }

private:


    double d_trueHeading = 0;
    QGeoCoordinate d_userPosition = QGeoCoordinate(0, 0);

    QString d_iconPath = "M 37.759575 88.151385 A 12.222 12.222 90 0 1 38.221575 85.463385 A 4.011 4.011 90 0 1 40.111575 83.363385 L "
                         "47.608575 80.549385 A 2.247 2.247 90 0 0 48.259575 78.806385 L 47.251575 62.132385 L 20.959575 70.007385 A 0.756 "
                         "0.756 90 0 1 19.972575 69.335385 C 19.783575 67.235385 19.804575 65.723385 21.484575 64.484385 L 46.726575 "
                         "46.151385 A 0.924 0.924 90 0 0 47.062575 45.458385 C 47.188575 42.728385 47.776575 27.629385 48.196575 24.458385 A "
                         "12.6 12.6 90 0 1 50.548575 17.549385 A 2.415 2.415 90 0 1 53.950575 17.549385 A 12.768 12.768 90 0 1 56.365575 "
                         "24.437385 C 56.806575 27.692385 57.520575 42.791385 57.667575 45.437385 A 0.84 0.84 90 0 0 58.003575 46.109385 L "
                         "83.497575 64.253385 C 85.177575 65.471385 85.219575 67.004385 85.030575 69.083385 A 0.735 0.735 90 0 1 84.064575 "
                         "69.755385 L 57.709575 62.153385 L 56.848575 78.953385 A 2.1 2.1 90 0 0 57.499575 80.675385 L 65.059575 83.321385 A "
                         "4.2 4.2 90 0 1 66.949575 85.421385 A 13.944 13.944 90 0 1 67.432575 88.109385 Z";
    double d_iconScale = 1;
    QColor d_iconColor = Qt::white;
    QColor d_iconBorder = Qt::black;

    MapRotationMode d_rotationMode = MapRotationMode::NORTH_UP;

//    static const QString s_defaultPlanePath;
//    static const QString s_cursorIconPath;
//    static const QString s_triangleIconPath;
//    static const QString s_airlinerIconPath;
//    static const QString s_gliderIconPath;
//    static const QString s_glider2IconPath;
//    static const QString s_jetIconPath;
//    static const QString s_propIconPath;
//    static const QString s_turbopropIconPath;
//    static const QString s_heliIconPath;

//    inline static const QList<QString> s_iconPaths = { s_defaultPlanePath, s_cursorIconPath, s_triangleIconPath,
//                                                       s_airlinerIconPath, s_gliderIconPath, s_glider2IconPath,
//                                                       s_jetIconPath,      s_propIconPath,   s_turbopropIconPath,
//                                                       s_heliIconPath };
};

}  // namespace pages::mfd


#endif  // __GEOMAP_HPP__
