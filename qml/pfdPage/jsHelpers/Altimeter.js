class Altimeter {
    constructor() {
        this.currentCenterGrad = -10000;
        this.scaleFactor = 0.96;
    }

    completedCallback(_parent) {
        this.verticalDeviationGroup = Qt.createQmlObject('import QtQuick 2.15; Item { visible: altInterface.verticalDeviationMode != 0 }', _parent);
        _parent.data.push(this.verticalDeviationGroup);
        this.createVerticalDeviationGroup();

        this.selectedAltitudeBackground = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'visible: apInterface.has_ap;' +
            'x: ' + (50 * this.scaleFactor) + ';' +
            'y: 0;' +
            'width: ' + (200 * this.scaleFactor) + ';' +
            'height: ' + (50 * this.scaleFactor) + ';' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(this.selectedAltitudeBackground);

        this.selectedAltitudeFixedBug = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: apInterface.has_ap;' +
            'ShapePath {' +
            'fillColor: "#36C8D2";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (60 * this.scaleFactor) + '; y: ' + (10 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (70 * this.scaleFactor) + '; y: ' + (10 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (70 * this.scaleFactor) + '; y: ' + (20 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (65 * this.scaleFactor) + '; y: ' + (25 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (70 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (70 * this.scaleFactor) + '; y: ' + (40 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (60 * this.scaleFactor) + '; y: ' + (40 * this.scaleFactor) + ' } } }',
            _parent);
        _parent.data.push(this.selectedAltitudeFixedBug);

        this.selectedAltText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'visible: apInterface.has_ap;' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (175 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (40 * this.scaleFactor) + ';' +
            'color: "#36C8D2";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (45 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: altInterface.referenceAltitude }',
            _parent);
        _parent.data.push(this.selectedAltText);

        this.createGraduationGrop(_parent);

        let background = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (50 * this.scaleFactor) + ';' +
            'y: ' + (650 * this.scaleFactor) + ';' +
            'width: ' + (250 * this.scaleFactor) + ';' +
            'height: ' + (50 * this.scaleFactor) + ';' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(background);

        this.baroText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (175 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (690 * this.scaleFactor) + ';' +
            'color: "#36C8D2";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (45 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: pressureUnit == 0 ? (altInterface.pressure.toFixed(2) + "IN") : (Math.round(altInterface.pressure * 33.8639) + "MB") }',
            _parent);
        _parent.data.push(this.baroText);

        this.createVerticalSpeedGroup(_parent);
    }

    createVerticalDeviationGroup() {
        let background = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: 0;' +
            'y: ' + (150 * this.scaleFactor) + ';' +
            'width: ' + (50 * this.scaleFactor) + ';' +
            'height: ' + (400 * this.scaleFactor) + ';' +
            'color: "#1A1D21";' +
            'opacity: 0.25 }',
            this.verticalDeviationGroup);
        this.verticalDeviationGroup.data.push(background);

        let topBackground = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: 0;' +
            'y: ' + (100 * this.scaleFactor) + ';' +
            'width: ' + (50 * this.scaleFactor) + ';' +
            'height: ' + (50 * this.scaleFactor) + ';' +
            'color: "#1A1D21" }',
            this.verticalDeviationGroup);
        this.verticalDeviationGroup.data.push(topBackground);

        this.verticalDeviationText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (25 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (140 * this.scaleFactor) + ';' +
            'color: altInterface.verticalDeviationMode == 2 ? "#10C210" : altInterface.verticalDeviationMode == 4 ? "#DFDFDF" : "#D12BC7";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (45 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: altInterface.verticalDeviationMode == 1 ? "V" : "G" }',
            this.verticalDeviationGroup);
        this.verticalDeviationGroup.data.push(this.verticalDeviationText);

        for (let i = -2; i <= 2; i++) {
            if (i != 0) {
                let grad = Qt.createQmlObject(
                    'import QtQuick 2.15; Rectangle {' +
                    'anchors.horizontalCenter: parent.left;' +
                    'anchors.horizontalCenterOffset: ' + (25 * this.scaleFactor) + ';' +
                    'anchors.verticalCenter: parent.top;' +
                    'anchors.verticalCenterOffset: ' + ((350 + 66 * i) * this.scaleFactor) + ';' +
                    'radius: ' + (7.5 * this.scaleFactor) + ';' +
                    'width: ' + (15 * this.scaleFactor) + ';' +
                    'height: ' + (15 * this.scaleFactor) + ';' +
                    'border.width: ' + (3 * this.scaleFactor) + ';' +
                    'border.color: "white";' +
                    'color: "transparent" }',
                    this.verticalDeviationGroup);
                this.verticalDeviationGroup.data.push(grad);
            }
        }

        this.diamondBug = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'transform: Translate { y: altInterface.verticalDeviationTransformValue }' +
            'ShapePath { ' +
            'fillColor: altInterface.verticalDeviationMode == 2 ? "#10C210" : altInterface.verticalDeviationMode == 4 ? "#DFDFDF" : "#D12BC7";' + // #10c210
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (10 * this.scaleFactor) + '; y: ' + (350 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (25 * this.scaleFactor) + '; y: ' + (335 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (40 * this.scaleFactor) + '; y: ' + (350 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (25 * this.scaleFactor) + '; y: ' + (365 * this.scaleFactor) + ' } } }',
            this.verticalDeviationGroup);
        this.verticalDeviationGroup.data.push(this.diamondBug);

    }

    createGraduationGrop(_parent) {
        let background = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (50 * this.scaleFactor) + ';' +
            'y: ' + (50 * this.scaleFactor) + ';' +
            'width: ' + (200 * this.scaleFactor) + ';' +
            'height: ' + (600 * this.scaleFactor) + ';' +
            'opacity: 0.25;' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(background);

        let graduationItem = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'x: ' + (50 * this.scaleFactor) + ';' +
            'y: ' + (50 * this.scaleFactor) + ';' +
            'width: ' + (200 * this.scaleFactor) + ';' +
            'height: ' + (600 * this.scaleFactor) + ';' +
            'clip: true }',
            _parent);
        _parent.data.push(graduationItem);

        this.graduationGroup = Qt.createQmlObject('import QtQuick 2.15; Item { transform: Translate { y: (altInterface.altitude - altInterface.center) * ' + (1.6 * this.scaleFactor) + ' } }', graduationItem);
        graduationItem.data.push(this.graduationGroup);

        this.graduationTexts = [];
        for (let i = -3; i <= 3; i++) {
            let mainGrad = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: 0;' +
                'y: ' + ((298 + i * 160) * this.scaleFactor) + ';' +
                'width: ' + (40 * this.scaleFactor) + ';' +
                'height: ' + (4 * this.scaleFactor) + ';' +
                'color: "white" }',
                this.graduationGroup);
            this.graduationGroup.data.push(mainGrad);

            let gradText = Qt.createQmlObject(
                'import QtQuick 2.15; Text {' +
                'anchors.left: parent.left;' +
                'anchors.leftMargin: ' + (50 * this.scaleFactor) + ';' +
                'anchors.verticalCenter: parent.top;' +
                'anchors.verticalCenterOffset: ' + ((300 + 160 * i) * this.scaleFactor) + ';' +
                'color: "white";' +
                'font.family: "Roboto Mono";' +
                'font.pixelSize: ' + (45 * this.scaleFactor).toFixed(0) + ';' +
                'font.bold: true;' +
                'text: "XXXX" }',
                _parent);
            this.graduationGroup.data.push(gradText);
            this.graduationTexts.push(gradText);

            for (let j = 1; j < 5; j++) {
                let grad = Qt.createQmlObject(
                    'import QtQuick 2.15; Rectangle {' +
                    'x: 0;' +
                    'y: ' + ((298 + i * 160 + j * 32) * this.scaleFactor) + ';' +
                    'width: ' + (15 * this.scaleFactor) + ';' +
                    'height: ' + (4 * this.scaleFactor) + ';' +
                    'color: "white" }',
                    this.graduationGroup);
                this.graduationGroup.data.push(grad);
            }
        }

        let trendElement = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (50 * this.scaleFactor) + ';' +
            'y: Math.min(altInterface.altitudeTrendValue + 100, 350) * ' + (this.scaleFactor) + ';' +
            'width: ' + (8 * this.scaleFactor) + ';' +
            'height: Math.abs(altInterface.altitudeTrendValue - 250) * ' + (this.scaleFactor) + ';' +
            'color: "#D12BC7" }',
            _parent);
        _parent.data.push(trendElement);

        this.createGroundLine(graduationItem);

        let cursor = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { ShapePath {' +
            'fillColor: "#1A1D21";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (0 * this.scaleFactor) + '; y: ' + (300 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (30 * this.scaleFactor) + '; y: ' + (260 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (130 * this.scaleFactor) + '; y: ' + (260 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (130 * this.scaleFactor) + '; y: ' + (240 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (200 * this.scaleFactor) + '; y: ' + (240 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (200 * this.scaleFactor) + '; y: ' + (360 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (130 * this.scaleFactor) + '; y: ' + (360 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (130 * this.scaleFactor) + '; y: ' + (340 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (30 * this.scaleFactor) + '; y: ' + (340 * this.scaleFactor) + ' } } }',
            graduationItem);
        graduationItem.data.push(cursor);

        this.createCursorBaseItem(graduationItem);

        this.createCursorRotatingItem(graduationItem);

        let selectedAltitudeBug = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: apInterface.has_ap;' +
            'transform: Translate { y: (altInterface.altitude - altInterface.referenceAltitude) * ' + (1.6 * this.scaleFactor) + ' }' +
            'ShapePath {' +
            'fillColor: "#36C8D2";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (0 * this.scaleFactor) + '; y: ' + (280 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (20 * this.scaleFactor) + '; y: ' + (280 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (20 * this.scaleFactor) + '; y: ' + (285 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (10 * this.scaleFactor) + '; y: ' + (300 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (20 * this.scaleFactor) + '; y: ' + (315 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (20 * this.scaleFactor) + '; y: ' + (320 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (0 * this.scaleFactor) + '; y: ' + (320 * this.scaleFactor) + ' } } }',
            graduationItem);
        graduationItem.data.push(selectedAltitudeBug);

        let minimumAltitudeBug = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: altInterface.minimumsState != 0;' +
            'transform: Translate { y: (altInterface.altitude - altInterface.minimum_altitude) * ' + (1.6 * this.scaleFactor) + ' }' +
            'ShapePath {' +
            'fillColor: "transparent";' +
            'strokeColor: "#36C8D2";' +
            'strokeWidth: ' + (5 * this.scaleFactor) + ';' +//20,260 20,273 0,300 20,327 20,340
            'PathMove { x: ' + (20 * this.scaleFactor) + '; y: ' + (260 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (20 * this.scaleFactor) + '; y: ' + (273 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (0 * this.scaleFactor) + '; y: ' + (300 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (20 * this.scaleFactor) + '; y: ' + (327 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (20 * this.scaleFactor) + '; y: ' + (340 * this.scaleFactor) + ' } } }',
            graduationItem);
        graduationItem.data.push(minimumAltitudeBug);
    }

    createGroundLine(_parent) {
        this.groundLine = Qt.createQmlObject('import QtQuick 2.15; Item { transform: Translate { y: altInterface.radarAltitudeTransformValue } }', _parent);
        _parent.data.push(this.groundLine);

        let background = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: 0;' +
            'y: 0;' +
            'width: ' + (200 * this.scaleFactor) + ';' +
            'height: ' + (600 * this.scaleFactor) + ';' +
            'border.width: ' + (4 * this.scaleFactor) + ';' +
            'border.color: "white";' +
            'color: "#654222" }',
            this.groundLine);
        this.groundLine.data.push(background);

        let groundLineItem = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'x: 0;' +
            'y: 0;' +
            'width: ' + (200 * this.scaleFactor) + ';' +
            'height: ' + (600 * this.scaleFactor) + ';' +
            'clip: true }',
            this.groundLine);
        this.groundLine.data.push(groundLineItem);

        for (let i = -5; i <= 25; i++) {
            let line = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: 0;' +
                'y: ' + ((-50 + 30 * i) * this.scaleFactor) + ';' +
                'width: ' + (200 * this.scaleFactor) + ';' +
                'height: ' + (4 * this.scaleFactor) + ';' +
                'transform: Matrix4x4 { matrix: Qt.matrix4x4(1,0,0,0, Math.tan(-Math.PI / 6),1,0,0, 0,0,1,0, 0,0,0,1) }' +
                'color: "white" }',
                groundLineItem);
            groundLineItem.data.push(line);
        }
    }


    createCursorBaseItem(_parent) {
        let cursorBaseItem = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'x: ' + (30 * this.scaleFactor) + ';' +
            'y: ' + (260 * this.scaleFactor) + ';' +
            'width: ' + (100 * this.scaleFactor) + ';' +
            'height: ' + (80 * this.scaleFactor) + ';' +
            'clip: true }',
            _parent);
        _parent.data.push(cursorBaseItem);

        this.digit1Top = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (16 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (-1 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'transform: Translate { y: 0 }' +
            'font.pixelSize: ' + (50 * this.scaleFactor).toFixed(0) + ';' +
            'text: "X" }',
            cursorBaseItem);
        cursorBaseItem.data.push(this.digit1Top);

        this.digit1Bot = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (16 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (57 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'transform: Translate { y: 0 }' +
            'font.pixelSize: ' + (50 * this.scaleFactor).toFixed(0) + ';' +
            'text: "X" }',
            cursorBaseItem);
        cursorBaseItem.data.push(this.digit1Bot);

        this.digit2Top = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (44 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (-1 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'transform: Translate { y: 0 }' +
            'font.pixelSize: ' + (50 * this.scaleFactor).toFixed(0) + ';' +
            'text: "X" }',
            cursorBaseItem);
        cursorBaseItem.data.push(this.digit2Top);

        this.digit2Bot = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (44 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (57 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'transform: Translate { y: 0 }' +
            'font.pixelSize: ' + (50 * this.scaleFactor).toFixed(0) + ';' +
            'text: "X" }',
            cursorBaseItem);
        cursorBaseItem.data.push(this.digit2Bot);

        this.digit3Top = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (72 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (-1 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'transform: Translate { y: 0 }' +
            'font.pixelSize: ' + (50 * this.scaleFactor).toFixed(0) + ';' +
            'text: "X" }',
            cursorBaseItem);
        cursorBaseItem.data.push(this.digit3Top);

        this.digit3Bot = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (72 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (57 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'transform: Translate { y: 0 }' +
            'font.pixelSize: ' + (50 * this.scaleFactor).toFixed(0) + ';' +
            'text: "X" }',
            cursorBaseItem);
        cursorBaseItem.data.push(this.digit3Bot);
    }

    createCursorRotatingItem(_parent) {
        let cursorRotatingItem = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'x: ' + (130 * this.scaleFactor) + ';' +
            'y: ' + (240 * this.scaleFactor) + ';' +
            'width: ' + (70 * this.scaleFactor) + ';' +
            'height: ' + (120 * this.scaleFactor) + ';' +
            'clip: true }',
            _parent);
        _parent.data.push(cursorRotatingItem);

        this.endDigitsGroup = Qt.createQmlObject('import QtQuick 2.15; Item { transform: Translate { y: 0 } }', cursorRotatingItem);
        cursorRotatingItem.data.push(this.endDigitsGroup);

        this.endDigits = [];
        for (let i = -2; i <= 2; i++) {
            let digit = Qt.createQmlObject(
                'import QtQuick 2.15; Text {' +
                'anchors.left: parent.left;' +
                'anchors.leftMargin: ' + (7 * this.scaleFactor) + ';' +
                'anchors.baseline: parent.top;' +
                'anchors.baselineOffset: ' + ((77 + 45 * i) * this.scaleFactor) + ';' +
                'color: "white";' +
                'font.bold: true;' +
                'font.family: "Roboto Mono";' +
                'font.pixelSize: ' + (50 * this.scaleFactor).toFixed(0) + ';' +
                'text: "XX" }',
                this.endDigitsGroup);
            this.endDigits.push(digit);
            this.endDigitsGroup.data.push(digit);
        }
    }

    createVerticalSpeedGroup(_parent) {
        let verticalSpeedGroup = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', _parent);
        _parent.data.push(verticalSpeedGroup);

        let background = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { opacity: 0.25; ShapePath {' +
            'fillColor: "#1A1D21";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (250 * this.scaleFactor) + '; y: ' + (100 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (250 * this.scaleFactor) + '; y: ' + (600 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (325 * this.scaleFactor) + '; y: ' + (600 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (325 * this.scaleFactor) + '; y: ' + (400 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (260 * this.scaleFactor) + '; y: ' + (350 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (325 * this.scaleFactor) + '; y: ' + (300 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (325 * this.scaleFactor) + '; y: ' + (100 * this.scaleFactor) + ' } } }',
            verticalSpeedGroup);
        verticalSpeedGroup.data.push(background);

        let dashes = [-200, -150, -100, -50, 50, 100, 150, 200];
        let height = 3;
        let width = 10;
        let fontSize = 30;

        for (let i = 0; i < dashes.length; i++) {
            let rect = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: ' + (250 * this.scaleFactor) + ';' +
                'y: ' + ((350 - dashes[i] - height / 2) * this.scaleFactor) + ';' +
                'width: ' + (((dashes[i] % 100) == 0 ? 2 * width : width) * this.scaleFactor) + ';' +
                'height: ' + (height * this.scaleFactor) + ';' +
                'color: "white" }',
                verticalSpeedGroup);
            verticalSpeedGroup.data.push(rect);

            if ((dashes[i] % 100) == 0) {
                let text = Qt.createQmlObject(
                    'import QtQuick 2.15; Text {' +
                    'anchors.left: parent.left;' +
                    'anchors.leftMargin: ' + ((250 + 3 * width) * this.scaleFactor) + ';' +
                    'anchors.verticalCenter: parent.top;' +
                    'anchors.verticalCenterOffset: ' + ((350 - dashes[i]) * this.scaleFactor) + ';' +
                    'color: "white";' +
                    'font.family: "Roboto Mono";' +
                    'font.pixelSize: ' + (fontSize * this.scaleFactor).toFixed(0) + ';' +
                    'font.bold: true;' +
                    'text: "' + (dashes[i] / 100) + '" }',
                    verticalSpeedGroup);
                verticalSpeedGroup.data.push(text);
            }
        }

        this.selectedVSBug = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: apInterface.has_ap;' +
            'transform: Translate { y: -Math.max(Math.min(altInterface.referenceVspeed, 2500), -2500) / 10 }' +
            'ShapePath {' +
            'fillColor: "#36C8D2";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (250 * this.scaleFactor) + '; y: ' + (330 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (270 * this.scaleFactor) + '; y: ' + (330 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (270 * this.scaleFactor) + '; y: ' + (335 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (260 * this.scaleFactor) + '; y: ' + (350 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (270 * this.scaleFactor) + '; y: ' + (365 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (270 * this.scaleFactor) + '; y: ' + (370 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (250 * this.scaleFactor) + '; y: ' + (370 * this.scaleFactor) + ' } } }',
            verticalSpeedGroup);
        verticalSpeedGroup.data.push(this.selectedVSBug);

        this.indicator = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { transform: Translate { y: altInterface.vspeedIndicatorTransformValue }}', verticalSpeedGroup);
        verticalSpeedGroup.data.push(this.indicator);

        let indicatorBackground = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "#1A1D21";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (260 * this.scaleFactor) + '; y: ' + (350 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (285 * this.scaleFactor) + '; y: ' + (375 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (380 * this.scaleFactor) + '; y: ' + (375 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (380 * this.scaleFactor) + '; y: ' + (325 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (285 * this.scaleFactor) + '; y: ' + (325 * this.scaleFactor) + ' } }',
            this.indicator);
        this.indicator.data.push(indicatorBackground);

        this.indicatorText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (285 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (360 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (fontSize * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: altInterface.vspeedTextValue }',
            this.indicator);
        this.indicator.data.push(this.indicatorText);

        this.selectedVSBackground = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'visible: apInterface.has_ap;' +
            'x: ' + (250 * this.scaleFactor) + ';' +
            'y: ' + (50 * this.scaleFactor) + ';' +
            'width: ' + (75 * this.scaleFactor) + ';' +
            'height: ' + (50 * this.scaleFactor) + ';' +
            'color: "#1A1D21" }',
            verticalSpeedGroup);
        verticalSpeedGroup.data.push(this.selectedVSBackground);

        this.selectedVSText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'visible: apInterface.has_ap;' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (287.5 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (85 * this.scaleFactor) + ';' +
            'color: "#36C8D2";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (25 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: altInterface.referenceVspeed }',
            verticalSpeedGroup);
        verticalSpeedGroup.data.push(this.selectedVSText);
    }


    update(value) {
        let center = altInterface.center;

        if (this.currentCenterGrad != center)
        {
            this.currentCenterGrad = center;
            for (let i = 0; i < this.graduationTexts.length; i++) {
                this.graduationTexts[i].text = Math.round((3 - i) * 100 + center);
            }
        }
        let endValue = value % 100;
        let endCenter = Math.round(endValue / 10) * 10;
        this.endDigitsGroup.transform[0].y = (endValue - endCenter) * 4.32;
        for (let i = 0; i < this.endDigits.length; i++) {
            let digitValue = Math.round((((2 - i) * 10) + value) % 100 / 10) * 10;
            this.endDigits[i].text = Math.round(Math.abs((digitValue % 100) / 10)) + "0";
        }

        if (Math.abs(value) >= 90) {
            let d3Value = (Math.abs(value) % 1000) / 100;


            if (endValue > 90) {
                this.digit3Bot.text = value < 100 ? "" : Math.floor(d3Value);
                this.digit3Top.text = Math.ceil(d3Value) % 10;

                let translate = (endValue - 90) * 5.472;
                this.digit3Bot.transform[0].y = translate;
                this.digit3Top.transform[0].y = translate;
            }
            else if (endValue < -90) {
                this.digit3Bot.text = Math.ceil(d3Value) % 10;
                this.digit3Top.text = value > -100 ? "" : Math.floor(d3Value);

                let translate = (endValue + 100) * 5.472;
                this.digit3Bot.transform[0].y = translate;
                this.digit3Top.transform[0].y = translate;
            }
            else {
                this.digit3Bot.text = value < 100 ? "" : Math.floor(d3Value);
                this.digit3Top.text = Math.ceil(d3Value) % 10;

                this.digit3Bot.transform[0].y = 0;
                this.digit3Top.transform[0].y = 0;
            }

            if (Math.abs(value) >= 990) {
                let d2Value = (Math.abs(value) % 10000) / 1000;

                if (d3Value > 9) {
                    if (endValue > 90) {
                        this.digit2Bot.text = value < 1000 ? "" : Math.floor(d2Value);
                        this.digit2Top.text = Math.ceil(d2Value) % 10;

                        let translate = (endValue - 90) * 5.472;
                        this.digit2Bot.transform[0].y = translate;
                        this.digit2Top.transform[0].y = translate;
                    }
                    else if (endValue < -90) {
                        this.digit2Bot.text = Math.ceil(d2Value) % 10;
                        this.digit2Top.text = value > -1000 ? "" : Math.floor(d2Value);

                        let translate = (endValue + 100) * 5.472;
                        this.digit2Bot.transform[0].y = translate;
                        this.digit2Top.transform[0].y = translate;
                    }
                    else {
                        this.digit2Bot.text = value < 1000 ? "" : Math.floor(d2Value);
                        this.digit2Top.text = Math.ceil(d2Value) % 10;

                        this.digit2Bot.transform[0].y = 0;
                        this.digit2Top.transform[0].y = 0;
                    }
                }
                else {
                    this.digit2Bot.text = Math.abs(value) < 1000 ? "" : Math.floor(d2Value);
                    this.digit2Top.text = Math.ceil(d2Value) % 10;

                    this.digit2Bot.transform[0].y = 0;
                    this.digit2Top.transform[0].y = 0;
                }

                if (Math.abs(value) >= 9990) {
                    let d1Value = (Math.abs(value) % 100000) / 10000;

                    if(d3Value > 9 && d2Value > 9) {
                        if (endValue > 90) {
                            this.digit1Bot.text = value < 10000 ? "" : Math.floor(d1Value);
                            this.digit1Top.text = Math.ceil(d1Value) % 10;

                            let translate = (endValue - 90) * 5.472;
                            this.digit1Bot.transform[0].y = translate;
                            this.digit1Top.transform[0].y = translate;
                        }
                        else if (endValue < -90) {
                            this.digit1Bot.text = Math.ceil(d1Value) % 10;
                            this.digit1Top.text = value > -10000 ? "" : Math.floor(d1Value);

                            let translate = (endValue + 100) * 5.472;
                            this.digit1Bot.transform[0].y = translate;
                            this.digit1Top.transform[0].y = translate;
                        }
                        else {
                            this.digit1Bot.text = value < 10000 ? "" : Math.floor(d1Value);
                            this.digit1Top.text = Math.ceil(d1Value) % 10;

                            this.digit1Bot.transform[0].y = 0;
                            this.digit1Top.transform[0].y = 0;
                        }
                    }
                    else {
                        this.digit1Bot.text = Math.abs(value) < 10000 ? "" : Math.floor(d1Value);
                        this.digit1Top.text = Math.ceil(d1Value) % 10;

                        this.digit1Bot.transform[0].y = 0;
                        this.digit1Top.transform[0].y = 0;
                    }
                }
                else {
                    this.digit1Bot.transform[0].y = 0;
                    this.digit1Top.transform[0].y = 0;

                    this.digit1Bot.text = value < 0 ? "-" : "";
                    this.digit1Top.text = "";
                }
            }
            else {
                this.digit2Bot.transform[0].y = 0;
                this.digit2Top.transform[0].y = 0;

                this.digit2Bot.text = value < 0 ? "-" : "";
                this.digit1Bot.text = "";
                this.digit1Top.text = "";
                this.digit2Top.text = "";
            }
        }
        else {
            this.digit3Bot.transform[0].y = 0;
            this.digit3Top.transform[0].y = 0;

            this.digit3Bot.text = value < 0 ? "-" : "";
            this.digit2Bot.text = "";
            this.digit1Bot.text = "";
            this.digit1Top.text = "";
            this.digit2Top.text = "";
            this.digit3Top.text = "";
        }
    }



}
