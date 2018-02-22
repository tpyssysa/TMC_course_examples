/***************************************************************************
*                                                                          *
*                main.qml for 01_basic_items                               *
*                Created on  : Thu Mar 30 2017 09:25                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Basic items")

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "#403737";
            }
            GradientStop {
                position: 1.00;
                color: "#ffffff";
            }
        }
    }

    Image {
        source: "qrc:/images/qt_logo.png"
    }

    Text {
        anchors.centerIn: parent
        text: qsTr("Hello world!")
    }
}
