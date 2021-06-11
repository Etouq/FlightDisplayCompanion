class AOAIndicator {
    constructor() {
        this.redPercent = 17;
        this.whiteBarAngle = 50;
        this.scaleFactor = 1.92;
    }

    completedCallback(_parent) {
        let background = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (0 * this.scaleFactor) + ';' +
            'y: ' + (0 * this.scaleFactor) + ';' +
            'width: ' + (100 * this.scaleFactor) + ';' +
            'height: ' + (100 * this.scaleFactor) + ';' +
            'opacity: 0.25;' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(background);

        let whiteCircle = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { ShapePath {' +
            'fillColor: "transparent";' +
            'strokeColor: "white";' +
            'strokeWidth: ' + (4 * this.scaleFactor) + ';' +
            'PathAngleArc { radiusX: ' + (80 * this.scaleFactor) + '; radiusY: ' + (80 * this.scaleFactor) + '; startAngle: 180; sweepAngle: 90; centerX: ' + (90 * this.scaleFactor) + '; centerY: ' + (90 * this.scaleFactor) + ' } } }',
            _parent);
        _parent.data.push(whiteCircle);

        let redCircle = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { ShapePath {' +
            'fillColor: "transparent";' +
            'strokeColor: "red";' +
            'strokeWidth: ' + (4 * this.scaleFactor) + ';' +
            'PathAngleArc { radiusX: ' + (80 * this.scaleFactor) + '; radiusY: ' + (80 * this.scaleFactor) + '; startAngle: 270; sweepAngle: -15.3; centerX: ' + (90 * this.scaleFactor) + '; centerY: ' + (90 * this.scaleFactor) + ' } } }',
            _parent);
        _parent.data.push(redCircle);

        let whiteBar = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (-10 * this.scaleFactor) + ';' +
            'y: ' + (90 * this.scaleFactor) + ';' +
            'width: ' + (15 * this.scaleFactor) + ';' +
            'height: ' + (2 * this.scaleFactor) + ';' +
            'transform: Rotation { angle: 50; origin.x: ' + (100 * this.scaleFactor) + '; origin.y: 0 }' +
            'color: "white" }',
            _parent);
        _parent.data.push(whiteBar);

        this.cursor = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'transform: Rotation { angle: aoaInterface.aoaAngle; origin.x: ' + (90 * this.scaleFactor) + '; origin.y: ' + (90 * this.scaleFactor) + ' }' +
            'ShapePath {' +
            'fillColor: aoaInterface.cursorColor;' +
            'strokeColor: "black";' +
            'strokeWidth: ' + (1 * this.scaleFactor) + ';' +
            'PathMove { x: ' + (10 * this.scaleFactor) + '; y: ' + (90 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (30 * this.scaleFactor) + '; y: ' + (82.5 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (30 * this.scaleFactor) + '; y: ' + (97.5 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (10 * this.scaleFactor) + '; y: ' + (90 * this.scaleFactor) + ' } } }',
            _parent);
        _parent.data.push(this.cursor);

        let AOAText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (60 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (70 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (17 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: "AOA" }',
            _parent);
        _parent.data.push(AOAText);
    }
}
