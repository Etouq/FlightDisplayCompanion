import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQuick.Controls 2.15
import Mfd.Flightplan 1.0
import TypeEnums 1.0

MapItemView {
    model: 0

    delegate: MapQuickItem {
        id: waypointItem

        required property int index

        anchorPoint.x: width / 2
        anchorPoint.y: width / 2
        width: 87.5
        height: 119.5
        coordinate: Flightplan.getPosition(index)

        sourceItem: Item {
            width: 87.5
            height: 119.5

            Image {
                width: 87.5
                height: 87.5
                source: waypointTypeToIcon(Flightplan.getWpType(index))

                function waypointTypeToIcon(wpType) {
                    switch (wpType) {
                        case WaypointType.AIRPORT:
                            return "qrc:/images/mapImages/ICON_MAP_AIRPORT_NON_TOWERED_SERVICED_PINK.png";
                        case WaypointType.INTERSECTION:
                            return "qrc:/images/mapImages/ICON_MAP_INTERSECTION.png";
                        case WaypointType.VOR:
                            return "qrc:/images/mapImages/ICON_MAP_VOR.png";
                        case WaypointType.NDB:
                            return "qrc:/images/mapImages/ICON_MAP_NDB_WAYPOINT.png";
                        case WaypointType.USER:
                            return "qrc:/images/mapImages/ICON_MAP_USERWAYPOINT.png";
                        default:
                            return "";
                    }
                }
            }

            Label {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom

                bottomInset: -5
                leftInset: -5
                rightInset: -5
                topInset: -5

                font.family: "Roboto Mono"
                font.pixelSize: 20
                font.bold: true

                color: "white"
                text: Flightplan.getIdent(index)

                background: Rectangle {
                    color: "#3f4851"
                }
            }
        }
    }
}
