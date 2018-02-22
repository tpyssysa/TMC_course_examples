/***************************************************************************
*                                                                          *
*                main.qml for 02_property_binding                          *
*                Created on  : Thu Mar 30 2017 09:27                       *
*                Made by : Qt training <training@qt.io>                    *
*                                                                          *
***************************************************************************/

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Property bindings")

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

    TextInput {
        x: parent.width * 0.1; y: parent.height * 0.1
        width: parent.width * 0.75
        font { family: "Helvetica";
            pixelSize: (parent.height > parent.width)
                       ? parent.width * 0.4
                       : parent.height * 0.4 }
        text: qsTr("Qt Quick")
        focus: true
        onTextChanged: color = "green"
        wrapMode: Text.WordWrap
    }
}

