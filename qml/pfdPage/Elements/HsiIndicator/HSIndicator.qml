import QtQuick 2.15
import Pfd.Bearings 1.0
import General.Settings 1.0

Item {

    Rectangle {
        x: 343.3846153846154
        y: 35.44615384615385
        width: 4.430769230769231
        height: 26.584615384615386
        color: "white"
        transform: Rotation {
            angle: -135
            origin.x: 2.2153846153846155
            origin.y: 252.55384615384617
        }
    }
    Rectangle {
        x: 343.3846153846154
        y: 35.44615384615385
        width: 4.430769230769231
        height: 26.584615384615386
        color: "white"
        transform: Rotation {
            angle: -90
            origin.x: 2.2153846153846155
            origin.y: 252.55384615384617
        }
    }
    Rectangle {
        x: 343.3846153846154
        y: 35.44615384615385
        width: 4.430769230769231
        height: 26.584615384615386
        color: "white"
        transform: Rotation {
            angle: -45
            origin.x: 2.2153846153846155
            origin.y: 252.55384615384617
        }
    }
    Rectangle {
        x: 343.3846153846154
        y: 35.44615384615385
        width: 4.430769230769231
        height: 26.584615384615386
        color: "white"
        transform: Rotation {
            angle: 45
            origin.x: 2.2153846153846155
            origin.y: 252.55384615384617
        }
    }
    Rectangle {
        x: 343.3846153846154
        y: 35.44615384615385
        width: 4.430769230769231
        height: 26.584615384615386
        color: "white"
        transform: Rotation {
            angle: 90
            origin.x: 2.2153846153846155
            origin.y: 252.55384615384617
        }
    }
    Rectangle {
        x: 343.3846153846154
        y: 35.44615384615385
        width: 4.430769230769231
        height: 26.584615384615386
        color: "white"
        transform: Rotation {
            angle: 135
            origin.x: 2.2153846153846155
            origin.y: 252.55384615384617
        }
    }

    Turnrate {}

    BackgroundCircle {
    }



    StaticParts {}

    Loader {
        active: GenSettings.dmeMode !== BearingMode.OFF
        sourceComponent: DmeGroup {
        }
    }

    Loader {
        active: GenSettings.bearing1Mode !== BearingMode.OFF
        sourceComponent: Bearing1FixedGroup {
        }
    }

    Loader {
        active: GenSettings.bearing2Mode !== BearingMode.OFF
        sourceComponent: Bearing2FixedGroup {
        }
    }

    // DmeGroup {
    //     id: dmeGroup
    // }

    // Bearing1FixedGroup {
    //     id: brg1FixedGroup
    // }

    // Bearing2FixedGroup {
    //     id: brg2FixedGroup
    // }

    Item {
        x: 0
        y: 288
        width: 134.34814059988142
        height: 138.40555302115993
        TapHandler {
            onTapped: GenSettings.nextDmeMode()
        }
    }

    Item {
        x: 0
        y: 430.602628357737
        width: 231.04255493350342
        height: 82.47521814639418
        TapHandler {
            onTapped: GenSettings.nextBearing1Mode()
        }
    }

    Item {
        x: 460.15744506649673
        y: 430.602628357737
        width: 231.04255493350342
        height: 82.47521814639418
        TapHandler {
            onTapped: GenSettings.nextBearing2Mode()
        }
    }


}
