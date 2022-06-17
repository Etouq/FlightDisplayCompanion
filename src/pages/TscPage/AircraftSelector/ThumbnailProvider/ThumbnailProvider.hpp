#ifndef __THUMBNAIL_PROVIDER_HPP__
#define __THUMBNAIL_PROVIDER_HPP__

#include <QHash>
#include <QQuickImageProvider>


namespace pages::tsc
{

class ThumbnailProvider : public QQuickImageProvider
{
public:

    ThumbnailProvider()
      : QQuickImageProvider(QQuickImageProvider::Image)
    {}

    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override
    {
        if (!d_images.contains(id))
        {
            QImage ret(requestedSize, QImage::Format_RGB32);
            ret.fill(Qt::red);
            *size = requestedSize;
            return ret;
        }

        QImage ret = d_images.value(id);
        *size = ret.size();

        if (requestedSize.width() > 0 && requestedSize.height() > 0)
        {
            return ret.scaled(requestedSize, Qt::KeepAspectRatio);
        }
        if (requestedSize.width() > 0)
        {
            return ret.scaledToWidth(requestedSize.width());
        }
        if (requestedSize.height() > 0)
        {
            return ret.scaledToHeight(requestedSize.height());
        }

        return ret;
    }

    void storeImage(QString identifier, const QImage &image)
    {
        d_images.insert(identifier, image);
    }

    void clear()
    {
        d_images.clear();
    }

private:

    QHash<QString, QImage> d_images;
};

}  // namespace pages::tsc


#endif  // __THUMBNAIL_PROVIDER_HPP__