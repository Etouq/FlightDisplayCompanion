import QtQuick 2.15
import QtQuick.Shapes 1.15

import Pfd.Bottombar 1.0
import Tsc.FlightTmr 1.0
import General.Settings 1.0
import TypeEnums 1.0

Item {
    width: 1920
    y: 1177.8 + (65 - 57 * Math.sin(-0.6) - 116) * 691.2 / 156
    height: 1200 - y

    function movedOnScreen() {
        if (topTimeElement.state === "topTmrState" || botTimeElement.state === "botTmrState") {
            FlightTmr.movedOnscreen();
        }
    }

    function movedOffScreen() {
        if (topTimeElement.state === "topTmrState" || botTimeElement.state === "botTmrState") {
            FlightTmr.movedOffscreen();
        }
    }

    Shape {
        ShapePath
        {
            fillColor: "#1A1D21"
            strokeColor: "transparent"

            PathMove { x: 0; y: 0 }
            PathLine { x: 0; y: 1200 }
            PathLine { x: 1920; y: 1200 }
            PathLine { x: 1920; y: 0 }
            PathLine { x: 614.4 + (78 - 57 * Math.cos(Math.PI + 0.6)) * 691.2 / 156; relativeY: 0 }
            PathArc { radiusX: 57 * 691.2 / 156; radiusY: 57 * 691.2 / 156; x: 614.4 + (78 - 57 * Math.cos(-0.6)) * 691.2 / 156; relativeY: 0}
        }
    }

    Text {
        x: 12
        width: 50
        height: parent.height / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: "GS"
    }

    Text {
        x: 62
        width: 130
        height: parent.height / 2
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
        color: "white"
        font.family: "Roboto Mono"
        font.pixelSize: 36
        font.bold: true
        text: Bottombar.groundSpeed + "KT"
    }

    Item {
        x: 12
        anchors.bottom: parent.bottom
        height: parent.height / 2
        width: 180

        Text {
            id: tempTitle
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 50

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft

            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true

            color: "white"

            text: "TAT"
        }

        Text {
            id: tempValue
            x: 50
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 130

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight

            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true

            color: "white"

            text: Bottombar.totalAirTemp
        }

        states: [
            State {
                name: "tatState"
                when: GenSettings.bottomTempType === BottomTemperatureType.TAT

                PropertyChanges {
                    target: tempTitle
                    text: "TAT"
                }
                PropertyChanges {
                    target: tempValue
                    text: Bottombar.totalAirTemp
                }
            },
            State {
                name: "oatState"
                when: GenSettings.bottomTempType === BottomTemperatureType.OAT

                PropertyChanges {
                    target: tempTitle
                    text: "OAT"
                }
                PropertyChanges {
                    target: tempValue
                    text: Bottombar.outsideAirTemp
                }
            },
            State {
                name: "isaState"
                when: GenSettings.bottomTempType === BottomTemperatureType.ISA

                PropertyChanges {
                    target: tempTitle
                    text: "ISA"
                }
                PropertyChanges {
                    target: tempValue
                    text: Bottombar.stdAtmAirTemp
                }
            }
        ]
    }

    Rectangle {
        x: 201.6
        width: 4.8
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        color: "white"
    }

    Item {
        id: topTimeElement
        x: 1425
        width: 255
        height: parent.height / 2

        Text {
            id: topTimeTitle

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 65

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft

            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true

            color: "white"

            text: "UTC"
        }

        Text {
            id: topTimeValue
            x: 75
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 180

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight

            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true

            color: "white"

            text: Bottombar.zuluTime
        }

        onStateChanged: function() {
            if (state === "topTmrState")
                FlightTmr.movedOnscreen();
        }

        states: [
            State {
                name: "topUtcState"
                when: GenSettings.topTimeType === TimeType.UTC

                PropertyChanges {
                    target: topTimeTitle
                    text: "UTC"
                }
                PropertyChanges {
                    target: topTimeValue
                    text: Bottombar.zuluTime
                }
            },
            State {
                name: "topLclState"
                when: GenSettings.topTimeType === TimeType.LCL

                PropertyChanges {
                    target: topTimeTitle
                    text: "LCL"
                }
                PropertyChanges {
                    target: topTimeValue
                    text: Bottombar.localTime
                }
            },
            State {
                name: "topTmrState"
                when: GenSettings.topTimeType === TimeType.TMR

                PropertyChanges {
                    target: topTimeTitle
                    text: "TMR"
                }
                PropertyChanges {
                    target: topTimeValue
                    text: FlightTmr.timeString
                }
            }
        ]
    }

    Item {
        id: botTimeElement
        x: 1425
        anchors.bottom: parent.bottom
        width: 255
        height: parent.height / 2

        Text {
            id: botTimeTitle

            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 65

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft

            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true

            color: "white"

            text: "LCL"
        }

        Text {
            id: botTimeValue
            x: 75
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 180

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight

            font.family: "Roboto Mono"
            font.pixelSize: 36
            font.bold: true

            color: "white"

            text: Bottombar.localTime
        }

        onStateChanged: function() {
            if (state === "botTmrState")
                FlightTmr.movedOnscreen();
        }

        states: [
            State {
                name: "botUtcState"
                when: GenSettings.botTimeType === TimeType.UTC

                PropertyChanges {
                    target: botTimeTitle
                    text: "UTC"
                }
                PropertyChanges {
                    target: botTimeValue
                    text: Bottombar.zuluTime
                }
            },
            State {
                name: "botLclState"
                when: GenSettings.botTimeType === TimeType.LCL

                PropertyChanges {
                    target: botTimeTitle
                    text: "LCL"
                }
                PropertyChanges {
                    target: botTimeValue
                    text: Bottombar.localTime
                }
            },
            State {
                name: "botTmrState"
                when: GenSettings.botTimeType === TimeType.TMR

                PropertyChanges {
                    target: botTimeTitle
                    text: "TMR"
                }
                PropertyChanges {
                    target: botTimeValue
                    text: FlightTmr.timeString
                }
            }
        ]
    }


}
