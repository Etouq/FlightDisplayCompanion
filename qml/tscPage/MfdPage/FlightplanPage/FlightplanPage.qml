import QtQuick 2.15

import Mfd.GeoMapPage 1.0
import Mfd.Flightplan 1.0
import TypeEnums 1.0

import "../../"
import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"
import "FlightplanTable"

TscPageBase {
    id: flightplanPage

    pageTitle: "Active Flight Plan"

    showBackButton: true

    FlightplanTable {
        y: 120
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864
    }

}
