import QtQuick 2.15
import QtQuick.Controls 2.15
import "gradientButtonElements"

Column {
    id: fullKeyboard

    spacing: fullKeyboard.keySpacing

    property real keySize: 140
    property real keySpacing: 4
    property bool upperCase: true

    signal keyPressed(string key)


    Row {
        spacing: fullKeyboard.keySpacing
        height: fullKeyboard.keySize

        Repeater {
            model: ["1","2","3","4","5","6","7","8","9","0"]
            delegate: GradientButton {
                required property string modelData

                width: fullKeyboard.keySize
                height: fullKeyboard.keySize

                MainText {
                    text: modelData
                    font.pixelSize: 84
                }

                onReleased: fullKeyboard.keyPressed(modelData);
            }
        }
    }

    Row {
        x: fullKeyboard.keySize / 2
        spacing: fullKeyboard.keySpacing
        height: fullKeyboard.keySize

        Repeater {
            model: fullKeyboard.upperCase ? ["Q","W","E","R","T","Y","U","I","O","P"] : ["q","w","e","r","t","y","u","i","o","p"]
            delegate: GradientButton {
                required property string modelData

                width: fullKeyboard.keySize
                height: fullKeyboard.keySize

                MainText {
                    text: modelData
                    font.pixelSize: 84
                }

                onReleased: fullKeyboard.keyPressed(modelData);
            }
        }
    }

    Row {
        x: fullKeyboard.keySize * 3 / 4
        spacing: fullKeyboard.keySpacing
        height: fullKeyboard.keySize

        Repeater {
            model: fullKeyboard.upperCase ? ["A","S","D","F","G","H","J","K","L"] : ["a","s","d","f","g","h","j","k","l"]
            delegate: GradientButton {
                required property string modelData

                width: fullKeyboard.keySize
                height: fullKeyboard.keySize

                MainText {
                    text: modelData
                    font.pixelSize: 84
                }

                onReleased: fullKeyboard.keyPressed(modelData);
            }
        }
    }
    Row {
        x: fullKeyboard.keySize * 5 / 4
        spacing: fullKeyboard.keySpacing
        height: fullKeyboard.keySize

        Repeater {
            model: fullKeyboard.upperCase ? ["Z","X","C","V","B","N","M"] : ["z","x","c","v","b","n","m"]
            delegate: GradientButton {
                required property string modelData

                width: fullKeyboard.keySize
                height: fullKeyboard.keySize

                MainText {
                    text: modelData
                    font.pixelSize: 84
                }

                onReleased: fullKeyboard.keyPressed(modelData);
            }
        }
    }

}