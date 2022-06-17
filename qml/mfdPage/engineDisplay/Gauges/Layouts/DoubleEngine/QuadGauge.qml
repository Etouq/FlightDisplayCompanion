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

        radius: 70.5
        centerY: 82.5
        edgeSpacing: 97.5

        gaugeData: MfdRoot.engine1()
    }

    Compound.DoubleCircularGauge {
        id: secondGauge

        radius: 70.5
        centerY: 217.5
        edgeSpacing: 97.5

        gaugeData: MfdRoot.engine2()
    }

    Vertical.DoubleGauge {
        id: thirdGauge
        centerX: 97.5
        yTop: 318

        title: thirdGauge.gaugeData.getTitle()
        unit: thirdGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.engine3()
    }

    Vertical.DoubleGauge {
        id: fourthGauge
        centerX: 322.5
        yTop: 318

        title: fourthGauge.gaugeData.getTitle()
        unit: fourthGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.engine4()
    }

    Component {
        id: singleTankComponent
        Vertical.Gauge {
            id: singleTankGauge
            centerX: 97.5
            yTop: 499.5

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
            centerX: 97.5
            yTop: 499.5

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
        centerX: 322.5
        yTop: 499.5

        title: fuelFlowGauge.gaugeData.getTitle()
        unit: fuelFlowGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.fuelFlowGauge()
    }

    Compound.FuelText {
        id: fuelTextGauge
        topBaseline: 675
    }

    Vertical.DoubleGauge {
        id: oilTempGauge
        centerX: EngineMisc.hasEgt() ? 82.5 : 120
        yTop: 765

        title: oilTempGauge.gaugeData.getTitle()
        unit: oilTempGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.oilTempGauge()
    }

    Vertical.DoubleGauge {
        id: oilPressGauge
        centerX: EngineMisc.hasEgt() ? 337.5 : 300
        yTop: 765

        title: oilPressGauge.gaugeData.getTitle()
        unit: oilPressGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.oilPressGauge()
    }

    Loader {
        active: EngineMisc.hasEgt()
        asynchronous: true
        sourceComponent: Vertical.DoubleGauge {
            id: egtGauge

            centerX: 210
            yTop: 765

            title: egtGauge.gaugeData.getTitle()
            unit: egtGauge.gaugeData.getUnitString()

            gaugeData: MfdRoot.egtGauge()
        }
    }

    Component {
        id: flapsGauge
        Flaps.Gauge {
            yStart: 939.6
        }
    }

    Component {
        id: flapsSpoilersGauge
        Flaps.SpoilersGauge {
            yStart: 939.6
        }
    }

    Loader {
        active: EngineMisc.hasFlaps()
        asynchronous: true
        sourceComponent: EngineMisc.hasSpoilers() ? flapsSpoilersGauge : flapsGauge
    }

    Compound.TrimGauge {
        y: 1042.5
    }
}
