import QtQuick 2.15

Rectangle {
    id: popupRoot
    visible: false
    anchors.fill: parent
    color: Qt.rgba(0, 0, 0, 0.8)

    signal colorPicked(color _newColor)


    TapHandler {
        onTapped: popupRoot.visible = false
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
            text: "Pick a Color"
        }
    }




    Rectangle {
        x: 629.2
        y: 190.2
        width: 529.6
        height: 699.6
        border.width: 4.8
        border.color: "white"
        color: "black"

        Grid {
            width: 500
            height: 670
            anchors.centerIn: parent
            columns: 6
            rows: 8
            columnSpacing: 10
            rowSpacing: 10

            flow: Grid.TopToBottom

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#000000"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#FF0000"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#FFCCCC"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#FF8080"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#FF3333"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#CC0000"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#800000"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#330000"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#333333"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#FFFF00"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#FFFFCC"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#FFFF80"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#FFFF33"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#CCCC00"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#808000"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#333300"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#666666"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#00FF00"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#CCFFCC"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#80FF80"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#33FF33"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#00CC00"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#008000"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#003300"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#999999"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#00FFFF"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#CCFFFF"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#80FFFF"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#33FFFF"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#00CCCC"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#008080"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#003333"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#CCCCCC"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#0000FF"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#CCCCFF"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#8080FF"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#3333FF"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#0000CC"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#000080"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#000033"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#FFFFFF"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#FF00FF"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#FFCCFF"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#FF80FF"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#FF33FF"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#CC00CC"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#800080"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }

            Rectangle {
                width: 75
                height: 75
                border.width: 1.5
                border.color: "#DCDCDC"
                color: "#330033"

                TapHandler {
                    onTapped: {
                        popupRoot.colorPicked(parent.color);
                        popupRoot.visible = false;
                    }
                }
            }
        }
    }


}
