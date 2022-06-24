import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.Bearings 1.0
import General.Settings 1.0
import TypeEnums 1.0

Shape {
    id: root

    states: [
        State {
            name: "nav1ModeBrg2"
            when: GenSettings.bearing2Mode === BearingMode.NAV1

            PropertyChanges {
                target: distanceText
                text: Bearings.nav1Distance
            }
            PropertyChanges {
                target: identText
                text: Bearings.nav1Ident
            }
            PropertyChanges {
                target: sourceText
                text: "NAV1"
            }
        },
        State {
            name: "nav2ModeBrg2"
            when: GenSettings.bearing2Mode === BearingMode.NAV2

            PropertyChanges {
                target: distanceText
                text: Bearings.nav2Distance
            }
            PropertyChanges {
                target: identText
                text: Bearings.nav2Ident
            }
            PropertyChanges {
                target: sourceText
                text: "NAV2"
            }
        },
        State {
            name: "gpsModeBrg2"
            when: GenSettings.bearing2Mode === BearingMode.GPS

            PropertyChanges {
                target: distanceText
                text: Bearings.gpsDistance
            }
            PropertyChanges {
                target: identText
                text: Bearings.gpsIdent
            }
            PropertyChanges {
                target: sourceText
                text: "GPS"
            }
        },
        State {
            name: "adfModeBrg2"
            when: GenSettings.bearing2Mode === BearingMode.ADF

            PropertyChanges {
                target: distanceText
                text: ""
            }
            PropertyChanges {
                target: identText
                text: Bearings.adfIdent
            }
            PropertyChanges {
                target: sourceText
                text: "ADF"
            }
        }
    ]

    ShapePath {
        fillColor: "#1A1D21"
        strokeColor: "transparent"
        PathMove { x: 554.041683913189; y: 430.602628357737 }
        PathLine { x: 691.2; y: 430.602628357737 }
        PathLine { x: 691.2; y: 513.0778465041312 }
        PathLine { x: 460.15744506649673; y: 513.0778465041312 }
        PathArc { radiusX: 252.55384615384617; radiusY: 252.55384615384617; direction: PathArc.Counterclockwise; x: 554.041683913189; y: 430.602628357737 }
    }

    Text {
        id: distanceText
        anchors.right: parent.left
        anchors.rightMargin: -686.7692307692308
        anchors.baseline: parent.top
        anchors.baselineOffset: 456.3692307692308
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 27
        font.bold: true
        text: "16.2 NM"
    }

    Text {
        id: identText
        anchors.right: parent.left
        anchors.rightMargin: -686.7692307692308
        anchors.baseline: parent.top
        anchors.baselineOffset: 482.9538461538462
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 27
        font.bold: true
        text: "ATL"
    }

    Text {
        id: sourceText
        anchors.right: parent.left
        anchors.rightMargin: -686.7692307692308
        anchors.baseline: parent.top
        anchors.baselineOffset: 509.53846153846155
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 27
        font.bold: true
        text: "NAV1"
    }

    // arrow
    ShapePath {
        fillColor: "transparent"
        strokeColor: "#36C8D2"
        strokeWidth: 2.2153846153846155

        PathMove { x: 522.8307692307693; y: 496.2461538461539 }
        PathLine { x: 531.6923076923077; relativeY: 0 }
        PathMove { x: 589.2923076923078; relativeY: 0 }
        PathLine { x: 580.4307692307692; relativeY: 0 }
        PathLine { x: 567.1384615384616; y: 509.53846153846155 }
        PathMove { x: 580.4307692307692; y: 496.2461538461539 }
        PathLine { x: 567.1384615384616; y: 482.9538461538462 }
        PathMove { x: 573.7846153846154; y: 502.8923076923077 }
        PathLine { x: 536.123076923077; relativeY: 0 }
        PathQuad { relativeX: 0; y: 489.6; controlX:  522.8307692307693; controlY:  496.2461538461539 }
        PathLine { x: 573.7846153846154; relativeY: 0 }
    }


}
