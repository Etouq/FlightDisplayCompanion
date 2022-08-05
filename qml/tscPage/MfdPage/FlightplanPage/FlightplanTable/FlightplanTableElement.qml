import QtQuick 2.15
import QtQuick.Controls 2.15

import TypeEnums 1.0
import Mfd.Flightplan 1.0

import "private"

ListView {
    id: flightplanTableView

    property int showCount: 6


    signal elementClicked(int index)

    clip: true

    width: contentWidth + 36
    height: 120 + (flightplanTableView.showCount - 1) * 118
    contentWidth: flightplanTableView.identCellWidth + flightplanTableView.altCellWidth + flightplanTableView.dtkCellWidth + flightplanTableView.distCellWidth + flightplanTableView.speedCellWidth + 6 * flightplanTableView.borderWidth + 10 * flightplanTableView.cellPadding

    spacing: -1
    reuseItems: true

    model: FlightplanModel

    boundsBehavior: Flickable.StopAtBounds

    FontMetrics {
        id: fontMetrics
        font.family: "Roboto Mono"
        font.bold: true
        font.pixelSize: 45
    }

    readonly property real cellPadding: 8
    readonly property real borderWidth: 1
    readonly property real contentHeight: 120 - 2 * (flightplanTableView.cellPadding + flightplanTableView.borderWidth)
    readonly property real identCellWidth: 45 + flightplanTableView.contentHeight + fontMetrics.boundingRect("A".repeat(9)).width + 15 - flightplanTableView.cellPadding
    readonly property real altCellWidth: fontMetrics.boundingRect("A00000FT").width + 30
    readonly property real dtkCellWidth: fontMetrics.boundingRect("000°").width + 30
    readonly property real distCellWidth: fontMetrics.boundingRect("00.0NM").width + 30
    readonly property real speedCellWidth: fontMetrics.boundingRect("___KT").width + 30


    ScrollBar.vertical: ScrollBar {
        anchors.right: flightplanTableView.right
        anchors.rightMargin: 9
        policy: ScrollBar.AlwaysOn
        width: 18

        contentItem: Rectangle {
            implicitWidth: 18
            implicitHeight: flightplanTableView.height * 100 / (95 * flightplanTableView.model.count)
            color: "white"
        }

    }

    delegate: TableRow {

        identCellWidth: flightplanTableView.identCellWidth
        altCellWidth: flightplanTableView.altCellWidth
        dtkCellWidth: flightplanTableView.dtkCellWidth
        distCellWidth: flightplanTableView.distCellWidth
        speedCellWidth: flightplanTableView.speedCellWidth

    }


}
