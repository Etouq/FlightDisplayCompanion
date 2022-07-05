import QtQuick 2.15
import QtQuick.Controls 2.15

Text {
    width: parent.width
    anchors.top: parent.top
    anchors.topMargin: 0.05 * parent.height
    horizontalAlignment: Text.AlignHCenter

    font.pixelSize: 42
    font.family: "Roboto Mono"
    font.bold: true

    color: "white"

    wrapMode: Text.WordWrap
}
