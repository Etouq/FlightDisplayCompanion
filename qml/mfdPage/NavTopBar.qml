import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    width: parent.width
    height: 90
    Rectangle {
        id: bg
        x: 420
        y: 0
        width: 1365
        height: 48
        color: "#1A1D21"

        property bool flightPlanActive: navInterface.gpsIsActiveFlightPlan

        Row {
            spacing: 0

            Text {
                width: 62.758620689655174
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "white"
                text: "GS"
            }

            Text {
                width: 125.51724137931035
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: bottomInterface.groundSpeed + "KT"
            }

            Text {
                width: 62.758620689655174
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "white"
                text: "DTK"
            }

            Text {
                width: 125.51724137931035
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: bg.flightPlanActive ? mfdInterface.gps_dtk.toFixed(0) + "°" : "___°"
            }

            Text {
                width: 62.758620689655174
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "white"
                text: "TRK"
            }

            Text {
                width: 125.51724137931035
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: hsiInterface.currentTrackAngle.toFixed(0) +  "°"
            }

            Text {
                width: 62.758620689655174
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "white"
                text: "ETE"
            }

            Text {
                width: 125.51724137931035
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: bg.flightPlanActive ? mfdInterface.ete : "__:__"
            }

            Text {
                width: 62.758620689655174
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "white"
                text: "BRG"
            }

            Text {
                width: 125.51724137931035
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: bg.flightPlanActive ? hsiBrgInterface.gpsBearing.toFixed(0) + "°" : "___°"
            }

            Text {
                width: 62.758620689655174
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "white"
                text: "DIS"
            }

            Text {
                width: 125.51724137931035
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: hsiBrgInterface.gpsDistance === "" || !bg.flightPlanActive ? "__._NM" : hsiBrgInterface.gpsDistance
            }

            Text {
                width: 62.758620689655174
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "white"
                text: "ETA"
            }

            Text {
                width: 172.58620689655174
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: bg.flightPlanActive ? mfdInterface.eta : "__:__UTC"
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
            transform: Rotation { angle: windInterface.windTrueDirection + 180; origin.x: 33.75; origin.y: 45 }
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
