import QtQuick 2.15

Text {
    width: parent.width
    horizontalAlignment: Text.AlignHCenter

    font.pixelSize: 48
    font.family: "Roboto Mono"
    font.bold: true

    color: parent.enabled ? "white" : "#666666"

    wrapMode: Text.WordWrap
}
