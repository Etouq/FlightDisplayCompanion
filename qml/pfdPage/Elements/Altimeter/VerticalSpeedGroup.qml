import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.Altimeter 1.0
import Pfd.Autopilot 1.0

Item {

    Canvas {
        x: 240
        y: 96
        width: 72
        height: 480

        onPaint: {
            var ctx = getContext("2d");
            ctx.fillStyle = "#1a1d21";
            ctx.globalAlpha = 0.25;
            ctx.beginPath();
            ctx.moveTo(0, 0);
            ctx.lineTo(0, 480);
            ctx.lineTo(72, 480);
            ctx.lineTo(72, 288);
            ctx.lineTo(9.6, 240);
            ctx.lineTo(72, 192);
            ctx.lineTo(72, 0);
            ctx.fill();
        }
    }

    Rectangle {
        x: 240
        y: 526.56
        width: 19.2
        height: 2.88
        color: "white"
    }
    Text {
        x: 268.8
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 528
        color: "white"
        font.bold: true
        font.family: "Roboto Mono"
        font.pixelSize: 29
        text: "-2"
    }
    Rectangle {
        x: 240
        y: 478.56
        width: 9.6
        height: 2.88
        color: "white"
    }
    Rectangle {
        x: 240
        y: 430.56
        width: 19.2
        height: 2.88
        color: "white"
    }
    Text {
        x: 268.8
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 432
        color: "white"
        font.bold: true
        font.family: "Roboto Mono"
        font.pixelSize: 29
        text: "-1"
    }
    Rectangle {
        x: 240
        y: 382.56
        width: 9.6
        height: 2.88
        color: "white"
    }
    Rectangle {
        x: 240
        y: 286.56
        width: 9.6
        height: 2.88
        color: "white"
    }
    Rectangle {
        x: 240
        y: 238.56
        width: 19.2
        height: 2.88
        color: "white"
    }
    Text {
        x: 268.8
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 240
        color: "white"
        font.bold: true
        font.family: "Roboto Mono"
        font.pixelSize: 29
        text: "1"
    }
    Rectangle {
        x: 240
        y: 190.56
        width: 9.6
        height: 2.88
        color: "white"
    }
    Rectangle {
        x: 240
        y: 142.56
        width: 19.2
        height: 2.88
        color: "white"
    }
    Text {
        x: 268.8
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 144
        color: "white"
        font.bold: true
        font.family: "Roboto Mono"
        font.pixelSize: 29
        text: "2"
    }

    Loader {
        active: ApInfo.hasAp
        asynchronous: true

        sourceComponent: Shape {
            y: Math.max(Math.min(Altimeter.referenceVspeed * -0.096, 216), -216)

            ShapePath {
                fillColor: "#36c8d2"
                strokeColor: "transparent"

                PathMove { x: 240; y: 316.8 }
                PathLine { x: 259.2; y: 316.8 }
                PathLine { x: 259.2; y: 321.6 }
                PathLine { x: 249.6; y: 336 }
                PathLine { x: 259.2; y: 350.4 }
                PathLine { x: 259.2; y: 355.2 }
                PathLine { x: 240; y: 355.2 }
            }
        }
    }

    Shape {
        y: Altimeter.vspeedIndicatorTransformValue

        ShapePath {
            fillColor: "#1a1d21"
            strokeColor: "transparent"

            PathMove { x: 249.6; y: 336 }
            PathLine { x: 273.6; y: 360 }
            PathLine { x: 364.8; y: 360 }
            PathLine { x: 364.8; y: 312 }
            PathLine { x: 273.6; y: 312 }
        }

        Text {
            x: 273.6
            anchors.baseline: parent.top
            anchors.baselineOffset: 345.6
            color: "white"
            font.bold: true
            font.family: "Roboto Mono"
            font.pixelSize: 29
            text: Altimeter.vspeedTextValue
        }
    }

    Loader {
        active: ApInfo.hasAp
        asynchronous: true

        sourceComponent: Rectangle {
            x: 240
            y: 48
            width: 72
            height: 48
            color: "#1a1d21"

            Text {
                anchors.horizontalCenter: parent.left
                anchors.horizontalCenterOffset: 36
                anchors.baseline: parent.top
                anchors.baselineOffset: 33.6
                color: "#36c8d2"
                font.bold: true
                font.family: "Roboto Mono"
                font.pixelSize: 24
                text: Altimeter.referenceVspeed
            }
        }
    }





}
