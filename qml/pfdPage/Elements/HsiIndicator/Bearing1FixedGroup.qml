import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.Bearings 1.0
import General.Settings 1.0
import TypeEnums 1.0

Shape {
    id: root


    ShapePath {
        fillColor: "#1A1D21"
        strokeColor: "transparent"

        // PathMove {
        //     x: 137.15831608681108
        //     y: 430.602628357737
        // }
        PathMove {
            x: 0
            y: 430.602628357737
        }
        PathLine {
            x: 0
            y: 513.0778465041312
        }
        PathLine {
            x: 231.04255493350342
            y: 513.0778465041312
        }
        PathArc {
            radiusX: 252.55384615384617
            radiusY: 252.55384615384617
            direction: PathArc.Clockwise
            x: 137.15831608681108
            y: 430.602628357737
        }
    }

    Text {
        id: distanceText
        anchors.left: parent.left
        anchors.leftMargin: 4.430769230769231
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
        anchors.left: parent.left
        anchors.leftMargin: 4.430769230769231
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
        anchors.left: parent.left
        anchors.leftMargin: 4.430769230769231
        anchors.baseline: parent.top
        anchors.baselineOffset: 509.53846153846155
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 27
        font.bold: true
        text: "NAV1"
    }

    // arrow
    Rectangle {
        x: 101.90769230769232
        y: 495.69230769230774
        width: 66.46153846153847
        height: 1.1076923076923078
        color: "#36C8D2"
    }

    Rectangle {
        x: 110.76923076923077
        y: 495.69230769230774
        width: 17.723076923076924
        height: 1.1076923076923078
        color: "#36C8D2"
        transform: Rotation {
            angle: -45
            origin.x: 0
            origin.y: 0.5538461538461539
        }
    }

    Rectangle {
        x: 110.76923076923077
        y: 495.69230769230774
        width: 17.723076923076924
        height: 1.1076923076923078
        color: "#36C8D2"
        transform: Rotation {
            angle: 45
            origin.x: 0
            origin.y: 0.5538461538461539
        }
    }

    states: [
        State {
            name: "nav1ModeBrg1"
            when: GenSettings.bearing1Mode === BearingMode.NAV1

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
            name: "nav2ModeBrg1"
            when: GenSettings.bearing1Mode === BearingMode.NAV2

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
            name: "gpsModeBrg1"
            when: GenSettings.bearing1Mode === BearingMode.GPS

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
            name: "adfModeBrg1"
            when: GenSettings.bearing1Mode === BearingMode.ADF

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
}
