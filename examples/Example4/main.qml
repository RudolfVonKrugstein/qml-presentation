import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

Window {
    visible: true
    width: 480
    height: 640

    ColumnLayout {
        anchors.centerIn: parent
        RowLayout {
            TextField {
                id: n1        }
            Text {
                text: "+"
            }
            TextField {
                id: n2
            }
            Text {
                text: " = " + (parseInt(n1.text) + parseInt(n2.text))
            }
        }
        TextField {
             textColor: (text.indexOf("@")<0)?"red":"green"
             onTextChanged: {
                 console.log(text)
             }
        }
    }
}
