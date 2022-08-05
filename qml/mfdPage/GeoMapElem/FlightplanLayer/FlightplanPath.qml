import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQml 2.15
import Mfd.Flightplan 1.0

MapItemGroup {

    function updatePath() {

        let fpPath = [];

        for (let i = 0; i < FlightplanModel.rowCount(); ++i) {
            fpPath.push(FlightplanModel.position(i));
        }

        const polylines = [flightPlanMapRoute, flightPlanMapRoute1, flightPlanMapRoute2, flightPlanMapRoute3];

        // split into separate polylines since too many points makes the line disappear for some reason
        for (let i = 0; i < polylines.length - 1; ++i) {
            polylines[i].path = fpPath.slice(i * 60, (i + 1) * 60);
        }

        flightPlanMapRoute4.path = fpPath.slice(polylines.length * 60, fpPath.length);
    }

    MapPolyline {
        id: flightPlanMapRoute
        line.width: 6
        line.color: "#ed008c"
        path: []
    }

    MapPolyline {
        id: flightPlanMapRoute1
        enabled: flightPlanMapRoute1.path.length > 0
        visible: flightPlanMapRoute1.path.length > 0
        line.width: 6
        line.color: "#ed008c"
        path: []
    }

    MapPolyline {
        id: flightPlanMapRoute2
        enabled: flightPlanMapRoute2.path.length > 0
        visible: flightPlanMapRoute2.path.length > 0
        line.width: 6
        line.color: "#ed008c"
        path: []
    }

    MapPolyline {
        id: flightPlanMapRoute3
        enabled: flightPlanMapRoute3.path.length > 0
        visible: flightPlanMapRoute3.path.length > 0
        line.width: 6
        line.color: "#ed008c"
        path: []
    }

    MapPolyline {
        id: flightPlanMapRoute4
        enabled: flightPlanMapRoute4.path.length > 0
        visible: flightPlanMapRoute4.path.length > 0
        line.width: 6
        line.color: "#ed008c"
        path: []
    }

}
