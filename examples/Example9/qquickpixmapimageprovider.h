#ifndef QQUICKPIXMAPIMAGEPROVIDER_H
#define QQUICKPIXMAPIMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QMap>
#include <QDebug>

class QQuickPixmapImageProvider : public QQuickImageProvider
{
public:
    QQuickPixmapImageProvider();
    void addPixmap(const QString& name, const QPixmap& p);
private:
    QMap<QString,QPixmap> pixmaps;
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

};

#endif // QQUICKPIXMAPIMAGEPROVIDER_H
