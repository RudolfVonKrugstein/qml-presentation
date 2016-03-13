#ifndef QDOWNLOADER_H
#define QDOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QStringList>
#include <QPixmap>
#include <qquickpixmapimageprovider.h>

class QXkcdDownloader : public QObject
{
    Q_OBJECT
public:
    explicit QXkcdDownloader(QQuickPixmapImageProvider* imageProvider, QNetworkAccessManager* manager, QObject *parent = 0);
    virtual ~QXkcdDownloader();
    void startDownload(int id);

    int imageDownloadProgress;
    QString title;
    QPixmap imageData;
    int xkcdID;
private:
    QNetworkAccessManager *manager;
    QQuickPixmapImageProvider *imageProvider;

signals:
    void imageProgressChanged(int progress);
    void imageFinished(int xkcdID);
    void titleFinished(QString title);
};

#endif // QDOWNLOADER_H
