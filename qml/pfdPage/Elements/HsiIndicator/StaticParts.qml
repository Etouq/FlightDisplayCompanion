import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.HSIndicator 1.0
import TypeEnums 1.0

Item {

    Shape {
        ShapePath { // top triangle
            fillColor: "white"
            strokeColor: "black"
            fillRule: ShapePath.WindingFill
            strokeWidth: 4.430769230769231
            joinStyle: ShapePath.MiterJoin

            PathMove { x: 327.8769230769231; y: 53.16923076923077 }
            PathLine { x: 363.32307692307694; y: 53.16923076923077 }
            PathLine { x: 345.6; y: 79.75384615384615 }
            PathLine { x: 327.8769230769231; y: 53.16923076923077 }
        }

        ShapePath { // plane icon
            fillColor: "white"
            strokeColor: "transparent"

            PathMove { x: 319.0153846153846; y: 288 }
            PathLine { x: 341.1692307692308; y: 288 }
            PathLine { x: 341.1692307692308; y: 301.2923076923077 }
            PathLine { x: 336.73846153846154; y: 305.7230769230769 }
            PathLine { x: 336.73846153846154; y: 310.1538461538462 }
            PathLine { x: 354.46153846153845; y: 310.1538461538462 }
            PathLine { x: 354.46153846153845; y: 305.7230769230769 }
            PathLine { x: 350.03076923076924; y: 301.2923076923077 }
            PathLine { x: 350.03076923076924; y: 288 }
            PathLine { x: 372.1846153846154; y: 288 }
            PathLine { x: 372.1846153846154; y: 283.5692307692308 }
            PathLine { x: 350.03076923076924; y: 279.13846153846157 }
            PathLine { x: 350.03076923076924; y: 270.2769230769231 }
            PathQuad { x: 341.1692307692308; y: 270.2769230769231; controlX: 345.6; controlY: 261.41538461538465 }
            PathLine { x: 341.1692307692308; y: 279.13846153846157 }
            PathLine { x: 319.0153846153846; y: 283.5692307692308 }
        }
    }


    // bearing
    Rectangle {
        x: 279.13846153846157
        y: 0
        width: 132.92307692307693
        height: 53.16923076923077
        color: "#1A1D21"
    }

    Text {
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 345.6
        anchors.baseline: parent.top
        anchors.baselineOffset: 44.30769230769231
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 49
        font.bold: true
        text: HSIndicator.rotationText
    }


    // heading
    Rectangle {
        x: 66.46153846153847
        y: 35.44615384615385
        width: 159.5076923076923
        height: 35.44615384615385
        color: "#1A1D21"
    }

    Text {
        anchors.left: parent.left
        anchors.leftMargin: 75.32307692307693
        anchors.baseline: parent.top
        anchors.baselineOffset: 63.80307692307693
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 31
        font.bold: true
        text: "HDG"
    }

    Text {
        anchors.left: parent.left
        anchors.leftMargin: 146.21538461538464
        anchors.baseline: parent.top
        anchors.baselineOffset: 63.80307692307693
        color: "#36C8D2"
        font.family: "Roboto Mono"
        font.pixelSize: 31
        font.bold: true
        text: HSIndicator.headingText
    }


    // course
    Rectangle {
        x: 465.2307692307693
        y: 35.44615384615385
        width: 159.5076923076923
        height: 35.44615384615385
        color: "#1A1D21"
    }

    Text {
        anchors.left: parent.left
        anchors.leftMargin: 474.0923076923077
        anchors.baseline: parent.top
        anchors.baselineOffset: 63.80307692307693
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 31
        font.bold: true
        text: "CRS"
    }

    Text {
        anchors.left: parent.left
        anchors.leftMargin: 544.9846153846154
        anchors.baseline: parent.top
        anchors.baselineOffset: 63.80307692307693
        color: "#D12BC7"
        font.family: "Roboto Mono"
        font.pixelSize: 31
        font.bold: true
        text: HSIndicator.courseText
    }


    // nav source
    Rectangle {
        x: 243.6923076923077
        y: 219.32307692307694
        width: 70.8923076923077
        height: 31.01538461538462
        color: "#1A1D21"
    }

    Text {
        id: navSourceText
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 279.13846153846157
        anchors.baseline: parent.top
        anchors.baselineOffset: 243.6923076923077
        color: "#D12BC7"
        font.family: "Roboto Mono"
        font.pixelSize: 27
        font.bold: true
        text: "GPS"

        states: [
            State {
                name: ""

                PropertyChanges {
                    target: navSourceText
                    text: ""
                    color: "#10C210"
                }
            },
            State {
                name: "gpsSource"
                when: HSIndicator.navSource === HsiNavSource.GPS

                PropertyChanges {
                    target: navSourceText
                    text: "GPS"
                    color: "#D12BC7"
                }
            },
            State {
                name: "vor1Source"
                when: HSIndicator.navSource === HsiNavSource.VOR1
                extend: ""

                PropertyChanges {
                    target: navSourceText
                    text: "VOR1"
                }
            },
            State {
                name: "loc1Source"
                when: HSIndicator.navSource === HsiNavSource.LOC1
                extend: ""

                PropertyChanges {
                    target: navSourceText
                    text: "LOC1"
                }
            },
            State {
                name: "tcn1Source"
                when: HSIndicator.navSource === HsiNavSource.TCN1
                extend: ""

                PropertyChanges {
                    target: navSourceText
                    text: "TCN1"
                }
            },
            State {
                name: "vor2Source"
                when: HSIndicator.navSource === HsiNavSource.VOR2
                extend: ""
                PropertyChanges {
                    target: navSourceText
                    text: "VOR2"
                }
            },
            State {
                name: "loc2Source"
                when: HSIndicator.navSource === HsiNavSource.LOC2
                extend: ""
                PropertyChanges {
                    target: navSourceText
                    text: "LOC2"
                }
            },
            State {
                name: "tcn2Source"
                when: HSIndicator.navSource === HsiNavSource.TCN2
                extend: ""
                PropertyChanges {
                    target: navSourceText
                    text: "TCN2"
                }
            }
        ]

    }


    // cross track error
    Rectangle {
        visible: HSIndicator.navSource === HsiNavSource.GPS && HSIndicator.crossTrackError >= 2
        x: 252.55384615384617
        y: 334.5230769230769
        width: 177.23076923076923
        height: 31.01538461538462
        color: "#1A1D21"
    }

    Text {
        visible: HSIndicator.navSource === HsiNavSource.GPS && HSIndicator.crossTrackError >= 2
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 345.6
        anchors.baseline: parent.top
        anchors.baselineOffset: 358.8923076923077
        color: "#D12BC7"
        font.family: "Roboto Mono"
        font.pixelSize: 27
        font.bold: true
        text: "XTK " + HSIndicator.crossTrackError.toFixed(2) + "NM"
    }

}
