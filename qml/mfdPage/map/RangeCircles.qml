import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15

MapItemGroup {
    property real smallRadius: zoomLevels[zoomLevelIdx] * 1852
    MapCircle
    {
        center: mfdInterface.currCoordinates
        radius: smallRadius
        border.width: 3
    }
    MapCircle
    {
        center: mfdInterface.currCoordinates
        radius: smallRadius * 2
        border.width: 3
    }
    MapCircle
    {
        center: mfdInterface.currCoordinates
        radius: smallRadius * 3
        border.width: 3
    }
    MapCircle
    {
        center: mfdInterface.currCoordinates
        radius: smallRadius * 4
        border.width: 3
    }

    Connections {
        target: settingsInterface
        function onShowRangeRingTextChanged() {
            let textEnabled = settingsInterface.getShowRangeRingText();
            firstText.visible = textEnabled;
            secondText.visible = textEnabled;
            thirdText.visible = textEnabled;
            fourthText.visible = textEnabled;
        }
    }

    Component.onCompleted: {
        let textEnabled = settingsInterface.getShowRangeRingText();
        firstText.visible = textEnabled;
        secondText.visible = textEnabled;
        thirdText.visible = textEnabled;
        fourthText.visible = textEnabled;
    }

    MapQuickItem {
        anchorPoint.x: firstText.width + 5
        anchorPoint.y: firstText.height / 2
        coordinate: mfdInterface.currCoordinates.atDistanceAndAzimuth(smallRadius, 90);

        sourceItem: Text {
            id: firstText
            font.family: "Roboto Mono"
            //font.bold: true
            font.pixelSize: 20
            text: Math.round(zoomLevels[zoomLevelIdx] * 10) / 10
        }
    }

    MapQuickItem {
        anchorPoint.x: secondText.width + 5
        anchorPoint.y: secondText.height / 2
        coordinate: mfdInterface.currCoordinates.atDistanceAndAzimuth(smallRadius * 2, 90);

        sourceItem: Text {
            id: secondText
            font.family: "Roboto Mono"
            //font.bold: true
            font.pixelSize: 20
            text: Math.round(zoomLevels[zoomLevelIdx] * 20) / 10
        }
    }

    MapQuickItem {
        anchorPoint.x: thirdText.width + 5
        anchorPoint.y: thirdText.height / 2
        coordinate: mfdInterface.currCoordinates.atDistanceAndAzimuth(smallRadius * 3, 90);

        sourceItem: Text {
            id: thirdText
            font.family: "Roboto Mono"
            //font.bold: true
            font.pixelSize: 20
            text: Math.round(zoomLevels[zoomLevelIdx] * 30) / 10
        }
    }

    MapQuickItem {
        anchorPoint.x: fourthText.width + 5
        anchorPoint.y: fourthText.height / 2
        coordinate: mfdInterface.currCoordinates.atDistanceAndAzimuth(smallRadius * 4, 90);

        sourceItem: Text {
            id: fourthText
            font.family: "Roboto Mono"
            //font.bold: true
            font.pixelSize: 20
            text: Math.round(zoomLevels[zoomLevelIdx] * 40) / 10
        }
    }
}
