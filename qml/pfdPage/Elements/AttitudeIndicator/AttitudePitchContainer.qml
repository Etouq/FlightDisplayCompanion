import QtQuick 2.15
import Pfd.Attitude 1.0

Item {
    width: 331.2
    height: 374.4
    clip: true

    AttitudePitch {}

    Loader {
        active: Attitude.fdActive
        asynchronous: true

        sourceComponent: FlightDirector {}
    }

}
