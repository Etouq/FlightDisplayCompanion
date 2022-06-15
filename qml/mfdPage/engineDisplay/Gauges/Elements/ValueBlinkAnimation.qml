import QtQuick 2.15

SequentialAnimation {
    id: valAnimRoot
    property Text textTarget
    property Rectangle rectTarget

    alwaysRunToEnd: false
    loops: Animation.Infinite

    onStarted: function () {
        valAnimRoot.rectTarget.visible = true
    }

    onStopped: function () {
        valAnimRoot.rectTarget.visible = false
    }

    PropertyAction {
        target: valAnimRoot.textTarget
        property: "color"
        value: "red"
    }
    PropertyAction {
        target: valAnimRoot.rectTarget
        property: "color"
        value: "white"
    }
    PauseAnimation {
        duration: 500
    }
    PropertyAction {
        target: valAnimRoot.textTarget
        property: "color"
        value: "white"
    }
    PropertyAction {
        target: valAnimRoot.rectTarget
        property: "color"
        value: "red"
    }
    PauseAnimation {
        duration: 500
    }
}
