import QtQuick 2.15
import QtQuick.Shapes 1.15

Shape {
    id: root
    transform: Rotation { angle: hsiInterface.course; origin.x: 345.6; origin.y: 288 }

    Component.onCompleted: hsiInterface.qmlArrowCompleted()

    states: [
        State {
            name: "gpsSource"
            when: hsiInterface.navSource === 0

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
            name: "vor/loc1Source"
            when: hsiInterface.navSource === 1 || hsiInterface.navSource === 2

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
            name: "vor/loc2Source"
            when: hsiInterface.navSource === 3 || hsiInterface.navSource === 4

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
        visible: hsiInterface.toFrom === 2
        ShapePath {
            fillColor: hsiInterface.navSource === 0 ? "#D12BC7" : "#10C210"
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
        visible: hsiInterface.displayDeviation
        transform: Translate { x: hsiInterface.courseDeviation * 4.430769230769231 }
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
        visible: hsiInterface.toFrom === 1
        ShapePath {
            fillColor: hsiInterface.navSource === 0 ? "#D12BC7" : "#10C210"
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
}
