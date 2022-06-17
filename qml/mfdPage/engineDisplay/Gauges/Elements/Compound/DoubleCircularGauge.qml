import QtQuick 2.15
import "../Circular" as Circular
import Mfd.Engine 1.0

Item {
    id: compoundRoot

    required property real radius
    required property real centerY
    required property real edgeSpacing

    property int valueTextSize: 26

    required property GaugeData gaugeData



    Circular.Gauge {
        id: gaugeLeft

        title: ""
        unit: ""

        radius: compoundRoot.radius
        centerX: compoundRoot.edgeSpacing
        centerY: compoundRoot.centerY

        valueTextSize: compoundRoot.valueTextSize

        gaugeData: compoundRoot.gaugeData
        engine: compoundRoot.gaugeData.engine1()
    }

    Circular.Gauge {
        id: gaugeRight

        title: ""
        unit: ""

        radius: compoundRoot.radius
        centerX: 420 - compoundRoot.edgeSpacing
        centerY: compoundRoot.centerY

        valueTextSize: compoundRoot.valueTextSize

        gaugeData: compoundRoot.gaugeData
        engine: compoundRoot.gaugeData.engine2()

    }

    Text {
        id: gaugeTitle
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 210
        y: compoundRoot.centerY - 72
        lineHeight: 0.8
        horizontalAlignment: Text.AlignHCenter
        color: "white"
        font.pixelSize: 26
        font.family: "Roboto Mono"
        font.bold: true
        text: compoundRoot.gaugeData.getTitle() + '\n' + compoundRoot.gaugeData.getUnitString()
    }
}
