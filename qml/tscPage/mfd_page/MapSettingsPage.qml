import QtQuick 2.15
import "../"
import "../styled_controls"
import "../styled_controls/gradientButtonElements"
import Mfd.GeoMap 1.0
import QtQml 2.15
import TypeEnums 1.0

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
            id: orientationButton

            Component.onCompleted: function() {
                orientationButton.text = mapOrientationToString();
            }

            Connections {
                target: GeoMap
                function onRotationModeChanged() {
                    orientationButton.text = mapOrientationToString();
                }
            }

            function mapOrientationToString() {
                switch (GeoMap.rotationMode) {
                    case MapRotationMode.NORTH_UP:
                        return "North Up";
                    case MapRotationMode.DTK_UP:
                        return "Desired Track Up";
                    case MapRotationMode.HDG_UP:
                        return "Heading Up";
                    case MapRotationMode.TRACK_UP:
                        return "Track Up";
                }
            }
        }

        onReleased: orientationPopup.visible = true
    }

    MapOrientationPopup {
        id: orientationPopup
    }

}
