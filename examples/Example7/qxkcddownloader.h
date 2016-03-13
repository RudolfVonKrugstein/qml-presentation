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
    Q_PROPERTY(QString title READ getTitle NOTIFY titleChanged);
    Q_PROPERTY(int xkcdID READ getXkcdID WRITE setXkcdID NOTIFY xkcdIDChanged);
    Q_PROPERTY(int imageDownloadProgress READ getImageDownloadProgress NOTIFY imageProgressChanged);
    Q_PROPERTY(bool finished READ getFinished NOTIFY finishedChanged);

public:
    explicit QXkcdDownloader(QObject *parent = 0);
    explicit QXkcdDownloader(QQuickPixmapImageProvider* imageProvider, QNetworkAccessManager* manager, QObject *parent = 0);
    virtual ~QXkcdDownloader();
    void startDownload(int id);

    QString getTitle();
    int getXkcdID();
    int setXkcdID(int id);
    int getImageDownloadProgress();
    bool getFinished();

    int imageDownloadProgress;
    QString title;
    QPixmap imageData;
    int xkcdID;
    bool finished;
private:
    QNetworkAccessManager *manager;
    QQuickPixmapImageProvider *imageProvider;

signals:
    void imageProgressChanged(int progress);
    void imageFinished(int xkcdID);
    void titleChanged(QString title);
    void xkcdIDChanged(int id);
    void finishedChanged();
};

#endif // QDOWNLOADER_H
