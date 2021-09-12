import QtQuick 2.15
import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"

TscPageBase {
    id: root

    showBackButton: true
    showHomeButton: true

    pageTitle: "Map Settings"


    GradientButton {
        x: 60
        y: 180
        width: 360
        height: 252

        UpperTitle {
            text: "Orientation"
        }

        LowerValue {
            property var orientationStrings: ["North Up", "Heading Up", "Track Up"]
            text: orientationStrings[mfdInterface.mapOrientationMode]
        }

        onReleased: orientationPopup.visible = true
    }

    MapOrientationPopup {
        id: orientationPopup
    }

}
