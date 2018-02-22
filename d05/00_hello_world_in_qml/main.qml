/***************************************************************************
*                                                                          *
*                main.qml for 00_hello_world_in_qml                        *
*                Created on  : Thu Mar 30 2017 09:23                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        anchors.centerIn: parent
        text: qsTr("Hello world!")
    }
}
