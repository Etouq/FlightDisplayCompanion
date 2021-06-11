import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "jsHelpers/AirspeedIndicator.js" as AirspeedIndicatorJs
import "jsHelpers/AttitudeIndicator.js" as AttitudeIndicatorJs
import "jsHelpers/Altimeter.js" as AltimeterJs
import "jsHelpers/HSIndicator.js" as HSIndicatorJs
import "jsHelpers/WindDataDisplay.js" as WindDataDisplayJs
import "jsHelpers/AngleOfAttackIndicator.js" as AngleOfAttackIndicatorJs
import "jsHelpers/AutopilotInfos.js" as AutopilotInfosJs
import "jsHelpers/RadioInfos.js" as RadioInfosJs

Item {

    property int windMode: 0
    property int bearing1Mode: 0
    property int bearing2Mode: 0
    property int dmeMode: 0
    property int temperatureUnit: 0
    property int pressureUnit: 0

    property int airspeedLastCallTime: 0

    property var attItem: new AttitudeIndicatorJs.AttitudeIndicator()
    property var altItem: new AltimeterJs.Altimeter()
    property var iasItem: new AirspeedIndicatorJs.AirspeedIndicator()
    property var hsiItem: new HSIndicatorJs.HSIndicator()
    property var windItem: new WindDataDisplayJs.WindDataDisplay()
    property var aoaItem: new AngleOfAttackIndicatorJs.AOAIndicator()
    property var apInfoItem: new AutopilotInfosJs.AutopilotInfos()
    property var comInfoItem: new RadioInfosJs.ComInfos()
    property var navFreqInfoItem: new RadioInfosJs.NavFreqInfos()

    Component.onCompleted: {
        airspeedLastCallTime = new Date().getTime();
    }

    Connections
    {
        target: iasInterface
        function onAirspeedChanged() {
            let newTime = new Date().getTime();
            let deltaTime = newTime - airspeedLastCallTime;
            airspeedLastCallTime = newTime;

            iasItem.update(iasInterface.airspeed, deltaTime);
        }
    }

    Connections
    {
        target: iasInterface
        function onColorsChanged() {
            iasItem.updateColors(iasInterface.getRedBegin(), iasInterface.getRedEnd(), iasInterface.getGreenBegin(), iasInterface.getGreenEnd(), iasInterface.getFlapsBegin(), iasInterface.getFlapsEnd(), iasInterface.getYellowBegin(), iasInterface.getYellowEnd(), iasInterface.getMinSpeed(), iasInterface.getNoColor());
            iasItem.update(iasInterface.airspeed);
        }
    }

    Connections
    {
        target: altInterface
        function onAltitudeChanged() { altItem.update(altInterface.altitude); }
    }

    Connections {
        target: settingsInterface
        function onTemperatureUnitChanged() {
            temperatureUnit = settingsInterface.getTemperatureUnit();
        }
    }

    Connections {
        target: settingsInterface
        function onPressureUnitChanged() {
            pressureUnit = settingsInterface.getPressureUnit();
        }
    }



    Item {
        id: attParent
        width: 576
        height: 432
        anchors.top: parent.top
        anchors.topMargin: 150
        anchors.left: parent.left
        anchors.leftMargin: 672

        Component.onCompleted:
        {
            pfdPageId.attItem.completedCallback(attParent);
        }
    }

    Shape {
        id: altParent
        width: 380 * 0.96
        height: 700 * 0.96
        anchors.left: parent.left
        anchors.leftMargin: 1344
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 432

        Component.onCompleted: {
            pfdPageId.altItem.completedCallback(altParent);
            pfdPageId.altItem.update(0);
        }
    }

    Item {
        id: iasParent
        width: 250 * 0.96
        height: 700 * 0.96
        anchors.right: parent.right
        anchors.rightMargin: 1344
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 432

        Component.onCompleted:
        {
            pfdPageId.iasItem.completedCallback(iasParent);
            pfdPageId.iasItem.updateColors(iasInterface.getRedBegin(), iasInterface.getRedEnd(), iasInterface.getGreenBegin(), iasInterface.getGreenEnd(), iasInterface.getFlapsBegin(), iasInterface.getFlapsEnd(), iasInterface.getYellowBegin(), iasInterface.getYellowEnd(), iasInterface.getMinSpeed(), iasInterface.getNoColor());
            pfdPageId.iasItem.update(20);
        }
    }


    Shape {
        id: bottomBar
        ShapePath
        {
            fillColor: "#1A1D21"
            strokeColor: "transparent"

            PathMove { x: 0; y: hsiParent.y + (65 - 57 * Math.sin(-0.6)) * 691.2 / 156 }
            PathLine { x: 0; y: 1200 }
            PathLine { x: 1920; y: 1200 }
            PathLine { x: 1920; y: hsiParent.y + (65 - 57 * Math.sin(-0.6)) * 691.2 / 156 }
            PathLine { x: hsiParent.x + (78 - 57 * Math.cos(Math.PI + 0.6)) * 691.2 / 156; relativeY: 0 }
            PathArc { radiusX: 57 * 691.2 / 156; radiusY: 57 * 691.2 / 156; x: hsiParent.x + (78 - 57 * Math.cos(-0.6)) * 691.2 / 156; relativeY: 0}
        }

        Text {
            id: gsTitle
            anchors.left: parent.left
            anchors.leftMargin: 12.21696
            anchors.top: parent.top
            anchors.topMargin: hsiParent.y + (65 - 57 * Math.sin(-0.6)) * 691.2 / 156
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true
            text: "GS"
        }

        Text {
            id: gsValue
            anchors.right: parent.left
            anchors.rightMargin: -191.39904
            anchors.top: parent.top
            anchors.topMargin: hsiParent.y + (65 - 57 * Math.sin(-0.6)) * 691.2 / 156
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true
            text: bottomInterface.groundSpeed + "KT"
        }

        Text {
            id: tatTitle
            anchors.left: parent.left
            anchors.leftMargin: 12.21696
            anchors.bottom: parent.top
            anchors.bottomMargin: -1200
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true
            text: "TAT"
        }

        Text {
            id: tatValue
            anchors.right: parent.left
            anchors.rightMargin: -191.39904
            anchors.bottom: parent.top
            anchors.bottomMargin: -1200
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true
            text: temperatureUnit == 0 ? (bottomInterface.totalAirTemp + "ºC") : temperatureUnit == 1 ? (Math.round(bottomInterface.totalAirTemp * 1.8 + 32.0) + "ºF") : temperatureUnit == 2 ? (bottomInterface.totalAirTemp + 273 + "K") : (Math.round((bottomInterface.totalAirTemp + 273.15) * 1.8) + "ºR")
        }

        Rectangle {
            x: 201.216
            y: hsiParent.y + (65 - 57 * Math.sin(-0.6)) * 691.2 / 156
            width: 4.8
            height: 1200 - y
            color: "white"
        }

        Text {
            id: utcTitle
            anchors.left: parent.left
            anchors.leftMargin: 1423.3728
            anchors.top: parent.top
            anchors.topMargin: hsiParent.y + (65 - 57 * Math.sin(-0.6)) * 691.2 / 156
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true
            text: "UTC"
        }

        Text {
            id: utcValue
            anchors.right: parent.left
            anchors.rightMargin: -1687.104
            anchors.top: parent.top
            anchors.topMargin: hsiParent.y + (65 - 57 * Math.sin(-0.6)) * 691.2 / 156
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true
            text: bottomInterface.zuluTime
        }

        Text {
            id: lclTitle
            anchors.left: parent.left
            anchors.leftMargin: 1423.3728
            anchors.bottom: parent.top
            anchors.bottomMargin: -1200
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true
            text: "LCL"
        }

        Text {
            id: lclValue
            anchors.right: parent.left
            anchors.rightMargin: -1687.104
            anchors.bottom: parent.top
            anchors.bottomMargin: -1200
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true
            text: bottomInterface.localTime
        }
    }

    Item {
        id: hsiParent
        height: 116 * 691.2 / 156
        anchors.left: parent.left
        anchors.leftMargin: 614.4
        anchors.right: parent.right
        anchors.rightMargin: 614.4
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 22.2


        Component.onCompleted: pfdPageId.hsiItem.completedCallback(hsiParent);
    }

    Item {
        id: windDataParent
        anchors.left: parent.left
        anchors.leftMargin: 576
        anchors.top: parent.top
        anchors.topMargin: 769.8
        width: 1.5 * 90
        height: 1.5 * 60
        TapHandler {
            onTapped: {
                if (windMode >= 3)
                    windMode = 0;
                else
                    windMode++;
            }
        }


        Component.onCompleted: pfdPageId.windItem.completedCallback(windDataParent);
    }

    Item {
        id: aoaParent
        anchors.right: parent.right
        anchors.rightMargin: 1392
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 228
        width: 192
        height: 192


        Component.onCompleted: pfdPageId.aoaItem.completedCallback(aoaParent);
    }

    Item {
        id: apInfoParent
        visible: apInterface.has_ap
        anchors.left: parent.left
        anchors.leftMargin: 633.6
        anchors.top: parent.top
        width: 652.8
        height: 96


        Component.onCompleted: pfdPageId.apInfoItem.completedCallback(apInfoParent);
    }

    Item {
        id: comInfoParent
        anchors.right: parent.right
        anchors.top: parent.top
        width: 230.4
        height: 96
        visible: radioInterface.hasComm1 || radioInterface.hasComm2


        Component.onCompleted: pfdPageId.comInfoItem.completedCallback(comInfoParent);
    }

    Item {
        id: navFreqInfoParent
        anchors.left: parent.left
        anchors.top: parent.top
        width: 230.4
        height: 96
        visible: radioInterface.hasNav1 || radioInterface.hasNav2


        Component.onCompleted: pfdPageId.navFreqInfoItem.completedCallback(navFreqInfoParent);
    }

    NavInfoItem {

    }

    RadarAltitudeItem {

    }


}

