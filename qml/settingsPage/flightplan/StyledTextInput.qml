import QtQuick 2.15
import QtQuick.Controls 2.15

TextField {
    id: root
    font.family: "Roboto Mono"
    font.bold: true
    font.pixelSize: 20
    color: "black"
    height: 45
    width: 250
    opacity: enabled ? 1 : 0.38
    leftPadding: 16
    bottomPadding: 6
    topPadding: 12
    rightPadding: 9

    property string placeholderTxt: ""
    property bool nextIsComboBox: false
    property bool overrideEnterHandler: false

    onEditingFinished: ensureVisible(0)

    background: Rectangle {
        color: "transparent"
        border.width: 2
        border.color: root.focus ? "#00b4ff" : "#666767"
        radius: 4

        TextMetrics {
            id: textMetrics
            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 15
            text: textLabel.text
        }

        TextMetrics {
            id: bigTextMetrics
            font.family: "Roboto Mono"
            font.pixelSize: 20
            text: textLabel.text
        }

        Rectangle {
            id: placeholderBg
            anchors.horizontalCenter: parent.left
            anchors.horizontalCenterOffset: 16 + textMetrics.width / 2
            width: root.focus || root.length > 0 ? textMetrics.width + 12 : 0
            height: 4
            y: -1
            color: "#c4c5c6"
            Behavior on width {
                NumberAnimation { duration: 125 }
            }
        }

        Text {
            id: textLabel
            font.family: "Roboto Mono"
            font.bold: root.focus || root.length > 0
            font.pixelSize: root.focus || root.length > 0 ? 15 : 20
            color: root.enabled && (root.focus || root.length > 0) ? "#00b4ff" : "#666767"
            x: 16
            y: root.focus || root.length > 0 ? (1 - textMetrics.height / 2) : (22.5 - bigTextMetrics.height / 2)
            text: root.placeholderTxt
            Behavior on y {
                NumberAnimation { duration: 125 }
            }
            Behavior on font.pixelSize {
                NumberAnimation { duration: 125 }
            }
            Behavior on color {
                ColorAnimation { duration: 125 }
            }
        }

    }




}
