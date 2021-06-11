class GaugeColorZone {
    constructor(_color, _begin, _end) {
        this.begin = _begin;
        this.end = _end;
        this.color = _color;
    }
}

class DoubleVerticalGauge {
    constructor() {
        //size and position
        this.centerX = 210;
        this.yTop = 135;
        this.internalCenterX = 75;
        this.internalyTop = 45;
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
        this.titleElement = null;
        this.unitElement = null;




        this.parent = null;
        this.objectArray = [];
        this.root = null;
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


    drawBase(_parent, _valueName, extraWide = false) {
        this.objectArray = [];
        if (extraWide)
            this.internalCenterX = 82.5;
        _parent.data = [];
        this.root = Qt.createQmlObject('import QtQuick 2.15; Item { ' +
            'clip: true; ' +
            'width: ' + (extraWide ? "165" : "150") + '; ' +
            'x: ' + (this.centerX - (extraWide ? 82.5 : 75)) + '; ' +
            'y: ' + (this.yTop - 45) + '; ' +
            'height: ' + (this.height + 52.5) + ' }',
            _parent);
        _parent.data.push(this.root);

        this.colorZoneParent = Qt.createQmlObject('import QtQuick 2.15; Item {}', this.root);
        this.root.data.push(this.colorZoneParent);

        this.gradParent = Qt.createQmlObject('import QtQuick 2.15; Item {}', this.root);
        this.root.data.push(this.gradParent);


        let beginBar = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle { ' +
            'color: "white"; ' +
            'width: ' + (extraWide ? "90" : "75") + '; ' +
            'x: ' + (this.internalCenterX - (extraWide ? 45 : 37.5)) + '; ' +
            'y: ' + (this.internalyTop + this.height) + '; ' +
            'height: 3 }',
            this.root);
        this.root.data.push(beginBar);

        let endBar = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle { ' +
            'color: "white"; ' +
            'width: ' + (extraWide ? "90" : "75") + '; ' +
            'x: ' + (this.internalCenterX - (extraWide ? 45 : 37.5)) + '; ' +
            'y: ' + (this.internalyTop - 3) + '; ' +
            'height: 3 }',
            this.root);
        this.root.data.push(endBar);

        let gradTextBackground = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle { ' +
            'color: "#1a1d21"; ' +
            'width: ' + (extraWide ? "57" : "42") + '; ' +
            'x: ' + (this.internalCenterX - (extraWide ? 28.5 : 21)) + '; ' +
            'y: ' + (this.internalyTop - 10.5) + '; ' +
            'height: ' + (this.height + 21) + ' }',
            this.root);
        this.root.data.push(gradTextBackground);

        this.textGradParent = Qt.createQmlObject('import QtQuick 2.15; Item {}', this.root);
        this.root.data.push(this.textGradParent);


        let barLeft = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle { ' +
            'color: "white"; ' +
            'width: 3; ' +
            'x: ' + (this.internalCenterX - (extraWide ? 31.5 : 24)) + '; ' +
            'y: ' + (this.internalyTop - 3) + '; ' +
            'height: ' + (this.height + 6) + ' }',
            this.root);
        this.root.data.push(barLeft);

        let barRight = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle { ' +
            'color: "white"; ' +
            'width: 3; ' +
            'x: ' + (this.internalCenterX + (extraWide ? 28.5 : 21)) + '; ' +
            'y: ' + (this.internalyTop - 3) + '; ' +
            'height: ' + (this.height + 6) + ' }',
            this.root);
        this.root.data.push(barRight);

        let leftCursor = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'transform: Translate { y: ' + _valueName + '.engine1TransformValue }' +
            'ShapePath { ' +
            'fillColor: "white";' +
            'strokeColor: "transparent";' +
            'PathMove { ' +
            'x: ' + (this.internalCenterX - (extraWide ? 37.5 : 30)) + ';' +
            'y: ' + (this.internalyTop + this.height) + ' }' +
            'PathLine { ' +
            'x: ' + (this.internalCenterX - (extraWide ? 52.5 : 45)) + ';' +
            'y: ' + (this.internalyTop + this.height) + ' }' +
            'PathLine { ' +
            'x: ' + (this.internalCenterX - (extraWide ? 52.5 : 45)) + ';' +
            'y: ' + (this.internalyTop + 2 * this.height + 15) + ' }' +
            'PathLine { ' +
            'x: ' + (this.internalCenterX - (extraWide ? 45 : 37.5)) + ';' +
            'y: ' + (this.internalyTop + 2 * this.height + 15) + ' }' +
            'PathLine { ' +
            'x: ' + (this.internalCenterX - (extraWide ? 45 : 37.5)) + ';' +
            'y: ' + (this.internalyTop + this.height + 15) + ' } } }',
            this.root);
        this.root.data.push(leftCursor);

        let rightCursor = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {' +
            'transform: Translate { y: ' + _valueName + '.engine2TransformValue }' +
            'ShapePath { ' +
            'fillColor: "white";' +
            'strokeColor: "transparent";' +
            'PathMove { ' +
            'x: ' + (this.internalCenterX + (extraWide ? 37.5 : 30)) + ';' +
            'y: ' + (this.internalyTop + this.height) + ' }' +
            'PathLine { ' +
            'x: ' + (this.internalCenterX + (extraWide ? 52.5 : 45)) + ';' +
            'y: ' + (this.internalyTop + this.height) + ' }' +
            'PathLine { ' +
            'x: ' + (this.internalCenterX + (extraWide ? 52.5 : 45)) + ';' +
            'y: ' + (this.internalyTop + 2 * this.height + 15) + ' }' +
            'PathLine { ' +
            'x: ' + (this.internalCenterX + (extraWide ? 45 : 37.5)) + ';' +
            'y: ' + (this.internalyTop + 2 * this.height + 15) + ' }' +
            'PathLine { ' +
            'x: ' + (this.internalCenterX + (extraWide ? 45 : 37.5)) + ';' +
            'y: ' + (this.internalyTop + this.height + 15) + ' } } }',
            this.root);
        this.root.data.push(rightCursor);


        let titleText = Qt.createQmlObject(
            'import QtQuick 2.15; Text { ' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + this.internalCenterX + ';' +
            'horizontalAlignment: Text.AlignHCenter;' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (this.internalyTop - 25.5) + '; ' +
            'anchors.alignWhenCentered: false;' +
            'renderType: Text.NativeRendering;' +
            'color: "white"; ' +
            'font.pixelSize: 18; ' +
            'font.family: "Roboto Mono";' +
            'font.bold: true;' +
            'text: "' + this.title + '" }',
            this.root);
        this.root.data.push(titleText);

        let unitText = Qt.createQmlObject('import QtQuick 2.15; Text { ' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + this.internalCenterX + ';' +
            'horizontalAlignment: Text.AlignHCenter;' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (this.internalyTop - 6) + '; ' +
            'anchors.alignWhenCentered: false;' +
            'renderType: Text.NativeRendering;' +
            'color: "white"; ' +
            'font.pixelSize: 18; ' +
            'font.family: "Roboto Mono";' +
            'font.bold: true;' +
            'text: "' + this.unit + '" }',
            this.root);
        this.root.data.push(unitText);


        let valueText1 = Qt.createQmlObject(
            'import QtQuick 2.15; Text { ' +
            'anchors.right: parent.left;' +
            'anchors.rightMargin: ' + (22.5 - this.internalCenterX) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (this.internalyTop - 6) + '; ' +
            'anchors.alignWhenCentered: false;' +
            'color: ' + _valueName + '.engine1Color; ' +
            'font.pixelSize: 18; ' +
            'font.family: "Roboto Mono";' +
            'font.bold: true;' +
            'text: ' + _valueName + '.engine1Value }',
            this.root);
        this.root.data.push(valueText1);

        let valueText2 = Qt.createQmlObject(
            'import QtQuick 2.15; Text { ' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (22.5 + this.internalCenterX) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (this.internalyTop - 6) + '; ' +
            'anchors.alignWhenCentered: false;' +
            'color: ' + _valueName + '.engine2Color; ' +
            'font.pixelSize: 18; ' +
            'font.family: "Roboto Mono";' +
            'font.bold: true;' +
            'text: ' + _valueName + '.engine2Value }',
            this.root);
        this.root.data.push(valueText2);

        if (this.colorZones.length > 0)
            this.drawColorZones(extraWide);


        if (this.gradDist > 0)
            this.drawGraduations(extraWide);

        if (this.textGradDist > 0)
            this.drawTextGraduations();


    }





