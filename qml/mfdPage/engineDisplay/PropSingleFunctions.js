function drawRpmGauges(rpmGaugeHandle, rpmGaugeParent) {
    //setup gauge parameters
    rpmGaugeHandle.setScaleFactor(1.3);

    rpmGaugeHandle.setAngles(rpmGaugeItem.getStartAngle(), rpmGaugeItem.getEndAngle());

    rpmGaugeHandle.setPos(210, 135);

    rpmGaugeHandle.setRadius(120);


    rpmGaugeHandle.setRange(rpmGaugeItem.getMinValue(), rpmGaugeItem.getMaxValue());

    rpmGaugeHandle.clearColorZones();

    for (let idx = 0; idx < rpmGaugeItem.getColorZonesSize(); ++idx) {
        rpmGaugeHandle.addColorZone(rpmGaugeItem.getStartValueAtIndex(idx), rpmGaugeItem.getEndValueAtIndex(idx), rpmGaugeItem.getColorAtIndex(idx));
    }

    rpmGaugeHandle.setGrads(rpmGaugeItem.getGradDist(), rpmGaugeItem.getTextGradDist(), rpmGaugeItem.getGradStart());


    rpmGaugeHandle.setTitle(rpmGaugeItem.getName(), 210, 75, 30);

    rpmGaugeHandle.setUnit(rpmGaugeItem.getUnit(), 210, 105, 30);

    rpmGaugeHandle.setValueText(210, 142.5, 38);


    //draw gauges
    rpmGaugeHandle.drawBase(rpmGaugeParent, "rpmGaugeItem.engine1");
}


function drawSecondGauges(secondGaugeHandle, secondGaugeParent) {
    //setup gauge parameters
    secondGaugeHandle.setScaleFactor(1.3);

    secondGaugeHandle.setAngles(secondGaugeItem.getStartAngle(), secondGaugeItem.getEndAngle());

    secondGaugeHandle.setPos(210, 322.5);

    secondGaugeHandle.setRadius(120);


    secondGaugeHandle.setRange(secondGaugeItem.getMinValue(), secondGaugeItem.getMaxValue());

    secondGaugeHandle.clearColorZones();

    for (let idx = 0; idx < secondGaugeItem.getColorZonesSize(); ++idx) {
        secondGaugeHandle.addColorZone(secondGaugeItem.getStartValueAtIndex(idx), secondGaugeItem.getEndValueAtIndex(idx), secondGaugeItem.getColorAtIndex(idx));
    }

    secondGaugeHandle.setGrads(secondGaugeItem.getGradDist(), secondGaugeItem.getTextGradDist(), secondGaugeItem.getGradStart());


    secondGaugeHandle.setTitle(secondGaugeItem.getName(), 210, 262.5, 30);

    secondGaugeHandle.setUnit(secondGaugeItem.getUnit(), 210, 292.5, 30);

    secondGaugeHandle.setValueText(210, 330, 38);

    //draw gauges
    secondGaugeHandle.drawBase(secondGaugeParent, "secondGaugeItem.engine1");
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
    fuelFlowGaugeHandle.drawBase(fuelFlowGauge, "fuelFlowGaugeItem.engine1", fuelFlowGaugeItem.getMaxValue() >= 10000);
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
    oilTempGaugeHandle.drawBase(oilTempGauge, "oilTempGaugeItem.engine1", oilTempGaugeItem.getMaxValue() >= 10000);
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
    oilPressGaugeHandle.drawBase(oilPressGauge, "oilPressGaugeItem.engine1", oilPressGaugeItem.getMaxValue() >= 10000);
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
    egtGaugeHandle.drawBase(egtGauge, "egtGaugeItem.engine1", egtGaugeItem.getMaxValue() >= 10000);
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
