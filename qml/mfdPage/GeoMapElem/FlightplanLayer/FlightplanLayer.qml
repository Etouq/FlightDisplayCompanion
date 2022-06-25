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
            flightplanWaypoints.model = 0; // force update
            flightplanWaypoints.model = Flightplan.getFlightPlanSize();
        }
    }

    FlightplanPath {
        id: flightplanPath
    }

    FlightplanWaypoints {
        id: flightplanWaypoints
    }

}