    drawColorZones(extraWide) {
        for (let j = this.colorZoneParent.data.length - 1; j >= 0; j--) {
            this.colorZoneParent.data[j].destroy();
        }
        this.colorZoneParent.data = [];
        //console.log(this.colorZones.length);
        for (let i = 0; i < this.colorZones.length; ++i) {
            //console.log("begin: " + this.colorZones[i].begin + " end: " + this.colorZones[i].end + " color: " + this.colorZones[i].color)
            let begin = (this.colorZones[i].begin - this.minValue) / (this.maxValue - this.minValue) * -this.height + this.internalyTop + this.height;
            let end = (this.colorZones[i].end - this.minValue) / (this.maxValue - this.minValue) * -this.height + this.internalyTop + this.height;

            let obj = Qt.createQmlObject(
                'import QtQuick 2.15; import QtQuick.Shapes 1.15; Rectangle { ' +
                'color: "' + this.colorZones[i].color + '";' +
                'width: ' + (extraWide ? "75" : "60") + ';' +
                'x: ' + (this.internalCenterX - (extraWide ? 37.5 : 30)) + ';' +
                'y: ' + end + ';' +
                'height: ' + (begin - end) + ' }',
                this.colorZoneParent);
            this.colorZoneParent.data.push(obj);
        }
    }

