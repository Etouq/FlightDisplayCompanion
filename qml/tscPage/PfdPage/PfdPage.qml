import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQml 2.15

import Tsc.FlightTmr 1.0
import Tsc.NavCom 1.0
import Tsc.SpeedBugs 1.0

import "SpeedBugPage"
import "Timers"
import "Minimums"
import "PfdSettings"


Item {
    id: pfdPageRoot

    signal mfdClicked()
    signal navcomClicked()

    QtObject {
        id: propertyObject

        property SpeedBugEntry speedBugEntry
    }

    Loader {
        id: pageLoader

        sourceComponent: homeComponent
    }


    Component {
        id: homeComponent

        PfdHome {
            onSpeedbugsClicked: function() {
                pageLoader.sourceComponent = speedBugComponent;
            }
            onTimersClicked: function() {
                pageLoader.sourceComponent = timersComponent;
            }
            onMinimumsClicked: function() {
                pageLoader.sourceComponent = minimumsComponent;
            }
            onPfdSettingsClicked: function() {
                pageLoader.sourceComponent = pfdSettingsComponent;
            }
            onMfdClicked: function() {
                pfdPageRoot.mfdClicked();
            }
            onNavcomClicked: function() {
                pfdPageRoot.navcomClicked();
            }
        }
    }

    Component {
        id: speedBugComponent

        SpeedBugPage {
            onValueClicked: function(speedBugEntry) {
                propertyObject.speedBugEntry = speedBugEntry;
                pageLoader.sourceComponent = speedBugKeyboardComponent;
            }
            onAddSpeedbugClicked: function() {
                pageLoader.sourceComponent = speedBugNameKeyboardComponent;
            }
            onBackClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onPfdClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onMfdClicked: function() {
                pfdPageRoot.mfdClicked();
            }
            onNavcomClicked: function() {
                pfdPageRoot.navcomClicked();
            }
        }
    }

    Component {
        id: speedBugKeyboardComponent

        SpeedKeyboard {
            speedBugEntry: propertyObject.speedBugEntry

            onBackClicked: function() {
                pageLoader.sourceComponent = speedBugComponent;
            }
            onPfdClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onMfdClicked: function() {
                pfdPageRoot.mfdClicked();
            }
            onNavcomClicked: function() {
                pfdPageRoot.navcomClicked();
            }
        }
    }

    Component {
        id: speedBugNameKeyboardComponent

        SpeedBugNameKeyboard {
            onBackClicked: function() {
                pageLoader.sourceComponent = speedBugComponent;
            }
            onPfdClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onMfdClicked: function() {
                pfdPageRoot.mfdClicked();
            }
            onNavcomClicked: function() {
                pfdPageRoot.navcomClicked();
            }
        }
    }


    Component {
        id: timersComponent

        Timers {
            onTimeValueClicked: function() {
                pageLoader.sourceComponent = timeKeyboardComponent;
            }
            onBackClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onPfdClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onMfdClicked: function() {
                pfdPageRoot.mfdClicked();
            }
            onNavcomClicked: function() {
                pfdPageRoot.navcomClicked();
            }
        }
    }

    Component {
        id: timeKeyboardComponent

        TimeKeyboard {
            onBackClicked: function() {
                pageLoader.sourceComponent = timersComponent;
            }
            onPfdClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onMfdClicked: function() {
                pfdPageRoot.mfdClicked();
            }
            onNavcomClicked: function() {
                pfdPageRoot.navcomClicked();
            }
        }
    }

    Component {
        id: minimumsComponent

        Minimums {
            onBackClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onPfdClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onMfdClicked: function() {
                pfdPageRoot.mfdClicked();
            }
            onNavcomClicked: function() {
                pfdPageRoot.navcomClicked();
            }
        }
    }

    Component {
        id: pfdSettingsComponent

        PfdSettings {
            onBackClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onPfdClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onMfdClicked: function() {
                pfdPageRoot.mfdClicked();
            }
            onNavcomClicked: function() {
                pfdPageRoot.navcomClicked();
            }
        }
    }



}
