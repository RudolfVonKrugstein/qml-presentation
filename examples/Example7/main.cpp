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

    // Register the downloader type
    qmlRegisterType<QXkcdDownloader>("de.goodpoint_jd",1,0,"Downloader");

    // Set a downloader
    QXkcdDownloader downloader(xkcdImageProvider,&manager);
    // Here we register variables to be used in qml
    engine.rootContext()->setContextProperty("downloader",&downloader);

    //Start the download
    downloader.startDownload(681);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
