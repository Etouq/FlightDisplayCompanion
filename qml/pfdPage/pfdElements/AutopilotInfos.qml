import QtQuick 2.15
import QtQuick.Shapes 1.15

Rectangle {
    width: 652.8
    height: 114
    radius: 18
    x: 633.6
    y: -18
    color: "#1A1D21"
    visible: apInterface.has_ap

    Item {
        id: left
        width: 156.672
        height: 96
        y: 18
        x: 0

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            y: 0.96
            color: "green"
            font.pixelSize: 42
            font.family: "Roboto Mono"
            font.bold: true
            text: apInterface.ap_lateralActive
        }

        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 7.68
            color: "white"
            font.pixelSize: 36
            font.family: "Roboto Mono"
            font.bold: true
            text: apInterface.ap_lateralArmed
        }
    }

    Item {
        id: center
        width: 156.672
        height: 96
        y: 18
        x: 163.2

        Rectangle {
            x: -4.8
            width: 4.8
            height: 96
            color: "white"
        }

        Rectangle {
            x: 156.672
            width: 4.8
            height: 96
            color: "white"
        }

        Text {
            width: 78.336
            horizontalAlignment: Text.AlignHCenter
            y: 0.96
            color: "green"
            font.pixelSize: 42
            font.family: "Roboto Mono"
            font.bold: true
            text: "AP"
            visible: apInterface.ap_status
        }

        Text {
            width: 78.336
            horizontalAlignment: Text.AlignHCenter
            anchors.right: parent.right
            y: 0.96
            color: "green"
            font.pixelSize: 42
            font.family: "Roboto Mono"
            font.bold: true
            text: "YD"
            visible: apInterface.ap_ydStatus
        }

        Image {
            x: 39.168
            y: 55.0656
            visible: apInterface.ap_fdActive
            width: 78.336
            height: 31.3344
            source: "qrc:/images/fdArrow.png"
        }

    }

    Item {
        id: right
        width: 339.456
        height: 96
        y: 18
        x: 313.344

        Text {
            width: 169.728
            horizontalAlignment: Text.AlignHCenter
            y: 0.96
            color: "green"
            font.pixelSize: 42
            font.family: "Roboto Mono"
            font.bold: true
            text: apInterface.ap_verticalActive
        }

        Text {
            width: 169.728
            horizontalAlignment: Text.AlignHCenter
            anchors.right: parent.right
            y: 0.96
            color: "green"
            font.pixelSize: 36
            font.family: "Roboto Mono"
            font.bold: true
            text: apInterface.ap_modeReference
        }

        Text {
            width: 169.728
            horizontalAlignment: Text.AlignHCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 7.68
            color: "white"
            font.pixelSize: 36
            font.family: "Roboto Mono"
            font.bold: true
            text: apInterface.ap_armed
        }

        Text {
            width: 169.728
            horizontalAlignment: Text.AlignHCenter
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 7.68
            color: "white"
            font.pixelSize: 36
            font.family: "Roboto Mono"
            font.bold: true
            text: apInterface.ap_armedReference
        }
    }
}
