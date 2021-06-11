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


function drawN2Gauges(leftN2GaugeHandle, rightN2GaugeHandle, n2GaugeParent) {
    //setup gauge parameters
    leftN2GaugeHandle.setScaleFactor(1);
    rightN2GaugeHandle.setScaleFactor(1);

    leftN2GaugeHandle.setAngles(n2GaugeItem.getStartAngle(), n2GaugeItem.getEndAngle());
    rightN2GaugeHandle.setAngles(n2GaugeItem.getStartAngle(), n2GaugeItem.getEndAngle());

    leftN2GaugeHandle.setPos(97.5, 217.5);
    rightN2GaugeHandle.setPos(322.5, 217.5);

    leftN2GaugeHandle.setRadius(70.5);
    rightN2GaugeHandle.setRadius(70.5);


    leftN2GaugeHandle.setRange(n2GaugeItem.getMinValue(), n2GaugeItem.getMaxValue());
    rightN2GaugeHandle.setRange(n2GaugeItem.getMinValue(), n2GaugeItem.getMaxValue());

    leftN2GaugeHandle.clearColorZones();
    rightN2GaugeHandle.clearColorZones();

    for (let idx = 0; idx < n2GaugeItem.getColorZonesSize(); ++idx) {
        leftN2GaugeHandle.addColorZone(n2GaugeItem.getStartValueAtIndex(idx), n2GaugeItem.getEndValueAtIndex(idx), n2GaugeItem.getColorAtIndex(idx));
        rightN2GaugeHandle.addColorZone(n2GaugeItem.getStartValueAtIndex(idx), n2GaugeItem.getEndValueAtIndex(idx), n2GaugeItem.getColorAtIndex(idx));
    }

    leftN2GaugeHandle.setGrads(n2GaugeItem.getGradDist(), n2GaugeItem.getTextGradDist(), n2GaugeItem.getGradStart());
    rightN2GaugeHandle.setGrads(n2GaugeItem.getGradDist(), n2GaugeItem.getTextGradDist(), n2GaugeItem.getGradStart());


    leftN2GaugeHandle.setTitle("", 0, 0, 0);
    rightN2GaugeHandle.setTitle("", 0, 0, 0);

    leftN2GaugeHandle.setUnit("", 0, 0, 0);
    rightN2GaugeHandle.setUnit("", 0, 0, 0);

    leftN2GaugeHandle.setValueText(97.5, 227.390625, 26);
    rightN2GaugeHandle.setValueText(322.5, 227.390625, 26);

    //create gauge children
    let n2GaugeLeft = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', n2GaugeParent);
    let n2GaugeRight = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', n2GaugeParent);
    let n2TitleAndUnit = Qt.createQmlObject(
        'import QtQuick 2.15; Text {' +
        'anchors.horizontalCenter: n2GaugeParent.left;' +
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
        'text: "' + n2GaugeItem.getName() + '\n' + n2GaugeItem.getUnit() + '" }',
        n2GaugeParent);
    n2GaugeParent.data = [n2GaugeLeft, n2GaugeRight, n2TitleAndUnit];

    //draw gauges
    leftN2GaugeHandle.drawBase(n2GaugeLeft, "n2GaugeItem.engine1");
    rightN2GaugeHandle.drawBase(n2GaugeRight, "n2GaugeItem.engine2");
}



