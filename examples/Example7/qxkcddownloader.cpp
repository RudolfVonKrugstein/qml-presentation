#include "qxkcddownloader.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

QXkcdDownloader::QXkcdDownloader(QObject* parent) : QObject(parent) {
}

QXkcdDownloader::QXkcdDownloader(QQuickPixmapImageProvider* imageProvider, QNetworkAccessManager* manager, QObject *parent) :
    QObject(parent)
{
    this->imageProvider = imageProvider;
    this->manager = manager;
    imageDownloadProgress = 0;
    title = "";
}

QXkcdDownloader::~QXkcdDownloader()
{
    manager->deleteLater();
}

QString QXkcdDownloader::getTitle() {
    return title;
}

int QXkcdDownloader::getXkcdID() {
    return xkcdID;
}

int QXkcdDownloader::setXkcdID(int id) {
    startDownload(id);
    emit xkcdIDChanged(id);
}

int QXkcdDownloader::getImageDownloadProgress() {
    return imageDownloadProgress;
}

bool QXkcdDownloader::getFinished() {
    return finished;
}

void QXkcdDownloader::startDownload(int id)
{
    xkcdID = id;
    finished = false;
    emit finishedChanged();

    QString jsonUrl = "http://xkcd.com/" + QString::number(id) + "/info.0.json";

    QNetworkRequest request;
    request.setUrl(QUrl(jsonUrl));
    QNetworkReply* reply = manager->get(request);

    // Downloaded the json information (format descried here: https://xkcd.com/json.html)
    connect(reply,&QNetworkReply::finished,[this,reply](){

        QByteArray data = reply->readAll();
        QJsonObject jsonData = QJsonDocument::fromJson(data).object();

        if (reply->error() != QNetworkReply::NoError) {
            title = reply->errorString();
            emit titleChanged(title);
            return;
        }
        title = jsonData["title"].toString();
        emit titleChanged(title);

        // Download the image
        QNetworkRequest request;
        request.setUrl(jsonData["img"].toString());
        QNetworkReply* imgReply = manager->get(request);

        connect(imgReply,&QNetworkReply::finished,[this,imgReply]{
            // Finished downloading image! Add it to the image provider
            imageData.loadFromData(imgReply->readAll(),"PNG");
            imageProvider->addPixmap(QString::number(xkcdID),imageData);

            finished = true;
            emit finishedChanged();
            emit imageFinished(xkcdID);
            emit xkcdIDChanged(xkcdID);
            imgReply->deleteLater();
        });

        connect(imgReply,&QNetworkReply::downloadProgress,[this](qint64 read,qint64 total) {
            imageDownloadProgress = read/((double)total) * 100;
            emit imageProgressChanged(imageDownloadProgress);
        });
        reply->deleteLater();
    });
}
