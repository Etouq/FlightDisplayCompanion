function drawN1Gauges(engine1N1GaugeHandle, engine2N1GaugeHandle, engine3N1GaugeHandle, engine4N1GaugeHandle, n1GaugeParent) {
    //setup gauge parameters
    engine1N1GaugeHandle.setPosition(61.5, 40.5);
    engine2N1GaugeHandle.setPosition(160.5, 40.5);
    engine3N1GaugeHandle.setPosition(259.5, 40.5);
    engine4N1GaugeHandle.setPosition(358.5, 40.5);


    engine1N1GaugeHandle.setRange(n1GaugeItem.getMinValue(), n1GaugeItem.getMaxValue());
    engine2N1GaugeHandle.setRange(n1GaugeItem.getMinValue(), n1GaugeItem.getMaxValue());
    engine3N1GaugeHandle.setRange(n1GaugeItem.getMinValue(), n1GaugeItem.getMaxValue());
    engine4N1GaugeHandle.setRange(n1GaugeItem.getMinValue(), n1GaugeItem.getMaxValue());


    engine1N1GaugeHandle.clearColorZones();
    engine2N1GaugeHandle.clearColorZones();
    engine3N1GaugeHandle.clearColorZones();
    engine4N1GaugeHandle.clearColorZones();

    for (let idx = 0; idx < n1GaugeItem.getColorZonesSize(); ++idx) {
        engine1N1GaugeHandle.addColorZone(n1GaugeItem.getStartValueAtIndex(idx), n1GaugeItem.getEndValueAtIndex(idx), n1GaugeItem.getColorAtIndex(idx));
        engine2N1GaugeHandle.addColorZone(n1GaugeItem.getStartValueAtIndex(idx), n1GaugeItem.getEndValueAtIndex(idx), n1GaugeItem.getColorAtIndex(idx));
        engine3N1GaugeHandle.addColorZone(n1GaugeItem.getStartValueAtIndex(idx), n1GaugeItem.getEndValueAtIndex(idx), n1GaugeItem.getColorAtIndex(idx));
        engine4N1GaugeHandle.addColorZone(n1GaugeItem.getStartValueAtIndex(idx), n1GaugeItem.getEndValueAtIndex(idx), n1GaugeItem.getColorAtIndex(idx));
    }

    engine1N1GaugeHandle.setGrads(n1GaugeItem.getGradDist(), n1GaugeItem.getTextGradDist(), n1GaugeItem.getGradStart());
    engine2N1GaugeHandle.setGrads(n1GaugeItem.getGradDist(), n1GaugeItem.getTextGradDist(), n1GaugeItem.getGradStart());
    engine3N1GaugeHandle.setGrads(n1GaugeItem.getGradDist(), n1GaugeItem.getTextGradDist(), n1GaugeItem.getGradStart());
    engine4N1GaugeHandle.setGrads(n1GaugeItem.getGradDist(), n1GaugeItem.getTextGradDist(), n1GaugeItem.getGradStart());


    engine1N1GaugeHandle.setTitleAndUnit("", "");
    engine2N1GaugeHandle.setTitleAndUnit("", "");
    engine3N1GaugeHandle.setTitleAndUnit("", "");
    engine4N1GaugeHandle.setTitleAndUnit("", "");

    engine1N1GaugeHandle.setValuePos(2);
    engine2N1GaugeHandle.setValuePos(2);
    engine3N1GaugeHandle.setValuePos(2);
    engine4N1GaugeHandle.setValuePos(2);


    //create gauge children
    let engine1N1Gauge = Qt.createQmlObject('import QtQuick 2.15; Item {}', n1GaugeParent);
    let engine2N1Gauge = Qt.createQmlObject('import QtQuick 2.15; Item {}', n1GaugeParent);
    let engine3N1Gauge = Qt.createQmlObject('import QtQuick 2.15; Item {}', n1GaugeParent);
    let engine4N1Gauge = Qt.createQmlObject('import QtQuick 2.15; Item {}', n1GaugeParent);
    let n1TitleAndUnit = Qt.createQmlObject(
        'import QtQuick 2.15; Text {' +
        'anchors.horizontalCenter: n1GaugeParent.left;' +
        'anchors.horizontalCenterOffset: 210;' +
        'anchors.baseline: n1GaugeParent.top;' +
        'anchors.baselineOffset: 30;' +
        'anchors.alignWhenCentered: false;' +
        'horizontalAlignment: Text.AlignHCenter;' +
        'renderType: Text.NativeRendering;' +
        'color: "white";' +
        'font.pixelSize: 23;' +
        'font.family: "Roboto Mono";' +
        'font.bold: true;' +
        'text: "' + n1GaugeItem.getName() + ' ' + n1GaugeItem.getUnit() + '" }',
        n1GaugeParent);

    n1GaugeParent.children = [engine1N1Gauge, engine2N1Gauge, engine3N1Gauge, engine4N1Gauge, n1TitleAndUnit];

    //draw gauges
    engine1N1GaugeHandle.drawBase(engine1N1Gauge, "n1GaugeItem.engine1");
    engine2N1GaugeHandle.drawBase(engine2N1Gauge, "n1GaugeItem.engine2");
    engine3N1GaugeHandle.drawBase(engine3N1Gauge, "n1GaugeItem.engine3");
    engine4N1GaugeHandle.drawBase(engine4N1Gauge, "n1GaugeItem.engine4");
}


