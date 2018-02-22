/***************************************************************************
*                                                                          *
*                main.qml for 09_positioners                               *
*                Created on  : Thu Mar 30 2017 09:37                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Positioners")

    Column {
        anchors { left: parent.left; right: parent.right; top: parent.top; margins: 50 }

        Rectangle {
            width: parent.width
            height: root.height / 2 - parent.anchors.margins

            color: "lightblue"

            Row {
                anchors { left: parent.left; top: parent.top; margins: 50 }

                Rectangle {
                    width: 50; height: 50
                    color: "white"
                }
            }
        }

        Rectangle {
            width: parent.width
            height: root.height / 2 - parent.anchors.margins
            color: "green"

            Row {
                anchors { left: parent.left; top: parent.top; leftMargin: 100; topMargin: 50 }
                Rectangle {
                    width: 80; height: 50
                    color: "blue"
                }
            }
        }
    }
}

