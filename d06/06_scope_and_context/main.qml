/***************************************************************************
*                                                                          *
*                main.qml for 07_scope_and_context                         *
*                Created on  : Thu Mar 30 2017 09:33                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    title: qsTr("Scope and context")
    id: root
    width: 1024; height: 600
    visible: true
    color: "black"

    Flickable {
        anchors.fill: parent
        contentHeight: grid.childrenRect.height

        Grid {
            id: grid
            anchors.fill: parent
            spacing: 2
            columns: 10
            Component.onCompleted: {
                for (var i = 0; i < children.length; ++i) {
                    if ((i % 3) === 0)
                        children[i].color = "blue";
                }
            }
            Instantiator {
                model: 100
                delegate: Component {
                    Rectangle {
                        parent: grid
                        width: parent.width / parent.columns - parent.spacing
                        height: width
                        color: "white"
                        MouseArea {
                            anchors.fill: parent
                            onClicked: notification.show(qsTr("Item " + index + " pressed"));
                        }
                    }
                }
            }
        }
    }

    Notification {
        id: notification
        anchors.centerIn: parent
        width: parent.width / 2
        height: parent.height / 2
    }
}



