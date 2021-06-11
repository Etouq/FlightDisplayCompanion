import QtQuick 2.15
import QtQuick.Controls 2.15

ListView {
    id: root
    property string selectedAircraftName: ""

    x: 1250
    y: 40
    width: 624
    height: 1120
    spacing: 40
    flickDeceleration: 1000
    maximumFlickVelocity: 5000
    clip: false
    interactive: true
    ScrollBar.vertical: ScrollBar {
        anchors.top: parent.top
        anchors.left: parent.right
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        policy: ScrollBar.AlwaysOn
        active: true
        interactive: true

        contentItem: Rectangle {
            implicitWidth: 20
            implicitHeight: 150
            radius: width / 2
            color: "#00b4ff"
        }

        background: Rectangle {
            implicitWidth: 20
            implicitHeight: parent.height
            radius: width / 2
            color: "#3F4751"
        }

    }

    model: ListModel { id: modelId }

    Connections {
        target: aircraftInterface
        function onUpdateAircraftList()
        {
            modelId.clear();
            let names = aircraftInterface.getKeys();
            for (let i = 0; i < names.length; i++) {
                modelId.append({ "name": names[i], "url": aircraftInterface.getImagePath(names[i]) });
            }
        }
    }

    Component.onCompleted: {
        modelId.clear();
        let names = aircraftInterface.getKeys();
        for (let i = 0; i < names.length; i++) {
            modelId.append({ "name": names[i], "url": aircraftInterface.getImagePath(names[i]) });
        }
    }


    delegate: Item {
        width: 600
        height: 250
        x: 12

        Rectangle {
            //selected indicator border
            x: -12
            y: -12
            width: 624
            height: 271
            color: "white"
            visible: selectedAircraftName == name
        }

        Rectangle {
            //border
            x: -6
            y: -6
            width: 612
            height: 259
            color: "#00b4ff"
        }

        Image {
            y: 0
            width: 600
            height: 216
            source: url
            cache: false
        }

        Item {
            y: 216
            width: 600
            height: 34

            Text {
                anchors.centerIn: parent
                font.family: "Roboto Mono"
                font.bold: true;
                font.pixelSize: 30
                color: "white"
                text: name
            }
        }





        TapHandler {
            onTapped: {
                mfdPageId.clearAircraft();
                if (selectedAircraftName == name)
                {
                    selectedAircraftName = "";
                }
                else
                {
                    selectedAircraftName = name;
                    aircraftInterface.loadAircraft(name);
                }
            }
        }
    }

}
