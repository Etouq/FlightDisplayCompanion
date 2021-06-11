function drawRpmGauges(leftRpmGaugeHandle, rightRpmGaugeHandle, rpmGaugeParent) {
    //setup gauge parameters
    leftRpmGaugeHandle.setScaleFactor(1);
    rightRpmGaugeHandle.setScaleFactor(1);

    leftRpmGaugeHandle.setAngles(rpmGaugeItem.getStartAngle(), rpmGaugeItem.getEndAngle());
    rightRpmGaugeHandle.setAngles(rpmGaugeItem.getStartAngle(), rpmGaugeItem.getEndAngle());

    leftRpmGaugeHandle.setPos(97.5, 135);
    rightRpmGaugeHandle.setPos(322.5, 135);

    leftRpmGaugeHandle.setRadius(75);
    rightRpmGaugeHandle.setRadius(75);


    leftRpmGaugeHandle.setRange(rpmGaugeItem.getMinValue(), rpmGaugeItem.getMaxValue());
    rightRpmGaugeHandle.setRange(rpmGaugeItem.getMinValue(), rpmGaugeItem.getMaxValue());

    leftRpmGaugeHandle.clearColorZones();
    rightRpmGaugeHandle.clearColorZones();

    for (let idx = 0; idx < rpmGaugeItem.getColorZonesSize(); ++idx) {
        leftRpmGaugeHandle.addColorZone(rpmGaugeItem.getStartValueAtIndex(idx), rpmGaugeItem.getEndValueAtIndex(idx), rpmGaugeItem.getColorAtIndex(idx));
        rightRpmGaugeHandle.addColorZone(rpmGaugeItem.getStartValueAtIndex(idx), rpmGaugeItem.getEndValueAtIndex(idx), rpmGaugeItem.getColorAtIndex(idx));
    }

    leftRpmGaugeHandle.setGrads(rpmGaugeItem.getGradDist(), rpmGaugeItem.getTextGradDist(), rpmGaugeItem.getGradStart());
    rightRpmGaugeHandle.setGrads(rpmGaugeItem.getGradDist(), rpmGaugeItem.getTextGradDist(), rpmGaugeItem.getGradStart());


    leftRpmGaugeHandle.setTitle("", 0, 0, 0);
    rightRpmGaugeHandle.setTitle("", 0, 0, 0);

    leftRpmGaugeHandle.setUnit("", 0, 0, 0);
    rightRpmGaugeHandle.setUnit("", 0, 0, 0);

    leftRpmGaugeHandle.setValueText(97.5, 144.890625, 26);
    rightRpmGaugeHandle.setValueText(322.5, 144.890625, 26);


    //create gauge children
    let rpmGaugeLeft = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', rpmGaugeParent);
    let rpmGaugeRight = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', rpmGaugeParent);
    let rpmTitleAndUnit = Qt.createQmlObject(
        'import QtQuick 2.15; Text {' +
        'anchors.horizontalCenter: rpmGaugeParent.left;' +
        'anchors.horizontalCenterOffset: 210;' +
        'y: 60;' +
        'anchors.alignWhenCentered: false;' +
        'lineHeight: 0.8;' +
        'horizontalAlignment: Text.AlignHCenter;' +
        'renderType: Text.NativeRendering;' +
        'color: "white";' +
        'font.pixelSize: 26;' +
        'font.family: "Roboto Mono";' +
        'font.bold: true;' +
        'text: "' + rpmGaugeItem.getName() + '\n' + rpmGaugeItem.getUnit() + '" }',
        rpmGaugeParent);

    rpmGaugeParent.children = [rpmGaugeLeft, rpmGaugeRight, rpmTitleAndUnit];

    //draw gauges
    leftRpmGaugeHandle.drawBase(rpmGaugeLeft, "rpmGaugeItem.engine1");
    rightRpmGaugeHandle.drawBase(rpmGaugeRight, "rpmGaugeItem.engine2");
}


