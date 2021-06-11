class TrimsGaugeClass {
    constructor() {
        this.elevTop = 1024.5;

        this.hasRuddTrim = true;
        this.hasAilTrim = true;

        this.parent = null;
        this.objectArray = [];
    }

    setElevTop(_elevTop) {
        this.elevTop = _elevTop;
    }

    setAvailableTrims(_hasRuddTrim, _hasAilTrim) {
        this.hasRuddTrim = _hasRuddTrim;
        this.hasAilTrim = _hasAilTrim;
    }

    createTrimGauges(_parent) {
        this.parent = _parent;
        this.parent.data = [];

        let elevText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' + 
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + ((!this.hasRuddTrim && !this.hasAilTrim) ? 189 : 90) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (this.elevTop - 12) + ';' +
            'anchors.alignWhenCentered: false;' +
            'renderType: Text.NativeRendering;' +
            'color: \"white\";' +
            'font.pixelSize: 18;' +
            'font.family: \"Roboto Mono\";' +
            'font.bold: true;' +
            'text: \"ELEV\" }',
            this.parent);
        this.parent.data.push(elevText);

        let verticalBar = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + ((!this.hasRuddTrim && !this.hasAilTrim) ? 226.5 : 127.5) + ';' +
            'y: ' + (this.elevTop - 3) + ';' +
            'width: 3;' +
            'height: 126;' +
            'color: \"white\" }',
            this.parent);
        this.parent.data.push(verticalBar);

        let topBar = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + ((!this.hasRuddTrim && !this.hasAilTrim) ? 211.5 : 112.5) + ';' +
            'y: ' + (this.elevTop - 3) + ';' +
            'width: 15;' +
            'height: 3;' +
            'color: \"white\" }',
            this.parent);
        this.parent.data.push(topBar);

        let dnText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' + 
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + ((!this.hasRuddTrim && !this.hasAilTrim) ? 189 : 90) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (this.elevTop + 6) + ';' +
            'anchors.alignWhenCentered: false;' +
            'renderType: Text.NativeRendering;' +
            'color: \"white\";' +
            'font.pixelSize: 18;' +
            'font.family: \"Roboto Mono\";' +
            'font.bold: true;' +
            'text: \"DN\" }',
            this.parent);
        this.parent.data.push(dnText);

        let bottomBar = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + ((!this.hasRuddTrim && !this.hasAilTrim) ? 211.5 : 112.5) + ';' +
            'y: ' + (this.elevTop + 120) + ';' +
            'width: 15;' +
            'height: 3;' +
            'color: \"white\" }',
            this.parent);
        this.parent.data.push(bottomBar);

        let upText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' + 
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + ((!this.hasRuddTrim && !this.hasAilTrim) ? 189 : 90) + ';' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (this.elevTop + 129) + ';' +
            'anchors.alignWhenCentered: false;' +
            'renderType: Text.NativeRendering;' +
            'color: \"white\";' +
            'font.pixelSize: 18;' +
            'font.family: \"Roboto Mono\";' +
            'font.bold: true;' +
            'text: \"UP\" }',
            this.parent);
        this.parent.data.push(upText);

        let centerGrad = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + ((!this.hasRuddTrim && !this.hasAilTrim) ? 219 : 120) + ';' +
            'y: ' + (this.elevTop + 58.5) + ';' +
            'width: 7.5;' +
            'height: 3;' +
            'color: \"white\" }',
            this.parent);
        this.parent.data.push(centerGrad);

        let elevCursor = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { ' +
            'transform: Translate { y: commonGaugeProperties.elevTrimTransformValue }' +
            'ShapePath { ' +
            'fillColor: \"aqua\";' +
            'strokeColor: \"transparent\";' +
            'PathMove { x: ' + ((!this.hasRuddTrim && !this.hasAilTrim) ? 211.5 : 112.5) + '; y: ' + (this.elevTop + 54) + ' }' +
            'PathLine { relativeX: 7.5; relativeY: 0 }' +
            'PathLine { relativeX: 7.5; relativeY: 6 }' +
            'PathLine { relativeX: -7.5; relativeY: 6 }' +
            'PathLine { relativeX: -7.5; relativeY: 0 } } }',
            this.parent);
        this.parent.data.push(elevCursor);

        if(this.hasRuddTrim)
        {
            let rudText = Qt.createQmlObject(
                'import QtQuick 2.15; Text {' + 
                'anchors.horizontalCenter: parent.left;' +
                'anchors.horizontalCenterOffset: 267;' +
                'anchors.baseline: parent.top;' +//+21.075
                'anchors.baselineOffset: ' + (this.hasAilTrim ? this.elevTop + 21.3 : this.elevTop + 52.9125) + ';' +
                'anchors.alignWhenCentered: false;' +
                'renderType: Text.NativeRendering;' +
                'color: \"white\";' +
                'font.pixelSize: 24;' +
                'font.family: \"Roboto Mono\";' +
                'font.bold: true;' +
                'text: \"RUD\" }',
                this.parent);
            this.parent.data.push(rudText);

            let rudHorizontalBar = Qt.createQmlObject(//increment: 12.3
                'import QtQuick 2.15; Rectangle {' +
                'x: 204;' +
                'y: ' + (this.hasAilTrim ? this.elevTop + 49.5 : this.elevTop + 81.1125) + ';' +
                'width: 126;' +
                'height: 3;' +
                'color: \"white\" }',
                this.parent);
            this.parent.data.push(rudHorizontalBar);
    
            let rudLeftBar = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: 204;' +
                'y: ' + (this.hasAilTrim ? this.elevTop + 30 : this.elevTop + 61.6125) + ';' +
                'width: 3;' +
                'height: 22.5;' +
                'color: \"white\" }',
                this.parent);
            this.parent.data.push(rudLeftBar);

            let rudRightBar = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: 327;' +
                'y: ' + (this.hasAilTrim ? this.elevTop + 30 : this.elevTop + 61.6125) + ';' +
                'width: 3;' +
                'height: 22.5;' +
                'color: \"white\" }',
                this.parent);
            this.parent.data.push(rudRightBar);

            let rudCenterGrad = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: 265.5;' +
                'y: ' + (this.hasAilTrim ? this.elevTop + 42 : this.elevTop + 73.6125) + ';' +
                'width: 3;' +
                'height: 7.5;' +
                'color: \"white\" }',
                this.parent);
            this.parent.data.push(rudCenterGrad);

            let rudCursor = Qt.createQmlObject(
                'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { ' +
                'transform: Translate { x: commonGaugeProperties.rudderTrimTransformValue }' +
                'ShapePath { ' +
                'fillColor: \"aqua\";' +
                'strokeColor: \"transparent\";' +
                'PathMove { x: 261; y: ' + (this.hasAilTrim ? this.elevTop + 25.5 : this.elevTop + 57.1125) + ' }' +
                'PathLine { relativeX: 0; relativeY: 12 }' +
                'PathLine { relativeX: 6; relativeY: 12 }' +
                'PathLine { relativeX: 6; relativeY: -12 }' +
                'PathLine { relativeX: 0; relativeY: -12 } } }',
                this.parent);
            this.parent.data.push(rudCursor);
        }
        if(this.hasAilTrim)
        {
            let ailText = Qt.createQmlObject(
                'import QtQuick 2.15; Text {' + 
                'anchors.horizontalCenter: parent.left;' +
                'anchors.horizontalCenterOffset: 267;' +
                'anchors.baseline: parent.top;' +//-22.075
                'anchors.baselineOffset: ' + (this.hasRuddTrim ? this.elevTop + 118.575 : this.elevTop + 85.5375) + ';' +
                'anchors.alignWhenCentered: false;' +
                'renderType: Text.NativeRendering;' +
                'color: \"white\";' +
                'font.pixelSize: 24;' +
                'font.family: \"Roboto Mono\";' +
                'font.bold: true;' +
                'text: \"AIL\" }',
                this.parent);
            this.parent.data.push(ailText);

            let ailHorizontalBar = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: 204;' +
                'y: ' + (this.hasRuddTrim ? this.elevTop + 67.5 : this.elevTop + 34.4625) + ';' +
                'width: 126;' +
                'height: 3;' +
                'color: \"white\" }',
                this.parent);
            this.parent.data.push(ailHorizontalBar);
    
            let ailLeftBar = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: 204;' +
                'y: ' + (this.hasRuddTrim ? this.elevTop + 67.5 : this.elevTop + 34.4625) + ';' +
                'width: 3;' +
                'height: 22.5;' +
                'color: \"white\" }',
                this.parent);
            this.parent.data.push(ailLeftBar);

            let ailRightBar = Qt.createQmlObject(//increment: 13
                'import QtQuick 2.15; Rectangle {' +
                'x: 327;' +
                'y: ' + (this.hasRuddTrim ? this.elevTop + 67.5 : this.elevTop + 34.4625) + ';' +
                'width: 3;' +
                'height: 22.5;' +
                'color: \"white\" }',
                this.parent);
            this.parent.data.push(ailRightBar);

            let ailCenterGrad = Qt.createQmlObject(
                'import QtQuick 2.15; Rectangle {' +
                'x: 265.5;' +
                'y: ' + (this.hasRuddTrim ? this.elevTop + 70.5 : this.elevTop + 37.4625) + ';' +
                'width: 3;' +
                'height: 7.5;' +
                'color: \"white\" }',
                this.parent);
            this.parent.data.push(ailCenterGrad);

            let ailCursor = Qt.createQmlObject(
                'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { ' +
                'transform: Translate { x: commonGaugeProperties.aileronTrimTransformValue }' +
                'ShapePath { ' +
                'fillColor: \"aqua\";' +
                'fillRule: ShapePath.WindingFill;' +
                'strokeColor: \"transparent\";' +
                'PathMove { x: 261; y: ' + (this.hasRuddTrim ? this.elevTop + 94.5 : this.elevTop + 61.4625) + ' }' +
                'PathLine { relativeX: 0; relativeY: -12 }' +
                'PathLine { relativeX: 6; relativeY: -12 }' +
                'PathLine { relativeX: 6; relativeY: 12 }' +
                'PathLine { relativeX: 0; relativeY: 12 } } }',
                this.parent);
            this.parent.data.push(ailCursor);
        }

        //this.parent.data = this.objectArray;
    }
}
