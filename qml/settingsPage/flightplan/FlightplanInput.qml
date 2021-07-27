import QtQuick 2.15
import QtQuick.Shapes 1.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15


Item {


    property bool validInput: identInput.acceptableInput && latInput.acceptableInput && lonInput.acceptableInput && (!alt1Input.enabled || alt1Input.acceptableInput) && (!alt2Input.enabled || alt2Input.acceptableInput)

    function insertWpBefore(index)
    {
        mfdInterface.qmlInsertFpWaypoint(index, latInput.getValue(), lonInput.getValue(), identInput.text, wpTypeInput.getIdent(), alt1Input.getValue(), alt2Input.getValue(), altTypeInput.getIdent());
        insertModeActive = false
    }

    function appendWaypoint()
    {
        insertModeActive = false
        mfdInterface.qmlAppendFpWaypoint(latInput.getValue(), lonInput.getValue(), identInput.text, wpTypeInput.getIdent(), alt1Input.getValue(), alt2Input.getValue(), altTypeInput.getIdent());
    }

    function startEditMode()
    {
        identInput.text = mfdInterface.getFpIdentAt(selectedItemIdx);
        wpTypeInput.setIndex(mfdInterface.getFpWpTypeAt(selectedItemIdx));
        latInput.setValue(mfdInterface.getFpPositionAt(selectedItemIdx).latitude);
        lonInput.setValue(mfdInterface.getFpPositionAt(selectedItemIdx).longitude);
        altTypeInput.setIndex(mfdInterface.getFpAltTypeAt(selectedItemIdx));
        alt1Input.setValue(mfdInterface.getFpAltitude1At(selectedItemIdx));
        alt2Input.setValue(mfdInterface.getFpAltitude2At(selectedItemIdx));

        identInput.ensureVisible(0);
        latInput.ensureVisible(0);
        lonInput.ensureVisible(0);
        alt1Input.ensureVisible(0);
        alt2Input.ensureVisible(0);
    }

    function saveWaypointEdit()
    {
        mfdInterface.qmlEditFpWaypoint(selectedItemIdx, latInput.getValue(), lonInput.getValue(), identInput.text, wpTypeInput.getIdent(), alt1Input.getValue(), alt2Input.getValue(), altTypeInput.getIdent());
        editModeActive = false;
        selectedItemIdx = -1;
    }

    function setDirectTo()
    {
        mfdInterface.qmlDirectTo(latInput.getValue(), lonInput.getValue(), identInput.text, wpTypeInput.getIdent(), alt1Input.getValue(), alt2Input.getValue(), altTypeInput.getIdent(), altInterface.altitude);
    }

    Column {
        id: inputColumn
        x: 930
        width: 250
        spacing: 10

        StyledTextInput {
            id: identInput

            placeholderTxt: "Ident"
            inputMethodHints: Qt.ImhUppercaseOnly

            validator: RegularExpressionValidator { regularExpression: /.+/ }

            EnterKey.type: Qt.EnterKeyNext
            KeyNavigation.tab: wpTypeInput

            nextIsComboBox: true
        }

        StyledComboBox {
            id: wpTypeInput

            model: ["Airport", "Intersection", "NDB", "User", "VOR"]

            title: "Waypoint Type"

            EnterKey.type: Qt.EnterKeyNext
            KeyNavigation.tab: latInput

            function setIndex(ident) {
                currentIndex = ident
            }

            function getIdent() {
                return currentIndex;
            }
        }

        StyledTextInput {
            id: latInput

            inputMethodHints: Qt.ImhFormattedNumbersOnly
            placeholderTxt: "Latitude"
            validator: DoubleValidator { bottom: -90.0; top: 90.0 }

            EnterKey.type: Qt.EnterKeyNext
            KeyNavigation.tab: lonInput

            function setValue(val) {
                text = val;
                ensureVisible(0);
            }

            function getValue() {
                return acceptableInput ? parseFloat(text) : 0;
            }
        }

        StyledTextInput {
            id: lonInput


            inputMethodHints: Qt.ImhFormattedNumbersOnly
            placeholderTxt: "Longitude"
            validator: DoubleValidator { bottom: -180.0; top: 180.0 }

            EnterKey.type: Qt.EnterKeyNext
            KeyNavigation.tab: altTypeInput

            nextIsComboBox: true

            function setValue(val) {
                text = val;
                ensureVisible(0);
            }

            function getValue() {
                return acceptableInput ? parseFloat(text) : 0;
            }
        }

        StyledComboBox {
            id: altTypeInput

            title: "Altitude Type"
            model: ["None", "At", "At or Below", "At or Above", "In Between"]

            EnterKey.type: Qt.EnterKeyNext
            KeyNavigation.tab: currentIndex != 0 ? alt1Input : settingsPageId

            overrideEnterHandler: false

            function setIndex(ident) {
                currentIndex = ident + 1
            }

            function getIdent() {
                return currentIndex - 1;
            }
        }

        StyledTextInput {
            id: alt1Input

            enabled: altTypeInput.currentIndex != 0

            inputMethodHints: Qt.ImhDigitsOnly
            placeholderTxt: altTypeInput.currentIndex != 4 ? "Altitude" : "Lower Altitude"
            validator: RegularExpressionValidator { regularExpression: /-?\d+/ }

            EnterKey.type: altTypeInput.currentIndex == 4 ? Qt.EnterKeyNext : Qt.EnterKeyDone
            KeyNavigation.tab: altTypeInput.currentIndex == 4 ? alt2Input : settingsPageId

            overrideEnterHandler: false

            function setValue(val) {
                if (enabled) {
                    text = val;
                    ensureVisible(0);
                }
            }

            function getValue() {
                return acceptableInput && enabled ? parseInt(text) : 0;
            }

        }

        StyledTextInput {
            id: alt2Input

            enabled: altTypeInput.currentIndex == 4

            inputMethodHints: Qt.ImhDigitsOnly
            placeholderTxt: "Upper Altitude"
            validator: RegularExpressionValidator { regularExpression: /-?\d+/ }

            EnterKey.type: Qt.EnterKeyDone
            KeyNavigation.tab: appendButton

            overrideEnterHandler: true

            Keys.onEnterPressed: settingsPageId.forceActiveFocus()
            Keys.onReturnPressed: settingsPageId.forceActiveFocus()

            function setValue(val) {
                if (enabled) {
                    text = val;
                    ensureVisible(0);
                }
            }

            function getValue() {
                return acceptableInput && enabled ? parseInt(text) : 0;
            }
        }

        StyledButton {
            id: appendButton

            text: "Append"

            KeyNavigation.tab: insertButton
            enabled: validInput && !insertModeActive && !editModeActive

            onClicked: appendWaypoint()
            Keys.onEnterPressed: appendWaypoint()
            Keys.onReturnPressed: appendWaypoint()
        }

        StyledButton {
            id: insertButton

            text: insertModeActive ? "Cancel" : "Insert"

            KeyNavigation.tab: clearButton

            enabled: validInput && !editModeActive

            onClicked: insertModeActive = !insertModeActive

            Keys.onReturnPressed: insertModeActive = !insertModeActive
            Keys.onEnterPressed: insertModeActive = !insertModeActive

        }

        StyledButton {
            id: clearButton

            KeyNavigation.tab: directToButton

            text: "Clear"

            enabled: fpTableWpListModel.count > 0 && !insertModeActive

            onClicked: {
                insertModeActive = false
                mfdInterface.qmlClearFlightPlan();
            }

            Keys.onReturnPressed: {
                insertModeActive = false
                mfdInterface.qmlClearFlightPlan();
            }

            Keys.onEnterPressed: {
                insertModeActive = false
                mfdInterface.qmlClearFlightPlan();
            }
        }

        StyledButton {
            id: directToButton

            text: "Direct To"

            KeyNavigation.tab: identInput

            enabled: !insertModeActive && validInput

            onClicked: setDirectTo()

            Keys.onReturnPressed: setDirectTo()
            Keys.onEnterPressed: setDirectTo()
        }

    }


    Rectangle {
        x: 0
        y: -40
        width: 850
        height: 35

        color: "black"
        visible: insertModeActive

        Text {
            anchors.centerIn: parent
            color: "white"
            font.family: "Roboto Mono"
            font.bold: true
            font.pixelSize: 25
            text: "Select waypoint before which to insert the new waypoint"

        }
    }

    Row {
        anchors.bottom: inputColumn.bottom
        x: 0
        spacing: 10
        visible: selectedItemIdx >= 0

        StyledButton {
            id: deleteButton
            text: "Delete"

            enabled: !editModeActive

            onClicked: {
                mfdInterface.qmlDeleteFpWaypoint(selectedItemIdx);
                selectedItemIdx = -1;
            }

            Keys.onReturnPressed: {
                mfdInterface.qmlDeleteFpWaypoint(selectedItemIdx);
                selectedItemIdx = -1;
            }

            Keys.onEnterPressed: {
                mfdInterface.qmlDeleteFpWaypoint(selectedItemIdx);
                selectedItemIdx = -1;
            }
        }

        StyledButton {
            id: editButton

            text: editModeActive ? "Cancel" : "Edit"

            onClicked: {
                if (editModeActive)
                    selectedItemIdx = -1;
                editModeActive = !editModeActive;
            }

            Keys.onReturnPressed: {
                if (editModeActive)
                    selectedItemIdx = -1;
                editModeActive = !editModeActive;
            }

            Keys.onEnterPressed: {
                if (editModeActive)
                    selectedItemIdx = -1;
                editModeActive = !editModeActive;
            }

        }

        StyledButton {
            id: saveButton

            text: "Save"

            enabled: editModeActive && validInput

            onClicked: {
                saveWaypointEdit();
            }

            Keys.onReturnPressed: {
                saveWaypointEdit();
            }

            Keys.onEnterPressed: {
                saveWaypointEdit();
            }
        }

    }




}