    drawGraduations(extraWide) {
        for (let j = this.gradParent.data.length - 1; j >= 0; j--)
            this.gradParent.data[j].destroy();
        this.gradParent.data = [];
        let count = 0;
        for (let i = Math.abs(this.gradStart - this.minValue) < 0.1 ? this.gradStart + this.gradDist : this.gradStart; i < this.maxValue; i += this.gradDist) {
            let obj = Qt.createQmlObject(
                'import QtQuick 2.15; import QtQuick.Shapes 1.15; Rectangle { ' +
                'color: "white";' +
                'width: ' + (extraWide ? "78" : "63") + ';' +
                'x: ' + (this.internalCenterX - (extraWide ? 39 : 31.5)) + ';' +
                'y: ' + ((i - this.minValue) / (this.maxValue - this.minValue) * -this.height + this.internalyTop + this.height - 0.75) + ';' +
                'height: 1.5 }',
                this.gradParent);
            this.gradParent.data[count] = obj;
            count++;
        }
    }

    drawTextGraduations() {
        for (let j = this.textGradParent.data.length - 1; j >= 0; j--)
            this.textGradParent.data[j].destroy();
        for (let i = this.gradStart; i <= this.maxValue; i += this.textGradDist) {
            let obj = Qt.createQmlObject(
                'import QtQuick 2.15; Text { ' +
                'anchors.horizontalCenter: parent.left;' +
                'anchors.horizontalCenterOffset: ' + this.internalCenterX + ';' +
                'horizontalAlignment: Text.AlignHCenter;' +
                'anchors.verticalCenter: parent.top;' +
                'anchors.verticalCenterOffset: ' + ((i - this.minValue) / (this.maxValue - this.minValue) * -this.height + this.internalyTop + this.height) + '; ' +
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
    }


}
