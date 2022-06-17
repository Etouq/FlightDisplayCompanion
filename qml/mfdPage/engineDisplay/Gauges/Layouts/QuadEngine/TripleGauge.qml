import QtQuick 2.15
import "../../Elements/Vertical" as Vertical
import "../../Elements/Flaps" as Flaps
import "../../Elements/Trims" as Trims
import "../../Elements/Compound" as Compound
import Mfd 1.0
import Mfd.Engine 1.0

Item {
    id: layoutRoot

    readonly property real bottomGaugesMinWidth: getBottomGaugesMinWidth()

    function getBottomGaugesMinWidth() {
        if (EngineMisc.hasEgt()) {
            const oilTempGaugeData = MfdRoot.oilTempGauge()
            const egtGaugeData = MfdRoot.egtGauge()
            const oilPressGaugeData = MfdRoot.oilPressGauge()

            const oilTempGaugeWidth = 2 * oilTempGaugeData.valueMaxSize(
                                        ) + oilPressGaugeData.unitWidth() - 86
            const oilPressGaugeWidth = 2 * oilPressGaugeData.valueMaxSize(
                                         ) + oilPressGaugeData.unitWidth() - 86
            const egtGaugeWidth = 2 * egtGaugeData.valueMaxSize(
                                    ) + egtGaugeData.unitWidth() - 86

            return Math.max(oilTempGaugeWidth, egtGaugeWidth,
                            oilPressGaugeWidth)
        }

        return 42
    }

    Compound.QuadVertGauge {
        id: firstGauge

        yTop: 70
        edgeSpacing: 61.5
        valuePos: 2

        titleSpacing: 20

        gaugeData: MfdRoot.gauge1()
    }

    Vertical.QuadGauge {
        id: secondGauge
        centerX: 105
        yTop: 280

        title: secondGauge.gaugeData.getTitle()
        unit: secondGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.gauge2()
    }

    Vertical.QuadGauge {
        id: thirdGauge
        centerX: 315
        yTop: 280

        title: thirdGauge.gaugeData.getTitle()
        unit: thirdGauge.gaugeData.getUnitString()

        gaugeData: MfdRoot.gauge3()
    }

    Component {
        id: singleTankComponent
        Vertical.Gauge {
            id: singleTankGauge
            centerX: 105
            yTop: 490

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
            yTop: 490

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

    Vertical.QuadGauge {
        centerX: 315
        yTop: 490

        title: MfdRoot.fuelFlowGauge().getTitle()
        unit: MfdRoot.fuelFlowGauge().getUnitString()

        gaugeData: MfdRoot.fuelFlowGauge()
    }

    Compound.FuelText {
        id: fuelTextGauge
        topBaseline: 670
    }

    Vertical.QuadGauge {
        id: oilTempGauge
        centerX: 420 / 4 + (layoutRoot.bottomGaugesMinWidth + 96) / 2
                 * (1 - (EngineMisc.hasEgt() ? 3 : 2) / 2)
        yTop: 760

        title: oilTempGauge.gaugeData.getTitle()
        unit: oilTempGauge.gaugeData.getUnitString()

        minCenterWidth: layoutRoot.bottomGaugesMinWidth

        gaugeData: MfdRoot.oilTempGauge()
    }

    Vertical.QuadGauge {
        id: oilPressGauge
        centerX: 420 - (layoutRoot.bottomGaugesMinWidth + 96) / 2
                 * (1 - (EngineMisc.hasEgt() ? 3 : 2) / 2) - 420 / 4
        yTop: 760

        title: oilPressGauge.gaugeData.getTitle()
        unit: oilPressGauge.gaugeData.getUnitString()

        minCenterWidth: layoutRoot.bottomGaugesMinWidth

        gaugeData: MfdRoot.oilPressGauge()
    }

    Loader {
        asynchronous: true
        active: EngineMisc.hasEgt()
        sourceComponent: Vertical.QuadGauge {
            id: egtGauge
            centerX: 210
            yTop: 760

            title: egtGauge.gaugeData.getTitle()
            unit: egtGauge.gaugeData.getUnitString()

            minCenterWidth: layoutRoot.bottomGaugesMinWidth

            gaugeData: MfdRoot.egtGauge()
        }
    }

    Component {
        id: flapsGauge
        Flaps.Gauge {
            yStart: 950
        }
    }

    Component {
        id: flapsSpoilersGauge
        Flaps.SpoilersGauge {
            yStart: 950
        }
    }

    Loader {
        active: EngineMisc.hasFlaps()
        asynchronous: true
        sourceComponent: EngineMisc.hasSpoilers() ? flapsSpoilersGauge : flapsGauge
    }

    Compound.TrimGauge {
        y: 1045
    }
}
