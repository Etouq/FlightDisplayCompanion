import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.Attitude 1.0

Shape {
    transform: Rotation {
        angle: Attitude.bankAngle
        origin.x: 288
        origin.y: 288
    }

    ShapePath {
        fillColor: "white"
        strokeColor: "transparent"

        PathMove { x: 288; y: 43.2}
        PathLine { relativeX: -28.8; relativeY: -43.2 }
        PathLine { relativeX: 57.6; relativeY: 0 }
    }

    Rectangle {
        x: 285.12
        y: 0
        width: 5.76
        height: 43.2
        transform: Rotation { angle: -60; origin.x: 2.88; origin.y: 288 }
        color: "white"
    }

    Rectangle {
        x: 285.12
        y: 0
        width: 5.76
        height: 43.2
        transform: Rotation { angle: -30; origin.x: 2.88; origin.y: 288 }
        color: "white"
    }

    Rectangle {
        x: 285.12
        y: 0
        width: 5.76
        height: 43.2
        transform: Rotation { angle: 30; origin.x: 2.88; origin.y: 288 }
        color: "white"
    }

    Rectangle {
        x: 285.12
        y: 0
        width: 5.76
        height: 43.2
        transform: Rotation { angle: 60; origin.x: 2.88; origin.y: 288 }
        color: "white"
    }

    Rectangle {
        x: 285.12
        y: 14.4
        width: 5.76
        height: 28.8
        transform: Rotation { angle: -45; origin.x: 2.88; origin.y: 273.6 }
        color: "white"
    }

    Rectangle {
        x: 285.12
        y: 14.4
        width: 5.76
        height: 28.8
        transform: Rotation { angle: -20; origin.x: 2.88; origin.y: 273.6 }
        color: "white"
    }

    Rectangle {
        x: 285.12
        y: 14.4
        width: 5.76
        height: 28.8
        transform: Rotation { angle: -10; origin.x: 2.88; origin.y: 273.6 }
        color: "white"
    }

    Rectangle {
        x: 285.12
        y: 14.4
        width: 5.76
        height: 28.8
        transform: Rotation { angle: 10; origin.x: 2.88; origin.y: 273.6 }
        color: "white"
    }

    Rectangle {
        x: 285.12
        y: 14.4
        width: 5.76
        height: 28.8
        transform: Rotation { angle: 20; origin.x: 2.88; origin.y: 273.6 }
        color: "white"
    }

    Rectangle {
        x: 285.12
        y: 14.4
        width: 5.76
        height: 28.8
        transform: Rotation { angle: 45; origin.x: 2.88; origin.y: 273.6 }
        color: "white"
    }
}
