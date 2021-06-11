class GaugeColorZone {
    constructor(_color, _begin, _end) {
        this.begin = _begin;
        this.end = _end;
        this.color = _color;
    }
}

class VerticalGauge {
    constructor() {
        //size and position
        this.centerX = 210;
        this.yTop = 135;
        this.height = 120;

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
        this.titleElement = null;
        this.unitElement = null;

        this.valuePos = 1; // 1: bottom, 2: attached to cursor
        this.valueTextSize = 30;
        this.valueTextX = 210;
        this.valueTextY = 150;


        this.parent = null;
        this.objectArray = [];
        this.cursorGroup = null;
    }

    setPosition(_cx, _yTop, _height = 120) {
        this.centerX = _cx;
        this.yTop = _yTop;
        this.height = _height;
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


    setTitleAndUnit(_title, _unit) {
        this.title = _title;
        this.unit = _unit;
    }


    setValuePos(_posType) {
        this.valuePos = _posType;
    }



    drawBase(_parent, _valueName) {
        this.parent = _parent;
        for (let i = this.parent.data.length - 1; i >= 0; --i)
            this.parent.data[i].destroy();
        this.objectArray = [];
        this.colorZoneParent = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', this.parent);
        this.parent.data.push(this.colorZoneParent);

        this.gradParent = Qt.createQmlObject('import QtQuick 2.15; Item {}', this.parent);
        this.parent.data.push(this.gradParent);

        this.textGradParent = Qt.createQmlObject('import QtQuick 2.15; Item {}', this.parent);
        this.parent.data.push(this.textGradParent);


        let rightBar = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle { ' +
            'color: "white"; ' +
            'width: 3; ' +
            'x: ' + (this.centerX + 15) + '; ' +
            'y: ' + (this.yTop - 3) + '; ' +
            'height: ' + (this.height + 6) + ' }',
            this.parent);
        this.parent.data.push(rightBar);

        let beginBar = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle { ' +
            'color: "white"; ' +
            'width: 18; ' +
            'height: 3; ' +
            'x: ' + this.centerX + '; ' +
            'y: ' + (this.yTop + this.height) + ' }',
            this.parent);
        this.parent.data.push(beginBar);

        let endBar = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle { ' +
            'color: "white"; ' +
            'width: 18; ' +
            'height: 3; ' +
            'x: ' + this.centerX + '; ' +
            'y: ' + (this.yTop - 3) + ' }',
            this.parent);
        this.parent.data.push(endBar);


        this.cursorGroup = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'transform: Translate { y: ' + _valueName + 'TransformValue } }',
            this.parent);
        this.parent.data.push(this.cursorGroup);

        let cursor = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; ShapePath { ' +
            'fillColor: "white";' +
            'strokeColor: "transparent";' +
            'PathMove { ' +
            'x: ' + (this.centerX + 15) + ';' +
            'y: ' + (this.yTop + this.height) + ' }' +
            'PathLine { ' +
            'x: ' + (this.centerX + 10.5) + ';' +
            'y: ' + (this.yTop + this.height - 4.5) + ' }' +
            'PathLine { ' +
            'x: ' + (this.centerX + 3) + ';' +
            'y: ' + (this.yTop + this.height - 4.5) + ' }' +
            'PathLine { ' +
            'x: ' + (this.centerX + 3) + ';' +
            'y: ' + (this.yTop + this.height + 4.5) + ' }' +
            'PathLine { ' +
            'x: ' + (this.centerX + 10.5) + ';' +
            'y: ' + (this.yTop + this.height + 4.5) + ' } }',
            this.cursorGroup);
        let cursorGroupArray = [];
        cursorGroupArray.push(cursor);

        if (this.valuePos === 2) {
            let valueText = Qt.createQmlObject(
                'import QtQuick 2.15; Text { ' +
                'anchors.right: parent.left;' +
                'anchors.rightMargin: ' + (3 - this.centerX) + ';' +
                'anchors.verticalCenter: parent.top;' +
                'anchors.verticalCenterOffset: ' + (this.yTop + this.height) + '; ' +
                'anchors.alignWhenCentered: false;' +
                'color: ' + _valueName + 'Color; ' +
                'font.pixelSize: 15; ' +
                'font.family: "Roboto Mono";' +
                'font.bold: true;' +
                'text: ' + _valueName + 'Value }',
                this.cursorGroup);

            cursorGroupArray.push(valueText);

        }

        this.cursorGroup.data = cursorGroupArray;

        if (this.title !== "")
        {
            var titleTextBg = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle { ' +
                'visible: ' + _valueName + 'RedBlink;' +
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
        if (this.unit !== "")
        {
            var unitTextBg = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle { ' +
                'visible: ' + _valueName + 'RedBlink;' +
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
        if (this.valuePos !== 2)
        {
            var valueTextBg = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle { ' +
                'visible: ' + _valueName + 'RedBlink;' +
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
        }

        if (this.title !== "") {
            let titleElement = Qt.createQmlObject(
                'import QtQuick 2.15; import QtQuick.Controls 2.15; Label { ' +
                'anchors.horizontalCenter: parent.left;' +
                'anchors.horizontalCenterOffset: ' + this.centerX + ';' +
                'horizontalAlignment: Text.AlignHCenter;' +
                'anchors.baseline: parent.top;' +
                'anchors.baselineOffset: ' + (this.yTop - 25.5) + '; ' +
                'anchors.alignWhenCentered: false;' +
                'renderType: Text.NativeRendering;' +
                'color: ' + _valueName + 'RedBlink ? "white" : "white"; ' +
                'font.pixelSize: 18; ' +
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

            titleTextBg.anchors.left = titleElement.left;
            titleTextBg.anchors.leftMargin = -1.5;
            titleTextBg.anchors.right = titleElement.right;
            titleTextBg.anchors.rightMargin = -1.5;
            titleTextBg.anchors.top = titleElement.top;
            titleTextBg.anchors.topMargin = 1.5;
            titleTextBg.anchors.bottom = titleElement.bottom;
            titleTextBg.anchors.bottomMargin = -0.75;
        }


        if (this.unit !== "") {
            let unitElement = Qt.createQmlObject(
                'import QtQuick 2.15; Text { ' +
                'anchors.horizontalCenter: parent.left;' +
                'anchors.horizontalCenterOffset: ' + this.centerX + ';' +
                'horizontalAlignment: Text.AlignHCenter;' +
                'anchors.baseline: parent.top;' +
                'anchors.baselineOffset: ' + (this.yTop - 6) + '; ' +
                'anchors.alignWhenCentered: false;' +
                'renderType: Text.NativeRendering;' +
                'color: ' + _valueName + 'RedBlink ? "white" : "white"; ' +
                'font.pixelSize: 18; ' +
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

            unitTextBg.anchors.left = unitElement.left;
            unitTextBg.anchors.leftMargin = -1.5;
            unitTextBg.anchors.right = unitElement.right;
            unitTextBg.anchors.rightMargin = -1.5;
            unitTextBg.anchors.top = unitElement.top;
            unitTextBg.anchors.topMargin = 1.5;
            unitTextBg.anchors.bottom = unitElement.bottom;
            unitTextBg.anchors.bottomMargin = -0.75;
        }

        if (this.valuePos !== 2)
        {
            let valueText = Qt.createQmlObject(
                'import QtQuick 2.15; Text { ' +
                'anchors.horizontalCenter: parent.left;' +
                'anchors.horizontalCenterOffset: ' + this.centerX + ';' +
                'horizontalAlignment: Text.AlignHCenter;' +
                'anchors.baseline: parent.top;' +
                'anchors.baselineOffset: ' + (this.yTop + this.height + 22.5) + '; ' +
                'anchors.alignWhenCentered: false;' +
                'renderType: Text.NativeRendering;' +
                'color: ' + _valueName + 'RedBlink ? "white" : ' + _valueName + 'Color; ' +
                'font.pixelSize: 18; ' +
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

            valueTextBg.anchors.left = valueText.left;
            valueTextBg.anchors.leftMargin = -1.5;
            valueTextBg.anchors.right = valueText.right;
            valueTextBg.anchors.rightMargin = -1.5;
            valueTextBg.anchors.top = valueText.top;
            valueTextBg.anchors.topMargin = 1.5;
            valueTextBg.anchors.bottom = valueText.bottom;
            valueTextBg.anchors.bottomMargin = -1.5;
        }


        if (this.colorZones.length > 0)
            this.drawColorZones();

        if (this.gradDist > 0)
            this.drawGraduations();

        if (this.textGradDist > 0 && this.valuePos === 1)
            this.drawTextGraduations();

    }





    drawColorZones() {
        for(let j = this.colorZoneParent.data.length - 1; j >= 0; j--) {
            this.colorZoneParent.data[j].destroy();
        }
        for (let i = 0; i < this.colorZones.length; ++i) {
            let begin = (this.colorZones[i].begin - this.minValue) / (this.maxValue - this.minValue) * -this.height + this.yTop + this.height;
            let end = (this.colorZones[i].end - this.minValue) / (this.maxValue - this.minValue) * -this.height + this.yTop + this.height;

            let obj = Qt.createQmlObject(
                'import QtQuick 2.15; import QtQuick.Shapes 1.15; Rectangle { ' +
                'color: "' + this.colorZones[i].color + '";' +
                'width: 6;' +
                'x: ' + (this.centerX + 9) + ';' +
                'y: ' + end + ';' +
                'height: ' + (begin - end) + ' }',
                this.colorZoneParent);
                this.colorZoneParent.data.push(obj);
        }
    }

    drawGraduations() {
        for (let j = this.gradParent.data.length - 1; j >= 0; j--)
            this.gradParent.data[j].destroy(); 
        for (let i = Math.abs(this.gradStart - this.minValue) < 0.1 ? this.gradStart + this.gradDist : this.gradStart; i < this.maxValue; i += this.gradDist) {
            let obj = Qt.createQmlObject(
                'import QtQuick 2.15; import QtQuick.Shapes 1.15; Rectangle { ' +
                'color: "white";' +
                'width: 15;' +
                'x: ' + this.centerX + ';' +
                'y: ' + ((i - this.minValue) / (this.maxValue - this.minValue) * -this.height + this.yTop + this.height - 0.75) + ';' +
                'height: 1.5 }',
                this.gradParent);
                this.gradParent.data.push(obj);
        }
    }

    drawTextGraduations() {
        for (let j = this.textGradParent.data.length - 1; j >= 0; j--)
            this.textGradParent.data[j].destroy();
        for (let i = this.gradStart; i <= this.maxValue; i += this.textGradDist) {
            let obj = Qt.createQmlObject(
                'import QtQuick 2.15; Text { ' +
                'anchors.right: parent.left;' +
                'anchors.rightMargin: ' + (3 - this.centerX) + ';' +
                'anchors.verticalCenter: parent.top;' +
                'anchors.verticalCenterOffset: ' + ((i - this.minValue) / (this.maxValue - this.minValue) * -this.height + this.yTop + this.height) + '; ' +
                'anchors.alignWhenCentered: false;' +
                'renderType: Text.NativeRendering;' +
                'color: "white"; ' +
                'font.pixelSize: 15; ' +
                'font.family: "Roboto Mono";' +
                'font.bold: true;' +
                'text: "' + i + '" }',
                this.textGradParent);
            this.textGradParent.data.push(obj);
        }
        //this.textGradParent.data = textGradArray;
    }



}