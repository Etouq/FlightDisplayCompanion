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

        gaugeData: MfdRoot.gauge1()
    }

    Compound.DoubleCircularGauge {
        id: secondGauge

        radius: 70.5
        centerY: 217.5
        edgeSpacing: 97.5

        gaugeData: MfdRoot.gauge2()
    }

    Compound.DoubleCircularGauge {
        id: thirdGauge

        radius: 70.5
        centerY: 352.5
        edgeSpacing: 97.5

        gaugeData: MfdRoot.gauge3()
    }

    Component {
        id: singleTankComponent
        Vertical.Gauge {
            id: singleTankGauge
            centerX: 97.5
            yTop: 480

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
            yTop: 480

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
        yTop: 480

        title: fuelFlowGauge.gaugeData.getTitle()
        unit: fuelFlowGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.fuelFlowGauge()
    }

    Compound.FuelText {
        id: fuelTextGauge
        topBaseline: 660
    }

    Vertical.DoubleGauge {
        id: oilTempGauge
        centerX: EngineMisc.hasSecondaryTempGauge() ?  82.5 : 120
        yTop: 750

        title: oilTempGauge.gaugeData.getTitle()
        unit: oilTempGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.oilTempGauge()
    }

    Vertical.DoubleGauge {
        id: oilPressGauge
        centerX: EngineMisc.hasSecondaryTempGauge() ?  337.5 : 300
        yTop: 750

        title: oilPressGauge.gaugeData.getTitle()
        unit: oilPressGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.oilPressGauge()
    }

    Loader {
        asynchronous: true
        active: EngineMisc.hasSecondaryTempGauge()
        sourceComponent: Vertical.DoubleGauge {
            id: secondaryTempGauge

            centerX: 210
            yTop: 750

            title: secondaryTempGauge.gaugeData.getTitle()
            unit: secondaryTempGauge.gaugeData.getUnitString()

            gaugeData: MfdRoot.secondaryTempGauge()
        }
    }

    Component {
         id: flapsGauge
        Flaps.Gauge {
        yStart: 924.6
        }
    }

    Component {
         id: flapsSpoilersGauge
        Flaps.SpoilersGauge {
        yStart: 924.6
        }
    }

    Loader {
        active: EngineMisc.hasFlaps()
        asynchronous: true
        sourceComponent: EngineMisc.hasSpoilers() ? flapsSpoilersGauge : flapsGauge
    }

    Compound.TrimGauge {
        y: 1027.5
    }


}
