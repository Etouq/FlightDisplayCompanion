import QtQuick 2.15

import Mfd.GeoMapPage 1.0
import Mfd.Flightplan 1.0
import TypeEnums 1.0

import "../../"
import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"

TscPageBase {
    id: flightplanPage

    pageTitle: "Active Flight Plan"

    showBackButton: true

    Connections {
        target: Flightplan
        function onFlightplanChanged() {
            fpTableWpListModel.clear();
            for (let i = 0; i < Flightplan.getFlightPlanSize(); i++) {
                fpTableWpListModel.append({
                    "ident": Flightplan.getIdent(i),
                    "wpType": Flightplan.getWpType(i),
                    "alt1": Flightplan.getAltitude1(i),
                    "alt2": Flightplan.getAltitude2(i),
                    "altType": Flightplan.getAltType(i),
                    "dtk": Flightplan.getLegBearing(i),
                    "dist": Flightplan.getLegDistanceTo(i),
                    "totDist": Flightplan.getCumulativeDistance(i)
                });
            }
        }
    }

    Component.onCompleted: {
        for (let i = 0; i < Flightplan.getFlightPlanSize(); i++) {
            fpTableWpListModel.append({
                "ident": Flightplan.getIdent(i),
                "wpType": Flightplan.getWpType(i),
                "alt1": Flightplan.getAltitude1(i),
                "alt2": Flightplan.getAltitude2(i),
                "altType": Flightplan.getAltType(i),
                "dtk": Flightplan.getLegBearing(i),
                "dist": Flightplan.getLegDistanceTo(i),
                "totDist": Flightplan.getCumulativeDistance(i)
            });
        }
    }



    ListModel {
        id: fpTableWpListModel
    }


    Rectangle {
        y: 120
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864
        width: 913
        height: 525
        color: "white"

        Rectangle {
            anchors.left: parent.left
            anchors.leftMargin: 7
            anchors.right: parent.right
            anchors.rightMargin: 7
            anchors.top: parent.top
            anchors.topMargin: 7
            anchors.bottom: flightplanTableView.top
            anchors.bottomMargin: 5
            color: "black"
        }

        Rectangle {
            anchors.left: flightplanTableView.right
            anchors.right: parent.right
            anchors.rightMargin: 7
            anchors.top: parent.top
            anchors.topMargin: 7
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 7
            color: "black"
        }

        Item {
            x: 7
            width: 295
            height: 40
            anchors.bottom: flightplanTableView.top
            anchors.bottomMargin: 5

            Text {
                anchors.centerIn: parent
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 30
                color: "white"
                text: fpTableWpListModel.count > 1 ? ((fpTableWpListModel.get(0).ident === "" ? "____" : fpTableWpListModel.get(0).ident) + "/" + (fpTableWpListModel.get(fpTableWpListModel.count - 1).ident === "" ? "____" : fpTableWpListModel.get(fpTableWpListModel.count - 1).ident)) : "____/____"
            }
        }

        Item {
            x: 307
            width: 180
            height: 40
            anchors.bottom: flightplanTableView.top
            anchors.bottomMargin: 5

            Text {
                anchors.centerIn: parent
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 30
                color: "white"
                text: "ALT"
            }
        }

        Item {
            x: 492
            width: 120
            height: 40
            anchors.bottom: flightplanTableView.top
            anchors.bottomMargin: 5

            Text {
                anchors.centerIn: parent
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 30
                color: "white"
                text: "DTK"
            }
        }

        Item {
            x: 617
            width: 130
            height: 40
            anchors.bottom: flightplanTableView.top
            anchors.bottomMargin: 5

            Text {
                anchors.centerIn: parent
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 30
                color: "white"
                text: "DIS"
            }
        }

        Item {
            x: 752
            width: 130
            height: 40
            anchors.bottom: flightplanTableView.top
            anchors.bottomMargin: 5

            Text {
                anchors.centerIn: parent
                font.family: "Roboto Mono"
                font.bold: true
                font.pixelSize: 30
                color: "white"
                text: "TDIS"
            }
        }

        FlightplanTable {
            id: flightplanTableView
            width: 885
            height: 470
            anchors.left: parent.left
            anchors.leftMargin: 2
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 7

            model: fpTableWpListModel
        }

    }

}
