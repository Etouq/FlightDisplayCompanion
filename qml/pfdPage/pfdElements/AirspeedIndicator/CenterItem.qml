import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {


    Item {
        transform: Translate {
            y: (iasInterface.airspeed - iasInterface.center) * 9.6
        }

        Loader {
            active: !iasInterface.noColor
            sourceComponent: Item {
                Rectangle {
                    x: 168
                    y: iasInterface.redY
                    width: 24
                    height: iasInterface.redHeight
                    color: "red"
                }

                Rectangle {
                    x: 168
                    y: iasInterface.yellowY
                    width: 24
                    height: iasInterface.yellowHeight
                    color: "yellow"
                }

                Rectangle {
                    x: 168
                    y: iasInterface.greenY
                    width: 24
                    height: iasInterface.greenHeight
                    color: "green"
                }

                Rectangle {
                    x: 180
                    y: iasInterface.flapsY
                    width: 12
                    height: iasInterface.flapsHeight
                    color: "white"
                }
            }
        }

        GradGroup {
        }

        Loader {
            active: !iasInterface.noColor && iasInterface.minSpeed > 0
            sourceComponent: StartElement {
                transform: Translate {
                    y: iasInterface.minTransform
                }
            }
        }

        Loader {
            active: !iasInterface.noColor && iasInterface.maxSpeed > 0
            sourceComponent: EndElement {
                transform: Translate {
                    y: iasInterface.maxTransform
                }
            }
        }

    }

    Item {
        transform: Translate {
            y: iasInterface.airspeed * 9.6
        }

        Shape {
            visible: apInterface.has_ap
            transform: Translate {
                y: iasInterface.refSpeed * -9.6
            }
            ShapePath {
                fillColor: "#36c8d2"
                strokeColor: "transparent"

                PathMove { x: 192; y: 268.8 }
                PathLine { x: 172.8; y: 268.8 }
                PathLine { x: 172.8; y: 273.6 }
                PathLine { x: 182.4; y: 288 }
                PathLine { x: 172.8; y: 302.4 }
                PathLine { x: 172.8; y: 307.2 }
                PathLine { x: 192; y: 307.2 }
            }
        }

        Shape {
            visible: tscBackend.vrActive
            transform: Translate {
                y: tscBackend.vrSpeed * -9.6
            }
            ShapePath {
                fillColor: "#1a1d21"
                strokeColor: "transparent"

                PathMove { x: 192; y: 288 }
                PathLine { x: 201.6; y: 302.4 }
                PathLine { x: 240; y: 302.4 }
                PathLine { x: 240; y: 273.6 }
                PathLine { x: 201.6; y: 273.6 }
            }
            Text {
                anchors.horizontalCenter: parent.left
                anchors.horizontalCenterOffset: 220.8
                anchors.verticalCenter: parent.top
                anchors.verticalCenterOffset: 288
                color: "aqua"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 24
                text: "R"
            }
        }

        Shape {
            visible: tscBackend.vxActive
            transform: Translate {
                y: tscBackend.vxSpeed * -9.6
            }
            ShapePath {
                fillColor: "#1a1d21"
                strokeColor: "transparent"

                PathMove { x: 192; y: 288 }
                PathLine { x: 201.6; y: 302.4 }
                PathLine { x: 240; y: 302.4 }
                PathLine { x: 240; y: 273.6 }
                PathLine { x: 201.6; y: 273.6 }
            }
            Text {
                anchors.horizontalCenter: parent.left
                anchors.horizontalCenterOffset: 220.8
                anchors.verticalCenter: parent.top
                anchors.verticalCenterOffset: 288
                color: "aqua"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 24
                text: "X"
            }
        }

        Shape {
            visible: tscBackend.vyActive
            transform: Translate {
                y: tscBackend.vySpeed * -9.6
            }
            ShapePath {
                fillColor: "#1a1d21"
                strokeColor: "transparent"

                PathMove { x: 192; y: 288 }
                PathLine { x: 201.6; y: 302.4 }
                PathLine { x: 240; y: 302.4 }
                PathLine { x: 240; y: 273.6 }
                PathLine { x: 201.6; y: 273.6 }
            }
            Text {
                anchors.horizontalCenter: parent.left
                anchors.horizontalCenterOffset: 220.8
                anchors.verticalCenter: parent.top
                anchors.verticalCenterOffset: 288
                color: "aqua"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 24
                text: "Y"
            }
        }

        Shape {
            visible: tscBackend.vappActive
            transform: Translate {
                y: tscBackend.vappSpeed * -9.6
            }
            ShapePath {
                fillColor: "#1a1d21"
                strokeColor: "transparent"

                PathMove { x: 192; y: 288 }
                PathLine { x: 201.6; y: 302.4 }
                PathLine { x: 240; y: 302.4 }
                PathLine { x: 240; y: 273.6 }
                PathLine { x: 201.6; y: 273.6 }
            }
            Text {
                anchors.horizontalCenter: parent.left
                anchors.horizontalCenterOffset: 220.8
                anchors.verticalCenter: parent.top
                anchors.verticalCenterOffset: 288
                color: "aqua"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 24
                text: "AP"
            }
        }
    }





}
