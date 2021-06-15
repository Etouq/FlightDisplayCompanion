import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "jsHelpers/AirspeedIndicator.js" as AirspeedIndicatorJs
import "jsHelpers/AttitudeIndicator.js" as AttitudeIndicatorJs
import "jsHelpers/Altimeter.js" as AltimeterJs
import "jsHelpers/HSIndicator.js" as HSIndicatorJs
import "pfdElements"

Item {

    property int bearing1Mode: 0
    property int bearing2Mode: 0
    property int dmeMode: 0
    property int pressureUnit: 0

    property int airspeedLastCallTime: 0

    property var attItem: new AttitudeIndicatorJs.AttitudeIndicator()
    property var altItem: new AltimeterJs.Altimeter()
    property var iasItem: new AirspeedIndicatorJs.AirspeedIndicator()
    property var hsiItem: new HSIndicatorJs.HSIndicator()

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

    BottomBar {

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


    WindDataDisplay {
        x: 576
        y: 769.8
    }

    AngleOfAttackIndicator {
        anchors.right: parent.right
        anchors.rightMargin: 1392
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 228
    }

    AutopilotInfos {
    }

    ComInfos {

    }

    NavFreqInfos {

    }

    NavInfos {

    }

    RadarAltitude {

    }


}

