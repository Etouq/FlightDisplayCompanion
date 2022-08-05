import QtQuick 2.15


import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"

Rectangle {
    id: popupRoot

    anchors.fill: parent

    visible: false

    color: Qt.rgba(0, 0, 0, 0.8)

    property alias title: pageTitle.text
    property var options: []
    property var callback


    MouseArea {
        anchors.fill: parent
        onClicked: popupRoot.visible = false
    }

    Rectangle {
        width: 1728
        height: 120
        color: "black"

        Text {
            id: pageTitle
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 60
            color: "white"
        }
    }

    Rectangle {
        x: 599.2
        y: 180
        width: 529.6
        height: popupRoot.options.length * 210 + 19.6
        border.width: 4.8
        border.color: "white"
        color: "black"

        Column {
            anchors.fill: parent
            anchors.margins: 14.8
            spacing: 10

            Repeater {
                model: popupRoot.options

                delegate: GradientButton {
                    id: optionButton

                    required property int index
                    required property string modelData

                    width: 500
                    height: 200

                    Text {
                        anchors.fill: parent

                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter

                        font.pixelSize: 60
                        font.family: "Roboto Mono"
                        font.bold: true

                        color: "white"

                        text: optionButton.modelData

                        wrapMode: Text.WordWrap

                        lineHeight: 60
                        lineHeightMode: Text.FixedHeight
                    }

                    onReleased: function() {
                        popupRoot.callback(optionButton.index);
                        popupRoot.visible = false;
                    }
                }
            }
        }
    }


}
