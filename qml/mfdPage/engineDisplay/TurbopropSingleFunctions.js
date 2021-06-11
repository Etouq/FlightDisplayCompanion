function drawN1Gauges(n1GaugeHandle, n1GaugeParent) {
    //setup gauge parameters
    n1GaugeHandle.setScaleFactor(1.3);

    n1GaugeHandle.setAngles(n1GaugeItem.getStartAngle(), n1GaugeItem.getEndAngle());

    n1GaugeHandle.setPos(105, 105);

    n1GaugeHandle.setRadius(90);


    n1GaugeHandle.setRange(n1GaugeItem.getMinValue(), n1GaugeItem.getMaxValue());

    n1GaugeHandle.clearColorZones();

    for (let idx = 0; idx < n1GaugeItem.getColorZonesSize(); ++idx) {
        n1GaugeHandle.addColorZone(n1GaugeItem.getStartValueAtIndex(idx), n1GaugeItem.getEndValueAtIndex(idx), n1GaugeItem.getColorAtIndex(idx));
    }

    n1GaugeHandle.setGrads(n1GaugeItem.getGradDist(), n1GaugeItem.getTextGradDist(), n1GaugeItem.getGradStart());


    n1GaugeHandle.setTitle(n1GaugeItem.getName(), 105, 90, 23);

    n1GaugeHandle.setUnit(n1GaugeItem.getUnit(), 105, 112.5, 23);

    n1GaugeHandle.setValueText(105, 142.5, 30);

    //draw gauges
    n1GaugeHandle.drawBase(n1GaugeParent, "n1GaugeItem.engine1");
}


function drawTrqGauges(trqGaugeHandle, trqGaugeParent) {
    //setup gauge parameters
    trqGaugeHandle.setScaleFactor(1.3);

    trqGaugeHandle.setAngles(trqGaugeItem.getStartAngle(), trqGaugeItem.getEndAngle());

    trqGaugeHandle.setPos(315, 105);

    trqGaugeHandle.setRadius(90);


    trqGaugeHandle.setRange(trqGaugeItem.getMinValue(), trqGaugeItem.getMaxValue());

    trqGaugeHandle.clearColorZones();

    for (let idx = 0; idx < trqGaugeItem.getColorZonesSize(); ++idx) {
        trqGaugeHandle.addColorZone(trqGaugeItem.getStartValueAtIndex(idx), trqGaugeItem.getEndValueAtIndex(idx), trqGaugeItem.getColorAtIndex(idx));
    }

    trqGaugeHandle.setGrads(trqGaugeItem.getGradDist(), trqGaugeItem.getTextGradDist(), trqGaugeItem.getGradStart());


    trqGaugeHandle.setTitle(trqGaugeItem.getName(), 315, 90, 23);

    trqGaugeHandle.setUnit(trqGaugeItem.getUnit(), 315, 112.5, 23);

    trqGaugeHandle.setValueText(315, 142.5, 30);

    //draw gauges
    trqGaugeHandle.drawBase(trqGaugeParent, "trqGaugeItem.engine1");
}


function drawIttGauges(ittGaugeHandle, ittGaugeParent) {
    //setup gauge parameters
    ittGaugeHandle.setScaleFactor(1.3);

    ittGaugeHandle.setAngles(ittGaugeItem.getStartAngle(), ittGaugeItem.getEndAngle());

    ittGaugeHandle.setPos(105, 315);

    ittGaugeHandle.setRadius(90);


    ittGaugeHandle.setRange(ittGaugeItem.getMinValue(), ittGaugeItem.getMaxValue());

    ittGaugeHandle.clearColorZones();

    for (let idx = 0; idx < ittGaugeItem.getColorZonesSize(); ++idx) {
        ittGaugeHandle.addColorZone(ittGaugeItem.getStartValueAtIndex(idx), ittGaugeItem.getEndValueAtIndex(idx), ittGaugeItem.getColorAtIndex(idx));
    }

    ittGaugeHandle.setGrads(ittGaugeItem.getGradDist(), ittGaugeItem.getTextGradDist(), ittGaugeItem.getGradStart());


    ittGaugeHandle.setTitle(ittGaugeItem.getName(), 105, 300, 23);

    ittGaugeHandle.setUnit(ittGaugeItem.getUnit(), 105, 322.5, 23);

    ittGaugeHandle.setValueText(105, 352.5, 30);

    //draw gauges
    ittGaugeHandle.drawBase(ittGaugeParent, "ittGaugeItem.engine1");
}



function drawRpmGauges(rpmGaugeHandle, rpmGaugeParent) {
    //setup gauge parameters
    rpmGaugeHandle.setScaleFactor(1.3);

    rpmGaugeHandle.setAngles(rpmGaugeItem.getStartAngle(), rpmGaugeItem.getEndAngle());

    rpmGaugeHandle.setPos(315, 315);

    rpmGaugeHandle.setRadius(90);


    rpmGaugeHandle.setRange(rpmGaugeItem.getMinValue(), rpmGaugeItem.getMaxValue());

    rpmGaugeHandle.clearColorZones();

    for (let idx = 0; idx < rpmGaugeItem.getColorZonesSize(); ++idx) {
        rpmGaugeHandle.addColorZone(rpmGaugeItem.getStartValueAtIndex(idx), rpmGaugeItem.getEndValueAtIndex(idx), rpmGaugeItem.getColorAtIndex(idx));
    }

    rpmGaugeHandle.setGrads(rpmGaugeItem.getGradDist(), rpmGaugeItem.getTextGradDist(), rpmGaugeItem.getGradStart());


    rpmGaugeHandle.setTitle(rpmGaugeItem.getName(), 315, 300, 23);

    rpmGaugeHandle.setUnit(rpmGaugeItem.getUnit(), 315, 322.5, 23);

    rpmGaugeHandle.setValueText(315, 352.5, 30);

    //draw gauges
    rpmGaugeHandle.drawBase(rpmGaugeParent, "rpmGaugeItem.engine1");
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

    fuelFlowGaugeHandle.setValuePos(1);

    //draw gauges
    fuelFlowGaugeHandle.drawBase(fuelFlowGauge, "fuelFlowGaugeItem.engine1");
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

    oilTempGaugeHandle.setValuePos(2);

    //draw gauges
    oilTempGaugeHandle.drawBase(oilTempGauge, "oilTempGaugeItem.engine1");
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

    oilPressGaugeHandle.setValuePos(2);

    //draw gauges
    oilPressGaugeHandle.drawBase(oilPressGauge, "oilPressGaugeItem.engine1");
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

    egtGaugeHandle.setValuePos(2);

    //draw gauges
    egtGaugeHandle.drawBase(egtGauge, "egtGaugeItem.engine1");
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
