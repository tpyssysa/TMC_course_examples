/***************************************************************************
*                                                                          *
*                main.qml for 06_nested_layout                             *
*                Created on  : Thu Mar 30 2017 09:33                       *
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

    color: "gray"

    Rectangle {
        x: 50; y: 50
        width: parent.width * 0.75; height: parent.height * 0.375
        color: "lightblue"

        Rectangle {
            x: 50; y: 50
            width: parent.width / 6.0; height: parent.height / 3.0
            color: "white"
        }
    }

    Rectangle {
        x: 50; y: 200
        width: parent.width * 0.75; height: parent.height * 0.375
        color: "green"

        Rectangle {
            x: 100; y: 50
            width: parent.width * 0.5; height: parent.width * 0.2
            color: "blue"
        }
    }
}
