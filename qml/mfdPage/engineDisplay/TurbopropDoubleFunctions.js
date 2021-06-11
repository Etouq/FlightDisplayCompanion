function drawN1Gauges(leftN1GaugeHandle, rightN1GaugeHandle, n1GaugeParent) {
    //setup gauge parameters
    leftN1GaugeHandle.setScaleFactor(1);
    rightN1GaugeHandle.setScaleFactor(1);

    leftN1GaugeHandle.setAngles(n1GaugeItem.getStartAngle(), n1GaugeItem.getEndAngle());
    rightN1GaugeHandle.setAngles(n1GaugeItem.getStartAngle(), n1GaugeItem.getEndAngle());

    leftN1GaugeHandle.setPos(97.5, 82.5);
    rightN1GaugeHandle.setPos(322.5, 82.5);

    leftN1GaugeHandle.setRadius(70.5);
    rightN1GaugeHandle.setRadius(70.5);


    leftN1GaugeHandle.setRange(n1GaugeItem.getMinValue(), n1GaugeItem.getMaxValue());
    rightN1GaugeHandle.setRange(n1GaugeItem.getMinValue(), n1GaugeItem.getMaxValue());

    leftN1GaugeHandle.clearColorZones();
    rightN1GaugeHandle.clearColorZones();

    for (let idx = 0; idx < n1GaugeItem.getColorZonesSize(); ++idx) {
        leftN1GaugeHandle.addColorZone(n1GaugeItem.getStartValueAtIndex(idx), n1GaugeItem.getEndValueAtIndex(idx), n1GaugeItem.getColorAtIndex(idx));
        rightN1GaugeHandle.addColorZone(n1GaugeItem.getStartValueAtIndex(idx), n1GaugeItem.getEndValueAtIndex(idx), n1GaugeItem.getColorAtIndex(idx));
    }

    leftN1GaugeHandle.setGrads(n1GaugeItem.getGradDist(), n1GaugeItem.getTextGradDist(), n1GaugeItem.getGradStart());
    rightN1GaugeHandle.setGrads(n1GaugeItem.getGradDist(), n1GaugeItem.getTextGradDist(), n1GaugeItem.getGradStart());


    leftN1GaugeHandle.setTitle("", 0, 0, 0);
    rightN1GaugeHandle.setTitle("", 0, 0, 0);

    leftN1GaugeHandle.setUnit("", 0, 0, 0);
    rightN1GaugeHandle.setUnit("", 0, 0, 0);

    leftN1GaugeHandle.setValueText(97.5, 92.390625, 26);
    rightN1GaugeHandle.setValueText(322.5, 92.390625, 26);


    //create gauge children
    let n1GaugeLeft = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', n1GaugeParent);
    let n1GaugeRight = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', n1GaugeParent);
    let n1TitleAndUnit = Qt.createQmlObject(
        'import QtQuick 2.15; Text {' +
        'anchors.horizontalCenter: n1GaugeParent.left;' +
        'anchors.horizontalCenterOffset: 210;' +
        'y: 10.5;' +
        'anchors.alignWhenCentered: false;' +
        'lineHeight: 0.8;' +
        'horizontalAlignment: Text.AlignHCenter;' +
        'renderType: Text.NativeRendering;' +
        'color: "white";' +
        'font.pixelSize: 26;' +
        'font.family: "Roboto Mono";' +
        'font.bold: true;' +
        'text: "' + n1GaugeItem.getName() + '\n' + n1GaugeItem.getUnit() + '" }',
        n1GaugeParent);

    n1GaugeParent.children = [n1GaugeLeft, n1GaugeRight, n1TitleAndUnit];

    //draw gauges
    leftN1GaugeHandle.drawBase(n1GaugeLeft, "n1GaugeItem.engine1");
    rightN1GaugeHandle.drawBase(n1GaugeRight, "n1GaugeItem.engine2");
}


