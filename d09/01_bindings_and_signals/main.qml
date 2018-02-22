/***************************************************************************
*                                                                          *
*                main.qml for 01_bindings_and_signals                      *
*                Created on  : Thu Mar 30 2017 09:25                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Bindings and signals")

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: simpleClass.backgroundColor
        Text {
            anchors.centerIn: parent
            font.pixelSize: 18
            text: simpleClass.userText
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                simpleClass.backgroundColor = Qt.rgba(1, 0, 0, 1);
            }
        }
    }

    Connections {
        target: simpleClass
        onBackgroundColorChanged: simpleClass.userText = qsTr("Background colour changed to " + simpleClass.backgroundColor);
        onUserTextChanged: console.log("User text changed")
    }
}
