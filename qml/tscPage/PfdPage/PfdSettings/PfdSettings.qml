import QtQuick 2.15

import Pfd.Altimeter 1.0
import Pfd.Bottombar 1.0
import General.Settings 1.0
import TypeEnums 1.0

import "../../"
import "../../styled_controls"
import "../../styled_controls/gradientButtonElements"


TscPageBase {
    id: pfdHome

    pageTitle: "PFD Settings"

    showBackButton: true


    Column {
        y: 120
        anchors.horizontalCenter: parent.left
        anchors.horizontalCenterOffset: 864
        spacing: 6

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 6

            GradientButton {
                id: windModeButton
                width: 320

                UpperTitle {
                    text: "Wind Mode"
                }

                LowerValue {
                    id: windModeText
                    text: "Off"
                }

                function endCallback(index)
                {
                    if (index === 0) {
                        GenSettings.windMode = WindMode.OFF;
                    }
                    else if (index === 1) {
                        GenSettings.windMode = WindMode.MODE1;
                    }
                    else if (index === 2) {
                        GenSettings.windMode = WindMode.MODE2;
                    }
                    else if (index === 3) {
                        GenSettings.windMode = WindMode.MODE3;
                    }
                }

                onReleased: function() {
                    optionsPopup.callback = windModeButton.endCallback;
                    optionsPopup.options = ["Off", "Mode 1", "Mode 2", "Mode 3"];
                    optionsPopup.title = "Wind Mode";
                    optionsPopup.visible = true;
                }

                states: [
                    State {
                        name: "windOff"
                        when: GenSettings.windMode === WindMode.OFF

                        PropertyChanges {
                            target: windModeText
                            text: "Off"
                        }
                    },
                    State {
                        name: "wind1"
                        when: GenSettings.windMode === WindMode.MODE1

                        PropertyChanges {
                            target: windModeText
                            text: "Mode 1"
                        }
                    },
                    State {
                        name: "wind2"
                        when: GenSettings.windMode === WindMode.MODE2

                        PropertyChanges {
                            target: windModeText
                            text: "Mode 2"
                        }
                    },
                    State {
                        name: "wind3"
                        when: GenSettings.windMode === WindMode.MODE3

                        PropertyChanges {
                            target: windModeText
                            text: "Mode 3"
                        }
                    }
                ]
            }

            GradientButton {
                id: pressureUnitButton
                width: 320

                UpperTitle {
                    text: "Pressure Unit"
                }

                LowerValue {
                    id: pressureUnitText
                    text: "InHg"
                }

                function endCallback(index)
                {
                    Altimeter.setPressureInMillibar(index === 1);
                }

                onReleased: function() {
                    optionsPopup.callback = pressureUnitButton.endCallback;
                    optionsPopup.options = ["Inches of Mercury\n(InHg)", "Millibar\n(mb)"];
                    optionsPopup.title = "Pressure Unit";
                    optionsPopup.visible = true;
                }

                states: [
                    State {
                        name: "inHg"
                        when: !Altimeter.isPressureInMillibar

                        PropertyChanges {
                            target: pressureUnitText
                            text: "InHg"
                        }
                    },
                    State {
                        name: "mb"
                        when: Altimeter.isPressureInMillibar

                        PropertyChanges {
                            target: pressureUnitText
                            text: "mb"
                        }
                    }
                ]

            }
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 6

            GradientButton {
                id: outsideTempButton
                width: 320

                UpperTitle {
                    text: "Temperature Type"
                }

                LowerValue {
                    id: tempTypeText
                    text: "TAT"
                }

                function endCallback(index)
                {
                    if (index === 0) {
                        GenSettings.bottomTempType = BottomTemperatureType.TAT;
                    }
                    else if (index === 1) {
                        GenSettings.bottomTempType = BottomTemperatureType.OAT;
                    }
                    else if (index === 2) {
                        GenSettings.bottomTempType = BottomTemperatureType.ISA;
                    }
                }

                onReleased: function() {
                    optionsPopup.callback = outsideTempButton.endCallback;
                    optionsPopup.options = ["TAT", "OAT", "ISA"];
                    optionsPopup.title = "Temperature Type";
                    optionsPopup.visible = true;
                }

                states: [
                    State {
                        name: "tat"
                        when: GenSettings.bottomTempType === BottomTemperatureType.TAT

                        PropertyChanges {
                            target: tempTypeText
                            text: "TAT"
                        }
                    },
                    State {
                        name: "oat"
                        when: GenSettings.bottomTempType === BottomTemperatureType.OAT

                        PropertyChanges {
                            target: tempTypeText
                            text: "OAT"
                        }
                    },
                    State {
                        name: "isa"
                        when: GenSettings.bottomTempType === BottomTemperatureType.ISA

                        PropertyChanges {
                            target: tempTypeText
                            text: "ISA"
                        }
                    }
                ]
            }

            GradientButton {
                id: tempUnitButton
                width: 320

                UpperTitle {
                    text: "Temperature Unit"
                }

                LowerValue {
                    id: tempUnitText
                    text: "Celsius\n(ºC)"
                }

                function endCallback(index)
                {
                    Bottombar.updateTemperatureUnit(index);
                }

                onReleased: function() {
                    optionsPopup.callback = tempUnitButton.endCallback;
                    optionsPopup.options = ["Celsius\n(ºC)", "Fahrenheit\n(ºF)", "Kelvin\n(K)", "Rankine\n(ºR)"];
                    optionsPopup.title = "Temperature Unit";
                    optionsPopup.visible = true;
                }

                states: [
                    State {
                        name: "celsius"
                        when: Bottombar.tempUnit === 0

                        PropertyChanges {
                            target: tempUnitText
                            text: "Celsius\n(ºC)"
                        }
                    },
                    State {
                        name: "fahrenheit"
                        when: Bottombar.tempUnit === 1

                        PropertyChanges {
                            target: tempUnitText
                            text: "Fahrenheit\n(ºF)"
                        }
                    },
                    State {
                        name: "kelvin"
                        when: Bottombar.tempUnit === 2

                        PropertyChanges {
                            target: tempUnitText
                            text: "Kelvin\n(K)"
                        }
                    },
                    State {
                        name: "rankine"
                        when: Bottombar.tempUnit === 3

                        PropertyChanges {
                            target: tempUnitText
                            text: "Rankine\n(ºR)"
                        }
                    }
                ]
            }
        }

        Row {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 6

            GradientButton {
                id: topTimeButton
                width: 320

                UpperTitle {
                    text: "Top Time Type"
                }

                LowerValue {
                    id: topTimeTypeText
                    text: "UTC"
                }

                function endCallback(index)
                {
                    if (index === 0) {
                        GenSettings.topTimeType = TimeType.UTC;
                    }
                    else if (index === 1) {
                        GenSettings.topTimeType = TimeType.LCL;
                    }
                    else if (index === 2) {
                        GenSettings.topTimeType = TimeType.TMR;
                    }
                }

                onReleased: function() {
                    optionsPopup.callback = topTimeButton.endCallback;
                    optionsPopup.options = ["UTC", "Local", "Timer"];
                    optionsPopup.title = "Top Time Type";
                    optionsPopup.visible = true;
                }

                states: [
                    State {
                        name: "utcTop"
                        when: GenSettings.topTimeType === TimeType.UTC

                        PropertyChanges {
                            target: topTimeTypeText
                            text: "UTC"
                        }
                    },
                    State {
                        name: "lclTop"
                        when: GenSettings.topTimeType === TimeType.LCL

                        PropertyChanges {
                            target: topTimeTypeText
                            text: "Local"
                        }
                    },
                    State {
                        name: "tmrTop"
                        when: GenSettings.topTimeType === TimeType.TMR

                        PropertyChanges {
                            target: topTimeTypeText
                            text: "Timer"
                        }
                    }
                ]
            }

            GradientButton {
                id: botTimeButton
                width: 320

                UpperTitle {
                    text: "Bottom Time Type"
                }

                LowerValue {
                    id: botTimeTypeText
                    text: "Local"
                }

                function endCallback(index)
                {
                    if (index === 0) {
                        GenSettings.botTimeType = TimeType.UTC;
                    }
                    else if (index === 1) {
                        GenSettings.botTimeType = TimeType.LCL;
                    }
                    else if (index === 2) {
                        GenSettings.botTimeType = TimeType.TMR;
                    }
                }

                onReleased: function() {
                    optionsPopup.callback = botTimeButton.endCallback;
                    optionsPopup.options = ["UTC", "Local", "Timer"];
                    optionsPopup.title = "Bottom Time Type";
                    optionsPopup.visible = true;
                }

                states: [
                    State {
                        name: "utcBot"
                        when: GenSettings.botTimeType === TimeType.UTC

                        PropertyChanges {
                            target: botTimeTypeText
                            text: "UTC"
                        }
                    },
                    State {
                        name: "lclBot"
                        when: GenSettings.botTimeType === TimeType.LCL

                        PropertyChanges {
                            target: botTimeTypeText
                            text: "Local"
                        }
                    },
                    State {
                        name: "tmrBot"
                        when: GenSettings.botTimeType === TimeType.TMR

                        PropertyChanges {
                            target: botTimeTypeText
                            text: "Timer"
                        }
                    }
                ]
            }
        }

    }

    OptionsOverlay {
        id: optionsPopup

        title: ""
    }

}
