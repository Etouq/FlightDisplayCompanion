class AutopilotInfos {
    constructor() {
        this.scaleFactor = 1;
    }


    completedCallback(_parent) {
        let background = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: 0;' +
            'y: ' + (-18 * this.scaleFactor) + ';' +
            'width: ' + (652.8 * this.scaleFactor) + ';' +
            'height: ' + (114 * this.scaleFactor) + ';' +
            'radius: ' + (18 * this.scaleFactor) + ';' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(background);

        this.ap_lateralActive = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (78.336 * this.scaleFactor) + ';' +
            'anchors.top: parent.top;' +
            'anchors.topMargin: ' + (0.96 * this.scaleFactor) + ';' +
            'color: "green";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (42 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: apInterface.ap_lateralActive }',
            _parent);
        _parent.data.push(this.ap_lateralActive);

        this.ap_lateralArmed = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (78.336 * this.scaleFactor) + ';' +
            'anchors.bottom: parent.bottom;' +
            'anchors.bottomMargin: ' + (7.68 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (36 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: apInterface.ap_lateralArmed }',
            _parent);
        _parent.data.push(this.ap_lateralArmed);


        let borderLeft = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (160.8 * this.scaleFactor) + ';' +
            'y: 0;' +
            'width: ' + (4.8 * this.scaleFactor) + ';' +
            'height: ' + (96 * this.scaleFactor) + ';' +
            'color: "white" }',
            _parent);
        _parent.data.push(borderLeft);

        let borderRight = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (324 * this.scaleFactor) + ';' +
            'y: 0;' +
            'width: ' + (4.8 * this.scaleFactor) + ';' +
            'height: ' + (96 * this.scaleFactor) + ';' +
            'color: "white" }',
            _parent);
        _parent.data.push(borderRight);


        this.ap_status = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (204 * this.scaleFactor) + ';' +
            'anchors.top: parent.top;' +
            'anchors.topMargin: ' + (0.96 * this.scaleFactor) + ';' +
            'color: "green";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (42 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: apInterface.ap_status ? "AP" : "" }',
            _parent);
        _parent.data.push(this.ap_status);

        this.ap_YdStatus = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (285.6 * this.scaleFactor) + ';' +
            'anchors.top: parent.top;' +
            'anchors.topMargin: ' + (0.96 * this.scaleFactor) + ';' +
            'color: "green";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (42 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: apInterface.ap_ydStatus ? "YD" : "" }',
            _parent);
        _parent.data.push(this.ap_YdStatus);

        this.ap_FDIndicatorArrow = Qt.createQmlObject(
            'import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape { visible: apInterface.ap_fdActive;' +
            'ShapePath {' +
            'fillColor: "green";' +
            'strokeColor: "transparent";' +
            'PathMove { x: ' + (204.036 * this.scaleFactor) + '; y: ' + (71.4 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (15 * this.scaleFactor) + '; relativeY: ' + (-15 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (0 * this.scaleFactor) + '; relativeY: ' + (18 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (60 * this.scaleFactor) + '; relativeY: ' + (0 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (0 * this.scaleFactor) + '; relativeY: ' + (-6 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (-60 * this.scaleFactor) + '; relativeY: ' + (0 * this.scaleFactor) + ' }' +
            'PathLine { relativeX: ' + (0 * this.scaleFactor) + '; relativeY: ' + (18 * this.scaleFactor) + ' } } }',
            _parent);
        _parent.data.push(this.ap_FDIndicatorArrow);




        this.ap_verticalActive = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (398.208 * this.scaleFactor) + ';' +
            'anchors.top: parent.top;' +
            'anchors.topMargin: ' + (0.96 * this.scaleFactor) + ';' +
            'color: "green";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (42 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: apInterface.ap_verticalActive }',
            _parent);
        _parent.data.push(this.ap_verticalActive);

        this.ap_modeReference = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.horizontalCenter: parent.right;' +
            'anchors.horizontalCenterOffset: ' + (-84.864 * this.scaleFactor) + ';' +
            'anchors.top: parent.top;' +
            'anchors.topMargin: ' + (0.96 * this.scaleFactor) + ';' +
            'color: "green";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (36 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: apInterface.ap_modeReference }',
            _parent);
        _parent.data.push(this.ap_modeReference);

        this.ap_armed = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.horizontalCenter: parent.left;' +
            'anchors.horizontalCenterOffset: ' + (398.208 * this.scaleFactor) + ';' +
            'anchors.bottom: parent.bottom;' +
            'anchors.bottomMargin: ' + (7.68 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (36 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: apInterface.ap_armed }',
            _parent);
        _parent.data.push(this.ap_armed);

        this.ap_armedReference = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.horizontalCenter: parent.right;' +
            'anchors.horizontalCenterOffset: ' + (-84.864 * this.scaleFactor) + ';' +
            'anchors.bottom: parent.bottom;' +
            'anchors.bottomMargin: ' + (7.68 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (36 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'text: apInterface.ap_armedReference }',
            _parent);
        _parent.data.push(this.ap_armedReference);
    }










}
