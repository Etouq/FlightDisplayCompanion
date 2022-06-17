import QtQuick 2.15
import "../Vertical" as Vertical
import Mfd.Engine 1.0

Item {
    id: compoundRoot

    required property real yTop
    required property real edgeSpacing

    readonly property real gaugeSpacing: (420 - 2 * compoundRoot.edgeSpacing) / 3

    property real titleSpacing: 10.5

    property int valuePos: 1

    required property GaugeData gaugeData


    Vertical.Gauge {
        id: gaugeLeft

        title: ""
        unit: ""

        yTop: compoundRoot.yTop
        centerX: compoundRoot.edgeSpacing

        valuePos: 1

        gaugeData: compoundRoot.gaugeData
        engine: compoundRoot.gaugeData.engine1()
    }

    Vertical.Gauge {
        id: gaugeLeftMid

        title: ""
        unit: ""

        yTop: compoundRoot.yTop
        centerX: compoundRoot.edgeSpacing + compoundRoot.gaugeSpacing

        valuePos: 1

        gaugeData: compoundRoot.gaugeData
        engine: compoundRoot.gaugeData.engine2()
    }

    Vertical.Gauge {
        id: gaugeRightMid

        title: ""
        unit: ""

        yTop: compoundRoot.yTop
        centerX: 420 - compoundRoot.edgeSpacing - compoundRoot.gaugeSpacing

        valuePos: 1

        gaugeData: compoundRoot.gaugeData
        engine: compoundRoot.gaugeData.engine3()
    }

    Vertical.Gauge {
        id: gaugeRight

        title: ""
        unit: ""

        yTop: compoundRoot.yTop
        centerX: 420 - compoundRoot.edgeSpacing

        valuePos: 1

        gaugeData: compoundRoot.gaugeData
        engine: compoundRoot.gaugeData.engine4()
    }

    Text {
        id: gaugeTitle
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 210
        anchors.baseline: parent.top
        anchors.baselineOffset: compoundRoot.yTop - compoundRoot.titleSpacing
        color: "white"
        font.pixelSize: 23
        font.family: "Roboto Mono"
        font.bold: true
        text: compoundRoot.gaugeData.getTitle() + ' ' + compoundRoot.gaugeData.getUnitString()
    }

}
