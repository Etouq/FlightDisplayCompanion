import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "Elements"
import "Elements/AttitudeIndicator"
import "Elements/HsiIndicator"
import "Elements/AirspeedIndicator"
import "Elements/Altimeter"

Item {


    AttitudeBackground {
        anchors.fill: parent
    }

    AttitudeIndicator {
        anchors.top: parent.top
        anchors.topMargin: 150
        anchors.left: parent.left
        anchors.leftMargin: 672
    }

    Altimeter {
        x: 1344
        y: 96
        width: 364.8
        height: 672
    }

    AirspeedIndicator {
        width: 240
        height: 670
        anchors.right: parent.right
        anchors.rightMargin: 1344
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 432
    }

    BottomBar {

    }

    HSIndicator {
        id: hsiIndicator
        height: 116 * 691.2 / 156
        anchors.left: parent.left
        anchors.leftMargin: 614.4
        anchors.right: parent.right
        anchors.rightMargin: 614.4
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 22.2
    }


    WindDataDisplay {
        x: 576
        y: 769.8
    }

    AngleOfAttackIndicator {
        anchors.right: parent.right
        anchors.rightMargin: 1392
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 228
    }

    AutopilotInfos {
    }

    ComInfos {

    }

    NavFreqInfos {

    }

    NavInfos {

    }

    RadarAltitude {

    }


}

