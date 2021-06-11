class FuelTextClass {
    constructor() {
        this.topBaseline = 440;

        this.hasApu = false;

        this.parent = null;
        this.objectArray = [];
    }

    setTopBaseline(_topBaseline) {
        this.topBaseline = _topBaseline;
    }

    setHasApu(_hasApu) {
        this.hasApu = _hasApu;
    }

    createFuelText(_parent) {
        this.parent = _parent;
        this.objectArray = [];

        let fuelTimeText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' + 
            'anchors.left: parent.left;' +
            'anchors.leftMargin: 7.5;' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (this.hasApu ? this.topBaseline : this.topBaseline + 11.25) + ';' +
            'anchors.alignWhenCentered: false;' +
            'renderType: Text.NativeRendering;' +
            'color: \"white\";' +
            'font.pixelSize: 18;' +
            'font.family: \"Roboto Mono\";' +
            'font.bold: true;' +
            'text: \"FUEL TIME\" }',
            this.parent);
        this.objectArray.push(fuelTimeText);

        let fuelTimeTextText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' + 
            'anchors.right: parent.left;' +
            'anchors.rightMargin: -202.5;' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (this.hasApu ? this.topBaseline : this.topBaseline + 11.25) + ';' +
            'anchors.alignWhenCentered: false;' +
            'renderType: Text.NativeRendering;' +
            'color: \"white\";' +
            'font.pixelSize: 18;' +
            'font.family: \"Roboto Mono\";' +
            'font.bold: true;' +
            'text: commonGaugeProperties.fuelTimeText }',
            this.parent);
        this.objectArray.push(fuelTimeTextText);

        let fuelRangeText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' + 
            'anchors.left: parent.left;' +
            'anchors.leftMargin: 217.5;' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (this.hasApu ? this.topBaseline : this.topBaseline + 11.25) + ';' +
            'anchors.alignWhenCentered: false;' +
            'renderType: Text.NativeRendering;' +
            'color: \"white\";' +
            'font.pixelSize: 18;' +
            'font.family: \"Roboto Mono\";' +
            'font.bold: true;' +
            'text: \"FUEL RANGE\" }',
            this.parent);
        this.objectArray.push(fuelRangeText);

        let fuelRangeTextText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' + 
            'anchors.right: parent.left;' +
            'anchors.rightMargin: -412.5;' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (this.hasApu ? this.topBaseline : this.topBaseline + 11.25) + ';' +
            'anchors.alignWhenCentered: false;' +
            'renderType: Text.NativeRendering;' +
            'color: \"white\";' +
            'font.pixelSize: 18;' +
            'font.family: \"Roboto Mono\";' +
            'font.bold: true;' +
            'text: commonGaugeProperties.fuelRangeText }',
            this.parent);
        this.objectArray.push(fuelRangeTextText);

        let separator = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: 209.25;' +
            //'y: ' + (this.hasApu ? this.topBaseline - 18.6796875 : this.topBaseline - 7.4296875) + ';' +
            'y: ' + (fuelRangeText.y) + ';' +
            'width: 1.5;' +
            //'height: 23.7890625;' +
            'height: ' + (fuelRangeText.height) + ';' +
            'color: \"white\" }',
            this.parent);
        this.objectArray.push(separator);

        if (this.hasApu)
        {
            let apuRpmText = Qt.createQmlObject(
                'import QtQuick 2.15; Text {' + 
                'anchors.right: parent.left;' +
                'anchors.rightMargin: -195;' +
                'anchors.baseline: parent.top;' +
                'anchors.baselineOffset: ' + (this.topBaseline + 22.5) + ';' +
                'anchors.alignWhenCentered: false;' +
                'renderType: Text.NativeRendering;' +
                'color: \"white\";' +
                'font.pixelSize: 18;' +
                'font.family: \"Roboto Mono\";' +
                'font.bold: true;' +
                'text: \"APU N1\" }',
                this.parent);
            this.objectArray.push(apuRpmText);
    
            let apuRpmTextText = Qt.createQmlObject(
                'import QtQuick 2.15; Text {' + 
                'anchors.left: parent.left;' +
                'anchors.leftMargin: 225;' +
                'anchors.baseline: parent.top;' +
                'anchors.baselineOffset: ' + (this.topBaseline + 22.5) + ';' +
                'anchors.alignWhenCentered: false;' +
                'renderType: Text.NativeRendering;' +
                'color: \"white\";' +
                'font.pixelSize: 18;' +
                'font.family: \"Roboto Mono\";' +
                'font.bold: true;' +
                'text: commonGaugeProperties.apuRpmText }',
                this.parent);
            this.objectArray.push(apuRpmTextText);
        }

        this.parent.data = this.objectArray;
    }
}