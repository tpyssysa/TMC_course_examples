/***************************************************************************
*                                                                          *
*                main.qml for 04_states                                    *
*                Created on  : Thu Mar 30 2017 09:30                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    property real margin: 5
    visible: true
    width: 640
    height: 480
    title: qsTr("States")

    Item {
        id: root
        anchors.fill: parent
        Rectangle {
            id: groove
            x: 10; y: 25
            width: parent.width * 0.5 ; height: parent.height * 0.67
            color: "gray"
            border.color: "lightgray"
            border.width: 4

            MouseArea {
                anchors.fill: parent
                onClicked: root.state == "" ? root.state = "on"
                                            : root.state = ""
            }
        }

        Rectangle {
            id: handle
            y: groove.y + margin
            anchors { left: groove.left; leftMargin: margin; right: groove.right; rightMargin: margin }
            height: parent.height * 0.2
            color: "lightgray"
        }

        Rectangle {
            id: light
            color: "black"
            x: root.width * 0.7; y: root.height * 0.43
            width: parent.width * 0.2; height: parent.height * 0.13
            radius: margin
        }

        states: [
            State { name: "on"
                PropertyChanges { target: handle; y: groove.y + groove.height - handle.height - margin }
                PropertyChanges { target: light; color: "red" } }
        ]

        transitions: [
            Transition { from: ""; to: "on"
                reversible: true
                ParallelAnimation {
                    ColorAnimation { target: light; properties: "color" }
                    PropertyAnimation { target: handle; properties: "y" }
                }
            }
        ]
    }
}
