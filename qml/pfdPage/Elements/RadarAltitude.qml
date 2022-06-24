import QtQuick 2.15
import Pfd.Altimeter 1.0

Rectangle {
    visible: Altimeter.radarAltitude < 2500
    x: 1152
    y: 570
    width: 156.6
    height: 60
    color: "#1A1D21"

    Text {
        width: 53.76
        height: 60
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: "RA"
    }

    Text {
        x: 53.76
        width: 99.84
        height: 60
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 40
        font.bold: true
        text: Altimeter.radarAltitude
    }
}
