import QtQuick 2.15
import QtQuick.Controls 2.15

Text {
    x: parent.width * 0.05
    width: parent.width * 0.9

    anchors.top: parent.top
    anchors.topMargin: 0.42 * parent.height

    horizontalAlignment: Text.AlignHCenter

    font.pixelSize: 48
    font.family: "Roboto Mono"
    font.bold: true

    color: "aqua"

    lineHeight: 48
    lineHeightMode: Text.FixedHeight
}
