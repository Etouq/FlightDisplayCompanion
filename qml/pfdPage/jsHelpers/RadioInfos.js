class ComInfos {
    constructor() {
        this.scaleFactor = 1;
    }

    completedCallback(_parent) {
        let background = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'anchors.right: parent.right;' +
            'anchors.rightMargin: ' + (-18 * this.scaleFactor) + ';' +
            'y: ' + (-18 * this.scaleFactor) + ';' +
            'width: ' + (248.4 * this.scaleFactor) + ';' +
            'height: ' + (114 * this.scaleFactor) + ';' +
            'radius: ' + (18 * this.scaleFactor) + ';' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(background);

        let com1Text = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (11.52 * this.scaleFactor) + ';' +
            'anchors.top: parent.top;' +
            'anchors.topMargin: ' + (4.8 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (30 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'visible: radioInterface.hasComm1;' +
            'enabled: radioInterface.hasComm1;' +
            'text: "COM1" }',
            _parent);
        _parent.data.push(com1Text);

        this.com1Freq = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.right: parent.right;' +
            'anchors.rightMargin: ' + (11.52 * this.scaleFactor) + ';' +
            'anchors.top: parent.top;' +
            'anchors.topMargin: ' + (4.8 * this.scaleFactor) + ';' +
            'color: "green";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (30 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'visible: radioInterface.hasComm1;' +
            'enabled: radioInterface.hasComm1;' +
            'text: radioInterface.comm1Freq.toFixed(3) }',
            _parent);
        _parent.data.push(this.com1Freq);

        let com2Text = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (11.52 * this.scaleFactor) + ';' +
            'anchors.bottom: parent.bottom;' +
            'anchors.bottomMargin: ' + (4.8 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (30 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'visible: radioInterface.hasComm2;' +
            'enabled: radioInterface.hasComm2;' +
            'text: "COM2" }',
            _parent);
        _parent.data.push(com2Text);

        this.com2Freq = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.right: parent.right;' +
            'anchors.rightMargin: ' + (11.52 * this.scaleFactor) + ';' +
            'anchors.bottom: parent.bottom;' +
            'anchors.bottomMargin: ' + (4.8 * this.scaleFactor) + ';' +
            'color: "green";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (30 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'visible: radioInterface.hasComm2;' +
            'enabled: radioInterface.hasComm2;' +
            'text: radioInterface.comm2Freq.toFixed(3) }',
            _parent);
        _parent.data.push(this.com2Freq);
    }
}

class NavFreqInfos {
    constructor() {
        this.scaleFactor = 1;
    }

    completedCallback(_parent) {
        let background = Qt.createQmlObject(
            'import QtQuick 2.15; Rectangle {' +
            'x: ' + (-18 * this.scaleFactor) + ';' +
            'y: ' + (-18 * this.scaleFactor) + ';' +
            'width: ' + (248.4 * this.scaleFactor) + ';' +
            'height: ' + (114 * this.scaleFactor) + ';' +
            'radius: ' + (18 * this.scaleFactor) + ';' +
            'color: "#1A1D21" }',
            _parent);
        _parent.data.push(background);

        let nav1Text = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (11.52 * this.scaleFactor) + ';' +
            'anchors.top: parent.top;' +
            'anchors.topMargin: ' + (4.8 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (30 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'visible: radioInterface.hasNav1;' +
            'enabled: radioInterface.hasNav1;' +
            'text: "NAV1" }',
            _parent);
        _parent.data.push(nav1Text);

        this.nav1Freq = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.right: parent.right;' +
            'anchors.rightMargin: ' + (11.52 * this.scaleFactor) + ';' +
            'anchors.top: parent.top;' +
            'anchors.topMargin: ' + (4.8 * this.scaleFactor) + ';' +
            'color: "green";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (30 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'visible: radioInterface.hasNav1;' +
            'enabled: radioInterface.hasNav1;' +
            'text: radioInterface.nav1Freq.toFixed(2) }',
            _parent);
        _parent.data.push(this.nav1Freq);

        let nav2Text = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.left: parent.left;' +
            'anchors.leftMargin: ' + (11.52 * this.scaleFactor) + ';' +
            'anchors.bottom: parent.bottom;' +
            'anchors.bottomMargin: ' + (4.8 * this.scaleFactor) + ';' +
            'color: "white";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (30 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'visible: radioInterface.hasNav2;' +
            'enabled: radioInterface.hasNav2;' +
            'text: "NAV2" }',
            _parent);
        _parent.data.push(nav2Text);

        this.nav2Freq = Qt.createQmlObject(
            'import QtQuick 2.15; Text {' +
            'anchors.right: parent.right;' +
            'anchors.rightMargin: ' + (11.52 * this.scaleFactor) + ';' +
            'anchors.bottom: parent.bottom;' +
            'anchors.bottomMargin: ' + (4.8 * this.scaleFactor) + ';' +
            'color: "green";' +
            'font.family: "Roboto Mono";' +
            'font.pixelSize: ' + (30 * this.scaleFactor).toFixed(0) + ';' +
            'font.bold: true;' +
            'visible: radioInterface.hasNav2;' +
            'enabled: radioInterface.hasNav2;' +
            'text: radioInterface.nav2Freq.toFixed(2) }',
            _parent);
        _parent.data.push(this.nav2Freq);
    }
}
