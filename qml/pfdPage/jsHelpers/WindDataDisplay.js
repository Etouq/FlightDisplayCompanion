class WindDataDisplay {
    constructor() {
        this.scaleFactor = 1.5
    }

    completedCallback(_parent) {
        this.windDataBackground = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (0 * this.scaleFactor) + ';' +
            'y: ' + (0 * this.scaleFactor) + ';' +
            'width: ' + (90 * this.scaleFactor) + ';' +
            'height: ' + (60 * this.scaleFactor) + ';' +
            'visible: windMode != 0;' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(this.windDataBackground);

        this.windDataOptn1 = Qt.createQmlObject('import QtQuick 2.15; Item { visible: windMode == 1 && windMode != 0 }', _parent);
        _parent.data.push(this.windDataOptn1);

        this.createWindDataOptn1();

        this.windDataOptn2 = Qt.createQmlObject('import QtQuick 2.15; Item { visible: windMode == 2 && windMode != 0 }', _parent);
        _parent.data.push(this.windDataOptn2);

        this.createWindDataOptn2();

        this.windDataOptn3 = Qt.createQmlObject('import QtQuick 2.15; Item { visible: windMode == 3 && windMode != 0 }', _parent);
        _parent.data.push(this.windDataOptn3);

        this.createWindDataOptn3();

    }

    createWindDataOptn1()
    {
        this.o1ArrowX = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'transform: Rotation { angle: Math.sin(windInterface.windDirection / 180.0 * 3.14159265358979323846) > 0 ? 90 : -90; origin.x: ' + (22.5 * this.scaleFactor) + '; origin.y: ' + (20 * this.scaleFactor) + ' }' +
            'ShapePath {' +
            'fillColor: "white";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (22.5 * this.scaleFactor) + '; y: ' + (5 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (17.5 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (21 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (21 * this.scaleFactor) + '; y: ' + (35 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (24 * this.scaleFactor) + '; y: ' + (35 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (24 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (27.5 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' } } }',
            this.windDataOptn1);
        this.windDataOptn1.data.push(this.o1ArrowX);

        this.o1ArrowY = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'transform: Rotation { angle: Math.cos(windInterface.windDirection / 180.0 * 3.14159265358979323846) > 0 ? 0 : 180; origin.x: ' + (22.5 * this.scaleFactor) + '; origin.y: ' + (20 * this.scaleFactor) + ' }' +
            'ShapePath {' +
            'fillColor: "white";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (22.5 * this.scaleFactor) + '; y: ' + (5 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (17.5 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (21 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (21 * this.scaleFactor) + '; y: ' + (35 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (24 * this.scaleFactor) + '; y: ' + (35 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (24 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (27.5 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' } } }',
            this.windDataOptn1);
        this.windDataOptn1.data.push(this.o1ArrowY);

        this.o1TextX = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (50 * this.scaleFactor) + ';' +
            'anchors.verticalCenter: parent.top;' +
            'anchors.verticalCenterOffset: ' + (20 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (20 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: Math.round(Math.abs(windInterface.windStrength * Math.sin(windInterface.windDirection / 180.0 * 3.14159265358979323846))) }',
            this.windDataOptn1);
        this.windDataOptn1.data.push(this.o1TextX);

        this.o1TextY = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (22.5 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (55 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (20 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: Math.round(Math.abs(windInterface.windStrength * Math.cos(windInterface.windDirection / 180.0 * 3.14159265358979323846))) }',
            this.windDataOptn1);
        this.windDataOptn1.data.push(this.o1TextY);
    }

    createWindDataOptn2() {
        this.o2Arrow = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'transform: Rotation { angle: windInterface.windDirection; origin.x: ' + (22.5 * this.scaleFactor) + '; origin.y: ' + (30 * this.scaleFactor) + ' }' +
            'ShapePath {' +
            'fillColor: "white";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (22.5 * this.scaleFactor) + '; y: ' + (10 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (15 * this.scaleFactor) + '; y: ' + (20 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (21 * this.scaleFactor) + '; y: ' + (20 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (21 * this.scaleFactor) + '; y: ' + (50 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (24 * this.scaleFactor) + '; y: ' + (50 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (24 * this.scaleFactor) + '; y: ' + (20 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (30 * this.scaleFactor) + '; y: ' + (20 * this.scaleFactor) + ' } } }',
            this.windDataOptn2);
        this.windDataOptn2.data.push(this.o2Arrow);

        this.o2Text = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (50 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (40 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (30 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: Math.round(windInterface.windStrength) }',
            this.windDataOptn2);
        this.windDataOptn2.data.push(this.o2Text);
    }

    createWindDataOptn3() {
        this.o3Arrow = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'transform: Rotation { angle: windInterface.windDirection; origin.x: ' + (22.5 * this.scaleFactor) + '; origin.y: ' + (30 * this.scaleFactor) + ' }' +
            'ShapePath {' +
            'fillColor: "white";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (22.5 * this.scaleFactor) + '; y: ' + (10 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (15 * this.scaleFactor) + '; y: ' + (20 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (21 * this.scaleFactor) + '; y: ' + (20 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (21 * this.scaleFactor) + '; y: ' + (50 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (24 * this.scaleFactor) + '; y: ' + (50 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (24 * this.scaleFactor) + '; y: ' + (20 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (30 * this.scaleFactor) + '; y: ' + (20 * this.scaleFactor) + ' } } }',
            this.windDataOptn3);
        this.windDataOptn3.data.push(this.o3Arrow);

        this.o3TextDirection = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (40 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (20 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (20 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: windInterface.windTrueDirection.toFixed(0) + "°"}',
            this.windDataOptn3);
        this.windDataOptn3.data.push(this.o3TextDirection);

        this.o3TextSpeed = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (40 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (50 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (20 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: windInterface.windStrength.toFixed(0) + "KT" }',
            this.windDataOptn3);
        this.windDataOptn3.data.push(this.o3TextSpeed);
    }



}