function drawTrqGauges(leftTrqGaugeHandle, rightTrqGaugeHandle, trqGaugeParent) {
    //setup gauge parameters
    leftTrqGaugeHandle.setScaleFactor(1);
    rightTrqGaugeHandle.setScaleFactor(1);

    leftTrqGaugeHandle.setAngles(trqGaugeItem.getStartAngle(), trqGaugeItem.getEndAngle());
    rightTrqGaugeHandle.setAngles(trqGaugeItem.getStartAngle(), trqGaugeItem.getEndAngle());

    leftTrqGaugeHandle.setPos(97.5, 217.5);
    rightTrqGaugeHandle.setPos(322.5, 217.5);

    leftTrqGaugeHandle.setRadius(70.5);
    rightTrqGaugeHandle.setRadius(70.5);


    leftTrqGaugeHandle.setRange(trqGaugeItem.getMinValue(), trqGaugeItem.getMaxValue());
    rightTrqGaugeHandle.setRange(trqGaugeItem.getMinValue(), trqGaugeItem.getMaxValue());

    leftTrqGaugeHandle.clearColorZones();
    rightTrqGaugeHandle.clearColorZones();

    for (let idx = 0; idx < trqGaugeItem.getColorZonesSize(); ++idx) {
        leftTrqGaugeHandle.addColorZone(trqGaugeItem.getStartValueAtIndex(idx), trqGaugeItem.getEndValueAtIndex(idx), trqGaugeItem.getColorAtIndex(idx));
        rightTrqGaugeHandle.addColorZone(trqGaugeItem.getStartValueAtIndex(idx), trqGaugeItem.getEndValueAtIndex(idx), trqGaugeItem.getColorAtIndex(idx));
    }

    leftTrqGaugeHandle.setGrads(trqGaugeItem.getGradDist(), trqGaugeItem.getTextGradDist(), trqGaugeItem.getGradStart());
    rightTrqGaugeHandle.setGrads(trqGaugeItem.getGradDist(), trqGaugeItem.getTextGradDist(), trqGaugeItem.getGradStart());


    leftTrqGaugeHandle.setTitle("", 0, 0, 0);
    rightTrqGaugeHandle.setTitle("", 0, 0, 0);

    leftTrqGaugeHandle.setUnit("", 0, 0, 0);
    rightTrqGaugeHandle.setUnit("", 0, 0, 0);

    leftTrqGaugeHandle.setValueText(97.5, 227.390625, 26);
    rightTrqGaugeHandle.setValueText(322.5, 227.390625, 26);

    //create gauge children
    let trqGaugeLeft = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', trqGaugeParent);
    let trqGaugeRight = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', trqGaugeParent);
    let trqTitleAndUnit = Qt.createQmlObject(
        'import QtQuick 2.15; Text {' +
        'anchors.horizontalCenter: trqGaugeParent.left;' +
        'anchors.horizontalCenterOffset: 210;' +
        'y: 145.5;' +
        'anchors.alignWhenCentered: false;' +
        'lineHeight: 0.8;' +
        'horizontalAlignment: Text.AlignHCenter;' +
        'renderType: Text.NativeRendering;' +
        'color: "white";' +
        'font.pixelSize: 26;' +
        'font.family: "Roboto Mono";' +
        'font.bold: true;' +
        'text: "' + trqGaugeItem.getName() + '\n' + trqGaugeItem.getUnit() + '" }',
        trqGaugeParent);
    trqGaugeParent.data = [trqGaugeLeft, trqGaugeRight, trqTitleAndUnit];

    //draw gauges
    leftTrqGaugeHandle.drawBase(trqGaugeLeft, "trqGaugeItem.engine1");
    rightTrqGaugeHandle.drawBase(trqGaugeRight, "trqGaugeItem.engine2");
}



function drawIttGauges(ittGaugeHandle, ittGaugeParent) {
    //setup gauge parameters
    ittGaugeHandle.setPosition(97.5, 318);

    ittGaugeHandle.setRange(ittGaugeItem.getMinValue(), ittGaugeItem.getMaxValue());

    ittGaugeHandle.clearColorZones();

    for (let idx = 0; idx < ittGaugeItem.getColorZonesSize(); ++idx)
        ittGaugeHandle.addColorZone(ittGaugeItem.getStartValueAtIndex(idx), ittGaugeItem.getEndValueAtIndex(idx), ittGaugeItem.getColorAtIndex(idx));

    ittGaugeHandle.setGrads(ittGaugeItem.getGradDist(), ittGaugeItem.getTextGradDist(), ittGaugeItem.getGradStart());


    ittGaugeHandle.setTitleAndUnit(ittGaugeItem.getName(), ittGaugeItem.getUnit());

    //draw gauges
    ittGaugeHandle.drawBase(ittGaugeParent, "ittGaugeItem", ittGaugeItem.getMaxValue() >= 10000);
}

