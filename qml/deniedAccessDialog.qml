import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Dialogs 1.3

Window {
    visible: true
    visibility: Window.FullScreen
    MessageDialog {
        id: messageDialog

        icon: StandardIcon.Critical
        title: "Error"
        text: "This application needs storage access to function. Please go into settings and allow storage access."
        standardButtons: StandardButton.Ok
        onAccepted: {
            Qt.quit();
        }

        Component.onCompleted: visible = true
    }
}


