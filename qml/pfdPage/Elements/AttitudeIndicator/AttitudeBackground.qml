import QtQuick 2.15
import Pfd.Attitude 1.0

Rectangle {

    color: "#00569d"

    // Rectangle {
    //     anchors.fill: parent
    //     color: "#00569d"
    // }

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
            x: -1040
            y: 438
            width: 4000
            height: 4000
            color: "#48432e"
        }

        Rectangle {
            x: -1040
            y: 433.68
            width: 4000
            height: 8.64
            color: "#e0e0e0"
        }
    }

}
