import QtQuick 2.15
import QtQuick.Shapes 1.15
import Pfd.Airspeed 1.0
import Pfd.Autopilot 1.0

Item {


    Item {
        transform: Translate {
            y: (Airspeed.airspeed - Airspeed.center) * 9.6
        }

        Loader {
            active: !Airspeed.noColor
            asynchronous: true

            sourceComponent: Item {
                Rectangle {
                    x: 168
                    y: Airspeed.redY
                    width: 24
                    height: Airspeed.redHeight
                    color: "red"
                }

                Rectangle {
                    x: 168
                    y: Airspeed.yellowY
                    width: 24
                    height: Airspeed.yellowHeight
                    color: "yellow"
                }

                Rectangle {
                    x: 168
                    y: Airspeed.greenY
                    width: 24
                    height: Airspeed.greenHeight
                    color: "green"
                }

                Rectangle {
                    x: 180
                    y: Airspeed.flapsY
                    width: 12
                    height: Airspeed.flapsHeight
                    color: "white"
                }
            }
        }

        GradGroup {
        }

        Loader {
            active: !Airspeed.noColor && Airspeed.minSpeed > 0.1
            asynchronous: true

            sourceComponent: StartElement {
                x: 168
                transform: Translate {
                    y: Airspeed.minTransform
                }
            }
        }

        Loader {
            active: !Airspeed.noColor && Airspeed.maxSpeed > 0.1
            asynchronous: true

            sourceComponent: EndElement {
                x: 168
                transform: Translate {
                    y: Airspeed.maxTransform
                }
            }
        }

    }

    Item {
        transform: Translate {
            y: Airspeed.airspeed * 9.6
        }


        Loader {
            active: ApInfo.hasAp
            asynchronous: true

            Shape {
                transform: Translate {
                    y: Airspeed.refSpeed * -9.6
                }

                ShapePath {
                    fillColor: "#36c8d2"
                    strokeColor: "transparent"

                    PathMove {
                        x: 192; y: 268.8
                    }
                    PathLine {
                        x: 172.8; y: 268.8
                    }
                    PathLine {
                        x: 172.8; y: 273.6
                    }
                    PathLine {
                        x: 182.4; y: 288
                    }
                    PathLine {
                        x: 172.8; y: 302.4
                    }
                    PathLine {
                        x: 172.8; y: 307.2
                    }
                    PathLine {
                        x: 192; y: 307.2
                    }
                }
            }
        }

        SpeedBugElement { }
    }



}
