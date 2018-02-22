/***************************************************************************
*                                                                          *
*                main.qml for 04_painted_items                             *
*                Created on  : Thu Mar 30 2017 09:30                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2
import Controls 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Painted Items")

    Button {
        anchors.fill: parent
        backgroundColor: "lightblue"
        buttontext: qsTr("Press me")
        onMousePressed: console.log("hello")
    }
}
