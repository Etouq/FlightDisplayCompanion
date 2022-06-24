import QtQuick 2.15
import Pfd.Attitude 1.0

Item {


    Rectangle {
        anchors.fill: parent
        color: "#00569d"
    }

    Item {
        transform: [
            Rotation {
                angle: Attitude.bankAngle
                origin.x: 960
                origin.y: 438
            },
            Translate {
                y: Attitude.pitchTransformValue
            }
        ]

        Rectangle {
            x: -790
            y: 438
            width: 3500
            height: 3500
            color: "#48432e"
        }

        Rectangle {
            x: -790
            y: 433.68
            width: 3500
            height: 8.64
            color: "#e0e0e0"
        }
    }

}
