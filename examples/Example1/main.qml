import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 480; height: 640
    Rectangle {
        id: page
        width: 320; height: 480
        color: "lightgray "
        Text {
            id: helloText
            text: "Hello world! "
            y: 30
            anchors.horizontalCenter: page.horizontalCenter
            font.pointSize: 24; font.bold: true
        }
     }

}
