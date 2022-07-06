import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3
import QtQml.Models 2.15

import IO.Network 1.0

import "MfdPage"
import "PfdPage"
import "settingsPage"
import "TscPage"

ApplicationWindow {
    id: bgRect
    color: "black"
    visible: true
    visibility: Window.FullScreen

    property real scaleFactor: Math.min(Screen.width / 1920,
                                        Screen.height / 1200)

    //    FontLoader {
    //        source: "qrc:/fonts/RobotoMono-VariableFont_wght.ttf"
    //    }

    //    FontLoader {
    //        source: "qrc:/fonts/RobotoMono-Bold.ttf"
    //    }
    SwipeView {
        id: view
        anchors.fill: parent
        currentIndex: 1

        //clip: true
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

            SwipeView.onIsCurrentItemChanged: function () {
                if (SwipeView.isCurrentItem)
                    pfdPageId.movedOnScreen()
                else
                    pfdPageId.movedOffScreen()
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

    ListModel {
        id: messageModel
    }

    function removeLast() {
        messageModel.remove(messageModel.count - 1)
    }

    ListView {
        id: messageView

        x: Screen.width / 2 - 960 * scaleFactor
        y: 100 * scaleFactor
        width: 400
        height: contentHeight

        clip: true

        scale: scaleFactor
        transformOrigin: Item.TopLeft

        model: messageModel

        addDisplaced: Transition {
            NumberAnimation {
                property: "y"
                duration: 400
            }
            NumberAnimation {
                property: "x"
                duration: 400
            }
        }

        add: Transition {
            SequentialAnimation {
                PropertyAction {
                    property: "x"
                    value: 0
                }
                PauseAnimation {
                    duration: 400
                }
                NumberAnimation {
                    property: "x"
                    from: 0
                    duration: 400
                }
            }
        }


        delegate: Rectangle {
            id: messageWrapper
            x: messageLabel.contentWidth + 10
            width: messageLabel.contentWidth + 10
            height: childrenRect.height

            color: "transparent"

            required property string message

            ListView.onRemove: SequentialAnimation {
                PropertyAction { target: messageWrapper; property: "ListView.delayRemove"; value: true }
                NumberAnimation { target: messageWrapper; property: "x"; to: 0; duration: 400; }
                PropertyAction { target: messageWrapper; property: "ListView.delayRemove"; value: false }
            }

            Timer {
                interval: 5000
                repeat: false
                running: true
                triggeredOnStart: false
                onTriggered: removeLast()
            }


            Label {
                id: messageLabel


                width: 400
                anchors.right: parent.left
                anchors.rightMargin: contentWidth - 390

                topPadding: 2.5
                bottomPadding: 2.5
                leftPadding: 5
                rightPadding: 5

                font.pixelSize: 24
                font.family: "Roboto"

                wrapMode: Text.WordWrap

                color: "red"
                text: parent.message

                background: Rectangle {
                    color: "white"
                    width: parent.contentWidth + 10
                    height: parent.contentHeight + 5
                    border.color: "transparent"
                }
            }
        }
    }

        Connections {
            target: NetworkClient
            function onNewErrorMessage(msg) {
                messageModel.insert(0, { "message": msg })
            }
        }

}
