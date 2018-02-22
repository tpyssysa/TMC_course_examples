/***************************************************************************
*                                                                          *
*                main.qml for 03_animations                                *
*                Created on  : Thu Mar 30 2017 09:28                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Animations")

    Notification {
        id: notification
        anchors.fill: parent
        border.color: "blue"
        onButtonClicked: console.log(x, y, mouseEvent);
    }

    Component.onCompleted: notification.show(qsTr("New note"));
}
