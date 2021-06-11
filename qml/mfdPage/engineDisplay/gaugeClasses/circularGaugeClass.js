class GaugeColorZone {
    constructor(_color, _begin, _end) {
        this.begin = _begin;
        this.end = _end;
        this.color = _color;
    }
}

function wrapAngle(_value) {
    return (360 + (_value % 360)) % 360;
}

class CircularGauge {
    constructor() {
        //size and position
        this.scaleFactor = 1;
        this.startAngle = 195;
        this.endAngle = 345;
        this.centerX = 210;
        this.centerY = 135;
        this.radius = 120;

        //parameters for extras (grads, colorzones etc)
        this.minValue = 0;
        this.maxValue = 110;
        this.colorZones = [];
        this.gradDist = -1;
        this.textGradDist = -1;
        this.gradStart = -1;
        this.colorZoneParent = null;
        this.gradParent = null;
        this.textGradParent = null;

        //title and unit
        this.title = "";
        this.unit = "";
        this.titleSize = -1;
        this.unitSize = -1;
        this.titleX = 0;
        this.titleY = 0;
        this.unitX = 0;
        this.unitY = 0;

        this.valueTextSize = 20;
        this.valueTextX = 140;
        this.valueTextY = 100;


        this.parent = null;
        this.objectArray = [];
    }


    valueToAngle(_value) {
        return this.startAngle - (_value - this.minValue) / (this.maxValue - this.minValue) * wrapAngle(this.startAngle - this.endAngle);
    }


    setScaleFactor(_factor) {
        this.scaleFactor = _factor;
    }

    setAngles(_startAngle, _endAngle) {
        this.startAngle = _startAngle;
        this.endAngle = _endAngle;
    }

    setPos(_cx, _cy) {
        this.centerX = _cx;
        this.centerY = _cy;
    }

    setRadius(_rad) {
        this.radius = _rad;
    }


    setRange(_minVal, _maxVal) {
        this.minValue = _minVal;
        this.maxValue = _maxVal;
    }

    addColorZone(_begin, _end, _color) {
        this.colorZones.push(new GaugeColorZone(_color, _begin, _end));
    }

    clearColorZones() {
        this.colorZones = [];
    }

    setGrads(_gradDist, _textGradDist, _gradStart) {
        this.gradDist = _gradDist;
        this.textGradDist = _textGradDist;
        this.gradStart = _gradStart;
    }


    setTitle(_title, _titleX, _titleY, _titleSize) {
        this.title = _title;
        this.titleX = _titleX;
        this.titleY = _titleY;
        this.titleSize = _titleSize;
    }

    setUnit(_unit, _unitX, _unitY, _unitSize) {
        this.unit = _unit;
        this.unitX = _unitX;
        this.unitY = _unitY;
        this.unitSize = _unitSize;
    }


    setValueText(_xPos, _yPos, _size) {
        this.valueTextX = _xPos;
        this.valueTextY = _yPos;
        this.valueTextSize = _size;
    }



    drawColorZones() {
        for(let j = this.colorZoneParent.data.length - 1; j >= 0; j--) {
            this.colorZoneParent.data[j].destroy();
        }
        for (let i = 0; i < this.colorZones.length; ++i) {
            let beginAngle = this.valueToAngle(this.colorZones[i].begin);
            let endAngle = this.valueToAngle(this.colorZones[i].end);
            //console.log("begin: " + this.colorZones[i].begin + " end: " + this.colorZones[i].end + " color: " + this.colorZones[i].color)
            //console.log("begin angle: " + beginAngle);
            //console.log("end angle: " + endAngle);

            let obj = Qt.createQmlObject(
                'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath { ' +
                'fillColor: "' + this.colorZones[i].color + '";' +
                'strokeColor: "transparent";' +
                'PathAngleArc { ' +
                'centerX: ' + this.centerX + ';' +
                'centerY: ' + this.centerY + ';' +
                'radiusX: ' + (this.radius - 3 * this.scaleFactor) + ';' +
                'radiusY: ' + (this.radius - 3 * this.scaleFactor) + ';' +
                'startAngle: ' + -beginAngle + ';' +
                'sweepAngle: ' + (beginAngle - endAngle) + ' }' +
                'PathAngleArc { ' +
                'centerX: ' + this.centerX + ';' +
                'centerY: ' + this.centerY + ';' +
                'radiusX: ' + (this.radius - 9 * this.scaleFactor) + ';' +
                'radiusY: ' + (this.radius - 9 * this.scaleFactor) + ';' +
                'startAngle: ' + -endAngle + ';' +
                'sweepAngle: ' + (endAngle - beginAngle) + ';' +
                'moveToStart: false } }',
                this.colorZoneParent);
                this.colorZoneParent.data.push(obj);
        }
    }


