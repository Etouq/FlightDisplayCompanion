import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {
    Shape {
        opacity: 0.25
        ShapePath {
            fillColor: "#1A1D21"
            strokeColor: "transparent"

            PathAngleArc { centerX: 345.6; centerY: 288; radiusX: 245.90769230769232; radiusY: 245.90769230769232; startAngle: 246; sweepAngle: 48 }
            PathAngleArc { centerX: 345.6; centerY: 288; radiusX: 223.75384615384615; radiusY: 223.75384615384615; startAngle: 294; sweepAngle: -48; moveToStart: false }
        }
    }

    Rectangle {
        x: 343.3846153846154
        y: 42.09230769230769
        width: 4.430769230769231
        height: 22.153846153846153
        color: "white"
        transform: Rotation { angle: -18; origin.x: 2.2153846153846155; origin.y: 245.90769230769232 }
    }

    Rectangle {
        x: 343.3846153846154
        y: 42.09230769230769
        width: 4.430769230769231
        height: 22.153846153846153
        color: "white"
        transform: Rotation { angle: -9; origin.x: 2.2153846153846155; origin.y: 245.90769230769232 }
    }

    Rectangle {
        x: 343.3846153846154
        y: 42.09230769230769
        width: 4.430769230769231
        height: 22.153846153846153
        color: "white"
        transform: Rotation { angle: 9; origin.x: 2.2153846153846155; origin.y: 245.90769230769232 }
    }

    Rectangle {
        x: 343.3846153846154
        y: 42.09230769230769
        width: 4.430769230769231
        height: 22.153846153846153
        color: "white"
        transform: Rotation { angle: 18; origin.x: 2.2153846153846155; origin.y: 245.90769230769232 }
    }

    Shape {
        ShapePath {
            fillColor: "#D12BC7"
            strokeColor: "transparent"

            PathAngleArc { centerX: 345.6; centerY: 288; radiusX: 239.26153846153846; radiusY: 239.26153846153846; startAngle: 270; sweepAngle: hsiInterface.turnRate }
            PathAngleArc { centerX: 345.6; centerY: 288; radiusX: 230.4; radiusY: 230.4; startAngle: 270 + hsiInterface.turnRate; sweepAngle: -hsiInterface.turnRate; moveToStart: false }
        }
    }

    Shape {
        visible: hsiInterface.turnRate <= -24
        ShapePath {
            fillColor: "#D12BC7"
            strokeColor: "transparent"

            PathMove { x: 244.67925262266917; y: 61.32829014061745 }
            PathLine { x: 229.1457734185646; y: 84.07868358399975 }
            PathLine { x: 255.4921898416689; y: 85.61454476840844 }
        }
    }

    Shape {
        visible: hsiInterface.turnRate >= 24
        ShapePath {
            fillColor: "#D12BC7"
            strokeColor: "transparent"

            PathMove { x: 446.5207473773309; y: 61.32829014061745 }
            PathLine { x: 462.0542265814354; y: 84.07868358399975 }
            PathLine { x: 435.7078101583311; y: 85.61454476840844 }
        }
    }
}






















