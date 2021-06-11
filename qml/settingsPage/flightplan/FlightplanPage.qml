import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15


Item {

    property bool insertModeActive: false
    property bool editModeActive: false
    property int selectedItemIdx: -1

    Connections {
        target: mfdInterface
        function onFlightplanChanged() {
            selectedItemIdx = -1;
            editModeActive = false;
            insertModeActive = false;
            fpTableWpListModel.clear();
            for (let i = 0; i < mfdInterface.getFlightPlanSize(); i++) {
                let coord = mfdInterface.getFpPositionAt(i);
                fpTableWpListModel.append({"ident": mfdInterface.getFpIdentAt(i), "wpType": mfdInterface.getFpWpTypeAt(i), "alt1": mfdInterface.getFpAltitude1At(i), "alt2": mfdInterface.getFpAltitude2At(i), "altType": mfdInterface.getFpAltTypeAt(i), "dtk": mfdInterface.getFpBearingAt(i), "dist": mfdInterface.getFpLegDistanceAt(i), "totDist": mfdInterface.getFpCumulativeDistanceAt(i)});
            }
        }
    }

    Component.onCompleted: {
        fpTableWpListModel.clear();
        for (let i = 0; i < mfdInterface.getFlightPlanSize(); i++) {
            let coord = mfdInterface.getFpPositionAt(i);
            fpTableWpListModel.append({"ident": mfdInterface.getFpIdentAt(i), "wpType": mfdInterface.getFpWpTypeAt(i), "alt1": mfdInterface.getFpAltitude1At(i), "alt2": mfdInterface.getFpAltitude2At(i), "altType": mfdInterface.getFpAltTypeAt(i), "dtk": mfdInterface.getFpBearingAt(i), "dist": mfdInterface.getFpLegDistanceAt(i), "totDist": mfdInterface.getFpCumulativeDistanceAt(i)});
        }
    }



    ListModel {
        id: fpTableWpListModel
    }


    Rectangle {
        width: 917
        height: 529
        x: 0
        y: 0
        color: "white"
        border.width: 2
        border.color: "black"

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
        }

    }

    FlightplanInput {
        id: fpTableInput
    }




}
