/***************************************************************************
*                                                                          *
*                main.qml for 05_modules                                   *
*                Created on  : Thu Mar 30 2017 09:33                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2
import "qrc:/CustomItems" 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Modules")

    Notification {
        id: notification
        anchors.fill: parent
        border.color: "blue"
        onButtonClicked: console.log(x, y, mouseEvent);
    }

    Component.onCompleted: notification.show(qsTr("New note"));
}
