import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 480; height: 640
    Rectangle {
        id: page
        width: widthSlider.value
        height: heightSlider.value
        border.width: borderWidthSlider.value
        anchors.verticalCenter: parent.verticalCenter
        radius: radiusSlider.value

        x: leftRadioButton.checked? 0 : parent.width-width

        Behavior on x {
            NumberAnimation {
                duration: 2000
                easing.type: Easing.OutBounce
            }
        }

        color: "lightgray "
        Text {
            id: helloText
            text: "Hello world! "
            y: 30
            anchors.horizontalCenter: page.horizontalCenter
            font.pointSize: 24; font.bold: true
        }
     }

    GridLayout {
        columns: 2
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        Label {text: "width:"}
        Slider {
            id: widthSlider
            minimumValue: 0
            maximumValue: window.width
        }
        Label {text: "height:"}
        Slider {
            id: heightSlider
            minimumValue: 0
            maximumValue: window.height
        }
        Label {text: "radius:"}
        Slider {
            id: radiusSlider
            minimumValue: 0
            maximumValue: 20
        }
        Label {text: "border width:"}
        Slider {
            id: borderWidthSlider
            minimumValue: 0
            maximumValue: 10
        }
        Label {text: "position:"}
        RowLayout {
            ExclusiveGroup{id: positionGroup}
            RadioButton{
                id: leftRadioButton
                text: "left"
                checked: true
                exclusiveGroup: positionGroup
            }
            RadioButton{
                id: rightRadioButton
                text: "right"
                exclusiveGroup: positionGroup
            }
        }
    }
}
