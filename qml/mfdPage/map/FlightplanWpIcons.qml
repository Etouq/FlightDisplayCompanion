import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQuick.Controls 2.15

MapItemView {
    model: flightplanWpListModel
    delegate: MapQuickItem {
        anchorPoint.x: width / 2
        anchorPoint.y: width / 2
        width: 87.5
        height: 119.5
        coordinate: QtPositioning.coordinate(posLat, posLon)
        sourceItem: Item {
            width: 87.5
            height: 119.5
            Image {
                width: 87.5
                height: 87.5
                source: type == 0 ? "qrc:/images/ICON_MAP_AIRPORT_NON_TOWERED_SERVICED_PINK.png" : type == 1 ? "qrc:/images/ICON_MAP_INTERSECTION.png" : type == 2 ? "qrc:/images/ICON_MAP_NDB_WAYPOINT.png" : type == 3 ? "qrc:/images/ICON_MAP_USERWAYPOINT.png" : "qrc:/images/ICON_MAP_VOR.png"
            }

            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                color: "white"
                font.family: "Roboto Mono"
                text: ident
                font.pixelSize: 20
                font.bold: true
                bottomInset: -5
                leftInset: -5
                rightInset: -5
                topInset: -5
                background: Rectangle {
                    color: "#3f4851"
                }
            }
        }
    }
}
