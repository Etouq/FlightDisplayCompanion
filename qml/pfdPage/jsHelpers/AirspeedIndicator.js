class AirspeedIndicator {
    constructor() {
        this.redBegin = 0;
        this.redEnd = 0;
        this.greenBegin = 0;
        this.greenEnd = 0;
        this.flapsBegin = 0;
        this.flapsEnd = 0;
        this.yellowBegin = 0;
        this.yellowEnd = 0;
        this.minValue = 0;
        this.maxValue = 0;
        this.currentCenterGrad = -10000;
        this.nocolor = false;
        this.scaleFactor = 0.96;
        this.airspeedReferenceGroup = null;
        this.selectedSpeedBugValue = 0;
        this.acceleration = NaN;
        this.lastSpeed = null;
    }

    updateColors(_redBegin, _redEnd, _greenBegin, _greenEnd, _flapsBegin, _flapsEnd, _yellowBegin, _yellowEnd, _minValue, _noColor)
    {
        this.redBegin = _redBegin;
        this.redEnd = _redEnd;
        this.greenBegin = _greenBegin;
        this.greenEnd = _greenEnd
        this.flapsBegin = _flapsBegin;
        this.flapsEnd = _flapsEnd;
        this.yellowBegin = _yellowBegin;
        this.yellowEnd = _yellowEnd;
        this.minValue = _minValue;
        this.nocolor = _noColor;
        this.currentCenterGrad = -10000;
    }

    updateMaxValue(_newMax)
    {
        this.maxValue = _newMax;
    }

    completedCallback(_parent) {
        this.createAirspeedReferenceGroup(_parent);

        let background = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: 0;' +
            'y: ' + (50 * this.scaleFactor) + ';' +
            'width: ' + (200 * this.scaleFactor) + ';' +
            'height: ' + (600 * this.scaleFactor) + ';' +
            'color: "#1A1D21";' +
            'opacity: 0.25 }',
            _parent);
        _parent.data.push(background);

        let centerItem = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'x: 0;' +
            'y: ' + (50 * this.scaleFactor) + ';' +
            'width: ' + (250 * this.scaleFactor) + ';' +
            'height: ' + (600 * this.scaleFactor) + ';' +
            'clip: true }',
            _parent);
        _parent.data.push(centerItem);

        this.createCenterGroup(centerItem);

        this.createDashItem(_parent);

        this.selectedSpeedBug = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: apInterface.has_ap;' +
            'transform: Translate { y: (Math.max(iasInterface.airspeed, 20) - iasInterface.refSpeed) * ' + (10 * this.scaleFactor) + ' }' +
            'ShapePath { ' +
            'fillColor: "#36C8D2";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (200 * this.scaleFactor) + '; y: ' + (280 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (180 * this.scaleFactor) + '; y: ' + (280 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (180 * this.scaleFactor) + '; y: ' + (285 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (190 * this.scaleFactor) + '; y: ' + (300 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (180 * this.scaleFactor) + '; y: ' + (315 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (180 * this.scaleFactor) + '; y: ' + (320 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (200 * this.scaleFactor) + '; y: ' + (320 * this.scaleFactor) + ' } } }',
            centerItem);
        centerItem.data.push(this.selectedSpeedBug);

        this.createSpeedBugs(centerItem);

        let cursorParent = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', _parent);
        _parent.data.push(cursorParent);
        this.cursor = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath { ' +
            'fillColor: "#1A1D21";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (200 * this.scaleFactor) + '; y: ' + (350 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (170 * this.scaleFactor) + '; y: ' + (310 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (150 * this.scaleFactor) + '; y: ' + (310 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (150 * this.scaleFactor) + '; y: ' + (290 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (100 * this.scaleFactor) + '; y: ' + (290 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (100 * this.scaleFactor) + '; y: ' + (310 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (0 * this.scaleFactor) + '; y: ' + (310 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (0 * this.scaleFactor) + '; y: ' + (390 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (100 * this.scaleFactor) + '; y: ' + (390 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (100 * this.scaleFactor) + '; y: ' + (410 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (150 * this.scaleFactor) + '; y: ' + (410 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (150 * this.scaleFactor) + '; y: ' + (390 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (170 * this.scaleFactor) + '; y: ' + (390 * this.scaleFactor) + ' } }',
            cursorParent);
        cursorParent.data.push(this.cursor);

        this.trendElement = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (200 * this.scaleFactor) + ';' +
            'y: (Math.min(airspeedTrendValue, 300) + 50) * ' + (this.scaleFactor) + ';' +
            'width: ' + (8 * this.scaleFactor) + ';' +
            'height: Math.abs(airspeedTrendValue - 300) * ' + (this.scaleFactor) + ';' +
            'color: "#D12BC7" }',
            _parent);
        _parent.data.push(this.trendElement);

        this.createBaseCursorItem(_parent);

        this.createRotatingCursorItem(_parent);

        this.bottomBackground = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: 0;' +
            'y: ' + (650 * this.scaleFactor) + ';' +
            'width: ' + (200 * this.scaleFactor) + ';' +
            'height: ' + (50 * this.scaleFactor) + ';' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(this.bottomBackground);

        let tasTasText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (5 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (688 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (35 * this.scaleFactor).toFixed(0) + ';' +
            'text: "TAS" }',
            _parent);
        _parent.data.push(tasTasText);

        this.tasText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.right: parent.left;' +
            'anchors.rightMargin: ' + (-195 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (688 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (35 * this.scaleFactor).toFixed(0) + ';' +
            'text: iasInterface.trueAirspeed + "KT" }',
            _parent);
        _parent.data.push(this.tasText);
    }

    createAirspeedReferenceGroup(_parent) {
        this.airspeedReferenceGroup = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { visible: apInterface.has_ap }', _parent);
        _parent.data.push(this.airspeedReferenceGroup);

        let background = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: 0;' +
            'y: 0;' +
            'width: ' + (200 * this.scaleFactor) + ';' +
            'height: ' + (50 * this.scaleFactor) + ';' +
            'color: "#1A1D21"; z: -1 }',
            this.airspeedReferenceGroup);
        this.airspeedReferenceGroup.data.push(background);

        this.selectedSpeedFixedBug = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "#36C8D2";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (190 * this.scaleFactor) + '; y: ' + (10 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (180 * this.scaleFactor) + '; y: ' + (10 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (180 * this.scaleFactor) + '; y: ' + (20 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (185 * this.scaleFactor) + '; y: ' + (25 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (180 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (180 * this.scaleFactor) + '; y: ' + (40 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (190 * this.scaleFactor) + '; y: ' + (40 * this.scaleFactor) + ' } }',
            this.airspeedReferenceGroup);
        this.airspeedReferenceGroup.data.push(this.selectedSpeedFixedBug);


        this.selectedSpeedText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (20 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (40 * this.scaleFactor) + ';' +
            'color: "#36C8D2";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (45 * this.scaleFactor).toFixed(0) + ';' +
            'text: iasInterface.refSpeed }',
            this.airspeedReferenceGroup);

        this.airspeedReferenceGroup.data.push(this.selectedSpeedText);

    }

    createCenterGroup(_parent) {
        this.centerGroup = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'transform: Translate { y: 0 } }',
            _parent);
        _parent.data.push(this.centerGroup);


        this.gradTexts = [];

        this.redElement = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (175 * this.scaleFactor) + ';' +
            'y: -1;' +
            'width: ' + (25 * this.scaleFactor) + ';' +
            'height: 0;' +
            'color: "red" }',
            this.centerGroup);
        this.centerGroup.data.push(this.redElement);

        this.yellowElement = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (175 * this.scaleFactor) + ';' +
            'y: -1;' +
            'width: ' + (25 * this.scaleFactor) + ';' +
            'height: 0;' +
            'color: "yellow" }',
            this.centerGroup);
        this.centerGroup.data.push(this.yellowElement);

        this.greenElement = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (175 * this.scaleFactor) + ';' +
            'y: -1;' +
            'width: ' + (25 * this.scaleFactor) + ';' +
            'height: 0;' +
            'color: "green" }',
            this.centerGroup);
        this.centerGroup.data.push(this.greenElement);

        this.flapsElement = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (187.5 * this.scaleFactor) + ';' +
            'y: -1;' +
            'width: ' + (12.5 * this.scaleFactor) + ';' +
            'height: 0;' +
            'color: "white" }',
            this.centerGroup);
        this.centerGroup.data.push(this.flapsElement);

        for (let i = -4; i <= 4; i++) {
            let grad = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: ' + (150 * this.scaleFactor) + ';' +
                'y: ' + ((298 + 100 * i) * this.scaleFactor) + ';' +
                'width: ' + (50 * this.scaleFactor) + ';' +
                'height: ' + (4 * this.scaleFactor) + ';' +
                'color: "white" }',
                this.centerGroup);
            this.centerGroup.data.push(grad);
            if (i != 0) {
                let halfGrad = Qt.createQmlObject(
                    'import QtQuick 2.15; Rectangle {' +
                    'x: ' + (175 * this.scaleFactor) + ';' +
                    'y: ' + ((298 + 100 * i + (i < 0 ? 50 : -50)) * this.scaleFactor) + ';' +
                    'width: ' + (25 * this.scaleFactor) + ';' +
                    'height: ' + (4 * this.scaleFactor) + ';' +
                    'color: "black" }',
                    this.centerGroup);
                this.centerGroup.data.push(halfGrad);
            }
            let gradText = Qt.createQmlObject(
                'import QtQuick 2.15; Text {' +
                'anchors.right: parent.left;' +
                'anchors.rightMargin: ' + (-152 * this.scaleFactor) + ';' +
                'anchors.verticalCenter: parent.top;' +
                'anchors.verticalCenterOffset: ' + ((300 + 100 * i) * this.scaleFactor) + ';' +
                'color: "white";' +
                'font.bold: true;' +
                'font.family: "Roboto Mono";' +
                'font.letterSpacing: ' + (12 * this.scaleFactor) + ';' +
                'font.pixelSize: ' + (50 * this.scaleFactor).toFixed(0) + ';' +
                'text: "XXX" }',
                this.centerGroup);
            this.gradTexts.push(gradText);
            this.centerGroup.data.push(gradText);
        }
    }

    createDashItem(_parent) {
        let dashItem = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'x: ' + (175 * this.scaleFactor) + ';' +
            'y: ' + (50 * this.scaleFactor) + ';' +
            'width: ' + (25 * this.scaleFactor) + ';' +
            'height: ' + (600 * this.scaleFactor) + ';' +
            'clip: true }',
            _parent);
        _parent.data.push(dashItem);

        this.startElement = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'transform: Translate { y: 0 } }',
            dashItem);
        dashItem.data.push(this.startElement);

        let startBg = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: 0;' +
            'y: ' + (-935 * this.scaleFactor) + ';' +
            'width: ' + (25 * this.scaleFactor) + ';' +
            'height: ' + (800 * this.scaleFactor) + ';' +
            'color: "white" }',
            this.startElement);
        this.startElement.data.push(startBg);

        for (let i = 0; i <= 32; i++) {
            let redLine = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: 0;' +
                'y: ' + ((-125 - 25 * i) * this.scaleFactor) + ';' +
                'width: ' + (25 * this.scaleFactor) + ';' +
                'height: ' + (12.5 * this.scaleFactor) + ';' +
                'transform: Matrix4x4 { matrix: Qt.matrix4x4(1,0,0,0, Math.tan(-Math.PI / 6),1,0,0, 0,0,1,0, 0,0,0,1) }' +
                'color: "red" }',
                this.startElement);
            this.startElement.data.push(redLine);
        }

        this.endElement = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'transform: Translate { y: 0 } }',
            dashItem);
        dashItem.data.push(this.endElement);

        let endBg = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: 0;' +
            'y: ' + (-900 * this.scaleFactor) + ';' +
            'width: ' + (25 * this.scaleFactor) + ';' +
            'height: ' + (800 * this.scaleFactor) + ';' +
            'color: "white" }',
            this.endElement);
        this.endElement.data.push(endBg);

        for (let i = 0; i <= 32; i++) {
            let redLine = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: 0;' +
                'y: ' + ((-125 - 25 * i) * this.scaleFactor) + ';' +
                'width: ' + (25 * this.scaleFactor) + ';' +
                'height: ' + (12.5 * this.scaleFactor) + ';' +
                'transform: Matrix4x4 { matrix: Qt.matrix4x4(1,0,0,0, Math.tan(-Math.PI / 6),1,0,0, 0,0,1,0, 0,0,0,1) }' +
                'color: "red" }',
                this.endElement);
            this.endElement.data.push(redLine);
        }
    }

    createBaseCursorItem(_parent) {
        let baseCursorItem = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'x: 0;' +
            'y: ' + (310 * this.scaleFactor) + ';' +
            'width: ' + (100 * this.scaleFactor) + ';' +
            'height: ' + (80 * this.scaleFactor) + ';' +
            'clip: true }',
            _parent);
        _parent.data.push(baseCursorItem);

        this.digit1Top = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (28 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (-1 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'transform: Translate { y: 0 }' +
            'font.pixelSize: ' + (50 * this.scaleFactor).toFixed(0) + ';' +
            'text: "-" }',
            baseCursorItem);
        baseCursorItem.data.push(this.digit1Top);

        this.digit1Bot = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (28 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (55 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'transform: Translate { y: 0 }' +
            'font.pixelSize: ' + (50 * this.scaleFactor).toFixed(0) + ';' +
            'text: "-" }',
            baseCursorItem);
        baseCursorItem.data.push(this.digit1Bot);

        this.digit2Top = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (70 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (-1 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'transform: Translate { y: 0 }' +
            'font.pixelSize: ' + (50 * this.scaleFactor).toFixed(0) + ';' +
            'text: "-" }',
            baseCursorItem);
        baseCursorItem.data.push(this.digit2Top);

        this.digit2Bot = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (70 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (55 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'transform: Translate { y: 0 }' +
            'font.pixelSize: ' + (50 * this.scaleFactor).toFixed(0) + ';' +
            'text: "-" }',
            baseCursorItem);
        baseCursorItem.data.push(this.digit2Bot);
    }

    createRotatingCursorItem(_parent) {
        let rotatingCursorItem = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'x: ' + (100 * this.scaleFactor) + ';' +
            'y: ' + (290 * this.scaleFactor) + ';' +
            'width: ' + (70 * this.scaleFactor) + ';' +
            'height: ' + (120 * this.scaleFactor) + ';' +
            'clip: true }',
            _parent);
        _parent.data.push(rotatingCursorItem);

        this.endDigitsGroup = Qt.createQmlObject('import QtQuick 2.15; Item { transform: Translate { y: 0 } }', rotatingCursorItem);
        rotatingCursorItem.data.push(this.endDigitsGroup);

        this.endDigits = [];

        for (let i = -2; i <= 2; i++) {
            let digit = Qt.createQmlObject(
                'import QtQuick 2.15; Text {' +
                'anchors.left: parent.left;' +
                'anchors.leftMargin: ' + (12 * this.scaleFactor) + ';' +
                'anchors.baseline: parent.top;' +
                'anchors.baselineOffset: ' + ((75 + 45 * i) * this.scaleFactor) + ';' +
                'color: "white";' +
                'font.bold: true;' +
                'font.family: "Roboto Mono";' +
                'font.pixelSize: ' + (50 * this.scaleFactor).toFixed(0) + ';' +
                'text: ' + (i === 0 ? '"-"' : '" "') + ' }',
                this.endDigitsGroup);
            this.endDigits.push(digit);
            this.endDigitsGroup.data.push(digit);
        }
    }

    createSpeedBugs(_parent) {

        let speedBugsGroup = Qt.createQmlObject('import QtQuick 2.15; Item {' +
            'transform: Translate { y: Math.max(iasInterface.airspeed, 20) * ' + (10 * this.scaleFactor) + ' } }',
            _parent);
        _parent.data.push(speedBugsGroup);

        let vrRefBug = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: tscBackend.vrActive;' +
            'transform: Translate { y: -tscBackend.vrSpeed * ' + (10 * this.scaleFactor) + ' }' +
            'ShapePath { ' +
            'fillColor: "#1A1D21";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (200 * this.scaleFactor) + '; y: ' + (300 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (210 * this.scaleFactor) + '; y: ' + (315 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (250 * this.scaleFactor) + '; y: ' + (315 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (250 * this.scaleFactor) + '; y: ' + (285 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (210 * this.scaleFactor) + '; y: ' + (285 * this.scaleFactor) + ' } }' +
            'Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (230 * this.scaleFactor) + ';' +
            'anchors.verticalCenter: parent.top;' +
            'anchors.verticalCenterOffset: ' + (300 * this.scaleFactor) + ';' +
            'color: "aqua";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (25 * this.scaleFactor).toFixed(0) + ';' +
            'text: "R" } }',
            speedBugsGroup);
        speedBugsGroup.data.push(vrRefBug);

        let vxRefBug = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: tscBackend.vxActive;' +
            'transform: Translate { y: -tscBackend.vxSpeed * ' + (10 * this.scaleFactor) + ' }' +
            'ShapePath { ' +
            'fillColor: "#1A1D21";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (200 * this.scaleFactor) + '; y: ' + (300 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (210 * this.scaleFactor) + '; y: ' + (315 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (250 * this.scaleFactor) + '; y: ' + (315 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (250 * this.scaleFactor) + '; y: ' + (285 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (210 * this.scaleFactor) + '; y: ' + (285 * this.scaleFactor) + ' } }' +
            'Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (230 * this.scaleFactor) + ';' +
            'anchors.verticalCenter: parent.top;' +
            'anchors.verticalCenterOffset: ' + (300 * this.scaleFactor) + ';' +
            'color: "aqua";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (25 * this.scaleFactor).toFixed(0) + ';' +
            'text: "X" } }',
            speedBugsGroup);
        speedBugsGroup.data.push(vxRefBug);

        let vyRefBug = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: tscBackend.vyActive;' +
            'transform: Translate { y: -tscBackend.vySpeed * ' + (10 * this.scaleFactor) + ' }' +
            'ShapePath { ' +
            'fillColor: "#1A1D21";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (200 * this.scaleFactor) + '; y: ' + (300 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (210 * this.scaleFactor) + '; y: ' + (315 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (250 * this.scaleFactor) + '; y: ' + (315 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (250 * this.scaleFactor) + '; y: ' + (285 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (210 * this.scaleFactor) + '; y: ' + (285 * this.scaleFactor) + ' } }' +
            'Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (230 * this.scaleFactor) + ';' +
            'anchors.verticalCenter: parent.top;' +
            'anchors.verticalCenterOffset: ' + (300 * this.scaleFactor) + ';' +
            'color: "aqua";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (25 * this.scaleFactor).toFixed(0) + ';' +
            'text: "Y" } }',
            speedBugsGroup);
        speedBugsGroup.data.push(vyRefBug);

        let vappRefBug = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: tscBackend.vappActive;' +
            'transform: Translate { y: -tscBackend.vappSpeed * ' + (10 * this.scaleFactor) + ' }' +
            'ShapePath { ' +
            'fillColor: "#1A1D21";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (200 * this.scaleFactor) + '; y: ' + (300 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (210 * this.scaleFactor) + '; y: ' + (315 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (250 * this.scaleFactor) + '; y: ' + (315 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (250 * this.scaleFactor) + '; y: ' + (285 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (210 * this.scaleFactor) + '; y: ' + (285 * this.scaleFactor) + ' } }' +
            'Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (230 * this.scaleFactor) + ';' +
            'anchors.verticalCenter: parent.top;' +
            'anchors.verticalCenterOffset: ' + (300 * this.scaleFactor) + ';' +
            'color: "aqua";' +
            'font.bold: true;' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (25 * this.scaleFactor).toFixed(0) + ';' +
            'text: "AP" } }',
            speedBugsGroup);
        speedBugsGroup.data.push(vappRefBug);



    }

    update(newValue, deltaTime) {
        var value = Math.max(newValue, 20);
        let center = Math.max(Math.round(value / 10) * 10, 60);

        if ((!this.nocolor && (this.minValue > 0 && value < this.minValue)) || (iasInterface.maxSpeed > 0 && value > iasInterface.maxSpeed)) {
            this.cursor.fillColor = "red";
            this.bottomBackground.color = "red";
        }
        else {
            this.cursor.fillColor = "#1A1D21";
            this.bottomBackground.color = "#1A1D21";
        }
        this.centerGroup.transform[0].y = (value - center) * 10 * this.scaleFactor;

        if (!this.nocolor && this.minValue > 0) {
            this.startElement.transform[0].y = (1185.6 - 9.6 * this.minValue + 9.6 * value);
        }
        if (!this.nocolor && iasInterface.maxSpeed > 0) {
            this.endElement.transform[0].y = (Math.min(Math.max(center + 40 - iasInterface.maxSpeed, -10), 80) + value - center) * 9.6;
        }

        if (this.currentCenterGrad != center) {
            this.currentCenterGrad = center;
            for (let j = 0; j < this.gradTexts.length; j++) {
                this.gradTexts[j].text = Math.round((4 - j) * 10 + center);
            }
            if (!this.nocolor) {
                let greenEndVal = Math.min(Math.max(-100, (300 + (-10 * (this.greenEnd - center)))), 700);
                let greenBeginVal = Math.min(Math.max(-100, (300 + (-10 * (this.greenBegin - center)))), 700);
                this.greenElement.y = greenEndVal * this.scaleFactor;
                this.greenElement.height = (greenBeginVal - greenEndVal) * this.scaleFactor;

                let yellowEndVal = Math.min(Math.max(-100, (300 + (-10 * (this.yellowEnd - center)))), 700);
                let yellowBeginVal = Math.min(Math.max(-100, (300 + (-10 * (this.yellowBegin - center)))), 700);
                this.yellowElement.y = yellowEndVal * this.scaleFactor;
                this.yellowElement.height = (yellowBeginVal - yellowEndVal) * this.scaleFactor;

                let redEndVal = Math.min(Math.max(-100, (300 + (-10 * (this.redEnd - center)))), 700);
                let redBeginVal = Math.min(Math.max(-100, (300 + (-10 * (this.redBegin - center)))), 700);
                this.redElement.y = redEndVal * this.scaleFactor;
                this.redElement.height = (redBeginVal - redEndVal) * this.scaleFactor;

                let flapsEndVal = Math.min(Math.max(-100, (300 + (-10 * (this.flapsEnd - center)))), 700);
                let flapsBeginVal = Math.min(Math.max(-100, (300 + (-10 * (this.flapsBegin - center)))), 700);
                this.flapsElement.y = flapsEndVal * this.scaleFactor;
                this.flapsElement.height = (flapsBeginVal - flapsEndVal) * this.scaleFactor;
            }
        }

        let endValue = value % 10;
        let endCenter = Math.round(endValue);
        this.endDigitsGroup.transform[0].y = (endValue - endCenter) * 43.2;
        for (let i = 0; i < this.endDigits.length; i++) {
            if (value == 20) {
                this.endDigits[i].text = (i == 2 ? "-" : " ");
            }
            else {
                this.endDigits[i].text = Math.round((12 - i + endCenter) % 10);
            }
        }
        if (value > 20) {
            let d2Value = (value % 100) / 10;
            this.digit2Bot.text = Math.floor(d2Value);
            this.digit2Top.text = Math.ceil(d2Value) % 10;
            if (endValue > 9) {
                let translate = (endValue - 9) * 52.8;
                this.digit2Bot.transform[0].y = translate;
                this.digit2Top.transform[0].y = translate;
            }
            else {
                this.digit2Bot.transform[0].y = 0;
                this.digit2Top.transform[0].y = 0;
            }

            if (value >= 99) {
                let d1Value = (value % 1000) / 100;
                this.digit1Bot.text = value < 100 ? "" : Math.floor(d1Value);
                this.digit1Top.text = Math.ceil(d1Value) % 10;
                if (endValue > 9 && d2Value > 9) {
                    let translate = (endValue - 9) * 52.8;
                    this.digit1Bot.transform[0].y = translate;
                    this.digit1Top.transform[0].y = translate;
                }
                else {
                    this.digit1Bot.transform[0].y = 0;
                    this.digit1Top.transform[0].y = 0;
                }
            }
            else {
                this.digit1Bot.text = "";
                this.digit1Top.text = "";
            }
        }
        else {
            this.digit2Bot.text = "";
            this.digit2Top.text = "";
            this.digit1Bot.transform[0].y = 0;
            this.digit1Top.transform[0].y = 0;
            this.digit2Bot.transform[0].y = 0;
            this.digit2Top.transform[0].y = 0;
        }

        if (this.acceleration == NaN) {
            this.acceleration = 0;
        }
        if (this.lastSpeed == null) {
            this.lastSpeed = newValue;
        }
        let instantAcceleration = 0;
        if (newValue < 20) {
            this.acceleration = 0;
        }
        else {
            instantAcceleration = (newValue - this.lastSpeed) / (deltaTime / 1000);
        }
        this.acceleration = (Math.max(2000 - deltaTime, 0) * this.acceleration + Math.min(deltaTime, 2000) * instantAcceleration) / 2000;
        this.lastSpeed = newValue;
        let trendValue = Math.min(Math.max(300 - parseFloat(this.acceleration) * 60, 0), 600) + 50;
        this.trendElement.y = Math.min(trendValue, 350) * this.scaleFactor;
        this.trendElement.height = Math.abs(trendValue - 350) * this.scaleFactor;


    }
}
