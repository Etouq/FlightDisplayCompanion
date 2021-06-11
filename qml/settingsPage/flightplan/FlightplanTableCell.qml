import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    x: 0
    width: 0
    height: 90
    y: 0
    color: "black"

    property string textValue: ""
    property int pixelSize: 30
    property alias textObject: textItem

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#0093d0" }
            GradientStop { position: 0.6; color: Qt.rgba(0, 147, 208, 0) }
        }
        border.width: 2
        border.color: "black"
    }

    Text {
        id: textItem
        anchors.fill: parent
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: pixelSize
        color: "white"
        text: textValue
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        lineHeight: 0.8
    }

}
