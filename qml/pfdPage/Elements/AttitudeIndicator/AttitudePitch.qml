import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.Attitude 1.0

Shape {
    transform: [
        Translate { y: Attitude.pitchTransformValue },
        Rotation {
            angle: Attitude.bankAngle
            origin.x: 165.6
            origin.y: 187.2
        }
    ]

    Rectangle {
        color: "white"
        x: 79.2
        y: 2949.84
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 2952
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "80"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 2952
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "80"
    }

    ShapePath {
        fillColor: "red"
        strokeColor: "transparent"
        PathMove { x: 136.8000; y: 2604.2400 }
        PathLine { relativeX: 57.6000; relativeY: 0 }
        PathLine { x: 252.0000; y: 2949.8400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
        PathLine { x: 165.6000; y: 2635.2000 }
        PathLine { x: 136.8000; y: 2949.8400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: 2604.24
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 2606.4
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "70"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 2606.4
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "70"
    }

    ShapePath {
        fillColor: "red"
        strokeColor: "transparent"
        PathMove { x: 136.8000; y: 2258.6400 }
        PathLine { relativeX: 57.6000; relativeY: 0 }
        PathLine { x: 252.0000; y: 2604.2400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
        PathLine { x: 165.6000; y: 2289.6000 }
        PathLine { x: 136.8000; y: 2604.2400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: 2258.64
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 2260.8
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "60"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 2260.8
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "60"
    }

    ShapePath {
        fillColor: "red"
        strokeColor: "transparent"
        PathMove { x: 136.8000; y: 1913.0400 }
        PathLine { relativeX: 57.6000; relativeY: 0 }
        PathLine { x: 252.0000; y: 2258.6400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
        PathLine { x: 165.6000; y: 1944.0000 }
        PathLine { x: 136.8000; y: 2258.6400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: 1913.04
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 1915.2
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "50"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 1915.2
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "50"
    }

    ShapePath {
        fillColor: "red"
        strokeColor: "transparent"
        PathMove { x: 136.8000; y: 1567.4400 }
        PathLine { relativeX: 57.6000; relativeY: 0 }
        PathLine { x: 252.0000; y: 1913.0400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
        PathLine { x: 165.6000; y: 1598.4000 }
        PathLine { x: 136.8000; y: 1913.0400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: 1567.44
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 1569.6
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "40"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 1569.6
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "40"
    }

    ShapePath {
        fillColor: "red"
        strokeColor: "transparent"
        PathMove { x: 136.8000; y: 1221.8400 }
        PathLine { relativeX: 57.6000; relativeY: 0 }
        PathLine { x: 252.0000; y: 1567.4400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
        PathLine { x: 165.6000; y: 1252.8000 }
        PathLine { x: 136.8000; y: 1567.4400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: 1221.84
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 1224
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "30"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 1224
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "30"
    }

    Rectangle {
        color: "white"
        x: 122.4
        y: 1049.04
        width: 86.4
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -115.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 1051.2
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "25"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 216
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 1051.2
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "25"
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: 876.24
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 878.4
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "20"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 878.4
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "20"
    }

    Rectangle {
        color: "white"
        x: 136.8
        y: 790.56
        width: 57.6
        height: 2.88
    }

    Rectangle {
        color: "white"
        x: 122.4
        y: 703.44
        width: 86.4
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -115.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 705.6
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "15"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 216
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 705.6
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "15"
    }

    Rectangle {
        color: "white"
        x: 136.8
        y: 617.76
        width: 57.6
        height: 2.88
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: 530.64
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 532.8
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "10"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 532.8
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "10"
    }

    Rectangle {
        color: "white"
        x: 136.8
        y: 444.96
        width: 57.6
        height: 2.88
    }

    Rectangle {
        color: "white"
        x: 122.4
        y: 357.84
        width: 86.4
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -115.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 360
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "5"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 216
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 360
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "5"
    }

    Rectangle {
        color: "white"
        x: 136.8
        y: 272.16
        width: 57.6
        height: 2.88
    }

    Rectangle {
        color: "white"
        x: 136.8
        y: 99.36
        width: 57.6
        height: 2.88
    }

    Rectangle {
        color: "white"
        x: 122.4
        y: 12.24
        width: 86.4
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -115.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 14.4
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "5"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 216
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 14.4
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "5"
    }

    Rectangle {
        color: "white"
        x: 136.8
        y: -73.44
        width: 57.6
        height: 2.88
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: -160.56
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -158.4
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "10"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -158.4
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "10"
    }

    Rectangle {
        color: "white"
        x: 136.8
        y: -246.24
        width: 57.6
        height: 2.88
    }

    Rectangle {
        color: "white"
        x: 122.4
        y: -333.36
        width: 86.4
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -115.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -331.2
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "15"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 216
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -331.2
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "15"
    }

    Rectangle {
        color: "white"
        x: 136.8
        y: -419.04
        width: 57.6
        height: 2.88
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: -506.16
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -504
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "20"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -504
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "20"
    }

    Rectangle {
        color: "white"
        x: 122.4
        y: -678.96
        width: 86.4
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -115.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -676.8
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "25"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 216
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -676.8
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "25"
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: -851.76
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -849.6
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "30"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -849.6
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "30"
    }

    Rectangle {
        color: "white"
        x: 122.4
        y: -1024.56
        width: 86.4
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -115.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -1022.4
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "35"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 216
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -1022.4
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "35"
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: -1197.36
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -1195.2
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "40"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -1195.2
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "40"
    }

    Rectangle {
        color: "white"
        x: 122.4
        y: -1370.16
        width: 86.4
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -115.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -1368
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "45"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 216
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -1368
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "45"
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: -1542.96
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -1540.8
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "50"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -1540.8
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "50"
    }

    ShapePath {
        fillColor: "red"
        strokeColor: "transparent"
        PathMove { x: 136.8000; y: -1542.9600 }
        PathLine { relativeX: 57.6000; relativeY: 0 }
        PathLine { x: 252.0000; y: -1884.2400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
        PathLine { x: 165.6000; y: -1569.6000 }
        PathLine { x: 136.8000; y: -1884.2400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: -1888.56
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -1886.4
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "60"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -1886.4
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "60"
    }

    ShapePath {
        fillColor: "red"
        strokeColor: "transparent"
        PathMove { x: 136.8000; y: -1888.5600 }
        PathLine { relativeX: 57.6000; relativeY: 0 }
        PathLine { x: 252.0000; y: -2229.8400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
        PathLine { x: 165.6000; y: -1915.2000 }
        PathLine { x: 136.8000; y: -2229.8400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: -2234.16
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -2232
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "70"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -2232
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "70"
    }

    ShapePath {
        fillColor: "red"
        strokeColor: "transparent"
        PathMove { x: 136.8000; y: -2234.1600 }
        PathLine { relativeX: 57.6000; relativeY: 0 }
        PathLine { x: 252.0000; y: -2575.4400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
        PathLine { x: 165.6000; y: -2260.8000 }
        PathLine { x: 136.8000; y: -2575.4400 }
        PathLine { relativeX: -57.6000; relativeY: 0 }
    }

    Rectangle {
        color: "white"
        x: 79.2
        y: -2579.76
        width: 172.8
        height: 4.32
    }

    Text {
        anchors.right: parent.left
        anchors.rightMargin: -72
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -2577.6
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "80"
    }

    Text {anchors.left: parent.left
        anchors.leftMargin: 259.2
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: -2577.6
        font.pixelSize: 29
        font.bold: true
        font.family: "Roboto Mono"
        color: "white"
        text: "80"
    }

}
