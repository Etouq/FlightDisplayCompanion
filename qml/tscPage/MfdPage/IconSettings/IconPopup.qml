import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import Mfd.GeoMapPage 1.0
import TypeEnums 1.0

import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"

Rectangle {
    id: popupRoot

    anchors.fill: parent

    visible: false

    color: Qt.rgba(0, 0, 0, 0.8)


    MouseArea {
        anchors.fill: parent
        onClicked: popupRoot.visible = false
    }

    Rectangle {
        width: 1728
        height: 120
        color: "black"

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 60
            color: "white"
            text: "Pick Icon"
        }
    }

    Rectangle {
        x: 461.2
        y: 126.2
        width: 805.6
        height: Math.min(Math.ceil(GeoMapPage.iconCount() / 3), 4) * 262 + 19.6

        border.width: 4.8
        border.color: "white"

        color: "black"

        GridView {
            id: iconView
            anchors.fill: parent
            anchors.margins: 9.8

            clip: true

            snapMode: GridView.SnapToRow

            cellWidth: 262
            cellHeight: 262

            ScrollBar.vertical: ScrollBar {
                parent: iconView.parent

                anchors {
                    top: iconView.top
                    left: iconView.right
                    bottom: iconView.bottom

                    topMargin: -9.8
                    leftMargin: 14.8
                    bottomMargin: -9.8
                }

                contentItem: Rectangle {
                    implicitWidth: 20
                    color: "white"
                }
            }

            model: GeoMapPage.iconCount()

            delegate: Item {
                width: 262
                height: 262

                required property int index

                GradientButton {
                    width: 252
                    height: 252

                    anchors.centerIn: parent


                    Shape {
                        x: 25.2
                        y: 25.2
                        width: 201.6
                        height: 201.6

                        ShapePath {
                            fillColor: "white"
                            strokeColor: "black"
                            strokeWidth: 1

                            scale: Qt.size(1.92, 1.92)
                            PathSvg {
                                path: GeoMapPage.iconAt(index);
                            }
                        }
                    }

                    onReleased: {
                        GeoMapPage.selectIcon(index); popupRoot.visible = false;
                    }
                }
            }
        }

    }

}
