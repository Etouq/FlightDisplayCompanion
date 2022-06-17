import QtQuick 2.15
import "../../Elements/Circular" as Circular
import "../../Elements/Vertical" as Vertical
import "../../Elements/Flaps" as Flaps
import "../../Elements/Trims" as Trims
import "../../Elements/Compound" as Compound
import Mfd 1.0
import Mfd.Engine 1.0

Item {

    Compound.DoubleCircularGauge {
        id: firstGauge

        radius: 75
        centerY: 135
        edgeSpacing: 97.5

        gaugeData: MfdRoot.gauge1()
    }

    Compound.DoubleCircularGauge {
        id: secondGauge

        radius: 75
        centerY: 315
        edgeSpacing: 97.5

        gaugeData: MfdRoot.gauge2()
    }

    Component {
        id: singleTankComponent
        Vertical.Gauge {
            id: singleTankGauge
            centerX: 105
            yTop: 445.5

            valuePos: 0

            title: singleTankGauge.gaugeData.getTitle()
            unit: singleTankGauge.gaugeData.getUnitString()

            gaugeData: MfdRoot.fuelQtyGauge()
            engine: MfdRoot.fuelQtyGauge().engine1()
        }
    }

    Component {
        id: doubleTankComponent

        Vertical.DoubleGauge {
            id: doubleTankGauge
            centerX: 105
            yTop: 445.5

            title: doubleTankGauge.gaugeData.getTitle()
            unit: doubleTankGauge.gaugeData.getUnitString()

            gaugeData: MfdRoot.fuelQtyGauge()
        }
    }

    Loader {
        asynchronous: true
        sourceComponent: EngineMisc.hasSingleTank() ? singleTankComponent : doubleTankComponent
    }

    Vertical.DoubleGauge {
        id: fuelFlowGauge
        centerX: 315
        yTop: 445.5

        title: fuelFlowGauge.gaugeData.getTitle()
        unit: fuelFlowGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.fuelFlowGauge()
    }

    Compound.FuelText {
        id: fuelTextGauge
        topBaseline: 622.5
    }

    Vertical.DoubleGauge {
        id: oilTempGauge
        centerX: EngineMisc.hasEgt() ? 82.5 : 120
        yTop: 730.5

        title: oilTempGauge.gaugeData.getTitle()
        unit: oilTempGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.oilTempGauge()
    }

    Loader {
        id: egtLoader
        active: EngineMisc.hasEgt()
        asynchronous: true
        sourceComponent: Vertical.DoubleGauge {
            id: egtGauge

            centerX: 210
            yTop: 730.5

            title: egtGauge.gaugeData.getTitle()
            unit: egtGauge.gaugeData.getUnitString()

            gaugeData: MfdRoot.egtGauge()
        }
    }

    Vertical.DoubleGauge {
        id: oilPressGauge
        centerX: EngineMisc.hasEgt() ? 337.5 : 300
        yTop: 730.5

        title: oilPressGauge.gaugeData.getTitle()
        unit: oilPressGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.oilPressGauge()
    }

    Component {
        id: flapsGauge
        Flaps.Gauge {
            yStart: 909.6
        }
    }

    Component {
        id: flapsSpoilersGauge
        Flaps.SpoilersGauge {
            yStart: 909.6
        }
    }

    Loader {
        active: EngineMisc.hasFlaps()
        asynchronous: true
        sourceComponent: EngineMisc.hasSpoilers() ? flapsSpoilersGauge : flapsGauge
    }

    Compound.TrimGauge {
        y: 1020
    }
}
