import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {

    AirspeedReferenceGroup {
    }

    Rectangle {
        y: 48
        width: 192
        height: 576
        color: "#1a1d21"
        opacity: 0.25
    }

    CenterItem {
        y: 48
        width: 240
        height: 576
        clip: true
    }

    Cursor {
    }

    Rectangle {
        id: trendElement
        x: 192
        y: 47.04
        width: 7.68
        height: 50
        color: "#d12bc7"
    }

    Rectangle {
        y: 624
        width: 192
        height: 48
        color: "#1a1d21"
    }

    Text {
        x: 4.8
        anchors.baseline: parent.top
        anchors.baselineOffset: 660.48
        color: "white"
        font.bold: true
        font.family: "Roboto Mono"
        font.pixelSize: 34
        text: "TAS"
    }

    Text {
        anchors.right: parent.right
        anchors.rightMargin: 52.8
        anchors.baseline: parent.top
        anchors.baselineOffset: 660.48
        color: "white"
        font.bold: true
        font.family: "Roboto Mono"
        font.pixelSize: 34
        text: iasInterface.trueAirspeed + "KT"
    }

    property real acceleration: 0
    property real lastSpeed: -1
    property real lastCallTime: -1

    Component.onCompleted: { lastCallTime = new Date().getTime() }

    function updateAcceleration(_newSpeed) {
        if (lastSpeed < 0)
            lastSpeed = _newSpeed;

        let newCallTime = new Date().getTime();
        let deltaTime = newCallTime - lastCallTime;
        lastCallTime = newCallTime;

        let instantAcceleration = 0;
        if (_newSpeed < 20) {
            instantAcceleration = 0;
            acceleration = 0;
        }
        else {
            instantAcceleration = (_newSpeed - lastSpeed) / (deltaTime / 1000);
        }
        acceleration = (Math.max(2000 - deltaTime, 0) * acceleration + Math.min(deltaTime, 2000) * instantAcceleration) / 2000;
        lastSpeed = _newSpeed;
        let trendValue = Math.min(Math.max(300 + acceleration * -60, 0), 600);
        trendElement.y = Math.min(trendValue * 0.96 + 48, 336);
        trendElement.height = Math.abs(trendValue - 300) * 0.96;
    }

    Connections {
        target: iasInterface
        function onAirspeedChanged() {
            updateAcceleration(iasInterface.airspeed);
        }
    }

}
