import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQml 2.15
import Mfd.Flightplan 1.0

MapItemGroup {

    Connections {
        target: Flightplan
        function onFlightplanChanged() {
            flightplanPath.updatePath();
        }
    }

    FlightplanPath {
        id: flightplanPath
    }

    FlightplanWaypoints {
        id: flightplanWaypoints
    }

}
