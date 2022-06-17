import QtQuick 2.15
import "../Trims" as Trim
import Mfd.Engine 1.0

Item {
    id: compoundRoot

    required y

    Loader {
        active: EngineMisc.hasElevatorTrim()
        asynchronous: true
        sourceComponent: Trim.Elevator {
            x: EngineMisc.hasRudderTrim() || EngineMisc.hasAileronTrim() ? 112.5 : 211.5
            y: 0
        }
    }

    Loader {
        active: EngineMisc.hasRudderTrim()
        asynchronous: true
        sourceComponent: Trim.Rudder {
            x: !EngineMisc.hasElevatorTrim() ? 147 : 204
            y: !EngineMisc.hasAileronTrim() ? 57.1125 : 25.5
        }
    }

    Loader {
        active: EngineMisc.hasAileronTrim()
        asynchronous: true
        sourceComponent: Trim.Aileron {
            x: !EngineMisc.hasElevatorTrim() ? 147 : 204
            y: !EngineMisc.hasRudderTrim() ? 34.4625 : 67.5
        }
    }

}