function drawN2Gauges(engine1N2GaugeHandle, engine2N2GaugeHandle, engine3N2GaugeHandle, engine4N2GaugeHandle, n2GaugeParent) {
    //setup gauge parameters
    engine1N2GaugeHandle.setPosition(61.5, 209.25);
    engine2N2GaugeHandle.setPosition(160.5, 209.25);
    engine3N2GaugeHandle.setPosition(259.5, 209.25);
    engine4N2GaugeHandle.setPosition(358.5, 209.25);


    engine1N2GaugeHandle.setRange(n2GaugeItem.getMinValue(), n2GaugeItem.getMaxValue());
    engine2N2GaugeHandle.setRange(n2GaugeItem.getMinValue(), n2GaugeItem.getMaxValue());
    engine3N2GaugeHandle.setRange(n2GaugeItem.getMinValue(), n2GaugeItem.getMaxValue());
    engine4N2GaugeHandle.setRange(n2GaugeItem.getMinValue(), n2GaugeItem.getMaxValue());


    engine1N2GaugeHandle.clearColorZones();
    engine2N2GaugeHandle.clearColorZones();
    engine3N2GaugeHandle.clearColorZones();
    engine4N2GaugeHandle.clearColorZones();

    for (let idx = 0; idx < n2GaugeItem.getColorZonesSize(); ++idx) {
        engine1N2GaugeHandle.addColorZone(n2GaugeItem.getStartValueAtIndex(idx), n2GaugeItem.getEndValueAtIndex(idx), n2GaugeItem.getColorAtIndex(idx));
        engine2N2GaugeHandle.addColorZone(n2GaugeItem.getStartValueAtIndex(idx), n2GaugeItem.getEndValueAtIndex(idx), n2GaugeItem.getColorAtIndex(idx));
        engine3N2GaugeHandle.addColorZone(n2GaugeItem.getStartValueAtIndex(idx), n2GaugeItem.getEndValueAtIndex(idx), n2GaugeItem.getColorAtIndex(idx));
        engine4N2GaugeHandle.addColorZone(n2GaugeItem.getStartValueAtIndex(idx), n2GaugeItem.getEndValueAtIndex(idx), n2GaugeItem.getColorAtIndex(idx));
    }

    engine1N2GaugeHandle.setGrads(n2GaugeItem.getGradDist(), n2GaugeItem.getTextGradDist(), n2GaugeItem.getGradStart());
    engine2N2GaugeHandle.setGrads(n2GaugeItem.getGradDist(), n2GaugeItem.getTextGradDist(), n2GaugeItem.getGradStart());
    engine3N2GaugeHandle.setGrads(n2GaugeItem.getGradDist(), n2GaugeItem.getTextGradDist(), n2GaugeItem.getGradStart());
    engine4N2GaugeHandle.setGrads(n2GaugeItem.getGradDist(), n2GaugeItem.getTextGradDist(), n2GaugeItem.getGradStart());


    engine1N2GaugeHandle.setTitleAndUnit("", "");
    engine2N2GaugeHandle.setTitleAndUnit("", "");
    engine3N2GaugeHandle.setTitleAndUnit("", "");
    engine4N2GaugeHandle.setTitleAndUnit("", "");

    engine1N2GaugeHandle.setValuePos(2);
    engine2N2GaugeHandle.setValuePos(2);
    engine3N2GaugeHandle.setValuePos(2);
    engine4N2GaugeHandle.setValuePos(2);


    //create gauge children
    let engine1N2Gauge = Qt.createQmlObject('import QtQuick 2.15; Item {}', n2GaugeParent);
    let engine2N2Gauge = Qt.createQmlObject('import QtQuick 2.15; Item {}', n2GaugeParent);
    let engine3N2Gauge = Qt.createQmlObject('import QtQuick 2.15; Item {}', n2GaugeParent);
    let engine4N2Gauge = Qt.createQmlObject('import QtQuick 2.15; Item {}', n2GaugeParent);
    let n2TitleAndUnit = Qt.createQmlObject(
        'import QtQuick 2.15; Text {' +
        'anchors.horizontalCenter: n2GaugeParent.left;' +
        'anchors.horizontalCenterOffset: 210;' +
        'anchors.baseline: n2GaugeParent.top;' +
        'anchors.baselineOffset: 198.75;' +
        'anchors.alignWhenCentered: false;' +
        'horizontalAlignment: Text.AlignHCenter;' +
        'renderType: Text.NativeRendering;' +
        'color: "white";' +
        'font.pixelSize: 23;' +
        'font.family: "Roboto Mono";' +
        'font.bold: true;' +
        'text: "' + n2GaugeItem.getName() + ' ' + n2GaugeItem.getUnit() + '" }',
        n2GaugeParent);

    n2GaugeParent.children = [engine1N2Gauge, engine2N2Gauge, engine3N2Gauge, engine4N2Gauge, n2TitleAndUnit];

    //draw gauges
    engine1N2GaugeHandle.drawBase(engine1N2Gauge, "n2GaugeItem.engine1");
    engine2N2GaugeHandle.drawBase(engine2N2Gauge, "n2GaugeItem.engine2");
    engine3N2GaugeHandle.drawBase(engine3N2Gauge, "n2GaugeItem.engine3");
    engine4N2GaugeHandle.drawBase(engine4N2Gauge, "n2GaugeItem.engine4");
}



