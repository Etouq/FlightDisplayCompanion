import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15
import QtQuick.Layouts 1.15

Item {
    width: 420
    height: 1200
    x: 0

    property string airportName: ""
    property string airportIdent: ""

    TabBar {
        x: 0
        y: 0
        id: bar
        width: parent.width
        height: 50
        TabButton {
            text: "Overview"
            height: 60
            font.family: "Roboto"
            font.pixelSize: 22

        }
        TabButton {
            text: "Runways"
            height: 60
            font.family: "Roboto"
            font.pixelSize: 22
        }
        TabButton {
            text: "Com"
            height: 60
            font.family: "Roboto"
            font.pixelSize: 22
        }
    }

    ScrollView {
        x: 0
        y: 50
        width: parent.width
        height: 1150
        clip: true
        contentHeight: overviewListView.height + overviewListView.y
        visible: bar.currentIndex == 0
        ScrollBar.vertical.policy: ScrollBar.AlwaysOff

        Image {
            source: "qrc:/images/ICON_MAP_AIRPORT.png"
            width: 45
            height: 45
            x: 7.5
            anchors.bottom: overviewListView.top
        }

        Text {
            x: 60
            anchors.bottom: overviewListView.top
            font.family: "Roboto"
            font.bold: true
            font.pixelSize: 22
            color: "white"
            text: airportName + " (" + airportIdent + ")"
        }

        Column {
            id: overviewListView
            x: 0
            width: parent.width
            y: 45
            height: childrenRect.height

            Repeater {

                model: overviewModel
                /*delegate: Rectangle {
                    width: overviewListView.width
                    height: Math.max(45, 15 + Math.max(valueText.contentHeight, labelText.contentHeight))
                    color: rowColor

                    Text {
                        id: labelText
                        anchors.top: parent.top
                        anchors.topMargin: 7.5
                        x: 7.5 + levelIndex * 7.5
                        font.pixelSize: 22
                        color: "white"
                        font.family: "Roboto"
                        font.bold: !multiColumn
                        text: label
                        width: multiColumn ? 420 - (7.5 + levelIndex * 7.5) : 210 - (7.5 + levelIndex * 7.5)
                        wrapMode: Text.WordWrap
                    }

                    Text {
                        id: valueText
                        anchors.top: parent.top
                        anchors.topMargin: 7.5
                        x: 210
                        font.pixelSize: 22
                        color: "white"
                        font.family: "Roboto"
                        font.bold: false
                        text: value
                        wrapMode: Text.WordWrap
                        width: 210
                    }


                }*/
            }
        }

    }

    ScrollView {
        x: 0
        y: 50
        width: parent.width
        height: 1150
        clip: true
        contentHeight: runwayListView.height + runwayListView.y
        visible: bar.currentIndex == 1
        ScrollBar.vertical.policy: ScrollBar.AlwaysOff

        Image {
            source: "qrc:/images/ICON_MAP_AIRPORT.png"
            width: 45
            height: 45
            x: 7.5
            anchors.bottom: runwayListView.top
        }

        Text {
            x: 60
            anchors.bottom: runwayListView.top
            font.family: "Roboto"
            font.bold: true
            font.pixelSize: 22
            color: "white"
            text: "Kennedy Intl (KJFK)"
        }

        Column {
            id: runwayListView
            x: 0
            width: parent.width
            y: 45
            height: childrenRect.height

            Repeater {

                model: runwayModel
                delegate: Rectangle {
                    width: runwayListView.width
                    height: Math.max(45, 15 + rwyValueText.contentHeight)
                    color: rowColor

                    Text {
                        anchors.top: parent.top
                        anchors.topMargin: 7.5
                        x: 7.5 + levelIndex * 7.5
                        font.pixelSize: 22
                        color: "white"
                        font.family: "Roboto"
                        font.bold: true
                        text: label
                    }

                    Text {
                        id: rwyValueText
                        anchors.top: parent.top
                        anchors.topMargin: 7.5
                        x: 210
                        font.pixelSize: 22
                        color: "white"
                        font.family: "Roboto"
                        font.bold: false
                        text: value
                        wrapMode: Text.WordWrap
                        width: 210
                    }
                }
            }
        }


    }

    ScrollView {
        x: 0
        y: 50
        width: parent.width
        height: 1150
        clip: true
        contentHeight: comListView.height + comListView.y
        visible: bar.currentIndex == 2
        ScrollBar.vertical.policy: ScrollBar.AlwaysOff

        Image {
            source: "qrc:/images/ICON_MAP_AIRPORT.png"
            width: 45
            height: 45
            x: 7.5
            anchors.bottom: comListView.top
        }

        Text {
            x: 60
            anchors.bottom: comListView.top
            font.family: "Roboto"
            font.bold: true
            font.pixelSize: 22
            color: "white"
            text: "Kennedy Intl (KJFK)"
        }

        Column {
            id: comListView
            x: 0
            width: parent.width
            y: 45
            height: childrenRect.height



            Repeater {

                model: comModel
                delegate: Rectangle {
                    width: comListView.width
                    height: doubleRowItem.height
                    color: index % 2 == 0 ? '#44484d' : '#1a1d21'

                    Text {
                        id: comLabel
                        x: 0
                        anchors.verticalCenter: doubleRowItem.verticalCenter
                        font.pixelSize: 22
                        color: "white"
                        font.family: "Roboto"
                        text: label
                    }

                    Column {
                        x: 210
                        id: doubleRowItem
                        width: 210
                        height: childrenRect.height

                        Text {
                            x: 0
                            font.pixelSize: 22
                            color: "white"
                            font.family: "Roboto"
                            text: frequency
                        }

                        Text {
                            x: 0
                            font.pixelSize: 22
                            color: "white"
                            font.family: "Roboto"
                            text: name
                        }
                    }


                }
            }

            Rectangle {
                height: 27
                color: "#1a1d21"
                width: parent.width

            }
        }


    }






}
