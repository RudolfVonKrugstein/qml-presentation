#include "qquickpixmapimageprovider.h"

QQuickPixmapImageProvider::QQuickPixmapImageProvider() : QQuickImageProvider(QQuickImageProvider::Pixmap)
{
}

void QQuickPixmapImageProvider::addPixmap(const QString& name,const QPixmap &p) {
    pixmaps[name] = p;
}

QPixmap QQuickPixmapImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) {
    if (pixmaps.find(id) == pixmaps.end()) {
        return QPixmap();// Empty response
    }
    QPixmap& pixmap = pixmaps[id];
    if (size) {
        *size = pixmap.size();
    }
    return pixmap.scaled(requestedSize.width() >0 ? requestedSize.width() : pixmap.width(),
                   requestedSize.height() >0 ? requestedSize.height() : pixmap.height());
}