function drawIttGauges(engine1IttGaugeHandle, engine2IttGaugeHandle, engine3IttGaugeHandle, engine4IttGaugeHandle, ittGaugeParent) {
    //setup gauge parameters
    engine1IttGaugeHandle.setPosition(61.5, 378);
    engine2IttGaugeHandle.setPosition(160.5, 378);
    engine3IttGaugeHandle.setPosition(259.5, 378);
    engine4IttGaugeHandle.setPosition(358.5, 378);


    engine1IttGaugeHandle.setRange(ittGaugeItem.getMinValue(), ittGaugeItem.getMaxValue());
    engine2IttGaugeHandle.setRange(ittGaugeItem.getMinValue(), ittGaugeItem.getMaxValue());
    engine3IttGaugeHandle.setRange(ittGaugeItem.getMinValue(), ittGaugeItem.getMaxValue());
    engine4IttGaugeHandle.setRange(ittGaugeItem.getMinValue(), ittGaugeItem.getMaxValue());


    engine1IttGaugeHandle.clearColorZones();
    engine2IttGaugeHandle.clearColorZones();
    engine3IttGaugeHandle.clearColorZones();
    engine4IttGaugeHandle.clearColorZones();

    for (let idx = 0; idx < ittGaugeItem.getColorZonesSize(); ++idx) {
        engine1IttGaugeHandle.addColorZone(ittGaugeItem.getStartValueAtIndex(idx), ittGaugeItem.getEndValueAtIndex(idx), ittGaugeItem.getColorAtIndex(idx));
        engine2IttGaugeHandle.addColorZone(ittGaugeItem.getStartValueAtIndex(idx), ittGaugeItem.getEndValueAtIndex(idx), ittGaugeItem.getColorAtIndex(idx));
        engine3IttGaugeHandle.addColorZone(ittGaugeItem.getStartValueAtIndex(idx), ittGaugeItem.getEndValueAtIndex(idx), ittGaugeItem.getColorAtIndex(idx));
        engine4IttGaugeHandle.addColorZone(ittGaugeItem.getStartValueAtIndex(idx), ittGaugeItem.getEndValueAtIndex(idx), ittGaugeItem.getColorAtIndex(idx));
    }

    engine1IttGaugeHandle.setGrads(ittGaugeItem.getGradDist(), ittGaugeItem.getTextGradDist(), ittGaugeItem.getGradStart());
    engine2IttGaugeHandle.setGrads(ittGaugeItem.getGradDist(), ittGaugeItem.getTextGradDist(), ittGaugeItem.getGradStart());
    engine3IttGaugeHandle.setGrads(ittGaugeItem.getGradDist(), ittGaugeItem.getTextGradDist(), ittGaugeItem.getGradStart());
    engine4IttGaugeHandle.setGrads(ittGaugeItem.getGradDist(), ittGaugeItem.getTextGradDist(), ittGaugeItem.getGradStart());


    engine1IttGaugeHandle.setTitleAndUnit("", "");
    engine2IttGaugeHandle.setTitleAndUnit("", "");
    engine3IttGaugeHandle.setTitleAndUnit("", "");
    engine4IttGaugeHandle.setTitleAndUnit("", "");

    engine1IttGaugeHandle.setValuePos(2);
    engine2IttGaugeHandle.setValuePos(2);
    engine3IttGaugeHandle.setValuePos(2);
    engine4IttGaugeHandle.setValuePos(2);


    //create gauge children
    let engine1IttGauge = Qt.createQmlObject('import QtQuick 2.15; Item {}', ittGaugeParent);
    let engine2IttGauge = Qt.createQmlObject('import QtQuick 2.15; Item {}', ittGaugeParent);
    let engine3IttGauge = Qt.createQmlObject('import QtQuick 2.15; Item {}', ittGaugeParent);
    let engine4IttGauge = Qt.createQmlObject('import QtQuick 2.15; Item {}', ittGaugeParent);
    let ittTitleAndUnit = Qt.createQmlObject(
        'import QtQuick 2.15; Text {' +
        'anchors.horizontalCenter: ittGaugeParent.left;' +
        'anchors.horizontalCenterOffset: 210;' +
        'anchors.baseline: ittGaugeParent.top;' +
        'anchors.baselineOffset: 367.5;' +
        'anchors.alignWhenCentered: false;' +
        'horizontalAlignment: Text.AlignHCenter;' +
        'renderType: Text.NativeRendering;' +
        'color: "white";' +
        'font.pixelSize: 23;' +
        'font.family: "Roboto Mono";' +
        'font.bold: true;' +
        'text: "' + ittGaugeItem.getName() + ' ' + ittGaugeItem.getUnit() + '" }',
        ittGaugeParent);

    ittGaugeParent.children = [engine1IttGauge, engine2IttGauge, engine3IttGauge, engine4IttGauge, ittTitleAndUnit];

    //draw gauges
    engine1IttGaugeHandle.drawBase(engine1IttGauge, "ittGaugeItem.engine1");
    engine2IttGaugeHandle.drawBase(engine2IttGauge, "ittGaugeItem.engine2");
    engine3IttGaugeHandle.drawBase(engine3IttGauge, "ittGaugeItem.engine3");
    engine4IttGaugeHandle.drawBase(engine4IttGauge, "ittGaugeItem.engine4");
}



