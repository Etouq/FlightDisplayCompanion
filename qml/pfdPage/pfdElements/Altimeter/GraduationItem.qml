import QtQuick 2.15
import QtQuick.Shapes 1.15

Item {

    GraduationGroup {
        y: (altInterface.altitude - altInterface.center) * 1.536
    }

    GroundLine {
        y: altInterface.radarAltitudeTransformValue
        width: 192
        height: 576
        clip: true
    }

    Canvas {
        y: 230.4
        width: 192
        height: 115.2

        onPaint: {
            var ctx = getContext("2d");
            ctx.fillStyle = "#1a1d21";
            ctx.beginPath();
            ctx.moveTo(0, 57.6);
            ctx.lineTo(28.8, 19.2);
            ctx.lineTo(124.8, 19.2);
            ctx.lineTo(124.8, 0);
            ctx.lineTo(192, 0);
            ctx.lineTo(192, 115.2);
            ctx.lineTo(124.8, 115.2);
            ctx.lineTo(124.8, 96);
            ctx.lineTo(28.8, 96);
            ctx.fill();
        }
    }

    DigitsGroup {
    }

    Item {
        y: altInterface.altitude * 1.536

        Loader {
            active: apInterface.has_ap
            sourceComponent: Canvas {
                y:  altInterface.referenceAltitude * -1.536
                width: 19.2
                height: 307.2

                onPaint: {
                    var ctx = getContext("2d");
                    ctx.fillStyle = "#36c8d2";
                    ctx.beginPath();
                    ctx.moveTo(0, 268.8);
                    ctx.lineTo(19.2, 268.8);
                    ctx.lineTo(19.2, 273.6);
                    ctx.lineTo(9.6, 288);
                    ctx.lineTo(19.2, 302.4);
                    ctx.lineTo(19.2, 307.2);
                    ctx.lineTo(0, 307.2);
                    ctx.fill();
                }
            }
        }

        Loader {
            active: altInterface.minimumsState !== 0
            sourceComponent: Canvas {
                y:  altInterface.minimum_altitude * -1.536
                width: 25
                height: 340
                visible: altInterface.minimumsState !== 0

                onPaint: {
                    var ctx = getContext("2d");
                    ctx.strokeStyle = "#36c8d2";
                    ctx.lineWidth = 4.8;
                    ctx.beginPath();
                    ctx.moveTo(19.2, 249.6);
                    ctx.lineTo(19.2, 262.08);
                    ctx.lineTo(0, 288);
                    ctx.lineTo(19.2, 313.92);
                    ctx.lineTo(19.2, 326.4);
                    ctx.stroke();
                }
            }
        }

    }


}
