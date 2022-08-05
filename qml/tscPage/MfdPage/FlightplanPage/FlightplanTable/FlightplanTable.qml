import QtQuick 2.15
import QtQuick.Controls 2.15

import Mfd.Flightplan 1.0


Rectangle {
    id: tableRoot

    width: flightplanTableView.width + 7//913
    height: flightplanTableView.height + headerRow.height + 14//width * 525 / 913

    color: "black"
    border.color: "white"

    border.width: 4

    signal elementClicked(int index)

    FontMetrics {
        id: fontMetrics
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: 45
    }

    Row {
        id: headerRow

        readonly property real cellPadding: 8
        readonly property real borderWidth: 1

        anchors.left: flightplanTableView.left
        anchors.leftMargin: headerRow.borderWidth + headerRow.cellPadding + 15
        anchors.bottom: flightplanTableView.top
        anchors.bottomMargin: 8
        height: 60

        spacing: headerRow.borderWidth + headerRow.cellPadding * 2 + 30

        Text {
            id: fpTitle
            width: 45 + (120 - 2 * (headerRow.cellPadding + headerRow.borderWidth)) + fontMetrics.boundingRect("A".repeat(9)).width - 15 - headerRow.cellPadding
            height: 60

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 45

            color: "white"
            text: FlightplanModel.getTitle()
        }

        Text {
            width: fontMetrics.boundingRect("A00000FT").width
            height: 60

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 45

            color: "white"
            text: "ALT"
        }

        Text {
            width: fontMetrics.boundingRect("000°").width
            height: 60

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 45

            color: "white"
            text: "DTK"
        }

        Text {
            width: fontMetrics.boundingRect("00.0NM").width
            height: 60

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 45

            color: "white"
            text: "DIST"
        }

        Text {
            width: fontMetrics.boundingRect("___KT").width
            height: 60

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 45

            color: "white"
            text: "SPD"
        }
    }

    FlightplanTableElement {
        id: flightplanTableView
        anchors.left: parent.left
        anchors.leftMargin: 3
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 3

        onElementClicked: function(index) {
            tableRoot.elementClicked(index);
        }
    }

    Rectangle {
        anchors.left: flightplanTableView.left
        anchors.right: parent.right
        anchors.top: flightplanTableView.top
        height: 1

        color: "white"
    }

    Rectangle {
        anchors.right: flightplanTableView.right
        anchors.rightMargin: 36
        anchors.top: flightplanTableView.top
        anchors.bottom: flightplanTableView.bottom
        width: 1

        color: "white"
    }

    Connections {
        target: FlightplanModel
        function onFlightplanTitleChanged() {
            fpTitle.text = FlightplanModel.getTitle();
        }
    }


}
