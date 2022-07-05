import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ListView {
    id: flightplanTableView

    clip: true

    spacing: 5
    reuseItems: true

    function getWpTypeUrl(typeId) {
        switch (typeId) {
            case 0:
                return "qrc:/images/miscImages/ICON_MAP_AIRPORT.png";
            case 1:
                return "qrc:/images/miscImages/ICON_MAP_INT.png";
            case 2:
                return "qrc:/images/miscImages/ICON_MAP_NDB.png";
            case 3:
                return "qrc:/images/miscImages/ICON_MAP_USER.png";
            case 4:
                return "qrc:/images/miscImages/ICON_MAP_VOR_2.png";
            default:
                return "qrc:/images/miscImages/ICON_MAP_USER.png";
        }
    }

    function getAltString(altType, alt1, alt2) {
        switch (altType) {
            case -1:
                return "____FT";
            case 0:
                return alt1 + "FT";
            case 1:
                return "B" + alt1 + "FT";
            case 2:
                return "A" + alt1 + "FT";
            case 3:
                return "A" + alt1 + "FT\nB" + alt2 + "FT";
            default:
                return "____FT";
        }
    }

    ScrollBar.vertical: ScrollBar {
        parent: flightplanTableView.parent
        anchors.top: flightplanTableView.top
        anchors.topMargin: -7
        anchors.left: flightplanTableView.right
        anchors.leftMargin: 5
        anchors.bottom: flightplanTableView.bottom
        policy: ScrollBar.AsNeeded

        contentItem: Rectangle {
            implicitWidth: 10
            implicitHeight: flightplanTableView.height * 100 / (95 * fpTableWpListModel.count)
            color: "white"
        }

    }

    snapMode: ListView.SnapToItem

    delegate: Item {
        width: 885
        height: 90

        Rectangle {
            x: 5
            y: 0
            width: 295
            height: 90
            color: "black"

            Rectangle {
                anchors.fill: parent
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#0093d0" }
                    GradientStop { position: 0.6; color: Qt.rgba(0, 147, 208, 0) }
                }
                border.width: 2
                border.color: "black"
            }

            Image {
                x: 0
                y: 0
                width: 90
                height: 90
                source: getWpTypeUrl(wpType)
            }

            Text {
                anchors.verticalCenter: parent.verticalCenter
                x: 105
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 30
                color: "white"
                text: ident
            }
        }

        FlightplanTableCell {
            //alt
            x: 305
            width: 180
            textValue: getAltString(altType, alt1, alt2)
        }

        FlightplanTableCell {
            //dtk
            x: 490
            width: 120
            textValue: dtk < 0 ? "" : (dtk + "°")
        }

        FlightplanTableCell {
            //dist
            x: 615
            width: 130
            textValue: dist < 0 ? "" : (dist.toFixed(dist < 100 ? 1 : 0) + "NM")
        }

        FlightplanTableCell {
            //total dist
            x: 750
            width: 130
            textValue: totDist < 0 ? "" : (totDist.toFixed(totDist < 100 ? 1 : 0) + "NM")
        }


    }
}
