import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.HSIndicator 1.0
import TypeEnums 1.0

Shape {
    id: root
    transform: Rotation { angle: HSIndicator.course; origin.x: 345.6; origin.y: 288 }

    Component.onCompleted: HSIndicator.qmlArrowCompleted()


    ShapePath {
        id: beginArrow
        fillColor: "#D12BC7"
        strokeColor: "#10C210"
        strokeWidth: 4.430769230769231
        fillRule: ShapePath.WindingFill
        joinStyle: ShapePath.MiterJoin

        PathMove { x: 350.03076923076924; y: 491.81538461538463 }
        PathLine { x: 341.1692307692308; y: 491.81538461538463 }
        PathLine { x: 341.1692307692308; y: 398.7692307692308 }
        PathLine { x: 350.03076923076924; y: 398.7692307692308 }
        PathLine { x: 350.03076923076924; y: 491.81538461538463 }
    }

    Shape {
        visible: HSIndicator.toFrom === 2
        ShapePath {
            fillColor: HSIndicator.navSource === HsiNavSource.GPS ? "#D12BC7" : "#10C210"
            fillRule: ShapePath.WindingFill
            strokeColor: "black"
            strokeWidth: 0.9094736842105263
            joinStyle: ShapePath.MiterJoin

            PathMove { x: 327.8769230769231; y: 398.7692307692308 }
            PathLine { x: 363.32307692307694; y: 398.7692307692308 }
            PathLine { x: 345.6; y: 420.92307692307696 }
            PathLine { x: 327.8769230769231; y: 398.7692307692308 }
        }
    }

    Shape {
        visible: HSIndicator.displayDeviation
        transform: Translate { x: HSIndicator.courseDeviation * 4.430769230769231 }
        ShapePath {
            id: courseDeviationIndicator
            fillColor: "#D12BC7"
            strokeColor: "#10C210"
            strokeWidth: 4.430769230769231
            fillRule: ShapePath.WindingFill
            joinStyle: ShapePath.MiterJoin

            PathMove { x: 341.1692307692308; y: 396.55384615384617 }
            PathLine { x: 350.03076923076924; y: 396.55384615384617 }
            PathLine { x: 350.03076923076924; y: 179.44615384615386 }
            PathLine { x: 341.1692307692308; y: 179.44615384615386 }
            PathLine { x: 341.1692307692308; y: 396.55384615384617 }
        }
    }

    ShapePath {
        id: endArrow
        fillColor: "#D12BC7"
        strokeColor: "#10C210"
        strokeWidth: 4.430769230769231
        fillRule: ShapePath.WindingFill
        joinStyle: ShapePath.MiterJoin

        PathMove { x: 350.03076923076924; y: 177.23076923076923 }
        PathLine { x: 341.1692307692308; y: 177.23076923076923 }
        PathLine { x: 341.1692307692308; y: 132.92307692307693 }
        PathLine { x: 323.4461538461539; y: 132.92307692307693 }
        PathLine { x: 345.6; y: 84.18461538461538 }
        PathLine { x: 367.75384615384615; y: 132.92307692307693 }
        PathLine { x: 350.03076923076924; y: 132.92307692307693 }
        PathLine { x: 350.03076923076924; y: 177.23076923076923 }
    }

    Shape {
        visible: HSIndicator.toFrom === 1
        ShapePath {
            fillColor: HSIndicator.navSource === HsiNavSource.GPS ? "#D12BC7" : "#10C210"
            strokeColor: "black"
            strokeWidth: 0.9094736842105263
            joinStyle: ShapePath.MiterJoin

            PathMove { x: 327.8769230769231; y: 177.23076923076923 }
            PathLine { x: 363.32307692307694; y: 177.23076923076923 }
            PathLine { x: 345.6; y: 155.0769230769231 }
            PathLine { x: 327.8769230769231; y: 177.23076923076923 }
        }
    }

    Rectangle {
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 256.9846153846154
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 288
        width: 22.153846153846153
        height: 22.153846153846153
        radius: 11.076923076923077
        border.width: 4.430769230769231
        border.color: "white"
        color: "transparent"
    }

    Rectangle {
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 301.2923076923077
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 288
        width: 22.153846153846153
        height: 22.153846153846153
        radius: 11.076923076923077
        border.width: 4.430769230769231
        border.color: "white"
        color: "transparent"
    }

    Rectangle {
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 389.90769230769234
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 288
        width: 22.153846153846153
        height: 22.153846153846153
        radius: 11.076923076923077
        border.width: 4.430769230769231
        border.color: "white"
        color: "transparent"
    }

    Rectangle {
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 434.21538461538466
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 288
        width: 22.153846153846153
        height: 22.153846153846153
        radius: 11.076923076923077
        border.width: 4.430769230769231
        border.color: "white"
        color: "transparent"
    }


    states: [
        State {
            name: "gpsSource"
            when: HSIndicator.navSource === HsiNavSource.GPS

            PropertyChanges {
                target: beginArrow
                fillColor: "#D12BC7"
                strokeColor: "transparent"
            }
            PropertyChanges {
                target: courseDeviationIndicator
                fillColor: "#D12BC7"
                strokeColor: "transparent"
            }
            PropertyChanges {
                target: endArrow
                fillColor: "#D12BC7"
                strokeColor: "transparent"
            }
        },
        State {
            name: "vor/loc/tcn1Source"
            when: HSIndicator.navSource === HsiNavSource.VOR1 || HSIndicator.navSource === HsiNavSource.LOC1 || HSIndicator.navSource === HsiNavSource.TCN1

            PropertyChanges {
                target: beginArrow
                fillColor: "#10C210"
                strokeColor: "transparent"
            }
            PropertyChanges {
                target: courseDeviationIndicator
                fillColor: "#10C210"
                strokeColor: "transparent"
            }
            PropertyChanges {
                target: endArrow
                fillColor: "#10C210"
                strokeColor: "transparent"
            }
        },
        State {
            name: "vor/loc/tcn2Source"
            when: HSIndicator.navSource === HsiNavSource.VOR2 || HSIndicator.navSource === HsiNavSource.LOC2 || HSIndicator.navSource === HsiNavSource.TCN2

            PropertyChanges {
                target: beginArrow
                fillColor: "transparent"
                strokeColor: "#10C210"
            }
            PropertyChanges {
                target: courseDeviationIndicator
                fillColor: "transparent"
                strokeColor: "#10C210"
            }
            PropertyChanges {
                target: endArrow
                fillColor: "transparent"
                strokeColor: "#10C210"
            }
        }
    ]
}
