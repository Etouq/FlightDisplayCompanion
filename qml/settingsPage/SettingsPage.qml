import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQml 2.15

import "flightplan"
import "connection"

Item {
    id: root

    property bool simStarted: false

    function setEditModeInactive() {
        flightPlan.editModeActive = false;
        flightPlan.insertModeActive = false;
        flightPlan.selectedItemIdx = -1;
    }

    Connections
    {
        target: netInterface
        function onConnectedChanged() {
            if (netInterface.connected !== 1)
                simStarted = false;
        }
    }

    Connections {
        target: netInterface
        function onSimConnectClosed() {
            simStarted = false;
        }
    }


    Connections {
        target: netInterface
        function onErrorStringChanged() {
            if (netInterface.errorString !== "") {
                errorDrawer.open()
                drawerCloseTimer.restart();
            }
        }
    }


    Rectangle {
        anchors.fill: parent
        color: "#c4c5c6"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.forceActiveFocus();
            root.setEditModeInactive();
        }
    }

    ConnectionInput { }

    Timer {
        id: drawerCloseTimer
        repeat: false
        running: false
        interval: 4750
        onTriggered: errorDrawer.close()
    }

    Drawer {
        id: errorDrawer
        edge: Qt.LeftEdge
        y: 100
        modal: false
        interactive: false

        background: Item {}


        Label {
            background: Rectangle {
                color: "white"
                width: parent.contentWidth + 10
                height: parent.contentHeight + 5
                border.color: "transparent"
            }
            color: "red"
            font.pixelSize: 24
            font.family: "Roboto"
            width: 400
            text: netInterface.errorString
            wrapMode: Text.WordWrap
            topPadding: 2.5
            bottomPadding: 2.5
            leftPadding: 5
            rightPadding: 5
        }

        Behavior on position {
            NumberAnimation { duration: 750 }
        }

    }

    ThumbnailView {
        id: thumbnails
    }

    Button {
        id: selectAircraft
        x: 965
        y: 100
        width: 250
        height: 100

        background: Rectangle {
            color: selectAircraft.enabled ? (selectAircraft.pressed ? "white" : "#00b4ff") : "#949595"
            radius: 6

            Rectangle {
                anchors.fill: parent
                color: "white"
                opacity: 0.24
                visible: selectAircraft.visualFocus && !selectAircraft.pressed
            }
        }

        contentItem: Text {
            text: !simStarted ? "Start" : "Change Aircraft"
            color: selectAircraft.enabled ? (selectAircraft.pressed ? "#00b4ff" : "white") : "#666767"
            font.family: "Roboto Mono"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 24
        }

        enabled: thumbnails.selectedAircraftName != "" && netInterface.connected === 1 && !netInterface.serverIsDesigner;
        onClicked: {
            if (!simStarted)
                aircraftInterface.startupSim();
            else
                aircraftInterface.sendSelectedAircraftToSim();
            simStarted = true;

        }
    }

    FlightplanPage {
        id: flightPlan
        x: 35
        y: 400
    }


    StyledCheckBox {
        id: fuelRangeCheck
        x: 50
        y: 250
        width: 325
        text: "Show Fuel Range Circle"
        Component.onCompleted: checked = settingsInterface.getShowMapFuelRange()
        onCheckedChanged: settingsInterface.setShowMapFuelRange(checked)
    }

    StyledCheckBox {
        id: rangeCircleCheck
        x: 50
        y: 280
        width: 325
        text: "Show Range Circles"
        Component.onCompleted: checked = settingsInterface.getShowRangeRings()
        onCheckedChanged: settingsInterface.setShowRangeRings(checked)
    }

    StyledCheckBox {
        id: rangeTextCheck
        x: 50
        y: 310
        width: 325
        text: "Show Range Circle Labels"
        enabled: rangeCircleCheck.checked
        Component.onCompleted: checked = settingsInterface.getShowRangeRingText()
        onCheckedChanged: settingsInterface.setShowRangeRingText(checked)
    }

    StyledComboBox {
        id: temperatureBox
        title: "Temperature Unit"
        overrideEnterHandler: true
        model: ["Celsius", "Fahrenheit", "Kelvin", "Rankine"]
        currentIndex: 0
        x: 385
        y: 250
        Component.onCompleted: currentIndex = settingsInterface.getTemperatureUnit()
        onCurrentIndexChanged: settingsInterface.setTemperatureUnit(currentIndex)
    }

    StyledComboBox {
        id: pressureBox
        title: "Altimeter Unit"
        overrideEnterHandler: true
        model: ["Inch of Mercury", "Millibar"]
        currentIndex: 0
        x: 645
        y: 250
        Component.onCompleted: currentIndex = settingsInterface.getPressureUnit()
        onCurrentIndexChanged: settingsInterface.setPressureUnit(currentIndex)
    }



}
