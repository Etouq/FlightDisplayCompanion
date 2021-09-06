import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: root
    width: 252
    height: 252

    background: Rectangle {
        anchors.fill: parent
        color: parent.down ? parent.enabled ? "#0093d0" : "black" : "transparent"

        Rectangle {
            anchors.fill: parent
            gradient: Gradient {
                GradientStop { position: 0; color: root.enabled ? "#0093d0" : "#303030" }
                GradientStop { position: 0.6; color: root.enabled ? "#000093d0" : "#00303030" }
            }
        }


    }
}