    drawBase(_parent, _valueName) {
        this.objectArray = [];
        this.parent = _parent;
        for (let i = this.parent.data.length - 1; i >= 0; --i)
            this.parent.data[i].destroy();
        this.colorZoneParent = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', this.parent);
        this.parent.data.push(this.colorZoneParent);

        this.gradParent = Qt.createQmlObject('import QtQuick 2.15; Item {}', this.parent);
        this.parent.data.push(this.gradParent);
        this.textGradParent = Qt.createQmlObject('import QtQuick 2.15; Item {}', this.parent);
        this.parent.data.push(this.textGradParent);

        let sweepVal = wrapAngle(this.startAngle - this.endAngle);
        let mainArc = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { ShapePath { ' +
            'fillColor: "transparent"; ' +
            'strokeColor: "white"; ' +
            'strokeWidth: ' + (3 * this.scaleFactor) + '; ' +
            'PathAngleArc { ' +
            'centerX: ' + this.centerX + '; ' +
            'centerY: ' + this.centerY + '; ' +
            'radiusX: ' + this.radius + '; ' +
            'radiusY: ' + this.radius + '; ' +
            'startAngle: ' + -this.startAngle + '; ' +
            'sweepAngle: ' + sweepVal + ' } } }',
            this.parent);
        this.parent.data.push(mainArc);

        let beginLimit = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle { ' +
            'x: ' + (this.centerX + this.radius - 15 * this.scaleFactor) + '; ' +
            'y: ' + (this.centerY - 1.5 * this.scaleFactor) + '; ' +
            'width: ' + (15 * this.scaleFactor) + '; ' +
            'height: ' + (3 * this.scaleFactor) + '; ' +
            'color: "white"; ' +
            'transform: Rotation { ' +
            'angle: ' + -this.startAngle + '; ' +
            'origin.x: ' + (15 * this.scaleFactor - this.radius) + '; ' +
            'origin.y: ' + (1.5 * this.scaleFactor) + ' } }',
            this.parent);
        this.parent.data.push(beginLimit);

        let endLimit = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle { ' +
            'x: ' + (this.centerX + this.radius - 15 * this.scaleFactor) + '; ' +
            'y: ' + (this.centerY - 1.5 * this.scaleFactor) + '; ' +
            'width: ' + (15 * this.scaleFactor) + '; ' +
            'height: ' + (3 * this.scaleFactor) + '; ' +
            'color: "white"; ' +
            'transform: Rotation { ' +
            'angle: ' + -this.endAngle + '; ' +
            'origin.x: ' + (15 * this.scaleFactor - this.radius) + '; ' +
            'origin.y: ' + (1.5 * this.scaleFactor) + ' } }',
            this.parent);
        this.parent.data.push(endLimit);

        let cursor = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'transform: Rotation { angle: ' + _valueName + 'Angle; origin.x: ' + this.centerX + '; origin.y:' + this.centerY + ' } ' +
            'ShapePath { ' +
            'fillColor: "white";' +
            'strokeColor: "transparent";' +
            'PathMove { ' +
            'x: ' + (this.centerX + this.radius - 7.5 * this.scaleFactor) + ';' +
            'y: ' + this.centerY + ' }' +
            'PathLine { ' +
            'x: ' + (this.centerX + this.radius - 22.5 * this.scaleFactor) + ';' +
            'y: ' + (this.centerY - 7.5 * this.scaleFactor) + ' }' +
            'PathLine { ' +
            'x: ' + (this.centerX + this.radius - 22.5 * this.scaleFactor) + ';' +
            'y: ' + (this.centerY + 7.5 * this.scaleFactor) + ' } } }',
            this.parent);
        this.parent.data.push(cursor);

        if (this.title !== "") {
            var titleTextBg = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle { ' +
                'visible: ' + _valueName + 'RedBlink;' +
                'color: "green"; ' +
                'SequentialAnimation on color { ' +
                'alwaysRunToEnd: false;' +
                'running: ' + _valueName + 'RedBlink;' +
                'loops: Animation.Infinite;' +
                'ColorAnimation { from: "red"; to: "white"; duration: 20 }' +
                'PauseAnimation { duration: 480 }' +
                'ColorAnimation { to: "red"; duration: 20 }' +
                'PauseAnimation { duration: 480 } } }',
                this.parent);
            this.parent.data.push(titleTextBg);
        }
        if (this.unit !== "") {
            var unitTextBg = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle { ' +
                'visible: ' + _valueName + 'RedBlink;' +
                'color: "blue"; ' +
                'SequentialAnimation on color { ' +
                'alwaysRunToEnd: false;' +
                'running: ' + _valueName + 'RedBlink;' +
                'loops: Animation.Infinite;' +
                'ColorAnimation { from: "red"; to: "white"; duration: 20 }' +
                'PauseAnimation { duration: 480 }' +
                'ColorAnimation { to: "red"; duration: 20 }' +
                'PauseAnimation { duration: 480 } } }',
                this.parent);
            this.parent.data.push(unitTextBg);
        }

        let valueTextBg = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle { ' +
            'visible: ' + _valueName + 'RedBlink;' +
            'color: "red"; ' +
            'SequentialAnimation on color { ' +
            'alwaysRunToEnd: false;' +
            'running: ' + _valueName + 'RedBlink;' +
            'loops: Animation.Infinite;' +
            'ColorAnimation { from: "red"; to: "white"; duration: 20 }' +
            'PauseAnimation { duration: 480 }' +
            'ColorAnimation { to: "red"; duration: 20 }' +
            'PauseAnimation { duration: 480 } } }',
            this.parent);
        this.parent.data.push(valueTextBg);


        if (this.title !== "") {
            let titleElement = Qt.createQmlObject(
                'import QtQuick 2.15; Text { ' +
                //'anchors.horizontalCenter: parent.left;' +
                'anchors.horizontalCenterOffset: ' + this.titleX + ';' +
                'horizontalAlignment: Text.AlignHCenter;' +
                //'anchors.baseline: parent.top;' +
                'anchors.baselineOffset: ' + this.titleY + '; ' +
                'anchors.alignWhenCentered: false;' +
                'renderType: Text.NativeRendering;' +
                'color: ' + _valueName + 'RedBlink ? "white" : "white"; ' +
                'font.pixelSize: ' + this.titleSize + '; ' +
                'font.family: "Roboto Mono";' +
                'font.bold: true;' +
                'text: "' + this.title + '";' +
                'SequentialAnimation on color { ' +
                'alwaysRunToEnd: false;' +
                'running: ' + _valueName + 'RedBlink;' +
                'loops: Animation.Infinite;' +
                'ColorAnimation { from: "white"; to: "red"; duration: 20 }' +
                'PauseAnimation { duration: 480 }' +
                'ColorAnimation { to: "white"; duration: 20 }' +
                'PauseAnimation { duration: 480 } } }',
                this.parent);
            this.parent.data.push(titleElement);

            titleElement.anchors.horizontalCenter = this.parent.left;
            titleElement.anchors.baseline = this.parent.top;

            titleTextBg.anchors.left = titleElement.left;
            titleTextBg.anchors.leftMargin = -1.5;
            titleTextBg.anchors.right = titleElement.right;
            titleTextBg.anchors.rightMargin = -1.5;
            titleTextBg.anchors.top = titleElement.top;
            titleTextBg.anchors.topMargin = -1.5;
            titleTextBg.anchors.bottom = titleElement.bottom;
            titleTextBg.anchors.bottomMargin = -1.5;
        }


        if (this.unit !== "") {
            let unitElement = Qt.createQmlObject(
                'import QtQuick 2.15; Text { ' +
                //'anchors.horizontalCenter: parent.left;' +
                'anchors.horizontalCenterOffset: ' + this.unitX + ';' +
                'horizontalAlignment: Text.AlignHCenter;' +
                //'anchors.baseline: parent.top;' +
                'anchors.baselineOffset: ' + this.unitY + '; ' +
                'anchors.alignWhenCentered: false;' +
                'renderType: Text.NativeRendering;' +
                'color: ' + _valueName + 'RedBlink ? "white" : "white"; ' +
                'font.pixelSize: ' + this.unitSize + '; ' +
                'font.family: "Roboto Mono";' +
                'font.bold: true;' +
                'text: "' + this.unit + '";' +
                'SequentialAnimation on color { ' +
                'alwaysRunToEnd: false;' +
                'running: ' + _valueName + 'RedBlink;' +
                'loops: Animation.Infinite;' +
                'ColorAnimation { from: "white"; to: "red"; duration: 20 }' +
                'PauseAnimation { duration: 480 }' +
                'ColorAnimation { to: "white"; duration: 20 }' +
                'PauseAnimation { duration: 480 } } }',
                this.parent);
            this.parent.data.push(unitElement);

            unitElement.anchors.horizontalCenter = this.parent.left;
            unitElement.anchors.baseline = this.parent.top;

            unitTextBg.anchors.left = unitElement.left;
            unitTextBg.anchors.leftMargin = -1.5;
            unitTextBg.anchors.right = unitElement.right;
            unitTextBg.anchors.rightMargin = -1.5;
            unitTextBg.anchors.top = unitElement.top;
            unitTextBg.anchors.topMargin = -1.5;
            unitTextBg.anchors.bottom = unitElement.bottom;
            unitTextBg.anchors.bottomMargin = -1.5;
        }

        let valueText = Qt.createQmlObject(
            'import QtQuick 2.15; Text { ' +
            //'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + this.valueTextX + ';' +
            'horizontalAlignment: Text.AlignHCenter;' +
            //'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + this.valueTextY + '; ' +
            'anchors.alignWhenCentered: false;' +
            'renderType: Text.NativeRendering;' +
            'color: ' + _valueName + 'RedBlink ? "white" : ' + _valueName + 'Color; ' +
            'font.pixelSize: ' + this.valueTextSize + '; ' +
            'font.family: "Roboto Mono";' +
            'font.bold: true;' +
            'text: ' + _valueName + 'Value;' +
            'SequentialAnimation on color { ' +
            'alwaysRunToEnd: false;' +
            'running: ' + _valueName + 'RedBlink;' +
            'loops: Animation.Infinite;' +
            'ColorAnimation { from: "white"; to: "red"; duration: 20 }' +
            'PauseAnimation { duration: 480 }' +
            'ColorAnimation { to: "white"; duration: 20 }' +
            'PauseAnimation { duration: 480 } } }',
            this.parent);
        this.parent.data.push(valueText);

        valueText.anchors.horizontalCenter = this.parent.left;
        valueText.anchors.baseline = this.parent.top;

        valueTextBg.anchors.left = valueText.left;
        valueTextBg.anchors.leftMargin = -1.5;
        valueTextBg.anchors.right = valueText.right;
        valueTextBg.anchors.rightMargin = -1.5;
        valueTextBg.anchors.top = valueText.top;
        valueTextBg.anchors.topMargin = -1.5;
        valueTextBg.anchors.bottom = valueText.bottom;
        valueTextBg.anchors.bottomMargin = -1.5;


        this.parent.data.push(valueText);

        if (this.colorZones.length > 0)
            this.drawColorZones();

        if (this.gradDist > 0)
            this.drawGraduations();
        
        if (this.textGradDist > 0)
            this.drawTextGraduations();

    }



