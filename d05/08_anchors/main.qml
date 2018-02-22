/***************************************************************************
*                                                                          *
*                main.cpp for 08_anchors                                   *
*                Created on  : Thu Mar 30 2017 09:36                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 300
    title: qsTr("Anchors")

    Image {
        source: "qrc:/images/bluebackground.png"
        width: parent.width
        height: parent.height
    }

    Image {
        id: borderImage1
        source: "qrc:/images/bluebutton.png"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 15
        width: parent.width * 0.7; height: 75
        Image {
            anchors.left: parent.left
            anchors.leftMargin: 40
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/images/login.png"
        }
        Text {
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: -20
            anchors.verticalCenter: parent.verticalCenter
            text: "Login"
            font.bold: true
            color:"white"
            font.pixelSize: 32
        }
    }

    Image {
        id: borderImage2
        source: "qrc:/images/bluebutton.png"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15
        width: parent.width * 0.7; height: 75
        Image {
            anchors.left: parent.left
            anchors.leftMargin: 40
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/images/signout.png"
        }
        Text {
            anchors.left: parent.horizontalCenter
            anchors.leftMargin: -20
            anchors.verticalCenter: parent.verticalCenter
            text: "Sign Out"
            font.bold: true
            color:"white"
            font.pixelSize: 32
        }
    }
}
