class HSIndicator {
    constructor() {
        this.isDmeDisplayed = false;
        this.isBearing1Displayed = false;
        this.isBearing2Displayed = false;
        this.crossTrackCurrent = 0;
        this.crossTrackGoal = 0;
        this.sourceIsGps = true;
        this.logic_dmeDisplayed = false;
        this.logic_dmeSource = 1;
        this.logic_cdiSource = 3;
        this.logic_brg1Source = 0;
        this.logic_brg2Source = 0;
        this.logic_navSelected = 0;
        this.scaleFactor = 691.2 / 156;
    }


    completedCallback(_parent) {
        let lines = [-135, -90, -45, 45, 90, 135];
        for (let i = 0; i < lines.length; i++) {
            let line = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: ' + (77.5 * this.scaleFactor) + ';' +
                'y: ' + (8 * this.scaleFactor) + ';' +
                'width: ' + (1 * this.scaleFactor) + ';' +
                'height: ' + (6 * this.scaleFactor) + ';' +
                'transform: Rotation { angle: ' + lines[i] + '; origin.x: ' + (0.5 * this.scaleFactor) + '; origin.y: ' + (57 * this.scaleFactor) + ' }' +
                'color: "white" }',
                _parent);
            _parent.data.push(line);
        }

        this.createTurnRate(_parent);

        this.backgroundCircle = Qt.createQmlObject('import QtQuick 2.15; Item { transform: Rotation { angle: -hsiInterface.rotation; origin.x: ' + (78 * this.scaleFactor) + '; origin.y: ' + (65 * this.scaleFactor) + ' } }', _parent);
        _parent.data.push(this.backgroundCircle);

        this.createBackgroundCircle();

