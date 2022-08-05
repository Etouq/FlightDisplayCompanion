import QtQuick 2.15
import "../../Elements/Circular" as Circular
import "../../Elements/Vertical" as Vertical
import "../../Elements/Flaps" as Flaps
import "../../Elements/Trims" as Trims
import "../../Elements/Compound" as Compound
import Mfd 1.0
import Mfd.Engine 1.0

Item {

    Circular.Gauge {
        id: firstGauge

        radius: 90
        centerX: 105
        centerY: 115

        titleSize: 23
        unitSize: 23

        valueTextSize: 30

        arcWidth: 4
        colorZoneWidth: 8
        gradScaleFactor: 1.3

        title: MfdRoot.gauge1().getTitle()
        unit: MfdRoot.gauge1().getUnitString()

        gaugeData: MfdRoot.gauge1()
        engine: MfdRoot.gauge1().engine1()
    }

    Circular.Gauge {
        id: secondGauge

        radius: 90
        centerX: 315
        centerY: 115

        titleSize: 23
        unitSize: 23

        valueTextSize: 30

        arcWidth: 4
        colorZoneWidth: 8
        gradScaleFactor: 1.3

        title: MfdRoot.gauge2().getTitle()
        unit: MfdRoot.gauge2().getUnitString()

        gaugeData: MfdRoot.gauge2()
        engine: MfdRoot.gauge2().engine1()
    }

    Circular.Gauge {
        id: thirdGauge

        radius: 90
        centerX: 105
        centerY: 300

        titleSize: 23
        unitSize: 23

        valueTextSize: 30

        arcWidth: 4
        colorZoneWidth: 8
        gradScaleFactor: 1.3

        title: MfdRoot.gauge3().getTitle()
        unit: MfdRoot.gauge3().getUnitString()

        gaugeData: MfdRoot.gauge3()
        engine: MfdRoot.gauge3().engine1()
    }

    Circular.Gauge {
        id: fourthGauge

        radius: 90
        centerX: 315
        centerY: 300

        titleSize: 23
        unitSize: 23

        valueTextSize: 30

        arcWidth: 4
        colorZoneWidth: 8
        gradScaleFactor: 1.3

        title: MfdRoot.gauge4().getTitle()
        unit: MfdRoot.gauge4().getUnitString()

        gaugeData: MfdRoot.gauge4()
        engine: MfdRoot.gauge4().engine1()
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
        sourceComponent: EngineMisc.hasSingleTank(
                             ) ? singleTankComponent : doubleTankComponent
    }

    Vertical.Gauge {
        id: fuelFlowGauge
        centerX: 315
        yTop: 445.5

        valuePos: 1

        title: fuelFlowGauge.gaugeData.getTitle()
        unit: fuelFlowGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.fuelFlowGauge()
        engine: MfdRoot.fuelFlowGauge().engine1()
    }

    Compound.FuelText {
        id: fuelTextGauge
        topBaseline: 622.5
    }

    Vertical.Gauge {
        id: oilTempGauge
        centerX: EngineMisc.hasSecondaryTempGauge() ? 82.5 : 120
        yTop: 730.5

        valuePos: 1

        title: oilTempGauge.gaugeData.getTitle()
        unit: oilTempGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.oilTempGauge()
        engine: MfdRoot.oilTempGauge().engine1()
    }

    Vertical.Gauge {
        id: oilPressGauge
        centerX: EngineMisc.hasSecondaryTempGauge() ? 337.5 : 300
        yTop: 730.5

        valuePos: 1

        title: oilPressGauge.gaugeData.getTitle()
        unit: oilPressGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.oilPressGauge()
        engine: MfdRoot.oilPressGauge().engine1()
    }

    Loader {
        asynchronous: true
        active: EngineMisc.hasSecondaryTempGauge()
        sourceComponent: Vertical.Gauge {
            id: secondaryTempGauge
            centerX: 210
            yTop: 730.5

            valuePos: 1

            title: secondaryTempGauge.gaugeData.getTitle()
            unit: secondaryTempGauge.gaugeData.getUnitString()

            gaugeData: MfdRoot.secondaryTempGauge()
            engine: MfdRoot.secondaryTempGauge().engine1()
        }
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
        sourceComponent: EngineMisc.hasSpoilers(
                             ) ? flapsSpoilersGauge : flapsGauge
    }

    Compound.TrimGauge {
        y: 1020
    }
}
