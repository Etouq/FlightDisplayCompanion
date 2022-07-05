import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQml 2.15

import Tsc.NavCom 1.0

Item {
    id: navcomPageRoot

    signal pfdClicked()
    signal mfdClicked()

    QtObject {
        id: propertyObject

        property string pageTitle
        property real minFreq
        property real maxFreq
        property real activeFreq
        property real stbyFreq
        property var endCallback
        property int nbDigits
    }

    Loader {
        id: pageLoader

        sourceComponent: homeComponent
    }

    Component {
        id: homeComponent

        NavComHome {
            onRadioClicked: function(title, minFreq, maxFreq, activeFreq, stbyFreq, endCallback, nbDigits) {
                propertyObject.pageTitle = title;
                propertyObject.minFreq = minFreq;
                propertyObject.maxFreq = maxFreq;
                propertyObject.activeFreq = activeFreq;
                propertyObject.stbyFreq = stbyFreq;
                propertyObject.endCallback = endCallback;
                propertyObject.nbDigits = nbDigits;

                pageLoader.sourceComponent = freqKeyboardComponent;
            }
            onXpndrClicked: function() {
                pageLoader.sourceComponent = xpdrKeyboardComponent;
            }
            onPfdClicked: function() {
                navcomPageRoot.pfdClicked();
            }
            onMfdClicked: function() {
                navcomPageRoot.mfdClicked();
            }
        }
    }

    Component {
        id: freqKeyboardComponent

        FrequencyKeyboard {
            pageTitle: propertyObject.pageTitle
            minFreq: propertyObject.minFreq * 1000000
            maxFreq: propertyObject.maxFreq * 1000000
            activeFreq: "Active Freq: " + (propertyObject.activeFreq / 1000000).toFixed(propertyObject.nbDigits)
            stbyFreq: propertyObject.stbyFreq
            endCallback: propertyObject.endCallback
            nbDigits: propertyObject.nbDigits

            onEnterClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onTransferClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onBackClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onPfdClicked: function() {
                navcomPageRoot.pfdClicked();
            }
            onMfdClicked: function() {
                navcomPageRoot.mfdClicked();
            }
            onNavcomClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
        }
    }

    Component {
        id: xpdrKeyboardComponent

        TransponderKeyboard {
            onBackClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onPfdClicked: function() {
                navcomPageRoot.pfdClicked();
            }
            onMfdClicked: function() {
                navcomPageRoot.mfdClicked();
            }
            onNavcomClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
        }
    }

}
