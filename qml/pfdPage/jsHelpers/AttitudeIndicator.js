class AttitudeIndicator {
    constructor() {
        this.bankSizeRatio = -24;
        this.horizonTopColor = "#00569d";
        this.horizonBottomColor = "#48432e";
        this.scaleFactor = 1.44;
    }

    buildGraduations() {
        let maxDash = 80;
        let fullPrecisionLowerLimit = -20;
        let fullPrecisionUpperLimit = 20;
        let halfPrecisionLowerLimit = -30;
        let halfPrecisionUpperLimit = 45;
        let unusualAttitudeLowerLimit = -30;
        let unusualAttitudeUpperLimit = 50;
        let bigWidth = 120;
        let bigHeight = 3;
        let mediumWidth = 60;
        let mediumHeight = 3;
        let smallWidth = 40;
        let smallHeight = 2;
        let fontSize = 20;
        let angle = -maxDash;
        let nextAngle;
        let width;
        let height;
        let text;

        while (angle <= maxDash) {
            if (angle % 10 == 0) {
                width = bigWidth;
                height = bigHeight;
                text = true;
                if (angle >= fullPrecisionLowerLimit && angle < fullPrecisionUpperLimit) {
                    nextAngle = angle + 2.5;
                }
                else if (angle >= halfPrecisionLowerLimit && angle < halfPrecisionUpperLimit) {
                    nextAngle = angle + 5;
                }
                else {
                    nextAngle = angle + 10;
                }
            }
            else {
                if (angle % 5 == 0) {
                    width = mediumWidth;
                    height = mediumHeight;
                    text = true;
                    if (angle >= fullPrecisionLowerLimit && angle < fullPrecisionUpperLimit) {
                        nextAngle = angle + 2.5;
                    }
                    else {
                        nextAngle = angle + 5;
                    }
                }
                else {
                    width = smallWidth;
                    height = smallHeight;
                    nextAngle = angle + 2.5;
                    text = false;
                }
            }
            if (angle !== 0) {
                let rect = Qt.createQmlObject(
                    'import QtQuick 2.15; Rectangle {' +
                    'color: "white";' +
                    'x: ' + ((115 - width / 2) * this.scaleFactor) + ';' +
                    'y: ' + ((130 + this.bankSizeRatio * angle - height / 2) * this.scaleFactor) + ';' +
                    'width: ' + (width * this.scaleFactor) + ';' +
                    'height: ' + (height * this.scaleFactor) + ' }',
                    this.attitude_pitch);
                this.attitude_pitch.data.push(rect);
                if (text) {
                    let leftText = Qt.createQmlObject(
                        'import QtQuick 2.15; Text {' +
                        'anchors.right: parent.left;' +
                        'anchors.rightMargin: ' + (-(115 - width / 2 - 5) * this.scaleFactor) + ';' +
                        'anchors.verticalCenter: parent.top;' +
                        'anchors.verticalCenterOffset: ' + ((130 + this.bankSizeRatio * angle) * this.scaleFactor) + ';' +
                        'font.pixelSize: ' + (fontSize * this.scaleFactor).toFixed(0) + ';' +
                        'font.bold: true;' +
                        'font.family: "Roboto Mono";' +
                        'color: "white";' +
                        'text: "' + Math.abs(angle) + '" }',
                        this.attitude_pitch);
                    this.attitude_pitch.data.push(leftText);

                    let rightText = Qt.createQmlObject(
                        'import QtQuick 2.15; Text {' +
                        'anchors.left: parent.left;' +
                        'anchors.leftMargin: ' + ((115 + width / 2 + 5) * this.scaleFactor) + ';' +
                        'anchors.verticalCenter: parent.top;' +
                        'anchors.verticalCenterOffset: ' + ((130 + this.bankSizeRatio * angle) * this.scaleFactor) + ';' +
                        'font.pixelSize: ' + (fontSize * this.scaleFactor).toFixed(0) + ';' +
                        'font.bold: true;' +
                        'font.family: "Roboto Mono";' +
                        'color: "white";' +
                        'text: "' + Math.abs(angle) + '" }',
                        this.attitude_pitch);
                    this.attitude_pitch.data.push(rightText);
                }
                if (angle < unusualAttitudeLowerLimit) {
                    let chevron = Qt.createQmlObject(
                        'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
                        'fillColor: "red";' +
                        'strokeColor: "transparent";' +
                        'PathMove { x: ' + ((115 - smallWidth / 2) * this.scaleFactor) + '; y: ' + ((130 + this.bankSizeRatio * nextAngle - bigHeight / 2) * this.scaleFactor) + ' }' +
                        'PathLine { relativeX: ' + (smallWidth * this.scaleFactor) + '; relativeY: 0 }' +
                        'PathLine { x: ' + ((115 + bigWidth / 2) * this.scaleFactor) + '; y: ' + ((130 + this.bankSizeRatio * angle - bigHeight / 2) * this.scaleFactor) + ' }' +
                        'PathLine { relativeX: ' + (-smallWidth * this.scaleFactor) + '; relativeY: 0 }' +
                        'PathLine { x: ' + (115 * this.scaleFactor) + '; y: ' + ((130 + this.bankSizeRatio * nextAngle + 20) * this.scaleFactor) + ' }' +
                        'PathLine { x: ' + ((115 - bigWidth / 2 + smallWidth) * this.scaleFactor) + '; y: ' + ((130 + this.bankSizeRatio * angle - bigHeight / 2) * this.scaleFactor) + ' }' +
                        'PathLine { relativeX: ' + (-smallWidth * this.scaleFactor) + '; relativeY: 0 } }',
                        this.attitude_pitch);
                    this.attitude_pitch.data.push(chevron);
                }
                if (angle >= unusualAttitudeUpperLimit && nextAngle <= maxDash) {
                    let chevron = Qt.createQmlObject(
                        'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
                        'fillColor: "red";' +
                        'strokeColor: "transparent";' +
                        'PathMove { x: ' + ((115 - smallWidth / 2) * this.scaleFactor) + '; y: ' + ((130 + this.bankSizeRatio * angle - bigHeight / 2) * this.scaleFactor) + ' }' +
                        'PathLine { relativeX: ' + (smallWidth * this.scaleFactor) + '; relativeY: 0 }' +
                        'PathLine { x: ' + ((115 + bigWidth / 2) * this.scaleFactor) + '; y: ' + ((130 + this.bankSizeRatio * nextAngle + bigHeight / 2) * this.scaleFactor) + ' }' +
                        'PathLine { relativeX: ' + (-smallWidth * this.scaleFactor) + '; relativeY: 0 }' +
                        'PathLine { x: ' + (115 * this.scaleFactor) + '; y: ' + ((130 + this.bankSizeRatio * angle - 20) * this.scaleFactor) + ' }' +
                        'PathLine { x: ' + ((115 - bigWidth / 2 + smallWidth) * this.scaleFactor) + '; y: ' + ((130 + this.bankSizeRatio * nextAngle + bigHeight / 2) * this.scaleFactor) + ' }' +
                        'PathLine { relativeX: ' + (-smallWidth * this.scaleFactor) + '; relativeY: 0 } }',
                        this.attitude_pitch);
                    this.attitude_pitch.data.push(chevron);
                }
            }
            angle = nextAngle;
        }
    }

    completedCallback(_parent) {
        this.horizonTop = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (-800 * this.scaleFactor) + ';' +
            'y: ' + (-800 * this.scaleFactor) + ';' +
            'width: ' + (2000 * this.scaleFactor) + ';' +
            'height: ' + (2000 * this.scaleFactor) + ';' +
            'color: "' + this.horizonTopColor + '" }',
            _parent);
        _parent.data.push(this.horizonTop);

        this.bottomPart = Qt.createQmlObject(
            'import QtQuick 2.15; Item { transform: [Rotation { angle: attInterface.bankAngle; origin.x: ' + (200 * this.scaleFactor) + '; origin.y: ' + (200 * this.scaleFactor) + ' }, Translate { y: attInterface.pitchTransformValue }] }', _parent);
        _parent.data.push(this.bottomPart);

        this.horizonBottom = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (-1300 * this.scaleFactor) + ';' +
            'y: ' + (200 * this.scaleFactor) + ';' +
            'width: ' + (3000 * this.scaleFactor) + ';' +
            'height: ' + (3000 * this.scaleFactor) + ';' +
            'color: "' + this.horizonBottomColor + '" }',
            this.bottomPart);
        this.bottomPart.data.push(this.horizonBottom);

        let separator = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (-1300 * this.scaleFactor) + ';' +
            'y: ' + (197 * this.scaleFactor) + ';' +
            'width: ' + (3000 * this.scaleFactor) + ';' +
            'height: ' + (6 * this.scaleFactor) + ';' +
            'color: "#e0e0e0" }',
            this.bottomPart);
        this.bottomPart.data.push(separator);

        let attitude_pitch_container = Qt.createQmlObject(
            'import QtQuick 2.15; Item {' +
            'width: ' + (230 * this.scaleFactor) + ';' +
            'height: ' + (260 * this.scaleFactor) + ';' +
            'x: ' + (85 * this.scaleFactor) + ';' +
            'y: ' + (70 * this.scaleFactor) + ';' +
            'clip: true }',
            _parent);
        _parent.data.push(attitude_pitch_container);

        this.attitude_pitch = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { transform: [Translate { y: attInterface.pitchTransformValue }, Rotation { angle: attInterface.bankAngle; origin.x: ' + (115 * this.scaleFactor) + '; origin.y: ' + (130 * this.scaleFactor) + ' }] }', attitude_pitch_container);
        attitude_pitch_container.data.push(this.attitude_pitch);

        this.buildGraduations();

        this.flightDirector = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { visible: attInterface.fdActive; enabled: attInterface.fdActive; transform: [Translate { y: attInterface.fdPitchTransformValue }, Rotation { angle: attInterface.fdBankAngle; origin.x: ' + (115 * this.scaleFactor) + '; origin.y: ' + (130 * this.scaleFactor) + ' }] }', attitude_pitch_container);
        attitude_pitch_container.data.push(this.flightDirector);

        let triangleOuterLeft = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "#D12BC7";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (-25 * this.scaleFactor) + '; y: ' + (160 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (50 * this.scaleFactor) + '; relativeY: 0 }' +
            'PathLine { x: ' + (115 * this.scaleFactor) + '; y: ' + (130 * this.scaleFactor) + ' } }',
            this.flightDirector);
        this.flightDirector.data.push(triangleOuterLeft);

        let triangleOuterRight = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "#D12BC7";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (255 * this.scaleFactor) + '; y: ' + (160 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (-50 * this.scaleFactor) + '; relativeY: 0 }' +
            'PathLine { x: ' + (115 * this.scaleFactor) + '; y: ' + (130 * this.scaleFactor) + ' } }',
            this.flightDirector);
        this.flightDirector.data.push(triangleOuterRight);

        this.attitude_bank = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { transform: Rotation { angle: attInterface.bankAngle; origin.x: ' + (200 * this.scaleFactor) + '; origin.y: ' + (200 * this.scaleFactor) + ' } }', _parent);
        _parent.data.push(this.attitude_bank);

        let topTriangle2 = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "white";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (200 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (-20 * this.scaleFactor) + '; relativeY: ' + (-30 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (40 * this.scaleFactor) + '; relativeY: 0 } }',
            this.attitude_bank);
        this.attitude_bank.data.push(topTriangle2);

        let bigDashes = [-60, -30, 30, 60];
        let smallDashes = [-45, -20, -10, 10, 20, 45];
        let radius = 170;
        let width = 4;
        let height = 30;
        for (let i = 0; i < bigDashes.length; i++) {
            let dash = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: ' + ((200 - width / 2) * this.scaleFactor) + ';' +
                'y: ' + ((200 - radius - height) * this.scaleFactor) + ';' +
                'width: ' + (width * this.scaleFactor) + ';' +
                'height: ' + (height * this.scaleFactor) + ';' +
                'transform: Rotation { angle: ' + bigDashes[i] + '; origin.x: ' + (width / 2 * this.scaleFactor) + '; origin.y: ' + ((radius + height) * this.scaleFactor) + ' }' +
                'color: "white" }',
                this.attitude_bank);
            this.attitude_bank.data.push(dash);
        }
        width = 4;
        height = 20;
        for (let i = 0; i < smallDashes.length; i++) {
            let dash = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: ' + ((200 - width / 2) * this.scaleFactor) + ';' +
                'y: ' + ((200 - radius - height) * this.scaleFactor) + ';' +
                'width: ' + (width * this.scaleFactor) + ';' +
                'height: ' + (height * this.scaleFactor) + ';' +
                'transform: Rotation { angle: ' + smallDashes[i] + '; origin.x: ' + (width / 2 * this.scaleFactor) + '; origin.y: ' + ((radius + height) * this.scaleFactor) + ' }' +
                'color: "white" }',
                this.attitude_bank);
            this.attitude_bank.data.push(dash);
        }

        let cursors = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', _parent);
        _parent.data.push(cursors);

        let leftLower = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "#CCCC00";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (10 * this.scaleFactor) + '; y: ' + (200 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (-10 * this.scaleFactor) + '; relativeY: ' + (12 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (50 * this.scaleFactor) + '; relativeY: ' + (0 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (10 * this.scaleFactor) + '; relativeY: ' + (-12 * this.scaleFactor) + ' } }',
            cursors);
        cursors.data.push(leftLower);

        let leftUpper = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "#FFFF00";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (10 * this.scaleFactor) + '; y: ' + (200 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (-10 * this.scaleFactor) + '; relativeY: ' + (-12 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (50 * this.scaleFactor) + '; relativeY: ' + (0 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (10 * this.scaleFactor) + '; relativeY: ' + (12 * this.scaleFactor) + ' } }',
            cursors);
        cursors.data.push(leftUpper);

        let rightLower = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "#CCCC00";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (390 * this.scaleFactor) + '; y: ' + (200 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (10 * this.scaleFactor) + '; relativeY: ' + (12 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (-50 * this.scaleFactor) + '; relativeY: ' + (0 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (-10 * this.scaleFactor) + '; relativeY: ' + (-12 * this.scaleFactor) + ' } }',
            cursors);
        cursors.data.push(rightLower);

        let rightUpper = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "#FFFF00";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (390 * this.scaleFactor) + '; y: ' + (200 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (10 * this.scaleFactor) + '; relativeY: ' + (-12 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (-50 * this.scaleFactor) + '; relativeY: ' + (0 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (-10 * this.scaleFactor) + '; relativeY: ' + (12 * this.scaleFactor) + ' } }',
            cursors);
        cursors.data.push(rightUpper);

        let triangleInnerLeft = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "#FFFF00";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (110 * this.scaleFactor) + '; y: ' + (230 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (30 * this.scaleFactor) + '; relativeY: ' + (0 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (200 * this.scaleFactor) + '; y: ' + (200 * this.scaleFactor) + ' } }',
            cursors);
        cursors.data.push(triangleInnerLeft);

        let triangleInnerRight = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "#FFFF00";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (290 * this.scaleFactor) + '; y: ' + (230 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (-30 * this.scaleFactor) + '; relativeY: ' + (0 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (200 * this.scaleFactor) + '; y: ' + (200 * this.scaleFactor) + ' } }',
            cursors);
        cursors.data.push(triangleInnerRight);

        let topTriangle = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath {' +
            'fillColor: "white";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (200 * this.scaleFactor) + '; y: ' + (30 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (-13 * this.scaleFactor) + '; relativeY: ' + (20 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (26 * this.scaleFactor) + '; relativeY: ' + (0 * this.scaleFactor) + ' } }',
            cursors);
        cursors.data.push(topTriangle);

        this.slipSkid = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'transform: Translate { x: attInterface.slipSkidTransformValue }' +
            'ShapePath {' +
            'fillColor: "white";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (180 * this.scaleFactor) + '; y: ' + (60 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (184 * this.scaleFactor) + '; y: ' + (54 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (216 * this.scaleFactor) + '; y: ' + (54 * this.scaleFactor) + ' }' +
            'PathLine { x: ' + (220 * this.scaleFactor) + '; y: ' + (60 * this.scaleFactor) + ' } } }',
            _parent);
        _parent.data.push(this.slipSkid);
    }




}
