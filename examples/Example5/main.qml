import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

Window {
    visible: true
    height: 640
    width: 480

        Text {
            text: comicTitle
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
        }

        Image {
            source: imageURL
            anchors.centerIn: parent
        }

        ProgressBar {
            value: imageProgress/100.0
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
        }
}
