import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {
    id: root

    transform: Rotation { angle: -hsiInterface.rotation; origin.x: 345.6; origin.y: 288 }

    Rectangle {
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 345.6
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 288
        width: 443.0769230769231
        height: 443.0769230769231
        radius: 221.53846153846155
        opacity: 0.25
        color: "#1A1D21"
    }

    BgCircleItems {}

    Shape {
        transform: Rotation { angle: hsiInterface.headingBugRotation; origin.x: 345.6; origin.y: 288 }
        ShapePath {
            fillColor: "aqua"
            strokeColor: "transparent"

            PathMove { x: 327.8769230769231; y: 66.46153846153847 }
            PathLine { x: 332.3076923076923; y: 66.46153846153847 }
            PathLine { x: 345.6; y: 84.18461538461538 }
            PathLine { x: 358.8923076923077; y: 66.46153846153847 }
            PathLine { x: 363.32307692307694; y: 66.46153846153847 }
            PathLine { x: 363.32307692307694; y: 88.61538461538461 }
            PathLine { x: 327.8769230769231; y: 88.61538461538461 }
        }
    }

    Rectangle {
        visible: hsiBrgInterface.brg1Mode != 0 || hsiBrgInterface.brg2Mode != 0
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 345.6
        anchors.verticalCenter: parent.top
        anchors.verticalCenterOffset: 288
        width: 269.39076923076925
        height: 269.39076923076925
        radius: 134.69538461538463
        border.color: "white"
        border.width: 3.544615384615385
        color: "transparent"
    }

    Shape {
        transform: Rotation { angle: hsiInterface.currentTrackAngle; origin.x: 345.6; origin.y: 288 }
        ShapePath {
            fillColor: "#D12BC7"
            strokeColor: "transparent"

            PathMove { x: 345.6; y: 48.73846153846154 }
            PathLine { x: 354.46153846153845; y: 66.46153846153847 }
            PathLine { x: 345.6; y: 84.18461538461538 }
            PathLine { x: 336.73846153846154; y: 66.46153846153847 }
        }
    }

    Shape {
        id: bearing1Arrow
        visible: false

        transform: Rotation {
            id: bearing1Rotation
            angle: 0
            origin.x: 345.6
            origin.y: 288
        }

        states: [
            State {
                name: "nav1Mode"
                when: hsiBrgInterface.brg1Mode == 1

                PropertyChanges {
                    target: bearing1Arrow
                    visible: hsiBrgInterface.showNav1Bearing
                }
                PropertyChanges {
                    target: bearing1Rotation
                    angle: (180 + hsiBrgInterface.nav1Bearing) % 360
                }
            },
            State {
                name: "nav2Mode"
                when: hsiBrgInterface.brg1Mode == 2

                PropertyChanges {
                    target: bearing1Arrow
                    visible: hsiBrgInterface.showNav2Bearing
                }
                PropertyChanges {
                    target: bearing1Rotation
                    angle: (180 + hsiBrgInterface.nav2Bearing) % 360
                }
            },
            State {
                name: "gpsMode"
                when: hsiBrgInterface.brg1Mode == 3

                PropertyChanges {
                    target: bearing1Arrow
                    visible: true
                }
                PropertyChanges {
                    target: bearing1Rotation
                    angle: hsiBrgInterface.gpsBearing
                }
            },
            State {
                name: "adfMode"
                when: hsiBrgInterface.brg1Mode == 4

                PropertyChanges {
                    target: bearing1Arrow
                    visible: hsiBrgInterface.showAdfBearing
                }
                PropertyChanges {
                    target: bearing1Rotation
                    angle: (hsiBrgInterface.adfBearing + hsiInterface.rotation) % 360
                }
            }
        ]

        ShapePath {
            fillColor: "transparent"
            strokeColor: "#36C8D2"
            strokeWidth: 4.430769230769231

            PathMove { x: 345.6; y: 491.81538461538463 }
            PathLine { x: 345.6; y: 420.92307692307696 }
            PathMove { x: 345.6; y: 84.18461538461538 }
            PathLine { x: 345.6; y: 155.0769230769231 }
            PathMove { x: 345.6; y: 101.90769230769232 }
            PathLine { x: 376.61538461538464; y: 132.92307692307693 }
            PathMove { x: 345.6; y: 101.90769230769232 }
            PathLine { x: 314.5846153846154; y: 132.92307692307693 }
        }
    }

    Shape {
        id: bearing2Arrow
        visible: false

        transform: Rotation {
            id: bearing2Rotation
            angle: 0
            origin.x: 345.6
            origin.y: 288
        }

        states: [
            State {
                name: "nav1Mode"
                when: hsiBrgInterface.brg2Mode == 1

                PropertyChanges {
                    target: bearing2Arrow
                    visible: hsiBrgInterface.showNav1Bearing
                }
                PropertyChanges {
                    target: bearing2Rotation
                    angle: (180 + hsiBrgInterface.nav1Bearing) % 360
                }
            },
            State {
                name: "nav2Mode"
                when: hsiBrgInterface.brg2Mode == 2

                PropertyChanges {
                    target: bearing2Arrow
                    visible: hsiBrgInterface.showNav2Bearing
                }
                PropertyChanges {
                    target: bearing2Rotation
                    angle: (180 + hsiBrgInterface.nav2Bearing) % 360
                }
            },
            State {
                name: "gpsMode"
                when: hsiBrgInterface.brg2Mode == 3

                PropertyChanges {
                    target: bearing2Arrow
                    visible: true
                }
                PropertyChanges {
                    target: bearing2Rotation
                    angle: hsiBrgInterface.gpsBearing
                }
            },
            State {
                name: "adfMode"
                when: hsiBrgInterface.brg2Mode == 4

                PropertyChanges {
                    target: bearing2Arrow
                    visible: hsiBrgInterface.showAdfBearing
                }
                PropertyChanges {
                    target: bearing2Rotation
                    angle: (hsiBrgInterface.adfBearing + hsiInterface.rotation) % 360
                }
            }
        ]

        ShapePath {
            fillColor: "transparent"
            strokeColor: "#36C8D2"
            strokeWidth: 4.430769230769231

            PathMove { x: 345.6; y: 491.81538461538463 }
            PathLine { x: 345.6; y: 474.0923076923077 }
            PathMove { x: 332.3076923076923; y: 420.92307692307696 }
            PathLine { x: 332.3076923076923; y: 465.2307692307693 }
            PathQuad { x: 358.8923076923077; y: 465.2307692307693; controlX: 345.6; controlY: 491.81538461538463 }
            PathLine { x: 358.8923076923077; y: 420.92307692307696 }
            PathMove { x: 345.6; y: 84.18461538461538 }
            PathLine { x: 345.6; y: 101.90769230769232 }
            PathLine { x: 376.61538461538464; y: 132.92307692307693 }
            PathMove { x: 345.6; y: 101.90769230769232 }
            PathLine { x: 314.5846153846154; y: 132.92307692307693 }
            PathMove { x: 332.3076923076923; y: 115.2 }
            PathLine { x: 332.3076923076923; y: 155.0769230769231 }
            PathMove { x: 358.8923076923077; y: 115.2 }
            PathLine { x: 358.8923076923077; y: 155.0769230769231 }
        }
    }

    Course {
    }
}
