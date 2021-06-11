import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQuick.Layouts 1.15

Rectangle {
    visible: navInterface.gpsIsActiveFlightPlan
    anchors.left: parent.left
    anchors.leftMargin: 1267.2
    anchors.bottom: parent.bottom
    anchors.bottomMargin: 324
    width: 480
    height: 96
    color: "#1A1D21"


    Text {
        id: fromWp
        anchors.top: parent.top
        anchors.topMargin: 4.8
        anchors.left: parent.left
        anchors.leftMargin: 24
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: navInterface.currentLegFrom
    }

    Shape {
        anchors.verticalCenter: fromWp.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        height: 36
        width: 67.2

        //add D if direct to
        Shape {
            visible: navInterface.legIsDirectTo
            ShapePath
            {
                fillColor: "#D12BC7"
                strokeColor: "transparent"

                PathMove { x: 16.1; y: 3 }
                PathLine { x: 16.1; y: 33 }
                PathLine { x: 24.1; y: 33 }
                PathArc { radiusX: 15; radiusY: 15; direction: PathArc.Counterclockwise; x: 24.1; y: 3 }
                PathMove { x: 21.1; y: 8 }
                PathLine { x: 21.1; y: 28 }
                PathLine { x: 24.1; y: 28 }
                PathArc { radiusX: 10; radiusY: 10; direction: PathArc.Counterclockwise; x: 24.1; y: 8 }
            }
        }



        ShapePath
        {
            fillColor: "#D12BC7"
            strokeColor: "transparent"

            PathMove { x: 0; y: 12 }
            PathLine { x: 49.2; y: 12 }
            PathLine { x: 49.2; y: 0 }
            PathLine { x: 67.2; y: 18 }
            PathLine { x: 49.2; y: 36 }
            PathLine { x: 49.2; y: 24 }
            PathLine { x: 0; y: 24 }
        }
    }

    Text {
        id: toWp
        anchors.top: parent.top
        anchors.topMargin: 4.8
        anchors.right: parent.right
        anchors.rightMargin: 24
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: navInterface.currentLegTo
    }

    RowLayout {
        id: bottomInfos
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 4.8
        spacing: 0


        Text {
            Layout.leftMargin: 9.6
            Layout.rightMargin: 9.6
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 28
            font.bold: true
            text: "DIS"
        }

        Text {
            Layout.leftMargin: 9.6
            Layout.rightMargin: 9.6
            color: "#D12BC7"
            font.family: "Roboto Mono"
            font.pixelSize: 28
            font.bold: true
            text: navInterface.currentLegDistance
        }

        Text {
            Layout.leftMargin: 9.6
            Layout.rightMargin: 9.6
            color: "white"
            font.family: "Roboto Mono"
            font.pixelSize: 28
            font.bold: true
            text: "BRG"
        }

        Text {
            Layout.leftMargin: 9.6
            Layout.rightMargin: 9.6
            color: "#D12BC7"
            font.family: "Roboto Mono"
            font.pixelSize: 28
            font.bold: true
            text: navInterface.currentLegBearing
        }
    }
}


