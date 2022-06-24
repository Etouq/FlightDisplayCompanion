import QtQuick 2.15
import "../styled_controls"
import "../styled_controls/gradientButtonElements"
import QtQuick.Shapes 1.15
import QtQuick.Layouts 1.15
import Mfd.GeoMap 1.0
import TypeEnums 1.0

Rectangle {
    id: popupRoot
    visible: false
    anchors.fill: parent
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
        height: 1067.6
        border.width: 4.8
        border.color: "white"
        color: "black"

        GridLayout {
            anchors.centerIn: parent
            width: 776
            columns: 3
            rowSpacing: 10
            columnSpacing: 10

            Repeater {
                model: GeoMap.iconCount()

                delegate: GradientButton {
                    width: 252
                    height: 252

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    required property int index

                    Shape {
                        x: 25.2
                        y: 25.2
                        width: 201.6
                        height: 201.6

                        ShapePath {
                            fillColor: "white"
                            strokeColor: "black"
                            strokeWidth: 2.88

                            scale: Qt.size(1.92, 1.92)
                            PathSvg { path: GeoMap.iconAt(index); }
                        }
                    }

                    onReleased: { GeoMap.selectIcon(index); popupRoot.visible = false; }
                }
            }

        }

        // Column {
        //     anchors.centerIn: parent
        //     width: 776
        //     height: 1038
        //     spacing: 10

        //     Row {
        //         width: 776
        //         height: 252
        //         spacing: 10

        //         GradientButton {
        //             width: 252
        //             height: 252

        //             Shape {
        //                 x: 25.2
        //                 y: 25.2
        //                 width: 201.6
        //                 height: 201.6

        //                 ShapePath {
        //                     fillColor: "white"
        //                     strokeColor: "black"
        //                     strokeWidth: 2.88

        //                     scale: Qt.size(1.92, 1.92)
        //                     PathSvg { path: mfdInterface.getIconPathAt(0); }
        //                 }
        //             }

        //             onReleased: { mfdInterface.selectIcon(0); popupRoot.visible = false; }
        //         }

        //         GradientButton {
        //             width: 252
        //             height: 252

        //             Shape {
        //                 x: 25.2
        //                 y: 25.2
        //                 width: 201.6
        //                 height: 201.6

        //                 ShapePath {
        //                     fillColor: "white"
        //                     strokeColor: "black"
        //                     strokeWidth: 2.88

        //                     scale: Qt.size(1.92, 1.92)
        //                     PathSvg { path: mfdInterface.getIconPathAt(1); }
        //                 }
        //             }

        //             onReleased: { mfdInterface.selectIcon(1); popupRoot.visible = false; }
        //         }

        //         GradientButton {
        //             width: 252
        //             height: 252

        //             Shape {
        //                 x: 25.2
        //                 y: 25.2
        //                 width: 201.6
        //                 height: 201.6

        //                 ShapePath {
        //                     fillColor: "white"
        //                     strokeColor: "black"
        //                     strokeWidth: 2.88

        //                     scale: Qt.size(1.92, 1.92)
        //                     PathSvg { path: mfdInterface.getIconPathAt(2); }
        //                 }
        //             }

        //             onReleased: { mfdInterface.selectIcon(2); popupRoot.visible = false; }
        //         }
        //     }

        //     Row {
        //         width: 776
        //         height: 252
        //         spacing: 10

        //         GradientButton {
        //             width: 252
        //             height: 252

        //             Shape {
        //                 x: 25.2
        //                 y: 25.2
        //                 width: 201.6
        //                 height: 201.6

        //                 ShapePath {
        //                     fillColor: "white"
        //                     strokeColor: "black"
        //                     strokeWidth: 2.88

        //                     scale: Qt.size(1.92, 1.92)
        //                     PathSvg { path: mfdInterface.getIconPathAt(3); }
        //                 }
        //             }

        //             onReleased: { mfdInterface.selectIcon(3); popupRoot.visible = false; }
        //         }

        //         GradientButton {
        //             width: 252
        //             height: 252

        //             Shape {
        //                 x: 25.2
        //                 y: 25.2
        //                 width: 201.6
        //                 height: 201.6

        //                 ShapePath {
        //                     fillColor: "white"
        //                     strokeColor: "black"
        //                     strokeWidth: 2.88

        //                     scale: Qt.size(1.92, 1.92)
        //                     PathSvg { path: mfdInterface.getIconPathAt(4); }
        //                 }
        //             }

        //             onReleased: { mfdInterface.selectIcon(4); popupRoot.visible = false; }
        //         }

        //         GradientButton {
        //             width: 252
        //             height: 252

        //             Shape {
        //                 x: 25.2
        //                 y: 25.2
        //                 width: 201.6
        //                 height: 201.6

        //                 ShapePath {
        //                     fillColor: "white"
        //                     strokeColor: "black"
        //                     strokeWidth: 2.88

        //                     scale: Qt.size(1.92, 1.92)
        //                     PathSvg { path: mfdInterface.getIconPathAt(5); }
        //                 }
        //             }

        //             onReleased: { mfdInterface.selectIcon(5); popupRoot.visible = false; }
        //         }
        //     }

        //     Row {
        //         width: 776
        //         height: 252
        //         spacing: 10

        //         GradientButton {
        //             width: 252
        //             height: 252

        //             Shape {
        //                 x: 25.2
        //                 y: 25.2
        //                 width: 201.6
        //                 height: 201.6

        //                 ShapePath {
        //                     fillColor: "white"
        //                     strokeColor: "black"
        //                     strokeWidth: 2.88

        //                     scale: Qt.size(1.92, 1.92)
        //                     PathSvg { path: mfdInterface.getIconPathAt(6); }
        //                 }
        //             }

        //             onReleased: { mfdInterface.selectIcon(6); popupRoot.visible = false; }
        //         }

        //         GradientButton {
        //             width: 252
        //             height: 252

        //             Shape {
        //                 x: 25.2
        //                 y: 25.2
        //                 width: 201.6
        //                 height: 201.6

        //                 ShapePath {
        //                     fillColor: "white"
        //                     strokeColor: "black"
        //                     strokeWidth: 2.88

        //                     scale: Qt.size(1.92, 1.92)
        //                     PathSvg { path: mfdInterface.getIconPathAt(7); }
        //                 }
        //             }

        //             onReleased: { mfdInterface.selectIcon(7); popupRoot.visible = false; }
        //         }

        //         GradientButton {
        //             width: 252
        //             height: 252

        //             Shape {
        //                 x: 25.2
        //                 y: 25.2
        //                 width: 201.6
        //                 height: 201.6

        //                 ShapePath {
        //                     fillColor: "white"
        //                     strokeColor: "black"
        //                     strokeWidth: 2.88

        //                     scale: Qt.size(1.92, 1.92)
        //                     PathSvg { path: mfdInterface.getIconPathAt(8); }
        //                 }
        //             }

        //             onReleased: { mfdInterface.selectIcon(8); popupRoot.visible = false; }
        //         }
        //     }

        //     GradientButton {
        //         anchors.horizontalCenter: parent.horizontalCenter
        //         width: 252
        //         height: 252

        //         Shape {
        //             x: 25.2
        //             y: 25.2
        //             width: 201.6
        //             height: 201.6

        //             ShapePath {
        //                 fillColor: "white"
        //                 strokeColor: "black"
        //                 strokeWidth: 2.88

        //                 scale: Qt.size(1.92, 1.92)
        //                 PathSvg { path: mfdInterface.getIconPathAt(9); }
        //             }
        //         }

        //         onReleased: { mfdInterface.selectIcon(9); popupRoot.visible = false; }
        //     }

        // }
    }

}
