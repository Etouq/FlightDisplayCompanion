import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15
import QtQuick.Controls 2.15

Item {
    id: mapButtonRoot


    signal decreaseZoomClicked()
    signal increaseZoomClicked()
    signal recenterClicked()

    property alias canZoomOut: mapZoomOut.visible
    property alias canZoomIn: mapZoomIn.visible
    property alias mapNotCentered: centerMap.visible

    Button {
        id: mapZoomOut
        x: 1428
        y: 100
        width: 60
        height: 60

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

        onClicked: mapButtonRoot.decreaseZoomClicked()

    }

    Button {
        id: mapZoomIn
        x: 1428
        y: 172
        width: 60
        height: 60

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

        onClicked: mapButtonRoot.increaseZoomClicked()
    }

    Button {
        id: centerMap
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

        onClicked: mapButtonRoot.recenterClicked()
    }

}
