import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: root
    width: 250
    height: 45


    background: Rectangle {
        color: root.enabled ? (root.pressed ? "white" : "#00b4ff") : "#949595"
        radius: 6

        Rectangle {
            anchors.fill: parent
            color: "white"
            opacity: 0.24
            visible: root.focus && !root.pressed
        }
    }

    contentItem: Text {
        text: root.text
        color: root.enabled ? (root.pressed ? "#00b4ff" : "white") : "#666767"
        font.family: "Roboto Mono"
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 20
    }


}
