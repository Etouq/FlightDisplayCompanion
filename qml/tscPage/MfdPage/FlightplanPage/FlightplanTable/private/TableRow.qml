import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15

import TypeEnums 1.0
import Mfd.Flightplan 1.0

Rectangle {
    id: rowRoot

    width: row.width + 2 * rowRoot.borderWidth // 885
    height: 120


    color: "transparent"
    border.width: rowRoot.borderWidth
    border.color: "white"

    required property int index
    required property string ident
    required property string wpTypeUrl
    required property string altTypeText
    required property string dtk
    required property string dist
    required property string speed

    readonly property real cellPadding: 8
    readonly property real borderWidth: 1

    property alias identCellWidth: identCell.width
    property alias altCellWidth: altCell.width
    property alias dtkCellWidth: dtkCell.width
    property alias distCellWidth: distCell.width
    property alias speedCellWidth: speedCell.width

    Row {
        id: row

        x: rowRoot.borderWidth
        y: rowRoot.borderWidth + rowRoot.cellPadding
        height: rowRoot.height - 2 * (rowRoot.cellPadding + rowRoot.borderWidth)

        spacing: rowRoot.cellPadding
        rightPadding: rowRoot.cellPadding
        leftPadding: rowRoot.cellPadding

        Rectangle {
            id: identCell

            height: parent.height

            gradient: Gradient {
                GradientStop { position: 0.0; color: "#0093d0" }
                GradientStop { position: 0.6; color: Qt.rgba(0, 147, 208, 0) }
            }

            Image {
                id: wpIcon
                x: 45 - rowRoot.cellPadding
                width: parent.height
                height: parent.height
                source: rowRoot.wpTypeUrl
            }

            Text {
                id: wpIdent
                anchors.left: wpIcon.right
                anchors.verticalCenter: parent.verticalCenter

                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 45

                color: "white"
                text: rowRoot.ident
            }
        }

        Rectangle {
            y: -row.y
            width: rowRoot.borderWidth
            height: rowRoot.height

            color: "white"
        }

        TableCell {
            id: altCell
            text: rowRoot.altTypeText
        }

        Rectangle {
            y: -row.y
            width: rowRoot.borderWidth
            height: rowRoot.height

            color: "white"
        }

        TableCell {
            id: dtkCell
            text: rowRoot.dtk

            // to deal with stupid chenanigans of spacing around the ° character
            textObject.anchors.right: undefined
            textObject.anchors.left: textObject.parent.left
            textObject.anchors.leftMargin: 15
        }

        Rectangle {
            y: -row.y
            width: rowRoot.borderWidth
            height: rowRoot.height

            color: "white"
        }

        TableCell {
            id: distCell
            text: rowRoot.dist
        }

        Rectangle {
            y: -row.y
            width: rowRoot.borderWidth
            height: rowRoot.height

            color: "white"
        }

        TableCell {
            id: speedCell
            text: rowRoot.speed
        }
    }

    Shape {
            id: arrow

            visible: Flightplan.activeLegIdx === rowRoot.index

            readonly property real offsetLeft: 0
            readonly property real offsetTop: -120
            readonly property real endOffsetTop: 0


            readonly property real arrowLeftOffset: 45
            readonly property real arrowTopOffset: 60

            readonly property real lineWidth: 10
            readonly property real lineDistance: 22
            readonly property real headWidth: 18


            readonly property real x1: offsetLeft + arrowLeftOffset
            readonly property real y1: offsetTop + arrowTopOffset
            readonly property real y2: endOffsetTop + arrowTopOffset

            ShapePath {

                fillColor: "magenta"
                strokeColor: "transparent"

                PathMove {
                    x: arrow.x1
                    y: arrow.y1 - arrow.lineWidth / 2
                }
                PathLine {
                    relativeX: 0
                    relativeY: arrow.lineWidth
                }
                PathLine {
                    relativeX: -arrow.lineDistance
                    relativeY: 0
                }
                PathLine {
                    relativeX: 0
                    y: arrow.y2 - arrow.lineWidth / 2
                }
                PathLine {
                    relativeX: arrow.lineDistance - arrow.headWidth
                    relativeY: 0
                }
                PathLine {
                    relativeX: 0
                    relativeY: -arrow.lineWidth
                }
                PathLine {
                    x: arrow.x1
                    y: arrow.y2
                }
                PathLine {
                    relativeX: -arrow.headWidth
                    relativeY: arrow.lineWidth * 1.5
                }
                PathLine {
                    relativeX: 0
                    relativeY: -arrow.lineWidth
                }
                PathLine {
                    relativeX: arrow.headWidth - arrow.lineDistance - arrow.lineWidth
                    relativeY: 0
                }
                PathLine {
                    relativeX: 0
                    y: arrow.y1 - arrow.lineWidth / 2
                }

            }
        }



}