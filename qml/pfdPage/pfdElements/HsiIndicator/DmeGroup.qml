import QtQuick 2.15
import QtQuick.Shapes 1.15

Shape {
    id: root

    visible: dmeMode != 0

    property int dmeMode: 0

    states: [
        State {
            name: "nav1ModeDme"
            when: root.dmeMode == 1

            PropertyChanges {
                target: sourceText
                text: "NAV1"
            }
            PropertyChanges {
                target: identText
                text: hsiBrgInterface.nav1Freq
            }
            PropertyChanges {
                target: distanceText
                text: hsiBrgInterface.nav1Dme
            }
        },
        State {
            name: "nav2ModeDme"
            when: root.dmeMode == 2

            PropertyChanges {
                target: sourceText
                text: "NAV2"
            }
            PropertyChanges {
                target: identText
                text: hsiBrgInterface.nav2Freq
            }
            PropertyChanges {
                target: distanceText
                text: hsiBrgInterface.nav2Dme
            }
        }
    ]


    ShapePath {
        fillColor: "#1A1D21"
        strokeColor: "transparent"

        PathMove { x: 93.04615384615386; y: 288 }
        PathLine { x: 0; y: 288 }
        PathLine { x: 0; y: 426.4055530211599 }
        PathLine { x: 134.34814059988142; y: 426.4055530211599 }
        PathArc { radiusX: 252.55384615384617; radiusY: 252.55384615384617; direction: PathArc.Clockwise; x: 93.04615384615386; y: 288 }
    }

    Text {
        anchors.left: parent.left
        anchors.leftMargin: 4.430769230769231
        anchors.baseline: parent.top
        anchors.baselineOffset: 319.0153846153846
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 27
        font.bold: true
        text: "DME"
    }

    Text {
        id: sourceText
        anchors.left: parent.left
        anchors.leftMargin: 4.430769230769231
        anchors.baseline: parent.top
        anchors.baselineOffset: 350.03076923076924
        color: "#36C8D2"
        font.family: "Roboto Mono"
        font.pixelSize: 27
        font.bold: true
        text: "NAV1"
    }

    Text {
        id: identText
        anchors.left: parent.left
        anchors.leftMargin: 4.430769230769231
        anchors.baseline: parent.top
        anchors.baselineOffset: 381.04615384615386
        color: "#36C8D2"
        font.family: "Roboto Mono"
        font.pixelSize: 27
        font.bold: true
        text: "117.80"
    }

    Text {
        id: distanceText
        anchors.left: parent.left
        anchors.leftMargin: 4.430769230769231
        anchors.baseline: parent.top
        anchors.baselineOffset: 412.0615384615385
        color: "#36C8D2"
        font.family: "Roboto Mono"
        font.pixelSize: 27
        font.bold: true
        text: "97.7NM"
    }


}
