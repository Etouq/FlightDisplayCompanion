import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQuick.Controls 2.15

Item {
    Button {
        id: mapZoomOut
        x: 1428
        y: 100
        width: 60
        height: 60
        visible: zoomLevelIdx < zoomLevels.length - 1

        background: Rectangle {
            width: 60
            height: 60
            radius: 30
            border.color: "#444444"
            color: "#bbbbbb"
            border.width: 3
            Image {
                source: "qrc:/images/buttonImages/mapZoomLess.svg"
                anchors.fill: parent
            }
        }

        onClicked: {
            zoomLevelIdx++;
            updateZoom();
        }

    }

    Button {
        id: mapZoomIn
        x: 1428
        y: 172
        width: 60
        height: 60
        visible: zoomLevelIdx > 0

        background: Rectangle {
            width: 60
            height: 60
            radius: 30
            border.color: "#444444"
            color: "#bbbbbb"
            border.width: 3
            Image {
                source: "qrc:/images/buttonImages/mapZoomPlus.svg"
                anchors.fill: parent
            }
        }

        onClicked: {
            zoomLevelIdx--;
            updateZoom();
        }
    }

    Button {
        id: centerMap
        visible: panModeActive
        x: 1428
        y: 244
        width: 60
        height: 60

        background: Rectangle {
            width: 60
            height: 60
            radius: 9
            border.color: "#444444"
            color: "#bbbbbb"
            border.width: 3
            Image {
                source: "qrc:/images/buttonImages/centerbutton.svg"
                anchors.fill: parent
            }
        }

        onClicked: {
            mapDisplay.center = mfdInterface.currCoordinates;
            panModeActive = false;
            updateZoom();
        }
    }

}
