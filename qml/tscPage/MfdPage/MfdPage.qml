import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQml 2.15


import "MapSettings"
import "IconSettings"
import "FlightplanPage"

Item {
    id: mfdPageRoot

    signal pfdClicked()
    signal navcomClicked()


    Loader {
        id: pageLoader

        sourceComponent: homeComponent
    }

    Component {
        id: homeComponent

        MfdHome {
            onMapSettingsClicked: function() {
                pageLoader.sourceComponent = mapSettingsComponent;
            }
            onPlaneIconClicked: function() {
                pageLoader.sourceComponent = iconSettingsComponent;
            }
            onFlightplanClicked: function() {
                pageLoader.sourceComponent = flightplanComponent;
            }
            onPfdClicked: function() {
                mfdPageRoot.pfdClicked();
            }
            onNavcomClicked: function() {
                mfdPageRoot.navcomClicked();
            }
        }
    }

    Component {
        id: mapSettingsComponent

        MapSettings {
            onBackClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onPfdClicked: function() {
                mfdPageRoot.pfdClicked();
            }
            onMfdClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onNavcomClicked: function() {
                mfdPageRoot.navcomClicked();
            }
        }
    }

    Component {
        id: iconSettingsComponent

        IconSettings {
            onBackClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onPfdClicked: function() {
                mfdPageRoot.pfdClicked();
            }
            onMfdClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onNavcomClicked: function() {
                mfdPageRoot.navcomClicked();
            }
        }
    }
    Component {
        id: flightplanComponent

        FlightplanPage {
            onBackClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onPfdClicked: function() {
                mfdPageRoot.pfdClicked();
            }
            onMfdClicked: function() {
                pageLoader.sourceComponent = homeComponent;
            }
            onNavcomClicked: function() {
                mfdPageRoot.navcomClicked();
            }
        }
    }


}