function drawFuelTankGauge(fuelTankGaugeHandle, fuelTankGauge, numTanks) {
    //setup gauge parameters
    fuelTankGaugeHandle.setPosition(97.5, 558);

    fuelTankGaugeHandle.setRange(0, fuelQtyGaugeItem.getMaxValue());

    fuelTankGaugeHandle.clearColorZones();

    for (let idx = 0; idx < fuelQtyGaugeItem.getColorZonesSize(); ++idx)
        fuelTankGaugeHandle.addColorZone(fuelQtyGaugeItem.getStartValueAtIndex(idx), fuelQtyGaugeItem.getEndValueAtIndex(idx), fuelQtyGaugeItem.getColorAtIndex(idx));

    fuelTankGaugeHandle.setGrads(fuelQtyGaugeItem.getGradDist(), fuelQtyGaugeItem.getTextGradDist(), fuelQtyGaugeItem.getGradStart());


    fuelTankGaugeHandle.setTitleAndUnit(fuelQtyGaugeItem.getName(), fuelQtyGaugeItem.getUnit());


    if (numTanks === 1)
        fuelTankGaugeHandle.setValuePos(1);

    //draw gauges
    if (numTanks === 1)
        fuelTankGaugeHandle.drawBase(fuelTankGauge, "fuelQtyGaugeItem.engine1");
    else
        fuelTankGaugeHandle.drawBase(fuelTankGauge, "fuelQtyGaugeItem", fuelQtyGaugeItem.getMaxValue() >= 10000);
}



