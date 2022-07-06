import QtQuick 2.15
import QtQuick.Shapes 1.15

Shape {
    id: spinnerRoot

    property color spinnerColor: "#9c27b0"

    property real radius: 50

    width: 2 * radius
    height: 2 * radius

    transform: Rotation {
        id: spinnerRotation
        angle: 0
        origin.x: spinnerRoot.radius
        origin.y: spinnerRoot.radius
    }

    ParallelAnimation {
        running: true

        NumberAnimation {
            target: spinnerRotation
            property: "angle"
            duration: 2000
            from: 0
            to: 360
            loops: Animation.Infinite
        }

        SequentialAnimation {
            loops: Animation.Infinite

            NumberAnimation {
                target: spinnerArc
                property: "sweepAngle"
                duration: 500
                from: 18
                to: 288
                easing.type: Easing.Bezier
                easing.bezierCurve: [0.35, 0, 0.25, 1, 1, 1]
            }

            ParallelAnimation {
                NumberAnimation {
                    target: spinnerArc
                    property: "sweepAngle"
                    duration: 500
                    from: 288
                    to: 18
                    easing.type: Easing.Bezier
                    easing.bezierCurve: [0.35, 0, 0.25, 1, 1, 1]
                }

                NumberAnimation {
                    target: spinnerArc
                    property: "startAngle"
                    duration: 500
                    from: 0
                    to: 270
                    easing.type: Easing.Bezier
                    easing.bezierCurve: [0.35, 0, 0.25, 1, 1, 1]
                }
            }

            NumberAnimation {
                target: spinnerArc
                property: "sweepAngle"
                duration: 500
                from: 18
                to: 288
                easing.type: Easing.Bezier
                easing.bezierCurve: [0.35, 0, 0.25, 1, 1, 1]
            }

            ParallelAnimation {
                NumberAnimation {
                    target: spinnerArc
                    property: "sweepAngle"
                    duration: 500
                    from: 288
                    to: 18
                    easing.type: Easing.Bezier
                    easing.bezierCurve: [0.35, 0, 0.25, 1, 1, 1]
                }

                NumberAnimation {
                    target: spinnerArc
                    property: "startAngle"
                    duration: 500
                    from: 270
                    to: 540
                    easing.type: Easing.Bezier
                    easing.bezierCurve: [0.35, 0, 0.25, 1, 1, 1]
                }
            }

            NumberAnimation {
                target: spinnerArc
                property: "sweepAngle"
                duration: 500
                from: 18
                to: 288
                easing.type: Easing.Bezier
                easing.bezierCurve: [0.35, 0, 0.25, 1, 1, 1]
            }

            ParallelAnimation {
                NumberAnimation {
                    target: spinnerArc
                    property: "sweepAngle"
                    duration: 500
                    from: 288
                    to: 18
                    easing.type: Easing.Bezier
                    easing.bezierCurve: [0.35, 0, 0.25, 1, 1, 1]
                }

                NumberAnimation {
                    target: spinnerArc
                    property: "startAngle"
                    duration: 500
                    from: 180
                    to: 450
                    easing.type: Easing.Bezier
                    easing.bezierCurve: [0.35, 0, 0.25, 1, 1, 1]
                }
            }

            NumberAnimation {
                target: spinnerArc
                property: "sweepAngle"
                duration: 500
                from: 18
                to: 288
                easing.type: Easing.Bezier
                easing.bezierCurve: [0.35, 0, 0.25, 1, 1, 1]
            }

            ParallelAnimation {
                NumberAnimation {
                    target: spinnerArc
                    property: "sweepAngle"
                    duration: 500
                    from: 288
                    to: 18
                    easing.type: Easing.Bezier
                    easing.bezierCurve: [0.35, 0, 0.25, 1, 1, 1]
                }

                NumberAnimation {
                    target: spinnerArc
                    property: "startAngle"
                    duration: 500
                    from: 90
                    to: 360
                    easing.type: Easing.Bezier
                    easing.bezierCurve: [0.35, 0, 0.25, 1, 1, 1]
                }
            }
        }
    }

    ShapePath {
        id: spinner
        strokeColor: spinnerRoot.spinnerColor
        strokeWidth: spinnerRoot.radius / 5

        fillColor: "transparent"

        PathAngleArc {
            id: spinnerArc
            centerX: spinnerRoot.radius
            centerY: spinnerRoot.radius
            radiusX: spinnerRoot.radius * 0.9
            radiusY: spinnerRoot.radius * 0.9
            startAngle: 0
            sweepAngle: 18
        }
    }

}