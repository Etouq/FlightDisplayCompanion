import QtQuick 2.15

Text {
    height: parent.height * 0.4

    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: parent.bottom

    horizontalAlignment: Text.AlignHCenter

    font.pixelSize: 42
    font.family: "Roboto Mono"
    font.bold: true

    color: "white"

    wrapMode: Text.WordWrap
    lineHeight: 42
    lineHeightMode: Text.FixedHeight
}
