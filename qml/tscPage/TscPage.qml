import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import "styled_controls"
import "styled_controls/gradientButtonElements"
import "pfd_page"
import "navcom_page"
import "mfd_page"

Rectangle {
    id: tscRoot
    color: "black"


    Loader {
        id: homeLoader
        active: true
        sourceComponent: HomePage {
            onSpeedbugsClicked: {
                speedBugsLoader.active = true;
                homeLoader.active = false;
            }
            onTimersClicked: {
                timersLoader.active = true;
                homeLoader.active = false;
            }
            onMinimumsClicked: {
                minimumsLoader.active = true;
                homeLoader.active = false;
            }
            onMapSettingsClicked: {
                mapSettingsLoader.active = true;
                homeLoader.active = false;
            }
            onPlaneIconClicked: {
                planeIconLoader.active = true;
                homeLoader.active = false;
            }
            onRadiosClicked: {
                radioLoader.active = true;
                homeLoader.active = false;
            }
        }
    }

    Loader {
        id: speedBugsLoader
        active: false
        sourceComponent: SpeedBugs {
            onValueClicked: {
                speedKeyboardLoader.active = true;
                speedKeyboardLoader.item.setContext(_callback, _startingValue);
                speedBugsLoader.visible = false;
            }
            onBackClicked: {
                homeLoader.active = true;
                speedBugsLoader.active = false;
            }
            onHomeClicked: {
                homeLoader.active = true;
                speedBugsLoader.active = false;
            }
        }
    }

    Loader {
        id: timersLoader
        active: false
        sourceComponent: Timers {
            onTimeValueClicked: {
                timeKeyboardLoader.active = true;
                timeKeyboardLoader.item.currentInput = tscBackend.getCurrentDisplay();
                timeKeyboardLoader.item.updateInput();
                timersLoader.active = false;
            }

            onBackClicked: {
                homeLoader.active = true;
                timersLoader.active = false;
            }
            onHomeClicked: {
                homeLoader.active = true;
                timersLoader.active = false;
            }
        }
    }

    Loader {
        id: minimumsLoader
        active: false
        sourceComponent: Minimums {
            onBackClicked: {
                homeLoader.active = true;
                minimumsLoader.active = false;
            }
            onHomeClicked: {
                homeLoader.active = true;
                minimumsLoader.active = false;
            }
        }
    }

    Loader {
        id: mapSettingsLoader
        active: false
        sourceComponent: MapSettingsPage {
            onBackClicked: {
                homeLoader.active = true;
                mapSettingsLoader.active = false;
            }
            onHomeClicked: {
                homeLoader.active = true;
                mapSettingsLoader.active = false;
            }
        }
    }

    Loader {
        id: planeIconLoader
        active: false
        sourceComponent: PlaneIconPage {
            onBackClicked: {
                homeLoader.active = true;
                planeIconLoader.active = false;
            }
            onHomeClicked: {
                homeLoader.active = true;
                planeIconLoader.active = false;
            }
        }
    }

    Loader {
        id: radioLoader
        active: false
        sourceComponent: NavComHome {
            onRadioClicked: {
                frequencyKeyboardLoader.active = true;
                frequencyKeyboardLoader.item.setContext(title, minFreq, maxFreq, activeFreq, stbyFreq, endCallback, nbDigits);
                radioLoader.active = false;
            }
            onXpndrClicked: {
                xpdrKeyboardLoader.active = true;
                radioLoader.active = false;
            }
            onBackClicked: {
                homeLoader.active = true;
                radioLoader.active = false;
            }
            onHomeClicked: {
                homeLoader.active = true;
                radioLoader.active = false;
            }
        }
    }

    Loader {
        id: speedKeyboardLoader
        active: false
        sourceComponent: SpeedKeyboard {
            onEnterClicked: {
                callback(currentInput);
                speedBugsLoader.visible = true;
                speedKeyboardLoader.active = false;
            }
            onBackClicked: {
                speedBugsLoader.visible = true;
                speedKeyboardLoader.active = false;
            }
            onHomeClicked: {
                homeLoader.active = true;
                speedBugsLoader.visible = true;
                speedBugsLoader.active = false;
                speedKeyboardLoader.active = false;
            }
        }
    }

    Loader {
        id: timeKeyboardLoader
        active: false
        sourceComponent: TimeKeyboard {
            onEnterClicked: {
                if (validateEdit()) {
                    tscBackend.endKeyboardCallback(currentInput);
                    timersLoader.active = true;
                    timeKeyboardLoader.active = false;
                }
            }
            onBackClicked: {
                timersLoader.active = true;
                timeKeyboardLoader.active = false;
            }
            onHomeClicked: {
                homeLoader.active = true;
                timeKeyboardLoader.active = false;
            }
        }
    }

    Loader {
        id: frequencyKeyboardLoader
        active: false
        sourceComponent: FrequencyKeyboard {
            onEnterClicked: {
                endCallback(currentInput, false);
                radioLoader.active = true;
                frequencyKeyboardLoader.active = false;
            }
            onTransferClicked: {
                endCallback(currentInput, true);
                radioLoader.active = true;
                frequencyKeyboardLoader.active = false;
            }
            onBackClicked: {
                radioLoader.active = true;
                frequencyKeyboardLoader.active = false;
            }
            onHomeClicked: {
                homeLoader.active = true;
                frequencyKeyboardLoader.active = false;
            }
        }
    }

    Loader {
        id: xpdrKeyboardLoader
        active: false
        sourceComponent: TransponderKeyboard {
            onEnterClicked: {
                if (inputIndex != -1) {
                    for (let i = 0; i < currentInput.length; i++) {
                        if (currentInput[i] === -1) {
                            return;
                        }
                    }

                    let code = 4096 * currentInput[0] + 256 * currentInput[1] + 16 * currentInput[2] + currentInput[3];
                    tscBackend.setXpdrCode(code);
                    radioLoader.active = true;
                    xpdrKeyboardLoader.active = false;
                }
            }
            onBackClicked: {
                radioLoader.active = true;
                xpdrKeyboardLoader.active = false;
            }
            onHomeClicked: {
                homeLoader.active = true;
                xpdrKeyboardLoader.active = false;
            }
        }
    }




}
