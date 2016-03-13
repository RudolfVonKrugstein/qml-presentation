#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
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

    // Set a downloader
    QXkcdDownloader downloader(xkcdImageProvider,&manager);
    // Here we register variables to be used in qml
    engine.rootContext()->setContextProperty("imageProgress",0);
    engine.rootContext()->setContextProperty("imageURL","");
    engine.rootContext()->setContextProperty("comicTitle","Loading...");
    // Connect to change qml variables
    QObject::connect(&downloader,&QXkcdDownloader::onImageProgressChanged,[&engine,&downloader](int progress){
        engine.rootContext()->setContextProperty("imageProgress",progress);
    });
    downloader.connect(&downloader,&QXkcdDownloader::onTitleFinished,[&engine,&downloader](){
       engine.rootContext()->setContextProperty("comicTitle",downloader.title);
    });
    downloader.connect(&downloader,&QXkcdDownloader::onImageFinished,[&engine,&downloader](){
       // The downloader adds the image to the ImageProvider, we have to set the correct URL
       engine.rootContext()->setContextProperty("imageURL","image://xkcd/"+QString::number(downloader.xkcdID));
    });

    //Start the download
    downloader.startDownload(681);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