function drawFuelFlowGauge(fuelFlowGaugeHandle, fuelFlowGauge) {
    //setup gauge parameters
    fuelFlowGaugeHandle.setPosition(322.5, 558);

    fuelFlowGaugeHandle.setRange(0, fuelFlowGaugeItem.getMaxValue());

    fuelFlowGaugeHandle.clearColorZones();

    for (let idx = 0; idx < fuelFlowGaugeItem.getColorZonesSize(); ++idx)
        fuelFlowGaugeHandle.addColorZone(fuelFlowGaugeItem.getStartValueAtIndex(idx), fuelFlowGaugeItem.getEndValueAtIndex(idx), fuelFlowGaugeItem.getColorAtIndex(idx));

    fuelFlowGaugeHandle.setGrads(fuelFlowGaugeItem.getGradDist(), fuelFlowGaugeItem.getTextGradDist(), fuelFlowGaugeItem.getGradStart());


    fuelFlowGaugeHandle.setTitleAndUnit(fuelFlowGaugeItem.getName(), fuelFlowGaugeItem.getUnit());

    //draw gauges
    fuelFlowGaugeHandle.drawBase(fuelFlowGauge, "fuelFlowGaugeItem", fuelFlowGaugeItem.getMaxValue() >= 10000);
}



function drawOilTempGauge(oilTempGaugeHandle, oilTempGauge) {
    //setup gauge parameters
    oilTempGaugeHandle.setPosition(120, 780);


    oilTempGaugeHandle.setRange(oilTempGaugeItem.getMinValue(), oilTempGaugeItem.getMaxValue());

    oilTempGaugeHandle.clearColorZones();

    for (let idx = 0; idx < oilTempGaugeItem.getColorZonesSize(); ++idx)
        oilTempGaugeHandle.addColorZone(oilTempGaugeItem.getStartValueAtIndex(idx), oilTempGaugeItem.getEndValueAtIndex(idx), oilTempGaugeItem.getColorAtIndex(idx));

    oilTempGaugeHandle.setGrads(oilTempGaugeItem.getGradDist(), oilTempGaugeItem.getTextGradDist(), oilTempGaugeItem.getGradStart());


    oilTempGaugeHandle.setTitleAndUnit(oilTempGaugeItem.getName(), oilTempGaugeItem.getUnit());

    //draw gauges
    oilTempGaugeHandle.drawBase(oilTempGauge, "oilTempGaugeItem", oilTempGaugeItem.getMaxValue() >= 10000);
}



function drawOilPressGauge(oilPressGaugeHandle, oilPressGauge) {
    //setup gauge parameters
    oilPressGaugeHandle.setPosition(300, 780);


    oilPressGaugeHandle.setRange(oilPressGaugeItem.getMinValue(), oilPressGaugeItem.getMaxValue());

    oilPressGaugeHandle.clearColorZones();

    for (let idx = 0; idx < oilPressGaugeItem.getColorZonesSize(); ++idx)
        oilPressGaugeHandle.addColorZone(oilPressGaugeItem.getStartValueAtIndex(idx), oilPressGaugeItem.getEndValueAtIndex(idx), oilPressGaugeItem.getColorAtIndex(idx));

    oilPressGaugeHandle.setGrads(oilPressGaugeItem.getGradDist(), oilPressGaugeItem.getTextGradDist(), oilPressGaugeItem.getGradStart());


    oilPressGaugeHandle.setTitleAndUnit(oilPressGaugeItem.getName(), oilPressGaugeItem.getUnit());

    //draw gauges
    oilPressGaugeHandle.drawBase(oilPressGauge, "oilPressGaugeItem", oilPressGaugeItem.getMaxValue() >= 10000);
}

function drawFuelText(fuelTextHandle, fuelTextParent)
{
    fuelTextHandle.setTopBaseline(705);
    fuelTextHandle.setHasApu(commonGaugeProperties.getHasApu());
    fuelTextHandle.createFuelText(fuelTextParent);
}

function drawFlapsGauge(flapsHandle, flapsGaugeParent)
{
    flapsHandle.setYStart(954.6);
    flapsHandle.setComponents(commonGaugeProperties.getHasFlaps(), commonGaugeProperties.getHasSpoilers());
    flapsHandle.createFlapsGauge(flapsGaugeParent);
}

function drawTrimsGauges(trimsHandle, trimsParent)
{
    trimsHandle.setElevTop(1057.5);
    trimsHandle.setAvailableTrims(commonGaugeProperties.getHasRudderTrim(), commonGaugeProperties.getHasAileronTrim());
    trimsHandle.createTrimGauges(trimsParent);
}
