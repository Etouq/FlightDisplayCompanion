import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.Attitude 1.0

Item {
    width: 576
    height: 432
    AttitudePitchContainer {
        x: 122.4
        y: 100.8
    }

    AttitudeBank {}

    Cursors {}

    Shape {
        transform: Translate { x: Attitude.slipSkidTransformValue }
        ShapePath {
            fillColor: "white"
            strokeColor: "transparent"

            PathMove { x: 259.2; y: 86.4 }
            PathLine { x: 264.96; y: 77.76 }
            PathLine { x: 311.04; y: 77.76 }
            PathLine { x: 316.8; y: 86.4 }
        }
    }
}
