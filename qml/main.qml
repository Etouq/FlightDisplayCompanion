import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import "mfdPage"
import "pfdPage"
import "settingsPage"

Window {
    id: bgRect
    color: "black"
    visible: true
    visibility: Window.FullScreen

    property real scaleFactor: Math.min(Screen.width / 1920, Screen.height / 1200)

    FontLoader {
        source: "qrc:/RobotoMono-VariableFont_wght.ttf"
    }

    FontLoader {
        source: "qrc:/RobotoMono-Bold.ttf"
    }

    SwipeView {
        id: view
        anchors.fill: parent
        currentIndex: 0
        clip: true

        Item {
            SettingsPage {
                id: settingsPageId
                clip: true
                width: 1920
                height: 1200
                scale: scaleFactor
                anchors.centerIn: parent
            }
        }

        Item {
            PfdPage {
                id: pfdPageId
                clip: true
                width: 1920
                height: 1200
                scale: scaleFactor
                anchors.centerIn: parent
            }
        }

        Item {
            MfdPage {
                id: mfdPageId
                clip: true
                width: 1920
                height: 1200
                scale: scaleFactor
                anchors.centerIn: parent
            }
        }
    }
}


