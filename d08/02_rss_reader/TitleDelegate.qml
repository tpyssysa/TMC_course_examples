/***************************************************************************
*                                                                          *
*                TitleDelegate.qml for 02_rss_reader                       *
*                Created on  : Tue Apr 04 2017 15:23                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6

Rectangle {
    signal linkActivated(string link)

    width: parent.width
    height: parent.height
    color: "#505060"
    radius: 8

    Column {
        Text {
            x: 5
            color: "white"
            font.pixelSize: 18
            text: title
        }
        Text {
            x:5
            color: "white"
            font.pixelSize: 14
            text: link
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: linkActivated(link)
    }
}
