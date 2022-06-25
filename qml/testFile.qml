import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        anchors.fill: parent
        color: "green"
    }

    Text {
        anchors.centerIn: parent
        text: "Hello Phone"
        color: "red"
        font.pixelSize: 25
    }
}
