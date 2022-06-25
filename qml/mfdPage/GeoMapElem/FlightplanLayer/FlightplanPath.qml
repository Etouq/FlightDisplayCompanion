import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQml 2.15
import Mfd.Flightplan 1.0

MapItemGroup {

    function updatePath() {

        let fpPath = [];

        for (let i = 0; i < Flightplan.getFlightPlanSize(); i++) {
            fpPath.push(Flightplan.getPosition(i));
        }

        const polylines = [flightPlanMapRoute, flightPlanMapRoute1, flightPlanMapRoute2, flightPlanMapRoute3, flightPlanMapRoute4];

        // split into separate polylines since too many points makes the line disappear for som reason
        for (let i = 0; i < polylines.length; ++i) {
            if (i === polylines.length - 1 && (i + 1) * 60 <= fpPath.length) {
                polylines[i].path = fpPath.slice(i * 60, fpPath.length);
            }
            else {
                polylines[i].path = fpPath.slice(i * 60, (i + 1) * 60);
            }
        }
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