function drawRpmGauges(rpmGaugeHandle, rpmGaugeParent) {
    //setup gauge parameters
    rpmGaugeHandle.setPosition(322.5, 318);

    rpmGaugeHandle.setRange(rpmGaugeItem.getMinValue(), rpmGaugeItem.getMaxValue());

    rpmGaugeHandle.clearColorZones();

    for (let idx = 0; idx < rpmGaugeItem.getColorZonesSize(); ++idx)
        rpmGaugeHandle.addColorZone(rpmGaugeItem.getStartValueAtIndex(idx), rpmGaugeItem.getEndValueAtIndex(idx), rpmGaugeItem.getColorAtIndex(idx));

    rpmGaugeHandle.setGrads(rpmGaugeItem.getGradDist(), rpmGaugeItem.getTextGradDist(), rpmGaugeItem.getGradStart());


    rpmGaugeHandle.setTitleAndUnit(rpmGaugeItem.getName(), rpmGaugeItem.getUnit());

    //draw gauges
    rpmGaugeHandle.drawBase(rpmGaugeParent, "rpmGaugeItem", rpmGaugeItem.getMaxValue() >= 10000);
}



function drawFuelTankGauge(fuelTankGaugeHandle, fuelTankGauge, numTanks) {
    //setup gauge parameters
    fuelTankGaugeHandle.setPosition(97.5, 499.5);

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
    fuelFlowGaugeHandle.setPosition(322.5, 499.5);

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
    oilTempGaugeHandle.setPosition(commonGaugeProperties.getHasEgt() ?  82.5 : 120, 765);


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
    oilPressGaugeHandle.setPosition(commonGaugeProperties.getHasEgt() ?  337.5 : 300, 765);


    oilPressGaugeHandle.setRange(oilPressGaugeItem.getMinValue(), oilPressGaugeItem.getMaxValue());

    oilPressGaugeHandle.clearColorZones();

    for (let idx = 0; idx < oilPressGaugeItem.getColorZonesSize(); ++idx)
        oilPressGaugeHandle.addColorZone(oilPressGaugeItem.getStartValueAtIndex(idx), oilPressGaugeItem.getEndValueAtIndex(idx), oilPressGaugeItem.getColorAtIndex(idx));

    oilPressGaugeHandle.setGrads(oilPressGaugeItem.getGradDist(), oilPressGaugeItem.getTextGradDist(), oilPressGaugeItem.getGradStart());


    oilPressGaugeHandle.setTitleAndUnit(oilPressGaugeItem.getName(), oilPressGaugeItem.getUnit());

    //draw gauges
    oilPressGaugeHandle.drawBase(oilPressGauge, "oilPressGaugeItem", oilPressGaugeItem.getMaxValue() >= 10000);
}


function drawEgtGauge(egtGaugeHandle, egtGauge) {
    if(!commonGaugeProperties.getHasEgt())
    {
        for(let i = egtGauge.data.length - 1; i >= 0; i--)
            egtGauge.data[i].destroy();
        return;
    }
    //setup gauge parameters
    egtGaugeHandle.setPosition(210, 765);


    egtGaugeHandle.setRange(egtGaugeItem.getMinValue(), egtGaugeItem.getMaxValue());

    egtGaugeHandle.clearColorZones();

    for (let idx = 0; idx < egtGaugeItem.getColorZonesSize(); ++idx)
        egtGaugeHandle.addColorZone(egtGaugeItem.getStartValueAtIndex(idx), egtGaugeItem.getEndValueAtIndex(idx), egtGaugeItem.getColorAtIndex(idx));

    egtGaugeHandle.setGrads(egtGaugeItem.getGradDist(), egtGaugeItem.getTextGradDist(), egtGaugeItem.getGradStart());


    egtGaugeHandle.setTitleAndUnit(egtGaugeItem.getName(), egtGaugeItem.getUnit());

    //draw gauges
    egtGaugeHandle.drawBase(egtGauge, "egtGaugeItem", egtGaugeItem.getMaxValue() >= 10000);
}


function drawFuelText(fuelTextHandle, fuelTextParent)
{
    fuelTextHandle.setTopBaseline(675);
    fuelTextHandle.setHasApu(commonGaugeProperties.getHasApu());
    fuelTextHandle.createFuelText(fuelTextParent);
}

function drawFlapsGauge(flapsHandle, flapsGaugeParent)
{
    flapsHandle.setYStart(939.6);
    flapsHandle.setComponents(commonGaugeProperties.getHasFlaps(), commonGaugeProperties.getHasSpoilers());
    flapsHandle.createFlapsGauge(flapsGaugeParent);
}

function drawTrimsGauges(trimsHandle, trimsParent)
{
    trimsHandle.setElevTop(1042.5);
    trimsHandle.setAvailableTrims(commonGaugeProperties.getHasRudderTrim(), commonGaugeProperties.getHasAileronTrim());
    trimsHandle.createTrimGauges(trimsParent);
}
