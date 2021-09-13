import QtQuick 2.15

Item {

    Rectangle {
        x: 0
        y: 144
        width: 48
        height: 384
        color: "#1a1d21"
        opacity: 0.25
    }

    Rectangle {
        x: 0
        y: 96
        width: 48
        height: 48
        color: "#1a1d21"

        Text {
            id: verticalDeviationText
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.baseline: parent.top
            anchors.baselineOffset: 38.4
            color: "#d12bc7"
            font.bold: true
            font.family: "Roboto Mono"
            font.pixelSize: 43
            text: "V"
        }
    }

    Rectangle {
        x: 16.8
        y: 202.08
        width: 14.4
        height: 14.4
        radius: 7.2
        border.width: 2.88
        color: "transparent"
        border.color: "white"
    }

    Rectangle {
        x: 16.8
        y: 265.44
        width: 14.4
        height: 14.4
        radius: 7.2
        border.width: 2.88
        color: "transparent"
        border.color: "white"
    }

    Rectangle {
        x: 16.8
        y: 392.16
        width: 14.4
        height: 14.4
        radius: 7.2
        border.width: 2.88
        color: "transparent"
        border.color: "white"
    }

    Rectangle {
        x: 16.8
        y: 455.52
        width: 14.4
        height: 14.4
        radius: 7.2
        border.width: 2.88
        color: "transparent"
        border.color: "white"
    }

    Connections {
        target: altInterface
        function onVerticalDeviationModeChanged() {
            verticalDeviationBug.requestPaint();
        }
    }

    Canvas {
        id: verticalDeviationBug
        y: altInterface.verticalDeviationTransformValue
        width: 48
        height: 360
        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();
            let verticalDeviationMode = altInterface.verticalDeviationMode;
            if (verticalDeviationMode === 1) {        // VDI

                verticalDeviationText.text = "V";
                verticalDeviationText.color = "#d12bc7";

                ctx.fillStyle = "#d12bc7";
                ctx.beginPath();
                ctx.moveTo(4.8, 336);
                ctx.lineTo(38.4, 316.8);
                ctx.lineTo(38.4, 326.4);
                ctx.lineTo(24, 336);
                ctx.lineTo(38.4, 345.6);
                ctx.lineTo(38.4, 355.2);
                ctx.fill();
            }
            else if (verticalDeviationMode === 2) {   // GS

                verticalDeviationText.text = "G";
                verticalDeviationText.color = "#10c210";

                ctx.fillStyle = "#10c210";
                ctx.beginPath();
                ctx.moveTo(9.6, 336);
                ctx.lineTo(24, 321.6);
                ctx.lineTo(38.4, 336);
                ctx.lineTo(24, 350.4);
                ctx.fill();
            }
            else if (verticalDeviationMode === 3) {   // GP

                verticalDeviationText.text = "G";
                verticalDeviationText.color = "#d12bc7";

                ctx.fillStyle = "#d12bc7";
                ctx.beginPath();
                ctx.moveTo(9.6, 336);
                ctx.lineTo(24, 321.6);
                ctx.lineTo(38.4, 336);
                ctx.lineTo(24, 350.4);
                ctx.fill();
            }
            else {                                    // GSPreview

                verticalDeviationText.text = "G";
                verticalDeviationText.color = "#dfdfdf";

                ctx.fillStyle = "#dfdfdf";
                ctx.beginPath();
                ctx.moveTo(9.6, 336);
                ctx.lineTo(24, 321.6);
                ctx.lineTo(38.4, 336);
                ctx.lineTo(24, 350.4);
                ctx.lineTo(24, 340.8);
                ctx.lineTo(28.8, 336);
                ctx.lineTo(24, 331.2);
                ctx.lineTo(19.2, 336);
                ctx.lineTo(24, 340.8);
                ctx.lineTo(24, 350.4);
                ctx.fill();
            }
        }
    }


}
