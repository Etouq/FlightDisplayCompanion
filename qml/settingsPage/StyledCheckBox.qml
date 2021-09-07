import QtQuick 2.15
import QtQuick.Controls 2.15

CheckBox {
    id: root
    width: 200
    height: 25
    padding: 0
    opacity: enabled ? 1 : 0.38

    indicator: Rectangle {
        x: root.width - 25
        width: root.height
        height: root.height
        color: "transparent"
        radius: 2
        border.color: root.enabled && root.checked ? "#00b4ff" : "#666767"
        border.width: root.checked ? root.height / 2 : 2

        Behavior on border.width {
            NumberAnimation {
                duration: 100
                easing.type: Easing.OutCubic
            }
        }

        Behavior on border.color {
            ColorAnimation {
                duration: 100
                easing.type: Easing.OutCubic
            }
        }

        Image {
            x: (parent.width - width) / 2
            y: (parent.height - height) / 2
            width: 17.5
            height: 17.5
            source: "qrc:/images/buttonImages/check.png"
            fillMode: Image.PreserveAspectFit

            scale: root.checked ? 1 : 0
            Behavior on scale { NumberAnimation { duration: 100 } }
        }

    }

    contentItem: Text {
        id: textItem
        x: 0
        height: root.height
        text: root.text
        font.family: "Roboto Mono"
        font.pixelSize: 20
        color: root.enabled ? "black" : "#666767"
        verticalAlignment: Text.AlignVCenter
    }

}
