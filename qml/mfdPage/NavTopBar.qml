import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    width: parent.width
    height: 90
    Rectangle {
        x: 420
        y: 0
        width: 1365
        height: 48
        color: "#1A1D21"

        RowLayout {
            width: 1365
            height: 48

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "white"
                text: "GS"
            }

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "#d12bc7"
                text: bottomInterface.groundSpeed + "KT"
            }

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "white"
                text: "DTK"
            }

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "#d12bc7"
                text: mfdInterface.gps_dtk.toFixed(0) + "°"
            }

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "white"
                text: "TRK"
            }

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "#d12bc7"
                text: hsiInterface.currentTrackAngle.toFixed(0) +  "°"
            }

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "white"
                text: "ETE"
            }

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "#d12bc7"
                text: mfdInterface.ete;
            }

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "white"
                text: "BRG"
            }

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "#d12bc7"
                text: hsiBrgInterface.gpsBearing.toFixed(0) + "°"
            }

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "white"
                text: "DIS"
            }

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "#d12bc7"
                text: hsiBrgInterface.gpsDistance === "" ? "__._NM" : hsiBrgInterface.gpsDistance
            }

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "white"
                text: "ETA"
            }

            Text {
                Layout.fillHeight: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 30
                font.bold: true
                font.family: "Roboto Mono"
                color: "#d12bc7"
                text: mfdInterface.eta;
            }
        }
    }

    Rectangle {
        anchors.right: parent.right
        anchors.top: parent.top
        width: 135
        height: 90
        color: "#1A1D21"

        Shape {
            transform: Rotation { angle: (windInterface.windTrueDirection + 180) % 360; origin.x: 33.75; origin.y: 45 }
            ShapePath {
                fillColor: "white"
                strokeColor: "transparent"
                PathMove { x: 33.75; y: 15 }
                PathLine { x: 22.5; y: 30 }
                PathLine { x: 31.5; y: 30 }
                PathLine { x: 31.5; y: 75 }
                PathLine { x: 36; y: 75 }
                PathLine { x: 36; y: 30 }
                PathLine { x: 45; y: 30 }
            }
        }

        Text {
            x: 75
            anchors.baseline: parent.top
            anchors.baselineOffset: 60
            color: "white"
            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 45
            text: Math.round(windInterface.windStrength)
        }
    }
}
