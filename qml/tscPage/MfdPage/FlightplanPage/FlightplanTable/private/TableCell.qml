import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    height: parent.height

    gradient: Gradient {
        GradientStop {
            position: 0.0
            color: "#0093d0"
        }
        GradientStop {
            position: 0.6
            color: Qt.rgba(0, 147, 208, 0)
        }
    }

    property alias text: textItem.text
    property alias pixelSize: textItem.font.pixelSize
    property alias textObject: textItem

    Text {
        id: textItem

        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 15

        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: 45

        color: "white"
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
        lineHeight: 0.8
    }

}
