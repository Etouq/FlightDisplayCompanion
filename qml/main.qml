import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3

import "MfdPage"
import "PfdPage"
import "settingsPage"
import "TscPage"

ApplicationWindow {
    id: bgRect
    color: "black"
    visible: true
    visibility: Window.FullScreen

    property real scaleFactor: Math.min(Screen.width / 1920, Screen.height / 1200)

//    FontLoader {
//        source: "qrc:/fonts/RobotoMono-VariableFont_wght.ttf"
//    }

//    FontLoader {
//        source: "qrc:/fonts/RobotoMono-Bold.ttf"
//    }

    SwipeView {
        id: view
        anchors.fill: parent
        currentIndex: 0
        //clip: true

//        Item {
//            SettingsPage {
//                id: settingsPageId
//                clip: true
//                width: 1920
//                height: 1200
//                scale: scaleFactor
//                anchors.centerIn: parent
//            }
//        }

        Item {
            TscPage {
                id: tscPageId
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

            SwipeView.onIsCurrentItemChanged: function() {
                if (SwipeView.isCurrentItem)
                    pfdPageId.movedOnScreen();
                else
                    pfdPageId.movedOffScreen();
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

//    Connections {
//        target: NetworkClient
//        onNewErrorMessage: {
//            errorPopup.text = msg;
//            errorPopup.open();
//        }
//    }


//    MessageDialog {
//        id: errorPopup
//        icon: StandardIcon.Critical
//        title: "Error"
//        standardButtons: StandardButton.Ok
//    }
}


