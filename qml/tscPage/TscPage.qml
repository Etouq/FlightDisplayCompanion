import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQml 2.15

import "PfdPage"
import "MfdPage"
import "NavComPage"

Item {

    Loader {
        id: pageLoader

        sourceComponent: pfdPageComponent
    }

    Component {
        id: pfdPageComponent

        PfdPage {
            onMfdClicked: function() {
                pageLoader.sourceComponent = mfdPageComponent;
            }
            onNavcomClicked: function() {
                pageLoader.sourceComponent = navcomPageComponent;
            }
        }
    }

    Component {
        id: mfdPageComponent

        MfdPage {
            onPfdClicked: function() {
                pageLoader.sourceComponent = pfdPageComponent;
            }
            onNavcomClicked: function() {
                pageLoader.sourceComponent = navcomPageComponent;
            }
        }
    }

    Component {
        id: navcomPageComponent

        NavComPage {
            onPfdClicked: function() {
                pageLoader.sourceComponent = pfdPageComponent;
            }
            onMfdClicked: function() {
                pageLoader.sourceComponent = mfdPageComponent;
            }
        }
    }
}
