import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15
import QtQuick.Window 2.15

ComboBox {
    id: root
    width: 250
    height: 45
    leftPadding: 16
    bottomPadding: 9
    topPadding: 9
    rightPadding: 9

    property bool overrideEnterHandler: false
    property string title: ""

    delegate: ItemDelegate {
        width: parent.width
        height: 45
        topPadding: 9
        bottomPadding: 9
        leftPadding: 16
        rightPadding: 9
        background: Rectangle {
            anchors.fill: parent
            color: "black"
            opacity: 0.18
            visible: parent.highlighted
        }
        contentItem: Text {
            text: modelData
            color: "black"
            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 20
            verticalAlignment: Text.AlignVCenter
        }
        highlighted: root.currentIndex === index
    }

    indicator: Shape {
        ShapePath {
            fillColor: root.focus ? "#00b4ff" : "#666767"
            strokeColor: "transparent"

            PathMove {
                x: 220
                y: root.popup.opened || root.popup.enter.running ? 25 : 18
                Behavior on y {
                    NumberAnimation { duration: 150 }
                }
            }
            PathLine {
                relativeX: 9
                y: root.popup.opened || root.popup.enter.running ? 16 : 27
                Behavior on y {
                    NumberAnimation { duration: 150 }
                }
            }
            PathLine {
                relativeX: 9
                y: root.popup.opened || root.popup.enter.running ? 25 : 18
                Behavior on y {
                    NumberAnimation { duration: 150 }
                }
            }
        }
    }

    contentItem: Text {
        text: parent.displayText
        color: "black"
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: 20
        verticalAlignment: Text.AlignVCenter
    }

    background: Rectangle {
        color: "transparent"
        border.width: 2
        border.color: root.focus ? "#00b4ff" : "#666767"
        radius: 4

        Rectangle {
            id: placeholderBg
            anchors.horizontalCenter: parent.left
            anchors.horizontalCenterOffset: 16 + textLabel.width / 2
            width: textLabel.width + 12
            height: 4
            y: -1
            color: "#c4c5c6"
        }

        Text {
            id: textLabel
            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 15
            color: root.enabled ? "#00b4ff" : "#666767"
            x: 16
            y: 1 - textLabel.height / 2
            text: root.title
            Behavior on color {
                ColorAnimation { duration: 125 }
            }
        }
    }

    popup: Popup {
        y: root.height
        width: root.width
        height: Math.min(contentItem.implicitHeight, bgRect.height - root.y - root.height)
        padding: 0

        enter: Transition {
            // grow_fade_in
            NumberAnimation { property: "scale"; from: 0.9; to: 1.0; easing.type: Easing.OutQuint; duration: 220 }
            NumberAnimation { property: "opacity"; from: 0.0; to: 1.0; easing.type: Easing.OutCubic; duration: 150 }
        }

        exit: Transition {
            // shrink_fade_out
            NumberAnimation { property: "scale"; from: 1.0; to: 0.9; easing.type: Easing.OutQuint; duration: 220 }
            NumberAnimation { property: "opacity"; from: 1.0; to: 0.0; easing.type: Easing.OutCubic; duration: 150 }
        }

        background: Rectangle {
            color: "white"
            radius: 4
        }

        contentItem: ListView {
            clip: true
            implicitHeight: contentHeight
            model: root.delegateModel

            ScrollIndicator.vertical: ScrollIndicator{}

        }
    }


    Keys.onUpPressed: {
        if (root.count > 1) {
            if (root.currentIndex > 0)
                root.currentIndex--;
            else
                root.currentIndex = root.count - 1;
        }
    }

    Keys.onDownPressed: {
        if (root.count > 1) {
            if (root.currentIndex < root.count - 1)
                root.currentIndex++;
            else
                root.currentIndex = 0;
        }
    }


    Keys.onEnterPressed: {
        if (!overrideEnterHandler)
            KeyNavigation.tab.forceActiveFocus()
    }

    Keys.onReturnPressed: {
        if (!overrideEnterHandler)
            KeyNavigation.tab.forceActiveFocus()
    }

    onActivated: {
        if (!overrideEnterHandler)
            KeyNavigation.tab.forceActiveFocus()
    }


}
