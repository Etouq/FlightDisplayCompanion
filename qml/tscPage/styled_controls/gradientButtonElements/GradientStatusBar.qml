import QtQuick 2.0

Rectangle {
    property bool active: false

    width: parent.width * 0.8
    height: parent.height * 0.05
    anchors.bottom: parent.bottom
    anchors.bottomMargin: parent.height * 0.3
    anchors.horizontalCenter: parent.horizontalCenter
    color: active ? "lawngreen" : "grey"
}
