import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

Window {
    visible: true
    height: 640
    width: 480

    Text {
        id: titleText
        text: "Loading ..."
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
    }

    Image {
        id: image
        source: ""
        anchors.centerIn: parent
    }

    ProgressBar {
        id: progressBar
        value: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
    }


    Connections {
        target: downloader
        onTitleFinished: {
            titleText.text = title
        }
        onImageProgressChanged: {
            progressBar.value = progress/100.0
        }
        onImageFinished: {
            image.source = "image://xkcd/" + xkcdID
        }
    }

}