        let staticPartsParent = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', _parent);
        _parent.data.push(staticPartsParent);
        let topTriangle = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "white";' +
            'strokeColor: "black";' +
            'fillRule: ShapePath.WindingFill;' +
            'strokeWidth: ' + (1 * this.scaleFactor) + ';' +
            'joinStyle: ShapePath.MiterJoin;' +
            'PathMove { x: ' + (74 * this.scaleFactor) + '; y: ' + (12 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (82 * this.scaleFactor) + '; y: ' + (12 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (78 * this.scaleFactor) + '; y: ' + (18 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (74 * this.scaleFactor) + '; y: ' + (12 * this.scaleFactor) + ' } }',
            staticPartsParent);
            staticPartsParent.data.push(topTriangle);

        let plane = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "white";' +
            'strokeColor: "transparent";' +
            //'joinStyle: ShapePath.MiterJoin;' +
            'PathMove { x: ' + (72 * this.scaleFactor) + '; y: ' + (65 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (65 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (68 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (76 * this.scaleFactor) + '; y: ' + (69 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (76 * this.scaleFactor) + '; y: ' + (70 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (80 * this.scaleFactor) + '; y: ' + (70 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (80 * this.scaleFactor) + '; y: ' + (69 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (68 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (65 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (84 * this.scaleFactor) + '; y: ' + (65 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (84 * this.scaleFactor) + '; y: ' + (64 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (63 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (61 * this.scaleFactor) + ' }' +
            'PathQuad { x: ' + (77 * this.scaleFactor) + '; y: ' + (61 * this.scaleFactor) + '; controlX: ' + (78 * this.scaleFactor) + '; controlY: ' + (59 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (63 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (72 * this.scaleFactor) + '; y: ' + (64 * this.scaleFactor) + ' } }',
            staticPartsParent);
        staticPartsParent.data.push(plane);


        let bearingRectangle = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (63 * this.scaleFactor) + ';' +
            'y: 0;' +
            'width: ' + (30 * this.scaleFactor) + ';' +
            'height: ' + (12 * this.scaleFactor) + ';' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(bearingRectangle);


        this.bearingText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (78 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (10 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (11 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: hsiInterface.rotationText }',
            _parent);
        _parent.data.push(this.bearingText);

        let headingRectangle = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (15 * this.scaleFactor) + ';' +
            'y: ' + (8 * this.scaleFactor) + ';' +
            'width: ' + (36 * this.scaleFactor) + ';' +
            'height: ' + (8 * this.scaleFactor) + ';' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(headingRectangle);

        let headingLeftText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (17 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (14.4 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (7 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: "HDG" }',
            _parent);
        _parent.data.push(headingLeftText);

        this.headingValue = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (33 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (14.4 * this.scaleFactor) + ';' +
            'color: "#36C8D2";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (7 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: hsiInterface.headingText }',
            _parent);
        _parent.data.push(this.headingValue);

        let courseRectangle = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (105 * this.scaleFactor) + ';' +
            'y: ' + (8 * this.scaleFactor) + ';' +
            'width: ' + (36 * this.scaleFactor) + ';' +
            'height: ' + (8 * this.scaleFactor) + ';' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(courseRectangle);

        let courseLeftText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (107 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (14.4 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (7 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: "CRS" }',
            _parent);
        _parent.data.push(courseLeftText);

        this.courseValue = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (123 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (14.4 * this.scaleFactor) + ';' +
            'color: "#D12BC7";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (7 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: hsiInterface.courseText }',
            _parent);
        _parent.data.push(this.courseValue);

        this.navSourceBg = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (55 * this.scaleFactor) + ';' +
            'y: ' + (49.5 * this.scaleFactor) + ';' +
            'width: ' + (16 * this.scaleFactor) + ';' +
            'height: ' + (7 * this.scaleFactor) + ';' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(this.navSourceBg);

        this.navSource = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (63 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (55 * this.scaleFactor) + ';' +
            'color: hsiInterface.navSource == 0 ? "#D12BC7" : "#10C210";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (6 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: hsiInterface.navSource == 0 ? "GPS" : hsiInterface.navSource == 1 ? "VOR1" : hsiInterface.navSource == 2 ? "LOC1" : hsiInterface.navSource == 3 ? "VOR2" : "LOC2" }',
            _parent);
        _parent.data.push(this.navSource);

        this.crossTrackErrorBg = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'visible: hsiInterface.navSource == 0 && hsiInterface.crossTrackError >= 2;' +
            'x: ' + (57 * this.scaleFactor) + ';' +
            'y: ' + (75.5 * this.scaleFactor) + ';' +
            'width: ' + (40 * this.scaleFactor) + ';' +
            'height: ' + (7 * this.scaleFactor) + ';' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(this.crossTrackErrorBg);

        this.crossTrackError = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'visible: hsiInterface.navSource == 0 && hsiInterface.crossTrackError >= 2;' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (78 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (81 * this.scaleFactor) + ';' +
            'color: "#D12BC7";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (6 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: "XTK " + hsiInterface.crossTrackError.toFixed(2) + "NM" }',
            _parent);
        _parent.data.push(this.crossTrackError);

        this.dme = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { visible: dmeMode != 0; enabled: dmeMode != 0; }', _parent);
        _parent.data.push(this.dme);

        this.createDme();

        this.bearing1FixedGroup = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { visible: bearing1Mode != 0; enabled: bearing1Mode != 0 }', _parent);
        _parent.data.push(this.bearing1FixedGroup);

        this.createBearing1FixedGroup();

        this.bearing2FixedGroup = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { visible: bearing2Mode != 0; enabled: bearing2Mode != 0 }', _parent);
        _parent.data.push(this.bearing2FixedGroup);

        this.createBearing2FixedGroup();

        let dmeTapArea = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'x: ' + (0 * this.scaleFactor) + ';' +
            'y: ' + ((65 - 57 * Math.sin(0)) * this.scaleFactor) + ';' +
            'height: ' + (((65 - 57 * Math.sin(-0.58)) - (65 - 57 * Math.sin(0))) * this.scaleFactor) + ';' +
            'width: ' + ((78 - 57 * Math.cos(-0.58)) * this.scaleFactor) + ';' +
            'TapHandler {' +
            'onTapped: { if (dmeMode >= 2) { dmeMode = 0; } else dmeMode++; } }  ' +
            '  }',
            _parent);
        _parent.data.push(dmeTapArea);

        let bearing1TapArea = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'x: ' + (0 * this.scaleFactor) + ';' +
            'y: ' + ((65 - 57 * Math.sin(-0.6)) * this.scaleFactor) + ';' +
            'height: ' + (((65 - 57 * Math.sin(-1.1)) - (65 - 57 * Math.sin(-0.6))) * this.scaleFactor) + ';' +
            'width: ' + ((78 - 57 * Math.cos(-1.1)) * this.scaleFactor) + ';' +
            'TapHandler {' +
            'onTapped: { if (bearing1Mode >= 4) { bearing1Mode = 0; } else bearing1Mode++; } }  ' +
            '  }',
            _parent);
        _parent.data.push(bearing1TapArea);

        let bearing2TapArea = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'anchors.right: parent.right;' +
            'y: ' + ((65 - 57 * Math.sin(-0.6)) * this.scaleFactor) + ';' +
            'height: ' + (((65 - 57 * Math.sin(-1.1)) - (65 - 57 * Math.sin(-0.6))) * this.scaleFactor) + ';' +
            'width: ' + ((78 - 57 * Math.cos(-1.1)) * this.scaleFactor) + ';' +
            'TapHandler {' +
            'onTapped: { if (bearing2Mode >= 4) { bearing2Mode = 0; } else bearing2Mode++; } }  ' +
            ' }',
            _parent);
        _parent.data.push(bearing2TapArea);

    }

    createTurnRate(_parent) {
        let turnRateBackground = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { opacity: 0.25; ShapePath {' +
            'fillColor: "#1A1D21";' +
            'strokeColor: "transparent";' +
            'PathAngleArc { centerX: ' + (78 * this.scaleFactor) + '; centerY: ' + (65 * this.scaleFactor) + '; radiusX: ' + (55.5 * this.scaleFactor) + '; radiusY: ' + (55.5 * this.scaleFactor) + '; startAngle: 246; sweepAngle: 48 }' +
            'PathAngleArc { centerX: ' + (78 * this.scaleFactor) + '; centerY: ' + (65 * this.scaleFactor) + '; radiusX: ' + (50.5 * this.scaleFactor) + '; radiusY: ' + (50.5 * this.scaleFactor) + '; startAngle: 294; sweepAngle: -48; moveToStart: false } } }',
            _parent);
        _parent.data.push(turnRateBackground);

        let lines = [-18, -9, 9, 18];
        for (let i = 0; i < lines.length; i++) {
            let line = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: ' + (77.5 * this.scaleFactor) + ';' +
                'y: ' + (9.5 * this.scaleFactor) + ';' +
                'width: ' + (1 * this.scaleFactor) + ';' +
                'height: ' + (5 * this.scaleFactor) + ';' +
                'transform: Rotation { angle: ' + lines[i] + '; origin.x: ' + (0.5 * this.scaleFactor) + '; origin.y: ' + (55.5 * this.scaleFactor) + ' }' +
                'color: "white" }',
                _parent);
            _parent.data.push(line);
        }

        let turnRateArc = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { ShapePath {' +
            'fillColor: "#D12BC7";' +
            'strokeColor: "transparent";' +
            'PathAngleArc { centerX: ' + (78 * this.scaleFactor) + '; centerY: ' + (65 * this.scaleFactor) + '; radiusX: ' + (54 * this.scaleFactor) + '; radiusY: ' + (54 * this.scaleFactor) + '; startAngle: 270; sweepAngle: hsiInterface.turnRate }' +
            'PathAngleArc { centerX: ' + (78 * this.scaleFactor) + '; centerY: ' + (65 * this.scaleFactor) + '; radiusX: ' + (52 * this.scaleFactor) + '; radiusY: ' + (52 * this.scaleFactor) + '; startAngle: 270 + hsiInterface.turnRate; sweepAngle: -hsiInterface.turnRate; moveToStart: false } } }',
            _parent);
        _parent.data.push(turnRateArc);

        let leftArrowHead = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { visible: hsiInterface.turnRate <= -24; ShapePath {' +
            'fillColor: "#D12BC7";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + ((78 + 56 * Math.sin(-24 * Math.PI / 180)) * this.scaleFactor) + '; y: ' + ((65 - 56 * Math.cos(-24 * Math.PI / 180)) * this.scaleFactor) + ' }' +
            'PathLine { x: ' + ((78 + 53 * Math.sin(-24 * Math.PI / 180 - 0.1)) * this.scaleFactor) + '; y: ' + ((65 - 53 * Math.cos(-24 * Math.PI / 180 - 0.1)) * this.scaleFactor) + ' }' +
            'PathLine { x: ' + ((78 + 50 * Math.sin(-24 * Math.PI / 180)) * this.scaleFactor) + '; y: ' + ((65 - 50 * Math.cos(-24 * Math.PI / 180)) * this.scaleFactor) + ' } } }',
            _parent);
        _parent.data.push(leftArrowHead);

        let rightArrowHead = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { visible: hsiInterface.turnRate >= 24; ShapePath {' +
            'fillColor: "#D12BC7";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + ((78 + 56 * Math.sin(24 * Math.PI / 180)) * this.scaleFactor) + '; y: ' + ((65 - 56 * Math.cos(24 * Math.PI / 180)) * this.scaleFactor) + ' }' +
            'PathLine { x: ' + ((78 + 53 * Math.sin(24 * Math.PI / 180 + 0.1)) * this.scaleFactor) + '; y: ' + ((65 - 53 * Math.cos(24 * Math.PI / 180 + 0.1)) * this.scaleFactor) + ' }' +
            'PathLine { x: ' + ((78 + 50 * Math.sin(24 * Math.PI / 180)) * this.scaleFactor) + '; y: ' + ((65 - 50 * Math.cos(24 * Math.PI / 180)) * this.scaleFactor) + ' } } }',
            _parent);
        _parent.data.push(rightArrowHead);
    }


    createBackgroundCircle() {
        let circle = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (78 * this.scaleFactor) + ';' +
            'anchors.verticalCenter: parent.top;' +
            'anchors.verticalCenterOffset: ' + (65 * this.scaleFactor) + ';' +
            'width: ' + (100 * this.scaleFactor) + ';' +
            'height: ' + (100 * this.scaleFactor) + ';' +
            'radius: ' + (50 * this.scaleFactor) + ';' +
            'opacity: 0.25;' +
            'color: "#1A1D21" }',
            this.backgroundCircle);
        this.backgroundCircle.data.push(circle);

        for (let i = 0; i < 360; i += 5) {
            let length = (i % 10 == 0) ? 4 : 2;
            let line = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: ' + (77.5 * this.scaleFactor) + ';' +
                'y: ' + (15 * this.scaleFactor) + ';' +
                'width: ' + (1 * this.scaleFactor) + ';' +
                'height: ' + (length * this.scaleFactor) + ';' +
                'transform: Rotation { angle: ' + i + '; origin.x: ' + (0.5 * this.scaleFactor) + '; origin.y: ' + (50 * this.scaleFactor) + ' }' +
                'color: "white" }',
                this.backgroundCircle);
            this.backgroundCircle.data.push(line);
        }

        let texts = ["N", "3", "6", "E", "12", "15", "S", "21", "24", "W", "30", "33"];
        for (let i = 0; i < texts.length; i++) {
            let text = Qt.createQmlObject(
                'import QtQuick 2.15; Text {' +
                'anchors.horizontalCenter: parent.left;' +
                'anchors.horizontalCenterOffset: ' + (78 * this.scaleFactor) + ';' +
                'anchors.verticalCenter: parent.top;' +
                'anchors.verticalCenterOffset: ' + (((i % 3 == 0 ? 12 : 9) + 15) * this.scaleFactor) + ';' +
                'color: "white";' +
                'font.family: "Roboto Mono";' +
                'font.pixelSize: ' + ((i % 3 == 0 ? 15 : 8) * this.scaleFactor).toFixed(0) + ';' +
                'font.bold: true;' +
                'transform: Rotation { angle: ' + (i * 30) + '; origin.x: 0; origin.y: 0 }' +
                'text: "' + texts[i] + '" }',
                this.backgroundCircle);
            this.backgroundCircle.data.push(text);
            text.transform[0].origin.x = 78 * this.scaleFactor - text.x;
            text.transform[0].origin.y = 65 * this.scaleFactor - text.y;
            text.transform[0].angle = i * 30;
        }

        this.headingBug = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'transform: Rotation { angle: hsiInterface.headingBugRotation; origin.x: ' + (78 * this.scaleFactor) + '; origin.y: ' + (65 * this.scaleFactor) + ' }' +
            'ShapePath {' +
            'fillColor: "aqua";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (74 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (75 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (78 * this.scaleFactor) + '; y: ' + (19 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (81 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (82 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (82 * this.scaleFactor) + '; y: ' + (20 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (74 * this.scaleFactor) + '; y: ' + (20 * this.scaleFactor) + ' } } }',
            this.backgroundCircle);
        this.backgroundCircle.data.push(this.headingBug);

        this.innerCircle = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'visible: bearing1Mode != 0 || bearing2Mode != 0;' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (78 * this.scaleFactor) + ';' +
            'anchors.verticalCenter: parent.top;' +
            'anchors.verticalCenterOffset: ' + (65 * this.scaleFactor) + ';' +
            'width: ' + (60.8 * this.scaleFactor) + ';' +
            'height: ' + (60.8 * this.scaleFactor) + ';' +
            'radius: ' + (30.4 * this.scaleFactor) + ';' +
            'border.color: "white";' +
            'border.width: ' + (0.8 * this.scaleFactor) + ';' +
            'color: "transparent" }',
            this.backgroundCircle);
        this.backgroundCircle.data.push(this.innerCircle);

        this.currentTrackIndicator = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'transform: Rotation { angle: hsiInterface.currentTrackAngle; origin.x: ' + (78 * this.scaleFactor) + '; origin.y: ' + (65 * this.scaleFactor) + ' }' +
            'ShapePath {' +
            'fillColor: "#D12BC7";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (78 * this.scaleFactor) + '; y: ' + (11 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (80 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (78 * this.scaleFactor) + '; y: ' + (19 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (76 * this.scaleFactor) + '; y: ' + (15 * this.scaleFactor) + ' } } }',
            this.backgroundCircle);
        this.backgroundCircle.data.push(this.currentTrackIndicator);

        this.bearing1 = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: bearing1Mode == 1 ? hsiBrgInterface.showNav1Bearing : bearing1Mode == 2 ? hsiBrgInterface.showNav2Bearing : bearing1Mode == 3 ? true : bearing1Mode == 4 ? hsiBrgInterface.showAdfBearing : false;' +
            'enabled: bearing1Mode == 1 ? hsiBrgInterface.showNav1Bearing : bearing1Mode == 2 ? hsiBrgInterface.showNav2Bearing : bearing1Mode == 3 ? true : bearing1Mode == 4 ? hsiBrgInterface.showAdfBearing : false;' +
            'transform: Rotation { angle: bearing1Mode == 1 ? (180 + hsiBrgInterface.nav1Bearing) % 360 : bearing1Mode == 2 ? (180 + hsiBrgInterface.nav2Bearing) % 360 : bearing1Mode == 4 ? (hsiBrgInterface.adfBearing + hsiInterface.rotation) % 360 : hsiBrgInterface.gpsBearing;' +
            'origin.x: ' + (78 * this.scaleFactor) + '; origin.y: ' + (65 * this.scaleFactor) + ' }' +
            'ShapePath {' +
            'fillColor: "transparent";' +
            'strokeColor: "#36C8D2";' +
            'strokeWidth: ' + (1 * this.scaleFactor) + ';' +
            'PathMove { x: ' + (78 * this.scaleFactor) + '; y: ' + (111 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (78 * this.scaleFactor) + '; y: ' + (95 * this.scaleFactor) + ' }' +
            'PathMove { x: ' + (78 * this.scaleFactor) + '; y: ' + (19 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (78 * this.scaleFactor) + '; y: ' + (35 * this.scaleFactor) + ' }' +
            'PathMove { x: ' + (78 * this.scaleFactor) + '; y: ' + (23 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (85 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathMove { x: ' + (78 * this.scaleFactor) + '; y: ' + (23 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (71 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' } } }',
            this.backgroundCircle);
        this.backgroundCircle.data.push(this.bearing1);

        this.bearing2 = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: bearing2Mode == 1 ? hsiBrgInterface.showNav1Bearing : bearing2Mode == 2 ? hsiBrgInterface.showNav2Bearing : bearing2Mode == 3 ? true : bearing2Mode == 4 ? hsiBrgInterface.showAdfBearing : false;' +
            'enabled: bearing2Mode == 1 ? hsiBrgInterface.showNav1Bearing : bearing2Mode == 2 ? hsiBrgInterface.showNav2Bearing : bearing2Mode == 3 ? true : bearing2Mode == 4 ? hsiBrgInterface.showAdfBearing : false;' +
            'transform: Rotation { angle: bearing2Mode == 1 ? (180 + hsiBrgInterface.nav1Bearing) % 360 : bearing2Mode == 2 ? (180 + hsiBrgInterface.nav2Bearing) % 360 : bearing2Mode == 4 ? (hsiBrgInterface.adfBearing + hsiInterface.rotation) % 360 : hsiBrgInterface.gpsBearing;' +
            'origin.x: ' + (78 * this.scaleFactor) + '; origin.y: ' + (65 * this.scaleFactor) + ' }' +
            'ShapePath {' +
            'fillColor: "transparent";' +
            'strokeColor: "#36C8D2";' +
            'strokeWidth: ' + (1 * this.scaleFactor) + ';' +
            'PathMove { x: ' + (78 * this.scaleFactor) + '; y: ' + (111 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (78 * this.scaleFactor) + '; y: ' + (107 * this.scaleFactor) + ' }' +
            'PathMove { x: ' + (75 * this.scaleFactor) + '; y: ' + (95 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (75 * this.scaleFactor) + '; y: ' + (105 * this.scaleFactor) + ' }' +
            'PathQuad { x: ' + (81 * this.scaleFactor) + '; y: ' + (105 * this.scaleFactor) + '; controlX: ' + (78 * this.scaleFactor) + '; controlY: ' + (111 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (81 * this.scaleFactor) + '; y: ' + (95 * this.scaleFactor) + ' }' +
            'PathMove { x: ' + (78 * this.scaleFactor) + '; y: ' + (19 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (78 * this.scaleFactor) + '; y: ' + (23 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (85 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathMove { x: ' + (78 * this.scaleFactor) + '; y: ' + (23 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (71 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathMove { x: ' + (75 * this.scaleFactor) + '; y: ' + (26 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (75 * this.scaleFactor) + '; y: ' + (35 * this.scaleFactor) + ' }' +
            'PathMove { x: ' + (81 * this.scaleFactor) + '; y: ' + (26 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (81 * this.scaleFactor) + '; y: ' + (35 * this.scaleFactor) + ' } } }',
            this.backgroundCircle);
        this.backgroundCircle.data.push(this.bearing2);

        this.createCourse();
    }

    createCourse()
    {
        this.course = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { transform: Rotation { angle: hsiInterface.course; origin.x: ' + (78 * this.scaleFactor) + '; origin.y: ' + (65 * this.scaleFactor) + ' } }', this.backgroundCircle);
        this.backgroundCircle.data.push(this.course);

        this.beginArrow = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: !(hsiInterface.navSource == 3 || hsiInterface.navSource == 4);' +
            'enabled: !(hsiInterface.navSource == 3 || hsiInterface.navSource == 4);' +
            'ShapePath {' +
            'fillColor: hsiInterface.navSource == 0 ? "#D12BC7" : "#10C210";' +
            'strokeColor: "transparent";' +
            'fillRule: ShapePath.WindingFill;' +
            'joinStyle: ShapePath.MiterJoin;' +
            'PathMove { x: ' + (79 * this.scaleFactor) + '; y: ' + (111 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (111 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (90 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (90 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (111 * this.scaleFactor) + ' } } }',
            this.course);
        this.course.data.push(this.beginArrow);

        this.beginArrowStroke = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: (hsiInterface.navSource == 3 || hsiInterface.navSource == 4);' +
            'enabled: (hsiInterface.navSource == 3 || hsiInterface.navSource == 4);' +
            'ShapePath {' +
            'fillColor: "transparent";' +
            'strokeColor: "#10C210";' +
            'strokeWidth: ' + (this.scaleFactor) + ';' +
            'fillRule: ShapePath.WindingFill;' +
            'joinStyle: ShapePath.MiterJoin;' +
            'PathMove { x: ' + (79 * this.scaleFactor) + '; y: ' + (111 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (111 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (90 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (90 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (111 * this.scaleFactor) + ' } } }',
            this.course);
        this.course.data.push(this.beginArrowStroke);


        this.fromIndicator = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { visible: hsiInterface.toFrom == 2; ShapePath {' +
            'fillColor: hsiInterface.toFrom == 2 ? (hsiInterface.navSource == 0 ? "#D12BC7" : "#10C210") : "#10C210";' +
            'fillRule: ShapePath.WindingFill;' +
            'strokeColor: "black";' +
            'strokeWidth: ' + (0.2 * this.scaleFactor) + ';' +
            'joinStyle: ShapePath.MiterJoin;' +
            'PathMove { x: ' + (74 * this.scaleFactor) + '; y: ' + (90 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (82 * this.scaleFactor) + '; y: ' + (90 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (78 * this.scaleFactor) + '; y: ' + (95 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (74 * this.scaleFactor) + '; y: ' + (90 * this.scaleFactor) + ' } } }',
            this.course);
        this.course.data.push(this.fromIndicator);

        this.CDI = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: hsiInterface.displayDeviation && !(hsiInterface.navSource == 3 || hsiInterface.navSource == 4);' +
            'enabled: hsiInterface.displayDeviation && !(hsiInterface.navSource == 3 || hsiInterface.navSource == 4);' +
            'transform: Translate { x: hsiInterface.courseDeviation * ' + this.scaleFactor + ' }' +
            'ShapePath {' +
            'fillColor: hsiInterface.navSource == 0 ? "#D12BC7" : "#10C210";' +
            'strokeColor: "transparent";' +
            'fillRule: ShapePath.WindingFill;' +
            'joinStyle: ShapePath.MiterJoin;' +
            'PathMove { x: ' + (77 * this.scaleFactor) + '; y: ' + (89.5 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (89.5 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (40.5 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (40.5 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (89.5 * this.scaleFactor) + ' } } }',
            this.course);
        this.course.data.push(this.CDI);

        this.StrokeCDI = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: hsiInterface.displayDeviation && (hsiInterface.navSource == 3 || hsiInterface.navSource == 4);' +
            'enabled: hsiInterface.displayDeviation && (hsiInterface.navSource == 3 || hsiInterface.navSource == 4);' +
            'transform: Translate { x: hsiInterface.courseDeviation * ' + this.scaleFactor + ' }' +
            'ShapePath {' +
            'fillColor: "transparent";' +
            'strokeColor: "#10C210";' +
            'strokeWidth: ' + (this.scaleFactor) + ';' +
            'fillRule: ShapePath.WindingFill;' +
            'joinStyle: ShapePath.MiterJoin;' +
            'PathMove { x: ' + (77 * this.scaleFactor) + '; y: ' + (89.5 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (89.5 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (40.5 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (40.5 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (89.5 * this.scaleFactor) + ' } } }',
            this.course);
        this.course.data.push(this.StrokeCDI);

        this.endArrow = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { ' +
            'visible: !(hsiInterface.navSource == 3 || hsiInterface.navSource == 4);' +
            'enabled: !(hsiInterface.navSource == 3 || hsiInterface.navSource == 4);' +
            'ShapePath {' +
            'fillColor: hsiInterface.navSource == 0 ? "#D12BC7" : "#10C210";' +
            'strokeColor: "transparent";' +
            'fillRule: ShapePath.WindingFill;' +
            'joinStyle: ShapePath.MiterJoin;' +
            'PathMove { x: ' + (79 * this.scaleFactor) + '; y: ' + (40 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (40 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (73 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (78 * this.scaleFactor) + '; y: ' + (19 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (83 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (40 * this.scaleFactor) + ' } } }',
            this.course);
        this.course.data.push(this.endArrow);

        this.endArrowStroke = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'visible: (hsiInterface.navSource == 3 || hsiInterface.navSource == 4);' +
            'enabled: (hsiInterface.navSource == 3 || hsiInterface.navSource == 4);' +
            'ShapePath {' +
            'fillColor: "transparent";' +
            'strokeColor: "#10C210";' +
            'strokeWidth: ' + (this.scaleFactor) + ';' +
            'fillRule: ShapePath.WindingFill;' +
            'joinStyle: ShapePath.MiterJoin;' +
            'PathMove { x: ' + (79 * this.scaleFactor) + '; y: ' + (40 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (40 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (77 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (73 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (78 * this.scaleFactor) + '; y: ' + (19 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (83 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (79 * this.scaleFactor) + '; y: ' + (40 * this.scaleFactor) + ' } } }',
            this.course);
        this.course.data.push(this.endArrowStroke);


        this.toIndicator = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { visible: hsiInterface.toFrom == 1; ShapePath {' +
            'fillColor: hsiInterface.toFrom == 1 ? (hsiInterface.navSource == 0 ? "#D12BC7" : "#10C210") : "#10C210";' +
            'strokeColor: "black";' +
            'strokeWidth: ' + (0.2 * this.scaleFactor) + ';' +
            'joinStyle: ShapePath.MiterJoin;' +
            'PathMove { x: ' + (74 * this.scaleFactor) + '; y: ' + (40 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (82 * this.scaleFactor) + '; y: ' + (40 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (78 * this.scaleFactor) + '; y: ' + (35 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (74 * this.scaleFactor) + '; y: ' + (40 * this.scaleFactor) + ' } } }',
            this.course);
        this.course.data.push(this.toIndicator);

        let circlePosition = [-20, -10, 10, 20];
        for (let i = 0; i < circlePosition.length; i++) {
            let CDICircle = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'anchors.horizontalCenter: parent.left;' +
                'anchors.horizontalCenterOffset: ' + ((78 + circlePosition[i]) * this.scaleFactor) + ';' +
                'anchors.verticalCenter: parent.top;' +
                'anchors.verticalCenterOffset: ' + (65 * this.scaleFactor) + ';' +
                'width: ' + (5 * this.scaleFactor) + ';' +
                'height: ' + (5 * this.scaleFactor) + ';' +
                'radius: ' + (2.5 * this.scaleFactor) + ';' +
                'border.width: ' + (1 * this.scaleFactor) + ';' +
                'border.color: "white";' +
                'color: "transparent" }',
                this.course);
            this.course.data.push(CDICircle);
        }
    }

    createDme()
    {

        let beginX = 78 - 57 * Math.cos(0);
        let beginY = 65 - 57 * Math.sin(0);
        let endX = 78 - 57 * Math.cos(-0.58);
        let endY = 65 - 57 * Math.sin(-0.58);



        let topLeftZone = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "#1A1D21";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (beginX * this.scaleFactor) + '; y: ' + (beginY * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (0 * this.scaleFactor) + '; y: ' + (beginY * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (0 * this.scaleFactor) + '; y: ' + (endY * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (endX * this.scaleFactor) + '; y: ' + (endY * this.scaleFactor) + ' }' +
            'PathArc { radiusX: ' + (57 * this.scaleFactor) + '; radiusY: ' + (57 * this.scaleFactor) + '; direction: PathArc.Clockwise; x: ' + (beginX * this.scaleFactor) + '; y: ' + (beginY * this.scaleFactor) + ' } }',
            this.dme);
        this.dme.data.push(topLeftZone);

        let dmeText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (1 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (72 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (6 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: "DME" }',
            this.dme);
        this.dme.data.push(dmeText);

        this.dmeSource = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (1 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (79 * this.scaleFactor) + ';' +
            'color: "#36C8D2";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (6 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: dmeMode == 1 ? "NAV1" : "NAV2" }',
            this.dme);
        this.dme.data.push(this.dmeSource);

        this.dmeIdent = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (1 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (86 * this.scaleFactor) + ';' +
            'color: "#36C8D2";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (6 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: dmeMode == 1 ? hsiBrgInterface.nav1Freq : hsiBrgInterface.nav2Freq }',
            this.dme);
        this.dme.data.push(this.dmeIdent);

        this.dmeDistance = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (1 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (93 * this.scaleFactor) + ';' +
            'color: "#36C8D2";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (6 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: dmeMode == 1 ? hsiBrgInterface.nav1Dme : hsiBrgInterface.nav2Dme }',
            this.dme);
        this.dme.data.push(this.dmeDistance);


    }

    createBearing1FixedGroup() {
        let beginX = 78 - 57 * Math.cos(-0.6);
        let beginY = 65 - 57 * Math.sin(-0.6);
        let endX = 78 - 57 * Math.cos(-1.1);
        let endY = 65 - 57 * Math.sin(-1.1);
        let botLeftZone = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "#1A1D21";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (beginX * this.scaleFactor) + '; y: ' + (beginY * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (0 * this.scaleFactor) + '; y: ' + (beginY * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (0 * this.scaleFactor) + '; y: ' + (endY * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (endX * this.scaleFactor) + '; y: ' + (endY * this.scaleFactor) + ' }' +
            'PathArc { radiusX: ' + (57 * this.scaleFactor) + '; radiusY: ' + (57 * this.scaleFactor) + '; direction: PathArc.Clockwise; x: ' + (beginX * this.scaleFactor) + '; y: ' + (beginY * this.scaleFactor) + ' } }',
            this.bearing1FixedGroup);
        this.bearing1FixedGroup.data.push(botLeftZone);

        this.bearing1Distance = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (1 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (103 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (6 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: bearing1Mode == 1 ? hsiBrgInterface.nav1Distance : bearing1Mode == 2 ? hsiBrgInterface.nav2Distance : bearing1Mode == 3 ? hsiBrgInterface.gpsDistance : "" }',
            this.bearing1FixedGroup);
        this.bearing1FixedGroup.data.push(this.bearing1Distance);

        this.bearing1Ident = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (1 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (109 * this.scaleFactor) + ';' +
            'color: "#36C8D2";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (6 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: bearing1Mode == 1 ? hsiBrgInterface.nav1Ident : bearing1Mode == 2 ? hsiBrgInterface.nav2Ident : bearing1Mode == 3 ? hsiBrgInterface.gpsIdent : hsiBrgInterface.adfIdent }',
            this.bearing1FixedGroup);
        this.bearing1FixedGroup.data.push(this.bearing1Ident);

        this.bearing1Source = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (1 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (115 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (6 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: bearing1Mode == 1 ? "NAV1" : bearing1Mode == 2 ? "NAV2" : bearing1Mode == 3 ? "GPS" : "ADF" }',
            this.bearing1FixedGroup);
        this.bearing1FixedGroup.data.push(this.bearing1Source);

        let pointer1Main = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (23 * this.scaleFactor) + ';' +
            'y: ' + (111.875 * this.scaleFactor) + ';' +
            'width: ' + (15 * this.scaleFactor) + ';' +
            'height: ' + (0.25 * this.scaleFactor) + ';' +
            'color: "#36C8D2" }',
            this.bearing1FixedGroup);
        this.bearing1FixedGroup.data.push(pointer1Main);

        let pointer1Top = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (25 * this.scaleFactor) + ';' +
            'y: ' + (111.875 * this.scaleFactor) + ';' +
            'width: ' + (4 * this.scaleFactor) + ';' +
            'height: ' + (0.25 * this.scaleFactor) + ';' +
            'transform: Rotation { angle: -45; origin.x: 0; origin.y: ' + (0.125 * this.scaleFactor) + ' }' +
            'color: "#36C8D2" }',
            this.bearing1FixedGroup);
        this.bearing1FixedGroup.data.push(pointer1Top);

        let pointer1Bot = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (25 * this.scaleFactor) + ';' +
            'y: ' + (111.875 * this.scaleFactor) + ';' +
            'width: ' + (4 * this.scaleFactor) + ';' +
            'height: ' + (0.25 * this.scaleFactor) + ';' +
            'transform: Rotation { angle: 45; origin.x: 0; origin.y: ' + (0.125 * this.scaleFactor) + ' }' +
            'color: "#36C8D2" }',
            this.bearing1FixedGroup);
        this.bearing1FixedGroup.data.push(pointer1Bot);


    }

    createBearing2FixedGroup() {
        let beginX = 78 - 57 * Math.cos(Math.PI + 0.6);
        let beginY = 65 - 57 * Math.sin(Math.PI + 0.6);
        let endX = 78 - 57 * Math.cos(Math.PI + 1.1);
        let endY = 65 - 57 * Math.sin(Math.PI + 1.1);
        let botRightZone = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "#1A1D21";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (beginX * this.scaleFactor) + '; y: ' + (beginY * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (156 * this.scaleFactor) + '; y: ' + (beginY * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (156 * this.scaleFactor) + '; y: ' + (endY * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (endX * this.scaleFactor) + '; y: ' + (endY * this.scaleFactor) + ' }' +
            'PathArc { radiusX: ' + (57 * this.scaleFactor) + '; radiusY: ' + (57 * this.scaleFactor) + '; direction: PathArc.Counterclockwise; x: ' + (beginX * this.scaleFactor) + '; y: ' + (beginY * this.scaleFactor) + ' } }',
            this.bearing2FixedGroup);
        this.bearing2FixedGroup.data.push(botRightZone);

        this.bearing2Distance = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.right: parent.left;' +
            'anchors.rightMargin: ' + (-155 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (103 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (6 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: bearing2Mode == 1 ? hsiBrgInterface.nav1Distance : bearing2Mode == 2 ? hsiBrgInterface.nav2Distance : bearing2Mode == 3 ? hsiBrgInterface.gpsDistance : "" }',
            this.bearing2FixedGroup);
        this.bearing2FixedGroup.data.push(this.bearing2Distance);

        this.bearing2Ident = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.right: parent.left;' +
            'anchors.rightMargin: ' + (-155 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (109 * this.scaleFactor) + ';' +
            'color: "#36C8D2";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (6 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: bearing2Mode == 1 ? hsiBrgInterface.nav1Ident : bearing2Mode == 2 ? hsiBrgInterface.nav2Ident : bearing2Mode == 3 ? hsiBrgInterface.gpsIdent : hsiBrgInterface.adfIdent }',
            this.bearing2FixedGroup);
        this.bearing2FixedGroup.data.push(this.bearing2Ident);

        this.bearing2Source = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.right: parent.left;' +
            'anchors.rightMargin: ' + (-155 * this.scaleFactor) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (115 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (6 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: bearing2Mode == 1 ? "NAV1" : bearing2Mode == 2 ? "NAV2" : bearing2Mode == 3 ? "GPS" : "ADF" }',
            this.bearing2FixedGroup);
        this.bearing2FixedGroup.data.push(this.bearing2Source);

        let pointer2 = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "transparent";' +
            'strokeColor: "#36C8D2";' +
            'strokeWidth: ' + (0.5 * this.scaleFactor) + ';' +
            'PathMove { x: ' + (118 * this.scaleFactor) + '; y: ' + (112 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (120 * this.scaleFactor) + '; y: ' + (112 * this.scaleFactor) + ' }' +
            'PathMove { x: ' + (133 * this.scaleFactor) + '; y: ' + (112 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (131 * this.scaleFactor) + '; y: ' + (112 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (128 * this.scaleFactor) + '; y: ' + (115 * this.scaleFactor) + ' }' +
            'PathMove { x: ' + (131 * this.scaleFactor) + '; y: ' + (112 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (128 * this.scaleFactor) + '; y: ' + (109 * this.scaleFactor) + ' }' +
            'PathMove { x: ' + (129.5 * this.scaleFactor) + '; y: ' + (113.5 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (121 * this.scaleFactor) + '; y: ' + (113.5 * this.scaleFactor) + ' }' +
            'PathQuad { x: ' + (121 * this.scaleFactor) + '; y: ' + (110.5 * this.scaleFactor) + '; controlX: ' +  (118 * this.scaleFactor) + '; controlY: ' +  (112 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (129.5 * this.scaleFactor) + '; y: ' + (110.5 * this.scaleFactor) + ' } }',
            this.bearing2FixedGroup);
        this.bearing2FixedGroup.data.push(pointer2);


    }




}
