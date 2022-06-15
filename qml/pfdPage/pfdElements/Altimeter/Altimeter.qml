import QtQuick 2.15

Item {

    Loader {
        active: altInterface.verticalDeviationMode !== 0
        sourceComponent: VerticalDeviationGroup {
        }
    }

    Loader {
        active: apInterface.has_ap
        sourceComponent: SelectedAltitudeGroup {
        }
    }

    Rectangle {
        x: 48
        y: 48
        width: 192
        height: 576
        color: "#1a1d21"
        opacity: 0.25
    }

    GraduationItem {
        x: 48
        y: 48
        width: 192
        height: 576
        clip: true
    }

    Rectangle {
        x: 48
        y: Math.min(altInterface.altitudeTrendValue, 240)
        width: 7.68
        height: Math.abs(altInterface.altitudeTrendValue - 240)
        color: "#d12bc7"
    }

    Rectangle {
        x: 48
        y: 624
        width: 240
        height: 48
        color: "#1a1d21"
    }

    Text {
        id: baroText
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 168
        anchors.baseline: parent.top
        anchors.baselineOffset: 662.4
        color: "#36c8d2"
        font.bold: true
        font.family: "Roboto Mono"
        font.pixelSize: 43
        text: altInterface.pressure.toFixed(2) + "IN"

        Connections {
            target: settingsInterface
            function onPressureUnitChanged() {
                if (settingsInterface.getPressureUnit() === 0)
                    baroText.text = Qt.binding(function() { return altInterface.pressure.toFixed(2) + "IN" });
                else
                    baroText.text = Qt.binding(function() { return Math.round(altInterface.pressure * 33.8639) + "MB" });
            }
        }
    }

    VerticalSpeedGroup {
    }

}
