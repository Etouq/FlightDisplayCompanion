import QtQuick 2.15

Text {
    property int stateValue: 0 // 0: none, 1: active, 2: selected

    anchors.top: parent.top
    width: parent.width
    horizontalAlignment: Text.AlignHCenter
    font.pixelSize: 84
    font.family: "Roboto Mono"
    font.bold: true
    color: stateValue == 0 ? "white" : stateValue == 1 ? "lawngreen" : "aqua"
}
