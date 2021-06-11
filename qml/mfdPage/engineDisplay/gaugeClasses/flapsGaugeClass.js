class FlapsGaugeClass {
    constructor() {
        this.yStart = 924.6;

        this.hasFlaps = true;
        this.hasSpoilers = true;

        this.parent = null;
        this.objectArray = [];
    }

    setYStart(_yStart) {
        this.yStart = _yStart;
    }

    setComponents(_hasFlaps, _hasSpoilers) {
        this.hasFlaps = _hasFlaps;
        this.hasSpoilers = _hasSpoilers;
    }

    createFlapsGauge(_parent) {
        this.parent = _parent;
        this.objectArray = [];

        if(!this.hasFlaps)
        {
            _parent.children = this.objectArray;
            return;
        }

        if (this.hasSpoilers) {
            let wing = Qt.createQmlObject(
                'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { ShapePath {' +
                'fillColor: \"transparent\";' +
                'strokeColor: \"white\";' +
                'strokeWidth: 1.5;' +
                'PathMove { x: 179.0625; y: ' + this.yStart + ' }' +
                'PathCubic { relativeControl1X: -16.5; relativeControl1Y: -3.3; relativeControl2X: -50.0625; relativeControl2Y: -9.6; relativeX: -75.9; relativeY: -6.6 }' +
                'PathCubic { relativeControl1X: -72.6; relativeControl1Y: 9.9; relativeControl2X: -73.1625; relativeControl2Y: 42; relativeX: 3.3; relativeY: 46.2 }' +
                'PathCubic { relativeControl1X: 39.6; relativeControl1Y: 3.3; relativeControl2X: 89.1; relativeControl2Y: 3.3; relativeX: 155.1; relativeY: 0 }' +
                'PathCubic { relativeControl1X: -16.5; relativeControl1Y: -9.9; relativeControl2X: -6; relativeControl2Y: -25.2; relativeX: 3.3; relativeY: -23.1 }' +
                'PathLine { relativeX: -29.7; relativeY: -6.6 } } }',
                this.parent);
            this.objectArray.push(wing);
        }
        else {
            let wing = Qt.createQmlObject(
                'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { ShapePath { ' +
                'fillColor: \"transparent\";' +
                'strokeColor: \"white\";' +
                'strokeWidth: 1.5;' +
                'PathMove { x: 179.49885; y: ' + (this.yStart - 0.75) + ' }' +
                'PathCubic { relativeControl1X: -16.66845; relativeControl1Y: -3.26145; relativeControl2X: -50.49885; relativeControl2Y: -8.85; relativeX: -76.33635; relativeY: -5.85 }' +
                'PathCubic { relativeControl1X: -72.6; relativeControl1Y: 9.9; relativeControl2X: -73.1625; relativeControl2Y: 42; relativeX: 3.3; relativeY: 46.2 }' +
                'PathCubic { relativeControl1X: 39.6; relativeControl1Y: 3.3; relativeControl2X: 89.1; relativeControl2Y: 3.3; relativeX: 155.1; relativeY: 0 }' +
                'PathCubic { relativeControl1X: -16.5; relativeControl1Y: -9.9; relativeControl2X: -6; relativeControl2Y: -25.2; relativeX: 3.3; relativeY: -23.1 }' +
                'PathCubic { relativeControl1X: -9.3; relativeControl1Y: -2.1; relativeControl2X: -25.0704; relativeControl2Y: -5.36295; relativeX: -29.2821; relativeY: -6.20085 }' +
                'PathLine { x: 179.49885; y: ' + (this.yStart - 0.75) + ' } } }',
                this.parent);
            this.objectArray.push(wing);
        }

        let flaps = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { ' +
            'transform: Rotation { angle: commonGaugeProperties.flapsAngle; origin.x: 269.8124972; origin.y: ' + (this.yStart + 28.05) + ' }' +
            'ShapePath { ' +
            'fillColor: \"white\";' +
            'strokeColor: \"transparent\";' +
            'PathMove { x: 270.5625; y: ' + (this.yStart + 37.95) + ' }' +
            'PathQuad { relativeControlX: -23.1; relativeControlY: -9.9; relativeX: 0; relativeY: -19.8 }' +
            'PathQuad { relativeControlX: 115.5; relativeControlY: 16.5; relativeX: 0; relativeY: 19.8 } } }',
            this.parent);
        this.objectArray.push(flaps);

        let flapsText = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'visible: commonGaugeProperties.showFlapsText;' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: 360.5624972;' +
            'anchors.baseline: parent.top;' +
            'anchors.baselineOffset: ' + (this.yStart + 39.6) + ';' +
            'anchors.alignWhenCentered: false;' +
            'renderType: Text.NativeRendering;' +
            'color: \"white\";' +
            'font.pixelSize: 23;' +
            'font.family: \"Roboto Mono\";' +
            'font.bold: true;' +
            'text: commonGaugeProperties.flapsValue }',
            this.parent);
        this.objectArray.push(flapsText);

        if (this.hasSpoilers)
        {
            let speedbrakes = Qt.createQmlObject(
                'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { ' +
                'transform: Rotation { angle: commonGaugeProperties.spoilersAngle; origin.x: 188.9624972; origin.y: ' + (this.yStart + 1.275) + ' }' +
                'ShapePath { ' +
                'fillColor: \"white\";' +
                'strokeColor: \"transparent\";' +
                'PathMove { x: 192.2625; y: ' + (this.yStart + 6.6) + ' }' +
                'PathQuad { relativeControlX: -14.025; relativeControlY: -6.6; relativeX: 0; relativeY: -9.9 }' +
                'PathQuad { relativeControlX: 74.25; relativeControlY: 14.85; relativeX: 0; relativeY: 9.9 } } }',
                this.parent);
            this.objectArray.push(speedbrakes);

            let spoilersText = Qt.createQmlObject(
                'import QtQuick 2.15; Text {' +
                'visible: commonGaugeProperties.showSpoilersText;' +
                'anchors.left: parent.left;' +
                'anchors.leftMargin: 233.5124972;' +
                'anchors.baseline: parent.top;' +
                'anchors.baselineOffset: ' + (this.yStart - 13.2) + ';' +
                'anchors.alignWhenCentered: false;' +
                'renderType: Text.NativeRendering;' +
                'color: \"white\";' +
                'font.pixelSize: 23;' +
                'font.family: \"Roboto Mono\";' +
                'font.bold: true;' +
                'text: commonGaugeProperties.spoilersValue }',
                this.parent);
            this.objectArray.push(spoilersText);
        }


        this.parent.data = this.objectArray;
    }
}