#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml>
#include <QDebug>
#include "qxkcddownloader.h"
#include "qquickpixmapimageprovider.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Setup image provider
    QQuickPixmapImageProvider *xkcdImageProvider = new QQuickPixmapImageProvider;
    engine.addImageProvider("xkcd",xkcdImageProvider);

    // Global network manager
    QNetworkAccessManager manager;

    QXkcdDownloader::manager = &manager;
    QXkcdDownloader::imageProvider = xkcdImageProvider;
    // Register the downloader type
    qmlRegisterType<QXkcdDownloader>("de.goodpoint_hd",1,0,"XkcdDownloader");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
