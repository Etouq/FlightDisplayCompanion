import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {
    id: main

    property real elevTop: 0

    property bool hasElevTrim: commonGaugeProperties.getHasElevatorTrim()
    property bool hasRuddTrim: commonGaugeProperties.getHasRudderTrim()
    property bool hasAilTrim: commonGaugeProperties.getHasAileronTrim()


    Component {
        id: elevTrim
        ElevatorTrimGauge {
            elevTop: main.elevTop
            isOnlyTrimGauge: !(main.hasRuddTrim || main.hasAilTrim)
        }
    }

    Component {
        id: ruddTrim
        RudderTrimGauge {
            elevTop: main.elevTop
            noElevTrim: !main.hasElevTrim
            noAileronTrim: !main.hasAilTrim
        }
    }

    Component {
        id: ailTrim
        AileronTrimGauge {
            elevTop: main.elevTop
            noElevTrim: !main.hasElevTrim
            noRudderTrim: !main.hasRuddTrim
        }
    }

    Loader {
        sourceComponent: main.hasElevTrim ? elevTrim : undefined
    }

    Loader {
        sourceComponent: main.hasRuddTrim ? ruddTrim : undefined
    }

    Loader {
        sourceComponent: main.hasAilTrim ? ailTrim : undefined
    }
}