    drawGraduations() {
        for (let j = this.gradParent.data.length - 1; j >= 0; j--)
            this.gradParent.data[j].destroy(); 
        for (let i = Math.abs(this.gradStart - this.minValue) < 0.1 ? this.gradStart + this.gradDist : this.gradStart; i < this.maxValue; i += this.gradDist) {
            let heightVal = 1.5 * this.scaleFactor;
            let widthVal = 9 * this.scaleFactor;
            let xVal = this.centerX + this.radius - widthVal;
            let yVal = this.centerY - heightVal;
            let rotationAngle = -this.valueToAngle(i);

            let obj = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle { ' +
                'x: ' + xVal + '; ' +
                'y: ' + yVal + '; ' +
                'width: ' + widthVal + '; ' +
                'height: ' + heightVal + '; ' +
                'color: "white"; ' +
                'transform: Rotation { ' +
                'angle: ' + rotationAngle + '; ' +
                'origin.x: ' + (widthVal - this.radius) + '; ' +
                'origin.y: ' + heightVal + ' } }',
                this.gradParent);
                this.gradParent.data.push(obj);
        }
    }

    drawTextGraduations() {
        for (let j = this.textGradParent.data.length - 1; j >= 0; j--)
            this.textGradParent.data[j].destroy();
        for (let i = this.gradStart; i <= this.maxValue; i += this.textGradDist) {
            let angle = this.valueToAngle(i);
            let xCenter = this.centerX + (this.radius - 9 * this.scaleFactor) * 0.7 * Math.cos(angle * Math.PI / 180);
            let yCenter = this.centerY - (this.radius - 9 * this.scaleFactor) * 0.7 * Math.sin(angle * Math.PI / 180);
            let obj = Qt.createQmlObject(
                'import QtQuick 2.15; Text { ' +
                //'anchors.horizontalCenter: parent.left;' +
                'anchors.horizontalCenterOffset: ' + (xCenter) + ';' +
                //'anchors.verticalCenter: parent.top;' +
                'anchors.verticalCenterOffset: ' + (yCenter) + '; ' +
                'anchors.alignWhenCentered: false;' +
                'renderType: Text.NativeRendering;' +
                'color: "white"; ' +
                'font.pixelSize: 15; ' +
                'font.family: "Roboto Mono";' +
                'font.bold: true;' +
                'text: "' + i + '" }',
                this.textGradParent);
            this.textGradParent.data.push(obj);

            obj.anchors.horizontalCenter = this.textGradParent.left;
            obj.anchors.verticalCenter = this.textGradParent.top;
        }
    }
}