function drawSecondGauges(leftSecondGaugeHandle, rightSecondGaugeHandle, secondGaugeParent) {
    //setup gauge parameters
    leftSecondGaugeHandle.setScaleFactor(1);
    rightSecondGaugeHandle.setScaleFactor(1);

    leftSecondGaugeHandle.setAngles(secondGaugeItem.getStartAngle(), secondGaugeItem.getEndAngle());
    rightSecondGaugeHandle.setAngles(secondGaugeItem.getStartAngle(), secondGaugeItem.getEndAngle());

    leftSecondGaugeHandle.setPos(97.5, 315);
    rightSecondGaugeHandle.setPos(322.5, 315);

    leftSecondGaugeHandle.setRadius(75);
    rightSecondGaugeHandle.setRadius(75);


    leftSecondGaugeHandle.setRange(secondGaugeItem.getMinValue(), secondGaugeItem.getMaxValue());
    rightSecondGaugeHandle.setRange(secondGaugeItem.getMinValue(), secondGaugeItem.getMaxValue());

    leftSecondGaugeHandle.clearColorZones();
    rightSecondGaugeHandle.clearColorZones();

    for (let idx = 0; idx < secondGaugeItem.getColorZonesSize(); ++idx) {
        leftSecondGaugeHandle.addColorZone(secondGaugeItem.getStartValueAtIndex(idx), secondGaugeItem.getEndValueAtIndex(idx), secondGaugeItem.getColorAtIndex(idx));
        rightSecondGaugeHandle.addColorZone(secondGaugeItem.getStartValueAtIndex(idx), secondGaugeItem.getEndValueAtIndex(idx), secondGaugeItem.getColorAtIndex(idx));
    }

    leftSecondGaugeHandle.setGrads(secondGaugeItem.getGradDist(), secondGaugeItem.getTextGradDist(), secondGaugeItem.getGradStart());
    rightSecondGaugeHandle.setGrads(secondGaugeItem.getGradDist(), secondGaugeItem.getTextGradDist(), secondGaugeItem.getGradStart());


    leftSecondGaugeHandle.setTitle("", 0, 0, 0);
    rightSecondGaugeHandle.setTitle("", 0, 0, 0);

    leftSecondGaugeHandle.setUnit("", 0, 0, 0);
    rightSecondGaugeHandle.setUnit("", 0, 0, 0);

    leftSecondGaugeHandle.setValueText(97.5, 324.890625, 26);
    rightSecondGaugeHandle.setValueText(322.5, 324.890625, 26);

    //create gauge children
    let secondGaugeLeft = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', secondGaugeParent);
    let secondGaugeRight = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', secondGaugeParent);
    let secondTitleAndUnit = Qt.createQmlObject(
        'import QtQuick 2.15; Text {' +
        'anchors.horizontalCenter: secondGaugeParent.left;' +
        'anchors.horizontalCenterOffset: 210;' +
        'y: 240;' +
        'anchors.alignWhenCentered: false;' +
        'lineHeight: 0.8;' +
        'horizontalAlignment: Text.AlignHCenter;' +
        'renderType: Text.NativeRendering;' +
        'color: "white";' +
        'font.pixelSize: 26;' +
        'font.family: "Roboto Mono";' +
        'font.bold: true;' +
        'text: "' + secondGaugeItem.getName() + '\n' + secondGaugeItem.getUnit() + '" }',
        secondGaugeParent);
    secondGaugeParent.data = [secondGaugeLeft, secondGaugeRight, secondTitleAndUnit];

    //draw gauges
    leftSecondGaugeHandle.drawBase(secondGaugeLeft, "secondGaugeItem.engine1");
    rightSecondGaugeHandle.drawBase(secondGaugeRight, "secondGaugeItem.engine2");
}



function drawFuelTankGauge(fuelTankGaugeHandle, fuelTankGauge, numTanks) {
    //setup gauge parameters
    fuelTankGaugeHandle.setPosition(105, 445.5);

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
    fuelFlowGaugeHandle.setPosition(315, 445.5);

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
    oilTempGaugeHandle.setPosition(commonGaugeProperties.getHasEgt() ?  82.5 : 120, 730.5);


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
    oilPressGaugeHandle.setPosition(commonGaugeProperties.getHasEgt() ?  337.5 : 300, 730.5);


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
    egtGaugeHandle.setPosition(210, 730.5);


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
    fuelTextHandle.setTopBaseline(622.5);
    fuelTextHandle.setHasApu(commonGaugeProperties.getHasApu());
    fuelTextHandle.createFuelText(fuelTextParent);
}

function drawFlapsGauge(flapsHandle, flapsGaugeParent)
{
    flapsHandle.setYStart(909.6);
    flapsHandle.setComponents(commonGaugeProperties.getHasFlaps(), commonGaugeProperties.getHasSpoilers());
    flapsHandle.createFlapsGauge(flapsGaugeParent);
}

function drawTrimsGauges(trimsHandle, trimsParent)
{
    trimsHandle.setElevTop(1020);
    trimsHandle.setAvailableTrims(commonGaugeProperties.getHasRudderTrim(), commonGaugeProperties.getHasAileronTrim());
    trimsHandle.createTrimGauges(trimsParent);
}
