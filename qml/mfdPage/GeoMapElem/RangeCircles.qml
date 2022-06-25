import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15

import Mfd.GeoMapPage 1.0
import Mfd.Flightplan 1.0
import Pfd.HSIndicator 1.0
import General.Settings 1.0
import TypeEnums 1.0

MapItemGroup {
    id: circleRoot

    required property real zoomSetting
    property real smallRadius: circleRoot.zoomSetting * 1852
    property real textAzimuth: 90

    states: [
        State {
            name: "northUpState"
            when: GeoMapPage.rotationMode === MapRotationMode.NORTH_UP
            PropertyChanges { target: circleRoot; textAzimuth: 90 }
        },
        State {
            name: "headingUpState"
            when: GeoMapPage.mapOrientationMode === MapRotationMode.HDG_UP
            PropertyChanges { target: circleRoot; textAzimuth: 90 + GeoMap.trueHeading }
        },
        State {
            name: "trackUpState"
            when: GeoMapPage.mapOrientationMode === MapRotationMode.TRACK_UP
            PropertyChanges { target: circleRoot; textAzimuth: 90 + HSIndicator.currentTrackAngle }
        },
        State {
            name: "dtkUpState"
            when: GeoMapPage.mapOrientationMode === MapRotationMode.DTK_UP
            PropertyChanges { target: circleRoot; textAzimuth: 90 + FlightPlan.wpDtk }
        }
    ]


    MapCircle
    {
        center: GeoMapPage.userPosition
        radius: circleRoot.smallRadius
        border.width: 3
    }
    MapCircle
    {
        center: GeoMapPage.userPosition
        radius: circleRoot.smallRadius * 2
        border.width: 3
    }
    MapCircle
    {
        center: GeoMapPage.userPosition
        radius: circleRoot.smallRadius * 3
        border.width: 3
    }
    MapCircle
    {
        center: GeoMapPage.userPosition
        radius: circleRoot.smallRadius * 4
        border.width: 3
    }


    MapQuickItem {
        anchorPoint.x: firstText.width + 5
        anchorPoint.y: firstText.height / 2
        coordinate: GeoMapPage.userPosition.atDistanceAndAzimuth(circleRoot.smallRadius, circleRoot.textAzimuth);

        sourceItem: Text {
            id: firstText

            visible: GenSettings.showRangeText

            font.family: "Roboto Mono"
            //font.bold: true
            font.pixelSize: 20
            text: Math.round(circleRoot.zoomSetting * 10) / 10
        }
    }

    MapQuickItem {
        anchorPoint.x: secondText.width + 5
        anchorPoint.y: secondText.height / 2
        coordinate: GeoMapPage.userPosition.atDistanceAndAzimuth(circleRoot.smallRadius * 2, circleRoot.textAzimuth);

        sourceItem: Text {
            id: secondText

            visible: GenSettings.showRangeText

            font.family: "Roboto Mono"
            //font.bold: true
            font.pixelSize: 20
            text: Math.round(circleRoot.zoomSetting * 20) / 10
        }
    }

    MapQuickItem {
        anchorPoint.x: thirdText.width + 5
        anchorPoint.y: thirdText.height / 2
        coordinate: GeoMapPage.userPosition.atDistanceAndAzimuth(circleRoot.smallRadius * 3, circleRoot.textAzimuth);

        sourceItem: Text {
            id: thirdText

            visible: GenSettings.showRangeText

            font.family: "Roboto Mono"
            //font.bold: true
            font.pixelSize: 20
            text: Math.round(circleRoot.zoomSetting * 30) / 10
        }
    }

    MapQuickItem {
        anchorPoint.x: fourthText.width + 5
        anchorPoint.y: fourthText.height / 2
        coordinate: GeoMapPage.userPosition.atDistanceAndAzimuth(circleRoot.smallRadius * 4, circleRoot.textAzimuth);

        sourceItem: Text {
            id: fourthText

            visible: GenSettings.showRangeText

            font.family: "Roboto Mono"
            //font.bold: true
            font.pixelSize: 20
            text: Math.round(circleRoot.zoomSetting * 40) / 10
        }
    }
}
