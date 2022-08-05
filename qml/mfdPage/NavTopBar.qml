import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Pfd.NavInfo 1.0
import Pfd.Bottombar 1.0
import Pfd.WindInfo 1.0
import Mfd.Flightplan 1.0
import Pfd.HSIndicator 1.0
import Pfd.Bearings 1.0

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

        Row {
            spacing: 4.5
            anchors.fill: parent

            Text {
                width: 46.5
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
                width: 125
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: Bottombar.groundSpeed + "KT"
            }

            Text {
                width: 60
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
                width: 100
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: NavInfo.gpsIsActiveFlightPlan ? Flightplan.wpDtk.toFixed(0) + "°": "___°"
            }

            Text {
                width: 60
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
                width: 100
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: HSIndicator.currentTrackAngle.toFixed(0) + "°"
            }

            Text {
                width: 60
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
                width: 125
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: NavInfo.gpsIsActiveFlightPlan ? Flightplan.wpEte: "--:--"
            }

            Text {
                width: 60
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
                width: 100
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: NavInfo.gpsIsActiveFlightPlan ? Bearings.gpsBearing.toFixed(0) + "°": "___°"
            }

            Text {
                width: 60
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
                width: 175
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: Bearings.gpsDistance === "" || !NavInfo.gpsIsActiveFlightPlan ? "__._NM": Bearings.gpsDistance
            }

            Text {
                width: 60
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
                width: 175
                lineHeightMode: Text.FixedHeight
                lineHeight: 48
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 32
                font.family: "Roboto Mono"
                font.bold: true
                color: "#D12BC7"
                text: NavInfo.gpsIsActiveFlightPlan ? Flightplan.destEta: "--:--UTC"
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
            transform: Rotation {
                angle: WindInfo.windTrueDirection + 180; origin.x: 33.75; origin.y: 45
            }
            ShapePath {
                fillColor: "white"
                strokeColor: "transparent"
                PathMove {
                    x: 33.75; y: 15
                }
                PathLine {
                    x: 22.5; y: 30
                }
                PathLine {
                    x: 31.5; y: 30
                }
                PathLine {
                    x: 31.5; y: 75
                }
                PathLine {
                    x: 36; y: 75
                }
                PathLine {
                    x: 36; y: 30
                }
                PathLine {
                    x: 45; y: 30
                }
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
            text: Math.round(WindInfo.windStrength)
        }
    }
}
