import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQuick.Controls 2.15
import QtPositioning 5.15
import Mfd.Flightplan 1.0
import TypeEnums 1.0

MapItemView {
    model: FlightplanModel

    delegate: MapQuickItem {
        id: waypointItem

        required property int index
        required property string ident
        required property string mapIconUrl
        required property double lat
        required property double lon

        anchorPoint.x: width / 2
        anchorPoint.y: width / 2
        width: 87.5
        height: 119.5
        coordinate {
            latitude: waypointItem.lat
            longitude: waypointItem.lon
        }

        sourceItem: Item {
            width: 87.5
            height: 119.5

            Image {
                width: 87.5
                height: 87.5
                source: waypointItem.mapIconUrl
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
                text: waypointItem.ident

                background: Rectangle {
                    color: "#3f4851"
                }
            }
        }
    }
}
