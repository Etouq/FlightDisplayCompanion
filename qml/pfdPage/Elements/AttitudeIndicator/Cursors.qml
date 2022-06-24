import QtQuick 2.15
import QtQuick.Shapes 1.15

Shape {
    ShapePath {
        fillColor: "#CCCC00"
        strokeColor: "transparent"

        PathMove { x: 14.4; y: 288 }
        PathLine { relativeX: -14.4; relativeY: 17.28 }
        PathLine { relativeX: 72; relativeY: 0 }
        PathLine { relativeX: 14.4; relativeY: -17.28 }
    }

    ShapePath {
        fillColor: "#FFFF00"
        strokeColor: "transparent"

        PathMove { x: 14.4; y: 288 }
        PathLine { relativeX: -14.4; relativeY: -17.28 }
        PathLine { relativeX: 72; relativeY: 0 }
        PathLine { relativeX: 14.4; relativeY: 17.28 }
    }

    ShapePath {
        fillColor: "#CCCC00"
        strokeColor: "transparent"

        PathMove { x: 561.6; y: 288 }
        PathLine { relativeX: 14.4; relativeY: 17.28 }
        PathLine { relativeX: -72; relativeY: 0 }
        PathLine { relativeX: -14.4; relativeY: -17.28 }
    }

    ShapePath {
        fillColor: "#FFFF00"
        strokeColor: "transparent"

        PathMove { x: 561.6; y: 288 }
        PathLine { relativeX: 14.4; relativeY: -17.28 }
        PathLine { relativeX: -72; relativeY: 0 }
        PathLine { relativeX: -14.4; relativeY: 17.28 }
    }

    ShapePath {
        fillColor: "#FFFF00"
        strokeColor: "transparent"

        PathMove { x: 158.4; y: 331.2 }
        PathLine { relativeX: 43.2; relativeY: 0 }
        PathLine { x: 288; y: 288 }
    }

    ShapePath {
        fillColor: "#FFFF00"
        strokeColor: "transparent"

        PathMove { x: 417.6; y: 331.2 }
        PathLine { relativeX: -43.2; relativeY: 0 }
        PathLine { x: 288; y: 288 }
    }

    ShapePath {
        fillColor: "white"
        strokeColor: "transparent"

        PathMove { x: 288; y: 43.2 }
        PathLine { relativeX: -18.72; relativeY: 28.8 }
        PathLine { relativeX: 37.44; relativeY: 0 }
    }
}
