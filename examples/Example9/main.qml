import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

import de.goodpoint_hd 1.0

Window {
    id: window
    visible: true
    height: 640
    width: 480


    ScrollView {
        id: scrollView
        anchors.fill: parent

        contentItem: ColumnLayout {
            width: scrollView.width

            Repeater {
                anchors.horizontalCenter: parent.horizontalCenter
                model: 500

                ColumnLayout {
                    anchors.horizontalCenter: parent.horizontalCenter
                    XkcdDownloader {
                        id: downloader
                        xkcdID: index+1000
                    }

                    Text {
                        id: titleText
                        text: downloader.finished?downloader.title:"Loading ..."
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: parent.top
                    }

                    Image {
                        id: image
                        source: downloader.finished?("image://xkcd/" + downloader.xkcdID):""
                        anchors.centerIn: parent
                    }

                    ProgressBar {
                        id: progressBar
                        value: downloader.imageDownloadProgress/100
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.bottom: parent.bottom
                    }
                }
            }
        }
    }
}
