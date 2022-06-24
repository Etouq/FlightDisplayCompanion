import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.Attitude 1.0

Shape {

    transform: [
        Translate { y: Attitude.fdPitchTransformValue },
        Rotation {
            angle: Attitude.fdBankAngle
            origin.x: 165.6
            origin.y: 187.2
        }
    ]

    ShapePath {
        fillColor: "#D12BC7"
        strokeColor: "transparent"
        PathMove { x: -36; y: 230.4 }
        PathLine { relativeX: 72; relativeY: 0 }
        PathLine { x: 165.6; y: 187.2 }
    }

    ShapePath {
        fillColor: "#D12BC7"
        strokeColor: "transparent"
        PathMove { x: 367.2; y: 230.4 }
        PathLine { relativeX: -72; relativeY: 0 }
        PathLine { x: 165.6; y: 187.2 }
    }
}
