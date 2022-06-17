import QtQuick 2.15
import QtQuick.Shapes 1.15

ShapePath {
    id: colorArc
    required fillColor
    strokeColor: "transparent"

    required property real centerX
    required property real centerY
    required property real outerRadius
    required property real arcWidth

    required property real startAngle
    required property real endAngle

    PathAngleArc {
        id: outerArc
        centerX: colorArc.centerX
        centerY: colorArc.centerY
        radiusX: colorArc.outerRadius
        radiusY: colorArc.outerRadius
        startAngle: colorArc.startAngle
        sweepAngle: colorArc.endAngle - colorArc.startAngle
    }
    PathAngleArc {
        id: innerArc
        centerX: colorArc.centerX
        centerY: colorArc.centerY
        radiusX: colorArc.outerRadius - colorArc.arcWidth
        radiusY: colorArc.outerRadius - colorArc.arcWidth
        startAngle: colorArc.endAngle
        sweepAngle: colorArc.startAngle - colorArc.endAngle
        moveToStart: false
    }
}
