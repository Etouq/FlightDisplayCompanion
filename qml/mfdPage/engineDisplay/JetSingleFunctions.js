function drawN1Gauges(n1GaugeHandle, n1GaugeParent) {
    //setup gauge parameters
    n1GaugeHandle.setScaleFactor(1.3);

    n1GaugeHandle.setAngles(n1GaugeItem.getStartAngle(), n1GaugeItem.getEndAngle());

    n1GaugeHandle.setPos(210, 135);

    n1GaugeHandle.setRadius(120);


    n1GaugeHandle.setRange(n1GaugeItem.getMinValue(), n1GaugeItem.getMaxValue());

    n1GaugeHandle.clearColorZones();

    for (let idx = 0; idx < n1GaugeItem.getColorZonesSize(); ++idx) {
        n1GaugeHandle.addColorZone(n1GaugeItem.getStartValueAtIndex(idx), n1GaugeItem.getEndValueAtIndex(idx), n1GaugeItem.getColorAtIndex(idx));
    }

    n1GaugeHandle.setGrads(n1GaugeItem.getGradDist(), n1GaugeItem.getTextGradDist(), n1GaugeItem.getGradStart());


    n1GaugeHandle.setTitle(n1GaugeItem.getName(), 210, 75, 30);

    n1GaugeHandle.setUnit(n1GaugeItem.getUnit(), 210, 105, 30);

    n1GaugeHandle.setValueText(210, 142.5, 38);

    //draw gauges
    n1GaugeHandle.drawBase(n1GaugeParent, "n1GaugeItem.engine1");
}


function drawN2Gauges(n2GaugeHandle, n2GaugeParent) {
    //setup gauge parameters
    n2GaugeHandle.setScaleFactor(1.2);

    n2GaugeHandle.setAngles(n2GaugeItem.getStartAngle(), n2GaugeItem.getEndAngle());

    n2GaugeHandle.setPos(105, 315);

    n2GaugeHandle.setRadius(90);


    n2GaugeHandle.setRange(n2GaugeItem.getMinValue(), n2GaugeItem.getMaxValue());

    n2GaugeHandle.clearColorZones();

    for (let idx = 0; idx < n2GaugeItem.getColorZonesSize(); ++idx) {
        n2GaugeHandle.addColorZone(n2GaugeItem.getStartValueAtIndex(idx), n2GaugeItem.getEndValueAtIndex(idx), n2GaugeItem.getColorAtIndex(idx));
    }

    n2GaugeHandle.setGrads(n2GaugeItem.getGradDist(), n2GaugeItem.getTextGradDist(), n2GaugeItem.getGradStart());


    n2GaugeHandle.setTitle(n2GaugeItem.getName(), 105, 300, 23);

    n2GaugeHandle.setUnit(n2GaugeItem.getUnit(), 105, 322.5, 23);

    n2GaugeHandle.setValueText(105, 352.5, 30);

    //draw gauges
    n2GaugeHandle.drawBase(n2GaugeParent, "n2GaugeItem.engine1");
}



function drawIttGauges(ittGaugeHandle, ittGaugeParent) {
    //setup gauge parameters
    ittGaugeHandle.setScaleFactor(1.2);

    ittGaugeHandle.setAngles(ittGaugeItem.getStartAngle(), ittGaugeItem.getEndAngle());

    ittGaugeHandle.setPos(315, 315);

    ittGaugeHandle.setRadius(90);


    ittGaugeHandle.setRange(ittGaugeItem.getMinValue(), ittGaugeItem.getMaxValue());

    ittGaugeHandle.clearColorZones();

    for (let idx = 0; idx < ittGaugeItem.getColorZonesSize(); ++idx) {
        ittGaugeHandle.addColorZone(ittGaugeItem.getStartValueAtIndex(idx), ittGaugeItem.getEndValueAtIndex(idx), ittGaugeItem.getColorAtIndex(idx));
    }

    ittGaugeHandle.setGrads(ittGaugeItem.getGradDist(), ittGaugeItem.getTextGradDist(), ittGaugeItem.getGradStart());


    ittGaugeHandle.setTitle(ittGaugeItem.getName(), 315, 300, 23);

    ittGaugeHandle.setUnit(ittGaugeItem.getUnit(), 315, 322.5, 23);

    ittGaugeHandle.setValueText(315, 352.5, 20);

    //draw gauges
    ittGaugeHandle.drawBase(ittGaugeParent, "ittGaugeItem.engine1");
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
    oilTempGaugeHandle.setPosition(120, 730.5);


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
    oilPressGaugeHandle.setPosition(300, 730.5);


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