function drawIttGauges(leftIttGaugeHandle, rightIttGaugeHandle, ittGaugeParent) {
    //setup gauge parameters
    leftIttGaugeHandle.setScaleFactor(1);
    rightIttGaugeHandle.setScaleFactor(1);

    leftIttGaugeHandle.setAngles(ittGaugeItem.getStartAngle(), ittGaugeItem.getEndAngle());
    rightIttGaugeHandle.setAngles(ittGaugeItem.getStartAngle(), ittGaugeItem.getEndAngle());

    leftIttGaugeHandle.setPos(97.5, 352.5);
    rightIttGaugeHandle.setPos(322.5, 352.5);

    leftIttGaugeHandle.setRadius(70.5);
    rightIttGaugeHandle.setRadius(70.5);


    leftIttGaugeHandle.setRange(ittGaugeItem.getMinValue(), ittGaugeItem.getMaxValue());
    rightIttGaugeHandle.setRange(ittGaugeItem.getMinValue(), ittGaugeItem.getMaxValue());

    leftIttGaugeHandle.clearColorZones();
    rightIttGaugeHandle.clearColorZones();

    for (let idx = 0; idx < ittGaugeItem.getColorZonesSize(); ++idx) {
        leftIttGaugeHandle.addColorZone(ittGaugeItem.getStartValueAtIndex(idx), ittGaugeItem.getEndValueAtIndex(idx), ittGaugeItem.getColorAtIndex(idx));
        rightIttGaugeHandle.addColorZone(ittGaugeItem.getStartValueAtIndex(idx), ittGaugeItem.getEndValueAtIndex(idx), ittGaugeItem.getColorAtIndex(idx));
    }

    leftIttGaugeHandle.setGrads(ittGaugeItem.getGradDist(), ittGaugeItem.getTextGradDist(), ittGaugeItem.getGradStart());
    rightIttGaugeHandle.setGrads(ittGaugeItem.getGradDist(), ittGaugeItem.getTextGradDist(), ittGaugeItem.getGradStart());


    leftIttGaugeHandle.setTitle("", 0, 0, 0);
    rightIttGaugeHandle.setTitle("", 0, 0, 0);

    leftIttGaugeHandle.setUnit("", 0, 0, 0);
    rightIttGaugeHandle.setUnit("", 0, 0, 0);

    leftIttGaugeHandle.setValueText(97.5, 362.390625, 26);
    rightIttGaugeHandle.setValueText(322.5, 362.390625, 26);

    //create gauge children
    let ittGaugeLeft = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', ittGaugeParent);
    let ittGaugeRight = Qt.createQmlObject('import QtQuick 2.15; import QtQuick.Shapes 1.15; Shape {}', ittGaugeParent);
    let ittTitleAndUnit = Qt.createQmlObject(
        'import QtQuick 2.15; Text {' +
        'anchors.horizontalCenter: ittGaugeParent.left;' +
        'anchors.horizontalCenterOffset: 210;' +
        'y: 280.5;' +
        'anchors.alignWhenCentered: false;' +
        'lineHeight: 0.8;' +
        'horizontalAlignment: Text.AlignHCenter;' +
        'renderType: Text.NativeRendering;' +
        'color: "white";' +
        'font.pixelSize: 26;' +
        'font.family: "Roboto Mono";' +
        'font.bold: true;' +
        'text: "' + ittGaugeItem.getName() + '\n' + ittGaugeItem.getUnit() + '" }',
        ittGaugeParent);
    ittGaugeParent.data = [ittGaugeLeft, ittGaugeRight, ittTitleAndUnit];

    //draw gauges
    leftIttGaugeHandle.drawBase(ittGaugeLeft, "ittGaugeItem.engine1");
    rightIttGaugeHandle.drawBase(ittGaugeRight, "ittGaugeItem.engine2");
}



function drawFuelTankGauge(fuelTankGaugeHandle, fuelTankGauge, numTanks) {
    //setup gauge parameters
    fuelTankGaugeHandle.setPosition(97.5, 480);

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
    fuelFlowGaugeHandle.setPosition(322.5, 480);

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
    oilTempGaugeHandle.setPosition(120, 750);


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
    oilPressGaugeHandle.setPosition(300, 750);


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
    fuelTextHandle.setTopBaseline(660);
    fuelTextHandle.setHasApu(commonGaugeProperties.getHasApu());
    fuelTextHandle.createFuelText(fuelTextParent);
}

function drawFlapsGauge(flapsHandle, flapsGaugeParent)
{
    flapsHandle.setYStart(924.6);
    flapsHandle.setComponents(commonGaugeProperties.getHasFlaps(), commonGaugeProperties.getHasSpoilers());
    flapsHandle.createFlapsGauge(flapsGaugeParent);
}

function drawTrimsGauges(trimsHandle, trimsParent)
{
    trimsHandle.setElevTop(1027.5);
    trimsHandle.setAvailableTrims(commonGaugeProperties.getHasRudderTrim(), commonGaugeProperties.getHasAileronTrim());
    trimsHandle.createTrimGauges(trimsParent);
}
