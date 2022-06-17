#ifndef __GEOMAP_HPP__
#define __GEOMAP_HPP__

#include <QColor>
#include <QGeoCoordinate>
#include <QObject>
#include <QSettings>

class MapRotationModeClass
{
Q_GADGET

    public:

    enum class Value
    {
        NORTH_UP,
        DTK_UP,
        HDG_UP,
        TRACK_UP
    };
    Q_ENUM(Value)

private:
    explicit MapRotationModeClass();
};

typedef MapRotationModeClass::Value MapRotationMode;

namespace io::network
{
class NetworkClient;
}

namespace pages::mfd
{

class GeoMap : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double trueHeading READ trueHeading NOTIFY trueHeadingChanged)
    Q_PROPERTY(QGeoCoordinate userPosition READ userPosition NOTIFY userPositionChanged)

    Q_PROPERTY(QString iconPath READ iconPath NOTIFY iconPathChanged)
    Q_PROPERTY(double iconScale READ iconScale WRITE setIconScale NOTIFY iconScaleChanged)
    Q_PROPERTY(QColor iconColor READ iconColor WRITE setIconColor NOTIFY iconColorChanged)
    Q_PROPERTY(QColor iconBorder READ iconBorder WRITE setIconBorderColor NOTIFY iconBorderChanged)
    Q_PROPERTY(MapRotationMode rotationMode READ rotationMode WRITE setRotationMode NOTIFY rotationModeChanged)

public:

    explicit GeoMap(io::network::NetworkClient *netClient, QObject *parent = nullptr);

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
        return s_iconPaths.size();
    }

    Q_INVOKABLE const QString iconAt(int idx) const
    {
        return s_iconPaths.at(idx);
    }

    Q_INVOKABLE void selectIcon(int idx)
    {
        d_iconPath = s_iconPaths.at(idx);
        QSettings().setValue("pages/mfd/geomap/iconIdx", idx);
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
        QSettings().setValue("pages/mfd/geomap/iconScale", iconScale);
        emit iconScaleChanged();
    }

    void setIconColor(const QColor &iconColor)
    {
        d_iconColor = iconColor;
        QSettings().setValue("pages/mfd/geomap/iconColor", iconColor);
        emit iconColorChanged();
    }

    void setIconBorder(const QColor &iconBorder)
    {
        d_iconBorder = iconBorder;
        QSettings().setValue("pages/mfd/geomap/iconBorder", iconBorder);
        emit iconBorderChanged();
    }

    void setRotationMode(MapRotationMode rotationMode)
    {
        d_rotationMode = rotationMode;
        QSettings().setValue("pages/mfd/geomap/rotationMode", QVariant::fromValue(rotationMode));
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

    QString d_iconPath = s_defaultPlanePath;
    double d_iconScale = 1;
    QColor d_iconColor = Qt::white;
    QColor d_iconBorder = Qt::black;

    MapRotationMode d_rotationMode = MapRotationMode::NORTH_UP;

    static const QString s_defaultPlanePath;
    static const QString s_cursorIconPath;
    static const QString s_triangleIconPath;
    static const QString s_airlinerIconPath;
    static const QString s_gliderIconPath;
    static const QString s_glider2IconPath;
    static const QString s_jetIconPath;
    static const QString s_propIconPath;
    static const QString s_turbopropIconPath;
    static const QString s_heliIconPath;

    inline static const QList<QString> s_iconPaths = { s_defaultPlanePath, s_cursorIconPath, s_triangleIconPath,
                                                       s_airlinerIconPath, s_gliderIconPath, s_glider2IconPath,
                                                       s_jetIconPath,      s_propIconPath,   s_turbopropIconPath,
                                                       s_heliIconPath };
};

}  // namespace pages::mfd


#endif  // __GEOMAP_HPP__